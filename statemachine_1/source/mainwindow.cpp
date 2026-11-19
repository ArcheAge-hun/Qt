#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtStateMachine/QStateMachine>
#include <QtStateMachine/QState>
#include <QtStateMachine/QFinalState>
#include <QTimer>

// ========== 工厂：点灯 + 倒计时 + 最后 flashLastMs 毫秒闪烁 ==========
QState *createLightState(const QList<LightWidget*> &lights,
                         int duration, int flashLastMs,
                         QLabel *countdown, QStateMachine *machine)
{
    auto *lightState = new QState(machine);
    auto *timing     = new QState(lightState);
    auto *done       = new QFinalState(lightState);

    auto *totalTimer = new QTimer(lightState);
    totalTimer->setSingleShot(true);
    totalTimer->setInterval(duration);

    auto *tickTimer = new QTimer(lightState);
    tickTimer->setInterval(1000);

    auto *flashTimer = new QTimer(lightState);
    flashTimer->setInterval(500);          // 亮500ms / 灭500ms → 1Hz 闪烁

    const int totalSec = qMax(1, (duration + 999) / 1000);
    const QString normalStyle =
        "color:#eee; background:#333; border-radius:3px;";
    const QString flashStyle =
        "color:#fff; background:#c0392b; border-radius:3px;";

    // 进入：亮灯 + 显示初始倒计时 + 启动定时器
    QObject::connect(timing, &QState::entered, [=]()
    {
        for (LightWidget *l : lights) l->turnOn();
        countdown->setText(QString::number(totalSec));
        countdown->setStyleSheet(normalStyle);
        totalTimer->start();
        tickTimer->start();
        // 整个阶段都落在闪烁区间（如黄灯）→ 直接闪
        if (flashLastMs > 0 && duration <= flashLastMs)
        {
            countdown->setStyleSheet(flashStyle);
            flashTimer->start();
        }
    });

    // 离开：停定时器、关灯、清倒计时（exited 与下一状态 entered 在同一事件循环内，
    // 不会产生可见的“熄灭间隙”）
    QObject::connect(timing, &QState::exited, [=]()
    {
        totalTimer->stop();
        tickTimer->stop();
        flashTimer->stop();
        for (LightWidget *l : lights) l->turnOff();
        countdown->clear();
        countdown->setStyleSheet(normalStyle);
    });

    // 每秒刷新倒计时；到点进入闪烁期
    QObject::connect(tickTimer, &QTimer::timeout, [=]()
    {
        int ms = totalTimer->remainingTime();
        if (ms < 0) ms = 0;
        int sec = (ms + 999) / 1000;
        if (sec > 0) countdown->setText(QString::number(sec));

        if (flashLastMs > 0 && ms <= flashLastMs && !flashTimer->isActive())
        {
            for (LightWidget *l : lights) l->setOn(true);   // 先保证亮起
            countdown->setStyleSheet(flashStyle);
            flashTimer->start();
        }
    });

    // 闪烁：整组灯同相翻转
    QObject::connect(flashTimer, &QTimer::timeout, [=]()
    {
        bool anyOn = false;
        for (LightWidget *l : lights)
            if (l->isOn()) { anyOn = true; break; }
        for (LightWidget *l : lights) l->setOn(!anyOn);
    });

    timing->addTransition(totalTimer, &QTimer::timeout, done);
    lightState->setInitialState(timing);
    return lightState;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_light = new TrafficLightWidget(this);
    statusBar()->addPermanentWidget(m_light);

    QLabel *cd = m_light->countdown();
    auto *red    = m_light->redLight();
    auto *yellow = m_light->yellowLight();
    auto *green  = m_light->greenLight();

    m_statemachine = new QStateMachine(this);

    // 时长(ms), 最后多少ms开始闪烁
    QState *sRed       = createLightState({red},            30000, 10000, cd, m_statemachine);
    QState *sRedYellow = createLightState({red, yellow},     3000,     0, cd, m_statemachine);
    QState *sGreen     = createLightState({green},          30000, 10000, cd, m_statemachine);
    QState *sYellow    = createLightState({yellow},          3000,  3000, cd, m_statemachine);

    sRed->addTransition(sRed,             &QState::finished, sRedYellow);
    sRedYellow->addTransition(sRedYellow, &QState::finished, sGreen);
    sGreen->addTransition(sGreen,         &QState::finished, sYellow);
    sYellow->addTransition(sYellow,       &QState::finished, sRed);

    connect(sRed,       &QState::entered, this, [=]{ statusBar()->showMessage(tr("红灯")); });
    connect(sRedYellow, &QState::entered, this, [=]{ statusBar()->showMessage(tr("红黄过渡 — 即将变绿")); });
    connect(sGreen,     &QState::entered, this, [=]{ statusBar()->showMessage(tr("绿灯")); });
    connect(sYellow,    &QState::entered, this, [=]{ statusBar()->showMessage(tr("黄灯")); });

    m_statemachine->setInitialState(sRed);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnStart_clicked()
{
    bool bStart = ui->btnStart->property("start").toBool();
    if (bStart)
    {
        m_statemachine->start();
    }
    else
    {
        m_statemachine->stop();
    }

    bStart = !bStart;

    if (bStart)
    {
        ui->btnStart->setText(QString(tr("开始")));
    }
    else
    {
        ui->btnStart->setText(QString(tr("停止")));
    }
    ui->btnStart->setProperty("start", bStart);
}


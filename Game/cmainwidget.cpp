#include "cmainwidget.h"
#include "ui_cmainwidget.h"

#include <QPixmap>
#include <QDebug>

// 设置计数器
int steps = 0;

CMainWidget::CMainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CMainWidget)
{
    ui->setupUi(this);
    // 绘制背景图片
    m_pBackgroundLab = new CBackgroundLab(this);
    m_pBackgroundLab->setScaledContents(true);

    QPixmap pixmap("./Background.png");
    m_pBackgroundLab->setPixmap(pixmap);
    m_pBackgroundLab->setVisible(false);

    // 绘制登录界面
    m_pLoginWdg = new CLoginWidget(this);

    // 场景界面
    m_pScreenWdg = new CScreenWidget(this);
    m_pScreenWdg->hide();

    // 设置定时器
    m_pTimer = new QTimer(this);

    // 设置进度条
    m_pProgressBar = new QProgressBar(this);
    m_pProgressBar->setRange(0, 100);
    m_pProgressBar->resize(this->width()-20, 10);
    m_pProgressBar->move(10, this->height()-30);
    m_pProgressBar->setVisible(false);

    // 设置窗口大小
    this->resize(800, 600);

    // 信号
    connect(m_pLoginWdg->m_pStartBtn, &CPushbutton::clicked, this, &CMainWidget::onClicked);
    connect(m_pTimer, &QTimer::timeout, this, &CMainWidget::onTimeout);
}

CMainWidget::~CMainWidget()
{
    delete ui;
    delete m_pLoginWdg;
    delete m_pScreenWdg;
    delete m_pProgressBar;
    delete m_pBackgroundLab;
}

void CMainWidget::onClicked()
{
    m_pLoginWdg->hide();
    m_pBackgroundLab->setVisible(true);
    m_pProgressBar->setVisible(true);
    m_pTimer->start(100);
}

void CMainWidget::onTimeout()
{
    ++steps;
    m_pProgressBar->setValue(steps);

    if (steps > m_pProgressBar->maximum()) {
        m_pProgressBar->reset();
        m_pProgressBar->hide();
        m_pTimer->stop();
        steps = 0;

        m_pScreenWdg->show();
    }
}

void CMainWidget::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);

    m_pLoginWdg->resize(this->size());
    m_pScreenWdg->resize(this->size());
    m_pBackgroundLab->resize(this->size());

    m_pProgressBar->resize(this->width()-20, 10);
    m_pProgressBar->move(10, this->height()-30);
}

#include "widget.h"
#include "ui_widget.h"

#include <QCoreApplication>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    init();

    m_pTimer1 = new QTimer(this);
    connect(m_pTimer1, &QTimer::timeout, this, &Widget::onTimeout1);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "event:" << event->key();
}

void Widget::on_btnStart_clicked()
{
    m_timerValue1 = ui->spinBox1->value();
    m_pTimer1->start(1000 * m_timerValue1);
}

void Widget::on_btnStop_clicked()
{
    m_pTimer1->stop();
}

void Widget::onTimeout1()
{
    m_keyValue1 = winKeyMap.value(ui->editKye1->text().toUpper());
    qDebug() << "m_keyValue1:" << m_keyValue1;
    QKeyEvent keyEvent(QEvent::KeyPress, m_keyValue1, Qt::MetaModifier);
    QCoreApplication::sendEvent(this, &keyEvent);
}

void Widget::init()
{
    winKeyMap = QMap<QString, Qt::Key>{
        {"A", Qt::Key_A},
    };
}

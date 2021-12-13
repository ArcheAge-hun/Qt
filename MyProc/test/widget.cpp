#include "widget.h"
#include "ui_widget.h"
#include <QtDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    quint32 col = ui->textBrowser->frameSize().width()/7;
    qDebug() << col;
    char buf = '-';
    QByteArray byteArry(col, buf);
    ui->textBrowser->append(QString(byteArry));
}


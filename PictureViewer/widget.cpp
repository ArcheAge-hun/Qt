#include "widget.h"
#include <QVBoxLayout>

QLabel *g_pLabel = nullptr;

Widget::Widget(QWidget *parent) : QWidget(parent)
{
    m_pBtnOpen = new QPushButton("打开", this);
    g_pLabel = new QLabel("图片", this);

    QVBoxLayout *pVlayout = new QVBoxLayout(this);
    pVlayout->addWidget(m_pBtnOpen);
    pVlayout->addWidget(g_pLabel);

    connect(m_pBtnOpen, SIGNAL(clicked()), this, SLOT(onBtnOpen()));
}

void Widget::onBtnOpen()
{
    m_pDlg->on_btnOpen_clicked();
}

bool GShowPicture(QString file)
{
    QPixmap pixmap(file);
    if (pixmap.isNull())
        return false;

    g_pLabel->setPixmap(pixmap);
    return true;
}

#include "cloginwidget.h"

#include <QPixmap>
#include <QDebug>

CLoginWidget::CLoginWidget(QWidget *parent) : QWidget(parent)
{
    m_pBackgroundLab = new CBackgroundLab(this);
    m_pBackgroundLab->setScaledContents(true);

    QPixmap pixmap("./Login.png");
    if (pixmap.isNull())
        qDebug() << "111111111";

    m_pBackgroundLab->setPixmap(pixmap);

    m_pStartBtn = new CPushbutton("开始" ,this);
    m_pStartBtn->resize(m_pStartBtn->width()*1.1, m_pStartBtn->height());
    m_pStartBtn->move(m_pBackgroundLab->width()-115, m_pBackgroundLab->height()/4);
}

void CLoginWidget::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);

    m_pBackgroundLab->resize(this->size());
    m_pStartBtn->move(this->width()-115, this->height()/4);
}


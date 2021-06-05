#include "cscreenwidget.h"

#include <QPixmap>

CScreenWidget::CScreenWidget(QWidget *parent) : QWidget(parent)
{
    m_pScreenLab = new CBackgroundLab(this);

    QPixmap pixmap("./screen.jpg");
    m_pScreenLab->setPixmap(pixmap);

    m_pRole = new CRole(this);
    m_pRole->move(this->width()/10, this->height()/10);
}

void CScreenWidget::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);

    m_pScreenLab->resize(this->size());
}


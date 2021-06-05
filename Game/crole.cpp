#include "crole.h"

CRole::CRole(QWidget *parent) : QWidget(parent)
{
    m_pLabRole = new CBackgroundLab(this);

    QPixmap pixmap("./Role.gif");
    m_pLabRole->setPixmap(pixmap);

    this->resize(50, 50);
}

void CRole::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);

    m_pLabRole->resize(this->size());
}

#include "crole.h"

#include <QMovie>

CRole::CRole(QWidget *parent) : QWidget(parent)
{
    m_pLabRole = new CBackgroundLab(this);

    QMovie *PMovie = new QMovie("./Role.gif");
    m_pLabRole->setMovie(PMovie);

    this->resize(50, 50);
    PMovie->start();
}

void CRole::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);

    m_pLabRole->resize(this->size());
}

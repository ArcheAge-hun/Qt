#include "cscreenwidget.h"

#include <QPixmap>

CScreenWidget::CScreenWidget(QWidget *parent) : QWidget(parent)
{
    m_pScreenLab = new CBackgroundLab(this);
    m_pScreenLab->setScaledContents(true);

    QPixmap pixmap("./screen.jpg");
    m_pScreenLab->setPixmap(pixmap);
}

void CScreenWidget::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);

    m_pScreenLab->resize(this->size());
}


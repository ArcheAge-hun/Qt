#include "cbackgroundlab.h"

CBackgroundLab::CBackgroundLab(QWidget *parent, Qt::WindowFlags f) : QLabel(parent, f)
{
    this->setScaledContents(true);
}

CBackgroundLab::CBackgroundLab(const QString &text, QWidget *parent, Qt::WindowFlags f) : QLabel(text, parent, f)
{

}

CBackgroundLab::~CBackgroundLab()
{

}

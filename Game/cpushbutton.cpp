#include "cpushbutton.h"

CPushbutton::CPushbutton(QWidget *parent) : QPushButton(parent)
{

}

CPushbutton::CPushbutton(const QString &text, QWidget *parent) : QPushButton(text, parent)
{

}

CPushbutton::CPushbutton(const QIcon &icon, const QString &text, QWidget *parent) : QPushButton(icon, text, parent)
{

}

CPushbutton::~CPushbutton()
{

}

#ifndef CPUSHBUTTON_H
#define CPUSHBUTTON_H

#include <QPushButton>

class CPushbutton : public QPushButton
{
public:
    CPushbutton(QWidget * parent = 0);
    CPushbutton(const QString & text, QWidget * parent = 0);
    CPushbutton(const QIcon & icon, const QString & text, QWidget * parent = 0);
    ~CPushbutton();
};

#endif // CPUSHBUTTON_H

#ifndef CBACKGROUNDLAB_H
#define CBACKGROUNDLAB_H

#include <QLabel>

class CBackgroundLab : public QLabel
{
public:
    explicit CBackgroundLab(QWidget * parent = 0, Qt::WindowFlags f = 0);
    explicit CBackgroundLab(const QString & text, QWidget * parent = 0, Qt::WindowFlags f = 0);
    ~CBackgroundLab();
};

#endif // CBACKGROUNDLAB_H

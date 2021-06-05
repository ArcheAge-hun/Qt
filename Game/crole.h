#ifndef CROLE_H
#define CROLE_H

#include <QWidget>

#include "cbackgroundlab.h"

class CRole : public QWidget
{
    Q_OBJECT
public:
    explicit CRole(QWidget *parent = 0);

protected:
    void resizeEvent(QResizeEvent *event);

signals:

public slots:

private:
    CBackgroundLab *m_pLabRole;
};

#endif // CROLE_H

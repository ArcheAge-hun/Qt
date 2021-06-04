#ifndef CLOGINWIDGET_H
#define CLOGINWIDGET_H

#include <QWidget>

#include "cbackgroundlab.h"
#include "cpushbutton.h"

class CLoginWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CLoginWidget(QWidget *parent = 0);

protected:
    void resizeEvent(QResizeEvent *event);

signals:

public slots:

public:
    CPushbutton *m_pStartBtn;

private:
    CBackgroundLab *m_pBackgroundLab;
};

#endif // CLOGINWIDGET_H

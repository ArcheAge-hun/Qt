#ifndef CSCREENWIDGET_H
#define CSCREENWIDGET_H

#include <QWidget>

#include "cbackgroundlab.h"
#include "crole.h"

class CScreenWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CScreenWidget(QWidget *parent = 0);

protected:
    void resizeEvent(QResizeEvent *event);

signals:

public slots:

private:
    CBackgroundLab *m_pScreenLab;

    CRole *m_pRole;
};

#endif // CSCREENWIDGET_H

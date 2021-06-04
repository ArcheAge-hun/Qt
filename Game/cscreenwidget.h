#ifndef CSCREENWIDGET_H
#define CSCREENWIDGET_H

#include <QWidget>

#include "cbackgroundlab.h"

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
};

#endif // CSCREENWIDGET_H

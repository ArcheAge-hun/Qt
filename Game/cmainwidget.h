#ifndef CMAINWIDGET_H
#define CMAINWIDGET_H

#include <QWidget>
#include <QProgressBar>
#include <QTimer>

#include "cloginwidget.h"
#include "cscreenwidget.h"
#include "cbackgroundlab.h"

namespace Ui {
class CMainWidget;
}

class CMainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CMainWidget(QWidget *parent = 0);
    ~CMainWidget();

public slots:
    void onClicked();
    void onTimeout();

protected:
    void resizeEvent(QResizeEvent *event);

private:
    Ui::CMainWidget *ui;

    CLoginWidget *m_pLoginWdg;
    CScreenWidget *m_pScreenWdg;
    CBackgroundLab *m_pBackgroundLab;

    QProgressBar *m_pProgressBar;
    QTimer *m_pTimer;
};

#endif // CMAINWIDGET_H

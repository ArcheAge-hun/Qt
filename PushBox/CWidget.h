#ifndef CWIDGET_H
#define CWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QTimer>

#include "CGameMap.h"
#include "CRole.h"

namespace Ui {
class CWidget;
}

class CWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CWidget(QWidget *parent = 0);
    ~CWidget();

protected:
    void paintEvent(QPaintEvent *event);

    void keyPressEvent(QKeyEvent *event);

private:
    void MoveRole(QPoint pos);

private:
    Ui::CWidget *ui;

    QPainter *m_pPainter;

    CGameMap *m_pGameMap;

    CRole *m_pRole;

    QTimer *m_pTimer;
};

#endif // CWIDGET_H

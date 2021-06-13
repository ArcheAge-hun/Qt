#ifndef CWIDGET_H
#define CWIDGET_H

#include <QWidget>
#include <QPainter>

#include "CGameMap.h"

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

private:
    void DrawMap(QPoint pos);

private:
    Ui::CWidget *ui;

    QPainter *m_pPainter;

    CGameMap *m_pGameMap;
};

#endif // CWIDGET_H

#include "CWidget.h"
#include "ui_CWidget.h"

#include <QFileDialog>
#include <QKeyEvent>
#include <QDebug>
#include <iostream>

CWidget::CWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CWidget)
{
    ui->setupUi(this);

    m_pGameMap = new CGameMap(this);
    QString fileName = QFileDialog::getOpenFileName(this, "打开地图", "./", "*.txt");
    m_pGameMap->PaserMap(fileName);
    m_pRole = new CRole(QPoint(1, 1), this);

    m_pPainter = new QPainter(this);

    m_pTimer = new QTimer(this);

    setFixedSize(960, 800);

    m_pTimer->start(200);

    connect(m_pTimer, &QTimer::timeout, [this](){this->update();});
}

CWidget::~CWidget()
{
    delete ui;
}

void CWidget::paintEvent(QPaintEvent *event)
{
    QPainter bgPainter(this);
    bgPainter.drawImage(QRect(0, 0, this->width(), this->height()), QImage(":/imagges/images/bg.png"));

    m_pPainter->begin(this);

    m_pGameMap->DrawMap(m_pPainter, QPoint(0, 100));

    m_pRole->DrawRole(m_pPainter, QPoint(0, 100));

    m_pPainter->end();
}

void CWidget::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_W:
    case Qt::Key_Up:
        MoveRole(QPoint(0, -1));
        break;

    case Qt::Key_A:
    case Qt::Key_Left:
        MoveRole(QPoint(-1, 0));
        break;

    case Qt::Key_S:
    case Qt::Key_Down:
        MoveRole(QPoint(0, +1));
        break;

    case Qt::Key_D:
    case Qt::Key_Right:
        MoveRole(QPoint(+1, 0));
        break;
    }
}

void CWidget::MoveRole(QPoint pos)
{
    QPoint newPos = m_pRole->m_pos + pos;

    int newRow = newPos.y();
    int newCol = newPos.x();

    int offCol = pos.x();
    int offRow = pos.y();

    if (m_pGameMap->m_pMapArry[newRow][newCol] == Wall) {
        return;
    }
    else if (m_pGameMap->m_pMapArry[newRow][newCol] == Box) {
        if (m_pGameMap->m_pMapArry[newRow + offRow][newCol + offCol] == Road) {
            m_pGameMap->m_pMapArry[newRow + offRow][newCol + offCol] = Box;
            m_pGameMap->m_pMapArry[newRow][newCol] = Road;
        }
        else if (m_pGameMap->m_pMapArry[newRow + offRow][newCol + offCol] == Point) {
            m_pGameMap->m_pMapArry[newRow + offRow][newCol + offCol] = InPoint;
            m_pGameMap->m_pMapArry[newRow][newCol] = Road;
        } else {
            return;
        }
    }
    else if (m_pGameMap->m_pMapArry[newRow][newCol] == InPoint) {
        if (m_pGameMap->m_pMapArry[newRow + offRow][newCol + offCol] == Road) {
            m_pGameMap->m_pMapArry[newRow + offRow][newCol + offCol] = Box;
            m_pGameMap->m_pMapArry[newRow][newCol] = Point;
        }
        else if (m_pGameMap->m_pMapArry[newRow + offRow][newCol + offCol] == Point) {
            m_pGameMap->m_pMapArry[newRow + offRow][newCol + offCol] = InPoint;
            m_pGameMap->m_pMapArry[newRow][newCol] = Point;
        } else {
            return;
        }
    }

    m_pRole->Move(pos);
}

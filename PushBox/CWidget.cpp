#include "CWidget.h"
#include "ui_CWidget.h"

#include <QFileDialog>

enum MapInfo {
    Wall,
    Road,
    Box,
    Point,
    InPoint,
};

CWidget::CWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CWidget)
{
    ui->setupUi(this);

    m_pGameMap = new CGameMap(this);
    QString fileName = QFileDialog::getOpenFileName(this, "打开地图", "./", "*.txt");
    m_pGameMap->PaserMap(fileName);

    m_pPainter = new QPainter(this);

    setFixedSize(960, 800);
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

    DrawMap(QPoint(0, 100));

    m_pPainter->end();
}

void CWidget::DrawMap(QPoint pos)
{
    for (int row = 0; row < m_pGameMap->m_row; ++row) {
        for (int column = 0; column < m_pGameMap->m_column; ++column) {
            QString imageUrl;

            switch (m_pGameMap->m_pMapArry[row][column]) {
            case Wall:
                imageUrl = QString(":/imagges/images/wall.png");
                break;

            case Road:
                imageUrl = QString(":/imagges/images/road.png");
                break;

            case Box:
                imageUrl = QString(":/imagges/images/box.png");
                break;

            case Point:
                imageUrl = QString(":/imagges/images/point.png");
                break;
            }
            QImage image(imageUrl);
            m_pPainter->drawImage(QRect(pos.x() + column * image.width(), pos.y() + row * image.height(), image.width(), image.height()), image);
        }
    }
}

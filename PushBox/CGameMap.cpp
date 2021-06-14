#include "CGameMap.h"

#include <QFile>
#include <QDebug>

CGameMap::CGameMap(QObject *parent) : QObject(parent)
{
    m_row = 0;
    m_column = 0;
    m_pMapArry = nullptr;
}

CGameMap::~CGameMap()
{
    Clear();
}

void CGameMap::PaserMap(QString fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly))
        return;

    QByteArray arryAll = file.readAll();

    arryAll.replace("\r\n", "\n");
    QList<QByteArray> lstarryRow = arryAll.split('\n');


    m_row = lstarryRow.count();

    m_pMapArry = new int*[m_row];

    for (int row = 0; row < m_row; ++row) {
        QList<QByteArray> lstarryColumn = lstarryRow.at(row).split(',');
        m_column = lstarryColumn.count();
        m_pMapArry[row] = new int[m_column];
        for (int column = 0; column < m_column; ++column) {
            m_pMapArry[row][column] = lstarryColumn.at(column).toInt();
        }
    }
}

void CGameMap::DrawMap(QPainter *painter, QPoint pos)
{
    for (int row = 0; row < m_row; ++row) {
        for (int column = 0; column < m_column; ++column) {
            QString imageUrl;

            switch (m_pMapArry[row][column]) {
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
            painter->drawImage(QRect(pos.x() + column * image.width(), pos.y() + row * image.height(), image.width(), image.height()), image);
        }
    }
}

void CGameMap::Clear()
{
    if (m_pMapArry != nullptr) {
        for (int row = 0; row < m_row; ++row) {
            delete []m_pMapArry[row];
        }
        delete m_pMapArry;
    }
}

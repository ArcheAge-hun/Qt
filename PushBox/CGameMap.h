#ifndef CGAMEMAP_H
#define CGAMEMAP_H

#include <QObject>
#include <QPainter>
#include <QPoint>

enum MapInfo {
    Wall,
    Road,
    Box,
    Point,
    InPoint,
};

class CGameMap : public QObject
{
    Q_OBJECT
public:
    explicit CGameMap(QObject *parent = 0);
    ~CGameMap();

signals:

public slots:

public:
    void PaserMap(QString fileName);

    void DrawMap(QPainter *painter, QPoint pos);

private:
    void Clear();

public:
    int m_row;
    int m_column;
    int **m_pMapArry;
};

#endif // CGAMEMAP_H

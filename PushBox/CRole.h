#ifndef CROLE_H
#define CROLE_H

#include <QObject>
#include <QPoint>
#include <QImage>
#include <QPainter>

class CRole : public QObject
{
    Q_OBJECT
public:
    explicit CRole(QPoint pos, QObject *parent = 0);

signals:

public slots:

public:
    void DrawRole(QPainter *painter, QPoint pos);

    void Move(QPoint pos);

public:
    QPoint m_pos;

    QPoint m_paintPos;

    QImage m_image;

};

#endif // CROLE_H

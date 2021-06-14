#include "CRole.h"

CRole::CRole(QPoint pos, QObject *parent) : QObject(parent)
{
    m_pos = pos;

    m_image = QImage(":/imagges/images/role.png");

    m_paintPos = m_pos * m_image.width();
}

void CRole::DrawRole(QPainter *painter, QPoint pos)
{
    painter->drawImage(m_paintPos + pos, m_image);
}

void CRole::Move(QPoint pos)
{
    m_pos += pos;

    m_paintPos = m_pos * m_image.width();
}


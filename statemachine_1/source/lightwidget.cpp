#include "lightwidget.h"

LightWidget::LightWidget(const QColor &color, QWidget *parent)
    : QWidget(parent), m_color(color)
{
    setFixedSize(16, 16);
}

bool LightWidget::isOn() const
{
    return m_on;
}

void LightWidget::setOn(bool on)
{
    if (on == m_on) return;
    m_on = on;
    update();
}

void LightWidget::turnOn()
{
    setOn(true);
}

void LightWidget::turnOff()
{
    setOn(false);
}

void LightWidget::paintEvent(QPaintEvent *)
{
    QPainter p(this);
        p.setRenderHint(QPainter::Antialiasing);

        QRect r = rect().adjusted(1, 1, -1, -1);

        if (m_on)
        {
            // 灯体
            p.setPen(Qt::NoPen);
            p.setBrush(m_color);
            p.drawEllipse(r);

            // 左上角高光（径向渐变）
            QRadialGradient g(r.center() - QPoint(r.width()/4, r.height()/4),
                              r.width()/2);
            g.setColorAt(0.0, QColor(255, 255, 255, 200));
            g.setColorAt(0.5, QColor(255, 255, 255, 40));
            g.setColorAt(1.0, Qt::transparent);
            p.setBrush(g);
            p.drawEllipse(r);
        }
        else
        {
            // 熄灭：暗色圆（darker(350) 对 #00C957 约得 #005A27，深沉不显脏）
            p.setBrush(m_color.darker(350));
            p.drawEllipse(r);
        }
}

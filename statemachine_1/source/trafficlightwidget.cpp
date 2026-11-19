#include "trafficlightwidget.h"

TrafficLightWidget::TrafficLightWidget(QWidget *parent)
 : QWidget(parent)
{
    auto *lay = new QHBoxLayout(this);
    lay->setContentsMargins(4, 2, 4, 2);
    lay->setSpacing(4);

    m_red    = new LightWidget(Qt::red,    this);
    m_yellow = new LightWidget(Qt::yellow, this);
    m_green  = new LightWidget(Qt::green,  this);

    m_countdown = new QLabel(QStringLiteral("--"), this);
    QFont f = m_countdown->font();
    f.setBold(true);
    f.setFamily(QStringLiteral("Monospace"));
    f.setPointSize(11);
    m_countdown->setFont(f);
    m_countdown->setAlignment(Qt::AlignCenter);
    m_countdown->setFixedWidth(32);
    m_countdown->setStyleSheet(
        "color:#eee; background:#333; border-radius:3px;"
            );

    lay->addWidget(m_red);
    lay->addWidget(m_yellow);
    lay->addWidget(m_green);
    lay->addSpacing(6);
    lay->addWidget(m_countdown);
}

LightWidget *TrafficLightWidget::redLight()
{
    return m_red;
}

LightWidget *TrafficLightWidget::yellowLight()
{
    return m_yellow;
}

LightWidget *TrafficLightWidget::greenLight()
{
    return m_green;
}

QLabel *TrafficLightWidget::countdown()
{
    return m_countdown;
}

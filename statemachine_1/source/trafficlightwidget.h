#ifndef TRAFFICLIGHTWIDGET_H
#define TRAFFICLIGHTWIDGET_H

#include <QWidget>
#include <QLabel>

#include "lightwidget.h"

// ========== 红绿灯组合（灯 + 倒计时） ==========
class TrafficLightWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TrafficLightWidget(QWidget *parent = nullptr);

    LightWidget *redLight();
    LightWidget *yellowLight();
    LightWidget *greenLight();
    QLabel      *countdown();

private:
    LightWidget *m_red, *m_yellow, *m_green;
    QLabel *m_countdown;
};

#endif // TRAFFICLIGHTWIDGET_H

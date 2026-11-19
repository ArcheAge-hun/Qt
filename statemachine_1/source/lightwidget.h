#ifndef LIGHTWIDGET_H
#define LIGHTWIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include <QPainter>

// ========== 单个指示灯 ==========
class LightWidget : public QWidget
{
    Q_OBJECT
public:
    explicit LightWidget(const QColor &color, QWidget *parent = nullptr);

    bool isOn() const;
    void setOn(bool on);
    void turnOn();
    void turnOff();

protected:
    void paintEvent(QPaintEvent *) override;

private:
    QColor m_color;
    bool m_on = false;
};

#endif // LIGHTWIDGET_H

#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QMap>
#include <QKeyEvent>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

protected:
    void keyPressEvent(QKeyEvent *event);

private slots:
    void on_btnStart_clicked();

    void on_btnStop_clicked();

    void onTimeout1();

private:
    void init();

private:
    Ui::Widget *ui;

    QTimer *m_pTimer1;
    int m_timerValue1;

    QMap<QString, Qt::Key> winKeyMap;
    long int m_keyValue1;
};

#endif // WIDGET_H

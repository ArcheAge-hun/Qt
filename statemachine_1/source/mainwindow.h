#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtStateMachine/QtStateMachine>

#include "trafficlightwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnStart_clicked();

private:
    Ui::MainWindow *ui;
    TrafficLightWidget *m_light;
    QStateMachine *m_statemachine;
};
#endif // MAINWINDOW_H

#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include "dialog.h"

class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = nullptr);

signals:

public slots:
    void onBtnOpen();

private:
    QPushButton *m_pBtnOpen;

public:
    Dialog *m_pDlg;
    QString m_file;
};

extern bool GShowPicture(QString file);
extern QLabel *g_pLabel;

#endif // WIDGET_H

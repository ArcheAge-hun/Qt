#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    QImage DownLoadImage(QString url);

    void closeEvent(QCloseEvent *e);

private slots:
    void on_btnLoad_clicked();

    void onLoadProgress(int progress);

    void onLoadFinished(bool ok);

private:
    Ui::Widget *ui;
    bool exitFlag;
};

#endif // WIDGET_H

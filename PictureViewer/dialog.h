#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

class Widget;

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

public slots:
    void on_btnOpen_clicked();

private:
    bool ShowPicture(QString file);

private:
    Ui::Dialog *ui;
    QStringList m_files;

    qint32 m_currentIndex;
    QString m_currentFile;

public:
    Widget *m_pWdg;
private slots:
    void on_btnNext_clicked();
    void on_btnPrevious_clicked();
};

#endif // DIALOG_H

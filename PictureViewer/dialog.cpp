#include "dialog.h"
#include "ui_dialog.h"
#include "widget.h"
#include <QFileDialog>
#include <QPixmap>
#include <QThread>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    m_currentIndex = 0;
    m_currentFile.clear();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_btnOpen_clicked()
{
    QString filter = "*.png *.bmp *.jpg";
    m_files = QFileDialog::getOpenFileNames(nullptr, "选择图片", "./", filter);
    m_currentIndex = 0;
    m_currentFile = m_files.at(m_currentIndex);
    ShowPicture(m_currentFile);

//    m_pWdg->m_file = m_currentFile;
    GShowPicture(m_currentFile);
}

bool Dialog::ShowPicture(QString file)
{
    QPixmap pixmap(file);
    if (pixmap.isNull())
        return false;

    ui->labelViewer->setPixmap(pixmap);
    return true;
}

void Dialog::on_btnNext_clicked()
{
    ++m_currentIndex;
    if (m_currentIndex < 0 || m_currentIndex > m_files.count() - 1)
        m_currentIndex = 0;

    if (m_files.isEmpty())
        return;

    m_currentFile = m_files.at(m_currentIndex);
    ShowPicture(m_currentFile);

    GShowPicture(m_currentFile);
}

void Dialog::on_btnPrevious_clicked()
{
    --m_currentIndex;
    if (m_currentIndex < 0 || m_currentIndex > m_files.count())
        m_currentIndex = m_files.count() - 1;

    if (m_files.isEmpty())
        return;

    m_currentFile = m_files.at(m_currentIndex);
    ShowPicture(m_currentFile);

    GShowPicture(m_currentFile);
}

#include "widget.h"
#include "ui_widget.h"
#include <QWebPage>
#include <QWebFrame>
#include <QWebElementCollection>
#include <QWebElement>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QFileInfo>
#include <QMessageBox>
#include <QTimer>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    exitFlag = false;

    QWebSettings *settings = ui->webView->settings();
    settings->setAttribute(QWebSettings::AutoLoadImages, false);
    settings->setAttribute(QWebSettings::JavascriptEnabled, false);

    connect(ui->webView, SIGNAL(loadProgress(int)), this, SLOT(onLoadProgress(int)));

    connect(ui->webView, SIGNAL(loadFinished(bool)), this, SLOT(onLoadFinished(bool)));
}

Widget::~Widget()
{
    delete ui;
}

QImage Widget::DownLoadImage(QString url)
{
    QNetworkAccessManager mgr;

    QNetworkRequest request;
    request.setUrl(url);

    QNetworkReply *pReply = mgr.get(request);

    QEventLoop loop;
    connect(pReply, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();

    QByteArray buffer = pReply->readAll();

    QImage image = QImage::fromData(buffer);

    return image;

}

void Widget::closeEvent(QCloseEvent *e)
{
    QWidget::closeEvent(e);
    exitFlag = true;
}

void Widget::on_btnLoad_clicked()
{
    QString str = ui->lineEdit->text();
    ui->webView->load(QUrl(str));
}

void Widget::onLoadProgress(int progress)
{
    QString title = QString::number(progress) + "%";
    this->setWindowTitle(title);
}

void Widget::onLoadFinished(bool ok)
{
    Q_UNUSED(ok);

    QWebElementCollection elements = ui->webView->page()->mainFrame()->findAllElements(\
          "body > div.wrap > div > div > div.tupian > p > img");

    for (int i = 0; i < elements.count() && !exitFlag; ++i) {
        const QWebElement &ele = elements.at(i);

        QString url = ele.attribute("src");

        if (!url.contains("http"))
            url = "https:" + url;
        qDebug() << url;

        QImage image = DownLoadImage(url);

        QFileInfo info(url);
        QString fileName = "C:/Users/Administrator/Pictures/Saved Pictures/" + info.fileName();
        image.save(fileName);

        QEventLoop loop;
        QTimer::singleShot(2*1000, &loop, SLOT(quit()));
        loop.exec();
    }

    if(exitFlag)
        return;

    elements = ui->webView->page()->mainFrame()->findAllElements("body > div.wrap > div:nth-child(5) > div:nth-child(1) > div.next2 > a.article-next");

    if (elements.count() <= 0) {
        QMessageBox::information(this, "提示", "没有下一页", "确认");
        return;
    }

    QString nextPageUrl = "http://www.qqjay.com" + elements.at(0).attribute("href");
    ui->webView->load(nextPageUrl);
}

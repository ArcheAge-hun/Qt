#include "dialog.h"
#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog d;
    d.show();

    Widget w;
    w.show();

    w.m_pDlg = a.findChild<Dialog *>("d");
    d.m_pWdg = a.findChild<Widget *>("w");

    return a.exec();
}

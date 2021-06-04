/********************************************************************************
** Form generated from reading UI file 'cmainwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CMAINWIDGET_H
#define UI_CMAINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CMainWidget
{
public:

    void setupUi(QWidget *CMainWidget)
    {
        if (CMainWidget->objectName().isEmpty())
            CMainWidget->setObjectName(QStringLiteral("CMainWidget"));
        CMainWidget->resize(400, 300);

        retranslateUi(CMainWidget);

        QMetaObject::connectSlotsByName(CMainWidget);
    } // setupUi

    void retranslateUi(QWidget *CMainWidget)
    {
        CMainWidget->setWindowTitle(QApplication::translate("CMainWidget", "CMainWidget", 0));
    } // retranslateUi

};

namespace Ui {
    class CMainWidget: public Ui_CMainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CMAINWIDGET_H

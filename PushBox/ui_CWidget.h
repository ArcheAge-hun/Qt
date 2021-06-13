/********************************************************************************
** Form generated from reading UI file 'CWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CWIDGET_H
#define UI_CWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CWidget
{
public:

    void setupUi(QWidget *CWidget)
    {
        if (CWidget->objectName().isEmpty())
            CWidget->setObjectName(QStringLiteral("CWidget"));
        CWidget->resize(400, 300);

        retranslateUi(CWidget);

        QMetaObject::connectSlotsByName(CWidget);
    } // setupUi

    void retranslateUi(QWidget *CWidget)
    {
        CWidget->setWindowTitle(QApplication::translate("CWidget", "CWidget", 0));
    } // retranslateUi

};

namespace Ui {
    class CWidget: public Ui_CWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CWIDGET_H

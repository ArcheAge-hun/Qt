/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QCheckBox *checkBox1;
    QLineEdit *editKye1;
    QLabel *label;
    QSpinBox *spinBox1;
    QLabel *label_2;
    QPushButton *btnStart;
    QPushButton *btnStop;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(765, 575);
        checkBox1 = new QCheckBox(Widget);
        checkBox1->setObjectName(QStringLiteral("checkBox1"));
        checkBox1->setGeometry(QRect(70, 50, 71, 16));
        editKye1 = new QLineEdit(Widget);
        editKye1->setObjectName(QStringLiteral("editKye1"));
        editKye1->setGeometry(QRect(160, 50, 113, 20));
        label = new QLabel(Widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(290, 50, 54, 12));
        spinBox1 = new QSpinBox(Widget);
        spinBox1->setObjectName(QStringLiteral("spinBox1"));
        spinBox1->setGeometry(QRect(360, 50, 42, 22));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(430, 50, 31, 16));
        btnStart = new QPushButton(Widget);
        btnStart->setObjectName(QStringLiteral("btnStart"));
        btnStart->setGeometry(QRect(160, 360, 75, 23));
        btnStop = new QPushButton(Widget);
        btnStop->setObjectName(QStringLiteral("btnStop"));
        btnStop->setGeometry(QRect(300, 360, 75, 23));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0));
        checkBox1->setText(QApplication::translate("Widget", "\346\234\211\346\225\210", 0));
        label->setText(QApplication::translate("Widget", "\351\227\264\351\232\224", 0));
        label_2->setText(QApplication::translate("Widget", "\347\247\222", 0));
        btnStart->setText(QApplication::translate("Widget", "\345\274\200\345\247\213", 0));
        btnStop->setText(QApplication::translate("Widget", "\345\201\234\346\255\242", 0));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H

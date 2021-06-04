/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *btnOpen;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *btnPrevious;
    QLabel *labelViewer;
    QPushButton *btnNext;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEditName;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEditPath;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(400, 300);
        verticalLayout = new QVBoxLayout(Dialog);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        btnOpen = new QPushButton(Dialog);
        btnOpen->setObjectName(QStringLiteral("btnOpen"));

        horizontalLayout_4->addWidget(btnOpen);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_4);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        btnPrevious = new QPushButton(Dialog);
        btnPrevious->setObjectName(QStringLiteral("btnPrevious"));

        horizontalLayout_3->addWidget(btnPrevious);

        labelViewer = new QLabel(Dialog);
        labelViewer->setObjectName(QStringLiteral("labelViewer"));

        horizontalLayout_3->addWidget(labelViewer);

        btnNext = new QPushButton(Dialog);
        btnNext->setObjectName(QStringLiteral("btnNext"));

        horizontalLayout_3->addWidget(btnNext);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEditName = new QLineEdit(Dialog);
        lineEditName->setObjectName(QStringLiteral("lineEditName"));

        horizontalLayout_2->addWidget(lineEditName);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(Dialog);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEditPath = new QLineEdit(Dialog);
        lineEditPath->setObjectName(QStringLiteral("lineEditPath"));

        horizontalLayout->addWidget(lineEditPath);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", nullptr));
        btnOpen->setText(QApplication::translate("Dialog", "\351\200\211\346\213\251\345\233\276\347\211\207", nullptr));
        btnPrevious->setText(QApplication::translate("Dialog", "\344\270\212\344\270\200\345\274\240", nullptr));
        labelViewer->setText(QString());
        btnNext->setText(QApplication::translate("Dialog", "\344\270\213\344\270\200\345\274\240", nullptr));
        label_2->setText(QApplication::translate("Dialog", "\345\233\276\347\211\207\345\220\215\347\247\260\357\274\232", nullptr));
        lineEditName->setText(QString());
        label->setText(QApplication::translate("Dialog", "\345\233\276\347\211\207\350\267\257\345\276\204\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H

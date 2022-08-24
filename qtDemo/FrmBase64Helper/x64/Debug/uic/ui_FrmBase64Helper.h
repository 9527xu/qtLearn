/********************************************************************************
** Form generated from reading UI file 'FrmBase64Helper.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMBASE64HELPER_H
#define UI_FRMBASE64HELPER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FrmBase64HelperClass
{
public:
    QTextEdit *textEditBase64;
    QLabel *labelImage;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEditInputData;
    QPushButton *pushButtonOpenFile;
    QPushButton *pushButtonImageToBase64;
    QPushButton *pushButtonTextToBase64;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEditText;
    QPushButton *pushButtonClearDate;
    QPushButton *pushButtonBase64ToImage;
    QPushButton *pushButtonBase64ToText;
    QLabel *labelCostTimeTip;

    void setupUi(QWidget *FrmBase64HelperClass)
    {
        if (FrmBase64HelperClass->objectName().isEmpty())
            FrmBase64HelperClass->setObjectName(QString::fromUtf8("FrmBase64HelperClass"));
        FrmBase64HelperClass->setEnabled(true);
        FrmBase64HelperClass->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(FrmBase64HelperClass->sizePolicy().hasHeightForWidth());
        FrmBase64HelperClass->setSizePolicy(sizePolicy);
        textEditBase64 = new QTextEdit(FrmBase64HelperClass);
        textEditBase64->setObjectName(QString::fromUtf8("textEditBase64"));
        textEditBase64->setGeometry(QRect(30, 260, 256, 192));
        labelImage = new QLabel(FrmBase64HelperClass);
        labelImage->setObjectName(QString::fromUtf8("labelImage"));
        labelImage->setGeometry(QRect(10, 86, 491, 161));
        sizePolicy.setHeightForWidth(labelImage->sizePolicy().hasHeightForWidth());
        labelImage->setSizePolicy(sizePolicy);
        labelImage->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 241, 83);"));
        layoutWidget = new QWidget(FrmBase64HelperClass);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 313, 65));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lineEditInputData = new QLineEdit(layoutWidget);
        lineEditInputData->setObjectName(QString::fromUtf8("lineEditInputData"));
        lineEditInputData->setEnabled(true);

        horizontalLayout->addWidget(lineEditInputData);

        pushButtonOpenFile = new QPushButton(layoutWidget);
        pushButtonOpenFile->setObjectName(QString::fromUtf8("pushButtonOpenFile"));

        horizontalLayout->addWidget(pushButtonOpenFile);

        pushButtonImageToBase64 = new QPushButton(layoutWidget);
        pushButtonImageToBase64->setObjectName(QString::fromUtf8("pushButtonImageToBase64"));
        pushButtonImageToBase64->setEnabled(true);

        horizontalLayout->addWidget(pushButtonImageToBase64);

        pushButtonTextToBase64 = new QPushButton(layoutWidget);
        pushButtonTextToBase64->setObjectName(QString::fromUtf8("pushButtonTextToBase64"));

        horizontalLayout->addWidget(pushButtonTextToBase64);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lineEditText = new QLineEdit(layoutWidget);
        lineEditText->setObjectName(QString::fromUtf8("lineEditText"));
        lineEditText->setReadOnly(true);

        horizontalLayout_2->addWidget(lineEditText);

        pushButtonClearDate = new QPushButton(layoutWidget);
        pushButtonClearDate->setObjectName(QString::fromUtf8("pushButtonClearDate"));

        horizontalLayout_2->addWidget(pushButtonClearDate);

        pushButtonBase64ToImage = new QPushButton(layoutWidget);
        pushButtonBase64ToImage->setObjectName(QString::fromUtf8("pushButtonBase64ToImage"));

        horizontalLayout_2->addWidget(pushButtonBase64ToImage);

        pushButtonBase64ToText = new QPushButton(layoutWidget);
        pushButtonBase64ToText->setObjectName(QString::fromUtf8("pushButtonBase64ToText"));

        horizontalLayout_2->addWidget(pushButtonBase64ToText);


        verticalLayout->addLayout(horizontalLayout_2);

        labelCostTimeTip = new QLabel(layoutWidget);
        labelCostTimeTip->setObjectName(QString::fromUtf8("labelCostTimeTip"));

        verticalLayout->addWidget(labelCostTimeTip);


        retranslateUi(FrmBase64HelperClass);

        QMetaObject::connectSlotsByName(FrmBase64HelperClass);
    } // setupUi

    void retranslateUi(QWidget *FrmBase64HelperClass)
    {
        FrmBase64HelperClass->setWindowTitle(QApplication::translate("FrmBase64HelperClass", "FrmBase64Helper", nullptr));
        labelImage->setText(QString());
        pushButtonOpenFile->setText(QApplication::translate("FrmBase64HelperClass", "\346\211\223\345\274\200\346\226\207\344\273\266", nullptr));
        pushButtonImageToBase64->setText(QApplication::translate("FrmBase64HelperClass", "\345\233\276\347\211\207\350\275\254base64", nullptr));
        pushButtonTextToBase64->setText(QApplication::translate("FrmBase64HelperClass", "\346\226\207\345\255\227\350\275\254base64", nullptr));
        pushButtonClearDate->setText(QApplication::translate("FrmBase64HelperClass", "\346\270\205\347\251\272\346\225\260\346\215\256", nullptr));
        pushButtonBase64ToImage->setText(QApplication::translate("FrmBase64HelperClass", "base64\350\275\254\345\233\276\347\211\207", nullptr));
        pushButtonBase64ToText->setText(QApplication::translate("FrmBase64HelperClass", "base64\350\275\254\346\226\207\345\255\227", nullptr));
        labelCostTimeTip->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FrmBase64HelperClass: public Ui_FrmBase64HelperClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMBASE64HELPER_H

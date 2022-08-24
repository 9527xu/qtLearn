/********************************************************************************
** Form generated from reading UI file 'FrmUdpClient.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMUDPCLIENT_H
#define UI_FRMUDPCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FrmUdpClientClass
{
public:
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *textEditMain;
    QHBoxLayout *horizontalLayout;
    QComboBox *comboBoxData;
    QPushButton *pushButtonSend;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QCheckBox *checkBoxHexReceive;
    QCheckBox *checkBoxHexSend;
    QCheckBox *checkBoxAscii;
    QCheckBox *checkBoxShow;
    QCheckBox *checkBoxDebug;
    QCheckBox *checkBoxAutoSend;
    QComboBox *comboBoxInterval;
    QLabel *label;
    QComboBox *comboBoxBindIP;
    QLabel *label_2;
    QLineEdit *lineEditBindPort;
    QLabel *label_3;
    QLineEdit *lineEditServerIP;
    QLabel *label_4;
    QLineEdit *lineEditServerPort;
    QPushButton *pushButtonSave;
    QPushButton *pushButtonClear;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *FrmUdpClientClass)
    {
        if (FrmUdpClientClass->objectName().isEmpty())
            FrmUdpClientClass->setObjectName(QString::fromUtf8("FrmUdpClientClass"));
        FrmUdpClientClass->resize(1000, 600);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(FrmUdpClientClass->sizePolicy().hasHeightForWidth());
        FrmUdpClientClass->setSizePolicy(sizePolicy);
        horizontalLayout_2 = new QHBoxLayout(FrmUdpClientClass);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        textEditMain = new QTextEdit(FrmUdpClientClass);
        textEditMain->setObjectName(QString::fromUtf8("textEditMain"));

        verticalLayout_2->addWidget(textEditMain);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        comboBoxData = new QComboBox(FrmUdpClientClass);
        comboBoxData->setObjectName(QString::fromUtf8("comboBoxData"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(comboBoxData->sizePolicy().hasHeightForWidth());
        comboBoxData->setSizePolicy(sizePolicy1);
        comboBoxData->setEditable(true);

        horizontalLayout->addWidget(comboBoxData);

        pushButtonSend = new QPushButton(FrmUdpClientClass);
        pushButtonSend->setObjectName(QString::fromUtf8("pushButtonSend"));

        horizontalLayout->addWidget(pushButtonSend);


        verticalLayout_2->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout_2);

        frame = new QFrame(FrmUdpClientClass);
        frame->setObjectName(QString::fromUtf8("frame"));
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        checkBoxHexReceive = new QCheckBox(frame);
        checkBoxHexReceive->setObjectName(QString::fromUtf8("checkBoxHexReceive"));

        verticalLayout->addWidget(checkBoxHexReceive);

        checkBoxHexSend = new QCheckBox(frame);
        checkBoxHexSend->setObjectName(QString::fromUtf8("checkBoxHexSend"));

        verticalLayout->addWidget(checkBoxHexSend);

        checkBoxAscii = new QCheckBox(frame);
        checkBoxAscii->setObjectName(QString::fromUtf8("checkBoxAscii"));

        verticalLayout->addWidget(checkBoxAscii);

        checkBoxShow = new QCheckBox(frame);
        checkBoxShow->setObjectName(QString::fromUtf8("checkBoxShow"));

        verticalLayout->addWidget(checkBoxShow);

        checkBoxDebug = new QCheckBox(frame);
        checkBoxDebug->setObjectName(QString::fromUtf8("checkBoxDebug"));

        verticalLayout->addWidget(checkBoxDebug);

        checkBoxAutoSend = new QCheckBox(frame);
        checkBoxAutoSend->setObjectName(QString::fromUtf8("checkBoxAutoSend"));

        verticalLayout->addWidget(checkBoxAutoSend);

        comboBoxInterval = new QComboBox(frame);
        comboBoxInterval->setObjectName(QString::fromUtf8("comboBoxInterval"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(comboBoxInterval->sizePolicy().hasHeightForWidth());
        comboBoxInterval->setSizePolicy(sizePolicy2);

        verticalLayout->addWidget(comboBoxInterval);

        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        comboBoxBindIP = new QComboBox(frame);
        comboBoxBindIP->setObjectName(QString::fromUtf8("comboBoxBindIP"));
        sizePolicy2.setHeightForWidth(comboBoxBindIP->sizePolicy().hasHeightForWidth());
        comboBoxBindIP->setSizePolicy(sizePolicy2);

        verticalLayout->addWidget(comboBoxBindIP);

        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        lineEditBindPort = new QLineEdit(frame);
        lineEditBindPort->setObjectName(QString::fromUtf8("lineEditBindPort"));
        sizePolicy2.setHeightForWidth(lineEditBindPort->sizePolicy().hasHeightForWidth());
        lineEditBindPort->setSizePolicy(sizePolicy2);

        verticalLayout->addWidget(lineEditBindPort);

        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        lineEditServerIP = new QLineEdit(frame);
        lineEditServerIP->setObjectName(QString::fromUtf8("lineEditServerIP"));
        sizePolicy2.setHeightForWidth(lineEditServerIP->sizePolicy().hasHeightForWidth());
        lineEditServerIP->setSizePolicy(sizePolicy2);

        verticalLayout->addWidget(lineEditServerIP);

        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout->addWidget(label_4);

        lineEditServerPort = new QLineEdit(frame);
        lineEditServerPort->setObjectName(QString::fromUtf8("lineEditServerPort"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(lineEditServerPort->sizePolicy().hasHeightForWidth());
        lineEditServerPort->setSizePolicy(sizePolicy3);

        verticalLayout->addWidget(lineEditServerPort);

        pushButtonSave = new QPushButton(frame);
        pushButtonSave->setObjectName(QString::fromUtf8("pushButtonSave"));

        verticalLayout->addWidget(pushButtonSave);

        pushButtonClear = new QPushButton(frame);
        pushButtonClear->setObjectName(QString::fromUtf8("pushButtonClear"));

        verticalLayout->addWidget(pushButtonClear);

        verticalSpacer = new QSpacerItem(20, 273, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout_2->addWidget(frame);


        retranslateUi(FrmUdpClientClass);

        QMetaObject::connectSlotsByName(FrmUdpClientClass);
    } // setupUi

    void retranslateUi(QWidget *FrmUdpClientClass)
    {
        FrmUdpClientClass->setWindowTitle(QApplication::translate("FrmUdpClientClass", "FrmUdpClient", nullptr));
        pushButtonSend->setText(QApplication::translate("FrmUdpClientClass", "\345\217\221\351\200\201", nullptr));
        checkBoxHexReceive->setText(QApplication::translate("FrmUdpClientClass", "16\350\277\233\345\210\266\346\216\245\346\224\266", nullptr));
        checkBoxHexSend->setText(QApplication::translate("FrmUdpClientClass", "16\350\277\233\345\210\266\345\217\221\351\200\201", nullptr));
        checkBoxAscii->setText(QApplication::translate("FrmUdpClientClass", "\346\216\247\345\210\266\345\255\227\347\254\246", nullptr));
        checkBoxShow->setText(QApplication::translate("FrmUdpClientClass", "\346\232\202\345\201\234\346\230\276\347\244\272", nullptr));
        checkBoxDebug->setText(QApplication::translate("FrmUdpClientClass", "\346\250\241\346\213\237\350\256\276\345\244\207", nullptr));
        checkBoxAutoSend->setText(QApplication::translate("FrmUdpClientClass", "\345\256\232\346\227\266\345\217\221\351\200\201", nullptr));
        label->setText(QApplication::translate("FrmUdpClientClass", "\347\273\221\345\256\232\345\234\260\345\235\200", nullptr));
        label_2->setText(QApplication::translate("FrmUdpClientClass", "\347\273\221\345\256\232\347\253\257\345\217\243", nullptr));
        label_3->setText(QApplication::translate("FrmUdpClientClass", "\346\234\215\345\212\241\345\231\250\345\234\260\345\235\200", nullptr));
        label_4->setText(QApplication::translate("FrmUdpClientClass", "\346\234\215\345\212\241\345\231\250\347\253\257\345\217\243", nullptr));
        pushButtonSave->setText(QApplication::translate("FrmUdpClientClass", "\344\277\235\345\255\230", nullptr));
        pushButtonClear->setText(QApplication::translate("FrmUdpClientClass", "\346\270\205\347\251\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FrmUdpClientClass: public Ui_FrmUdpClientClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMUDPCLIENT_H

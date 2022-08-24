/********************************************************************************
** Form generated from reading UI file 'FrmTcpServer.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMTCPSERVER_H
#define UI_FRMTCPSERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FrmTcpServerClass
{
public:
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *textEditMain;
    QHBoxLayout *horizontalLayout;
    QComboBox *comboBoxData;
    QPushButton *pushButton_5;
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
    QComboBox *comboBoxListenIP;
    QLabel *label_2;
    QLineEdit *lineEditListenPort;
    QPushButton *pushButtonListen;
    QPushButton *pushButtonSave;
    QPushButton *pushButtonClear;
    QPushButton *pushButtonRemove;
    QLabel *labelCount;
    QListWidget *listWidget;
    QCheckBox *checkBoxSelectAll;

    void setupUi(QWidget *FrmTcpServerClass)
    {
        if (FrmTcpServerClass->objectName().isEmpty())
            FrmTcpServerClass->setObjectName(QString::fromUtf8("FrmTcpServerClass"));
        FrmTcpServerClass->resize(1000, 600);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(FrmTcpServerClass->sizePolicy().hasHeightForWidth());
        FrmTcpServerClass->setSizePolicy(sizePolicy);
        horizontalLayout_2 = new QHBoxLayout(FrmTcpServerClass);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        textEditMain = new QTextEdit(FrmTcpServerClass);
        textEditMain->setObjectName(QString::fromUtf8("textEditMain"));

        verticalLayout_2->addWidget(textEditMain);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        comboBoxData = new QComboBox(FrmTcpServerClass);
        comboBoxData->setObjectName(QString::fromUtf8("comboBoxData"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(comboBoxData->sizePolicy().hasHeightForWidth());
        comboBoxData->setSizePolicy(sizePolicy1);
        comboBoxData->setEditable(true);

        horizontalLayout->addWidget(comboBoxData);

        pushButton_5 = new QPushButton(FrmTcpServerClass);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        horizontalLayout->addWidget(pushButton_5);


        verticalLayout_2->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout_2);

        frame = new QFrame(FrmTcpServerClass);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy2);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
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
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(comboBoxInterval->sizePolicy().hasHeightForWidth());
        comboBoxInterval->setSizePolicy(sizePolicy3);

        verticalLayout->addWidget(comboBoxInterval);

        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(label);

        comboBoxListenIP = new QComboBox(frame);
        comboBoxListenIP->setObjectName(QString::fromUtf8("comboBoxListenIP"));
        sizePolicy3.setHeightForWidth(comboBoxListenIP->sizePolicy().hasHeightForWidth());
        comboBoxListenIP->setSizePolicy(sizePolicy3);

        verticalLayout->addWidget(comboBoxListenIP);

        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(label_2);

        lineEditListenPort = new QLineEdit(frame);
        lineEditListenPort->setObjectName(QString::fromUtf8("lineEditListenPort"));
        sizePolicy3.setHeightForWidth(lineEditListenPort->sizePolicy().hasHeightForWidth());
        lineEditListenPort->setSizePolicy(sizePolicy3);

        verticalLayout->addWidget(lineEditListenPort);

        pushButtonListen = new QPushButton(frame);
        pushButtonListen->setObjectName(QString::fromUtf8("pushButtonListen"));

        verticalLayout->addWidget(pushButtonListen);

        pushButtonSave = new QPushButton(frame);
        pushButtonSave->setObjectName(QString::fromUtf8("pushButtonSave"));

        verticalLayout->addWidget(pushButtonSave);

        pushButtonClear = new QPushButton(frame);
        pushButtonClear->setObjectName(QString::fromUtf8("pushButtonClear"));

        verticalLayout->addWidget(pushButtonClear);

        pushButtonRemove = new QPushButton(frame);
        pushButtonRemove->setObjectName(QString::fromUtf8("pushButtonRemove"));

        verticalLayout->addWidget(pushButtonRemove);

        labelCount = new QLabel(frame);
        labelCount->setObjectName(QString::fromUtf8("labelCount"));
        sizePolicy.setHeightForWidth(labelCount->sizePolicy().hasHeightForWidth());
        labelCount->setSizePolicy(sizePolicy);
        labelCount->setFrameShape(QFrame::Box);
        labelCount->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(labelCount);

        listWidget = new QListWidget(frame);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy4);

        verticalLayout->addWidget(listWidget);

        checkBoxSelectAll = new QCheckBox(frame);
        checkBoxSelectAll->setObjectName(QString::fromUtf8("checkBoxSelectAll"));

        verticalLayout->addWidget(checkBoxSelectAll);


        horizontalLayout_2->addWidget(frame);


        retranslateUi(FrmTcpServerClass);
        QObject::connect(pushButtonListen, SIGNAL(clicked()), FrmTcpServerClass, SLOT(on_listen_clicked()));
        QObject::connect(pushButtonSave, SIGNAL(clicked()), FrmTcpServerClass, SLOT(on_save_clicked()));
        QObject::connect(pushButtonClear, SIGNAL(clicked()), FrmTcpServerClass, SLOT(on_clear_clicked()));
        QObject::connect(pushButtonRemove, SIGNAL(clicked()), FrmTcpServerClass, SLOT(on_remove_clicked()));
        QObject::connect(pushButton_5, SIGNAL(clicked()), FrmTcpServerClass, SLOT(on_send_clicked()));
        QObject::connect(checkBoxHexReceive, SIGNAL(stateChanged(int)), FrmTcpServerClass, SLOT(stateChange()));
        QObject::connect(checkBoxHexSend, SIGNAL(stateChanged(int)), FrmTcpServerClass, SLOT(stateChange()));
        QObject::connect(checkBoxAscii, SIGNAL(stateChanged(int)), FrmTcpServerClass, SLOT(stateChange()));
        QObject::connect(checkBoxDebug, SIGNAL(stateChanged(int)), FrmTcpServerClass, SLOT(stateChange()));
        QObject::connect(checkBoxAutoSend, SIGNAL(stateChanged(int)), FrmTcpServerClass, SLOT(stateChange()));
        QObject::connect(comboBoxInterval, SIGNAL(currentIndexChanged(int)), FrmTcpServerClass, SLOT(stateChange()));
        QObject::connect(comboBoxListenIP, SIGNAL(currentIndexChanged(int)), FrmTcpServerClass, SLOT(stateChange()));
        QObject::connect(lineEditListenPort, SIGNAL(textChanged(QString)), FrmTcpServerClass, SLOT(stateChange()));
        QObject::connect(checkBoxSelectAll, SIGNAL(stateChanged(int)), FrmTcpServerClass, SLOT(stateChange()));

        QMetaObject::connectSlotsByName(FrmTcpServerClass);
    } // setupUi

    void retranslateUi(QWidget *FrmTcpServerClass)
    {
        FrmTcpServerClass->setWindowTitle(QApplication::translate("FrmTcpServerClass", "FrmTcpServer", nullptr));
        pushButton_5->setText(QApplication::translate("FrmTcpServerClass", "\345\217\221\351\200\201", nullptr));
        checkBoxHexReceive->setText(QApplication::translate("FrmTcpServerClass", "16\350\277\233\345\210\266\346\216\245\346\224\266", nullptr));
        checkBoxHexSend->setText(QApplication::translate("FrmTcpServerClass", "16\350\277\233\345\210\266\345\217\221\351\200\201", nullptr));
        checkBoxAscii->setText(QApplication::translate("FrmTcpServerClass", "\346\216\247\345\210\266\345\255\227\347\254\246", nullptr));
        checkBoxShow->setText(QApplication::translate("FrmTcpServerClass", "\346\232\202\345\201\234\346\230\276\347\244\272", nullptr));
        checkBoxDebug->setText(QApplication::translate("FrmTcpServerClass", "\346\250\241\346\213\237\350\256\276\345\244\207", nullptr));
        checkBoxAutoSend->setText(QApplication::translate("FrmTcpServerClass", "\345\256\232\346\227\266\345\217\221\351\200\201", nullptr));
        label->setText(QApplication::translate("FrmTcpServerClass", "\347\233\221\345\220\254\345\234\260\345\235\200", nullptr));
        label_2->setText(QApplication::translate("FrmTcpServerClass", "\347\233\221\345\220\254\347\253\257\345\217\243", nullptr));
        pushButtonListen->setText(QApplication::translate("FrmTcpServerClass", "\347\233\221\345\220\254", nullptr));
        pushButtonSave->setText(QApplication::translate("FrmTcpServerClass", "\344\277\235\345\255\230", nullptr));
        pushButtonClear->setText(QApplication::translate("FrmTcpServerClass", "\346\270\205\347\251\272", nullptr));
        pushButtonRemove->setText(QApplication::translate("FrmTcpServerClass", "\347\247\273\351\231\244", nullptr));
        labelCount->setText(QApplication::translate("FrmTcpServerClass", "\345\205\2610\344\270\252\345\256\242\346\210\267\347\253\257", nullptr));
        checkBoxSelectAll->setText(QApplication::translate("FrmTcpServerClass", "\345\257\271\346\211\200\346\234\211\345\256\242\346\210\267\347\253\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FrmTcpServerClass: public Ui_FrmTcpServerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMTCPSERVER_H

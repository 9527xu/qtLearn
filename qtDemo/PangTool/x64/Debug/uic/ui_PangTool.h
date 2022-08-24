/********************************************************************************
** Form generated from reading UI file 'PangTool.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PANGTOOL_H
#define UI_PANGTOOL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PangToolClass
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEditFilePath;
    QPushButton *pushButtonFile;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEditDir;
    QPushButton *pushButtonDir;
    QHBoxLayout *horizontalLayout_3;
    QProgressBar *progressBar;
    QPushButton *pushButtonTransForm;
    QTextEdit *textEdit;

    void setupUi(QWidget *PangToolClass)
    {
        if (PangToolClass->objectName().isEmpty())
            PangToolClass->setObjectName(QString::fromUtf8("PangToolClass"));
        PangToolClass->resize(600, 400);
        verticalLayout_2 = new QVBoxLayout(PangToolClass);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lineEditFilePath = new QLineEdit(PangToolClass);
        lineEditFilePath->setObjectName(QString::fromUtf8("lineEditFilePath"));

        horizontalLayout->addWidget(lineEditFilePath);

        pushButtonFile = new QPushButton(PangToolClass);
        pushButtonFile->setObjectName(QString::fromUtf8("pushButtonFile"));

        horizontalLayout->addWidget(pushButtonFile);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lineEditDir = new QLineEdit(PangToolClass);
        lineEditDir->setObjectName(QString::fromUtf8("lineEditDir"));

        horizontalLayout_2->addWidget(lineEditDir);

        pushButtonDir = new QPushButton(PangToolClass);
        pushButtonDir->setObjectName(QString::fromUtf8("pushButtonDir"));

        horizontalLayout_2->addWidget(pushButtonDir);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        progressBar = new QProgressBar(PangToolClass);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(0);

        horizontalLayout_3->addWidget(progressBar);

        pushButtonTransForm = new QPushButton(PangToolClass);
        pushButtonTransForm->setObjectName(QString::fromUtf8("pushButtonTransForm"));

        horizontalLayout_3->addWidget(pushButtonTransForm);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_2->addLayout(verticalLayout);

        textEdit = new QTextEdit(PangToolClass);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        verticalLayout_2->addWidget(textEdit);


        retranslateUi(PangToolClass);
        QObject::connect(pushButtonFile, SIGNAL(clicked()), PangToolClass, SLOT(on_file_clicked()));
        QObject::connect(pushButtonDir, SIGNAL(clicked()), PangToolClass, SLOT(on_dir_clicked()));
        QObject::connect(pushButtonTransForm, SIGNAL(clicked()), PangToolClass, SLOT(on_transform_clicked()));

        QMetaObject::connectSlotsByName(PangToolClass);
    } // setupUi

    void retranslateUi(QWidget *PangToolClass)
    {
        PangToolClass->setWindowTitle(QApplication::translate("PangToolClass", "PangTool", nullptr));
        pushButtonFile->setText(QApplication::translate("PangToolClass", "\351\200\211\346\213\251\346\226\207\344\273\266", nullptr));
        pushButtonDir->setText(QApplication::translate("PangToolClass", "\351\200\211\346\213\251\347\233\256\345\275\225", nullptr));
        pushButtonTransForm->setText(QApplication::translate("PangToolClass", "\346\211\247\350\241\214\350\275\254\346\215\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PangToolClass: public Ui_PangToolClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PANGTOOL_H

#pragma once
#include<qline.h>
#include<qimage.h>
#include"Base64Helper.h"
#include<qelapsedtimer.h>
#include<qmessagebox.h>
#include<qpushbutton.h>
#include <QtWidgets/QWidget>
#include "ui_FrmBase64Helper.h"
#include<qfiledialog.h>
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
class FrmBase64Helper : public QWidget
{
    Q_OBJECT

public:
    FrmBase64Helper(QWidget *parent = nullptr);
    ~FrmBase64Helper();
private slots:

    void clear();
    void openFile();
    void imageToBase64();
    void base64ToImage();
    void textToBase64();
    void base64ToText();
private:
    Ui::FrmBase64HelperClass ui;
};

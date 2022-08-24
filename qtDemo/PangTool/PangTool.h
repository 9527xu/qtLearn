#pragma once
#include<qtimer.h>
#include<QTime>
#include <QtWidgets/QWidget>
#include "ui_PangTool.h"
#include<QtGui>
#include<QtCore>
#include<QWidget>
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
QT_BEGIN_NAMESPACE
namespace Ui { class PangToolClass; };
QT_END_NAMESPACE

class PangTool : public QWidget
{
    Q_OBJECT

public:
    PangTool(QWidget *parent = nullptr);
    ~PangTool();
private slots:
    void on_dir_clicked();
    void on_file_clicked();
    void on_transform_clicked();
private:
    Ui::PangToolClass *ui;
};

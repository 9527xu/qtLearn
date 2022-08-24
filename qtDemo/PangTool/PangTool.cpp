#include "PangTool.h"
#include <QtWidgets/qfiledialog.h>
#define TIMEMS QTime::currentTime().toString("hh:mm:ss zzz")
PangTool::PangTool(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PangToolClass())
{
    ui->setupUi(this);
    ui->progressBar->setRange(0, 0);
    ui->progressBar->setValue(0);
}

PangTool::~PangTool()
{
    delete ui;
}

void PangTool::on_dir_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, "ѡ��Ŀ¼");
    if (!dir.isEmpty())
    {
        ui->lineEditDir->setText(dir);
        ui->progressBar->setValue(0);
    }
}

void PangTool::on_file_clicked()
{
    QString file = QFileDialog::getOpenFileName(this, "ѡ��png�ļ�", qApp->applicationDirPath(), "pngͼƬ�ļ�(*.png)");
    if (!file.isEmpty())
    {
        ui->lineEditFilePath->setText(file);
        ui->progressBar->setValue(0);
    }
}

void PangTool::on_transform_clicked()
{
    QStringList files;
    //�������ļ��������
    QString singleFile = ui->lineEditFilePath->text().trimmed();
    if (!singleFile.isEmpty())
    {
        files.append(singleFile);
    }
    //�����ļ�
    QString currentDir = ui->lineEditDir->text().trimmed();
    if (!currentDir.isEmpty())
    {
        QDir imagePath(currentDir);
        QStringList filter;
        filter.append("*.png");
        QStringList list = imagePath.entryList(filter);
        for (const auto& str : list)
        {
            files.append(currentDir + "/" + str);
        }
    }
    ui->progressBar->setRange(0, files.count());
    ui->progressBar->setValue(0);
    ui->textEdit->clear();
    int count = 0;
    for (const auto& file : files)
    {
        ui->textEdit->append(QString("%1->%2").arg(TIMEMS).arg(file));
        QImage image(file);
        image.save(file, "png");
        ++count;
        ui->progressBar->setValue(count);
        qApp->processEvents();
    }
    ui->textEdit->append(QString("%1->������ɣ���%2���ļ�").arg(TIMEMS).arg(files.count()));
}

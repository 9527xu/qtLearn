#include "FrmBase64Helper.h"

FrmBase64Helper::FrmBase64Helper(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    
    connect(ui.pushButtonOpenFile, &QPushButton::clicked,this,&FrmBase64Helper::openFile);
    connect(ui.pushButtonClearDate, &QPushButton::clicked, this, &FrmBase64Helper::clear);
    connect(ui.pushButtonImageToBase64, &QPushButton::clicked, this, &FrmBase64Helper::imageToBase64);
    connect(ui.pushButtonBase64ToImage, &QPushButton::clicked, this, &FrmBase64Helper::base64ToImage);
    connect(ui.pushButtonTextToBase64, &QPushButton::clicked, this, &FrmBase64Helper::textToBase64);
    connect(ui.pushButtonBase64ToText, &QPushButton::clicked, this, &FrmBase64Helper::base64ToText);
}

FrmBase64Helper::~FrmBase64Helper()
{}

void FrmBase64Helper::openFile()
{
    
        //���ף����⣬Ĭ�ϴ�·����ѡ����������
    QString fileName = QFileDialog::getOpenFileName(this, "ѡ����Ҫת����ͼƬ","", "ͼƬ(*.png *.bmp *.jpg)");
    if (!fileName.isEmpty())
    {
        ui.lineEditInputData->setText(fileName);
        ui.pushButtonImageToBase64->setEnabled(true);
        QPixmap pix;
        if (!pix.load(fileName))
        {
            QMessageBox::critical(this, "ͼƬ", "ͼƬ·������");
            return;
        }
        pix = pix.scaled(ui.labelImage->size() - QSize(4, 4), Qt::KeepAspectRatio);//�����ܴ��չʾ����������
        ui.labelImage->setPixmap(pix);
    }
}

void FrmBase64Helper::imageToBase64()
{
    //��ʱ
    QElapsedTimer time;
    time.start();
    QString fileName = ui.lineEditInputData->text().trimmed();//��ȡ�ı����ݣ������β�ո�
    if (!fileName.isEmpty())
    {
        QImage image;
        if (!image.load(fileName))
        {
            QMessageBox::critical(this, "ͼƬ", "ͼƬת��ʧ��");
        }
        ui.textEditBase64->setText(Base64Helper::imageToBase64(image));
    }
    //ͳ����ʱ
#if (QT_VERSION>=QT_VERSION_CHECK(4,8,0))
    double elapsed = (double)time.nsecsElapsed() / 1000000;//����
#else
    double elapsed = (double)time.elapsed();
#endif // (QT_VERSION>=QT_VERSION_CHECK(4,8,0)
    QString strTime = QString::number(elapsed, 'f', 3);//�Ը���������ʽ������3λС����
    ui.labelCostTimeTip->setText(QString("ͼƬתbase64��ʱ%1����").arg(strTime));
}

void FrmBase64Helper::base64ToImage()
{
    QElapsedTimer time;
    time.start();
    QString text = ui.textEditBase64->toPlainText().trimmed();//��ȡ���ı���ȥ����β�ո�
    if (!text.isEmpty())
    {
        QPixmap pix = QPixmap::fromImage(Base64Helper::base64ToImage(text));
        pix = pix.scaled(ui.labelImage->size() - QSize(4, 4), Qt::KeepAspectRatio);
        ui.labelImage->setPixmap(pix);
    }
    //ͳ����ʱ
#if (QT_VERSION>=QT_VERSION_CHECK(4,8,0))
    double elapsed = (double)time.nsecsElapsed() / 1000000;
#else
    double elapsed = (double)time.elapsed();
#endif // (QT_VERSION>=QT_VERSION_CHECK(4,8,0))
    QString strTime = QString::number(elapsed, 'f', 3);
    ui.labelCostTimeTip->setText(QString("base64תͼƬ��ʱ%1����").arg(strTime));

}

void FrmBase64Helper::textToBase64()
{
    
    QString text = ui.lineEditInputData->text();
        
    if (!text.isEmpty())
    {
        ui.textEditBase64->setText(Base64Helper::textToBase64(text));
    }
}

void FrmBase64Helper::base64ToText()
{
    QString text = ui.textEditBase64->toPlainText().trimmed();
    if (!text.isEmpty())
    {
        ui.lineEditText->setText(Base64Helper::base64ToText(text));
    }
}

void FrmBase64Helper::clear()
{
    ui.lineEditInputData->clear();
    ui.lineEditText->clear();
    ui.labelCostTimeTip->clear();
    ui.textEditBase64->clear();
    ui.labelImage->clear();
}

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
    
        //父亲，标题，默认打开路径，选择类型限制
    QString fileName = QFileDialog::getOpenFileName(this, "选择想要转换的图片","", "图片(*.png *.bmp *.jpg)");
    if (!fileName.isEmpty())
    {
        ui.lineEditInputData->setText(fileName);
        ui.pushButtonImageToBase64->setEnabled(true);
        QPixmap pix;
        if (!pix.load(fileName))
        {
            QMessageBox::critical(this, "图片", "图片路径错误");
            return;
        }
        pix = pix.scaled(ui.labelImage->size() - QSize(4, 4), Qt::KeepAspectRatio);//尽可能大地展示在所定区域
        ui.labelImage->setPixmap(pix);
    }
}

void FrmBase64Helper::imageToBase64()
{
    //计时
    QElapsedTimer time;
    time.start();
    QString fileName = ui.lineEditInputData->text().trimmed();//获取文本内容，清除首尾空格
    if (!fileName.isEmpty())
    {
        QImage image;
        if (!image.load(fileName))
        {
            QMessageBox::critical(this, "图片", "图片转换失败");
        }
        ui.textEditBase64->setText(Base64Helper::imageToBase64(image));
    }
    //统计用时
#if (QT_VERSION>=QT_VERSION_CHECK(4,8,0))
    double elapsed = (double)time.nsecsElapsed() / 1000000;//纳米
#else
    double elapsed = (double)time.elapsed();
#endif // (QT_VERSION>=QT_VERSION_CHECK(4,8,0)
    QString strTime = QString::number(elapsed, 'f', 3);//以浮点数的形式，保留3位小数点
    ui.labelCostTimeTip->setText(QString("图片转base64用时%1毫秒").arg(strTime));
}

void FrmBase64Helper::base64ToImage()
{
    QElapsedTimer time;
    time.start();
    QString text = ui.textEditBase64->toPlainText().trimmed();//获取纯文本，去掉首尾空格
    if (!text.isEmpty())
    {
        QPixmap pix = QPixmap::fromImage(Base64Helper::base64ToImage(text));
        pix = pix.scaled(ui.labelImage->size() - QSize(4, 4), Qt::KeepAspectRatio);
        ui.labelImage->setPixmap(pix);
    }
    //统计用时
#if (QT_VERSION>=QT_VERSION_CHECK(4,8,0))
    double elapsed = (double)time.nsecsElapsed() / 1000000;
#else
    double elapsed = (double)time.elapsed();
#endif // (QT_VERSION>=QT_VERSION_CHECK(4,8,0))
    QString strTime = QString::number(elapsed, 'f', 3);
    ui.labelCostTimeTip->setText(QString("base64转图片用时%1毫秒").arg(strTime));

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

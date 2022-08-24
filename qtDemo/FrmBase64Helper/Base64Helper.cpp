#include "Base64Helper.h"

Base64Helper::Base64Helper()
{}

Base64Helper::~Base64Helper()
{}

QString Base64Helper::imageToBase64(const QImage & image)
{
	
	QByteArray data;
	QBuffer buffer(&data);
	image.save(&buffer, "JPG");//将图片以jpg形式写入缓冲区中
	data = data.toBase64();
	return QString(data);
}

QImage Base64Helper::base64ToImage(const QString& data)
{
	QImage image;
	image.loadFromData(QByteArray::fromBase64(data.toUtf8()));
	return image;
}

QString Base64Helper::textToBase64(const QString& data)
{
	if (data.isEmpty())
	{
		return "";
	}
	return QString(data.toLatin1().toBase64());
}

QString Base64Helper::base64ToText(const QString& data)
{
	return QString(data.toLatin1());
}

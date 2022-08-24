#pragma once
#include<qmessagebox.h>
#include<qimage.h>
#include<qstring.h>
#include<qbuffer.h>
#include<qbytearray.h>
class Base64Helper 
{
public:
	Base64Helper();
	~Base64Helper();
	static QString imageToBase64(const QImage& image);//图片转base64字符串
	static QImage base64ToImage(const QString& data);//base64字符串转图片
	static QString textToBase64(const QString& data);//文本转base64
	static QString base64ToText(const QString& data);//base64转文本
};

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
	static QString imageToBase64(const QImage& image);//ͼƬתbase64�ַ���
	static QImage base64ToImage(const QString& data);//base64�ַ���תͼƬ
	static QString textToBase64(const QString& data);//�ı�תbase64
	static QString base64ToText(const QString& data);//base64ת�ı�
};

#pragma once
#include<qdebug.h>
#include<qmap.h>
#include<qstringlist.h>
#include<qfont.h>
#include <QWidget>
#include "ui_FrmTcpServer.h"
#include<QtNetwork>
#include "TcpServer.h"
class FrmTcpServer : public QWidget
{
	Q_OBJECT

public:
	FrmTcpServer(QWidget *parent = nullptr);
	~FrmTcpServer();
private slots:
	void disconnected(const QString& ip, int port);//��ʾ�Ͽ����ӿͻ���
	void connected(const QString& ip, int port);//��ʾ���ӵĿͻ���
	void error(const QString& ip, int port, const QString& error);//����error��Ϣ
	void sendData(const QString& ip, int port, const QString& data);//��ʾ���͵���Ϣ
	void receiveData(const QString& ip, int port, const QString& data);//��ʾ�յ�����Ϣ
	void on_listen_clicked();
	void on_save_clicked();
	void on_clear_clicked();
	void on_send_clicked();
	void on_remove_clicked();
	void stateChange();
private:
	void initForm();
	void initConfig();
	void initTimer();
	void append(int type, const QString& data, bool clear = false);
	
	Ui::FrmTcpServerClass *ui;
	TcpServer* serverSocket_=new TcpServer(this);
	bool isOk_=false;//�Ƿ�ʼ����
	QTimer *timer_=new QTimer(this);//��ʱ������Ϣ����
};

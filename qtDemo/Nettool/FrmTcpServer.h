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
	void disconnected(const QString& ip, int port);//显示断开连接客户端
	void connected(const QString& ip, int port);//显示连接的客户端
	void error(const QString& ip, int port, const QString& error);//传达error信息
	void sendData(const QString& ip, int port, const QString& data);//显示发送的信息
	void receiveData(const QString& ip, int port, const QString& data);//显示收到的信息
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
	bool isOk_=false;//是否开始监听
	QTimer *timer_=new QTimer(this);//定时发送消息对象
};

#pragma once
#include "ui_FrmTcpClient.h"
#include<qdebug.h>
#include<qtimer.h>
#include<qtextedit.h>
#include<qcheckbox.h>
#include <QWidget>
#include <QtNetwork>
#include<time.h>
#include<qfont.h>
#include"quihelperdata.h"
namespace Ui
{
	class frmTcpClient;
}
class FrmTcpClient : public QWidget
{
	Q_OBJECT

public:
	FrmTcpClient(QWidget *parent = nullptr);
	~FrmTcpClient();
private:
	void initConfig();
	void initForm();//初始化界面
	void append(int type, const QString& data, bool clear = false);//显示消息到界面
	
	void initTimer();//对定时器更新
	void sendData(const QString&data);//发送信息
protected:
	//重写事件过滤器
	bool eventFilter(QObject* watched, QEvent* event);
private slots:
	void disconnected();
	void connected();
	void readData();
	void error();//处理错误消息
	void on_save_clicked();
	void on_connected_clicked();
	void on_clear_clicked();
	void on_send_clicked();//填充发送的信息
	void on_checkbox_stateChanged();//处理选项框发生变化
private:
	Ui::FrmTcpClientClass *ui_;
	bool isOk_=false;//是否连接上了服务器
	QTcpSocket* socket_=new QTcpSocket();
	QTimer* timer_=new QTimer(this);//定时器，用于定时发送消息

};

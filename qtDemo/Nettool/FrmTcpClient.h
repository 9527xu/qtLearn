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
	void initForm();//��ʼ������
	void append(int type, const QString& data, bool clear = false);//��ʾ��Ϣ������
	
	void initTimer();//�Զ�ʱ������
	void sendData(const QString&data);//������Ϣ
protected:
	//��д�¼�������
	bool eventFilter(QObject* watched, QEvent* event);
private slots:
	void disconnected();
	void connected();
	void readData();
	void error();//���������Ϣ
	void on_save_clicked();
	void on_connected_clicked();
	void on_clear_clicked();
	void on_send_clicked();//��䷢�͵���Ϣ
	void on_checkbox_stateChanged();//����ѡ������仯
private:
	Ui::FrmTcpClientClass *ui_;
	bool isOk_=false;//�Ƿ��������˷�����
	QTcpSocket* socket_=new QTcpSocket();
	QTimer* timer_=new QTimer(this);//��ʱ�������ڶ�ʱ������Ϣ

};

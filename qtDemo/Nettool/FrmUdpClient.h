#pragma once
#include<QtCore>
#include "ui_FrmUdpClient.h"
#include<qcombobox.h>
#include"appdata.h"
#include <QWidget>
#include<QtNetwork>
#include<qtimer.h>
#include<QtGui>
QT_BEGIN_NAMESPACE
namespace Ui { class FrmUdpClientClass; };
QT_END_NAMESPACE

class FrmUdpClient : public QWidget
{
	Q_OBJECT

public:
	explicit FrmUdpClient(QWidget *parent = nullptr);
	~FrmUdpClient();
private:
	bool eventFilter(QObject* watched, QEvent* event);
	void initForm();
	void initConfig();
	void stateChange();
	void initTimer();
	void append(int type, const QString& data, bool clear = false);//显示信息到界面
private slots:

	void slot_readData();
	void slot_error();
	void slot_sendData(const QString& ip, int port, const QString& data);
	void on_save_clicked();
	void on_clear_clicked();
	void on_send_clicked();
private:
	Ui::FrmUdpClientClass *ui;
	QUdpSocket* socket_=new QUdpSocket(this);
	QTimer *timer_=new QTimer(this);
};

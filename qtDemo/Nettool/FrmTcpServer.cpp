#include "FrmTcpServer.h"
#include<qset.h>
FrmTcpServer::FrmTcpServer(QWidget *parent)
	: QWidget(parent),ui(new Ui::FrmTcpServerClass)
{
	
	ui->setupUi(this);
	this->initForm();
	this->initConfig();
	on_listen_clicked();
}

FrmTcpServer::~FrmTcpServer()
{
	serverSocket_->stop();
	delete ui;
}

void FrmTcpServer::connected(const QString& ip, int port)//显示连接的信息
{
	this->append(0, QString("[%1:%2] %3").arg(ip).arg(port).arg("客户端上线"));
	QString str = QString("%1:%2").arg(ip).arg(port);
	ui->listWidget->addItem(str);
	ui->labelCount->setText(QString("共%1个客户端").arg(ui->listWidget->count()));
}

void FrmTcpServer::disconnected(const QString& ip, int port)//显示断开连接客户端
{
	this->append(2, QString("[%1:%2]%3").arg(ip).arg(port).arg("客户端下线"));
	int row = -1;
	QString str = QString("%1:%2").arg(ip).arg(port);
	for (int i = 0; i < ui->listWidget->count(); ++i)//找到对应客端端信息的位置
	{
		if (ui->listWidget->item(i)->text() == str)
		{
			row = i;
			break;
		}
	}
	delete ui->listWidget->takeItem(row);//移除
	ui->labelCount->setText(QString("共%1个客户端").arg(ui->listWidget->count()));
}

void FrmTcpServer::error(const QString& ip, int port, const QString& error)//传达error信息
{
	this->append(2, QString("[%1:%2] %3").arg(ip).arg(port).arg(error));
}

void FrmTcpServer::sendData(const QString& ip, int port, const QString& data)//显示发送的信息
{
	this->append(0, QString("[%1:%2] %3").arg(ip).arg(port).arg(data));
}

void FrmTcpServer::receiveData(const QString& ip, int port, const QString& data)//显示收到的信息
{
	this->append(1, QString("[%1:%2] %3").arg(ip).arg(port).arg(data));
}

void FrmTcpServer::on_listen_clicked()
{
	
	if (ui->pushButtonListen->text() == "监听")
	{
		isOk_ = serverSocket_->start();//开启监听
		if (isOk_)
		{
			append(0, "监听成功");
			ui->pushButtonListen->setText("关闭");
		}
		else
		{
			append(2, QString("监听失败:%1").arg(serverSocket_->errorString()));
		}
	}
	else
	{
		isOk_ = false;
		serverSocket_->stop();//关闭监听
		ui->pushButtonListen->setText("监听");
		append(1, "关闭监听");
	}
}

void FrmTcpServer::on_save_clicked()
{
	QString data = ui->textEditMain->toPlainText();
	AppData::saveData(data);
	on_clear_clicked();
}

void FrmTcpServer::on_clear_clicked()
{
	append(0, "", true);
}

void FrmTcpServer::on_send_clicked()
{
	
	QString data = ui->comboBoxData->currentText();//获取对话框信息
	if (data.length() <= 0|| !isOk_)
	{
		return;
	}
	if (ui->checkBoxSelectAll->isChecked())//勾选上了全部发送
	{
		serverSocket_->writeData(data);
	}
	else
	{
		int row = ui->listWidget->currentRow();//获取所选行
		if (row >= 0)
		{
			QString str = ui->listWidget->item(row)->text();
			QStringList list = str.split(":");
			serverSocket_->writeData(list.at(0), list.at(1).toInt(), data);
		}
	}
}

void FrmTcpServer::on_remove_clicked()
{
	if (ui->checkBoxSelectAll->isChecked())
	{
		serverSocket_->remove();
	}
	else
	{
		int row = ui->listWidget->currentRow();
		if (row >= 0)
		{
			QString str = ui->listWidget->item(row)->text();
			QStringList list = str.split(":");
			serverSocket_->remove(list.at(0), list.at(1).toInt());
		}
	}
}

void FrmTcpServer::stateChange()
{
	AppConfig::HexSendTcpServer = ui->checkBoxHexSend->isChecked();
	AppConfig::HexReceiveTcpServer = ui->checkBoxHexReceive->isChecked();
	AppConfig::AsciiTcpServer = ui->checkBoxAscii->isChecked();
	AppConfig::DebugTcpServer = ui->checkBoxAscii->isChecked();
	AppConfig::AutoSendTcpServer = ui->checkBoxAutoSend->isChecked();
	AppConfig::IntervalTcpServer = ui->comboBoxInterval->currentText().toInt();
	AppConfig::TcpListenIP = ui->comboBoxListenIP->currentText();
	AppConfig::TcpListenPort = ui->lineEditListenPort->text().trimmed().toInt();
	AppConfig::SelectAllTcpServer = ui->checkBoxSelectAll->isChecked();
	AppConfig::writeConfig();
	this->initTimer();
}

void FrmTcpServer::initForm()
{
	QFont font;
	font.setPixelSize(16);
	ui->textEditMain->setFont(font);
	ui->textEditMain->viewport()->installEventFilter(this);
	connect(serverSocket_, &TcpServer::signal_connected, this, &FrmTcpServer::connected);
	connect(serverSocket_, &TcpServer::signal_disconnected, this, &FrmTcpServer::disconnected);
	connect(serverSocket_, &TcpServer::signal_error, this, &FrmTcpServer::error);
	connect(serverSocket_, &TcpServer::signal_sendData, this, &FrmTcpServer::sendData);
	connect(serverSocket_, &TcpServer::signal_receiveData, this, &FrmTcpServer::receiveData);

	//定时器
	connect(timer_, &QTimer::timeout, this, &FrmTcpServer::on_send_clicked);
	//填充数据到下拉框
	ui->comboBoxInterval->addItems(AppData::Intervals);
	ui->comboBoxData->addItems(AppData::Datas);
	AppData::loadIP(ui->comboBoxListenIP);
}

void FrmTcpServer::initConfig()
{
	ui->checkBoxHexSend->setChecked(AppConfig::HexSendTcpServer);
	ui->checkBoxHexReceive->setChecked(AppConfig::HexReceiveTcpServer);
	ui->checkBoxAscii->setChecked(AppConfig::AsciiTcpServer);
	ui->checkBoxDebug->setChecked(AppConfig::DebugTcpServer);
	ui->checkBoxAutoSend->setChecked(AppConfig::AutoSendTcpServer);
	ui->comboBoxInterval->setCurrentIndex(ui->comboBoxInterval->findText(QString::number(AppConfig::IntervalTcpServer)));
	ui->comboBoxListenIP->setCurrentIndex(ui->comboBoxListenIP->findText(AppConfig::TcpListenIP));
	ui->lineEditListenPort->setText(QString::number(AppConfig::TcpListenPort));
	ui->checkBoxSelectAll->setChecked(AppConfig::SelectAllTcpServer);
	this->initTimer();
}

void FrmTcpServer::initTimer()//改变定时器状态
{
	if (timer_->interval() != AppConfig::IntervalTcpServer)
	{
		timer_->setInterval(AppConfig::IntervalTcpServer);
	}
	if (AppConfig::AutoSendTcpServer)
	{
		if (timer_->isActive())
		{
			timer_->start();
		}
	}
	else
	{
		if (timer_->isActive())
		{
			timer_->stop();
		}
	}
}

void FrmTcpServer::append(int type, const QString& data, bool clear)
{
	static int currentCount = 0;
	static int maxCount = 100;
	if (clear)
	{
		ui->textEditMain->clear();
		currentCount = 0;
		return;
	}
	if (currentCount >= maxCount)
	{
		ui->textEditMain->clear();
		currentCount = 0;
	}
	if (ui->checkBoxShow->isChecked())
	{
		return;
	}
	//过滤回车换行符
	QString strData = data;
	strData = strData.replace("\r", "");
	strData = strData.replace("\n", "");
	//不同类型对应不同信息
	QMap<int, QString> msgType = {
		{0,"发送"},
		{1,"接收"},
		{2,"错误"}
	};
	//不同信息对应不同颜色
	QMap<QString, QColor>colorType = {
		{"发送",QColor("#22A3A9")},
		{"接收",QColor("#753775")},
		{"错误",QColor("#D64D54")}
	};
	
	strData = QString("时间[%1] %2:%3").arg(TIMEMS).arg(msgType[type]).arg(strData);
	ui->textEditMain->setTextColor(colorType[msgType[type]]);
	ui->textEditMain->append(strData);
	++currentCount;
	
}


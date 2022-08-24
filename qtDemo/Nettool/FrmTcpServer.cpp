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

void FrmTcpServer::connected(const QString& ip, int port)//��ʾ���ӵ���Ϣ
{
	this->append(0, QString("[%1:%2] %3").arg(ip).arg(port).arg("�ͻ�������"));
	QString str = QString("%1:%2").arg(ip).arg(port);
	ui->listWidget->addItem(str);
	ui->labelCount->setText(QString("��%1���ͻ���").arg(ui->listWidget->count()));
}

void FrmTcpServer::disconnected(const QString& ip, int port)//��ʾ�Ͽ����ӿͻ���
{
	this->append(2, QString("[%1:%2]%3").arg(ip).arg(port).arg("�ͻ�������"));
	int row = -1;
	QString str = QString("%1:%2").arg(ip).arg(port);
	for (int i = 0; i < ui->listWidget->count(); ++i)//�ҵ���Ӧ�Ͷ˶���Ϣ��λ��
	{
		if (ui->listWidget->item(i)->text() == str)
		{
			row = i;
			break;
		}
	}
	delete ui->listWidget->takeItem(row);//�Ƴ�
	ui->labelCount->setText(QString("��%1���ͻ���").arg(ui->listWidget->count()));
}

void FrmTcpServer::error(const QString& ip, int port, const QString& error)//����error��Ϣ
{
	this->append(2, QString("[%1:%2] %3").arg(ip).arg(port).arg(error));
}

void FrmTcpServer::sendData(const QString& ip, int port, const QString& data)//��ʾ���͵���Ϣ
{
	this->append(0, QString("[%1:%2] %3").arg(ip).arg(port).arg(data));
}

void FrmTcpServer::receiveData(const QString& ip, int port, const QString& data)//��ʾ�յ�����Ϣ
{
	this->append(1, QString("[%1:%2] %3").arg(ip).arg(port).arg(data));
}

void FrmTcpServer::on_listen_clicked()
{
	
	if (ui->pushButtonListen->text() == "����")
	{
		isOk_ = serverSocket_->start();//��������
		if (isOk_)
		{
			append(0, "�����ɹ�");
			ui->pushButtonListen->setText("�ر�");
		}
		else
		{
			append(2, QString("����ʧ��:%1").arg(serverSocket_->errorString()));
		}
	}
	else
	{
		isOk_ = false;
		serverSocket_->stop();//�رռ���
		ui->pushButtonListen->setText("����");
		append(1, "�رռ���");
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
	
	QString data = ui->comboBoxData->currentText();//��ȡ�Ի�����Ϣ
	if (data.length() <= 0|| !isOk_)
	{
		return;
	}
	if (ui->checkBoxSelectAll->isChecked())//��ѡ����ȫ������
	{
		serverSocket_->writeData(data);
	}
	else
	{
		int row = ui->listWidget->currentRow();//��ȡ��ѡ��
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

	//��ʱ��
	connect(timer_, &QTimer::timeout, this, &FrmTcpServer::on_send_clicked);
	//������ݵ�������
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

void FrmTcpServer::initTimer()//�ı䶨ʱ��״̬
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
	//���˻س����з�
	QString strData = data;
	strData = strData.replace("\r", "");
	strData = strData.replace("\n", "");
	//��ͬ���Ͷ�Ӧ��ͬ��Ϣ
	QMap<int, QString> msgType = {
		{0,"����"},
		{1,"����"},
		{2,"����"}
	};
	//��ͬ��Ϣ��Ӧ��ͬ��ɫ
	QMap<QString, QColor>colorType = {
		{"����",QColor("#22A3A9")},
		{"����",QColor("#753775")},
		{"����",QColor("#D64D54")}
	};
	
	strData = QString("ʱ��[%1] %2:%3").arg(TIMEMS).arg(msgType[type]).arg(strData);
	ui->textEditMain->setTextColor(colorType[msgType[type]]);
	ui->textEditMain->append(strData);
	++currentCount;
	
}


#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
#include<QString>
#include<QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),set("config.ini",QSettings::IniFormat)
{
    ui->setupUi(this);
    //获取本机的ip地址
    //hostname 计算机名称
    qDebug()<<"hostname"<< QHostInfo::localHostName(); //获取计算机名称
    //获取主机名的目的是为了获取主机的ip地址，可以使用方法 fromName获取ip
    //fromName函数实现了：根据主机名称获取主机的ip地址
    //fromName的返回值是 QHostInfo, 一个主机可以有很多个ip地址
    //在使用address方法，可以获取主机名的所有ip地址
    QHostInfo info = QHostInfo::fromName(QHostInfo::localHostName());
    foreach (QHostAddress addr, info.addresses()){
        qDebug()<<"addr.protocol() = " <<addr.protocol();
        if(addr.protocol() == QAbstractSocket::IPv4Protocol){
            qDebug()<< "addr:" << addr;
            ui->comboBox_ip->addItem(addr.toString());
        }
    }
    ui->comboBox_port->setCurrentText("8000");
    //隐藏远程主机窗口
    ui->groupBox_remote->hide();
    //发送,接收数据默认格式为ASCII
    ui->radioButton_send_ascii->setChecked(true);
    ui->radioButton_recv_ascii->setChecked(true);
    ui->textEdit_send->setText("Hello world!");
    set.beginGroup("Config");
    if(set.contains("type")) // 可以在config.ini进行搜索，找到和没找到两种
    {
        QString type =set.value("x1").toString();
        QString ip =set.value("ip").toString();
        QString port =set.value("port").toString();
        if(type == "UDP")
        {
            ui->comboBox_type->setCurrentIndex(0); //UDP
        }
        else if(type == "TCP Client")
        {
            ui->comboBox_type->setCurrentIndex(1); //TCP Client
        }
        else if(type == "TCP Server")
        {
            ui->comboBox_type->setCurrentIndex(2); //TCP Server
        }
        ui->comboBox_ip->setCurrentText(ip);
        ui->comboBox_port->setCurrentText(port);
    }
    else //如果没有就创建这些值
    {
        set.setValue("type",ui->comboBox_type->currentText());
        set.setValue("ip",ui->comboBox_ip->currentText());
        set.setValue("port",ui->comboBox_port->currentText());
    }
    set.endGroup();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::udp_readyRead_slot()
{
    qDebug()<<"udp_readyRead_slot";
    if(udpSocket != nullptr){
        quint32 nbytes = udpSocket->pendingDatagramSize();//读多少字节
        udpSocket->readDatagram(recvBuf,nbytes); //有多少读多少
        if(ui->radioButton_recv_ascii->isChecked())//ascii显示
        {
            ui->textEdit_recv->insertPlainText(QString(recvBuf));
            ui->textEdit_recv->insertPlainText(QString("\n"));
        }
        else if(ui->radioButton_recv_hex->isChecked())//hex显示
        {
            QString str2;
            AsciiToHex(QString(recvBuf),str2);
            ui->textEdit_recv->insertPlainText(str2);
            ui->textEdit_recv->insertPlainText(QString("\n"));
        }
    }

}

void MainWindow::tcp_readyRead_slot()
{
    if(tcpSocket != nullptr){
        QByteArray data = tcpSocket->readAll();//读多少字节
        if(ui->radioButton_recv_ascii->isChecked())//ascii显示
        {
            ui->textEdit_recv->insertPlainText(QString(data));
            ui->textEdit_recv->insertPlainText(QString("\n"));
        }
        else if(ui->radioButton_recv_hex->isChecked())//hex显示
        {
            QString str2;
            AsciiToHex(QString(data),str2);
            ui->textEdit_recv->insertPlainText(str2);
            ui->textEdit_recv->insertPlainText(QString("\n"));
        }
    }
}
// 客户端连接服务器后
void MainWindow::tcp_connected_slot()
{
    qDebug()<<"客户端已连接服务器";
    ui->pushButton_open->setIcon(QIcon(QString::fromUtf8(":/images/ledon.png")));
    ui->pushButton_open->setEnabled(true);
}
// 客户端连接服务器失败
void MainWindow::tcp_errorOccurred_slot(QAbstractSocket::SocketError socketError)
{
    qDebug()<<socketError;
    if(socketError == QAbstractSocket::ConnectionRefusedError){
        ui->pushButton_open->setEnabled(true);//可操作
        ui->comboBox_ip->setEnabled(true); //可操作
        ui->comboBox_type->setEnabled(true); //可操作
        ui->comboBox_port->setEnabled(true); //可操作
        ui->pushButton_open->setCheckable(false);//让按钮弹起来
        ui->pushButton_open->setText(tr("连接"));
        if(tcpSocket != nullptr){
            tcpSocket->close();
            tcpSocket->deleteLater();
            tcpSocket = nullptr;
        }
    }
}

void MainWindow::tcpserver_readyRead_slot()
{
    for(int i = 0;i < tcpClients.count(); i++){
        if(tcpClients.at(i)->bytesAvailable() > 0) //客户端有数据到达
        {
            QByteArray data = tcpClients.at(i)->readAll(); //读取所有的数据
            if(ui->radioButton_recv_ascii->isChecked())//ascii显示
            {
                ui->textEdit_recv->insertPlainText(QString(data));
                ui->textEdit_recv->insertPlainText(QString("\n"));
            }
            else if(ui->radioButton_recv_hex->isChecked())//hex显示
            {
                QString str2;
                AsciiToHex(QString(data),str2);
                ui->textEdit_recv->insertPlainText(str2);
                ui->textEdit_recv->insertPlainText(QString("\n"));
            }
        }
    }
}

void MainWindow::tcpserver_newConnection_slot()
{
    qDebug()<<"服务器连接成功";
    if(tcpServer != nullptr){
        QTcpSocket *client = tcpServer->nextPendingConnection();
        //设置这个client信号处理函数
        connect(client,&QTcpSocket::readyRead,this,&MainWindow::tcpserver_readyRead_slot);
        //客户端断开连接会发送disconnect信号
        connect(client,&QTcpSocket::disconnected,this,&MainWindow::tcpserver_disconnected_slot);
        //把客户端添加到vector内
        tcpClients.append(client);
        //获取客户端的ip和端口的信息
        QHostAddress addr = client->peerAddress(); //tcp连接的对方地址，就是客户端的地址
        quint16 port = client->peerPort(); //获取客户端的端口信息
        ui->comboBox_remote->addItem(tr("%0:%1").arg(addr.toString()).arg(port));
    }
}

void MainWindow::tcpserver_disconnected_slot()
{
    qDebug()<<"服务器断开连接";
    for(int i = 0;i < tcpClients.count(); i++){
        if(tcpClients.at(i)->state() == QAbstractSocket::UnconnectedState){
            tcpClients.at(i)->close();
            tcpClients.remove(i); //删除成员
            ui->comboBox_remote->removeItem(i);
        }
    }
}


//---------------------------------------------转换函数--------------------------------------------------------begin
// 把字符串转成16进制字符串
// str1 是ascii的字符串
// str2 是hex 的字符串
void MainWindow::AsciiToHex(const QString &str1, QString &str2){
    str2 = "";
    for(int i=0;i<str1.size();i++)
    {
        str2 += QString::asprintf("%02X",str1.at(i).toLatin1());
        if(i < (str1.size()-1) ) // 最后一个字符不加空格
        {
            str2 += " ";
            }
        }
}

// 把16进制的字符串 转成 ascii的字符串
// str1 是hex 的字符串
// str2 是ascii 的字符串
void MainWindow::HexToAscii(const QString &str1, QString &str2){
    str2 = "" ;
    QStringList list =  str1.split(" ") ; // 使用空格进行拆分
    qDebug()<<"list="<<list ;
    for(int i=0;i<list.size();i++)
     {
      qDebug()<<"char="<< QString::asprintf("%c",list.at(i).toInt() ) ;
      qDebug()<<"list.at(i)="<<list.at(i) ;
      bool ok ;
      qDebug()<<"list.at(i).toint="<<list.at(i).toInt(&ok,16) ;
      str2 += QString::asprintf("%c",list.at(i).toInt(&ok,16) ) ;
}
qDebug()<<"str2="<<str2 ;
}

char convertCharToHex(char ch)
{
    if((ch >= '0') && (ch <= '9'))
        return ch-0x30;
    else if((ch >= 'A') && (ch <= 'F'))
        return ch-'A'+10;
    else if((ch >= 'a') && (ch <= 'f'))
        return ch-'a'+10;
    else return (-1);
}
// 把16进制的字符串转成16进制的QByteArray  字符串类型转编码类型
void MainWindow::StringToHex(const QString &str, QByteArray &byteData)
{
    int hexdata,lowhexdata;
    int hexdatalen = 0;
    int len = str.length();
    byteData.resize(len/2);
    char lstr,hstr;
    for(int i=0; i<len; )
    {
        //char lstr,
        hstr=str[i].toLatin1();
        if(hstr == ' ')
        {
            i++;
            continue;
        }
        i++;
        if(i >= len)
            break;
        lstr = str[i].toLatin1();
        hexdata = convertCharToHex(hstr);
        lowhexdata = convertCharToHex(lstr);
        if((hexdata == 16) || (lowhexdata == 16))
            break;
        else
            hexdata = hexdata*16+lowhexdata;
        i++;
        byteData[hexdatalen] = (char)hexdata;
        hexdatalen++;
    }
    byteData.resize(hexdatalen);
}
//---------------------------------------------转换函数--------------------------------------------------------end
void MainWindow::on_radioButton_send_ascii_clicked()
{
    //设置一个标志位，表示发送字符串是什么格式的
    //false: ascii    true: hex
    if(sendHexAsciiFlag) //如果为真，则字符串是以hex形式发出
    {
        QString str2;
        HexToAscii(ui->textEdit_send->toPlainText(),str2);
        ui->textEdit_send->setText(str2);
        sendHexAsciiFlag = false; //转换后，设置标志位，表示已经转成ascii字符串类型
    }
}


void MainWindow::on_radioButton_send_hex_clicked()
{
    //设置一个标志位，表示发送字符串是什么格式的
    //false: ascii    true: hex
    if(!sendHexAsciiFlag) //如果为假，则字符串是以ascii形式发出
    {
        QString str2;
        AsciiToHex(ui->textEdit_send->toPlainText(),str2);
        ui->textEdit_send->setText(str2);
        sendHexAsciiFlag = true; //转换后，设置标志位，表示已经转成hex字符串类型
    }
}

void MainWindow::on_pushButton_open_clicked(bool checked)
{   //CurrentIndex() == 0 : udp
    //CurrentIndex() == 1 : tcp client
    //CurrentIndex() == 2 : tcp server
    qDebug()<<"comboBox_type->currentIndex()"<<ui->comboBox_type->currentIndex();
    qDebug()<<"checked="<< checked;
    if(ui->comboBox_type->currentText() =="UDP"){
        if(checked)//为真时
        {
            ui->pushButton_open->setText(tr("关闭"));
            ui->comboBox_ip->setEnabled(false); //不可操作
            ui->comboBox_type->setEnabled(false); //不可操作
            ui->comboBox_port->setEnabled(false); //不可操作
            udpSocket = new QUdpSocket(this); //创建udpSocket
            //设置信号处理函数
            connect(udpSocket,&QUdpSocket::readyRead,this,&MainWindow::udp_readyRead_slot);
            //绑定本地ip地址和端口号
            quint16 port = ui->comboBox_port->currentText().toUShort();
            QHostAddress addr(ui->comboBox_ip->currentText());
            udpSocket->bind(addr,port);
            //设置远程主机的信息 arg 是用于格式化字符串
            ui->comboBox_remote->setCurrentText(tr("%0:%1").arg(ui->comboBox_ip->currentText()) .arg(ui->comboBox_port->currentText()));
            //显示远程主机窗口
            ui->groupBox_remote->show();
            //保存操作步骤
            set.beginGroup("Config");
            set.setValue("type",ui->comboBox_type->currentText());
            set.setValue("ip",ui->comboBox_ip->currentText());
            set.setValue("port",ui->comboBox_port->currentText());
            set.endGroup();
        }else{
            ui->pushButton_open->setText(tr("打开"));
            ui->comboBox_ip->setEnabled(true); //可操作
            ui->comboBox_type->setEnabled(true); //可操作
            ui->comboBox_port->setEnabled(true); //可操作
            //隐藏远程窗口
            ui->comboBox_remote->hide();
            //释放udp socket
            if(udpSocket != nullptr){
                udpSocket->close();
                udpSocket->deleteLater();//释放内存
                udpSocket = nullptr;
            }
        }
    }
    else if(ui->comboBox_type->currentText() =="TCP Client"){ //TCP Client
        if(checked)//为真时
        {
            ui->pushButton_open->setText(tr("关闭"));
            ui->comboBox_ip->setEnabled(false); //不可操作
            ui->comboBox_type->setEnabled(false); //不可操作
            ui->comboBox_port->setEnabled(false); //不可操作
            ui->pushButton_open->setEnabled(false);//不可操作

            tcpSocket = new QTcpSocket(this); //创建tcp Socket
            //设置信号处理函数
            connect(tcpSocket,&QTcpSocket::readyRead,this,&MainWindow::tcp_readyRead_slot);
            //连接到服务器后会发送一个信号，connected()
            connect(tcpSocket,&QTcpSocket::connected,this,&MainWindow::tcp_connected_slot);
            //连接到服务器失败后发送一个信号，errorOccurred(),版本问题暂时注释
            // connect(tcpSocket,&QTcpSocket::errorOccurred,this,&MainWindow::tcp_errorOccurred_slot);
            //绑定本地ip地址和端口号
            quint16 port = ui->comboBox_port->currentText().toUShort();
            QHostAddress addr(ui->comboBox_ip->currentText());
            tcpSocket->connectToHost(addr,port); //启动tcp的连接
            //保存操作步骤
            set.beginGroup("Config");
            set.setValue("type",ui->comboBox_type->currentText());
            set.setValue("ip",ui->comboBox_ip->currentText());
            set.setValue("port",ui->comboBox_port->currentText());
            set.endGroup();
        }else{
            ui->pushButton_open->setText(tr("连接"));
            ui->comboBox_ip->setEnabled(true); //可操作
            ui->comboBox_type->setEnabled(true); //可操作
            ui->comboBox_port->setEnabled(true); //可操作
            //释放tcp socket
            if(tcpSocket != nullptr){
                tcpSocket->close();
                tcpSocket->deleteLater();//释放内存
                tcpSocket = nullptr;
            }
        }
    }
    else if(ui->comboBox_type->currentText() =="TCP Server"){ //TCP Server
        if(checked)//为真时
        {
            tcpServer = new QTcpServer(this); //创建tcp Server
            //设置信号处理函数
            connect(tcpServer,&QTcpServer::newConnection,this,&MainWindow::tcpserver_newConnection_slot);
            //绑定本地ip地址和端口号
            quint16 port = ui->comboBox_port->currentText().toUShort();
            QHostAddress addr(ui->comboBox_ip->currentText());
            if(tcpServer->listen(addr,port)) //监听连接，如果为真，服务器启动成功
            {
                //服务器启动成功
                ui->label_remote->setText(tr("客户端"));
                ui->comboBox_remote->clear();
                ui->groupBox_remote-> show();
                //设置led图片
                ui->pushButton_open->setIcon(QIcon(QString::fromUtf8(":/images/ledon.png")));
                ui->pushButton_open->setText(tr("关闭"));
                ui->comboBox_ip->setEnabled(false); //不可操作
                ui->comboBox_type->setEnabled(false); //不可操作
                ui->comboBox_port->setEnabled(false); //不可操作
            }
            else{
                if(tcpServer == nullptr){
                    tcpServer->close();
                    tcpServer->deleteLater();
                    tcpServer = nullptr;
                }
                ui->pushButton_open->setChecked(false); //按钮弹起来
            }
            //保存操作步骤
            set.beginGroup("Config");
            set.setValue("type",ui->comboBox_type->currentText());
            set.setValue("ip",ui->comboBox_ip->currentText());
            set.setValue("port",ui->comboBox_port->currentText());
            set.endGroup();
        }else{
            ui->pushButton_open->setIcon(QIcon(QString::fromUtf8(":/images/ledoff.png")));
            ui->pushButton_open->setText(tr("打开"));
            ui->comboBox_ip->setEnabled(true); //可操作
            ui->comboBox_type->setEnabled(true); //可操作
            ui->comboBox_port->setEnabled(true); //可操作
            //释放tcp socket
            if(tcpServer == nullptr){
                tcpServer->close();
                tcpServer->deleteLater();
                tcpServer = nullptr;
            }
        }
    }
}

void MainWindow::on_pushButton_send_clicked()
{
    if(ui->textEdit_send->toPlainText().isEmpty()) QMessageBox::critical(this,"错误消息对话框","请输入发送内容！");
    if(ui->comboBox_type->currentText() == "UDP"){
        if(! ui->pushButton_open->isChecked()){
            return ;
        } //没有被按下,返回空,不发送
        //提取远程主机信息,用split和链表遍历分别提取出ip地址和端口号
        QString ip_port = ui->comboBox_remote->currentText(); //得到ip和端口的字符串
        QStringList list = ip_port.split(":");
        foreach(QString l, list){
            qDebug()<<"l:"<<l;
        }
        QHostAddress addr(list[0]);
        quint16 port = list[1].toUShort();
        if(ui->radioButton_send_ascii->isChecked()) //是否发送ascii
        {
            if(udpSocket != nullptr){
                udpSocket->writeDatagram(ui->textEdit_send->toPlainText().toUtf8(),addr,port);
            }
        }
        else if(ui->radioButton_send_hex->isChecked()) //是否发送hex
        {
            QByteArray data;
            StringToHex(ui->textEdit_send->toPlainText(),data);
            if(udpSocket != nullptr){
                udpSocket->writeDatagram(data,addr,port);
            }
        }
    }
    else if(ui->comboBox_type->currentText() == "TCP Client"){
        if(! ui->pushButton_open->isChecked()){
            return ;
        } //没有被按下,返回空,不发送
        if(ui->radioButton_send_ascii->isChecked()) //是否发送ascii
        {
            if(tcpSocket != nullptr){
                tcpSocket->write(ui->textEdit_send->toPlainText().toUtf8());
            }
        }
        else if(ui->radioButton_send_hex->isChecked()) //是否发送hex
        {
            QByteArray data;
            StringToHex(ui->textEdit_send->toPlainText(),data);
            if(tcpSocket != nullptr){
                tcpSocket->write(data);
            }
        }
    }
    else if(ui->comboBox_type->currentText() == "TCP Server"){
        if(! ui->pushButton_open->isChecked()){
            return ;
        } //没有被按下,返回空,不发送
        for(int i = 0;i < tcpClients.count(); i++){
            //获取客户端的信息
            QString info = tr("%0:%1").arg(tcpClients.at(i)->peerAddress().toString()) .arg(tcpClients.at(i)->peerPort());
            qDebug()<<"info"<<info;
            if(info == ui->comboBox_remote->currentText()) //发送给当前的客户端
            {
                if(ui->radioButton_send_ascii->isChecked()) //是否发送ascii
                {
                    if(tcpClients.at(i) != nullptr){
                        tcpClients.at(i)->write(ui->textEdit_send->toPlainText().toUtf8());
                    }
                }
                else if(ui->radioButton_send_hex->isChecked()) //是否发送hex
                {
                    QByteArray data;
                    StringToHex(ui->textEdit_send->toPlainText(),data);
                    if(tcpClients.at(i) != nullptr){
                        tcpClients.at(i)->write(data);
                    }
                }
            }

        }
        if(ui->radioButton_send_ascii->isChecked()) //是否发送ascii
        {
            if(tcpSocket != nullptr){
                tcpSocket->write(ui->textEdit_send->toPlainText().toUtf8());
            }
        }
        else if(ui->radioButton_send_hex->isChecked()) //是否发送hex
        {
            QByteArray data;
            StringToHex(ui->textEdit_send->toPlainText(),data);
            if(tcpSocket != nullptr){
                tcpSocket->write(data);
            }
        }
    }
}


void MainWindow::on_pushButton_send_clear_clicked()
{
    ui->textEdit_send->clear();
}
void MainWindow::on_pushButton_recv_clear_clicked()
{
    ui->textEdit_recv->clear();
}
//切换udp，tcp时，更换标签
void MainWindow::on_comboBox_type_activated(int index)
{
    if(index == 0)// UDP
    {
        ui->label_ip->setText(tr("2.本地主机地址"));
        ui->label_port->setText(tr("3.本地主机端口"));
    }
    if(index == 1)//TCP Client
    {
        ui->label_ip->setText(tr("2.远程主机地址"));
        ui->label_port->setText(tr("3.远程主机端口"));
        ui->pushButton_open->setText(tr("连接"));
    }
    if(index == 2)//TCP Server
    {
        ui->label_ip->setText(tr("2.本地主机地址"));
        ui->label_port->setText(tr("3.本地主机端口"));
    }
}





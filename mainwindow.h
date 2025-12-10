#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QHostInfo>
#include <QMainWindow>
#include<QUdpSocket>
#include<QTcpSocket>
#include<QTcpServer>
#include<QSettings>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void udp_readyRead_slot();
    void tcp_readyRead_slot();
    void tcp_connected_slot();
    void tcp_errorOccurred_slot(QAbstractSocket::SocketError socketError);
    void tcpserver_newConnection_slot();
    void tcpserver_readyRead_slot();
    void tcpserver_disconnected_slot();
    void on_pushButton_open_clicked(bool checked);
    void on_radioButton_send_ascii_clicked();
    void AsciiToHex(const QString &str1,QString &str2);
    void HexToAscii(const QString &str1, QString &str2);
    void StringToHex(const QString &str, QByteArray &byteData);
    void on_radioButton_send_hex_clicked();
    void on_pushButton_send_clicked();
    void on_pushButton_send_clear_clicked();
    void on_comboBox_type_activated(int index);
    void on_pushButton_recv_clear_clicked();
private:
    Ui::MainWindow *ui;
    QSettings set; //定义一个对象
    QUdpSocket *udpSocket = nullptr;
    QTcpSocket *tcpSocket = nullptr;
    QTcpServer *tcpServer = nullptr;
    QVector<QTcpSocket *> tcpClients;
    bool sendHexAsciiFlag = false; //设置一个标志位，表示发送字符串是什么格式的
    char recvBuf[1024] = {0}; //接收数据缓存区
};
#endif // MAINWINDOW_H

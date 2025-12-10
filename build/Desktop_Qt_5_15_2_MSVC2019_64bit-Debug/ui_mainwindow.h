/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QComboBox *comboBox_type;
    QLabel *label_type;
    QLabel *label_ip;
    QComboBox *comboBox_ip;
    QComboBox *comboBox_port;
    QLabel *label_port;
    QPushButton *pushButton_open;
    QGroupBox *groupBox_2;
    QRadioButton *radioButton_recv_ascii;
    QRadioButton *radioButton_recv_hex;
    QGroupBox *groupBox_3;
    QRadioButton *radioButton_send_ascii;
    QRadioButton *radioButton_send_hex;
    QPushButton *pushButton_send_clear;
    QTabWidget *tabWidget;
    QWidget *tab;
    QTextEdit *textEdit_recv;
    QTabWidget *tabWidget_2;
    QWidget *tab_2;
    QTextEdit *textEdit_send;
    QPushButton *pushButton_send;
    QGroupBox *groupBox_remote;
    QComboBox *comboBox_remote;
    QLabel *label_remote;
    QPushButton *pushButton_recv_clear;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/network.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 20, 221, 271));
        comboBox_type = new QComboBox(groupBox);
        comboBox_type->addItem(QString());
        comboBox_type->addItem(QString());
        comboBox_type->addItem(QString());
        comboBox_type->setObjectName(QString::fromUtf8("comboBox_type"));
        comboBox_type->setGeometry(QRect(20, 60, 180, 30));
        label_type = new QLabel(groupBox);
        label_type->setObjectName(QString::fromUtf8("label_type"));
        label_type->setGeometry(QRect(20, 30, 120, 30));
        label_ip = new QLabel(groupBox);
        label_ip->setObjectName(QString::fromUtf8("label_ip"));
        label_ip->setGeometry(QRect(20, 90, 120, 30));
        comboBox_ip = new QComboBox(groupBox);
        comboBox_ip->setObjectName(QString::fromUtf8("comboBox_ip"));
        comboBox_ip->setGeometry(QRect(20, 120, 180, 30));
        comboBox_port = new QComboBox(groupBox);
        comboBox_port->setObjectName(QString::fromUtf8("comboBox_port"));
        comboBox_port->setGeometry(QRect(20, 180, 180, 30));
        comboBox_port->setEditable(true);
        label_port = new QLabel(groupBox);
        label_port->setObjectName(QString::fromUtf8("label_port"));
        label_port->setGeometry(QRect(20, 150, 120, 30));
        pushButton_open = new QPushButton(groupBox);
        pushButton_open->setObjectName(QString::fromUtf8("pushButton_open"));
        pushButton_open->setGeometry(QRect(20, 230, 180, 30));
        QFont font;
        font.setPointSize(11);
        pushButton_open->setFont(font);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/ledoff.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon1.addFile(QString::fromUtf8(":/images/ledon.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_open->setIcon(icon1);
        pushButton_open->setCheckable(true);
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 310, 221, 121));
        radioButton_recv_ascii = new QRadioButton(groupBox_2);
        radioButton_recv_ascii->setObjectName(QString::fromUtf8("radioButton_recv_ascii"));
        radioButton_recv_ascii->setGeometry(QRect(10, 30, 119, 24));
        radioButton_recv_hex = new QRadioButton(groupBox_2);
        radioButton_recv_hex->setObjectName(QString::fromUtf8("radioButton_recv_hex"));
        radioButton_recv_hex->setGeometry(QRect(120, 30, 119, 24));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 440, 221, 121));
        radioButton_send_ascii = new QRadioButton(groupBox_3);
        radioButton_send_ascii->setObjectName(QString::fromUtf8("radioButton_send_ascii"));
        radioButton_send_ascii->setGeometry(QRect(10, 30, 119, 24));
        radioButton_send_hex = new QRadioButton(groupBox_3);
        radioButton_send_hex->setObjectName(QString::fromUtf8("radioButton_send_hex"));
        radioButton_send_hex->setGeometry(QRect(120, 30, 119, 24));
        pushButton_send_clear = new QPushButton(groupBox_3);
        pushButton_send_clear->setObjectName(QString::fromUtf8("pushButton_send_clear"));
        pushButton_send_clear->setGeometry(QRect(20, 60, 161, 41));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(230, 10, 571, 451));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        textEdit_recv = new QTextEdit(tab);
        textEdit_recv->setObjectName(QString::fromUtf8("textEdit_recv"));
        textEdit_recv->setGeometry(QRect(0, 0, 581, 425));
        tabWidget->addTab(tab, QString());
        tabWidget_2 = new QTabWidget(centralwidget);
        tabWidget_2->setObjectName(QString::fromUtf8("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(230, 460, 455, 141));
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        textEdit_send = new QTextEdit(tab_2);
        textEdit_send->setObjectName(QString::fromUtf8("textEdit_send"));
        textEdit_send->setGeometry(QRect(0, 0, 455, 120));
        tabWidget_2->addTab(tab_2, QString());
        pushButton_send = new QPushButton(centralwidget);
        pushButton_send->setObjectName(QString::fromUtf8("pushButton_send"));
        pushButton_send->setGeometry(QRect(680, 480, 121, 121));
        groupBox_remote = new QGroupBox(centralwidget);
        groupBox_remote->setObjectName(QString::fromUtf8("groupBox_remote"));
        groupBox_remote->setGeometry(QRect(350, 460, 311, 25));
        comboBox_remote = new QComboBox(groupBox_remote);
        comboBox_remote->setObjectName(QString::fromUtf8("comboBox_remote"));
        comboBox_remote->setGeometry(QRect(80, 0, 231, 25));
        comboBox_remote->setEditable(true);
        label_remote = new QLabel(groupBox_remote);
        label_remote->setObjectName(QString::fromUtf8("label_remote"));
        label_remote->setGeometry(QRect(10, 3, 69, 19));
        pushButton_recv_clear = new QPushButton(centralwidget);
        pushButton_recv_clear->setObjectName(QString::fromUtf8("pushButton_recv_clear"));
        pushButton_recv_clear->setGeometry(QRect(30, 370, 161, 41));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\347\275\221\347\273\234\350\260\203\350\257\225\345\212\251\346\211\213 1.5", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\347\275\221\347\273\234\350\256\276\347\275\256", nullptr));
        comboBox_type->setItemText(0, QCoreApplication::translate("MainWindow", "UDP", nullptr));
        comboBox_type->setItemText(1, QCoreApplication::translate("MainWindow", "TCP Client", nullptr));
        comboBox_type->setItemText(2, QCoreApplication::translate("MainWindow", "TCP Server", nullptr));

        label_type->setText(QCoreApplication::translate("MainWindow", "1.\345\215\217\350\256\256\347\261\273\345\236\213", nullptr));
        label_ip->setText(QCoreApplication::translate("MainWindow", "2.\346\234\254\345\234\260\344\270\273\346\234\272\345\234\260\345\235\200", nullptr));
        label_port->setText(QCoreApplication::translate("MainWindow", "3.\346\234\254\345\234\260\344\270\273\346\234\272\347\253\257\345\217\243", nullptr));
        pushButton_open->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\346\216\245\346\224\266\350\256\276\347\275\256", nullptr));
        radioButton_recv_ascii->setText(QCoreApplication::translate("MainWindow", "ASCII", nullptr));
        radioButton_recv_hex->setText(QCoreApplication::translate("MainWindow", "HEX", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201\350\256\276\347\275\256", nullptr));
        radioButton_send_ascii->setText(QCoreApplication::translate("MainWindow", "ASCII", nullptr));
        radioButton_send_hex->setText(QCoreApplication::translate("MainWindow", "HEX", nullptr));
        pushButton_send_clear->setText(QCoreApplication::translate("MainWindow", "\346\270\205\351\231\244\345\217\221\351\200\201", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "\346\216\245\346\224\266\346\225\260\346\215\256", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_2), QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201\346\225\260\346\215\256", nullptr));
        pushButton_send->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201", nullptr));
        groupBox_remote->setTitle(QString());
        label_remote->setText(QCoreApplication::translate("MainWindow", "\350\277\234\347\250\213\344\270\273\346\234\272", nullptr));
        pushButton_recv_clear->setText(QCoreApplication::translate("MainWindow", "\346\270\205\351\231\244\346\216\245\346\224\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

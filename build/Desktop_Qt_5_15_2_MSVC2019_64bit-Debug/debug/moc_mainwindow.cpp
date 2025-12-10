/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[29];
    char stringdata0[520];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 18), // "udp_readyRead_slot"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 18), // "tcp_readyRead_slot"
QT_MOC_LITERAL(4, 50, 18), // "tcp_connected_slot"
QT_MOC_LITERAL(5, 69, 22), // "tcp_errorOccurred_slot"
QT_MOC_LITERAL(6, 92, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(7, 121, 11), // "socketError"
QT_MOC_LITERAL(8, 133, 28), // "tcpserver_newConnection_slot"
QT_MOC_LITERAL(9, 162, 24), // "tcpserver_readyRead_slot"
QT_MOC_LITERAL(10, 187, 27), // "tcpserver_disconnected_slot"
QT_MOC_LITERAL(11, 215, 26), // "on_pushButton_open_clicked"
QT_MOC_LITERAL(12, 242, 7), // "checked"
QT_MOC_LITERAL(13, 250, 33), // "on_radioButton_send_ascii_cli..."
QT_MOC_LITERAL(14, 284, 10), // "AsciiToHex"
QT_MOC_LITERAL(15, 295, 4), // "str1"
QT_MOC_LITERAL(16, 300, 8), // "QString&"
QT_MOC_LITERAL(17, 309, 4), // "str2"
QT_MOC_LITERAL(18, 314, 10), // "HexToAscii"
QT_MOC_LITERAL(19, 325, 11), // "StringToHex"
QT_MOC_LITERAL(20, 337, 3), // "str"
QT_MOC_LITERAL(21, 341, 11), // "QByteArray&"
QT_MOC_LITERAL(22, 353, 8), // "byteData"
QT_MOC_LITERAL(23, 362, 31), // "on_radioButton_send_hex_clicked"
QT_MOC_LITERAL(24, 394, 26), // "on_pushButton_send_clicked"
QT_MOC_LITERAL(25, 421, 32), // "on_pushButton_send_clear_clicked"
QT_MOC_LITERAL(26, 454, 26), // "on_comboBox_type_activated"
QT_MOC_LITERAL(27, 481, 5), // "index"
QT_MOC_LITERAL(28, 487, 32) // "on_pushButton_recv_clear_clicked"

    },
    "MainWindow\0udp_readyRead_slot\0\0"
    "tcp_readyRead_slot\0tcp_connected_slot\0"
    "tcp_errorOccurred_slot\0"
    "QAbstractSocket::SocketError\0socketError\0"
    "tcpserver_newConnection_slot\0"
    "tcpserver_readyRead_slot\0"
    "tcpserver_disconnected_slot\0"
    "on_pushButton_open_clicked\0checked\0"
    "on_radioButton_send_ascii_clicked\0"
    "AsciiToHex\0str1\0QString&\0str2\0HexToAscii\0"
    "StringToHex\0str\0QByteArray&\0byteData\0"
    "on_radioButton_send_hex_clicked\0"
    "on_pushButton_send_clicked\0"
    "on_pushButton_send_clear_clicked\0"
    "on_comboBox_type_activated\0index\0"
    "on_pushButton_recv_clear_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x08 /* Private */,
       3,    0,  100,    2, 0x08 /* Private */,
       4,    0,  101,    2, 0x08 /* Private */,
       5,    1,  102,    2, 0x08 /* Private */,
       8,    0,  105,    2, 0x08 /* Private */,
       9,    0,  106,    2, 0x08 /* Private */,
      10,    0,  107,    2, 0x08 /* Private */,
      11,    1,  108,    2, 0x08 /* Private */,
      13,    0,  111,    2, 0x08 /* Private */,
      14,    2,  112,    2, 0x08 /* Private */,
      18,    2,  117,    2, 0x08 /* Private */,
      19,    2,  122,    2, 0x08 /* Private */,
      23,    0,  127,    2, 0x08 /* Private */,
      24,    0,  128,    2, 0x08 /* Private */,
      25,    0,  129,    2, 0x08 /* Private */,
      26,    1,  130,    2, 0x08 /* Private */,
      28,    0,  133,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 16,   15,   17,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 16,   15,   17,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 21,   20,   22,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   27,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->udp_readyRead_slot(); break;
        case 1: _t->tcp_readyRead_slot(); break;
        case 2: _t->tcp_connected_slot(); break;
        case 3: _t->tcp_errorOccurred_slot((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 4: _t->tcpserver_newConnection_slot(); break;
        case 5: _t->tcpserver_readyRead_slot(); break;
        case 6: _t->tcpserver_disconnected_slot(); break;
        case 7: _t->on_pushButton_open_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->on_radioButton_send_ascii_clicked(); break;
        case 9: _t->AsciiToHex((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 10: _t->HexToAscii((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 11: _t->StringToHex((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        case 12: _t->on_radioButton_send_hex_clicked(); break;
        case 13: _t->on_pushButton_send_clicked(); break;
        case 14: _t->on_pushButton_send_clear_clicked(); break;
        case 15: _t->on_comboBox_type_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->on_pushButton_recv_clear_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

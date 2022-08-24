/****************************************************************************
** Meta object code from reading C++ file 'FrmTcpServer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../FrmTcpServer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FrmTcpServer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FrmTcpServer_t {
    QByteArrayData data[16];
    char stringdata0[174];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FrmTcpServer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FrmTcpServer_t qt_meta_stringdata_FrmTcpServer = {
    {
QT_MOC_LITERAL(0, 0, 12), // "FrmTcpServer"
QT_MOC_LITERAL(1, 13, 12), // "disconnected"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 2), // "ip"
QT_MOC_LITERAL(4, 30, 4), // "port"
QT_MOC_LITERAL(5, 35, 9), // "connected"
QT_MOC_LITERAL(6, 45, 5), // "error"
QT_MOC_LITERAL(7, 51, 8), // "sendData"
QT_MOC_LITERAL(8, 60, 4), // "data"
QT_MOC_LITERAL(9, 65, 11), // "receiveData"
QT_MOC_LITERAL(10, 77, 17), // "on_listen_clicked"
QT_MOC_LITERAL(11, 95, 15), // "on_save_clicked"
QT_MOC_LITERAL(12, 111, 16), // "on_clear_clicked"
QT_MOC_LITERAL(13, 128, 15), // "on_send_clicked"
QT_MOC_LITERAL(14, 144, 17), // "on_remove_clicked"
QT_MOC_LITERAL(15, 162, 11) // "stateChange"

    },
    "FrmTcpServer\0disconnected\0\0ip\0port\0"
    "connected\0error\0sendData\0data\0receiveData\0"
    "on_listen_clicked\0on_save_clicked\0"
    "on_clear_clicked\0on_send_clicked\0"
    "on_remove_clicked\0stateChange"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FrmTcpServer[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   69,    2, 0x08 /* Private */,
       5,    2,   74,    2, 0x08 /* Private */,
       6,    3,   79,    2, 0x08 /* Private */,
       7,    3,   86,    2, 0x08 /* Private */,
       9,    3,   93,    2, 0x08 /* Private */,
      10,    0,  100,    2, 0x08 /* Private */,
      11,    0,  101,    2, 0x08 /* Private */,
      12,    0,  102,    2, 0x08 /* Private */,
      13,    0,  103,    2, 0x08 /* Private */,
      14,    0,  104,    2, 0x08 /* Private */,
      15,    0,  105,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::QString,    3,    4,    6,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::QString,    3,    4,    8,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::QString,    3,    4,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FrmTcpServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FrmTcpServer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->disconnected((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->connected((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->error((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 3: _t->sendData((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 4: _t->receiveData((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 5: _t->on_listen_clicked(); break;
        case 6: _t->on_save_clicked(); break;
        case 7: _t->on_clear_clicked(); break;
        case 8: _t->on_send_clicked(); break;
        case 9: _t->on_remove_clicked(); break;
        case 10: _t->stateChange(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FrmTcpServer::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_FrmTcpServer.data,
    qt_meta_data_FrmTcpServer,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FrmTcpServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FrmTcpServer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FrmTcpServer.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int FrmTcpServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'FrmUdpClient.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../FrmUdpClient.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FrmUdpClient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FrmUdpClient_t {
    QByteArrayData data[11];
    char stringdata0[115];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FrmUdpClient_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FrmUdpClient_t qt_meta_stringdata_FrmUdpClient = {
    {
QT_MOC_LITERAL(0, 0, 12), // "FrmUdpClient"
QT_MOC_LITERAL(1, 13, 13), // "slot_readData"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 10), // "slot_error"
QT_MOC_LITERAL(4, 39, 13), // "slot_sendData"
QT_MOC_LITERAL(5, 53, 2), // "ip"
QT_MOC_LITERAL(6, 56, 4), // "port"
QT_MOC_LITERAL(7, 61, 4), // "data"
QT_MOC_LITERAL(8, 66, 15), // "on_save_clicked"
QT_MOC_LITERAL(9, 82, 16), // "on_clear_clicked"
QT_MOC_LITERAL(10, 99, 15) // "on_send_clicked"

    },
    "FrmUdpClient\0slot_readData\0\0slot_error\0"
    "slot_sendData\0ip\0port\0data\0on_save_clicked\0"
    "on_clear_clicked\0on_send_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FrmUdpClient[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    3,   46,    2, 0x08 /* Private */,
       8,    0,   53,    2, 0x08 /* Private */,
       9,    0,   54,    2, 0x08 /* Private */,
      10,    0,   55,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::QString,    5,    6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FrmUdpClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FrmUdpClient *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slot_readData(); break;
        case 1: _t->slot_error(); break;
        case 2: _t->slot_sendData((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 3: _t->on_save_clicked(); break;
        case 4: _t->on_clear_clicked(); break;
        case 5: _t->on_send_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FrmUdpClient::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_FrmUdpClient.data,
    qt_meta_data_FrmUdpClient,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FrmUdpClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FrmUdpClient::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FrmUdpClient.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int FrmUdpClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

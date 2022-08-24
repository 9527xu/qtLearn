/****************************************************************************
** Meta object code from reading C++ file 'FrmTcpClient.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../FrmTcpClient.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FrmTcpClient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FrmTcpClient_t {
    QByteArrayData data[11];
    char stringdata0[147];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FrmTcpClient_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FrmTcpClient_t qt_meta_stringdata_FrmTcpClient = {
    {
QT_MOC_LITERAL(0, 0, 12), // "FrmTcpClient"
QT_MOC_LITERAL(1, 13, 12), // "disconnected"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 9), // "connected"
QT_MOC_LITERAL(4, 37, 8), // "readData"
QT_MOC_LITERAL(5, 46, 5), // "error"
QT_MOC_LITERAL(6, 52, 15), // "on_save_clicked"
QT_MOC_LITERAL(7, 68, 20), // "on_connected_clicked"
QT_MOC_LITERAL(8, 89, 16), // "on_clear_clicked"
QT_MOC_LITERAL(9, 106, 15), // "on_send_clicked"
QT_MOC_LITERAL(10, 122, 24) // "on_checkbox_stateChanged"

    },
    "FrmTcpClient\0disconnected\0\0connected\0"
    "readData\0error\0on_save_clicked\0"
    "on_connected_clicked\0on_clear_clicked\0"
    "on_send_clicked\0on_checkbox_stateChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FrmTcpClient[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08 /* Private */,
       3,    0,   60,    2, 0x08 /* Private */,
       4,    0,   61,    2, 0x08 /* Private */,
       5,    0,   62,    2, 0x08 /* Private */,
       6,    0,   63,    2, 0x08 /* Private */,
       7,    0,   64,    2, 0x08 /* Private */,
       8,    0,   65,    2, 0x08 /* Private */,
       9,    0,   66,    2, 0x08 /* Private */,
      10,    0,   67,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FrmTcpClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FrmTcpClient *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->disconnected(); break;
        case 1: _t->connected(); break;
        case 2: _t->readData(); break;
        case 3: _t->error(); break;
        case 4: _t->on_save_clicked(); break;
        case 5: _t->on_connected_clicked(); break;
        case 6: _t->on_clear_clicked(); break;
        case 7: _t->on_send_clicked(); break;
        case 8: _t->on_checkbox_stateChanged(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject FrmTcpClient::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_FrmTcpClient.data,
    qt_meta_data_FrmTcpClient,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FrmTcpClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FrmTcpClient::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FrmTcpClient.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int FrmTcpClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

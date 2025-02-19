/****************************************************************************
** Meta object code from reading C++ file 'dataenginebase.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../DataEngine/dataenginebase.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dataenginebase.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DataEngineBase_t {
    QByteArrayData data[25];
    char stringdata0[285];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DataEngineBase_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DataEngineBase_t qt_meta_stringdata_DataEngineBase = {
    {
QT_MOC_LITERAL(0, 0, 14), // "DataEngineBase"
QT_MOC_LITERAL(1, 15, 22), // "connectionStateChanged"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 17), // "clientNameChanged"
QT_MOC_LITERAL(4, 57, 3), // "arg"
QT_MOC_LITERAL(5, 61, 11), // "hostChanged"
QT_MOC_LITERAL(6, 73, 11), // "portChanged"
QT_MOC_LITERAL(7, 85, 15), // "handleNewSignal"
QT_MOC_LITERAL(8, 101, 2), // "id"
QT_MOC_LITERAL(9, 104, 10), // "signalName"
QT_MOC_LITERAL(10, 115, 8), // "DataType"
QT_MOC_LITERAL(11, 124, 4), // "type"
QT_MOC_LITERAL(12, 129, 19), // "checkConnectionSlot"
QT_MOC_LITERAL(13, 149, 13), // "receiveSignal"
QT_MOC_LITERAL(14, 163, 5), // "value"
QT_MOC_LITERAL(15, 169, 14), // "unsigned char*"
QT_MOC_LITERAL(16, 184, 7), // "msgSize"
QT_MOC_LITERAL(17, 192, 16), // "attemptSubscribe"
QT_MOC_LITERAL(18, 209, 15), // "connectionState"
QT_MOC_LITERAL(19, 225, 15), // "ConnectionState"
QT_MOC_LITERAL(20, 241, 10), // "clientName"
QT_MOC_LITERAL(21, 252, 4), // "host"
QT_MOC_LITERAL(22, 257, 4), // "port"
QT_MOC_LITERAL(23, 262, 12), // "Disconnected"
QT_MOC_LITERAL(24, 275, 9) // "Connected"

    },
    "DataEngineBase\0connectionStateChanged\0"
    "\0clientNameChanged\0arg\0hostChanged\0"
    "portChanged\0handleNewSignal\0id\0"
    "signalName\0DataType\0type\0checkConnectionSlot\0"
    "receiveSignal\0value\0unsigned char*\0"
    "msgSize\0attemptSubscribe\0connectionState\0"
    "ConnectionState\0clientName\0host\0port\0"
    "Disconnected\0Connected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DataEngineBase[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       4,  160, // properties
       1,  176, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x06 /* Public */,
       3,    1,   95,    2, 0x06 /* Public */,
       5,    1,   98,    2, 0x06 /* Public */,
       6,    1,  101,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    3,  104,    2, 0x0a /* Public */,
      12,    0,  111,    2, 0x0a /* Public */,
      13,    2,  112,    2, 0x0a /* Public */,
      13,    2,  117,    2, 0x0a /* Public */,
      13,    2,  122,    2, 0x0a /* Public */,
      13,    2,  127,    2, 0x0a /* Public */,
      13,    2,  132,    2, 0x0a /* Public */,
      13,    2,  137,    2, 0x0a /* Public */,
      13,    2,  142,    2, 0x0a /* Public */,
      13,    2,  147,    2, 0x0a /* Public */,
      13,    3,  152,    2, 0x0a /* Public */,
      17,    0,  159,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::Int,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString, 0x80000000 | 10,    8,    9,   11,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    8,   14,
    QMetaType::Void, QMetaType::Int, QMetaType::SChar,    8,   14,
    QMetaType::Void, QMetaType::Int, QMetaType::Short,    8,   14,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    8,   14,
    QMetaType::Void, QMetaType::Int, QMetaType::Float,    8,   14,
    QMetaType::Void, QMetaType::Int, QMetaType::UInt,    8,   14,
    QMetaType::Void, QMetaType::Int, QMetaType::UShort,    8,   14,
    QMetaType::Void, QMetaType::Int, QMetaType::UChar,    8,   14,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 15, QMetaType::UInt,    8,   14,   16,
    QMetaType::Void,

 // properties: name, type, flags
      18, 0x80000000 | 19, 0x00495009,
      20, QMetaType::QString, 0x00495103,
      21, QMetaType::QString, 0x00495103,
      22, QMetaType::Int, 0x00495103,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,

 // enums: name, alias, flags, count, data
      19,   19, 0x0,    2,  181,

 // enum data: key, value
      23, uint(DataEngineBase::Disconnected),
      24, uint(DataEngineBase::Connected),

       0        // eod
};

void DataEngineBase::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DataEngineBase *_t = static_cast<DataEngineBase *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->connectionStateChanged(); break;
        case 1: _t->clientNameChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->hostChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->portChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->handleNewSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< DataType(*)>(_a[3]))); break;
        case 5: _t->checkConnectionSlot(); break;
        case 6: _t->receiveSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 7: _t->receiveSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< signed char(*)>(_a[2]))); break;
        case 8: _t->receiveSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< short(*)>(_a[2]))); break;
        case 9: _t->receiveSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 10: _t->receiveSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 11: _t->receiveSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2]))); break;
        case 12: _t->receiveSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< unsigned short(*)>(_a[2]))); break;
        case 13: _t->receiveSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< unsigned char(*)>(_a[2]))); break;
        case 14: _t->receiveSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< unsigned char*(*)>(_a[2])),(*reinterpret_cast< uint(*)>(_a[3]))); break;
        case 15: _t->attemptSubscribe(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DataEngineBase::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataEngineBase::connectionStateChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DataEngineBase::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataEngineBase::clientNameChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (DataEngineBase::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataEngineBase::hostChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (DataEngineBase::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataEngineBase::portChanged)) {
                *result = 3;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        DataEngineBase *_t = static_cast<DataEngineBase *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< ConnectionState*>(_v) = _t->connectionState(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->clientName(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->host(); break;
        case 3: *reinterpret_cast< int*>(_v) = _t->port(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        DataEngineBase *_t = static_cast<DataEngineBase *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 1: _t->setClientName(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setHost(*reinterpret_cast< QString*>(_v)); break;
        case 3: _t->setPort(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject DataEngineBase::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_DataEngineBase.data,
    qt_meta_data_DataEngineBase,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DataEngineBase::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DataEngineBase::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DataEngineBase.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int DataEngineBase::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 4;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void DataEngineBase::connectionStateChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void DataEngineBase::clientNameChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void DataEngineBase::hostChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void DataEngineBase::portChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'qtobserver.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../DataEngine/qtobserver.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qtobserver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QtObserver_t {
    QByteArrayData data[14];
    char stringdata0[125];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QtObserver_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QtObserver_t qt_meta_stringdata_QtObserver = {
    {
QT_MOC_LITERAL(0, 0, 10), // "QtObserver"
QT_MOC_LITERAL(1, 11, 11), // "dataChanged"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 5), // "index"
QT_MOC_LITERAL(4, 30, 5), // "value"
QT_MOC_LITERAL(5, 36, 14), // "unsigned char*"
QT_MOC_LITERAL(6, 51, 7), // "msgSize"
QT_MOC_LITERAL(7, 59, 11), // "syncChanged"
QT_MOC_LITERAL(8, 71, 9), // "newSignal"
QT_MOC_LITERAL(9, 81, 2), // "id"
QT_MOC_LITERAL(10, 84, 10), // "signalName"
QT_MOC_LITERAL(11, 95, 8), // "DataType"
QT_MOC_LITERAL(12, 104, 4), // "type"
QT_MOC_LITERAL(13, 109, 15) // "handleHeartBeat"

    },
    "QtObserver\0dataChanged\0\0index\0value\0"
    "unsigned char*\0msgSize\0syncChanged\0"
    "newSignal\0id\0signalName\0DataType\0type\0"
    "handleHeartBeat"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QtObserver[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      11,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   74,    2, 0x06 /* Public */,
       1,    2,   79,    2, 0x06 /* Public */,
       1,    2,   84,    2, 0x06 /* Public */,
       1,    2,   89,    2, 0x06 /* Public */,
       1,    2,   94,    2, 0x06 /* Public */,
       1,    2,   99,    2, 0x06 /* Public */,
       1,    2,  104,    2, 0x06 /* Public */,
       1,    2,  109,    2, 0x06 /* Public */,
       1,    3,  114,    2, 0x06 /* Public */,
       7,    2,  121,    2, 0x06 /* Public */,
       8,    3,  126,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    0,  133,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::SChar,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Short,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::UChar,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::UShort,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::UInt,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Float,    3,    4,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 5, QMetaType::UInt,    3,    4,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, 0x80000000 | 11,    9,   10,   12,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void QtObserver::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QtObserver *_t = static_cast<QtObserver *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->dataChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< signed char(*)>(_a[2]))); break;
        case 1: _t->dataChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< short(*)>(_a[2]))); break;
        case 2: _t->dataChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->dataChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< unsigned char(*)>(_a[2]))); break;
        case 4: _t->dataChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< unsigned short(*)>(_a[2]))); break;
        case 5: _t->dataChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2]))); break;
        case 6: _t->dataChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 7: _t->dataChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 8: _t->dataChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< unsigned char*(*)>(_a[2])),(*reinterpret_cast< uint(*)>(_a[3]))); break;
        case 9: _t->syncChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 10: _t->newSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< DataType(*)>(_a[3]))); break;
        case 11: _t->handleHeartBeat(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QtObserver::*)(int , signed char );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtObserver::dataChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (QtObserver::*)(int , short );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtObserver::dataChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (QtObserver::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtObserver::dataChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (QtObserver::*)(int , unsigned char );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtObserver::dataChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (QtObserver::*)(int , unsigned short );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtObserver::dataChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (QtObserver::*)(int , unsigned int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtObserver::dataChanged)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (QtObserver::*)(int , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtObserver::dataChanged)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (QtObserver::*)(int , float );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtObserver::dataChanged)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (QtObserver::*)(int , unsigned char * , unsigned int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtObserver::dataChanged)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (QtObserver::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtObserver::syncChanged)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (QtObserver::*)(int , QString , DataType );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtObserver::newSignal)) {
                *result = 10;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QtObserver::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_QtObserver.data,
    qt_meta_data_QtObserver,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QtObserver::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtObserver::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QtObserver.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "ISAPObserver"))
        return static_cast< ISAPObserver*>(this);
    return QObject::qt_metacast(_clname);
}

int QtObserver::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void QtObserver::dataChanged(int _t1, signed char _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QtObserver::dataChanged(int _t1, short _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QtObserver::dataChanged(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QtObserver::dataChanged(int _t1, unsigned char _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void QtObserver::dataChanged(int _t1, unsigned short _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void QtObserver::dataChanged(int _t1, unsigned int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void QtObserver::dataChanged(int _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void QtObserver::dataChanged(int _t1, float _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void QtObserver::dataChanged(int _t1, unsigned char * _t2, unsigned int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void QtObserver::syncChanged(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void QtObserver::newSignal(int _t1, QString _t2, DataType _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

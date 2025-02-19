/****************************************************************************
** Meta object code from reading C++ file 'dataenginesignal.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../DataEngine/dataenginesignal.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dataenginesignal.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DataEngineSignal_t {
    QByteArrayData data[22];
    char stringdata0[227];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DataEngineSignal_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DataEngineSignal_t qt_meta_stringdata_DataEngineSignal = {
    {
QT_MOC_LITERAL(0, 0, 16), // "DataEngineSignal"
QT_MOC_LITERAL(1, 17, 12), // "valueChanged"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 5), // "value"
QT_MOC_LITERAL(4, 37, 9), // "sendValue"
QT_MOC_LITERAL(5, 47, 3), // "arg"
QT_MOC_LITERAL(6, 51, 13), // "statusChanged"
QT_MOC_LITERAL(7, 65, 11), // "ErrorStatus"
QT_MOC_LITERAL(8, 77, 13), // "errorsChanged"
QT_MOC_LITERAL(9, 91, 15), // "QList<QObject*>"
QT_MOC_LITERAL(10, 107, 12), // "receiveValue"
QT_MOC_LITERAL(11, 120, 8), // "setValue"
QT_MOC_LITERAL(12, 129, 9), // "setStatus"
QT_MOC_LITERAL(13, 139, 6), // "status"
QT_MOC_LITERAL(14, 146, 8), // "addError"
QT_MOC_LITERAL(15, 155, 20), // "FieldbusAccessError*"
QT_MOC_LITERAL(16, 176, 5), // "error"
QT_MOC_LITERAL(17, 182, 11), // "removeError"
QT_MOC_LITERAL(18, 194, 6), // "errors"
QT_MOC_LITERAL(19, 201, 2), // "OK"
QT_MOC_LITERAL(20, 204, 11), // "SIGNALERROR"
QT_MOC_LITERAL(21, 216, 10) // "STACKERROR"

    },
    "DataEngineSignal\0valueChanged\0\0value\0"
    "sendValue\0arg\0statusChanged\0ErrorStatus\0"
    "errorsChanged\0QList<QObject*>\0"
    "receiveValue\0setValue\0setStatus\0status\0"
    "addError\0FieldbusAccessError*\0error\0"
    "removeError\0errors\0OK\0SIGNALERROR\0"
    "STACKERROR"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DataEngineSignal[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       2,   86, // properties
       1,   94, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       4,    1,   62,    2, 0x06 /* Public */,
       6,    1,   65,    2, 0x06 /* Public */,
       8,    1,   68,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    1,   71,    2, 0x0a /* Public */,
      11,    1,   74,    2, 0x0a /* Public */,
      12,    1,   77,    2, 0x0a /* Public */,
      14,    1,   80,    2, 0x0a /* Public */,
      17,    1,   83,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QVariant,    3,
    QMetaType::Void, QMetaType::QVariant,    5,
    QMetaType::Void, 0x80000000 | 7,    5,
    QMetaType::Void, 0x80000000 | 9,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::QVariant,    3,
    QMetaType::Void, QMetaType::QVariant,    3,
    QMetaType::Void, 0x80000000 | 7,   13,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void, 0x80000000 | 15,   16,

 // properties: name, type, flags
      13, 0x80000000 | 7, 0x00495009,
      18, 0x80000000 | 9, 0x00495009,

 // properties: notify_signal_id
       2,
       3,

 // enums: name, alias, flags, count, data
       7,    7, 0x0,    3,   99,

 // enum data: key, value
      19, uint(DataEngineSignal::OK),
      20, uint(DataEngineSignal::SIGNALERROR),
      21, uint(DataEngineSignal::STACKERROR),

       0        // eod
};

void DataEngineSignal::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DataEngineSignal *_t = static_cast<DataEngineSignal *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< QVariant(*)>(_a[1]))); break;
        case 1: _t->sendValue((*reinterpret_cast< QVariant(*)>(_a[1]))); break;
        case 2: _t->statusChanged((*reinterpret_cast< ErrorStatus(*)>(_a[1]))); break;
        case 3: _t->errorsChanged((*reinterpret_cast< QList<QObject*>(*)>(_a[1]))); break;
        case 4: _t->receiveValue((*reinterpret_cast< QVariant(*)>(_a[1]))); break;
        case 5: _t->setValue((*reinterpret_cast< QVariant(*)>(_a[1]))); break;
        case 6: _t->setStatus((*reinterpret_cast< ErrorStatus(*)>(_a[1]))); break;
        case 7: _t->addError((*reinterpret_cast< FieldbusAccessError*(*)>(_a[1]))); break;
        case 8: _t->removeError((*reinterpret_cast< FieldbusAccessError*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QObject*> >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< FieldbusAccessError* >(); break;
            }
            break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< FieldbusAccessError* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DataEngineSignal::*)(QVariant );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataEngineSignal::valueChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DataEngineSignal::*)(QVariant );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataEngineSignal::sendValue)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (DataEngineSignal::*)(ErrorStatus );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataEngineSignal::statusChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (DataEngineSignal::*)(QList<QObject*> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataEngineSignal::errorsChanged)) {
                *result = 3;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QObject*> >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        DataEngineSignal *_t = static_cast<DataEngineSignal *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< ErrorStatus*>(_v) = _t->status(); break;
        case 1: *reinterpret_cast< QList<QObject*>*>(_v) = _t->errors(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject DataEngineSignal::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_DataEngineSignal.data,
    qt_meta_data_DataEngineSignal,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DataEngineSignal::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DataEngineSignal::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DataEngineSignal.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int DataEngineSignal::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void DataEngineSignal::valueChanged(QVariant _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DataEngineSignal::sendValue(QVariant _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void DataEngineSignal::statusChanged(ErrorStatus _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void DataEngineSignal::errorsChanged(QList<QObject*> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
struct qt_meta_stringdata_ConsumerSignal_t {
    QByteArrayData data[5];
    char stringdata0[39];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ConsumerSignal_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ConsumerSignal_t qt_meta_stringdata_ConsumerSignal = {
    {
QT_MOC_LITERAL(0, 0, 14), // "ConsumerSignal"
QT_MOC_LITERAL(1, 15, 12), // "valueChanged"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 3), // "arg"
QT_MOC_LITERAL(4, 33, 5) // "value"

    },
    "ConsumerSignal\0valueChanged\0\0arg\0value"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ConsumerSignal[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       1,   22, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QVariant,    3,

 // properties: name, type, flags
       4, QMetaType::QVariant, 0x00495001,

 // properties: notify_signal_id
       0,

       0        // eod
};

void ConsumerSignal::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ConsumerSignal *_t = static_cast<ConsumerSignal *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< QVariant(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ConsumerSignal::*)(QVariant );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ConsumerSignal::valueChanged)) {
                *result = 0;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        ConsumerSignal *_t = static_cast<ConsumerSignal *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QVariant*>(_v) = _t->value(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject ConsumerSignal::staticMetaObject = { {
    &DataEngineSignal::staticMetaObject,
    qt_meta_stringdata_ConsumerSignal.data,
    qt_meta_data_ConsumerSignal,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ConsumerSignal::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ConsumerSignal::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ConsumerSignal.stringdata0))
        return static_cast<void*>(this);
    return DataEngineSignal::qt_metacast(_clname);
}

int ConsumerSignal::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = DataEngineSignal::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void ConsumerSignal::valueChanged(QVariant _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_IntConsumerSignal_t {
    QByteArrayData data[5];
    char stringdata0[42];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_IntConsumerSignal_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_IntConsumerSignal_t qt_meta_stringdata_IntConsumerSignal = {
    {
QT_MOC_LITERAL(0, 0, 17), // "IntConsumerSignal"
QT_MOC_LITERAL(1, 18, 12), // "valueChanged"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 3), // "arg"
QT_MOC_LITERAL(4, 36, 5) // "value"

    },
    "IntConsumerSignal\0valueChanged\0\0arg\0"
    "value"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IntConsumerSignal[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       1,   22, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

 // properties: name, type, flags
       4, QMetaType::Int, 0x00495001,

 // properties: notify_signal_id
       0,

       0        // eod
};

void IntConsumerSignal::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        IntConsumerSignal *_t = static_cast<IntConsumerSignal *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (IntConsumerSignal::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&IntConsumerSignal::valueChanged)) {
                *result = 0;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        IntConsumerSignal *_t = static_cast<IntConsumerSignal *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->value(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject IntConsumerSignal::staticMetaObject = { {
    &DataEngineSignal::staticMetaObject,
    qt_meta_stringdata_IntConsumerSignal.data,
    qt_meta_data_IntConsumerSignal,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *IntConsumerSignal::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IntConsumerSignal::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_IntConsumerSignal.stringdata0))
        return static_cast<void*>(this);
    return DataEngineSignal::qt_metacast(_clname);
}

int IntConsumerSignal::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = DataEngineSignal::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void IntConsumerSignal::valueChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_UIntConsumerSignal_t {
    QByteArrayData data[5];
    char stringdata0[43];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UIntConsumerSignal_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UIntConsumerSignal_t qt_meta_stringdata_UIntConsumerSignal = {
    {
QT_MOC_LITERAL(0, 0, 18), // "UIntConsumerSignal"
QT_MOC_LITERAL(1, 19, 12), // "valueChanged"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 3), // "arg"
QT_MOC_LITERAL(4, 37, 5) // "value"

    },
    "UIntConsumerSignal\0valueChanged\0\0arg\0"
    "value"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UIntConsumerSignal[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       1,   22, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::UInt,    3,

 // properties: name, type, flags
       4, QMetaType::UInt, 0x00495001,

 // properties: notify_signal_id
       0,

       0        // eod
};

void UIntConsumerSignal::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UIntConsumerSignal *_t = static_cast<UIntConsumerSignal *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< uint(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (UIntConsumerSignal::*)(uint );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UIntConsumerSignal::valueChanged)) {
                *result = 0;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        UIntConsumerSignal *_t = static_cast<UIntConsumerSignal *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< uint*>(_v) = _t->value(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject UIntConsumerSignal::staticMetaObject = { {
    &DataEngineSignal::staticMetaObject,
    qt_meta_stringdata_UIntConsumerSignal.data,
    qt_meta_data_UIntConsumerSignal,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *UIntConsumerSignal::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UIntConsumerSignal::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_UIntConsumerSignal.stringdata0))
        return static_cast<void*>(this);
    return DataEngineSignal::qt_metacast(_clname);
}

int UIntConsumerSignal::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = DataEngineSignal::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void UIntConsumerSignal::valueChanged(uint _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_ShortConsumerSignal_t {
    QByteArrayData data[5];
    char stringdata0[44];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ShortConsumerSignal_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ShortConsumerSignal_t qt_meta_stringdata_ShortConsumerSignal = {
    {
QT_MOC_LITERAL(0, 0, 19), // "ShortConsumerSignal"
QT_MOC_LITERAL(1, 20, 12), // "valueChanged"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 3), // "arg"
QT_MOC_LITERAL(4, 38, 5) // "value"

    },
    "ShortConsumerSignal\0valueChanged\0\0arg\0"
    "value"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ShortConsumerSignal[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       1,   22, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Short,    3,

 // properties: name, type, flags
       4, QMetaType::Short, 0x00495001,

 // properties: notify_signal_id
       0,

       0        // eod
};

void ShortConsumerSignal::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ShortConsumerSignal *_t = static_cast<ShortConsumerSignal *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< short(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ShortConsumerSignal::*)(short );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ShortConsumerSignal::valueChanged)) {
                *result = 0;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        ShortConsumerSignal *_t = static_cast<ShortConsumerSignal *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< short*>(_v) = _t->value(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject ShortConsumerSignal::staticMetaObject = { {
    &DataEngineSignal::staticMetaObject,
    qt_meta_stringdata_ShortConsumerSignal.data,
    qt_meta_data_ShortConsumerSignal,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ShortConsumerSignal::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ShortConsumerSignal::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ShortConsumerSignal.stringdata0))
        return static_cast<void*>(this);
    return DataEngineSignal::qt_metacast(_clname);
}

int ShortConsumerSignal::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = DataEngineSignal::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void ShortConsumerSignal::valueChanged(short _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_UShortConsumerSignal_t {
    QByteArrayData data[5];
    char stringdata0[45];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UShortConsumerSignal_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UShortConsumerSignal_t qt_meta_stringdata_UShortConsumerSignal = {
    {
QT_MOC_LITERAL(0, 0, 20), // "UShortConsumerSignal"
QT_MOC_LITERAL(1, 21, 12), // "valueChanged"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 3), // "arg"
QT_MOC_LITERAL(4, 39, 5) // "value"

    },
    "UShortConsumerSignal\0valueChanged\0\0"
    "arg\0value"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UShortConsumerSignal[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       1,   22, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::UShort,    3,

 // properties: name, type, flags
       4, QMetaType::UShort, 0x00495001,

 // properties: notify_signal_id
       0,

       0        // eod
};

void UShortConsumerSignal::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UShortConsumerSignal *_t = static_cast<UShortConsumerSignal *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< unsigned short(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (UShortConsumerSignal::*)(unsigned short );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UShortConsumerSignal::valueChanged)) {
                *result = 0;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        UShortConsumerSignal *_t = static_cast<UShortConsumerSignal *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< unsigned short*>(_v) = _t->value(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject UShortConsumerSignal::staticMetaObject = { {
    &DataEngineSignal::staticMetaObject,
    qt_meta_stringdata_UShortConsumerSignal.data,
    qt_meta_data_UShortConsumerSignal,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *UShortConsumerSignal::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UShortConsumerSignal::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_UShortConsumerSignal.stringdata0))
        return static_cast<void*>(this);
    return DataEngineSignal::qt_metacast(_clname);
}

int UShortConsumerSignal::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = DataEngineSignal::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void UShortConsumerSignal::valueChanged(unsigned short _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_CharConsumerSignal_t {
    QByteArrayData data[5];
    char stringdata0[43];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CharConsumerSignal_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CharConsumerSignal_t qt_meta_stringdata_CharConsumerSignal = {
    {
QT_MOC_LITERAL(0, 0, 18), // "CharConsumerSignal"
QT_MOC_LITERAL(1, 19, 12), // "valueChanged"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 3), // "arg"
QT_MOC_LITERAL(4, 37, 5) // "value"

    },
    "CharConsumerSignal\0valueChanged\0\0arg\0"
    "value"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CharConsumerSignal[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       1,   22, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::SChar,    3,

 // properties: name, type, flags
       4, QMetaType::SChar, 0x00495001,

 // properties: notify_signal_id
       0,

       0        // eod
};

void CharConsumerSignal::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CharConsumerSignal *_t = static_cast<CharConsumerSignal *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< signed char(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CharConsumerSignal::*)(signed char );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CharConsumerSignal::valueChanged)) {
                *result = 0;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        CharConsumerSignal *_t = static_cast<CharConsumerSignal *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< signed char*>(_v) = _t->value(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject CharConsumerSignal::staticMetaObject = { {
    &DataEngineSignal::staticMetaObject,
    qt_meta_stringdata_CharConsumerSignal.data,
    qt_meta_data_CharConsumerSignal,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CharConsumerSignal::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CharConsumerSignal::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CharConsumerSignal.stringdata0))
        return static_cast<void*>(this);
    return DataEngineSignal::qt_metacast(_clname);
}

int CharConsumerSignal::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = DataEngineSignal::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void CharConsumerSignal::valueChanged(signed char _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_UCharConsumerSignal_t {
    QByteArrayData data[5];
    char stringdata0[44];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UCharConsumerSignal_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UCharConsumerSignal_t qt_meta_stringdata_UCharConsumerSignal = {
    {
QT_MOC_LITERAL(0, 0, 19), // "UCharConsumerSignal"
QT_MOC_LITERAL(1, 20, 12), // "valueChanged"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 3), // "arg"
QT_MOC_LITERAL(4, 38, 5) // "value"

    },
    "UCharConsumerSignal\0valueChanged\0\0arg\0"
    "value"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UCharConsumerSignal[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       1,   22, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::UChar,    3,

 // properties: name, type, flags
       4, QMetaType::UChar, 0x00495001,

 // properties: notify_signal_id
       0,

       0        // eod
};

void UCharConsumerSignal::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UCharConsumerSignal *_t = static_cast<UCharConsumerSignal *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< unsigned char(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (UCharConsumerSignal::*)(unsigned char );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UCharConsumerSignal::valueChanged)) {
                *result = 0;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        UCharConsumerSignal *_t = static_cast<UCharConsumerSignal *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< unsigned char*>(_v) = _t->value(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject UCharConsumerSignal::staticMetaObject = { {
    &DataEngineSignal::staticMetaObject,
    qt_meta_stringdata_UCharConsumerSignal.data,
    qt_meta_data_UCharConsumerSignal,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *UCharConsumerSignal::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UCharConsumerSignal::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_UCharConsumerSignal.stringdata0))
        return static_cast<void*>(this);
    return DataEngineSignal::qt_metacast(_clname);
}

int UCharConsumerSignal::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = DataEngineSignal::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void UCharConsumerSignal::valueChanged(unsigned char _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_BoolConsumerSignal_t {
    QByteArrayData data[5];
    char stringdata0[43];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BoolConsumerSignal_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BoolConsumerSignal_t qt_meta_stringdata_BoolConsumerSignal = {
    {
QT_MOC_LITERAL(0, 0, 18), // "BoolConsumerSignal"
QT_MOC_LITERAL(1, 19, 12), // "valueChanged"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 3), // "arg"
QT_MOC_LITERAL(4, 37, 5) // "value"

    },
    "BoolConsumerSignal\0valueChanged\0\0arg\0"
    "value"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BoolConsumerSignal[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       1,   22, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,

 // properties: name, type, flags
       4, QMetaType::Bool, 0x00495001,

 // properties: notify_signal_id
       0,

       0        // eod
};

void BoolConsumerSignal::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BoolConsumerSignal *_t = static_cast<BoolConsumerSignal *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (BoolConsumerSignal::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BoolConsumerSignal::valueChanged)) {
                *result = 0;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        BoolConsumerSignal *_t = static_cast<BoolConsumerSignal *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->value(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject BoolConsumerSignal::staticMetaObject = { {
    &DataEngineSignal::staticMetaObject,
    qt_meta_stringdata_BoolConsumerSignal.data,
    qt_meta_data_BoolConsumerSignal,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *BoolConsumerSignal::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BoolConsumerSignal::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BoolConsumerSignal.stringdata0))
        return static_cast<void*>(this);
    return DataEngineSignal::qt_metacast(_clname);
}

int BoolConsumerSignal::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = DataEngineSignal::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void BoolConsumerSignal::valueChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_FloatConsumerSignal_t {
    QByteArrayData data[5];
    char stringdata0[44];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FloatConsumerSignal_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FloatConsumerSignal_t qt_meta_stringdata_FloatConsumerSignal = {
    {
QT_MOC_LITERAL(0, 0, 19), // "FloatConsumerSignal"
QT_MOC_LITERAL(1, 20, 12), // "valueChanged"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 3), // "arg"
QT_MOC_LITERAL(4, 38, 5) // "value"

    },
    "FloatConsumerSignal\0valueChanged\0\0arg\0"
    "value"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FloatConsumerSignal[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       1,   22, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Float,    3,

 // properties: name, type, flags
       4, QMetaType::Float, 0x00495001,

 // properties: notify_signal_id
       0,

       0        // eod
};

void FloatConsumerSignal::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FloatConsumerSignal *_t = static_cast<FloatConsumerSignal *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FloatConsumerSignal::*)(float );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FloatConsumerSignal::valueChanged)) {
                *result = 0;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        FloatConsumerSignal *_t = static_cast<FloatConsumerSignal *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< float*>(_v) = _t->value(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject FloatConsumerSignal::staticMetaObject = { {
    &DataEngineSignal::staticMetaObject,
    qt_meta_stringdata_FloatConsumerSignal.data,
    qt_meta_data_FloatConsumerSignal,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FloatConsumerSignal::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FloatConsumerSignal::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FloatConsumerSignal.stringdata0))
        return static_cast<void*>(this);
    return DataEngineSignal::qt_metacast(_clname);
}

int FloatConsumerSignal::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = DataEngineSignal::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void FloatConsumerSignal::valueChanged(float _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_QByteArrayConsumerSignal_t {
    QByteArrayData data[5];
    char stringdata0[49];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QByteArrayConsumerSignal_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QByteArrayConsumerSignal_t qt_meta_stringdata_QByteArrayConsumerSignal = {
    {
QT_MOC_LITERAL(0, 0, 24), // "QByteArrayConsumerSignal"
QT_MOC_LITERAL(1, 25, 12), // "valueChanged"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 3), // "arg"
QT_MOC_LITERAL(4, 43, 5) // "value"

    },
    "QByteArrayConsumerSignal\0valueChanged\0"
    "\0arg\0value"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QByteArrayConsumerSignal[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       1,   22, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray,    3,

 // properties: name, type, flags
       4, QMetaType::QByteArray, 0x00495001,

 // properties: notify_signal_id
       0,

       0        // eod
};

void QByteArrayConsumerSignal::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QByteArrayConsumerSignal *_t = static_cast<QByteArrayConsumerSignal *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QByteArrayConsumerSignal::*)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QByteArrayConsumerSignal::valueChanged)) {
                *result = 0;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        QByteArrayConsumerSignal *_t = static_cast<QByteArrayConsumerSignal *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QByteArray*>(_v) = _t->value(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject QByteArrayConsumerSignal::staticMetaObject = { {
    &DataEngineSignal::staticMetaObject,
    qt_meta_stringdata_QByteArrayConsumerSignal.data,
    qt_meta_data_QByteArrayConsumerSignal,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QByteArrayConsumerSignal::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QByteArrayConsumerSignal::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QByteArrayConsumerSignal.stringdata0))
        return static_cast<void*>(this);
    return DataEngineSignal::qt_metacast(_clname);
}

int QByteArrayConsumerSignal::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = DataEngineSignal::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void QByteArrayConsumerSignal::valueChanged(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_QStringConsumerSignal_t {
    QByteArrayData data[5];
    char stringdata0[46];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QStringConsumerSignal_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QStringConsumerSignal_t qt_meta_stringdata_QStringConsumerSignal = {
    {
QT_MOC_LITERAL(0, 0, 21), // "QStringConsumerSignal"
QT_MOC_LITERAL(1, 22, 12), // "valueChanged"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 3), // "arg"
QT_MOC_LITERAL(4, 40, 5) // "value"

    },
    "QStringConsumerSignal\0valueChanged\0\0"
    "arg\0value"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QStringConsumerSignal[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       1,   22, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // properties: name, type, flags
       4, QMetaType::QString, 0x00495001,

 // properties: notify_signal_id
       0,

       0        // eod
};

void QStringConsumerSignal::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QStringConsumerSignal *_t = static_cast<QStringConsumerSignal *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QStringConsumerSignal::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QStringConsumerSignal::valueChanged)) {
                *result = 0;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        QStringConsumerSignal *_t = static_cast<QStringConsumerSignal *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->value(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject QStringConsumerSignal::staticMetaObject = { {
    &DataEngineSignal::staticMetaObject,
    qt_meta_stringdata_QStringConsumerSignal.data,
    qt_meta_data_QStringConsumerSignal,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QStringConsumerSignal::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QStringConsumerSignal::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QStringConsumerSignal.stringdata0))
        return static_cast<void*>(this);
    return DataEngineSignal::qt_metacast(_clname);
}

int QStringConsumerSignal::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = DataEngineSignal::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void QStringConsumerSignal::valueChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_ProducerSignal_t {
    QByteArrayData data[7];
    char stringdata0[58];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ProducerSignal_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ProducerSignal_t qt_meta_stringdata_ProducerSignal = {
    {
QT_MOC_LITERAL(0, 0, 14), // "ProducerSignal"
QT_MOC_LITERAL(1, 15, 12), // "valueChanged"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 3), // "arg"
QT_MOC_LITERAL(4, 33, 9), // "sendValue"
QT_MOC_LITERAL(5, 43, 8), // "setValue"
QT_MOC_LITERAL(6, 52, 5) // "value"

    },
    "ProducerSignal\0valueChanged\0\0arg\0"
    "sendValue\0setValue\0value"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ProducerSignal[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       1,   38, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       4,    1,   32,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   35,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QVariant,    3,
    QMetaType::Void, QMetaType::QVariant,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QVariant,    6,

 // properties: name, type, flags
       6, QMetaType::QVariant, 0x00495103,

 // properties: notify_signal_id
       0,

       0        // eod
};

void ProducerSignal::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ProducerSignal *_t = static_cast<ProducerSignal *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< QVariant(*)>(_a[1]))); break;
        case 1: _t->sendValue((*reinterpret_cast< QVariant(*)>(_a[1]))); break;
        case 2: _t->setValue((*reinterpret_cast< QVariant(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ProducerSignal::*)(QVariant );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ProducerSignal::valueChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ProducerSignal::*)(QVariant );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ProducerSignal::sendValue)) {
                *result = 1;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        ProducerSignal *_t = static_cast<ProducerSignal *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QVariant*>(_v) = _t->value(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        ProducerSignal *_t = static_cast<ProducerSignal *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setValue(*reinterpret_cast< QVariant*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject ProducerSignal::staticMetaObject = { {
    &DataEngineSignal::staticMetaObject,
    qt_meta_stringdata_ProducerSignal.data,
    qt_meta_data_ProducerSignal,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ProducerSignal::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ProducerSignal::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ProducerSignal.stringdata0))
        return static_cast<void*>(this);
    return DataEngineSignal::qt_metacast(_clname);
}

int ProducerSignal::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = DataEngineSignal::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void ProducerSignal::valueChanged(QVariant _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ProducerSignal::sendValue(QVariant _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
struct qt_meta_stringdata_IntProducerSignal_t {
    QByteArrayData data[8];
    char stringdata0[63];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_IntProducerSignal_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_IntProducerSignal_t qt_meta_stringdata_IntProducerSignal = {
    {
QT_MOC_LITERAL(0, 0, 17), // "IntProducerSignal"
QT_MOC_LITERAL(1, 18, 12), // "valueChanged"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 3), // "arg"
QT_MOC_LITERAL(4, 36, 9), // "sendValue"
QT_MOC_LITERAL(5, 46, 8), // "setValue"
QT_MOC_LITERAL(6, 55, 1), // "v"
QT_MOC_LITERAL(7, 57, 5) // "value"

    },
    "IntProducerSignal\0valueChanged\0\0arg\0"
    "sendValue\0setValue\0v\0value"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IntProducerSignal[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       1,   38, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       4,    1,   32,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   35,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    6,

 // properties: name, type, flags
       7, QMetaType::Int, 0x00495103,

 // properties: notify_signal_id
       0,

       0        // eod
};

void IntProducerSignal::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        IntProducerSignal *_t = static_cast<IntProducerSignal *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->sendValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->setValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (IntProducerSignal::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&IntProducerSignal::valueChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (IntProducerSignal::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&IntProducerSignal::sendValue)) {
                *result = 1;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        IntProducerSignal *_t = static_cast<IntProducerSignal *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->value(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        IntProducerSignal *_t = static_cast<IntProducerSignal *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setValue(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject IntProducerSignal::staticMetaObject = { {
    &DataEngineSignal::staticMetaObject,
    qt_meta_stringdata_IntProducerSignal.data,
    qt_meta_data_IntProducerSignal,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *IntProducerSignal::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IntProducerSignal::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_IntProducerSignal.stringdata0))
        return static_cast<void*>(this);
    return DataEngineSignal::qt_metacast(_clname);
}

int IntProducerSignal::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = DataEngineSignal::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void IntProducerSignal::valueChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void IntProducerSignal::sendValue(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
struct qt_meta_stringdata_UIntProducerSignal_t {
    QByteArrayData data[8];
    char stringdata0[64];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UIntProducerSignal_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UIntProducerSignal_t qt_meta_stringdata_UIntProducerSignal = {
    {
QT_MOC_LITERAL(0, 0, 18), // "UIntProducerSignal"
QT_MOC_LITERAL(1, 19, 12), // "valueChanged"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 3), // "arg"
QT_MOC_LITERAL(4, 37, 9), // "sendValue"
QT_MOC_LITERAL(5, 47, 8), // "setValue"
QT_MOC_LITERAL(6, 56, 1), // "v"
QT_MOC_LITERAL(7, 58, 5) // "value"

    },
    "UIntProducerSignal\0valueChanged\0\0arg\0"
    "sendValue\0setValue\0v\0value"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UIntProducerSignal[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       1,   38, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       4,    1,   32,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   35,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::UInt,    3,
    QMetaType::Void, QMetaType::UInt,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::UInt,    6,

 // properties: name, type, flags
       7, QMetaType::UInt, 0x00495103,

 // properties: notify_signal_id
       0,

       0        // eod
};

void UIntProducerSignal::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UIntProducerSignal *_t = static_cast<UIntProducerSignal *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 1: _t->sendValue((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 2: _t->setValue((*reinterpret_cast< uint(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (UIntProducerSignal::*)(uint );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UIntProducerSignal::valueChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (UIntProducerSignal::*)(uint );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UIntProducerSignal::sendValue)) {
                *result = 1;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        UIntProducerSignal *_t = static_cast<UIntProducerSignal *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< uint*>(_v) = _t->value(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        UIntProducerSignal *_t = static_cast<UIntProducerSignal *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setValue(*reinterpret_cast< uint*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject UIntProducerSignal::staticMetaObject = { {
    &DataEngineSignal::staticMetaObject,
    qt_meta_stringdata_UIntProducerSignal.data,
    qt_meta_data_UIntProducerSignal,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *UIntProducerSignal::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UIntProducerSignal::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_UIntProducerSignal.stringdata0))
        return static_cast<void*>(this);
    return DataEngineSignal::qt_metacast(_clname);
}

int UIntProducerSignal::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = DataEngineSignal::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void UIntProducerSignal::valueChanged(uint _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void UIntProducerSignal::sendValue(uint _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
struct qt_meta_stringdata_ShortProducerSignal_t {
    QByteArrayData data[8];
    char stringdata0[65];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ShortProducerSignal_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ShortProducerSignal_t qt_meta_stringdata_ShortProducerSignal = {
    {
QT_MOC_LITERAL(0, 0, 19), // "ShortProducerSignal"
QT_MOC_LITERAL(1, 20, 12), // "valueChanged"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 3), // "arg"
QT_MOC_LITERAL(4, 38, 9), // "sendValue"
QT_MOC_LITERAL(5, 48, 8), // "setValue"
QT_MOC_LITERAL(6, 57, 1), // "v"
QT_MOC_LITERAL(7, 59, 5) // "value"

    },
    "ShortProducerSignal\0valueChanged\0\0arg\0"
    "sendValue\0setValue\0v\0value"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ShortProducerSignal[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       1,   38, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       4,    1,   32,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   35,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Short,    3,
    QMetaType::Void, QMetaType::Short,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Short,    6,

 // properties: name, type, flags
       7, QMetaType::Short, 0x00495103,

 // properties: notify_signal_id
       0,

       0        // eod
};

void ShortProducerSignal::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ShortProducerSignal *_t = static_cast<ShortProducerSignal *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< short(*)>(_a[1]))); break;
        case 1: _t->sendValue((*reinterpret_cast< short(*)>(_a[1]))); break;
        case 2: _t->setValue((*reinterpret_cast< short(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ShortProducerSignal::*)(short );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ShortProducerSignal::valueChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ShortProducerSignal::*)(short );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ShortProducerSignal::sendValue)) {
                *result = 1;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        ShortProducerSignal *_t = static_cast<ShortProducerSignal *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< short*>(_v) = _t->value(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        ShortProducerSignal *_t = static_cast<ShortProducerSignal *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setValue(*reinterpret_cast< short*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject ShortProducerSignal::staticMetaObject = { {
    &DataEngineSignal::staticMetaObject,
    qt_meta_stringdata_ShortProducerSignal.data,
    qt_meta_data_ShortProducerSignal,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ShortProducerSignal::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ShortProducerSignal::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ShortProducerSignal.stringdata0))
        return static_cast<void*>(this);
    return DataEngineSignal::qt_metacast(_clname);
}

int ShortProducerSignal::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = DataEngineSignal::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void ShortProducerSignal::valueChanged(short _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ShortProducerSignal::sendValue(short _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
struct qt_meta_stringdata_UShortProducerSignal_t {
    QByteArrayData data[8];
    char stringdata0[66];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UShortProducerSignal_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UShortProducerSignal_t qt_meta_stringdata_UShortProducerSignal = {
    {
QT_MOC_LITERAL(0, 0, 20), // "UShortProducerSignal"
QT_MOC_LITERAL(1, 21, 12), // "valueChanged"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 3), // "arg"
QT_MOC_LITERAL(4, 39, 9), // "sendValue"
QT_MOC_LITERAL(5, 49, 8), // "setValue"
QT_MOC_LITERAL(6, 58, 1), // "v"
QT_MOC_LITERAL(7, 60, 5) // "value"

    },
    "UShortProducerSignal\0valueChanged\0\0"
    "arg\0sendValue\0setValue\0v\0value"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UShortProducerSignal[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       1,   38, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       4,    1,   32,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   35,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::UShort,    3,
    QMetaType::Void, QMetaType::UShort,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::UShort,    6,

 // properties: name, type, flags
       7, QMetaType::UShort, 0x00495103,

 // properties: notify_signal_id
       0,

       0        // eod
};

void UShortProducerSignal::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UShortProducerSignal *_t = static_cast<UShortProducerSignal *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< ushort(*)>(_a[1]))); break;
        case 1: _t->sendValue((*reinterpret_cast< ushort(*)>(_a[1]))); break;
        case 2: _t->setValue((*reinterpret_cast< ushort(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (UShortProducerSignal::*)(ushort );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UShortProducerSignal::valueChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (UShortProducerSignal::*)(ushort );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UShortProducerSignal::sendValue)) {
                *result = 1;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        UShortProducerSignal *_t = static_cast<UShortProducerSignal *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< ushort*>(_v) = _t->value(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        UShortProducerSignal *_t = static_cast<UShortProducerSignal *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setValue(*reinterpret_cast< ushort*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject UShortProducerSignal::staticMetaObject = { {
    &DataEngineSignal::staticMetaObject,
    qt_meta_stringdata_UShortProducerSignal.data,
    qt_meta_data_UShortProducerSignal,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *UShortProducerSignal::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UShortProducerSignal::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_UShortProducerSignal.stringdata0))
        return static_cast<void*>(this);
    return DataEngineSignal::qt_metacast(_clname);
}

int UShortProducerSignal::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = DataEngineSignal::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void UShortProducerSignal::valueChanged(ushort _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void UShortProducerSignal::sendValue(ushort _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
struct qt_meta_stringdata_CharProducerSignal_t {
    QByteArrayData data[8];
    char stringdata0[64];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CharProducerSignal_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CharProducerSignal_t qt_meta_stringdata_CharProducerSignal = {
    {
QT_MOC_LITERAL(0, 0, 18), // "CharProducerSignal"
QT_MOC_LITERAL(1, 19, 12), // "valueChanged"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 3), // "arg"
QT_MOC_LITERAL(4, 37, 9), // "sendValue"
QT_MOC_LITERAL(5, 47, 8), // "setValue"
QT_MOC_LITERAL(6, 56, 1), // "v"
QT_MOC_LITERAL(7, 58, 5) // "value"

    },
    "CharProducerSignal\0valueChanged\0\0arg\0"
    "sendValue\0setValue\0v\0value"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CharProducerSignal[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       1,   38, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       4,    1,   32,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   35,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::SChar,    3,
    QMetaType::Void, QMetaType::SChar,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::SChar,    6,

 // properties: name, type, flags
       7, QMetaType::SChar, 0x00495103,

 // properties: notify_signal_id
       0,

       0        // eod
};

void CharProducerSignal::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CharProducerSignal *_t = static_cast<CharProducerSignal *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< signed char(*)>(_a[1]))); break;
        case 1: _t->sendValue((*reinterpret_cast< signed char(*)>(_a[1]))); break;
        case 2: _t->setValue((*reinterpret_cast< signed char(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CharProducerSignal::*)(signed char );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CharProducerSignal::valueChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CharProducerSignal::*)(signed char );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CharProducerSignal::sendValue)) {
                *result = 1;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        CharProducerSignal *_t = static_cast<CharProducerSignal *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< signed char*>(_v) = _t->value(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        CharProducerSignal *_t = static_cast<CharProducerSignal *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setValue(*reinterpret_cast< signed char*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject CharProducerSignal::staticMetaObject = { {
    &DataEngineSignal::staticMetaObject,
    qt_meta_stringdata_CharProducerSignal.data,
    qt_meta_data_CharProducerSignal,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CharProducerSignal::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CharProducerSignal::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CharProducerSignal.stringdata0))
        return static_cast<void*>(this);
    return DataEngineSignal::qt_metacast(_clname);
}

int CharProducerSignal::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = DataEngineSignal::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void CharProducerSignal::valueChanged(signed char _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CharProducerSignal::sendValue(signed char _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
struct qt_meta_stringdata_UCharProducerSignal_t {
    QByteArrayData data[8];
    char stringdata0[65];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UCharProducerSignal_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UCharProducerSignal_t qt_meta_stringdata_UCharProducerSignal = {
    {
QT_MOC_LITERAL(0, 0, 19), // "UCharProducerSignal"
QT_MOC_LITERAL(1, 20, 12), // "valueChanged"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 3), // "arg"
QT_MOC_LITERAL(4, 38, 9), // "sendValue"
QT_MOC_LITERAL(5, 48, 8), // "setValue"
QT_MOC_LITERAL(6, 57, 1), // "v"
QT_MOC_LITERAL(7, 59, 5) // "value"

    },
    "UCharProducerSignal\0valueChanged\0\0arg\0"
    "sendValue\0setValue\0v\0value"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UCharProducerSignal[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       1,   38, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       4,    1,   32,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   35,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::UChar,    3,
    QMetaType::Void, QMetaType::UChar,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::UChar,    6,

 // properties: name, type, flags
       7, QMetaType::UChar, 0x00495103,

 // properties: notify_signal_id
       0,

       0        // eod
};

void UCharProducerSignal::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UCharProducerSignal *_t = static_cast<UCharProducerSignal *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< unsigned char(*)>(_a[1]))); break;
        case 1: _t->sendValue((*reinterpret_cast< unsigned char(*)>(_a[1]))); break;
        case 2: _t->setValue((*reinterpret_cast< unsigned char(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (UCharProducerSignal::*)(unsigned char );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UCharProducerSignal::valueChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (UCharProducerSignal::*)(unsigned char );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UCharProducerSignal::sendValue)) {
                *result = 1;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        UCharProducerSignal *_t = static_cast<UCharProducerSignal *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< unsigned char*>(_v) = _t->value(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        UCharProducerSignal *_t = static_cast<UCharProducerSignal *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setValue(*reinterpret_cast< unsigned char*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject UCharProducerSignal::staticMetaObject = { {
    &DataEngineSignal::staticMetaObject,
    qt_meta_stringdata_UCharProducerSignal.data,
    qt_meta_data_UCharProducerSignal,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *UCharProducerSignal::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UCharProducerSignal::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_UCharProducerSignal.stringdata0))
        return static_cast<void*>(this);
    return DataEngineSignal::qt_metacast(_clname);
}

int UCharProducerSignal::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = DataEngineSignal::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void UCharProducerSignal::valueChanged(unsigned char _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void UCharProducerSignal::sendValue(unsigned char _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
struct qt_meta_stringdata_BoolProducerSignal_t {
    QByteArrayData data[8];
    char stringdata0[64];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BoolProducerSignal_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BoolProducerSignal_t qt_meta_stringdata_BoolProducerSignal = {
    {
QT_MOC_LITERAL(0, 0, 18), // "BoolProducerSignal"
QT_MOC_LITERAL(1, 19, 12), // "valueChanged"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 3), // "arg"
QT_MOC_LITERAL(4, 37, 9), // "sendValue"
QT_MOC_LITERAL(5, 47, 8), // "setValue"
QT_MOC_LITERAL(6, 56, 1), // "v"
QT_MOC_LITERAL(7, 58, 5) // "value"

    },
    "BoolProducerSignal\0valueChanged\0\0arg\0"
    "sendValue\0setValue\0v\0value"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BoolProducerSignal[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       1,   38, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       4,    1,   32,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   35,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    6,

 // properties: name, type, flags
       7, QMetaType::Bool, 0x00495103,

 // properties: notify_signal_id
       0,

       0        // eod
};

void BoolProducerSignal::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BoolProducerSignal *_t = static_cast<BoolProducerSignal *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->sendValue((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->setValue((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (BoolProducerSignal::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BoolProducerSignal::valueChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (BoolProducerSignal::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BoolProducerSignal::sendValue)) {
                *result = 1;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        BoolProducerSignal *_t = static_cast<BoolProducerSignal *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->value(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        BoolProducerSignal *_t = static_cast<BoolProducerSignal *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setValue(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject BoolProducerSignal::staticMetaObject = { {
    &DataEngineSignal::staticMetaObject,
    qt_meta_stringdata_BoolProducerSignal.data,
    qt_meta_data_BoolProducerSignal,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *BoolProducerSignal::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BoolProducerSignal::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BoolProducerSignal.stringdata0))
        return static_cast<void*>(this);
    return DataEngineSignal::qt_metacast(_clname);
}

int BoolProducerSignal::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = DataEngineSignal::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void BoolProducerSignal::valueChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void BoolProducerSignal::sendValue(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
struct qt_meta_stringdata_FloatProducerSignal_t {
    QByteArrayData data[8];
    char stringdata0[65];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FloatProducerSignal_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FloatProducerSignal_t qt_meta_stringdata_FloatProducerSignal = {
    {
QT_MOC_LITERAL(0, 0, 19), // "FloatProducerSignal"
QT_MOC_LITERAL(1, 20, 12), // "valueChanged"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 3), // "arg"
QT_MOC_LITERAL(4, 38, 9), // "sendValue"
QT_MOC_LITERAL(5, 48, 8), // "setValue"
QT_MOC_LITERAL(6, 57, 1), // "v"
QT_MOC_LITERAL(7, 59, 5) // "value"

    },
    "FloatProducerSignal\0valueChanged\0\0arg\0"
    "sendValue\0setValue\0v\0value"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FloatProducerSignal[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       1,   38, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       4,    1,   32,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   35,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Float,    3,
    QMetaType::Void, QMetaType::Float,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Float,    6,

 // properties: name, type, flags
       7, QMetaType::Float, 0x00495103,

 // properties: notify_signal_id
       0,

       0        // eod
};

void FloatProducerSignal::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FloatProducerSignal *_t = static_cast<FloatProducerSignal *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 1: _t->sendValue((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 2: _t->setValue((*reinterpret_cast< float(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FloatProducerSignal::*)(float );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FloatProducerSignal::valueChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (FloatProducerSignal::*)(float );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FloatProducerSignal::sendValue)) {
                *result = 1;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        FloatProducerSignal *_t = static_cast<FloatProducerSignal *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< float*>(_v) = _t->value(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        FloatProducerSignal *_t = static_cast<FloatProducerSignal *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setValue(*reinterpret_cast< float*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject FloatProducerSignal::staticMetaObject = { {
    &DataEngineSignal::staticMetaObject,
    qt_meta_stringdata_FloatProducerSignal.data,
    qt_meta_data_FloatProducerSignal,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FloatProducerSignal::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FloatProducerSignal::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FloatProducerSignal.stringdata0))
        return static_cast<void*>(this);
    return DataEngineSignal::qt_metacast(_clname);
}

int FloatProducerSignal::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = DataEngineSignal::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void FloatProducerSignal::valueChanged(float _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FloatProducerSignal::sendValue(float _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
struct qt_meta_stringdata_QByteArrayProducerSignal_t {
    QByteArrayData data[8];
    char stringdata0[70];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QByteArrayProducerSignal_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QByteArrayProducerSignal_t qt_meta_stringdata_QByteArrayProducerSignal = {
    {
QT_MOC_LITERAL(0, 0, 24), // "QByteArrayProducerSignal"
QT_MOC_LITERAL(1, 25, 12), // "valueChanged"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 3), // "arg"
QT_MOC_LITERAL(4, 43, 9), // "sendValue"
QT_MOC_LITERAL(5, 53, 8), // "setValue"
QT_MOC_LITERAL(6, 62, 1), // "v"
QT_MOC_LITERAL(7, 64, 5) // "value"

    },
    "QByteArrayProducerSignal\0valueChanged\0"
    "\0arg\0sendValue\0setValue\0v\0value"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QByteArrayProducerSignal[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       1,   38, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       4,    1,   32,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   35,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray,    3,
    QMetaType::Void, QMetaType::QByteArray,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QByteArray,    6,

 // properties: name, type, flags
       7, QMetaType::QByteArray, 0x00495103,

 // properties: notify_signal_id
       0,

       0        // eod
};

void QByteArrayProducerSignal::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QByteArrayProducerSignal *_t = static_cast<QByteArrayProducerSignal *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 1: _t->sendValue((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 2: _t->setValue((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QByteArrayProducerSignal::*)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QByteArrayProducerSignal::valueChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (QByteArrayProducerSignal::*)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QByteArrayProducerSignal::sendValue)) {
                *result = 1;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        QByteArrayProducerSignal *_t = static_cast<QByteArrayProducerSignal *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QByteArray*>(_v) = _t->value(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        QByteArrayProducerSignal *_t = static_cast<QByteArrayProducerSignal *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setValue(*reinterpret_cast< QByteArray*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject QByteArrayProducerSignal::staticMetaObject = { {
    &DataEngineSignal::staticMetaObject,
    qt_meta_stringdata_QByteArrayProducerSignal.data,
    qt_meta_data_QByteArrayProducerSignal,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QByteArrayProducerSignal::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QByteArrayProducerSignal::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QByteArrayProducerSignal.stringdata0))
        return static_cast<void*>(this);
    return DataEngineSignal::qt_metacast(_clname);
}

int QByteArrayProducerSignal::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = DataEngineSignal::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void QByteArrayProducerSignal::valueChanged(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QByteArrayProducerSignal::sendValue(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
struct qt_meta_stringdata_QStringProducerSignal_t {
    QByteArrayData data[8];
    char stringdata0[67];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QStringProducerSignal_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QStringProducerSignal_t qt_meta_stringdata_QStringProducerSignal = {
    {
QT_MOC_LITERAL(0, 0, 21), // "QStringProducerSignal"
QT_MOC_LITERAL(1, 22, 12), // "valueChanged"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 3), // "arg"
QT_MOC_LITERAL(4, 40, 9), // "sendValue"
QT_MOC_LITERAL(5, 50, 8), // "setValue"
QT_MOC_LITERAL(6, 59, 1), // "v"
QT_MOC_LITERAL(7, 61, 5) // "value"

    },
    "QStringProducerSignal\0valueChanged\0\0"
    "arg\0sendValue\0setValue\0v\0value"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QStringProducerSignal[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       1,   38, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       4,    1,   32,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   35,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    6,

 // properties: name, type, flags
       7, QMetaType::QString, 0x00495103,

 // properties: notify_signal_id
       0,

       0        // eod
};

void QStringProducerSignal::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QStringProducerSignal *_t = static_cast<QStringProducerSignal *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->sendValue((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->setValue((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QStringProducerSignal::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QStringProducerSignal::valueChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (QStringProducerSignal::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QStringProducerSignal::sendValue)) {
                *result = 1;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        QStringProducerSignal *_t = static_cast<QStringProducerSignal *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->value(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        QStringProducerSignal *_t = static_cast<QStringProducerSignal *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setValue(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject QStringProducerSignal::staticMetaObject = { {
    &DataEngineSignal::staticMetaObject,
    qt_meta_stringdata_QStringProducerSignal.data,
    qt_meta_data_QStringProducerSignal,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QStringProducerSignal::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QStringProducerSignal::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QStringProducerSignal.stringdata0))
        return static_cast<void*>(this);
    return DataEngineSignal::qt_metacast(_clname);
}

int QStringProducerSignal::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = DataEngineSignal::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void QStringProducerSignal::valueChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QStringProducerSignal::sendValue(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

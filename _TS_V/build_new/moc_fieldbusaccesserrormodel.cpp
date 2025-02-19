/****************************************************************************
** Meta object code from reading C++ file 'fieldbusaccesserrormodel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../DataEngine/fieldbusaccesserrormodel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fieldbusaccesserrormodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FieldbusAccessErrorModel_t {
    QByteArrayData data[11];
    char stringdata0[128];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FieldbusAccessErrorModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FieldbusAccessErrorModel_t qt_meta_stringdata_FieldbusAccessErrorModel = {
    {
QT_MOC_LITERAL(0, 0, 24), // "FieldbusAccessErrorModel"
QT_MOC_LITERAL(1, 25, 10), // "errorAdded"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 20), // "FieldbusAccessError*"
QT_MOC_LITERAL(4, 58, 5), // "error"
QT_MOC_LITERAL(5, 64, 12), // "errorCleared"
QT_MOC_LITERAL(6, 77, 17), // "stackErrorChanged"
QT_MOC_LITERAL(7, 95, 5), // "exist"
QT_MOC_LITERAL(8, 101, 11), // "removeError"
QT_MOC_LITERAL(9, 113, 3), // "row"
QT_MOC_LITERAL(10, 117, 10) // "stackError"

    },
    "FieldbusAccessErrorModel\0errorAdded\0"
    "\0FieldbusAccessError*\0error\0errorCleared\0"
    "stackErrorChanged\0exist\0removeError\0"
    "row\0stackError"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FieldbusAccessErrorModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       1,   46, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       5,    1,   37,    2, 0x06 /* Public */,
       6,    1,   40,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
       8,    1,   43,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Bool,    7,

 // methods: parameters
    QMetaType::Void, QMetaType::Int,    9,

 // properties: name, type, flags
      10, QMetaType::Bool, 0x00495001,

 // properties: notify_signal_id
       2,

       0        // eod
};

void FieldbusAccessErrorModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FieldbusAccessErrorModel *_t = static_cast<FieldbusAccessErrorModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->errorAdded((*reinterpret_cast< FieldbusAccessError*(*)>(_a[1]))); break;
        case 1: _t->errorCleared((*reinterpret_cast< FieldbusAccessError*(*)>(_a[1]))); break;
        case 2: _t->stackErrorChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->removeError((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< FieldbusAccessError* >(); break;
            }
            break;
        case 1:
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
            using _t = void (FieldbusAccessErrorModel::*)(FieldbusAccessError * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FieldbusAccessErrorModel::errorAdded)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (FieldbusAccessErrorModel::*)(FieldbusAccessError * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FieldbusAccessErrorModel::errorCleared)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (FieldbusAccessErrorModel::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FieldbusAccessErrorModel::stackErrorChanged)) {
                *result = 2;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        FieldbusAccessErrorModel *_t = static_cast<FieldbusAccessErrorModel *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->stackError(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject FieldbusAccessErrorModel::staticMetaObject = { {
    &QAbstractTableModel::staticMetaObject,
    qt_meta_stringdata_FieldbusAccessErrorModel.data,
    qt_meta_data_FieldbusAccessErrorModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FieldbusAccessErrorModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FieldbusAccessErrorModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FieldbusAccessErrorModel.stringdata0))
        return static_cast<void*>(this);
    return QAbstractTableModel::qt_metacast(_clname);
}

int FieldbusAccessErrorModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractTableModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
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
void FieldbusAccessErrorModel::errorAdded(FieldbusAccessError * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FieldbusAccessErrorModel::errorCleared(FieldbusAccessError * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void FieldbusAccessErrorModel::stackErrorChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'ptosettings.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../backend/ptosettings.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ptosettings.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Flow_limit_acc_t {
    QByteArrayData data[8];
    char stringdata0[109];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Flow_limit_acc_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Flow_limit_acc_t qt_meta_stringdata_Flow_limit_acc = {
    {
QT_MOC_LITERAL(0, 0, 14), // "Flow_limit_acc"
QT_MOC_LITERAL(1, 15, 28), // "accessory_icon_sourceChanged"
QT_MOC_LITERAL(2, 44, 0), // ""
QT_MOC_LITERAL(3, 45, 21), // "accessory_icon_source"
QT_MOC_LITERAL(4, 67, 9), // "pto1_left"
QT_MOC_LITERAL(5, 77, 10), // "pto1_right"
QT_MOC_LITERAL(6, 88, 9), // "pto2_left"
QT_MOC_LITERAL(7, 98, 10) // "pto2_right"

    },
    "Flow_limit_acc\0accessory_icon_sourceChanged\0"
    "\0accessory_icon_source\0pto1_left\0"
    "pto1_right\0pto2_left\0pto2_right"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Flow_limit_acc[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       5,   22, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // properties: name, type, flags
       3, QMetaType::QString, 0x00495003,
       4, QMetaType::Int, 0x00095003,
       5, QMetaType::Int, 0x00095003,
       6, QMetaType::Int, 0x00095003,
       7, QMetaType::Int, 0x00095003,

 // properties: notify_signal_id
       0,
       0,
       0,
       0,
       0,

       0        // eod
};

void Flow_limit_acc::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Flow_limit_acc *_t = static_cast<Flow_limit_acc *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->accessory_icon_sourceChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Flow_limit_acc::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Flow_limit_acc::accessory_icon_sourceChanged)) {
                *result = 0;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        Flow_limit_acc *_t = static_cast<Flow_limit_acc *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->accessory_icon_source(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->pto1_left(); break;
        case 2: *reinterpret_cast< int*>(_v) = _t->pto1_right(); break;
        case 3: *reinterpret_cast< int*>(_v) = _t->pto2_left(); break;
        case 4: *reinterpret_cast< int*>(_v) = _t->pto2_right(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        Flow_limit_acc *_t = static_cast<Flow_limit_acc *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->set_accessory_icon_source(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->set_pto1_left(*reinterpret_cast< int*>(_v)); break;
        case 2: _t->set_pto1_right(*reinterpret_cast< int*>(_v)); break;
        case 3: _t->set_pto2_left(*reinterpret_cast< int*>(_v)); break;
        case 4: _t->set_pto2_right(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject Flow_limit_acc::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_Flow_limit_acc.data,
    qt_meta_data_Flow_limit_acc,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Flow_limit_acc::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Flow_limit_acc::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Flow_limit_acc.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Flow_limit_acc::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 5;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Flow_limit_acc::accessory_icon_sourceChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'preheating.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../backend/preheating.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'preheating.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Pre_heating_settings_t {
    QByteArrayData data[7];
    char stringdata0[75];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Pre_heating_settings_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Pre_heating_settings_t qt_meta_stringdata_Pre_heating_settings = {
    {
QT_MOC_LITERAL(0, 0, 20), // "Pre_heating_settings"
QT_MOC_LITERAL(1, 21, 13), // "activeChanged"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 6), // "active"
QT_MOC_LITERAL(4, 43, 13), // "start_minutes"
QT_MOC_LITERAL(5, 57, 11), // "start_hours"
QT_MOC_LITERAL(6, 69, 5) // "am_pm"

    },
    "Pre_heating_settings\0activeChanged\0\0"
    "active\0start_minutes\0start_hours\0am_pm"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Pre_heating_settings[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       4,   22, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,

 // properties: name, type, flags
       4, QMetaType::Int, 0x00095003,
       5, QMetaType::Int, 0x00095003,
       6, QMetaType::QString, 0x00095003,
       3, QMetaType::Bool, 0x00495003,

 // properties: notify_signal_id
       0,
       0,
       0,
       0,

       0        // eod
};

void Pre_heating_settings::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Pre_heating_settings *_t = static_cast<Pre_heating_settings *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->activeChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Pre_heating_settings::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Pre_heating_settings::activeChanged)) {
                *result = 0;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        Pre_heating_settings *_t = static_cast<Pre_heating_settings *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->start_minutes(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->start_hours(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->am_pm(); break;
        case 3: *reinterpret_cast< bool*>(_v) = _t->active(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        Pre_heating_settings *_t = static_cast<Pre_heating_settings *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->set_start_minutes(*reinterpret_cast< int*>(_v)); break;
        case 1: _t->set_start_hours(*reinterpret_cast< int*>(_v)); break;
        case 2: _t->set_am_pm(*reinterpret_cast< QString*>(_v)); break;
        case 3: _t->set_active(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject Pre_heating_settings::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_Pre_heating_settings.data,
    qt_meta_data_Pre_heating_settings,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Pre_heating_settings::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Pre_heating_settings::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Pre_heating_settings.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Pre_heating_settings::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void Pre_heating_settings::activeChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

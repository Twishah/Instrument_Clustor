/****************************************************************************
** Meta object code from reading C++ file 'BackLightHandler.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../CCAux/BackLightHandler.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BackLightHandler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BackLightHandler_t {
    QByteArrayData data[14];
    char stringdata0[280];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BackLightHandler_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BackLightHandler_t qt_meta_stringdata_BackLightHandler = {
    {
QT_MOC_LITERAL(0, 0, 16), // "BackLightHandler"
QT_MOC_LITERAL(1, 17, 28), // "currentBacklightValueChanged"
QT_MOC_LITERAL(2, 46, 0), // ""
QT_MOC_LITERAL(3, 47, 30), // "currentLightSensorValueChanged"
QT_MOC_LITERAL(4, 78, 26), // "maxLightSensorValueChanged"
QT_MOC_LITERAL(5, 105, 21), // "hasLightSensorChanged"
QT_MOC_LITERAL(6, 127, 29), // "lightSensorDetectTimerTimeout"
QT_MOC_LITERAL(7, 157, 17), // "increaseBacklight"
QT_MOC_LITERAL(8, 175, 5), // "value"
QT_MOC_LITERAL(9, 181, 17), // "decreaseBacklight"
QT_MOC_LITERAL(10, 199, 21), // "currentBacklightValue"
QT_MOC_LITERAL(11, 221, 23), // "currentLightSensorValue"
QT_MOC_LITERAL(12, 245, 19), // "maxLightSensorValue"
QT_MOC_LITERAL(13, 265, 14) // "hasLightSensor"

    },
    "BackLightHandler\0currentBacklightValueChanged\0"
    "\0currentLightSensorValueChanged\0"
    "maxLightSensorValueChanged\0"
    "hasLightSensorChanged\0"
    "lightSensorDetectTimerTimeout\0"
    "increaseBacklight\0value\0decreaseBacklight\0"
    "currentBacklightValue\0currentLightSensorValue\0"
    "maxLightSensorValue\0hasLightSensor"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BackLightHandler[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       4,   60, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    0,   50,    2, 0x06 /* Public */,
       4,    0,   51,    2, 0x06 /* Public */,
       5,    0,   52,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   53,    2, 0x08 /* Private */,

 // methods: name, argc, parameters, tag, flags
       7,    1,   54,    2, 0x02 /* Public */,
       9,    1,   57,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,

 // properties: name, type, flags
      10, QMetaType::Int, 0x00495103,
      11, QMetaType::Int, 0x00495001,
      12, QMetaType::Int, 0x00495001,
      13, QMetaType::Int, 0x00495001,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,

       0        // eod
};

void BackLightHandler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BackLightHandler *_t = static_cast<BackLightHandler *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->currentBacklightValueChanged(); break;
        case 1: _t->currentLightSensorValueChanged(); break;
        case 2: _t->maxLightSensorValueChanged(); break;
        case 3: _t->hasLightSensorChanged(); break;
        case 4: _t->lightSensorDetectTimerTimeout(); break;
        case 5: _t->increaseBacklight((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->decreaseBacklight((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (BackLightHandler::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BackLightHandler::currentBacklightValueChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (BackLightHandler::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BackLightHandler::currentLightSensorValueChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (BackLightHandler::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BackLightHandler::maxLightSensorValueChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (BackLightHandler::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BackLightHandler::hasLightSensorChanged)) {
                *result = 3;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        BackLightHandler *_t = static_cast<BackLightHandler *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->currentBacklightValue(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->currentLightSensorValue(); break;
        case 2: *reinterpret_cast< int*>(_v) = _t->maxLightSensorValue(); break;
        case 3: *reinterpret_cast< int*>(_v) = _t->hasLightSensor(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        BackLightHandler *_t = static_cast<BackLightHandler *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setCurrentBacklightValue(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject BackLightHandler::staticMetaObject = { {
    &CCAuxHandlerBase::staticMetaObject,
    qt_meta_stringdata_BackLightHandler.data,
    qt_meta_data_BackLightHandler,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *BackLightHandler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BackLightHandler::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BackLightHandler.stringdata0))
        return static_cast<void*>(this);
    return CCAuxHandlerBase::qt_metacast(_clname);
}

int BackLightHandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = CCAuxHandlerBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
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
void BackLightHandler::currentBacklightValueChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void BackLightHandler::currentLightSensorValueChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void BackLightHandler::maxLightSensorValueChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void BackLightHandler::hasLightSensorChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

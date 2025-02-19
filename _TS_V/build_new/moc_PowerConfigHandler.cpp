/****************************************************************************
** Meta object code from reading C++ file 'PowerConfigHandler.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../CCAux/PowerConfigHandler.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PowerConfigHandler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PowerConfigHandler_t {
    QByteArrayData data[10];
    char stringdata0[190];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PowerConfigHandler_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PowerConfigHandler_t qt_meta_stringdata_PowerConfigHandler = {
    {
QT_MOC_LITERAL(0, 0, 18), // "PowerConfigHandler"
QT_MOC_LITERAL(1, 19, 27), // "startupTriggerConfigChanged"
QT_MOC_LITERAL(2, 47, 0), // ""
QT_MOC_LITERAL(3, 48, 26), // "extOnOffSigTrigTimeChanged"
QT_MOC_LITERAL(4, 75, 21), // "onOffSigActionChanged"
QT_MOC_LITERAL(5, 97, 21), // "suspendMaxTimeChanged"
QT_MOC_LITERAL(6, 119, 20), // "startupTriggerConfig"
QT_MOC_LITERAL(7, 140, 19), // "extOnOffSigTrigTime"
QT_MOC_LITERAL(8, 160, 14), // "onOffSigAction"
QT_MOC_LITERAL(9, 175, 14) // "suspendMaxTime"

    },
    "PowerConfigHandler\0startupTriggerConfigChanged\0"
    "\0extOnOffSigTrigTimeChanged\0"
    "onOffSigActionChanged\0suspendMaxTimeChanged\0"
    "startupTriggerConfig\0extOnOffSigTrigTime\0"
    "onOffSigAction\0suspendMaxTime"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PowerConfigHandler[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       4,   38, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    0,   35,    2, 0x06 /* Public */,
       4,    0,   36,    2, 0x06 /* Public */,
       5,    0,   37,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
       6, QMetaType::QString, 0x00495103,
       7, QMetaType::UInt, 0x00495103,
       8, QMetaType::QString, 0x00495103,
       9, QMetaType::UShort, 0x00495103,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,

       0        // eod
};

void PowerConfigHandler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PowerConfigHandler *_t = static_cast<PowerConfigHandler *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->startupTriggerConfigChanged(); break;
        case 1: _t->extOnOffSigTrigTimeChanged(); break;
        case 2: _t->onOffSigActionChanged(); break;
        case 3: _t->suspendMaxTimeChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PowerConfigHandler::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowerConfigHandler::startupTriggerConfigChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (PowerConfigHandler::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowerConfigHandler::extOnOffSigTrigTimeChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (PowerConfigHandler::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowerConfigHandler::onOffSigActionChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (PowerConfigHandler::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowerConfigHandler::suspendMaxTimeChanged)) {
                *result = 3;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        PowerConfigHandler *_t = static_cast<PowerConfigHandler *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->startupTriggerConfig(); break;
        case 1: *reinterpret_cast< uint*>(_v) = _t->extOnOffSigTrigTime(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->onOffSigAction(); break;
        case 3: *reinterpret_cast< unsigned short*>(_v) = _t->suspendMaxTime(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        PowerConfigHandler *_t = static_cast<PowerConfigHandler *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setStartupTriggerConfig(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setExtOnOffSigTrigTime(*reinterpret_cast< uint*>(_v)); break;
        case 2: _t->setOnOffSigAction(*reinterpret_cast< QString*>(_v)); break;
        case 3: _t->setSuspendMaxTime(*reinterpret_cast< unsigned short*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject PowerConfigHandler::staticMetaObject = { {
    &CCAuxHandlerBase::staticMetaObject,
    qt_meta_stringdata_PowerConfigHandler.data,
    qt_meta_data_PowerConfigHandler,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *PowerConfigHandler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PowerConfigHandler::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PowerConfigHandler.stringdata0))
        return static_cast<void*>(this);
    return CCAuxHandlerBase::qt_metacast(_clname);
}

int PowerConfigHandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = CCAuxHandlerBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
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
void PowerConfigHandler::startupTriggerConfigChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void PowerConfigHandler::extOnOffSigTrigTimeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void PowerConfigHandler::onOffSigActionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void PowerConfigHandler::suspendMaxTimeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

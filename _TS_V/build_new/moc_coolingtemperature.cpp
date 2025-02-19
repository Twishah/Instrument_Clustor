/****************************************************************************
** Meta object code from reading C++ file 'coolingtemperature.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../backend/coolingtemperature.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'coolingtemperature.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CoolingTemperature_t {
    QByteArrayData data[7];
    char stringdata0[143];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CoolingTemperature_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CoolingTemperature_t qt_meta_stringdata_CoolingTemperature = {
    {
QT_MOC_LITERAL(0, 0, 18), // "CoolingTemperature"
QT_MOC_LITERAL(1, 19, 28), // "coolingTempCelsiusCppChanged"
QT_MOC_LITERAL(2, 48, 0), // ""
QT_MOC_LITERAL(3, 49, 21), // "coolingTempCelsiusCpp"
QT_MOC_LITERAL(4, 71, 31), // "coolingTempFahrenheitCppChanged"
QT_MOC_LITERAL(5, 103, 24), // "coolingTempFahrenheitCpp"
QT_MOC_LITERAL(6, 128, 14) // "coolingTempMCU"

    },
    "CoolingTemperature\0coolingTempCelsiusCppChanged\0"
    "\0coolingTempCelsiusCpp\0"
    "coolingTempFahrenheitCppChanged\0"
    "coolingTempFahrenheitCpp\0coolingTempMCU"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CoolingTemperature[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       3,   30, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,
       4,    1,   27,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,

 // properties: name, type, flags
       6, QMetaType::Int, 0x00095103,
       3, QMetaType::QString, 0x00495103,
       5, QMetaType::QString, 0x00495103,

 // properties: notify_signal_id
       0,
       0,
       1,

       0        // eod
};

void CoolingTemperature::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CoolingTemperature *_t = static_cast<CoolingTemperature *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->coolingTempCelsiusCppChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->coolingTempFahrenheitCppChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CoolingTemperature::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CoolingTemperature::coolingTempCelsiusCppChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CoolingTemperature::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CoolingTemperature::coolingTempFahrenheitCppChanged)) {
                *result = 1;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        CoolingTemperature *_t = static_cast<CoolingTemperature *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->getCoolingTempMCU(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->getCoolingTempCelsiusCpp(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->getCoolingTempFahrenheitCpp(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        CoolingTemperature *_t = static_cast<CoolingTemperature *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setCoolingTempMCU(*reinterpret_cast< int*>(_v)); break;
        case 1: _t->setCoolingTempCelsiusCpp(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setCoolingTempFahrenheitCpp(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject CoolingTemperature::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_CoolingTemperature.data,
    qt_meta_data_CoolingTemperature,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CoolingTemperature::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CoolingTemperature::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CoolingTemperature.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CoolingTemperature::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void CoolingTemperature::coolingTempCelsiusCppChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CoolingTemperature::coolingTempFahrenheitCppChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

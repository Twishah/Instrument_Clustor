/****************************************************************************
** Meta object code from reading C++ file 'remainingtime.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../backend/remainingtime.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'remainingtime.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RemainingTime_t {
    QByteArrayData data[14];
    char stringdata0[145];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RemainingTime_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RemainingTime_t qt_meta_stringdata_RemainingTime = {
    {
QT_MOC_LITERAL(0, 0, 13), // "RemainingTime"
QT_MOC_LITERAL(1, 14, 23), // "remainingTimeCppChanged"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 16), // "remainingTimeCpp"
QT_MOC_LITERAL(4, 56, 23), // "percentageSOCChangedCpp"
QT_MOC_LITERAL(5, 80, 16), // "percentageSOCCpp"
QT_MOC_LITERAL(6, 97, 8), // "rtResult"
QT_MOC_LITERAL(7, 106, 4), // "hour"
QT_MOC_LITERAL(8, 111, 4), // "min1"
QT_MOC_LITERAL(9, 116, 4), // "min0"
QT_MOC_LITERAL(10, 121, 5), // "rate2"
QT_MOC_LITERAL(11, 127, 5), // "rate1"
QT_MOC_LITERAL(12, 133, 5), // "rate0"
QT_MOC_LITERAL(13, 139, 5) // "rtMCU"

    },
    "RemainingTime\0remainingTimeCppChanged\0"
    "\0remainingTimeCpp\0percentageSOCChangedCpp\0"
    "percentageSOCCpp\0rtResult\0hour\0min1\0"
    "min0\0rate2\0rate1\0rate0\0rtMCU"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RemainingTime[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       3,   48, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       4,    1,   32,    2, 0x06 /* Public */,
       6,    6,   35,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    7,    8,    9,   10,   11,   12,

 // properties: name, type, flags
      13, QMetaType::Float, 0x00095103,
       3, QMetaType::QString, 0x00495103,
       5, QMetaType::QString, 0x00495103,

 // properties: notify_signal_id
       0,
       0,
       1,

       0        // eod
};

void RemainingTime::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RemainingTime *_t = static_cast<RemainingTime *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->remainingTimeCppChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->percentageSOCChangedCpp((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->rtResult((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (RemainingTime::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RemainingTime::remainingTimeCppChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (RemainingTime::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RemainingTime::percentageSOCChangedCpp)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (RemainingTime::*)(QString , QString , QString , QString , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RemainingTime::rtResult)) {
                *result = 2;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        RemainingTime *_t = static_cast<RemainingTime *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< float*>(_v) = _t->getRtMCU(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->getRemainingTimeCpp(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->getPercentageSOCCpp(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        RemainingTime *_t = static_cast<RemainingTime *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setRtMCU(*reinterpret_cast< float*>(_v)); break;
        case 1: _t->setRemainingTimeCpp(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setPercentageSOCCpp(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject RemainingTime::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_RemainingTime.data,
    qt_meta_data_RemainingTime,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *RemainingTime::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RemainingTime::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RemainingTime.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int RemainingTime::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void RemainingTime::remainingTimeCppChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void RemainingTime::percentageSOCChangedCpp(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void RemainingTime::rtResult(QString _t1, QString _t2, QString _t3, QString _t4, QString _t5, QString _t6)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'backend.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../backend/backend.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'backend.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BackEnd_t {
    QByteArrayData data[32];
    char stringdata0[472];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BackEnd_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BackEnd_t qt_meta_stringdata_BackEnd = {
    {
QT_MOC_LITERAL(0, 0, 7), // "BackEnd"
QT_MOC_LITERAL(1, 8, 12), // "stateChanged"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 5), // "state"
QT_MOC_LITERAL(4, 28, 18), // "currentPageChanged"
QT_MOC_LITERAL(5, 47, 11), // "currentPage"
QT_MOC_LITERAL(6, 59, 17), // "ipAddress1Changed"
QT_MOC_LITERAL(7, 77, 17), // "ipAddress2Changed"
QT_MOC_LITERAL(8, 95, 18), // "displayNameChanged"
QT_MOC_LITERAL(9, 114, 26), // "hardwareButtonStateChanged"
QT_MOC_LITERAL(10, 141, 8), // "buttonNo"
QT_MOC_LITERAL(11, 150, 13), // "buttonPressed"
QT_MOC_LITERAL(12, 164, 22), // "mechanicMode1Activated"
QT_MOC_LITERAL(13, 187, 22), // "mechanicMode2Activated"
QT_MOC_LITERAL(14, 210, 8), // "setState"
QT_MOC_LITERAL(15, 219, 14), // "setCurrentPage"
QT_MOC_LITERAL(16, 234, 14), // "ipTimerTimeout"
QT_MOC_LITERAL(17, 249, 19), // "updateHwButtonState"
QT_MOC_LITERAL(18, 269, 21), // "changeToMechanicMode1"
QT_MOC_LITERAL(19, 291, 21), // "changeToMechanicMode2"
QT_MOC_LITERAL(20, 313, 14), // "verifyAppState"
QT_MOC_LITERAL(21, 328, 17), // "getSK1SK2combined"
QT_MOC_LITERAL(22, 346, 17), // "getSK1SK3combined"
QT_MOC_LITERAL(23, 364, 12), // "getAccsignal"
QT_MOC_LITERAL(24, 377, 11), // "menuPressed"
QT_MOC_LITERAL(25, 389, 9), // "upPressed"
QT_MOC_LITERAL(26, 399, 11), // "downPressed"
QT_MOC_LITERAL(27, 411, 12), // "enterPressed"
QT_MOC_LITERAL(28, 424, 10), // "ipAddress1"
QT_MOC_LITERAL(29, 435, 10), // "ipAddress2"
QT_MOC_LITERAL(30, 446, 11), // "displayName"
QT_MOC_LITERAL(31, 458, 13) // "currentConfig"

    },
    "BackEnd\0stateChanged\0\0state\0"
    "currentPageChanged\0currentPage\0"
    "ipAddress1Changed\0ipAddress2Changed\0"
    "displayNameChanged\0hardwareButtonStateChanged\0"
    "buttonNo\0buttonPressed\0mechanicMode1Activated\0"
    "mechanicMode2Activated\0setState\0"
    "setCurrentPage\0ipTimerTimeout\0"
    "updateHwButtonState\0changeToMechanicMode1\0"
    "changeToMechanicMode2\0verifyAppState\0"
    "getSK1SK2combined\0getSK1SK3combined\0"
    "getAccsignal\0menuPressed\0upPressed\0"
    "downPressed\0enterPressed\0ipAddress1\0"
    "ipAddress2\0displayName\0currentConfig"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BackEnd[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      22,   14, // methods
       6,  162, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  124,    2, 0x06 /* Public */,
       4,    1,  127,    2, 0x06 /* Public */,
       6,    0,  130,    2, 0x06 /* Public */,
       7,    0,  131,    2, 0x06 /* Public */,
       8,    0,  132,    2, 0x06 /* Public */,
       9,    2,  133,    2, 0x06 /* Public */,
      12,    0,  138,    2, 0x06 /* Public */,
      13,    0,  139,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      14,    1,  140,    2, 0x0a /* Public */,
      15,    1,  143,    2, 0x0a /* Public */,
      16,    0,  146,    2, 0x08 /* Private */,
      17,    2,  147,    2, 0x08 /* Private */,
      18,    0,  152,    2, 0x08 /* Private */,
      19,    0,  153,    2, 0x08 /* Private */,
      20,    0,  154,    2, 0x08 /* Private */,

 // methods: name, argc, parameters, tag, flags
      21,    0,  155,    2, 0x02 /* Public */,
      22,    0,  156,    2, 0x02 /* Public */,
      23,    0,  157,    2, 0x02 /* Public */,
      24,    0,  158,    2, 0x02 /* Public */,
      25,    0,  159,    2, 0x02 /* Public */,
      26,    0,  160,    2, 0x02 /* Public */,
      27,    0,  161,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QObjectStar,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   10,   11,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QObjectStar,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   10,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
       3, QMetaType::Int, 0x00495103,
       5, QMetaType::QObjectStar, 0x00495103,
      28, QMetaType::QString, 0x00495001,
      29, QMetaType::QString, 0x00495001,
      30, QMetaType::QString, 0x00495001,
      31, QMetaType::QObjectStar, 0x00095401,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,
       4,
       0,

       0        // eod
};

void BackEnd::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BackEnd *_t = static_cast<BackEnd *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->currentPageChanged((*reinterpret_cast< QObject*(*)>(_a[1]))); break;
        case 2: _t->ipAddress1Changed(); break;
        case 3: _t->ipAddress2Changed(); break;
        case 4: _t->displayNameChanged(); break;
        case 5: _t->hardwareButtonStateChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->mechanicMode1Activated(); break;
        case 7: _t->mechanicMode2Activated(); break;
        case 8: _t->setState((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->setCurrentPage((*reinterpret_cast< QObject*(*)>(_a[1]))); break;
        case 10: _t->ipTimerTimeout(); break;
        case 11: _t->updateHwButtonState((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 12: _t->changeToMechanicMode1(); break;
        case 13: _t->changeToMechanicMode2(); break;
        case 14: _t->verifyAppState(); break;
        case 15: { bool _r = _t->getSK1SK2combined();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 16: { bool _r = _t->getSK1SK3combined();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 17: { bool _r = _t->getAccsignal();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 18: _t->menuPressed(); break;
        case 19: _t->upPressed(); break;
        case 20: _t->downPressed(); break;
        case 21: _t->enterPressed(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (BackEnd::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BackEnd::stateChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (BackEnd::*)(QObject * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BackEnd::currentPageChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (BackEnd::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BackEnd::ipAddress1Changed)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (BackEnd::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BackEnd::ipAddress2Changed)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (BackEnd::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BackEnd::displayNameChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (BackEnd::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BackEnd::hardwareButtonStateChanged)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (BackEnd::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BackEnd::mechanicMode1Activated)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (BackEnd::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BackEnd::mechanicMode2Activated)) {
                *result = 7;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        BackEnd *_t = static_cast<BackEnd *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->state(); break;
        case 1: *reinterpret_cast< QObject**>(_v) = _t->currentPage(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->ipAddress1(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->ipAddress2(); break;
        case 4: *reinterpret_cast< QString*>(_v) = _t->displayName(); break;
        case 5: *reinterpret_cast< QObject**>(_v) = _t->currentConfig(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        BackEnd *_t = static_cast<BackEnd *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setState(*reinterpret_cast< int*>(_v)); break;
        case 1: _t->setCurrentPage(*reinterpret_cast< QObject**>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject BackEnd::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_BackEnd.data,
    qt_meta_data_BackEnd,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *BackEnd::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BackEnd::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BackEnd.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int BackEnd::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 22)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 22;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 22)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 22;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 6;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void BackEnd::stateChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void BackEnd::currentPageChanged(QObject * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void BackEnd::ipAddress1Changed()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void BackEnd::ipAddress2Changed()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void BackEnd::displayNameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void BackEnd::hardwareButtonStateChanged(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void BackEnd::mechanicMode1Activated()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void BackEnd::mechanicMode2Activated()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

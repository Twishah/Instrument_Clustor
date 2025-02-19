/****************************************************************************
** Meta object code from reading C++ file 'BuzzerHandler.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../CCAux/BuzzerHandler.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BuzzerHandler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BuzzerHandler_t {
    QByteArrayData data[27];
    char stringdata0[199];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BuzzerHandler_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BuzzerHandler_t qt_meta_stringdata_BuzzerHandler = {
    {
QT_MOC_LITERAL(0, 0, 13), // "BuzzerHandler"
QT_MOC_LITERAL(1, 14, 13), // "volumeChanged"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 17), // "toneLengthChanged"
QT_MOC_LITERAL(4, 47, 16), // "frequencyChanged"
QT_MOC_LITERAL(5, 64, 19), // "blockingModeChanged"
QT_MOC_LITERAL(6, 84, 14), // "triggerChanged"
QT_MOC_LITERAL(7, 99, 8), // "playTone"
QT_MOC_LITERAL(8, 108, 9), // "frequency"
QT_MOC_LITERAL(9, 118, 7), // "setFreq"
QT_MOC_LITERAL(10, 126, 6), // "volume"
QT_MOC_LITERAL(11, 133, 10), // "toneLength"
QT_MOC_LITERAL(12, 144, 12), // "blockingMode"
QT_MOC_LITERAL(13, 157, 7), // "trigger"
QT_MOC_LITERAL(14, 165, 4), // "Tone"
QT_MOC_LITERAL(15, 170, 1), // "C"
QT_MOC_LITERAL(16, 172, 2), // "CS"
QT_MOC_LITERAL(17, 175, 1), // "D"
QT_MOC_LITERAL(18, 177, 2), // "DS"
QT_MOC_LITERAL(19, 180, 1), // "E"
QT_MOC_LITERAL(20, 182, 1), // "F"
QT_MOC_LITERAL(21, 184, 2), // "FS"
QT_MOC_LITERAL(22, 187, 1), // "G"
QT_MOC_LITERAL(23, 189, 2), // "GS"
QT_MOC_LITERAL(24, 192, 1), // "A"
QT_MOC_LITERAL(25, 194, 2), // "AS"
QT_MOC_LITERAL(26, 197, 1) // "B"

    },
    "BuzzerHandler\0volumeChanged\0\0"
    "toneLengthChanged\0frequencyChanged\0"
    "blockingModeChanged\0triggerChanged\0"
    "playTone\0frequency\0setFreq\0volume\0"
    "toneLength\0blockingMode\0trigger\0Tone\0"
    "C\0CS\0D\0DS\0E\0F\0FS\0G\0GS\0A\0AS\0B"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BuzzerHandler[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       5,   60, // properties
       1,   80, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    0,   50,    2, 0x06 /* Public */,
       4,    0,   51,    2, 0x06 /* Public */,
       5,    0,   52,    2, 0x06 /* Public */,
       6,    0,   53,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
       7,    1,   54,    2, 0x02 /* Public */,
       9,    1,   57,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void, QMetaType::UShort,    8,
    QMetaType::Void, QMetaType::UShort,    8,

 // properties: name, type, flags
      10, QMetaType::Int, 0x00495103,
      11, QMetaType::Int, 0x00495103,
       8, QMetaType::Int, 0x00495001,
      12, QMetaType::Bool, 0x00495103,
      13, QMetaType::Bool, 0x00495103,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,
       4,

 // enums: name, alias, flags, count, data
      14,   14, 0x0,   12,   85,

 // enum data: key, value
      15, uint(BuzzerHandler::C),
      16, uint(BuzzerHandler::CS),
      17, uint(BuzzerHandler::D),
      18, uint(BuzzerHandler::DS),
      19, uint(BuzzerHandler::E),
      20, uint(BuzzerHandler::F),
      21, uint(BuzzerHandler::FS),
      22, uint(BuzzerHandler::G),
      23, uint(BuzzerHandler::GS),
      24, uint(BuzzerHandler::A),
      25, uint(BuzzerHandler::AS),
      26, uint(BuzzerHandler::B),

       0        // eod
};

void BuzzerHandler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BuzzerHandler *_t = static_cast<BuzzerHandler *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->volumeChanged(); break;
        case 1: _t->toneLengthChanged(); break;
        case 2: _t->frequencyChanged(); break;
        case 3: _t->blockingModeChanged(); break;
        case 4: _t->triggerChanged(); break;
        case 5: _t->playTone((*reinterpret_cast< quint16(*)>(_a[1]))); break;
        case 6: _t->setFreq((*reinterpret_cast< quint16(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (BuzzerHandler::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BuzzerHandler::volumeChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (BuzzerHandler::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BuzzerHandler::toneLengthChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (BuzzerHandler::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BuzzerHandler::frequencyChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (BuzzerHandler::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BuzzerHandler::blockingModeChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (BuzzerHandler::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BuzzerHandler::triggerChanged)) {
                *result = 4;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        BuzzerHandler *_t = static_cast<BuzzerHandler *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->volume(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->toneLength(); break;
        case 2: *reinterpret_cast< int*>(_v) = _t->frequency(); break;
        case 3: *reinterpret_cast< bool*>(_v) = _t->blockingMode(); break;
        case 4: *reinterpret_cast< bool*>(_v) = _t->trigger(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        BuzzerHandler *_t = static_cast<BuzzerHandler *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setVolume(*reinterpret_cast< int*>(_v)); break;
        case 1: _t->setToneLength(*reinterpret_cast< int*>(_v)); break;
        case 3: _t->setBlockingMode(*reinterpret_cast< bool*>(_v)); break;
        case 4: _t->setTrigger(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject BuzzerHandler::staticMetaObject = { {
    &CCAuxHandlerBase::staticMetaObject,
    qt_meta_stringdata_BuzzerHandler.data,
    qt_meta_data_BuzzerHandler,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *BuzzerHandler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BuzzerHandler::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BuzzerHandler.stringdata0))
        return static_cast<void*>(this);
    return CCAuxHandlerBase::qt_metacast(_clname);
}

int BuzzerHandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void BuzzerHandler::volumeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void BuzzerHandler::toneLengthChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void BuzzerHandler::frequencyChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void BuzzerHandler::blockingModeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void BuzzerHandler::triggerChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

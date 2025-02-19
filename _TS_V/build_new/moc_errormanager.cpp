/****************************************************************************
** Meta object code from reading C++ file 'errormanager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../backend/errormanager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'errormanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ErrorManager_t {
    QByteArrayData data[27];
    char stringdata0[409];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ErrorManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ErrorManager_t qt_meta_stringdata_ErrorManager = {
    {
QT_MOC_LITERAL(0, 0, 12), // "ErrorManager"
QT_MOC_LITERAL(1, 13, 11), // "newErrorPop"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 8), // "newError"
QT_MOC_LITERAL(4, 35, 25), // "currentErrorLenghtChanged"
QT_MOC_LITERAL(5, 61, 25), // "historyErrorLenghtChanged"
QT_MOC_LITERAL(6, 87, 15), // "socAlertChanged"
QT_MOC_LITERAL(7, 103, 8), // "addError"
QT_MOC_LITERAL(8, 112, 9), // "errorCode"
QT_MOC_LITERAL(9, 122, 14), // "hourMeterValue"
QT_MOC_LITERAL(10, 137, 17), // "getCurrentErrorAt"
QT_MOC_LITERAL(11, 155, 5), // "index"
QT_MOC_LITERAL(12, 161, 17), // "getHistoryErrorAt"
QT_MOC_LITERAL(13, 179, 21), // "getCurrentErrorLength"
QT_MOC_LITERAL(14, 201, 21), // "getHistoryErrorLength"
QT_MOC_LITERAL(15, 223, 21), // "getOnCurrentErrorPage"
QT_MOC_LITERAL(16, 245, 21), // "setOnCurrentErrorPage"
QT_MOC_LITERAL(17, 267, 5), // "value"
QT_MOC_LITERAL(18, 273, 11), // "setSocAlert"
QT_MOC_LITERAL(19, 285, 16), // "getBuzzerPattern"
QT_MOC_LITERAL(20, 302, 21), // "setBuzzerIsInCoolDown"
QT_MOC_LITERAL(21, 324, 4), // "code"
QT_MOC_LITERAL(22, 329, 19), // "startBuzzerCooldown"
QT_MOC_LITERAL(23, 349, 12), // "setBeepsDone"
QT_MOC_LITERAL(24, 362, 18), // "currentErrorLenght"
QT_MOC_LITERAL(25, 381, 18), // "onCurrentErrorPage"
QT_MOC_LITERAL(26, 400, 8) // "socAlert"

    },
    "ErrorManager\0newErrorPop\0\0newError\0"
    "currentErrorLenghtChanged\0"
    "historyErrorLenghtChanged\0socAlertChanged\0"
    "addError\0errorCode\0hourMeterValue\0"
    "getCurrentErrorAt\0index\0getHistoryErrorAt\0"
    "getCurrentErrorLength\0getHistoryErrorLength\0"
    "getOnCurrentErrorPage\0setOnCurrentErrorPage\0"
    "value\0setSocAlert\0getBuzzerPattern\0"
    "setBuzzerIsInCoolDown\0code\0"
    "startBuzzerCooldown\0setBeepsDone\0"
    "currentErrorLenght\0onCurrentErrorPage\0"
    "socAlert"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ErrorManager[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       3,  134, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   94,    2, 0x06 /* Public */,
       4,    0,   97,    2, 0x06 /* Public */,
       5,    0,   98,    2, 0x06 /* Public */,
       6,    0,   99,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
       7,    2,  100,    2, 0x02 /* Public */,
      10,    1,  105,    2, 0x02 /* Public */,
      12,    1,  108,    2, 0x02 /* Public */,
      13,    0,  111,    2, 0x02 /* Public */,
      14,    0,  112,    2, 0x02 /* Public */,
      15,    0,  113,    2, 0x02 /* Public */,
      16,    1,  114,    2, 0x02 /* Public */,
      18,    1,  117,    2, 0x02 /* Public */,
      19,    0,  120,    2, 0x02 /* Public */,
      20,    2,  121,    2, 0x02 /* Public */,
      22,    1,  126,    2, 0x02 /* Public */,
      23,    2,  129,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QVariantMap,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    8,    9,
    QMetaType::QVariantMap, QMetaType::Int,   11,
    QMetaType::QVariantMap, QMetaType::Int,   11,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::Bool,   17,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::QVariantMap,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,   21,   17,
    QMetaType::Void, QMetaType::QString,   21,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,   21,   17,

 // properties: name, type, flags
      24, QMetaType::Int, 0x00095000,
      25, QMetaType::Bool, 0x00095103,
      26, QMetaType::Int, 0x00095102,

 // properties: notify_signal_id
       0,
       0,
       0,

       0        // eod
};

void ErrorManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ErrorManager *_t = static_cast<ErrorManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newErrorPop((*reinterpret_cast< QVariantMap(*)>(_a[1]))); break;
        case 1: _t->currentErrorLenghtChanged(); break;
        case 2: _t->historyErrorLenghtChanged(); break;
        case 3: _t->socAlertChanged(); break;
        case 4: _t->addError((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 5: { QVariantMap _r = _t->getCurrentErrorAt((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariantMap*>(_a[0]) = std::move(_r); }  break;
        case 6: { QVariantMap _r = _t->getHistoryErrorAt((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariantMap*>(_a[0]) = std::move(_r); }  break;
        case 7: { int _r = _t->getCurrentErrorLength();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 8: { int _r = _t->getHistoryErrorLength();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 9: { bool _r = _t->getOnCurrentErrorPage();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 10: _t->setOnCurrentErrorPage((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->setSocAlert((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: { QVariantMap _r = _t->getBuzzerPattern();
            if (_a[0]) *reinterpret_cast< QVariantMap*>(_a[0]) = std::move(_r); }  break;
        case 13: _t->setBuzzerIsInCoolDown((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 14: _t->startBuzzerCooldown((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 15: _t->setBeepsDone((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ErrorManager::*)(QVariantMap );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ErrorManager::newErrorPop)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ErrorManager::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ErrorManager::currentErrorLenghtChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ErrorManager::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ErrorManager::historyErrorLenghtChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ErrorManager::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ErrorManager::socAlertChanged)) {
                *result = 3;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        ErrorManager *_t = static_cast<ErrorManager *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 1: *reinterpret_cast< bool*>(_v) = _t->getOnCurrentErrorPage(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        ErrorManager *_t = static_cast<ErrorManager *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 1: _t->setOnCurrentErrorPage(*reinterpret_cast< bool*>(_v)); break;
        case 2: _t->setSocAlert(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject ErrorManager::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_ErrorManager.data,
    qt_meta_data_ErrorManager,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ErrorManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ErrorManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ErrorManager.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ErrorManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
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
void ErrorManager::newErrorPop(QVariantMap _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ErrorManager::currentErrorLenghtChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void ErrorManager::historyErrorLenghtChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void ErrorManager::socAlertChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

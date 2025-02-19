/****************************************************************************
** Meta object code from reading C++ file 'popupmanager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../backend/popupmanager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'popupmanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PopUpManager_t {
    QByteArrayData data[15];
    char stringdata0[168];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PopUpManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PopUpManager_t qt_meta_stringdata_PopUpManager = {
    {
QT_MOC_LITERAL(0, 0, 12), // "PopUpManager"
QT_MOC_LITERAL(1, 13, 17), // "firstPopUpChanged"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 17), // "getPopUpToDisplay"
QT_MOC_LITERAL(4, 50, 8), // "addPopUp"
QT_MOC_LITERAL(5, 59, 10), // "pictSource"
QT_MOC_LITERAL(6, 70, 12), // "errorMessage"
QT_MOC_LITERAL(7, 83, 8), // "priority"
QT_MOC_LITERAL(8, 92, 10), // "buzzerType"
QT_MOC_LITERAL(9, 103, 4), // "size"
QT_MOC_LITERAL(10, 108, 11), // "deletePopUp"
QT_MOC_LITERAL(11, 120, 14), // "getCutOffLever"
QT_MOC_LITERAL(12, 135, 14), // "setCutOffLever"
QT_MOC_LITERAL(13, 150, 5), // "value"
QT_MOC_LITERAL(14, 156, 11) // "cutOffLever"

    },
    "PopUpManager\0firstPopUpChanged\0\0"
    "getPopUpToDisplay\0addPopUp\0pictSource\0"
    "errorMessage\0priority\0buzzerType\0size\0"
    "deletePopUp\0getCutOffLever\0setCutOffLever\0"
    "value\0cutOffLever"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PopUpManager[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       1,   66, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
       3,    0,   50,    2, 0x02 /* Public */,
       4,    4,   51,    2, 0x02 /* Public */,
       9,    0,   60,    2, 0x02 /* Public */,
      10,    0,   61,    2, 0x02 /* Public */,
      11,    0,   62,    2, 0x02 /* Public */,
      12,    1,   63,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,

 // methods: parameters
    QMetaType::QVariantMap,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::Int,    5,    6,    7,    8,
    QMetaType::Int,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::Bool,   13,

 // properties: name, type, flags
      14, QMetaType::Bool, 0x00095103,

       0        // eod
};

void PopUpManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PopUpManager *_t = static_cast<PopUpManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->firstPopUpChanged(); break;
        case 1: { QVariantMap _r = _t->getPopUpToDisplay();
            if (_a[0]) *reinterpret_cast< QVariantMap*>(_a[0]) = std::move(_r); }  break;
        case 2: _t->addPopUp((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 3: { int _r = _t->size();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 4: _t->deletePopUp(); break;
        case 5: { bool _r = _t->getCutOffLever();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 6: _t->setCutOffLever((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PopUpManager::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PopUpManager::firstPopUpChanged)) {
                *result = 0;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        PopUpManager *_t = static_cast<PopUpManager *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->getCutOffLever(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        PopUpManager *_t = static_cast<PopUpManager *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setCutOffLever(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject PopUpManager::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_PopUpManager.data,
    qt_meta_data_PopUpManager,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *PopUpManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PopUpManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PopUpManager.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int PopUpManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void PopUpManager::firstPopUpChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

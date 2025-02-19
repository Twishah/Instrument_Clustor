/****************************************************************************
** Meta object code from reading C++ file 'displayConfigHandler.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../backend/displayConfigHandler.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'displayConfigHandler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DisplayConfiguration_t {
    QByteArrayData data[7];
    char stringdata0[95];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DisplayConfiguration_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DisplayConfiguration_t qt_meta_stringdata_DisplayConfiguration = {
    {
QT_MOC_LITERAL(0, 0, 20), // "DisplayConfiguration"
QT_MOC_LITERAL(1, 21, 4), // "name"
QT_MOC_LITERAL(2, 26, 12), // "hwButtonNrOk"
QT_MOC_LITERAL(3, 39, 12), // "hwButtonNrUp"
QT_MOC_LITERAL(4, 52, 14), // "hwButtonNrDown"
QT_MOC_LITERAL(5, 67, 14), // "hwButtonNrMenu"
QT_MOC_LITERAL(6, 82, 12) // "headerHeight"

    },
    "DisplayConfiguration\0name\0hwButtonNrOk\0"
    "hwButtonNrUp\0hwButtonNrDown\0hwButtonNrMenu\0"
    "headerHeight"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DisplayConfiguration[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       6,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::QString, 0x00095401,
       2, QMetaType::Int, 0x00095401,
       3, QMetaType::Int, 0x00095401,
       4, QMetaType::Int, 0x00095401,
       5, QMetaType::Int, 0x00095401,
       6, QMetaType::Int, 0x00095401,

       0        // eod
};

void DisplayConfiguration::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{

#ifndef QT_NO_PROPERTIES
    if (_c == QMetaObject::ReadProperty) {
        DisplayConfiguration *_t = static_cast<DisplayConfiguration *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->name(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->hwButtonNrOk(); break;
        case 2: *reinterpret_cast< int*>(_v) = _t->hwButtonNrUp(); break;
        case 3: *reinterpret_cast< int*>(_v) = _t->hwButtonNrDown(); break;
        case 4: *reinterpret_cast< int*>(_v) = _t->hwButtonNrMenu(); break;
        case 5: *reinterpret_cast< int*>(_v) = _t->headerHeight(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject DisplayConfiguration::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_DisplayConfiguration.data,
    qt_meta_data_DisplayConfiguration,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DisplayConfiguration::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DisplayConfiguration::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DisplayConfiguration.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int DisplayConfiguration::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
   if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE

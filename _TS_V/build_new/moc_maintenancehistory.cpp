/****************************************************************************
** Meta object code from reading C++ file 'maintenancehistory.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../backend/maintenancehistory.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'maintenancehistory.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MaintenanceHistory_t {
    QByteArrayData data[14];
    char stringdata0[166];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MaintenanceHistory_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MaintenanceHistory_t qt_meta_stringdata_MaintenanceHistory = {
    {
QT_MOC_LITERAL(0, 0, 18), // "MaintenanceHistory"
QT_MOC_LITERAL(1, 19, 12), // "date1Changed"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 5), // "date1"
QT_MOC_LITERAL(4, 39, 17), // "hourMeter1Changed"
QT_MOC_LITERAL(5, 57, 10), // "hourMeter1"
QT_MOC_LITERAL(6, 68, 12), // "date2Changed"
QT_MOC_LITERAL(7, 81, 5), // "date2"
QT_MOC_LITERAL(8, 87, 17), // "hourMeter2Changed"
QT_MOC_LITERAL(9, 105, 10), // "hourMeter2"
QT_MOC_LITERAL(10, 116, 9), // "get_date1"
QT_MOC_LITERAL(11, 126, 14), // "get_hourMeter1"
QT_MOC_LITERAL(12, 141, 9), // "get_date2"
QT_MOC_LITERAL(13, 151, 14) // "get_hourMeter2"

    },
    "MaintenanceHistory\0date1Changed\0\0date1\0"
    "hourMeter1Changed\0hourMeter1\0date2Changed\0"
    "date2\0hourMeter2Changed\0hourMeter2\0"
    "get_date1\0get_hourMeter1\0get_date2\0"
    "get_hourMeter2"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MaintenanceHistory[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       4,   70, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       4,    1,   57,    2, 0x06 /* Public */,
       6,    1,   60,    2, 0x06 /* Public */,
       8,    1,   63,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
      10,    0,   66,    2, 0x02 /* Public */,
      11,    0,   67,    2, 0x02 /* Public */,
      12,    0,   68,    2, 0x02 /* Public */,
      13,    0,   69,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Double,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::Double,    9,

 // methods: parameters
    QMetaType::QString,
    QMetaType::Double,
    QMetaType::QString,
    QMetaType::Double,

 // properties: name, type, flags
       3, QMetaType::QString, 0x00495003,
       5, QMetaType::Double, 0x00495003,
       7, QMetaType::QString, 0x00495003,
       9, QMetaType::Double, 0x00495003,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,

       0        // eod
};

void MaintenanceHistory::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MaintenanceHistory *_t = static_cast<MaintenanceHistory *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->date1Changed((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->hourMeter1Changed((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->date2Changed((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->hourMeter2Changed((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: { QString _r = _t->get_date1();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 5: { double _r = _t->get_hourMeter1();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = std::move(_r); }  break;
        case 6: { QString _r = _t->get_date2();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 7: { double _r = _t->get_hourMeter2();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MaintenanceHistory::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MaintenanceHistory::date1Changed)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MaintenanceHistory::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MaintenanceHistory::hourMeter1Changed)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MaintenanceHistory::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MaintenanceHistory::date2Changed)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MaintenanceHistory::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MaintenanceHistory::hourMeter2Changed)) {
                *result = 3;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        MaintenanceHistory *_t = static_cast<MaintenanceHistory *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->get_date1(); break;
        case 1: *reinterpret_cast< double*>(_v) = _t->get_hourMeter1(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->get_date2(); break;
        case 3: *reinterpret_cast< double*>(_v) = _t->get_hourMeter2(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        MaintenanceHistory *_t = static_cast<MaintenanceHistory *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->set_date1(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->set_hourMeter1(*reinterpret_cast< double*>(_v)); break;
        case 2: _t->set_date2(*reinterpret_cast< QString*>(_v)); break;
        case 3: _t->set_hourMeter2(*reinterpret_cast< double*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject MaintenanceHistory::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_MaintenanceHistory.data,
    qt_meta_data_MaintenanceHistory,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MaintenanceHistory::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MaintenanceHistory::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MaintenanceHistory.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int MaintenanceHistory::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
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
void MaintenanceHistory::date1Changed(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MaintenanceHistory::hourMeter1Changed(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MaintenanceHistory::date2Changed(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MaintenanceHistory::hourMeter2Changed(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

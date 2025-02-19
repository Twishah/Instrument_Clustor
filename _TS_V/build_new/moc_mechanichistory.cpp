/****************************************************************************
** Meta object code from reading C++ file 'mechanichistory.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../backend/mechanichistory.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mechanichistory.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MechanicHistory_t {
    QByteArrayData data[11];
    char stringdata0[173];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MechanicHistory_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MechanicHistory_t qt_meta_stringdata_MechanicHistory = {
    {
QT_MOC_LITERAL(0, 0, 15), // "MechanicHistory"
QT_MOC_LITERAL(1, 16, 18), // "dateMecHistChanged"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 11), // "dateMecHist"
QT_MOC_LITERAL(4, 48, 18), // "timeMecHistChanged"
QT_MOC_LITERAL(5, 67, 11), // "timeMecHist"
QT_MOC_LITERAL(6, 79, 23), // "hourmeterMecHistChanged"
QT_MOC_LITERAL(7, 103, 16), // "hourmeterMecHist"
QT_MOC_LITERAL(8, 120, 15), // "get_dateMecHist"
QT_MOC_LITERAL(9, 136, 15), // "get_timeMecHist"
QT_MOC_LITERAL(10, 152, 20) // "get_hourmeterMecHist"

    },
    "MechanicHistory\0dateMecHistChanged\0\0"
    "dateMecHist\0timeMecHistChanged\0"
    "timeMecHist\0hourmeterMecHistChanged\0"
    "hourmeterMecHist\0get_dateMecHist\0"
    "get_timeMecHist\0get_hourmeterMecHist"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MechanicHistory[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       3,   56, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       4,    1,   47,    2, 0x06 /* Public */,
       6,    1,   50,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
       8,    0,   53,    2, 0x02 /* Public */,
       9,    0,   54,    2, 0x02 /* Public */,
      10,    0,   55,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::Double,    7,

 // methods: parameters
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::Double,

 // properties: name, type, flags
       3, QMetaType::QString, 0x00495003,
       5, QMetaType::QString, 0x00495003,
       7, QMetaType::Double, 0x00495003,

 // properties: notify_signal_id
       0,
       1,
       2,

       0        // eod
};

void MechanicHistory::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MechanicHistory *_t = static_cast<MechanicHistory *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->dateMecHistChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->timeMecHistChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->hourmeterMecHistChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: { QString _r = _t->get_dateMecHist();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 4: { QString _r = _t->get_timeMecHist();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 5: { double _r = _t->get_hourmeterMecHist();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MechanicHistory::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MechanicHistory::dateMecHistChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MechanicHistory::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MechanicHistory::timeMecHistChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MechanicHistory::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MechanicHistory::hourmeterMecHistChanged)) {
                *result = 2;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        MechanicHistory *_t = static_cast<MechanicHistory *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->get_dateMecHist(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->get_timeMecHist(); break;
        case 2: *reinterpret_cast< double*>(_v) = _t->get_hourmeterMecHist(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        MechanicHistory *_t = static_cast<MechanicHistory *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->set_dateMecHist(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->set_timeMecHist(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->set_hourmeterMecHist(*reinterpret_cast< double*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject MechanicHistory::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_MechanicHistory.data,
    qt_meta_data_MechanicHistory,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MechanicHistory::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MechanicHistory::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MechanicHistory.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int MechanicHistory::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
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
void MechanicHistory::dateMecHistChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MechanicHistory::timeMecHistChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MechanicHistory::hourmeterMecHistChanged(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

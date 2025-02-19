/****************************************************************************
** Meta object code from reading C++ file 'can_handler3.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../backend/can_handler3.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'can_handler3.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CAN_Handler3_t {
    QByteArrayData data[97];
    char stringdata0[2043];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CAN_Handler3_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CAN_Handler3_t qt_meta_stringdata_CAN_Handler3 = {
    {
QT_MOC_LITERAL(0, 0, 12), // "CAN_Handler3"
QT_MOC_LITERAL(1, 13, 33), // "McuSOFTNbOfSoftIdentFieldsCha..."
QT_MOC_LITERAL(2, 47, 0), // ""
QT_MOC_LITERAL(3, 48, 32), // "McuSOFTSoftwarePartNumberChanged"
QT_MOC_LITERAL(4, 81, 21), // "McuSOFTVersionChanged"
QT_MOC_LITERAL(5, 103, 24), // "McuSOFTPartNumberChanged"
QT_MOC_LITERAL(6, 128, 18), // "McuSOFTTypeChanged"
QT_MOC_LITERAL(7, 147, 32), // "McuSOFTCustomerSoftNumberChanged"
QT_MOC_LITERAL(8, 180, 20), // "BrakePedalPosChanged"
QT_MOC_LITERAL(9, 201, 20), // "AccelPedalPosChanged"
QT_MOC_LITERAL(10, 222, 30), // "BtnMenuCalendar_VisibleChanged"
QT_MOC_LITERAL(11, 253, 33), // "BtnMenuImmobilizer_VisibleCha..."
QT_MOC_LITERAL(12, 287, 29), // "BtnMenuHeating_VisibleChanged"
QT_MOC_LITERAL(13, 317, 29), // "BtnMenuMonitor_VisibleChanged"
QT_MOC_LITERAL(14, 347, 33), // "BtnMenuMaintenance_VisibleCha..."
QT_MOC_LITERAL(15, 381, 32), // "BtnMenuFiltrRegen_VisibleChanged"
QT_MOC_LITERAL(16, 414, 36), // "AdjustAddCtrlCircuit1_Visible..."
QT_MOC_LITERAL(17, 451, 36), // "AdjustAddCtrlCircuit2_Visible..."
QT_MOC_LITERAL(18, 488, 31), // "AdjustRCSForward_VisibleChanged"
QT_MOC_LITERAL(19, 520, 32), // "AdjustRCSBackward_VisibleChanged"
QT_MOC_LITERAL(20, 553, 39), // "AdjustAutoEngineStopTime_Visi..."
QT_MOC_LITERAL(21, 593, 38), // "BtnFctDateTimeAutomatic_Visib..."
QT_MOC_LITERAL(22, 632, 33), // "BtnImmobActivation_VisibleCha..."
QT_MOC_LITERAL(23, 666, 31), // "BtnImmobOwnerPin_VisibleChanged"
QT_MOC_LITERAL(24, 698, 32), // "BtnImmobDriverPin_VisibleChanged"
QT_MOC_LITERAL(25, 731, 31), // "BtnImmobTransPin_VisibleChanged"
QT_MOC_LITERAL(26, 763, 39), // "BtnImmobTimeToActivation_Visi..."
QT_MOC_LITERAL(27, 803, 25), // "BtnDiagMCU_VisibleChanged"
QT_MOC_LITERAL(28, 829, 25), // "BtnDiagTCU_VisibleChanged"
QT_MOC_LITERAL(29, 855, 25), // "BtnDiagECU_VisibleChanged"
QT_MOC_LITERAL(30, 881, 17), // "dmdDrvPedlChanged"
QT_MOC_LITERAL(31, 899, 18), // "dmdInchPedlChanged"
QT_MOC_LITERAL(32, 918, 17), // "dmdCrpPotiChanged"
QT_MOC_LITERAL(33, 936, 16), // "dmdHndThrChanged"
QT_MOC_LITERAL(34, 953, 14), // "SarDateChanged"
QT_MOC_LITERAL(35, 968, 14), // "SarTimeChanged"
QT_MOC_LITERAL(36, 983, 8), // "uint32_t"
QT_MOC_LITERAL(37, 992, 17), // "StartRelayChanged"
QT_MOC_LITERAL(38, 1010, 12), // "RailPChanged"
QT_MOC_LITERAL(39, 1023, 15), // "EngSpeedChanged"
QT_MOC_LITERAL(40, 1039, 18), // "FuelPerHourChanged"
QT_MOC_LITERAL(41, 1058, 35), // "engPercentLoadAtCurrentSpeedC..."
QT_MOC_LITERAL(42, 1094, 11), // "msgReceived"
QT_MOC_LITERAL(43, 1106, 2), // "ID"
QT_MOC_LITERAL(44, 1109, 6), // "Data_0"
QT_MOC_LITERAL(45, 1116, 6), // "Data_1"
QT_MOC_LITERAL(46, 1123, 6), // "Data_2"
QT_MOC_LITERAL(47, 1130, 6), // "Data_3"
QT_MOC_LITERAL(48, 1137, 6), // "Data_4"
QT_MOC_LITERAL(49, 1144, 6), // "Data_5"
QT_MOC_LITERAL(50, 1151, 6), // "Data_6"
QT_MOC_LITERAL(51, 1158, 6), // "Data_7"
QT_MOC_LITERAL(52, 1165, 20), // "byteArrayToHexString"
QT_MOC_LITERAL(53, 1186, 9), // "byteArray"
QT_MOC_LITERAL(54, 1196, 18), // "getCanTimeoutError"
QT_MOC_LITERAL(55, 1215, 7), // "sendCAN"
QT_MOC_LITERAL(56, 1223, 26), // "McuSOFTNbOfSoftIdentFields"
QT_MOC_LITERAL(57, 1250, 25), // "McuSOFTSoftwarePartNumber"
QT_MOC_LITERAL(58, 1276, 14), // "McuSOFTVersion"
QT_MOC_LITERAL(59, 1291, 17), // "McuSOFTPartNumber"
QT_MOC_LITERAL(60, 1309, 11), // "McuSOFTType"
QT_MOC_LITERAL(61, 1321, 25), // "McuSOFTCustomerSoftNumber"
QT_MOC_LITERAL(62, 1347, 13), // "BrakePedalPos"
QT_MOC_LITERAL(63, 1361, 13), // "AccelPedalPos"
QT_MOC_LITERAL(64, 1375, 23), // "BtnMenuCalendar_Visible"
QT_MOC_LITERAL(65, 1399, 26), // "BtnMenuImmobilizer_Visible"
QT_MOC_LITERAL(66, 1426, 22), // "BtnMenuHeating_Visible"
QT_MOC_LITERAL(67, 1449, 22), // "BtnMenuMonitor_Visible"
QT_MOC_LITERAL(68, 1472, 26), // "BtnMenuMaintenance_Visible"
QT_MOC_LITERAL(69, 1499, 25), // "BtnMenuFiltrRegen_Visible"
QT_MOC_LITERAL(70, 1525, 29), // "AdjustAddCtrlCircuit1_Visible"
QT_MOC_LITERAL(71, 1555, 29), // "AdjustAddCtrlCircuit2_Visible"
QT_MOC_LITERAL(72, 1585, 24), // "AdjustRCSForward_Visible"
QT_MOC_LITERAL(73, 1610, 25), // "AdjustRCSBackward_Visible"
QT_MOC_LITERAL(74, 1636, 32), // "AdjustAutoEngineStopTime_Visible"
QT_MOC_LITERAL(75, 1669, 31), // "BtnFctDateTimeAutomatic_Visible"
QT_MOC_LITERAL(76, 1701, 26), // "BtnImmobActivation_Visible"
QT_MOC_LITERAL(77, 1728, 24), // "BtnImmobOwnerPin_Visible"
QT_MOC_LITERAL(78, 1753, 25), // "BtnImmobDriverPin_Visible"
QT_MOC_LITERAL(79, 1779, 24), // "BtnImmobTransPin_Visible"
QT_MOC_LITERAL(80, 1804, 32), // "BtnImmobTimeToActivation_Visible"
QT_MOC_LITERAL(81, 1837, 18), // "BtnDiagMCU_Visible"
QT_MOC_LITERAL(82, 1856, 18), // "BtnDiagTCU_Visible"
QT_MOC_LITERAL(83, 1875, 18), // "BtnDiagECU_Visible"
QT_MOC_LITERAL(84, 1894, 10), // "dmdDrvPedl"
QT_MOC_LITERAL(85, 1905, 11), // "dmdInchPedl"
QT_MOC_LITERAL(86, 1917, 10), // "dmdCrpPoti"
QT_MOC_LITERAL(87, 1928, 9), // "dmdHndThr"
QT_MOC_LITERAL(88, 1938, 7), // "sarDate"
QT_MOC_LITERAL(89, 1946, 7), // "sarTime"
QT_MOC_LITERAL(90, 1954, 10), // "startRelay"
QT_MOC_LITERAL(91, 1965, 5), // "railP"
QT_MOC_LITERAL(92, 1971, 8), // "engSpeed"
QT_MOC_LITERAL(93, 1980, 11), // "fuelPerHour"
QT_MOC_LITERAL(94, 1992, 28), // "engPercentLoadAtCurrentSpeed"
QT_MOC_LITERAL(95, 2021, 11), // "ErrorExists"
QT_MOC_LITERAL(96, 2033, 9) // "ErrorCode"

    },
    "CAN_Handler3\0McuSOFTNbOfSoftIdentFieldsChanged\0"
    "\0McuSOFTSoftwarePartNumberChanged\0"
    "McuSOFTVersionChanged\0McuSOFTPartNumberChanged\0"
    "McuSOFTTypeChanged\0McuSOFTCustomerSoftNumberChanged\0"
    "BrakePedalPosChanged\0AccelPedalPosChanged\0"
    "BtnMenuCalendar_VisibleChanged\0"
    "BtnMenuImmobilizer_VisibleChanged\0"
    "BtnMenuHeating_VisibleChanged\0"
    "BtnMenuMonitor_VisibleChanged\0"
    "BtnMenuMaintenance_VisibleChanged\0"
    "BtnMenuFiltrRegen_VisibleChanged\0"
    "AdjustAddCtrlCircuit1_VisibleChanged\0"
    "AdjustAddCtrlCircuit2_VisibleChanged\0"
    "AdjustRCSForward_VisibleChanged\0"
    "AdjustRCSBackward_VisibleChanged\0"
    "AdjustAutoEngineStopTime_VisibleChanged\0"
    "BtnFctDateTimeAutomatic_VisibleChanged\0"
    "BtnImmobActivation_VisibleChanged\0"
    "BtnImmobOwnerPin_VisibleChanged\0"
    "BtnImmobDriverPin_VisibleChanged\0"
    "BtnImmobTransPin_VisibleChanged\0"
    "BtnImmobTimeToActivation_VisibleChanged\0"
    "BtnDiagMCU_VisibleChanged\0"
    "BtnDiagTCU_VisibleChanged\0"
    "BtnDiagECU_VisibleChanged\0dmdDrvPedlChanged\0"
    "dmdInchPedlChanged\0dmdCrpPotiChanged\0"
    "dmdHndThrChanged\0SarDateChanged\0"
    "SarTimeChanged\0uint32_t\0StartRelayChanged\0"
    "RailPChanged\0EngSpeedChanged\0"
    "FuelPerHourChanged\0"
    "engPercentLoadAtCurrentSpeedChanged\0"
    "msgReceived\0ID\0Data_0\0Data_1\0Data_2\0"
    "Data_3\0Data_4\0Data_5\0Data_6\0Data_7\0"
    "byteArrayToHexString\0byteArray\0"
    "getCanTimeoutError\0sendCAN\0"
    "McuSOFTNbOfSoftIdentFields\0"
    "McuSOFTSoftwarePartNumber\0McuSOFTVersion\0"
    "McuSOFTPartNumber\0McuSOFTType\0"
    "McuSOFTCustomerSoftNumber\0BrakePedalPos\0"
    "AccelPedalPos\0BtnMenuCalendar_Visible\0"
    "BtnMenuImmobilizer_Visible\0"
    "BtnMenuHeating_Visible\0BtnMenuMonitor_Visible\0"
    "BtnMenuMaintenance_Visible\0"
    "BtnMenuFiltrRegen_Visible\0"
    "AdjustAddCtrlCircuit1_Visible\0"
    "AdjustAddCtrlCircuit2_Visible\0"
    "AdjustRCSForward_Visible\0"
    "AdjustRCSBackward_Visible\0"
    "AdjustAutoEngineStopTime_Visible\0"
    "BtnFctDateTimeAutomatic_Visible\0"
    "BtnImmobActivation_Visible\0"
    "BtnImmobOwnerPin_Visible\0"
    "BtnImmobDriverPin_Visible\0"
    "BtnImmobTransPin_Visible\0"
    "BtnImmobTimeToActivation_Visible\0"
    "BtnDiagMCU_Visible\0BtnDiagTCU_Visible\0"
    "BtnDiagECU_Visible\0dmdDrvPedl\0dmdInchPedl\0"
    "dmdCrpPoti\0dmdHndThr\0sarDate\0sarTime\0"
    "startRelay\0railP\0engSpeed\0fuelPerHour\0"
    "engPercentLoadAtCurrentSpeed\0ErrorExists\0"
    "ErrorCode"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CAN_Handler3[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      43,   14, // methods
      41,  388, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      39,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  229,    2, 0x06 /* Public */,
       3,    1,  232,    2, 0x06 /* Public */,
       4,    1,  235,    2, 0x06 /* Public */,
       5,    1,  238,    2, 0x06 /* Public */,
       6,    1,  241,    2, 0x06 /* Public */,
       7,    1,  244,    2, 0x06 /* Public */,
       8,    1,  247,    2, 0x06 /* Public */,
       9,    1,  250,    2, 0x06 /* Public */,
      10,    1,  253,    2, 0x06 /* Public */,
      11,    1,  256,    2, 0x06 /* Public */,
      12,    1,  259,    2, 0x06 /* Public */,
      13,    1,  262,    2, 0x06 /* Public */,
      14,    1,  265,    2, 0x06 /* Public */,
      15,    1,  268,    2, 0x06 /* Public */,
      16,    1,  271,    2, 0x06 /* Public */,
      17,    1,  274,    2, 0x06 /* Public */,
      18,    1,  277,    2, 0x06 /* Public */,
      19,    1,  280,    2, 0x06 /* Public */,
      20,    1,  283,    2, 0x06 /* Public */,
      21,    1,  286,    2, 0x06 /* Public */,
      22,    1,  289,    2, 0x06 /* Public */,
      23,    1,  292,    2, 0x06 /* Public */,
      24,    1,  295,    2, 0x06 /* Public */,
      25,    1,  298,    2, 0x06 /* Public */,
      26,    1,  301,    2, 0x06 /* Public */,
      27,    1,  304,    2, 0x06 /* Public */,
      28,    1,  307,    2, 0x06 /* Public */,
      29,    1,  310,    2, 0x06 /* Public */,
      30,    1,  313,    2, 0x06 /* Public */,
      31,    1,  316,    2, 0x06 /* Public */,
      32,    1,  319,    2, 0x06 /* Public */,
      33,    1,  322,    2, 0x06 /* Public */,
      34,    1,  325,    2, 0x06 /* Public */,
      35,    1,  328,    2, 0x06 /* Public */,
      37,    1,  331,    2, 0x06 /* Public */,
      38,    1,  334,    2, 0x06 /* Public */,
      39,    1,  337,    2, 0x06 /* Public */,
      40,    1,  340,    2, 0x06 /* Public */,
      41,    1,  343,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      42,    9,  346,    2, 0x08 /* Private */,

 // methods: name, argc, parameters, tag, flags
      52,    1,  365,    2, 0x02 /* Public */,
      54,    0,  368,    2, 0x02 /* Public */,
      55,    9,  369,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 36,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   43,   44,   45,   46,   47,   48,   49,   50,   51,

 // methods: parameters
    QMetaType::QString, QMetaType::QByteArray,   53,
    QMetaType::QVariantMap,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   43,   44,   45,   46,   47,   48,   49,   50,   51,

 // properties: name, type, flags
      56, QMetaType::Int, 0x00495001,
      57, QMetaType::Int, 0x00495001,
      58, QMetaType::Int, 0x00495001,
      59, QMetaType::Int, 0x00495001,
      60, QMetaType::Int, 0x00495001,
      61, QMetaType::Int, 0x00495001,
      62, QMetaType::Int, 0x00495001,
      63, QMetaType::Int, 0x00495001,
      64, QMetaType::Int, 0x00495001,
      65, QMetaType::Int, 0x00495001,
      66, QMetaType::Int, 0x00495001,
      67, QMetaType::Int, 0x00495001,
      68, QMetaType::Int, 0x00495001,
      69, QMetaType::Int, 0x00495001,
      70, QMetaType::Int, 0x00495001,
      71, QMetaType::Int, 0x00495001,
      72, QMetaType::Int, 0x00495001,
      73, QMetaType::Int, 0x00495001,
      74, QMetaType::Int, 0x00495001,
      75, QMetaType::Int, 0x00495001,
      76, QMetaType::Int, 0x00495001,
      77, QMetaType::Int, 0x00495001,
      78, QMetaType::Int, 0x00495001,
      79, QMetaType::Int, 0x00495001,
      80, QMetaType::Int, 0x00495001,
      81, QMetaType::Int, 0x00495001,
      82, QMetaType::Int, 0x00495001,
      83, QMetaType::Int, 0x00495001,
      84, QMetaType::Int, 0x00495001,
      85, QMetaType::Int, 0x00495001,
      86, QMetaType::Int, 0x00495001,
      87, QMetaType::Int, 0x00495001,
      88, QMetaType::Int, 0x00495001,
      89, QMetaType::Int, 0x00495001,
      90, QMetaType::Int, 0x00495001,
      91, QMetaType::Double, 0x00495001,
      92, QMetaType::Double, 0x00495001,
      93, QMetaType::Double, 0x00495001,
      94, QMetaType::Int, 0x00495001,
      95, QMetaType::Bool, 0x00095001,
      96, QMetaType::Int, 0x00095001,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,
       4,
       5,
       6,
       7,
       8,
       9,
      10,
      11,
      12,
      13,
      14,
      15,
      16,
      17,
      18,
      19,
      20,
      21,
      22,
      23,
      24,
      25,
      26,
      27,
      28,
      29,
      30,
      31,
      32,
      33,
      34,
      35,
      36,
      37,
      38,
       0,
       0,

       0        // eod
};

void CAN_Handler3::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CAN_Handler3 *_t = static_cast<CAN_Handler3 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->McuSOFTNbOfSoftIdentFieldsChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->McuSOFTSoftwarePartNumberChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->McuSOFTVersionChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->McuSOFTPartNumberChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->McuSOFTTypeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->McuSOFTCustomerSoftNumberChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->BrakePedalPosChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->AccelPedalPosChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->BtnMenuCalendar_VisibleChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->BtnMenuImmobilizer_VisibleChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->BtnMenuHeating_VisibleChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->BtnMenuMonitor_VisibleChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->BtnMenuMaintenance_VisibleChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->BtnMenuFiltrRegen_VisibleChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->AdjustAddCtrlCircuit1_VisibleChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->AdjustAddCtrlCircuit2_VisibleChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->AdjustRCSForward_VisibleChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->AdjustRCSBackward_VisibleChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: _t->AdjustAutoEngineStopTime_VisibleChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: _t->BtnFctDateTimeAutomatic_VisibleChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 20: _t->BtnImmobActivation_VisibleChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 21: _t->BtnImmobOwnerPin_VisibleChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: _t->BtnImmobDriverPin_VisibleChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 23: _t->BtnImmobTransPin_VisibleChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 24: _t->BtnImmobTimeToActivation_VisibleChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 25: _t->BtnDiagMCU_VisibleChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 26: _t->BtnDiagTCU_VisibleChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 27: _t->BtnDiagECU_VisibleChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 28: _t->dmdDrvPedlChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 29: _t->dmdInchPedlChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 30: _t->dmdCrpPotiChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 31: _t->dmdHndThrChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 32: _t->SarDateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 33: _t->SarTimeChanged((*reinterpret_cast< uint32_t(*)>(_a[1]))); break;
        case 34: _t->StartRelayChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 35: _t->RailPChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 36: _t->EngSpeedChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 37: _t->FuelPerHourChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 38: _t->engPercentLoadAtCurrentSpeedChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 39: _t->msgReceived((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7])),(*reinterpret_cast< int(*)>(_a[8])),(*reinterpret_cast< int(*)>(_a[9]))); break;
        case 40: { QString _r = _t->byteArrayToHexString((*reinterpret_cast< const QByteArray(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 41: { QVariantMap _r = _t->getCanTimeoutError();
            if (_a[0]) *reinterpret_cast< QVariantMap*>(_a[0]) = std::move(_r); }  break;
        case 42: _t->sendCAN((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7])),(*reinterpret_cast< int(*)>(_a[8])),(*reinterpret_cast< int(*)>(_a[9]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CAN_Handler3::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CAN_Handler3::McuSOFTNbOfSoftIdentFieldsChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CAN_Handler3::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CAN_Handler3::McuSOFTSoftwarePartNumberChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (CAN_Handler3::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CAN_Handler3::McuSOFTVersionChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (CAN_Handler3::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CAN_Handler3::McuSOFTPartNumberChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (CAN_Handler3::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CAN_Handler3::McuSOFTTypeChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (CAN_Handler3::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CAN_Handler3::McuSOFTCustomerSoftNumberChanged)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (CAN_Handler3::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CAN_Handler3::BrakePedalPosChanged)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (CAN_Handler3::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CAN_Handler3::AccelPedalPosChanged)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (CAN_Handler3::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CAN_Handler3::BtnMenuCalendar_VisibleChanged)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (CAN_Handler3::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CAN_Handler3::BtnMenuImmobilizer_VisibleChanged)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (CAN_Handler3::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CAN_Handler3::BtnMenuHeating_VisibleChanged)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (CAN_Handler3::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CAN_Handler3::BtnMenuMonitor_VisibleChanged)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (CAN_Handler3::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CAN_Handler3::BtnMenuMaintenance_VisibleChanged)) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (CAN_Handler3::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CAN_Handler3::BtnMenuFiltrRegen_VisibleChanged)) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (CAN_Handler3::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CAN_Handler3::AdjustAddCtrlCircuit1_VisibleChanged)) {
                *result = 14;
                return;
            }
        }
        {
            using _t = void (CAN_Handler3::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CAN_Handler3::AdjustAddCtrlCircuit2_VisibleChanged)) {
                *result = 15;
                return;
            }
        }
        {
            using _t = void (CAN_Handler3::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CAN_Handler3::AdjustRCSForward_VisibleChanged)) {
                *result = 16;
                return;
            }
        }
        {
            using _t = void (CAN_Handler3::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CAN_Handler3::AdjustRCSBackward_VisibleChanged)) {
                *result = 17;
                return;
            }
        }
        {
            using _t = void (CAN_Handler3::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CAN_Handler3::AdjustAutoEngineStopTime_VisibleChanged)) {
                *result = 18;
                return;
            }
        }
        {
            using _t = void (CAN_Handler3::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CAN_Handler3::BtnFctDateTimeAutomatic_VisibleChanged)) {
                *result = 19;
                return;
            }
        }
        {
            using _t = void (CAN_Handler3::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CAN_Handler3::BtnImmobActivation_VisibleChanged)) {
                *result = 20;
                return;
            }
        }
        {
            using _t = void (CAN_Handler3::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CAN_Handler3::BtnImmobOwnerPin_VisibleChanged)) {
                *result = 21;
                return;
            }
        }
        {
            using _t = void (CAN_Handler3::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CAN_Handler3::BtnImmobDriverPin_VisibleChanged)) {
                *result = 22;
                return;
            }
        }
        {
            using _t = void (CAN_Handler3::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CAN_Handler3::BtnImmobTransPin_VisibleChanged)) {
                *result = 23;
                return;
            }
        }
        {
            using _t = void (CAN_Handler3::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CAN_Handler3::BtnImmobTimeToActivation_VisibleChanged)) {
                *result = 24;
                return;
            }
        }
        {
            using _t = void (CAN_Handler3::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CAN_Handler3::BtnDiagMCU_VisibleChanged)) {
                *result = 25;
                return;
            }
        }
        {
            using _t = void (CAN_Handler3::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CAN_Handler3::BtnDiagTCU_VisibleChanged)) {
                *result = 26;
                return;
            }
        }
        {
            using _t = void (CAN_Handler3::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CAN_Handler3::BtnDiagECU_VisibleChanged)) {
                *result = 27;
                return;
            }
        }
        {
            using _t = void (CAN_Handler3::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CAN_Handler3::dmdDrvPedlChanged)) {
                *result = 28;
                return;
            }
        }
        {
            using _t = void (CAN_Handler3::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CAN_Handler3::dmdInchPedlChanged)) {
                *result = 29;
                return;
            }
        }
        {
            using _t = void (CAN_Handler3::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CAN_Handler3::dmdCrpPotiChanged)) {
                *result = 30;
                return;
            }
        }
        {
            using _t = void (CAN_Handler3::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CAN_Handler3::dmdHndThrChanged)) {
                *result = 31;
                return;
            }
        }
        {
            using _t = void (CAN_Handler3::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CAN_Handler3::SarDateChanged)) {
                *result = 32;
                return;
            }
        }
        {
            using _t = void (CAN_Handler3::*)(uint32_t );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CAN_Handler3::SarTimeChanged)) {
                *result = 33;
                return;
            }
        }
        {
            using _t = void (CAN_Handler3::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CAN_Handler3::StartRelayChanged)) {
                *result = 34;
                return;
            }
        }
        {
            using _t = void (CAN_Handler3::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CAN_Handler3::RailPChanged)) {
                *result = 35;
                return;
            }
        }
        {
            using _t = void (CAN_Handler3::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CAN_Handler3::EngSpeedChanged)) {
                *result = 36;
                return;
            }
        }
        {
            using _t = void (CAN_Handler3::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CAN_Handler3::FuelPerHourChanged)) {
                *result = 37;
                return;
            }
        }
        {
            using _t = void (CAN_Handler3::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CAN_Handler3::engPercentLoadAtCurrentSpeedChanged)) {
                *result = 38;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        CAN_Handler3 *_t = static_cast<CAN_Handler3 *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->getMcuSOFTNbOfSoftIdentFields(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->getMcuSOFTSoftwarePartNumber(); break;
        case 2: *reinterpret_cast< int*>(_v) = _t->getMcuSOFTVersion(); break;
        case 3: *reinterpret_cast< int*>(_v) = _t->getMcuSOFTPartNumber(); break;
        case 4: *reinterpret_cast< int*>(_v) = _t->getMcuSOFTType(); break;
        case 5: *reinterpret_cast< int*>(_v) = _t->getMcuSOFTCustomerSoftNumber(); break;
        case 6: *reinterpret_cast< int*>(_v) = _t->getBrakePedalPos(); break;
        case 7: *reinterpret_cast< int*>(_v) = _t->getAccelPedalPos(); break;
        case 8: *reinterpret_cast< int*>(_v) = _t->getBtnMenuCalendar_Visible(); break;
        case 9: *reinterpret_cast< int*>(_v) = _t->getBtnMenuImmobilizer_Visible(); break;
        case 10: *reinterpret_cast< int*>(_v) = _t->getBtnMenuHeating_Visible(); break;
        case 11: *reinterpret_cast< int*>(_v) = _t->getBtnMenuMonitor_Visible(); break;
        case 12: *reinterpret_cast< int*>(_v) = _t->getBtnMenuMaintenance_Visible(); break;
        case 13: *reinterpret_cast< int*>(_v) = _t->getBtnMenuFiltrRegen_Visible(); break;
        case 14: *reinterpret_cast< int*>(_v) = _t->getAdjustAddCtrlCircuit1_Visible(); break;
        case 15: *reinterpret_cast< int*>(_v) = _t->getAdjustAddCtrlCircuit2_Visible(); break;
        case 16: *reinterpret_cast< int*>(_v) = _t->getAdjustRCSForward_Visible(); break;
        case 17: *reinterpret_cast< int*>(_v) = _t->getAdjustRCSBackward_Visible(); break;
        case 18: *reinterpret_cast< int*>(_v) = _t->getAdjustAutoEngineStopTime_Visible(); break;
        case 19: *reinterpret_cast< int*>(_v) = _t->getBtnFctDateTimeAutomatic_Visible(); break;
        case 20: *reinterpret_cast< int*>(_v) = _t->getBtnImmobActivation_Visible(); break;
        case 21: *reinterpret_cast< int*>(_v) = _t->getBtnImmobOwnerPin_Visible(); break;
        case 22: *reinterpret_cast< int*>(_v) = _t->getBtnImmobDriverPin_Visible(); break;
        case 23: *reinterpret_cast< int*>(_v) = _t->getBtnImmobTransPin_Visible(); break;
        case 24: *reinterpret_cast< int*>(_v) = _t->getBtnImmobTimeToActivation_Visible(); break;
        case 25: *reinterpret_cast< int*>(_v) = _t->getBtnDiagMCU_Visible(); break;
        case 26: *reinterpret_cast< int*>(_v) = _t->getBtnDiagTCU_Visible(); break;
        case 27: *reinterpret_cast< int*>(_v) = _t->getBtnDiagECU_Visible(); break;
        case 28: *reinterpret_cast< int*>(_v) = _t->getdmdDrvPedl(); break;
        case 29: *reinterpret_cast< int*>(_v) = _t->getdmdInchPedl(); break;
        case 30: *reinterpret_cast< int*>(_v) = _t->getdmdCrpPoti(); break;
        case 31: *reinterpret_cast< int*>(_v) = _t->getdmdHndThr(); break;
        case 32: *reinterpret_cast< int*>(_v) = _t->getSarDate(); break;
        case 33: *reinterpret_cast< int*>(_v) = _t->getSarTime(); break;
        case 34: *reinterpret_cast< int*>(_v) = _t->getStartRelay(); break;
        case 35: *reinterpret_cast< double*>(_v) = _t->getRailP(); break;
        case 36: *reinterpret_cast< double*>(_v) = _t->getEngSpeed(); break;
        case 37: *reinterpret_cast< double*>(_v) = _t->getFuelPerHour(); break;
        case 38: *reinterpret_cast< int*>(_v) = _t->getEngPercentLoadAtCurrentSpeed(); break;
        case 39: *reinterpret_cast< bool*>(_v) = _t->getCanError(); break;
        case 40: *reinterpret_cast< int*>(_v) = _t->getCanErrorCode(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject CAN_Handler3::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_CAN_Handler3.data,
    qt_meta_data_CAN_Handler3,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CAN_Handler3::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CAN_Handler3::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CAN_Handler3.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CAN_Handler3::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 43)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 43;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 43)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 43;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 41;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 41;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 41;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 41;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 41;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 41;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void CAN_Handler3::McuSOFTNbOfSoftIdentFieldsChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CAN_Handler3::McuSOFTSoftwarePartNumberChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CAN_Handler3::McuSOFTVersionChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CAN_Handler3::McuSOFTPartNumberChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void CAN_Handler3::McuSOFTTypeChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void CAN_Handler3::McuSOFTCustomerSoftNumberChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void CAN_Handler3::BrakePedalPosChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void CAN_Handler3::AccelPedalPosChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void CAN_Handler3::BtnMenuCalendar_VisibleChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void CAN_Handler3::BtnMenuImmobilizer_VisibleChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void CAN_Handler3::BtnMenuHeating_VisibleChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void CAN_Handler3::BtnMenuMonitor_VisibleChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void CAN_Handler3::BtnMenuMaintenance_VisibleChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void CAN_Handler3::BtnMenuFiltrRegen_VisibleChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void CAN_Handler3::AdjustAddCtrlCircuit1_VisibleChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void CAN_Handler3::AdjustAddCtrlCircuit2_VisibleChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}

// SIGNAL 16
void CAN_Handler3::AdjustRCSForward_VisibleChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}

// SIGNAL 17
void CAN_Handler3::AdjustRCSBackward_VisibleChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 17, _a);
}

// SIGNAL 18
void CAN_Handler3::AdjustAutoEngineStopTime_VisibleChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 18, _a);
}

// SIGNAL 19
void CAN_Handler3::BtnFctDateTimeAutomatic_VisibleChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 19, _a);
}

// SIGNAL 20
void CAN_Handler3::BtnImmobActivation_VisibleChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 20, _a);
}

// SIGNAL 21
void CAN_Handler3::BtnImmobOwnerPin_VisibleChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 21, _a);
}

// SIGNAL 22
void CAN_Handler3::BtnImmobDriverPin_VisibleChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 22, _a);
}

// SIGNAL 23
void CAN_Handler3::BtnImmobTransPin_VisibleChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 23, _a);
}

// SIGNAL 24
void CAN_Handler3::BtnImmobTimeToActivation_VisibleChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 24, _a);
}

// SIGNAL 25
void CAN_Handler3::BtnDiagMCU_VisibleChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 25, _a);
}

// SIGNAL 26
void CAN_Handler3::BtnDiagTCU_VisibleChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 26, _a);
}

// SIGNAL 27
void CAN_Handler3::BtnDiagECU_VisibleChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 27, _a);
}

// SIGNAL 28
void CAN_Handler3::dmdDrvPedlChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 28, _a);
}

// SIGNAL 29
void CAN_Handler3::dmdInchPedlChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 29, _a);
}

// SIGNAL 30
void CAN_Handler3::dmdCrpPotiChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 30, _a);
}

// SIGNAL 31
void CAN_Handler3::dmdHndThrChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 31, _a);
}

// SIGNAL 32
void CAN_Handler3::SarDateChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 32, _a);
}

// SIGNAL 33
void CAN_Handler3::SarTimeChanged(uint32_t _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 33, _a);
}

// SIGNAL 34
void CAN_Handler3::StartRelayChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 34, _a);
}

// SIGNAL 35
void CAN_Handler3::RailPChanged(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 35, _a);
}

// SIGNAL 36
void CAN_Handler3::EngSpeedChanged(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 36, _a);
}

// SIGNAL 37
void CAN_Handler3::FuelPerHourChanged(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 37, _a);
}

// SIGNAL 38
void CAN_Handler3::engPercentLoadAtCurrentSpeedChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 38, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

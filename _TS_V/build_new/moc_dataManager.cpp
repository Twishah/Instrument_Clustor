/****************************************************************************
** Meta object code from reading C++ file 'dataManager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../backend/dataManager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dataManager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DataManager_t {
    QByteArrayData data[158];
    char stringdata0[2889];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DataManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DataManager_t qt_meta_stringdata_DataManager = {
    {
QT_MOC_LITERAL(0, 0, 11), // "DataManager"
QT_MOC_LITERAL(1, 12, 21), // "engineStopTimeChanged"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 8), // "stopTime"
QT_MOC_LITERAL(4, 44, 15), // "indexPTOChanged"
QT_MOC_LITERAL(5, 60, 8), // "indexPTO"
QT_MOC_LITERAL(6, 69, 21), // "indexLockStateChanged"
QT_MOC_LITERAL(7, 91, 14), // "indexLockState"
QT_MOC_LITERAL(8, 106, 11), // "dateChanged"
QT_MOC_LITERAL(9, 118, 4), // "date"
QT_MOC_LITERAL(10, 123, 11), // "timeChanged"
QT_MOC_LITERAL(11, 135, 4), // "time"
QT_MOC_LITERAL(12, 140, 23), // "timePeriodFormatChanged"
QT_MOC_LITERAL(13, 164, 16), // "timePeriodFormat"
QT_MOC_LITERAL(14, 181, 19), // "dateTimeModeChanged"
QT_MOC_LITERAL(15, 201, 12), // "dateTimeMode"
QT_MOC_LITERAL(16, 214, 17), // "formatHourChanged"
QT_MOC_LITERAL(17, 232, 10), // "formatHour"
QT_MOC_LITERAL(18, 243, 25), // "daylightSavingTimeChanged"
QT_MOC_LITERAL(19, 269, 18), // "daylightSavingTime"
QT_MOC_LITERAL(20, 288, 15), // "timeZoneChanged"
QT_MOC_LITERAL(21, 304, 8), // "timeZone"
QT_MOC_LITERAL(22, 313, 19), // "soundSettingChanged"
QT_MOC_LITERAL(23, 333, 12), // "soundSetting"
QT_MOC_LITERAL(24, 346, 28), // "interval_hydraulicOilChanged"
QT_MOC_LITERAL(25, 375, 21), // "interval_hydraulicOil"
QT_MOC_LITERAL(26, 397, 37), // "interval_hydraulicOilRetFilte..."
QT_MOC_LITERAL(27, 435, 30), // "interval_hydraulicOilRetFilter"
QT_MOC_LITERAL(28, 466, 41), // "interval_hydraulicOilRetLineF..."
QT_MOC_LITERAL(29, 508, 34), // "interval_hydraulicOilRetLineF..."
QT_MOC_LITERAL(30, 543, 34), // "interval_travelReductionOilCh..."
QT_MOC_LITERAL(31, 578, 27), // "interval_travelReductionOil"
QT_MOC_LITERAL(32, 606, 20), // "mecHist_nbMaxChanged"
QT_MOC_LITERAL(33, 627, 13), // "mecHist_nbMax"
QT_MOC_LITERAL(34, 641, 15), // "tempUnitChanged"
QT_MOC_LITERAL(35, 657, 13), // "tempIsCelsius"
QT_MOC_LITERAL(36, 671, 17), // "rcsForwardChanged"
QT_MOC_LITERAL(37, 689, 8), // "rcsValue"
QT_MOC_LITERAL(38, 698, 18), // "rcsBackwardChanged"
QT_MOC_LITERAL(39, 717, 18), // "immobActiveChanged"
QT_MOC_LITERAL(40, 736, 13), // "isImmobActive"
QT_MOC_LITERAL(41, 750, 26), // "immobActivationTimeChanged"
QT_MOC_LITERAL(42, 777, 19), // "ImmobActivationTime"
QT_MOC_LITERAL(43, 797, 16), // "speedUnitChanged"
QT_MOC_LITERAL(44, 814, 10), // "speedIsKmh"
QT_MOC_LITERAL(45, 825, 19), // "pressureUnitChanged"
QT_MOC_LITERAL(46, 845, 8), // "pressure"
QT_MOC_LITERAL(47, 854, 17), // "volumeUnitChanged"
QT_MOC_LITERAL(48, 872, 6), // "volume"
QT_MOC_LITERAL(49, 879, 23), // "supressBuzzerDtcChanged"
QT_MOC_LITERAL(50, 903, 16), // "supressBuzzerDTC"
QT_MOC_LITERAL(51, 920, 33), // "supressBuzzerFlashingLightCha..."
QT_MOC_LITERAL(52, 954, 26), // "supressBuzzerFlashingLight"
QT_MOC_LITERAL(53, 981, 16), // "getIndexLanguage"
QT_MOC_LITERAL(54, 998, 14), // "selectLanguage"
QT_MOC_LITERAL(55, 1013, 13), // "language_code"
QT_MOC_LITERAL(56, 1027, 5), // "index"
QT_MOC_LITERAL(57, 1033, 14), // "getPtoSettings"
QT_MOC_LITERAL(58, 1048, 15), // "Flow_limit_acc*"
QT_MOC_LITERAL(59, 1064, 9), // "index_acc"
QT_MOC_LITERAL(60, 1074, 15), // "savePtoSettings"
QT_MOC_LITERAL(61, 1090, 12), // "get_indexPTO"
QT_MOC_LITERAL(62, 1103, 13), // "save_indexPTO"
QT_MOC_LITERAL(63, 1117, 16), // "getIndexStopTime"
QT_MOC_LITERAL(64, 1134, 18), // "saveEngineStopTime"
QT_MOC_LITERAL(65, 1153, 18), // "get_engineStopTime"
QT_MOC_LITERAL(66, 1172, 13), // "getPreHeating"
QT_MOC_LITERAL(67, 1186, 21), // "Pre_heating_settings*"
QT_MOC_LITERAL(68, 1208, 22), // "savePreHeatingSettings"
QT_MOC_LITERAL(69, 1231, 17), // "getPreHeatingDate"
QT_MOC_LITERAL(70, 1249, 17), // "setPreHeatingDate"
QT_MOC_LITERAL(71, 1267, 5), // "state"
QT_MOC_LITERAL(72, 1273, 18), // "get_indexLockState"
QT_MOC_LITERAL(73, 1292, 12), // "saveLockSate"
QT_MOC_LITERAL(74, 1305, 15), // "getDateTimeMode"
QT_MOC_LITERAL(75, 1321, 16), // "saveDateTimeMode"
QT_MOC_LITERAL(76, 1338, 13), // "getFormatHour"
QT_MOC_LITERAL(77, 1352, 14), // "saveFormatHour"
QT_MOC_LITERAL(78, 1367, 21), // "getDaylightSavingTime"
QT_MOC_LITERAL(79, 1389, 22), // "saveDaylightSavingTime"
QT_MOC_LITERAL(80, 1412, 15), // "getSoundSetting"
QT_MOC_LITERAL(81, 1428, 16), // "saveSoundSetting"
QT_MOC_LITERAL(82, 1445, 11), // "getTimeZone"
QT_MOC_LITERAL(83, 1457, 16), // "getTimeZoneIndex"
QT_MOC_LITERAL(84, 1474, 12), // "saveTimeZone"
QT_MOC_LITERAL(85, 1487, 16), // "setTimeZoneIndex"
QT_MOC_LITERAL(86, 1504, 16), // "getDayBrightness"
QT_MOC_LITERAL(87, 1521, 18), // "getNightBrightness"
QT_MOC_LITERAL(88, 1540, 16), // "setDayBrightness"
QT_MOC_LITERAL(89, 1557, 13), // "dayBrightness"
QT_MOC_LITERAL(90, 1571, 18), // "setNightBrightness"
QT_MOC_LITERAL(91, 1590, 15), // "nightBrightness"
QT_MOC_LITERAL(92, 1606, 14), // "saveBrightness"
QT_MOC_LITERAL(93, 1621, 25), // "get_interval_hydraulicOil"
QT_MOC_LITERAL(94, 1647, 26), // "save_interval_hydraulicOil"
QT_MOC_LITERAL(95, 1674, 34), // "get_interval_hydraulicOilRetF..."
QT_MOC_LITERAL(96, 1709, 35), // "save_interval_hydraulicOilRet..."
QT_MOC_LITERAL(97, 1745, 38), // "get_interval_hydraulicOilRetL..."
QT_MOC_LITERAL(98, 1784, 39), // "save_interval_hydraulicOilRet..."
QT_MOC_LITERAL(99, 1824, 31), // "get_interval_travelReductionOil"
QT_MOC_LITERAL(100, 1856, 32), // "save_interval_travelReductionOil"
QT_MOC_LITERAL(101, 1889, 23), // "get_maintenance_history"
QT_MOC_LITERAL(102, 1913, 19), // "MaintenanceHistory*"
QT_MOC_LITERAL(103, 1933, 14), // "index_mainHist"
QT_MOC_LITERAL(104, 1948, 24), // "save_maintenance_history"
QT_MOC_LITERAL(105, 1973, 20), // "get_mechanic_history"
QT_MOC_LITERAL(106, 1994, 16), // "MechanicHistory*"
QT_MOC_LITERAL(107, 2011, 13), // "index_mecHist"
QT_MOC_LITERAL(108, 2025, 21), // "save_mechanic_history"
QT_MOC_LITERAL(109, 2047, 17), // "get_mecHist_nbMax"
QT_MOC_LITERAL(110, 2065, 18), // "save_mecHist_nbMax"
QT_MOC_LITERAL(111, 2084, 20), // "set_mechanic_history"
QT_MOC_LITERAL(112, 2105, 9), // "hourmeter"
QT_MOC_LITERAL(113, 2115, 18), // "getOpTimeResetDate"
QT_MOC_LITERAL(114, 2134, 18), // "getOpTimeResetTime"
QT_MOC_LITERAL(115, 2153, 23), // "getOpTimeResetHourmeter"
QT_MOC_LITERAL(116, 2177, 18), // "setOpTimeResetDate"
QT_MOC_LITERAL(117, 2196, 9), // "resetDate"
QT_MOC_LITERAL(118, 2206, 18), // "setOpTimeResetTime"
QT_MOC_LITERAL(119, 2225, 9), // "resetTime"
QT_MOC_LITERAL(120, 2235, 23), // "setOpTimeResetHourmeter"
QT_MOC_LITERAL(121, 2259, 16), // "hourmeterAtReset"
QT_MOC_LITERAL(122, 2276, 20), // "saveOpTimeResetEvent"
QT_MOC_LITERAL(123, 2297, 20), // "getTempUnitIsCelsius"
QT_MOC_LITERAL(124, 2318, 19), // "saveTemperatureUnit"
QT_MOC_LITERAL(125, 2338, 13), // "getRCSForward"
QT_MOC_LITERAL(126, 2352, 14), // "getRCSBackward"
QT_MOC_LITERAL(127, 2367, 13), // "setRCSForward"
QT_MOC_LITERAL(128, 2381, 10), // "rcsForward"
QT_MOC_LITERAL(129, 2392, 14), // "setRCSBackward"
QT_MOC_LITERAL(130, 2407, 11), // "rcsBackward"
QT_MOC_LITERAL(131, 2419, 15), // "saveRCSSettings"
QT_MOC_LITERAL(132, 2435, 17), // "get_isImmobActive"
QT_MOC_LITERAL(133, 2453, 23), // "get_ImmobActivationTime"
QT_MOC_LITERAL(134, 2477, 15), // "set_immobActive"
QT_MOC_LITERAL(135, 2493, 8), // "isActive"
QT_MOC_LITERAL(136, 2502, 23), // "set_immobActivationTime"
QT_MOC_LITERAL(137, 2526, 7), // "minutes"
QT_MOC_LITERAL(138, 2534, 15), // "saveImmobActive"
QT_MOC_LITERAL(139, 2550, 23), // "saveImmobActivationTime"
QT_MOC_LITERAL(140, 2574, 19), // "getSupressBuzzerDTC"
QT_MOC_LITERAL(141, 2594, 20), // "saveSupressBuzzerDTC"
QT_MOC_LITERAL(142, 2615, 29), // "getSupressBuzzerFlashingLight"
QT_MOC_LITERAL(143, 2645, 30), // "saveSupressBuzzerFlashingLight"
QT_MOC_LITERAL(144, 2676, 17), // "getSpeedUnitIsKmh"
QT_MOC_LITERAL(145, 2694, 13), // "saveSpeedUnit"
QT_MOC_LITERAL(146, 2708, 15), // "getPressureUnit"
QT_MOC_LITERAL(147, 2724, 16), // "savePressureUnit"
QT_MOC_LITERAL(148, 2741, 13), // "getVolumeUnit"
QT_MOC_LITERAL(149, 2755, 14), // "saveVolumeUnit"
QT_MOC_LITERAL(150, 2770, 14), // "engineStopTime"
QT_MOC_LITERAL(151, 2785, 16), // "supressBuzzerDtc"
QT_MOC_LITERAL(152, 2802, 17), // "tempUnitIsCelsius"
QT_MOC_LITERAL(153, 2820, 9), // "rcsFoward"
QT_MOC_LITERAL(154, 2830, 19), // "immobActivationTime"
QT_MOC_LITERAL(155, 2850, 14), // "speedUnitIsKmh"
QT_MOC_LITERAL(156, 2865, 12), // "pressureUnit"
QT_MOC_LITERAL(157, 2878, 10) // "volumeUnit"

    },
    "DataManager\0engineStopTimeChanged\0\0"
    "stopTime\0indexPTOChanged\0indexPTO\0"
    "indexLockStateChanged\0indexLockState\0"
    "dateChanged\0date\0timeChanged\0time\0"
    "timePeriodFormatChanged\0timePeriodFormat\0"
    "dateTimeModeChanged\0dateTimeMode\0"
    "formatHourChanged\0formatHour\0"
    "daylightSavingTimeChanged\0daylightSavingTime\0"
    "timeZoneChanged\0timeZone\0soundSettingChanged\0"
    "soundSetting\0interval_hydraulicOilChanged\0"
    "interval_hydraulicOil\0"
    "interval_hydraulicOilRetFilterChanged\0"
    "interval_hydraulicOilRetFilter\0"
    "interval_hydraulicOilRetLineFilterChanged\0"
    "interval_hydraulicOilRetLineFilter\0"
    "interval_travelReductionOilChanged\0"
    "interval_travelReductionOil\0"
    "mecHist_nbMaxChanged\0mecHist_nbMax\0"
    "tempUnitChanged\0tempIsCelsius\0"
    "rcsForwardChanged\0rcsValue\0"
    "rcsBackwardChanged\0immobActiveChanged\0"
    "isImmobActive\0immobActivationTimeChanged\0"
    "ImmobActivationTime\0speedUnitChanged\0"
    "speedIsKmh\0pressureUnitChanged\0pressure\0"
    "volumeUnitChanged\0volume\0"
    "supressBuzzerDtcChanged\0supressBuzzerDTC\0"
    "supressBuzzerFlashingLightChanged\0"
    "supressBuzzerFlashingLight\0getIndexLanguage\0"
    "selectLanguage\0language_code\0index\0"
    "getPtoSettings\0Flow_limit_acc*\0index_acc\0"
    "savePtoSettings\0get_indexPTO\0save_indexPTO\0"
    "getIndexStopTime\0saveEngineStopTime\0"
    "get_engineStopTime\0getPreHeating\0"
    "Pre_heating_settings*\0savePreHeatingSettings\0"
    "getPreHeatingDate\0setPreHeatingDate\0"
    "state\0get_indexLockState\0saveLockSate\0"
    "getDateTimeMode\0saveDateTimeMode\0"
    "getFormatHour\0saveFormatHour\0"
    "getDaylightSavingTime\0saveDaylightSavingTime\0"
    "getSoundSetting\0saveSoundSetting\0"
    "getTimeZone\0getTimeZoneIndex\0saveTimeZone\0"
    "setTimeZoneIndex\0getDayBrightness\0"
    "getNightBrightness\0setDayBrightness\0"
    "dayBrightness\0setNightBrightness\0"
    "nightBrightness\0saveBrightness\0"
    "get_interval_hydraulicOil\0"
    "save_interval_hydraulicOil\0"
    "get_interval_hydraulicOilRetFilter\0"
    "save_interval_hydraulicOilRetFilter\0"
    "get_interval_hydraulicOilRetLineFilter\0"
    "save_interval_hydraulicOilRetLineFilter\0"
    "get_interval_travelReductionOil\0"
    "save_interval_travelReductionOil\0"
    "get_maintenance_history\0MaintenanceHistory*\0"
    "index_mainHist\0save_maintenance_history\0"
    "get_mechanic_history\0MechanicHistory*\0"
    "index_mecHist\0save_mechanic_history\0"
    "get_mecHist_nbMax\0save_mecHist_nbMax\0"
    "set_mechanic_history\0hourmeter\0"
    "getOpTimeResetDate\0getOpTimeResetTime\0"
    "getOpTimeResetHourmeter\0setOpTimeResetDate\0"
    "resetDate\0setOpTimeResetTime\0resetTime\0"
    "setOpTimeResetHourmeter\0hourmeterAtReset\0"
    "saveOpTimeResetEvent\0getTempUnitIsCelsius\0"
    "saveTemperatureUnit\0getRCSForward\0"
    "getRCSBackward\0setRCSForward\0rcsForward\0"
    "setRCSBackward\0rcsBackward\0saveRCSSettings\0"
    "get_isImmobActive\0get_ImmobActivationTime\0"
    "set_immobActive\0isActive\0"
    "set_immobActivationTime\0minutes\0"
    "saveImmobActive\0saveImmobActivationTime\0"
    "getSupressBuzzerDTC\0saveSupressBuzzerDTC\0"
    "getSupressBuzzerFlashingLight\0"
    "saveSupressBuzzerFlashingLight\0"
    "getSpeedUnitIsKmh\0saveSpeedUnit\0"
    "getPressureUnit\0savePressureUnit\0"
    "getVolumeUnit\0saveVolumeUnit\0"
    "engineStopTime\0supressBuzzerDtc\0"
    "tempUnitIsCelsius\0rcsFoward\0"
    "immobActivationTime\0speedUnitIsKmh\0"
    "pressureUnit\0volumeUnit"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DataManager[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
     103,   14, // methods
      23,  728, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      26,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  529,    2, 0x06 /* Public */,
       4,    1,  532,    2, 0x06 /* Public */,
       6,    1,  535,    2, 0x06 /* Public */,
       8,    1,  538,    2, 0x06 /* Public */,
      10,    1,  541,    2, 0x06 /* Public */,
      12,    1,  544,    2, 0x06 /* Public */,
      14,    1,  547,    2, 0x06 /* Public */,
      16,    1,  550,    2, 0x06 /* Public */,
      18,    1,  553,    2, 0x06 /* Public */,
      20,    1,  556,    2, 0x06 /* Public */,
      22,    1,  559,    2, 0x06 /* Public */,
      24,    1,  562,    2, 0x06 /* Public */,
      26,    1,  565,    2, 0x06 /* Public */,
      28,    1,  568,    2, 0x06 /* Public */,
      30,    1,  571,    2, 0x06 /* Public */,
      32,    1,  574,    2, 0x06 /* Public */,
      34,    1,  577,    2, 0x06 /* Public */,
      36,    1,  580,    2, 0x06 /* Public */,
      38,    1,  583,    2, 0x06 /* Public */,
      39,    1,  586,    2, 0x06 /* Public */,
      41,    1,  589,    2, 0x06 /* Public */,
      43,    1,  592,    2, 0x06 /* Public */,
      45,    1,  595,    2, 0x06 /* Public */,
      47,    1,  598,    2, 0x06 /* Public */,
      49,    1,  601,    2, 0x06 /* Public */,
      51,    1,  604,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
      53,    0,  607,    2, 0x02 /* Public */,
      54,    2,  608,    2, 0x02 /* Public */,
      57,    1,  613,    2, 0x02 /* Public */,
      60,    0,  616,    2, 0x02 /* Public */,
      61,    0,  617,    2, 0x02 /* Public */,
      62,    0,  618,    2, 0x02 /* Public */,
      63,    0,  619,    2, 0x02 /* Public */,
      64,    0,  620,    2, 0x02 /* Public */,
      65,    0,  621,    2, 0x02 /* Public */,
      66,    0,  622,    2, 0x02 /* Public */,
      68,    0,  623,    2, 0x02 /* Public */,
      69,    1,  624,    2, 0x02 /* Public */,
      70,    2,  627,    2, 0x02 /* Public */,
      72,    0,  632,    2, 0x02 /* Public */,
      73,    0,  633,    2, 0x02 /* Public */,
      74,    0,  634,    2, 0x02 /* Public */,
      75,    0,  635,    2, 0x02 /* Public */,
      76,    0,  636,    2, 0x02 /* Public */,
      77,    0,  637,    2, 0x02 /* Public */,
      78,    0,  638,    2, 0x02 /* Public */,
      79,    0,  639,    2, 0x02 /* Public */,
      80,    0,  640,    2, 0x02 /* Public */,
      81,    0,  641,    2, 0x02 /* Public */,
      82,    0,  642,    2, 0x02 /* Public */,
      83,    0,  643,    2, 0x02 /* Public */,
      84,    0,  644,    2, 0x02 /* Public */,
      85,    1,  645,    2, 0x02 /* Public */,
      86,    0,  648,    2, 0x02 /* Public */,
      87,    0,  649,    2, 0x02 /* Public */,
      88,    1,  650,    2, 0x02 /* Public */,
      90,    1,  653,    2, 0x02 /* Public */,
      92,    0,  656,    2, 0x02 /* Public */,
      93,    0,  657,    2, 0x02 /* Public */,
      94,    0,  658,    2, 0x02 /* Public */,
      95,    0,  659,    2, 0x02 /* Public */,
      96,    0,  660,    2, 0x02 /* Public */,
      97,    0,  661,    2, 0x02 /* Public */,
      98,    0,  662,    2, 0x02 /* Public */,
      99,    0,  663,    2, 0x02 /* Public */,
     100,    0,  664,    2, 0x02 /* Public */,
     101,    1,  665,    2, 0x02 /* Public */,
     104,    0,  668,    2, 0x02 /* Public */,
     105,    1,  669,    2, 0x02 /* Public */,
     108,    0,  672,    2, 0x02 /* Public */,
     109,    0,  673,    2, 0x02 /* Public */,
     110,    0,  674,    2, 0x02 /* Public */,
     111,    4,  675,    2, 0x02 /* Public */,
     113,    0,  684,    2, 0x02 /* Public */,
     114,    0,  685,    2, 0x02 /* Public */,
     115,    0,  686,    2, 0x02 /* Public */,
     116,    1,  687,    2, 0x02 /* Public */,
     118,    1,  690,    2, 0x02 /* Public */,
     120,    1,  693,    2, 0x02 /* Public */,
     122,    0,  696,    2, 0x02 /* Public */,
     123,    0,  697,    2, 0x02 /* Public */,
     124,    0,  698,    2, 0x02 /* Public */,
     125,    0,  699,    2, 0x02 /* Public */,
     126,    0,  700,    2, 0x02 /* Public */,
     127,    1,  701,    2, 0x02 /* Public */,
     129,    1,  704,    2, 0x02 /* Public */,
     131,    0,  707,    2, 0x02 /* Public */,
     132,    0,  708,    2, 0x02 /* Public */,
     133,    0,  709,    2, 0x02 /* Public */,
     134,    1,  710,    2, 0x02 /* Public */,
     136,    1,  713,    2, 0x02 /* Public */,
     138,    0,  716,    2, 0x02 /* Public */,
     139,    0,  717,    2, 0x02 /* Public */,
     140,    0,  718,    2, 0x02 /* Public */,
     141,    0,  719,    2, 0x02 /* Public */,
     142,    0,  720,    2, 0x02 /* Public */,
     143,    0,  721,    2, 0x02 /* Public */,
     144,    0,  722,    2, 0x02 /* Public */,
     145,    0,  723,    2, 0x02 /* Public */,
     146,    0,  724,    2, 0x02 /* Public */,
     147,    0,  725,    2, 0x02 /* Public */,
     148,    0,  726,    2, 0x02 /* Public */,
     149,    0,  727,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::Bool,   13,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void, QMetaType::QString,   21,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void, QMetaType::Int,   25,
    QMetaType::Void, QMetaType::Int,   27,
    QMetaType::Void, QMetaType::Int,   29,
    QMetaType::Void, QMetaType::Int,   31,
    QMetaType::Void, QMetaType::Int,   33,
    QMetaType::Void, QMetaType::Int,   35,
    QMetaType::Void, QMetaType::Int,   37,
    QMetaType::Void, QMetaType::Int,   37,
    QMetaType::Void, QMetaType::Int,   40,
    QMetaType::Void, QMetaType::Int,   42,
    QMetaType::Void, QMetaType::Int,   44,
    QMetaType::Void, QMetaType::Int,   46,
    QMetaType::Void, QMetaType::Int,   48,
    QMetaType::Void, QMetaType::Int,   50,
    QMetaType::Void, QMetaType::Int,   52,

 // methods: parameters
    QMetaType::Int,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   55,   56,
    0x80000000 | 58, QMetaType::Int,   59,
    QMetaType::Void,
    QMetaType::Int,
    QMetaType::Void,
    QMetaType::Int,
    QMetaType::Void,
    QMetaType::Int,
    0x80000000 | 67,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::Int,   56,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   56,   71,
    QMetaType::Int,
    QMetaType::Void,
    QMetaType::Int,
    QMetaType::Void,
    QMetaType::Int,
    QMetaType::Void,
    QMetaType::Int,
    QMetaType::Void,
    QMetaType::Int,
    QMetaType::Void,
    QMetaType::QString,
    QMetaType::Int,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   56,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,   89,
    QMetaType::Void, QMetaType::Int,   91,
    QMetaType::Void,
    QMetaType::Int,
    QMetaType::Void,
    QMetaType::Int,
    QMetaType::Void,
    QMetaType::Int,
    QMetaType::Void,
    QMetaType::Int,
    QMetaType::Void,
    0x80000000 | 102, QMetaType::Int,  103,
    QMetaType::Void,
    0x80000000 | 106, QMetaType::Int,  107,
    QMetaType::Void,
    QMetaType::Int,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::Int,  107,    9,   11,  112,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::Double,
    QMetaType::Void, QMetaType::QString,  117,
    QMetaType::Void, QMetaType::QString,  119,
    QMetaType::Void, QMetaType::Double,  121,
    QMetaType::Void,
    QMetaType::Int,
    QMetaType::Void,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,  128,
    QMetaType::Void, QMetaType::Int,  130,
    QMetaType::Void,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,  135,
    QMetaType::Void, QMetaType::Int,  137,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Int,
    QMetaType::Void,
    QMetaType::Int,
    QMetaType::Void,
    QMetaType::Int,
    QMetaType::Void,
    QMetaType::Int,
    QMetaType::Void,
    QMetaType::Int,
    QMetaType::Void,

 // properties: name, type, flags
     150, QMetaType::Int, 0x00495003,
       5, QMetaType::Int, 0x00495003,
       7, QMetaType::Int, 0x00495003,
      15, QMetaType::Int, 0x00495103,
      17, QMetaType::Int, 0x00495103,
      19, QMetaType::Int, 0x00495103,
      21, QMetaType::QString, 0x00495103,
      23, QMetaType::Int, 0x00495103,
     151, QMetaType::Int, 0x00495003,
      52, QMetaType::Int, 0x00495103,
      25, QMetaType::Int, 0x00495003,
      27, QMetaType::Int, 0x00495003,
      29, QMetaType::Int, 0x00495003,
      31, QMetaType::Int, 0x00495003,
      33, QMetaType::Int, 0x00495003,
     152, QMetaType::Int, 0x00495003,
     153, QMetaType::Int, 0x00495003,
     130, QMetaType::Int, 0x00495003,
      40, QMetaType::Int, 0x00495003,
     154, QMetaType::Int, 0x00495003,
     155, QMetaType::Int, 0x00495103,
     156, QMetaType::Int, 0x00495103,
     157, QMetaType::Int, 0x00495103,

 // properties: notify_signal_id
       0,
       1,
       2,
       6,
       7,
       8,
       9,
      10,
      24,
      25,
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

       0        // eod
};

void DataManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DataManager *_t = static_cast<DataManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->engineStopTimeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->indexPTOChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->indexLockStateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->dateChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->timeChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->timePeriodFormatChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->dateTimeModeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->formatHourChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->daylightSavingTimeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->timeZoneChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->soundSettingChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->interval_hydraulicOilChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->interval_hydraulicOilRetFilterChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->interval_hydraulicOilRetLineFilterChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->interval_travelReductionOilChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->mecHist_nbMaxChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->tempUnitChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->rcsForwardChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: _t->rcsBackwardChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: _t->immobActiveChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 20: _t->immobActivationTimeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 21: _t->speedUnitChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: _t->pressureUnitChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 23: _t->volumeUnitChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 24: _t->supressBuzzerDtcChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 25: _t->supressBuzzerFlashingLightChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 26: { int _r = _t->getIndexLanguage();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 27: _t->selectLanguage((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 28: { Flow_limit_acc* _r = _t->getPtoSettings((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< Flow_limit_acc**>(_a[0]) = std::move(_r); }  break;
        case 29: _t->savePtoSettings(); break;
        case 30: { int _r = _t->get_indexPTO();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 31: _t->save_indexPTO(); break;
        case 32: { int _r = _t->getIndexStopTime();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 33: _t->saveEngineStopTime(); break;
        case 34: { int _r = _t->get_engineStopTime();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 35: { Pre_heating_settings* _r = _t->getPreHeating();
            if (_a[0]) *reinterpret_cast< Pre_heating_settings**>(_a[0]) = std::move(_r); }  break;
        case 36: _t->savePreHeatingSettings(); break;
        case 37: { bool _r = _t->getPreHeatingDate((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 38: _t->setPreHeatingDate((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 39: { int _r = _t->get_indexLockState();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 40: _t->saveLockSate(); break;
        case 41: { int _r = _t->getDateTimeMode();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 42: _t->saveDateTimeMode(); break;
        case 43: { int _r = _t->getFormatHour();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 44: _t->saveFormatHour(); break;
        case 45: { int _r = _t->getDaylightSavingTime();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 46: _t->saveDaylightSavingTime(); break;
        case 47: { int _r = _t->getSoundSetting();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 48: _t->saveSoundSetting(); break;
        case 49: { QString _r = _t->getTimeZone();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 50: { int _r = _t->getTimeZoneIndex();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 51: _t->saveTimeZone(); break;
        case 52: _t->setTimeZoneIndex((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 53: { int _r = _t->getDayBrightness();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 54: { int _r = _t->getNightBrightness();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 55: _t->setDayBrightness((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 56: _t->setNightBrightness((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 57: _t->saveBrightness(); break;
        case 58: { int _r = _t->get_interval_hydraulicOil();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 59: _t->save_interval_hydraulicOil(); break;
        case 60: { int _r = _t->get_interval_hydraulicOilRetFilter();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 61: _t->save_interval_hydraulicOilRetFilter(); break;
        case 62: { int _r = _t->get_interval_hydraulicOilRetLineFilter();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 63: _t->save_interval_hydraulicOilRetLineFilter(); break;
        case 64: { int _r = _t->get_interval_travelReductionOil();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 65: _t->save_interval_travelReductionOil(); break;
        case 66: { MaintenanceHistory* _r = _t->get_maintenance_history((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< MaintenanceHistory**>(_a[0]) = std::move(_r); }  break;
        case 67: _t->save_maintenance_history(); break;
        case 68: { MechanicHistory* _r = _t->get_mechanic_history((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< MechanicHistory**>(_a[0]) = std::move(_r); }  break;
        case 69: _t->save_mechanic_history(); break;
        case 70: { int _r = _t->get_mecHist_nbMax();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 71: _t->save_mecHist_nbMax(); break;
        case 72: _t->set_mechanic_history((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 73: { QString _r = _t->getOpTimeResetDate();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 74: { QString _r = _t->getOpTimeResetTime();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 75: { double _r = _t->getOpTimeResetHourmeter();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = std::move(_r); }  break;
        case 76: _t->setOpTimeResetDate((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 77: _t->setOpTimeResetTime((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 78: _t->setOpTimeResetHourmeter((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 79: _t->saveOpTimeResetEvent(); break;
        case 80: { int _r = _t->getTempUnitIsCelsius();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 81: _t->saveTemperatureUnit(); break;
        case 82: { int _r = _t->getRCSForward();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 83: { int _r = _t->getRCSBackward();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 84: _t->setRCSForward((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 85: _t->setRCSBackward((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 86: _t->saveRCSSettings(); break;
        case 87: { int _r = _t->get_isImmobActive();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 88: { int _r = _t->get_ImmobActivationTime();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 89: _t->set_immobActive((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 90: _t->set_immobActivationTime((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 91: _t->saveImmobActive(); break;
        case 92: _t->saveImmobActivationTime(); break;
        case 93: { int _r = _t->getSupressBuzzerDTC();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 94: _t->saveSupressBuzzerDTC(); break;
        case 95: { int _r = _t->getSupressBuzzerFlashingLight();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 96: _t->saveSupressBuzzerFlashingLight(); break;
        case 97: { int _r = _t->getSpeedUnitIsKmh();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 98: _t->saveSpeedUnit(); break;
        case 99: { int _r = _t->getPressureUnit();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 100: _t->savePressureUnit(); break;
        case 101: { int _r = _t->getVolumeUnit();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 102: _t->saveVolumeUnit(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DataManager::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataManager::engineStopTimeChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DataManager::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataManager::indexPTOChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (DataManager::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataManager::indexLockStateChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (DataManager::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataManager::dateChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (DataManager::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataManager::timeChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (DataManager::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataManager::timePeriodFormatChanged)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (DataManager::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataManager::dateTimeModeChanged)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (DataManager::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataManager::formatHourChanged)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (DataManager::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataManager::daylightSavingTimeChanged)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (DataManager::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataManager::timeZoneChanged)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (DataManager::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataManager::soundSettingChanged)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (DataManager::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataManager::interval_hydraulicOilChanged)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (DataManager::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataManager::interval_hydraulicOilRetFilterChanged)) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (DataManager::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataManager::interval_hydraulicOilRetLineFilterChanged)) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (DataManager::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataManager::interval_travelReductionOilChanged)) {
                *result = 14;
                return;
            }
        }
        {
            using _t = void (DataManager::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataManager::mecHist_nbMaxChanged)) {
                *result = 15;
                return;
            }
        }
        {
            using _t = void (DataManager::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataManager::tempUnitChanged)) {
                *result = 16;
                return;
            }
        }
        {
            using _t = void (DataManager::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataManager::rcsForwardChanged)) {
                *result = 17;
                return;
            }
        }
        {
            using _t = void (DataManager::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataManager::rcsBackwardChanged)) {
                *result = 18;
                return;
            }
        }
        {
            using _t = void (DataManager::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataManager::immobActiveChanged)) {
                *result = 19;
                return;
            }
        }
        {
            using _t = void (DataManager::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataManager::immobActivationTimeChanged)) {
                *result = 20;
                return;
            }
        }
        {
            using _t = void (DataManager::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataManager::speedUnitChanged)) {
                *result = 21;
                return;
            }
        }
        {
            using _t = void (DataManager::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataManager::pressureUnitChanged)) {
                *result = 22;
                return;
            }
        }
        {
            using _t = void (DataManager::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataManager::volumeUnitChanged)) {
                *result = 23;
                return;
            }
        }
        {
            using _t = void (DataManager::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataManager::supressBuzzerDtcChanged)) {
                *result = 24;
                return;
            }
        }
        {
            using _t = void (DataManager::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataManager::supressBuzzerFlashingLightChanged)) {
                *result = 25;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        DataManager *_t = static_cast<DataManager *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->engineStopTime(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->get_indexPTO(); break;
        case 2: *reinterpret_cast< int*>(_v) = _t->get_indexLockState(); break;
        case 3: *reinterpret_cast< int*>(_v) = _t->getDateTimeMode(); break;
        case 4: *reinterpret_cast< int*>(_v) = _t->getFormatHour(); break;
        case 5: *reinterpret_cast< int*>(_v) = _t->getDaylightSavingTime(); break;
        case 6: *reinterpret_cast< QString*>(_v) = _t->getTimeZone(); break;
        case 7: *reinterpret_cast< int*>(_v) = _t->getSoundSetting(); break;
        case 8: *reinterpret_cast< int*>(_v) = _t->getSupressBuzzerDTC(); break;
        case 9: *reinterpret_cast< int*>(_v) = _t->getSupressBuzzerFlashingLight(); break;
        case 10: *reinterpret_cast< int*>(_v) = _t->get_interval_hydraulicOil(); break;
        case 11: *reinterpret_cast< int*>(_v) = _t->get_interval_hydraulicOilRetFilter(); break;
        case 12: *reinterpret_cast< int*>(_v) = _t->get_interval_hydraulicOilRetLineFilter(); break;
        case 13: *reinterpret_cast< int*>(_v) = _t->get_interval_travelReductionOil(); break;
        case 14: *reinterpret_cast< int*>(_v) = _t->get_mecHist_nbMax(); break;
        case 15: *reinterpret_cast< int*>(_v) = _t->getTempUnitIsCelsius(); break;
        case 16: *reinterpret_cast< int*>(_v) = _t->getRCSForward(); break;
        case 17: *reinterpret_cast< int*>(_v) = _t->getRCSBackward(); break;
        case 18: *reinterpret_cast< int*>(_v) = _t->get_isImmobActive(); break;
        case 19: *reinterpret_cast< int*>(_v) = _t->get_ImmobActivationTime(); break;
        case 20: *reinterpret_cast< int*>(_v) = _t->getSpeedUnitIsKmh(); break;
        case 21: *reinterpret_cast< int*>(_v) = _t->getPressureUnit(); break;
        case 22: *reinterpret_cast< int*>(_v) = _t->getVolumeUnit(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        DataManager *_t = static_cast<DataManager *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->set_engineStopTime(*reinterpret_cast< int*>(_v)); break;
        case 1: _t->set_indexPTO(*reinterpret_cast< int*>(_v)); break;
        case 2: _t->set_indexLockState(*reinterpret_cast< int*>(_v)); break;
        case 3: _t->setDateTimeMode(*reinterpret_cast< int*>(_v)); break;
        case 4: _t->setFormatHour(*reinterpret_cast< int*>(_v)); break;
        case 5: _t->setDaylightSavingTime(*reinterpret_cast< int*>(_v)); break;
        case 6: _t->setTimeZone(*reinterpret_cast< QString*>(_v)); break;
        case 7: _t->setSoundSetting(*reinterpret_cast< int*>(_v)); break;
        case 8: _t->setSupressBuzzerDTC(*reinterpret_cast< int*>(_v)); break;
        case 9: _t->setSupressBuzzerFlashingLight(*reinterpret_cast< int*>(_v)); break;
        case 10: _t->set_interval_hydraulicOil(*reinterpret_cast< int*>(_v)); break;
        case 11: _t->set_interval_hydraulicOilRetFilter(*reinterpret_cast< int*>(_v)); break;
        case 12: _t->set_interval_hydraulicOilRetLineFilter(*reinterpret_cast< int*>(_v)); break;
        case 13: _t->set_interval_travelReductionOil(*reinterpret_cast< int*>(_v)); break;
        case 14: _t->set_mecHist_nbMax(*reinterpret_cast< int*>(_v)); break;
        case 15: _t->setTemperatureUnitCelsius(*reinterpret_cast< int*>(_v)); break;
        case 16: _t->setRCSForward(*reinterpret_cast< int*>(_v)); break;
        case 17: _t->setRCSBackward(*reinterpret_cast< int*>(_v)); break;
        case 18: _t->set_immobActive(*reinterpret_cast< int*>(_v)); break;
        case 19: _t->set_immobActivationTime(*reinterpret_cast< int*>(_v)); break;
        case 20: _t->setSpeedUnitIsKmh(*reinterpret_cast< int*>(_v)); break;
        case 21: _t->setPressureUnit(*reinterpret_cast< int*>(_v)); break;
        case 22: _t->setVolumeUnit(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject DataManager::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_DataManager.data,
    qt_meta_data_DataManager,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DataManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DataManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DataManager.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int DataManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 103)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 103;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 103)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 103;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 23;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 23;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 23;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 23;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 23;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 23;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void DataManager::engineStopTimeChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DataManager::indexPTOChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void DataManager::indexLockStateChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void DataManager::dateChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void DataManager::timeChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void DataManager::timePeriodFormatChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void DataManager::dateTimeModeChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void DataManager::formatHourChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void DataManager::daylightSavingTimeChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void DataManager::timeZoneChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void DataManager::soundSettingChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void DataManager::interval_hydraulicOilChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void DataManager::interval_hydraulicOilRetFilterChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void DataManager::interval_hydraulicOilRetLineFilterChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void DataManager::interval_travelReductionOilChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void DataManager::mecHist_nbMaxChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}

// SIGNAL 16
void DataManager::tempUnitChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}

// SIGNAL 17
void DataManager::rcsForwardChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 17, _a);
}

// SIGNAL 18
void DataManager::rcsBackwardChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 18, _a);
}

// SIGNAL 19
void DataManager::immobActiveChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 19, _a);
}

// SIGNAL 20
void DataManager::immobActivationTimeChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 20, _a);
}

// SIGNAL 21
void DataManager::speedUnitChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 21, _a);
}

// SIGNAL 22
void DataManager::pressureUnitChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 22, _a);
}

// SIGNAL 23
void DataManager::volumeUnitChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 23, _a);
}

// SIGNAL 24
void DataManager::supressBuzzerDtcChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 24, _a);
}

// SIGNAL 25
void DataManager::supressBuzzerFlashingLightChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 25, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

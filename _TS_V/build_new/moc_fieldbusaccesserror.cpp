/****************************************************************************
** Meta object code from reading C++ file 'fieldbusaccesserror.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../DataEngine/fieldbusaccesserror.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fieldbusaccesserror.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FieldbusAccessError_t {
    QByteArrayData data[133];
    char stringdata0[2142];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FieldbusAccessError_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FieldbusAccessError_t qt_meta_stringdata_FieldbusAccessError = {
    {
QT_MOC_LITERAL(0, 0, 19), // "FieldbusAccessError"
QT_MOC_LITERAL(1, 20, 10), // "busChanged"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 3), // "bus"
QT_MOC_LITERAL(4, 36, 12), // "levelChanged"
QT_MOC_LITERAL(5, 49, 10), // "ErrorLevel"
QT_MOC_LITERAL(6, 60, 5), // "level"
QT_MOC_LITERAL(7, 66, 11), // "codeChanged"
QT_MOC_LITERAL(8, 78, 9), // "ErrorCode"
QT_MOC_LITERAL(9, 88, 4), // "code"
QT_MOC_LITERAL(10, 93, 17), // "identifierChanged"
QT_MOC_LITERAL(11, 111, 15), // "ErrorIdentifier"
QT_MOC_LITERAL(12, 127, 2), // "id"
QT_MOC_LITERAL(13, 130, 21), // "additionalInfoChanged"
QT_MOC_LITERAL(14, 152, 7), // "addInfo"
QT_MOC_LITERAL(15, 160, 18), // "descriptionChanged"
QT_MOC_LITERAL(16, 179, 5), // "descr"
QT_MOC_LITERAL(17, 185, 18), // "errorExistsChanged"
QT_MOC_LITERAL(18, 204, 3), // "arg"
QT_MOC_LITERAL(19, 208, 13), // "errorReceived"
QT_MOC_LITERAL(20, 222, 14), // "startedChanged"
QT_MOC_LITERAL(21, 237, 1), // "t"
QT_MOC_LITERAL(22, 239, 12), // "endedChanged"
QT_MOC_LITERAL(23, 252, 17), // "ErrorCodeToString"
QT_MOC_LITERAL(24, 270, 19), // "errorLevelToQString"
QT_MOC_LITERAL(25, 290, 19), // "ErrorLevelToQString"
QT_MOC_LITERAL(26, 310, 11), // "idToQString"
QT_MOC_LITERAL(27, 322, 11), // "IdToQString"
QT_MOC_LITERAL(28, 334, 16), // "addInfoToQString"
QT_MOC_LITERAL(29, 351, 16), // "AddInfoToQString"
QT_MOC_LITERAL(30, 368, 10), // "identifier"
QT_MOC_LITERAL(31, 379, 14), // "additionalInfo"
QT_MOC_LITERAL(32, 394, 11), // "description"
QT_MOC_LITERAL(33, 406, 11), // "errorExists"
QT_MOC_LITERAL(34, 418, 7), // "started"
QT_MOC_LITERAL(35, 426, 5), // "ended"
QT_MOC_LITERAL(36, 432, 7), // "WARNING"
QT_MOC_LITERAL(37, 440, 5), // "ERROR"
QT_MOC_LITERAL(38, 446, 5), // "FATAL"
QT_MOC_LITERAL(39, 452, 2), // "OK"
QT_MOC_LITERAL(40, 455, 13), // "UNKNOWN_LEVEL"
QT_MOC_LITERAL(41, 469, 10), // "ERR_ERR_ID"
QT_MOC_LITERAL(42, 480, 10), // "DLL_ERR_ID"
QT_MOC_LITERAL(43, 491, 10), // "MEM_ERR_ID"
QT_MOC_LITERAL(44, 502, 10), // "TPL_ERR_ID"
QT_MOC_LITERAL(45, 513, 10), // "NWM_ERR_ID"
QT_MOC_LITERAL(46, 524, 10), // "APL_ERR_ID"
QT_MOC_LITERAL(47, 535, 10), // "CYC_ERR_ID"
QT_MOC_LITERAL(48, 546, 10), // "REQ_ERR_ID"
QT_MOC_LITERAL(49, 557, 10), // "L2C_ERR_ID"
QT_MOC_LITERAL(50, 568, 10), // "ADR_ERR_ID"
QT_MOC_LITERAL(51, 579, 11), // "NMEA_ERR_ID"
QT_MOC_LITERAL(52, 591, 10), // "CDP_ERR_ID"
QT_MOC_LITERAL(53, 602, 11), // "DIAG_ERR_ID"
QT_MOC_LITERAL(54, 614, 10), // "USR_ERR_ID"
QT_MOC_LITERAL(55, 625, 5), // "OK_ID"
QT_MOC_LITERAL(56, 631, 10), // "UNKNOWN_ID"
QT_MOC_LITERAL(57, 642, 21), // "ERR_ERR_INVALID_PARAM"
QT_MOC_LITERAL(58, 664, 15), // "DLL_ERR_TX_OVRN"
QT_MOC_LITERAL(59, 680, 17), // "DLL_ERR_START_CAN"
QT_MOC_LITERAL(60, 698, 17), // "DLL_ERR_RESET_CAN"
QT_MOC_LITERAL(61, 716, 16), // "DLL_ERR_INIT_CAN"
QT_MOC_LITERAL(62, 733, 12), // "DLL_ERR_BOFF"
QT_MOC_LITERAL(63, 746, 12), // "DLL_ERR_EPAS"
QT_MOC_LITERAL(64, 759, 12), // "DLL_ERR_EACT"
QT_MOC_LITERAL(65, 772, 11), // "DLL_ERR_DOI"
QT_MOC_LITERAL(66, 784, 15), // "DLL_ERR_RX_OVRN"
QT_MOC_LITERAL(67, 800, 20), // "MEM_ERR_ALLOC_MEMORY"
QT_MOC_LITERAL(68, 821, 19), // "MEM_ERR_FREE_MEMORY"
QT_MOC_LITERAL(69, 841, 15), // "TPL_ERR_TX_OVRN"
QT_MOC_LITERAL(70, 857, 19), // "TPL_ERR_CONF_FILTER"
QT_MOC_LITERAL(71, 877, 21), // "TPL_ERR_UNEXP_BAM_FRM"
QT_MOC_LITERAL(72, 899, 21), // "TPL_ERR_UNEXP_RTS_FRM"
QT_MOC_LITERAL(73, 921, 21), // "TPL_ERR_UNEXP_CTS_FRM"
QT_MOC_LITERAL(74, 943, 21), // "TPL_ERR_UNEXP_EOM_FRM"
QT_MOC_LITERAL(75, 965, 20), // "TPL_ERR_UNEXP_CA_FRM"
QT_MOC_LITERAL(76, 986, 20), // "TPL_ERR_UNEXP_DT_FRM"
QT_MOC_LITERAL(77, 1007, 15), // "TPL_ERR_RX_OVRN"
QT_MOC_LITERAL(78, 1023, 19), // "TPL_ERR_TX_TIMEOUT0"
QT_MOC_LITERAL(79, 1043, 19), // "TPL_ERR_TX_TIMEOUT2"
QT_MOC_LITERAL(80, 1063, 19), // "TPL_ERR_RX_TIMEOUT0"
QT_MOC_LITERAL(81, 1083, 19), // "TPL_ERR_RX_TIMEOUT1"
QT_MOC_LITERAL(82, 1103, 19), // "TPL_ERR_RX_TIMEOUT2"
QT_MOC_LITERAL(83, 1123, 15), // "TPL_ERR_RX_LONG"
QT_MOC_LITERAL(84, 1139, 16), // "TPL_ERR_SEND_MSG"
QT_MOC_LITERAL(85, 1156, 15), // "TPL_ERR_SEND_CA"
QT_MOC_LITERAL(86, 1172, 17), // "TPL_ERR_SEND_NACK"
QT_MOC_LITERAL(87, 1190, 18), // "NWM_ERR_DEVICE_REG"
QT_MOC_LITERAL(88, 1209, 19), // "NWM_ERR_INVALID_HDL"
QT_MOC_LITERAL(89, 1229, 20), // "NWM_ERR_INVALID_ADDR"
QT_MOC_LITERAL(90, 1250, 15), // "NWM_ERR_NO_COMM"
QT_MOC_LITERAL(91, 1266, 15), // "NWM_ERR_NO_ADDR"
QT_MOC_LITERAL(92, 1282, 17), // "NWM_ERR_LIST_FULL"
QT_MOC_LITERAL(93, 1300, 21), // "APL_ERR_TIME_EXCEEDED"
QT_MOC_LITERAL(94, 1322, 15), // "APL_ERR_TX_LONG"
QT_MOC_LITERAL(95, 1338, 17), // "APL_ERR_NO_MEMORY"
QT_MOC_LITERAL(96, 1356, 19), // "APL_ERR_REG_REQUEST"
QT_MOC_LITERAL(97, 1376, 18), // "APL_ERR_TX_NO_ADDR"
QT_MOC_LITERAL(98, 1395, 21), // "APL_ERR_INVALID_PARAM"
QT_MOC_LITERAL(99, 1417, 20), // "APL_ERR_REQ_RESPONSE"
QT_MOC_LITERAL(100, 1438, 23), // "CYC_ERR_NOT_INITIALIZED"
QT_MOC_LITERAL(101, 1462, 23), // "CYC_ERR_RX_REGISTRATION"
QT_MOC_LITERAL(102, 1486, 23), // "CYC_ERR_TX_REGISTRATION"
QT_MOC_LITERAL(103, 1510, 21), // "CYC_ERR_TIME_EXCEEDED"
QT_MOC_LITERAL(104, 1532, 18), // "CYC_ERR_RX_TIMEOUT"
QT_MOC_LITERAL(105, 1551, 22), // "CYC_ERR_TX_INVALID_HDL"
QT_MOC_LITERAL(106, 1574, 21), // "CYC_ERR_TX_QUEUE_OVRN"
QT_MOC_LITERAL(107, 1596, 25), // "CYC_ERR_RX_INVALID_LENGTH"
QT_MOC_LITERAL(108, 1622, 21), // "REQ_ERR_INVALID_PARAM"
QT_MOC_LITERAL(109, 1644, 21), // "CDP_ERR_TIME_EXCEEDED"
QT_MOC_LITERAL(110, 1666, 19), // "CDP_ERR_ADDR_FORMAT"
QT_MOC_LITERAL(111, 1686, 16), // "CDP_ERR_CONF_PGN"
QT_MOC_LITERAL(112, 1703, 19), // "CDP_ERR_UNKNOWN_PGN"
QT_MOC_LITERAL(113, 1723, 22), // "CDP_ERR_STATE_READY_TX"
QT_MOC_LITERAL(114, 1746, 22), // "CDP_ERR_STATE_READY_RX"
QT_MOC_LITERAL(115, 1769, 17), // "CDP_ERR_NO_MEMORY"
QT_MOC_LITERAL(116, 1787, 20), // "CDP_ERR_ALLOC_MEMORY"
QT_MOC_LITERAL(117, 1808, 19), // "CDP_ERR_FREE_MEMORY"
QT_MOC_LITERAL(118, 1828, 17), // "CDP_ERR_RX_LENGTH"
QT_MOC_LITERAL(119, 1846, 21), // "CDP_ERR_RX_TIMEOUT_FC"
QT_MOC_LITERAL(120, 1868, 21), // "CDP_ERR_RX_TIMEOUT_CF"
QT_MOC_LITERAL(121, 1890, 18), // "CDP_ERR_TX_TIMEOUT"
QT_MOC_LITERAL(122, 1909, 19), // "CDP_ERR_PCI_INVALID"
QT_MOC_LITERAL(123, 1929, 23), // "DIAG_ERR_MEM_ABORTED_TX"
QT_MOC_LITERAL(124, 1953, 23), // "DIAG_ERR_MEM_ABORTED_RX"
QT_MOC_LITERAL(125, 1977, 24), // "DIAG_ERR_MEM_ABORTED_KEY"
QT_MOC_LITERAL(126, 2002, 25), // "DIAG_ERR_MEM_ABORTED_DATA"
QT_MOC_LITERAL(127, 2028, 17), // "DIAG_ERR_MEM_BUSY"
QT_MOC_LITERAL(128, 2046, 24), // "DIAG_ERR_MEM_BUSY_FAILED"
QT_MOC_LITERAL(129, 2071, 24), // "DIAG_ERR_MEM_INVALID_MSG"
QT_MOC_LITERAL(130, 2096, 20), // "USR_ERR_REQ_RESPONSE"
QT_MOC_LITERAL(131, 2117, 14), // "UNKNOWN_ERR_ID"
QT_MOC_LITERAL(132, 2132, 9) // "OK_ERR_ID"

    },
    "FieldbusAccessError\0busChanged\0\0bus\0"
    "levelChanged\0ErrorLevel\0level\0codeChanged\0"
    "ErrorCode\0code\0identifierChanged\0"
    "ErrorIdentifier\0id\0additionalInfoChanged\0"
    "addInfo\0descriptionChanged\0descr\0"
    "errorExistsChanged\0arg\0errorReceived\0"
    "startedChanged\0t\0endedChanged\0"
    "ErrorCodeToString\0errorLevelToQString\0"
    "ErrorLevelToQString\0idToQString\0"
    "IdToQString\0addInfoToQString\0"
    "AddInfoToQString\0identifier\0additionalInfo\0"
    "description\0errorExists\0started\0ended\0"
    "WARNING\0ERROR\0FATAL\0OK\0UNKNOWN_LEVEL\0"
    "ERR_ERR_ID\0DLL_ERR_ID\0MEM_ERR_ID\0"
    "TPL_ERR_ID\0NWM_ERR_ID\0APL_ERR_ID\0"
    "CYC_ERR_ID\0REQ_ERR_ID\0L2C_ERR_ID\0"
    "ADR_ERR_ID\0NMEA_ERR_ID\0CDP_ERR_ID\0"
    "DIAG_ERR_ID\0USR_ERR_ID\0OK_ID\0UNKNOWN_ID\0"
    "ERR_ERR_INVALID_PARAM\0DLL_ERR_TX_OVRN\0"
    "DLL_ERR_START_CAN\0DLL_ERR_RESET_CAN\0"
    "DLL_ERR_INIT_CAN\0DLL_ERR_BOFF\0"
    "DLL_ERR_EPAS\0DLL_ERR_EACT\0DLL_ERR_DOI\0"
    "DLL_ERR_RX_OVRN\0MEM_ERR_ALLOC_MEMORY\0"
    "MEM_ERR_FREE_MEMORY\0TPL_ERR_TX_OVRN\0"
    "TPL_ERR_CONF_FILTER\0TPL_ERR_UNEXP_BAM_FRM\0"
    "TPL_ERR_UNEXP_RTS_FRM\0TPL_ERR_UNEXP_CTS_FRM\0"
    "TPL_ERR_UNEXP_EOM_FRM\0TPL_ERR_UNEXP_CA_FRM\0"
    "TPL_ERR_UNEXP_DT_FRM\0TPL_ERR_RX_OVRN\0"
    "TPL_ERR_TX_TIMEOUT0\0TPL_ERR_TX_TIMEOUT2\0"
    "TPL_ERR_RX_TIMEOUT0\0TPL_ERR_RX_TIMEOUT1\0"
    "TPL_ERR_RX_TIMEOUT2\0TPL_ERR_RX_LONG\0"
    "TPL_ERR_SEND_MSG\0TPL_ERR_SEND_CA\0"
    "TPL_ERR_SEND_NACK\0NWM_ERR_DEVICE_REG\0"
    "NWM_ERR_INVALID_HDL\0NWM_ERR_INVALID_ADDR\0"
    "NWM_ERR_NO_COMM\0NWM_ERR_NO_ADDR\0"
    "NWM_ERR_LIST_FULL\0APL_ERR_TIME_EXCEEDED\0"
    "APL_ERR_TX_LONG\0APL_ERR_NO_MEMORY\0"
    "APL_ERR_REG_REQUEST\0APL_ERR_TX_NO_ADDR\0"
    "APL_ERR_INVALID_PARAM\0APL_ERR_REQ_RESPONSE\0"
    "CYC_ERR_NOT_INITIALIZED\0CYC_ERR_RX_REGISTRATION\0"
    "CYC_ERR_TX_REGISTRATION\0CYC_ERR_TIME_EXCEEDED\0"
    "CYC_ERR_RX_TIMEOUT\0CYC_ERR_TX_INVALID_HDL\0"
    "CYC_ERR_TX_QUEUE_OVRN\0CYC_ERR_RX_INVALID_LENGTH\0"
    "REQ_ERR_INVALID_PARAM\0CDP_ERR_TIME_EXCEEDED\0"
    "CDP_ERR_ADDR_FORMAT\0CDP_ERR_CONF_PGN\0"
    "CDP_ERR_UNKNOWN_PGN\0CDP_ERR_STATE_READY_TX\0"
    "CDP_ERR_STATE_READY_RX\0CDP_ERR_NO_MEMORY\0"
    "CDP_ERR_ALLOC_MEMORY\0CDP_ERR_FREE_MEMORY\0"
    "CDP_ERR_RX_LENGTH\0CDP_ERR_RX_TIMEOUT_FC\0"
    "CDP_ERR_RX_TIMEOUT_CF\0CDP_ERR_TX_TIMEOUT\0"
    "CDP_ERR_PCI_INVALID\0DIAG_ERR_MEM_ABORTED_TX\0"
    "DIAG_ERR_MEM_ABORTED_RX\0"
    "DIAG_ERR_MEM_ABORTED_KEY\0"
    "DIAG_ERR_MEM_ABORTED_DATA\0DIAG_ERR_MEM_BUSY\0"
    "DIAG_ERR_MEM_BUSY_FAILED\0"
    "DIAG_ERR_MEM_INVALID_MSG\0USR_ERR_REQ_RESPONSE\0"
    "UNKNOWN_ERR_ID\0OK_ERR_ID"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FieldbusAccessError[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       9,  142, // properties
       3,  178, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   99,    2, 0x06 /* Public */,
       4,    1,  102,    2, 0x06 /* Public */,
       7,    1,  105,    2, 0x06 /* Public */,
      10,    1,  108,    2, 0x06 /* Public */,
      13,    1,  111,    2, 0x06 /* Public */,
      15,    1,  114,    2, 0x06 /* Public */,
      17,    1,  117,    2, 0x06 /* Public */,
      19,    0,  120,    2, 0x06 /* Public */,
      20,    1,  121,    2, 0x06 /* Public */,
      22,    1,  124,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
      23,    1,  127,    2, 0x02 /* Public */,
      24,    0,  130,    2, 0x02 /* Public */,
      25,    1,  131,    2, 0x02 /* Public */,
      26,    0,  134,    2, 0x02 /* Public */,
      27,    1,  135,    2, 0x02 /* Public */,
      28,    0,  138,    2, 0x02 /* Public */,
      29,    1,  139,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, QMetaType::UInt,   14,
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Void, QMetaType::Bool,   18,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QDateTime,   21,
    QMetaType::Void, QMetaType::QDateTime,   21,

 // methods: parameters
    QMetaType::QString, 0x80000000 | 8,    9,
    QMetaType::QString,
    QMetaType::QString, 0x80000000 | 5,    6,
    QMetaType::QString,
    QMetaType::QString, 0x80000000 | 11,   12,
    QMetaType::QString,
    QMetaType::QString, QMetaType::UInt,   14,

 // properties: name, type, flags
       3, QMetaType::Int, 0x00495001,
       6, 0x80000000 | 5, 0x0049510b,
       9, 0x80000000 | 8, 0x00495009,
      30, 0x80000000 | 11, 0x00495009,
      31, QMetaType::UInt, 0x00495003,
      32, QMetaType::QString, 0x00495001,
      33, QMetaType::Bool, 0x00495103,
      34, QMetaType::QDateTime, 0x00495001,
      35, QMetaType::QDateTime, 0x00495001,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,
       4,
       5,
       6,
       8,
       9,

 // enums: name, alias, flags, count, data
       5,    5, 0x0,    5,  193,
      11,   11, 0x0,   16,  203,
       8,    8, 0x0,   76,  235,

 // enum data: key, value
      36, uint(FieldbusAccessError::WARNING),
      37, uint(FieldbusAccessError::ERROR),
      38, uint(FieldbusAccessError::FATAL),
      39, uint(FieldbusAccessError::OK),
      40, uint(FieldbusAccessError::UNKNOWN_LEVEL),
      41, uint(FieldbusAccessError::ERR_ERR_ID),
      42, uint(FieldbusAccessError::DLL_ERR_ID),
      43, uint(FieldbusAccessError::MEM_ERR_ID),
      44, uint(FieldbusAccessError::TPL_ERR_ID),
      45, uint(FieldbusAccessError::NWM_ERR_ID),
      46, uint(FieldbusAccessError::APL_ERR_ID),
      47, uint(FieldbusAccessError::CYC_ERR_ID),
      48, uint(FieldbusAccessError::REQ_ERR_ID),
      49, uint(FieldbusAccessError::L2C_ERR_ID),
      50, uint(FieldbusAccessError::ADR_ERR_ID),
      51, uint(FieldbusAccessError::NMEA_ERR_ID),
      52, uint(FieldbusAccessError::CDP_ERR_ID),
      53, uint(FieldbusAccessError::DIAG_ERR_ID),
      54, uint(FieldbusAccessError::USR_ERR_ID),
      55, uint(FieldbusAccessError::OK_ID),
      56, uint(FieldbusAccessError::UNKNOWN_ID),
      57, uint(FieldbusAccessError::ERR_ERR_INVALID_PARAM),
      58, uint(FieldbusAccessError::DLL_ERR_TX_OVRN),
      59, uint(FieldbusAccessError::DLL_ERR_START_CAN),
      60, uint(FieldbusAccessError::DLL_ERR_RESET_CAN),
      61, uint(FieldbusAccessError::DLL_ERR_INIT_CAN),
      62, uint(FieldbusAccessError::DLL_ERR_BOFF),
      63, uint(FieldbusAccessError::DLL_ERR_EPAS),
      64, uint(FieldbusAccessError::DLL_ERR_EACT),
      65, uint(FieldbusAccessError::DLL_ERR_DOI),
      66, uint(FieldbusAccessError::DLL_ERR_RX_OVRN),
      67, uint(FieldbusAccessError::MEM_ERR_ALLOC_MEMORY),
      68, uint(FieldbusAccessError::MEM_ERR_FREE_MEMORY),
      69, uint(FieldbusAccessError::TPL_ERR_TX_OVRN),
      70, uint(FieldbusAccessError::TPL_ERR_CONF_FILTER),
      71, uint(FieldbusAccessError::TPL_ERR_UNEXP_BAM_FRM),
      72, uint(FieldbusAccessError::TPL_ERR_UNEXP_RTS_FRM),
      73, uint(FieldbusAccessError::TPL_ERR_UNEXP_CTS_FRM),
      74, uint(FieldbusAccessError::TPL_ERR_UNEXP_EOM_FRM),
      75, uint(FieldbusAccessError::TPL_ERR_UNEXP_CA_FRM),
      76, uint(FieldbusAccessError::TPL_ERR_UNEXP_DT_FRM),
      77, uint(FieldbusAccessError::TPL_ERR_RX_OVRN),
      78, uint(FieldbusAccessError::TPL_ERR_TX_TIMEOUT0),
      79, uint(FieldbusAccessError::TPL_ERR_TX_TIMEOUT2),
      80, uint(FieldbusAccessError::TPL_ERR_RX_TIMEOUT0),
      81, uint(FieldbusAccessError::TPL_ERR_RX_TIMEOUT1),
      82, uint(FieldbusAccessError::TPL_ERR_RX_TIMEOUT2),
      83, uint(FieldbusAccessError::TPL_ERR_RX_LONG),
      84, uint(FieldbusAccessError::TPL_ERR_SEND_MSG),
      85, uint(FieldbusAccessError::TPL_ERR_SEND_CA),
      86, uint(FieldbusAccessError::TPL_ERR_SEND_NACK),
      87, uint(FieldbusAccessError::NWM_ERR_DEVICE_REG),
      88, uint(FieldbusAccessError::NWM_ERR_INVALID_HDL),
      89, uint(FieldbusAccessError::NWM_ERR_INVALID_ADDR),
      90, uint(FieldbusAccessError::NWM_ERR_NO_COMM),
      91, uint(FieldbusAccessError::NWM_ERR_NO_ADDR),
      92, uint(FieldbusAccessError::NWM_ERR_LIST_FULL),
      93, uint(FieldbusAccessError::APL_ERR_TIME_EXCEEDED),
      94, uint(FieldbusAccessError::APL_ERR_TX_LONG),
      95, uint(FieldbusAccessError::APL_ERR_NO_MEMORY),
      96, uint(FieldbusAccessError::APL_ERR_REG_REQUEST),
      97, uint(FieldbusAccessError::APL_ERR_TX_NO_ADDR),
      98, uint(FieldbusAccessError::APL_ERR_INVALID_PARAM),
      99, uint(FieldbusAccessError::APL_ERR_REQ_RESPONSE),
     100, uint(FieldbusAccessError::CYC_ERR_NOT_INITIALIZED),
     101, uint(FieldbusAccessError::CYC_ERR_RX_REGISTRATION),
     102, uint(FieldbusAccessError::CYC_ERR_TX_REGISTRATION),
     103, uint(FieldbusAccessError::CYC_ERR_TIME_EXCEEDED),
     104, uint(FieldbusAccessError::CYC_ERR_RX_TIMEOUT),
     105, uint(FieldbusAccessError::CYC_ERR_TX_INVALID_HDL),
     106, uint(FieldbusAccessError::CYC_ERR_TX_QUEUE_OVRN),
     107, uint(FieldbusAccessError::CYC_ERR_RX_INVALID_LENGTH),
     108, uint(FieldbusAccessError::REQ_ERR_INVALID_PARAM),
     109, uint(FieldbusAccessError::CDP_ERR_TIME_EXCEEDED),
     110, uint(FieldbusAccessError::CDP_ERR_ADDR_FORMAT),
     111, uint(FieldbusAccessError::CDP_ERR_CONF_PGN),
     112, uint(FieldbusAccessError::CDP_ERR_UNKNOWN_PGN),
     113, uint(FieldbusAccessError::CDP_ERR_STATE_READY_TX),
     114, uint(FieldbusAccessError::CDP_ERR_STATE_READY_RX),
     115, uint(FieldbusAccessError::CDP_ERR_NO_MEMORY),
     116, uint(FieldbusAccessError::CDP_ERR_ALLOC_MEMORY),
     117, uint(FieldbusAccessError::CDP_ERR_FREE_MEMORY),
     118, uint(FieldbusAccessError::CDP_ERR_RX_LENGTH),
     119, uint(FieldbusAccessError::CDP_ERR_RX_TIMEOUT_FC),
     120, uint(FieldbusAccessError::CDP_ERR_RX_TIMEOUT_CF),
     121, uint(FieldbusAccessError::CDP_ERR_TX_TIMEOUT),
     122, uint(FieldbusAccessError::CDP_ERR_PCI_INVALID),
     123, uint(FieldbusAccessError::DIAG_ERR_MEM_ABORTED_TX),
     124, uint(FieldbusAccessError::DIAG_ERR_MEM_ABORTED_RX),
     125, uint(FieldbusAccessError::DIAG_ERR_MEM_ABORTED_KEY),
     126, uint(FieldbusAccessError::DIAG_ERR_MEM_ABORTED_DATA),
     127, uint(FieldbusAccessError::DIAG_ERR_MEM_BUSY),
     128, uint(FieldbusAccessError::DIAG_ERR_MEM_BUSY_FAILED),
     129, uint(FieldbusAccessError::DIAG_ERR_MEM_INVALID_MSG),
     130, uint(FieldbusAccessError::USR_ERR_REQ_RESPONSE),
     131, uint(FieldbusAccessError::UNKNOWN_ERR_ID),
     132, uint(FieldbusAccessError::OK_ERR_ID),

       0        // eod
};

void FieldbusAccessError::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FieldbusAccessError *_t = static_cast<FieldbusAccessError *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->busChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->levelChanged((*reinterpret_cast< ErrorLevel(*)>(_a[1]))); break;
        case 2: _t->codeChanged((*reinterpret_cast< ErrorCode(*)>(_a[1]))); break;
        case 3: _t->identifierChanged((*reinterpret_cast< ErrorIdentifier(*)>(_a[1]))); break;
        case 4: _t->additionalInfoChanged((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 5: _t->descriptionChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->errorExistsChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->errorReceived(); break;
        case 8: _t->startedChanged((*reinterpret_cast< QDateTime(*)>(_a[1]))); break;
        case 9: _t->endedChanged((*reinterpret_cast< QDateTime(*)>(_a[1]))); break;
        case 10: { QString _r = _t->ErrorCodeToString((*reinterpret_cast< ErrorCode(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 11: { QString _r = _t->errorLevelToQString();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 12: { QString _r = _t->ErrorLevelToQString((*reinterpret_cast< const ErrorLevel(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 13: { QString _r = _t->idToQString();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 14: { QString _r = _t->IdToQString((*reinterpret_cast< const ErrorIdentifier(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 15: { QString _r = _t->addInfoToQString();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 16: { QString _r = _t->AddInfoToQString((*reinterpret_cast< uint(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FieldbusAccessError::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FieldbusAccessError::busChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (FieldbusAccessError::*)(ErrorLevel );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FieldbusAccessError::levelChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (FieldbusAccessError::*)(ErrorCode );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FieldbusAccessError::codeChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (FieldbusAccessError::*)(ErrorIdentifier );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FieldbusAccessError::identifierChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (FieldbusAccessError::*)(uint );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FieldbusAccessError::additionalInfoChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (FieldbusAccessError::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FieldbusAccessError::descriptionChanged)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (FieldbusAccessError::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FieldbusAccessError::errorExistsChanged)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (FieldbusAccessError::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FieldbusAccessError::errorReceived)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (FieldbusAccessError::*)(QDateTime );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FieldbusAccessError::startedChanged)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (FieldbusAccessError::*)(QDateTime );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FieldbusAccessError::endedChanged)) {
                *result = 9;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        FieldbusAccessError *_t = static_cast<FieldbusAccessError *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->bus(); break;
        case 1: *reinterpret_cast< ErrorLevel*>(_v) = _t->level(); break;
        case 2: *reinterpret_cast< ErrorCode*>(_v) = _t->code(); break;
        case 3: *reinterpret_cast< ErrorIdentifier*>(_v) = _t->identifier(); break;
        case 4: *reinterpret_cast< uint*>(_v) = _t->addInfo(); break;
        case 5: *reinterpret_cast< QString*>(_v) = _t->descriptionFullString(); break;
        case 6: *reinterpret_cast< bool*>(_v) = _t->errorExists(); break;
        case 7: *reinterpret_cast< QDateTime*>(_v) = _t->started(); break;
        case 8: *reinterpret_cast< QDateTime*>(_v) = _t->ended(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        FieldbusAccessError *_t = static_cast<FieldbusAccessError *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 1: _t->setLevel(*reinterpret_cast< ErrorLevel*>(_v)); break;
        case 4: _t->setAddInfo(*reinterpret_cast< uint*>(_v)); break;
        case 6: _t->setErrorExists(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject FieldbusAccessError::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_FieldbusAccessError.data,
    qt_meta_data_FieldbusAccessError,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FieldbusAccessError::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FieldbusAccessError::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FieldbusAccessError.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int FieldbusAccessError::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 9;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void FieldbusAccessError::busChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FieldbusAccessError::levelChanged(ErrorLevel _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void FieldbusAccessError::codeChanged(ErrorCode _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void FieldbusAccessError::identifierChanged(ErrorIdentifier _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void FieldbusAccessError::additionalInfoChanged(uint _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void FieldbusAccessError::descriptionChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void FieldbusAccessError::errorExistsChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void FieldbusAccessError::errorReceived()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void FieldbusAccessError::startedChanged(QDateTime _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void FieldbusAccessError::endedChanged(QDateTime _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

/* WARNING: AUTO-GENERATED FILE!
 * MANUAL EDITS WILL BE OVERWRITTEN BY "UPDATE PROJECT" IN LINX MANAGER PLUGIN.
 */

#include "fieldbusaccesserror.h"
#include <QBitArray>
#include <QDebug>

FieldbusAccessError::FieldbusAccessError(ushort errorCode, uint addInfo, QObject *parent) : QObject(parent)
{
    m_bus = 0;
    m_level = OK; // Use OK as base point so that setMember's flank-detection behaves rationally.
    setMembers(errorCode);
    m_addInfo = addInfo;
    //m_errorExists = true;
    emit errorReceived();
}

FieldbusAccessError::FieldbusAccessError(QObject *parent) : QObject(parent)
{
    // Assume OK until notified otherwise
    m_bus = 0;
    m_code = OK_ERR_ID;
    m_level = OK; //
    m_identifier = OK_ID;
    m_addInfo = 0;
    m_errorExists = false;
    m_started = QDateTime();
    m_ended = QDateTime();
}

FieldbusAccessError::~FieldbusAccessError()
{

}

FieldbusAccessError::ErrorCode FieldbusAccessError::code() const
{
    return m_code;
}

FieldbusAccessError::ErrorLevel FieldbusAccessError::level() const
{
    return m_level;
}

void FieldbusAccessError::setLevel(FieldbusAccessError::ErrorLevel level)
{
    if (level != m_level) {
        // Check for OK<->NOK flanks.
        if (m_level == OK) {
            // NOK flank
            setStarted(QDateTime::currentDateTime());
            setEnded(QDateTime());
            setErrorExists(true);

        }
        else if (level == OK) {
            // OK flank
            setEnded(QDateTime::currentDateTime());
            setErrorExists(false);
        }

        m_level = level;
        emit levelChanged(m_level);
    }
}

FieldbusAccessError::ErrorIdentifier FieldbusAccessError::identifier() const
{
    return m_identifier;
}

uint FieldbusAccessError::addInfo() const
{
    return m_addInfo;
}

QString FieldbusAccessError::ErrorCodeToString(ErrorCode code)
{
    switch(code)
    {
    case FieldbusAccessError::ERR_ERR_INVALID_PARAM:
        return "Invalid parameter passed to an API function.";
    case FieldbusAccessError::DLL_ERR_TX_OVRN:
        return "Overrun in the TxQueue.";
    case FieldbusAccessError::DLL_ERR_START_CAN:
        return "Starting CAN failed.";
    case FieldbusAccessError::DLL_ERR_RESET_CAN:
        return "Reset CAN failed.";
    case FieldbusAccessError::DLL_ERR_INIT_CAN:
        return "Init CAN  failed.";
    case FieldbusAccessError::DLL_ERR_BOFF:
        return "Bus error interrupt occurs on CAN.";
    case FieldbusAccessError::DLL_ERR_EPAS:
        return "Error warning interrupt occurs on CAN.";
    case FieldbusAccessError::DLL_ERR_EACT:
        return "CAN controller is in status error active.";
    case FieldbusAccessError::DLL_ERR_DOI:
        return "Data overrun interrupt occurs on CAN.";
    case FieldbusAccessError::DLL_ERR_RX_OVRN:
        return "Overrun in the RxQueue.";
    case FieldbusAccessError::MEM_ERR_ALLOC_MEMORY:
        return "Allocate memory failed.";
    case FieldbusAccessError::MEM_ERR_FREE_MEMORY:
        return "Free memory failed.";
    case FieldbusAccessError::TPL_ERR_TX_OVRN:
        return "No free Entry in the TxQueue of the TPL available.";
    case FieldbusAccessError::TPL_ERR_CONF_FILTER:
        return "Too many PGNs tried to register in the config filter.";
    case FieldbusAccessError::TPL_ERR_UNEXP_BAM_FRM:
        return "Unexpected BAM frame received.";
    case FieldbusAccessError::TPL_ERR_UNEXP_RTS_FRM:
        return "Unexpected RTS frame received.";
    case FieldbusAccessError::TPL_ERR_UNEXP_CTS_FRM:
        return "Unexpected CTS frame received.";
    case FieldbusAccessError::TPL_ERR_UNEXP_EOM_FRM:
        return "Unexpected EOM frame received.";
    case FieldbusAccessError::TPL_ERR_UNEXP_CA_FRM:
        return "Unexpected CA frame received.";
    case FieldbusAccessError::TPL_ERR_UNEXP_DT_FRM:
        return "Unexpected DT frame received.";
    case FieldbusAccessError::TPL_ERR_RX_OVRN:
        return "No free Rx Msg Buffer in the TPL for a global message available.";
    case FieldbusAccessError::TPL_ERR_TX_TIMEOUT0:
        return "Timer overrun for Tx Timeout T0.";
    case FieldbusAccessError::TPL_ERR_TX_TIMEOUT2:
        return "Timer overrun for Tx Timeout T2.";
    case FieldbusAccessError::TPL_ERR_RX_TIMEOUT0:
        return "Timer overrun for Rx Timeout T0.";
    case FieldbusAccessError::TPL_ERR_RX_TIMEOUT1:
        return "Timer overrun for Rx Timeout T1.";
    case FieldbusAccessError::TPL_ERR_RX_TIMEOUT2:
        return "Timer overrun for Rx Timeout T2.";
    case FieldbusAccessError::TPL_ERR_RX_LONG:
        return "The length of the received message is too long for a seg msg.";
    case FieldbusAccessError::TPL_ERR_SEND_MSG:
        return "Error by Sending: Can't send a segmented message.";
    case FieldbusAccessError::TPL_ERR_SEND_CA:
        return "Sending a CA message failed.";
    case FieldbusAccessError::TPL_ERR_SEND_NACK:
        return "Sending a NACK message failed.";
    case FieldbusAccessError::NWM_ERR_DEVICE_REG:
        return "The device is already registered in the device list.";
    case FieldbusAccessError::NWM_ERR_INVALID_HDL:
        return "The device handle is invalid.";
    case FieldbusAccessError::NWM_ERR_INVALID_ADDR:
        return "The device address is invalid.";
    case FieldbusAccessError::NWM_ERR_NO_COMM:
        return "The device is not able to start the CAN communication (starting CAN failed).";
    case FieldbusAccessError::NWM_ERR_NO_ADDR:
        return "The device is not able to claim an address and is therefore not allowed to take part at network communication any longer.";
    case FieldbusAccessError::NWM_ERR_LIST_FULL:
        return "The maximum number of nodes in the network is exceeded.";
    case FieldbusAccessError::APL_ERR_TIME_EXCEEDED:
        return "APL_Main() was not called in the required sequence.";
    case FieldbusAccessError::APL_ERR_TX_LONG:
        return "The data field of the transmit message is too long.";
    case FieldbusAccessError::APL_ERR_NO_MEMORY:
        return "No memory for the data field of the transmit message allocated.";
    case FieldbusAccessError::APL_ERR_REG_REQUEST:
        return "An error occurred during registration of a request PGN.";
    case FieldbusAccessError::APL_ERR_TX_NO_ADDR:
        return "Device has no address claimed.";
    case FieldbusAccessError::APL_ERR_INVALID_PARAM:
        return "Invalid parameter passed to an API function.";
    case FieldbusAccessError::APL_ERR_REQ_RESPONSE:
        return "A request message couldn't be answered from the request handler due to a queue overrun.";
    case FieldbusAccessError::CYC_ERR_NOT_INITIALIZED:
        return "The unit is not yet initialized.";
    case FieldbusAccessError::CYC_ERR_RX_REGISTRATION:
        return "The maximal number of receive messages is exceeded.";
    case FieldbusAccessError::CYC_ERR_TX_REGISTRATION:
        return "The maximal number of transmit messages is exceeded.";
    case FieldbusAccessError::CYC_ERR_TIME_EXCEEDED:
        return "CYC_Main() was not called in the required sequence.";
    case FieldbusAccessError::CYC_ERR_RX_TIMEOUT:
        return "A registered message wasn't received in the given time.";
    case FieldbusAccessError::CYC_ERR_TX_INVALID_HDL:
        return "A message couldn't be sent due to an invalid address handle.";
    case FieldbusAccessError::CYC_ERR_TX_QUEUE_OVRN:
        return "A message couldn't be sent due to an overrun of the transmit queue.";
    case FieldbusAccessError::CYC_ERR_RX_INVALID_LENGTH:
        return "The length of the received message is too long for the receive buffer.";
    case FieldbusAccessError::REQ_ERR_INVALID_PARAM:
        return "Invalid parameter passed to an API function.";
    case FieldbusAccessError::CDP_ERR_TIME_EXCEEDED:
        return "CDP_Main() was not called in the required sequence.";
    case FieldbusAccessError::CDP_ERR_ADDR_FORMAT:
        return "The addressing format of the CAN diagnostic protocol is invalid.";
    case FieldbusAccessError::CDP_ERR_CONF_PGN:
        return "There is no PGN entry free to register a CDP message.";
    case FieldbusAccessError::CDP_ERR_UNKNOWN_PGN:
        return "PGN is not registered.";
    case FieldbusAccessError::CDP_ERR_STATE_READY_TX:
        return "PGN is not ready for transmitting a CAN diagnostic message.";
    case FieldbusAccessError::CDP_ERR_STATE_READY_RX:
        return "PGN is not ready for receiving a CAN diagnostic message.";
    case FieldbusAccessError::CDP_ERR_NO_MEMORY:
        return "No memory for the data field allocated.";
    case FieldbusAccessError::CDP_ERR_ALLOC_MEMORY:
        return "Allocate memory failed.";
    case FieldbusAccessError::CDP_ERR_FREE_MEMORY:
        return "Free memory failed.";
    case FieldbusAccessError::CDP_ERR_RX_LENGTH:
        return "The length of the received CAN diagnostic protocol message is too large for the available receive buffer.";
    case FieldbusAccessError::CDP_ERR_RX_TIMEOUT_FC:
        return "The CAN diagnostic protocol flow control message wasn't received in the given time.";
    case FieldbusAccessError::CDP_ERR_RX_TIMEOUT_CF:
        return "The CAN diagnostic protocol consecutive frame message wasn't received in the given time.";
    case FieldbusAccessError::CDP_ERR_TX_TIMEOUT:
        return "The CAN diagnostic protocol message wasn't sent in the given time.";
    case FieldbusAccessError::CDP_ERR_PCI_INVALID:
        return "The CAN diagnostic protocol control information was invalid.";
    case FieldbusAccessError::DIAG_ERR_MEM_ABORTED_TX:
        return "A memory access session was aborted due to a transmit problem (sending a memory access message failed).";
    case FieldbusAccessError::DIAG_ERR_MEM_ABORTED_RX:
        return "A memory access session was aborted due to a receive problem (a memory access message wasn't received in the expected time).";
    case FieldbusAccessError::DIAG_ERR_MEM_ABORTED_KEY:
        return "A memory access session was aborted due to security reasons (an invalid key was received).";
    case FieldbusAccessError::DIAG_ERR_MEM_ABORTED_DATA:
        return "A memory access session was aborted due to addressing problems (invalid data length was received).";
    case FieldbusAccessError::DIAG_ERR_MEM_BUSY:
        return "A memory access session was declined because the device is busy (another session is in process).";
    case FieldbusAccessError::DIAG_ERR_MEM_BUSY_FAILED:
        return "Transmit a memory access response 'busy' failed.";
    case FieldbusAccessError::DIAG_ERR_MEM_INVALID_MSG:
        return "Invalid message received (the received PGN was not registered for the diagnostic unit).";
    case FieldbusAccessError::USR_ERR_REQ_RESPONSE:
        return "A request message couldn't be answered from the request handler due to a queue overrun.";
    case FieldbusAccessError::UNKNOWN_ERR_ID:
        return "Error code is not recognized.";
    case FieldbusAccessError::OK_ERR_ID:
        return "No error.";
    default:
        return "Error code is not recognized.";
    }
}

void FieldbusAccessError::setBus(int bus)
{
    if (bus == m_bus)
        return;

    m_bus = bus;
    emit busChanged(m_bus);
}

int FieldbusAccessError::bus() const
{
    return m_bus;
}

QString FieldbusAccessError::description()
{
    return ErrorCodeToString(m_code);
}

QString FieldbusAccessError::descriptionFullString()
{
    if (m_code == OK_ERR_ID)
        return QString("No error");
    else
        return QString("Id: %1  Code: %2  Level: %3  Add. Info: %4").arg(idToQString()).arg(description()).arg(errorLevelToQString()).arg(addInfoToQString());
}

void FieldbusAccessError::reset()
{
    m_code = OK_ERR_ID;
    m_level = OK;
    m_identifier = OK_ID;
    m_addInfo = 0;
    m_errorExists = false;
    m_started = QDateTime();
    m_ended = QDateTime();

    emit codeChanged(m_code);
    emit levelChanged(m_level);
    emit identifierChanged(m_identifier);
    emit additionalInfoChanged(m_addInfo);
    emit errorExistsChanged(m_errorExists);
    emit descriptionChanged(descriptionFullString());
    emit startedChanged(m_started);
    emit endedChanged(m_ended);
}

QString FieldbusAccessError::errorLevelToQString()
{
    return ErrorLevelToQString(m_level);
}

QString FieldbusAccessError::ErrorLevelToQString(const FieldbusAccessError::ErrorLevel level)
{
    switch(level)
    {
    case FieldbusAccessError::WARNING:
        return "Warning";
    case FieldbusAccessError::ERROR:
        return "Error";
    case FieldbusAccessError::FATAL:
        return "Fatal";
    case FieldbusAccessError::OK:
        return "OK";
    case FieldbusAccessError::UNKNOWN_LEVEL:
    default:
        return "UnknownLevel";
    }
}

QString FieldbusAccessError::idToQString()
{
    return IdToQString(m_identifier);
}

QString FieldbusAccessError::IdToQString(const FieldbusAccessError::ErrorIdentifier id)
{
    switch(id)
    {
    case FieldbusAccessError::ERR_ERR_ID:
        return "Error unit";
    case FieldbusAccessError::DLL_ERR_ID:
        return "Data link layer";
    case FieldbusAccessError::MEM_ERR_ID:
        return "Memory unit";
    case FieldbusAccessError::TPL_ERR_ID:
        return "Transport protocol";
    case FieldbusAccessError::NWM_ERR_ID:
        return "Network management";
    case FieldbusAccessError::APL_ERR_ID:
        return "Application layer";
    case FieldbusAccessError::CYC_ERR_ID:
        return "Cycle unit";
    case FieldbusAccessError::REQ_ERR_ID:
        return "Request unit";
    case FieldbusAccessError::L2C_ERR_ID:
        return "Layer 2 unit";
    case FieldbusAccessError::ADR_ERR_ID:
        return "Addressing unit";
    case FieldbusAccessError::NMEA_ERR_ID:
        return "NMEA 2000 module";
    case FieldbusAccessError::CDP_ERR_ID:
        return "CAN Diagnostic Protocol";
    case FieldbusAccessError::DIAG_ERR_ID:
        return "J1939 Diagnostic Module";
    case FieldbusAccessError::USR_ERR_ID:
        return "User specific code (generated)";
    case FieldbusAccessError::OK_ID:
        return "All";
    default:
        return "Unknown Id";
    }
}

QString FieldbusAccessError::addInfoToQString()
{
    return AddInfoToQString(m_addInfo);
}

QString FieldbusAccessError::AddInfoToQString(uint addInfo)
{
    return QString::number(addInfo);
}

bool FieldbusAccessError::errorExists() const
{
    return m_errorExists;
}

void FieldbusAccessError::setErrorExists(bool exists)
{
    if (exists != m_errorExists) {
        m_errorExists = exists;
        emit errorExistsChanged(m_errorExists);
    }
}

QDateTime FieldbusAccessError::started() const
{
    return m_started;
}

QDateTime FieldbusAccessError::ended() const
{
    return m_ended;
}

QString FieldbusAccessError::printBits(QString title, QByteArray data)
{
    QBitArray bitArray(8*data.count());

    QString res;

    res += QString("+------- \n%1\n ---------+\n").arg(title);

    for (int i = 0; i < data.count(); i++) {
        for (int b = 0; b < 8; b++) {
            bitArray.setBit( i * 8 + b, data.at(i) & (1 << (7 - b)) );
            res += bitArray[i * 8 + b] ? "1" : "0" ;
        }
        res += QString("\n");
    }
    res += QString("+-----------------------------+\n");

    return res;

}

void FieldbusAccessError::setStarted(QDateTime time)
{
    if (m_started == time)
        return;

    m_started = time;
    emit startedChanged(m_started);
}

void FieldbusAccessError::setEnded(QDateTime time)
{
    if (m_ended == time)
        return;

    m_ended = time;
    emit endedChanged(m_ended);
}

void FieldbusAccessError::setMembers(const FieldbusAccessError &error)
{
    m_code = error.code();
    m_level = error.level();
    m_identifier = error.identifier();
    m_started = error.started();
    m_ended = error.ended();
    m_errorExists = error.errorExists();

    emit codeChanged(m_code);
    emit levelChanged(m_level);
    emit identifierChanged(m_identifier);
    emit errorExistsChanged(m_errorExists);
    emit descriptionChanged(descriptionFullString());
    emit startedChanged(m_started);
    emit endedChanged(m_ended);
    emit errorReceived();
}

void FieldbusAccessError::setMembers(const ushort &errorCode)
{
    uchar error = (uchar) (errorCode & ERR_CODE_MASK);
    uchar id = (uchar) ((errorCode & ERR_ID_MASK) >> 8);
    uchar level = (uchar) ((errorCode & ERR_CLASS_MASK) >> 13);

    switch(id)
    {
    case FieldbusAccessError::ERR_ERR_ID:
        m_identifier = ERR_ERR_ID;
        break;
    case FieldbusAccessError::DLL_ERR_ID:
        m_identifier = DLL_ERR_ID;
        break;
    case FieldbusAccessError::MEM_ERR_ID:
        m_identifier = MEM_ERR_ID;
        break;
    case FieldbusAccessError::TPL_ERR_ID:
        m_identifier = TPL_ERR_ID;
        break;
    case FieldbusAccessError::NWM_ERR_ID:
        m_identifier = NWM_ERR_ID;
        break;
    case FieldbusAccessError::APL_ERR_ID:
        m_identifier = APL_ERR_ID;
        break;
    case FieldbusAccessError::CYC_ERR_ID:
        m_identifier = CYC_ERR_ID;
        break;
    case FieldbusAccessError::REQ_ERR_ID:
        m_identifier = REQ_ERR_ID;
        break;
    case FieldbusAccessError::L2C_ERR_ID:
        m_identifier = L2C_ERR_ID;
        break;
    case FieldbusAccessError::ADR_ERR_ID:
        m_identifier = ADR_ERR_ID;
        break;
    case FieldbusAccessError::NMEA_ERR_ID:
        m_identifier = NMEA_ERR_ID;
        break;
    case FieldbusAccessError::CDP_ERR_ID:
        m_identifier = CDP_ERR_ID;
        break;
    case FieldbusAccessError::DIAG_ERR_ID:
        m_identifier = DIAG_ERR_ID;
        break;
    case FieldbusAccessError::USR_ERR_ID:
        m_identifier = USR_ERR_ID;
        break;
    default:
        m_identifier = UNKNOWN_ID;
    }

    FieldbusAccessError::ErrorLevel prevLevel = m_level;
    switch(level)
    {
        case FieldbusAccessError::WARNING:
            m_level = FieldbusAccessError::WARNING;
        break;
        case FieldbusAccessError::ERROR:
            m_level = FieldbusAccessError::ERROR;
        break;
        case FieldbusAccessError::FATAL:
            m_level = FieldbusAccessError::FATAL;
        break;
        case FieldbusAccessError::OK:
            m_level = FieldbusAccessError::OK;
        break;
        default:
            m_level = FieldbusAccessError::UNKNOWN_LEVEL;
    }
    if (prevLevel == FieldbusAccessError::OK && m_level != FieldbusAccessError::OK) {
            m_started = QDateTime::currentDateTime();
            m_ended = QDateTime();
    }
    if (prevLevel != FieldbusAccessError::OK && m_level == FieldbusAccessError::OK)
            m_ended = QDateTime::currentDateTime();


    switch(m_identifier)
    {
    case FieldbusAccessError::ERR_ERR_ID:
        m_code = (ErrorCode) (error + ERR_ERR_ID_OFFSET);
        break;
    case FieldbusAccessError::DLL_ERR_ID:
        m_code = (ErrorCode) (error + DLL_ERR_ID_OFFSET);
        break;
    case FieldbusAccessError::MEM_ERR_ID:
        m_code = (ErrorCode) (error + MEM_ERR_ID_OFFSET);
        break;
    case FieldbusAccessError::TPL_ERR_ID:
        m_code = (ErrorCode) (error + TPL_ERR_ID_OFFSET);
        break;
    case FieldbusAccessError::NWM_ERR_ID:
        m_code = (ErrorCode) (error + NWM_ERR_ID_OFFSET);
        break;
    case FieldbusAccessError::APL_ERR_ID:
        m_code = (ErrorCode) (error + APL_ERR_ID_OFFSET);
        break;
    case FieldbusAccessError::CYC_ERR_ID:
        m_code = (ErrorCode) (error + CYC_ERR_ID_OFFSET);
        break;
    case FieldbusAccessError::REQ_ERR_ID:
        m_code = (ErrorCode) (error + REQ_ERR_ID_OFFSET);
        break;
    case FieldbusAccessError::L2C_ERR_ID:
        m_code = (ErrorCode) (error + L2C_ERR_ID_OFFSET);
        break;
    case FieldbusAccessError::ADR_ERR_ID:
        m_code = (ErrorCode) (error + ADR_ERR_ID_OFFSET);
        break;
    case FieldbusAccessError::NMEA_ERR_ID:
        m_code = (ErrorCode) (error + NMEA_ERR_ID_OFFSET);
        break;
    case FieldbusAccessError::CDP_ERR_ID:
        m_code = (ErrorCode) (error + CDP_ERR_ID_OFFSET);
        break;
    case FieldbusAccessError::DIAG_ERR_ID:
        m_code = (ErrorCode) (error + DIAG_ERR_ID_OFFSET);
        break;
    case FieldbusAccessError::USR_ERR_ID:
        m_code = (ErrorCode) (error + USR_ERR_ID_OFFSET);
        break;
    default:
        m_code = UNKNOWN_ERR_ID;
    }

    m_errorExists = m_level != FieldbusAccessError::OK;

//    emit codeChanged(m_code);
//    emit levelChanged(m_level);
//    emit identifierChanged(m_identifier);
//    emit errorExistsChanged(m_errorExists);
//    emit descriptionChanged(descriptionFullString());
//    emit errorReceived();
}

void FieldbusAccessError::setAddInfo(const uint addInfo)
{
    m_addInfo = addInfo;
//    emit additionalInfoChanged(m_addInfo);
}

void FieldbusAccessError::setData(const QByteArray data, int bus)
{
    // Ensure we got the amount of data we expect
    if (data.length() != 6)
        return;


    QByteArray ec = data.left(2);
    ushort errCode = 0;
    for (int i=0; i<ec.length(); i++) {
        errCode = errCode | (ec[i] << 8*i);
    }

    QByteArray ai = data.right(4);
    //qDebug() << printBits("ErrorMsg:",ai);
    uint addInfo = 0;
    //qDebug() << addInfo;
    for (int i=0; i<ai.length(); i++) {
        unsigned char c = ai[i];
        addInfo = addInfo | c << 8*i;
        //qDebug() << addInfo;
    }

    setMembers(errCode);
    setAddInfo(addInfo);
    setBus(bus);

    emit codeChanged(m_code);
    emit levelChanged(m_level);
    emit identifierChanged(m_identifier);
    emit errorExistsChanged(m_errorExists);
    emit descriptionChanged(descriptionFullString());
    emit additionalInfoChanged(m_addInfo);
    emit startedChanged(m_started);
    emit endedChanged(m_ended);
    emit errorReceived();
}

//QVariant FieldbusAccessError::data(int role)
//{
//    switch(role) {
//    case FieldbusAccessErrorModel::Level: return QVariant(errorLevelToQString());
//    case FieldbusAccessErrorModel::Code: return QVariant(ErrorCodeToString(m_code));
//    case FieldbusAccessErrorModel::Identifier: return QVariant(idToQString());
//    case FieldbusAccessErrorModel::AddInfo: return QVariant(addInfoToQString());
//    case FieldbusAccessErrorModel::Description: return QVariant(description());
//    case FieldbusAccessErrorModel::Exists: return QVariant(errorExists());
//    default: return QVariant();
//    };
//}


/******************************************************************************
//
// FILE:        communicationerror.h
//
// DESCRIPTION: Containts class and methods to interpret errors received from Fieldbus Access
//
// COPYRIGHT:   crosscontrol 2016
//
// CODE TEMPLATE REVISION: 1.0
//
******************************************************************************/
#ifndef FIELDBUSACCESSERROR_H
#define FIELDBUSACCESSERROR_H

/******************************************************************************
// INCLUDE FILES
******************************************************************************/
#include <QObject>
#include <QDateTime>
//#include "fieldbusaccesserrormodel.h"

/******************************************************************************
// MANIFEST CONSTANTS, MACROS
******************************************************************************/
#define ERR_ERR_ID_OFFSET        0      /* error unit identifier          */
#define DLL_ERR_ID_OFFSET       50      /* data link layer identifier     */
#define MEM_ERR_ID_OFFSET       100     /* memory unit identifier         */
#define TPL_ERR_ID_OFFSET       150     /* transport protocol identifier  */
#define NWM_ERR_ID_OFFSET       200     /* network management identifier  */
#define APL_ERR_ID_OFFSET       250     /* application layer identifier   */
#define CYC_ERR_ID_OFFSET       300     /* cycle unit identifier          */
#define REQ_ERR_ID_OFFSET       350     /* request unit identifier        */
#define L2C_ERR_ID_OFFSET       400     /* layer 2 unit identifier        */
#define ADR_ERR_ID_OFFSET       450     /* addressing unit identifier     */
#define NMEA_ERR_ID_OFFSET      500     /* NMEA 2000 module               */
#define CDP_ERR_ID_OFFSET       550     /* CAN Diagnostic Protocol        */
#define DIAG_ERR_ID_OFFSET      600     /* J1939 Diagnostic Module        */
#define USR_ERR_ID_OFFSET       650     /* user specific code (generated) */
#define UNKNOWN_ERR_ID_OFFSET   700     /* unknown error                  */
#define ERR_CLASS_MASK          0x6000  /* mask of the error classes      */
#define ERR_ID_MASK             0x1F00  /* mask of the error identifiers  */
#define ERR_CODE_MASK           0x00FF  /* mask of the error code         */
#define ERR_BUILD_ERROR_CODE(classification ,id ,error)  (ushort)(((classification) << 13) | ((id) << 8) | (error))

//class FieldbusAccessErrorModel;

/******************************************************************************
// CLASS DEFINITION
******************************************************************************/

/**
 * @brief The CommunicationError contains Enums, members and methods to express errors from Fieldbuss Access
 */
class FieldbusAccessError : public QObject
{
    Q_OBJECT

    Q_PROPERTY (int bus READ bus NOTIFY busChanged)
    Q_PROPERTY (ErrorLevel level READ level WRITE setLevel NOTIFY levelChanged)
    Q_PROPERTY (ErrorCode code READ code NOTIFY codeChanged)
    Q_PROPERTY (ErrorIdentifier identifier READ identifier NOTIFY identifierChanged)
    Q_PROPERTY (uint additionalInfo READ addInfo WRITE setAddInfo NOTIFY additionalInfoChanged)
    Q_PROPERTY (QString description READ descriptionFullString NOTIFY descriptionChanged)
    Q_PROPERTY (bool errorExists READ errorExists WRITE setErrorExists NOTIFY errorExistsChanged)
    Q_PROPERTY (QDateTime started READ started NOTIFY startedChanged)
    Q_PROPERTY (QDateTime ended READ ended NOTIFY endedChanged)

public:
    /**
     * @brief The ErrorLevel enum holds information how severe the occured error is.
     */
    enum ErrorLevel
    {
        WARNING     = 0,    /*!< An error warning has occurred  */
        ERROR       = 1,    /*!< An error has occurred          */
        FATAL       = 2,    /*!< A fatal error has occurred     */
        OK          = 3,    /*!< No error has occurred yet      */
        UNKNOWN_LEVEL       /*!< Unknown error level            */
    };

    /**
     * @brief The ErrorIdentifier enum holds information which area the error is related to.
     */
    enum ErrorIdentifier
    {
        ERR_ERR_ID    =    0,   /*!< error unit identifier             */
        DLL_ERR_ID    =    1,   /*!< data link layer identifier        */
        MEM_ERR_ID    =    2,   /*!< memory unit identifier            */
        TPL_ERR_ID    =    3,   /*!< transport protocol identifier     */
        NWM_ERR_ID    =    4,   /*!< network management identifier     */
        APL_ERR_ID    =    5,   /*!< application layer identifier      */
        CYC_ERR_ID    =    6,   /*!<!< cycle unit identifier           */
        REQ_ERR_ID    =    7,   /*!< request unit identifier           */
        L2C_ERR_ID    =    8,   /*!< layer 2 unit identifier           */
        ADR_ERR_ID    =    9,   /*!< addressing unit identifier        */
        NMEA_ERR_ID   =   10,   /*!< NMEA 2000 module                  */
        CDP_ERR_ID    =   11,   /*!< CAN Diagnostic Protocol           */
        DIAG_ERR_ID   =   12,   /*!< J1939 Diagnostic Module           */
        USR_ERR_ID    =   13,   /*!< user specific code (generated)    */
        OK_ID         =   14,   /*!< no error                          */
        UNKNOWN_ID
    };

    /**
     * @brief The ErrorCode enum holds the actual unique error code.
     */
    enum ErrorCode
    {
        ERR_ERR_INVALID_PARAM   =  ERR_ERR_ID_OFFSET + 1,   /*!< Invalid parameter passed to an API function */

        DLL_ERR_TX_OVRN         =  DLL_ERR_ID_OFFSET + 1,   /*!< Overrun in the TxQueue */
        DLL_ERR_START_CAN       =  DLL_ERR_ID_OFFSET + 2,   /*!< Starting CAN failed */
        DLL_ERR_RESET_CAN       =  DLL_ERR_ID_OFFSET + 3,   /*!< Reset CAN failed */
        DLL_ERR_INIT_CAN        =  DLL_ERR_ID_OFFSET + 4,   /*!< Init CAN  failed */
        DLL_ERR_BOFF            =  DLL_ERR_ID_OFFSET + 11,  /*!< Bus error interrupt occurs on CAN */
        DLL_ERR_EPAS            =  DLL_ERR_ID_OFFSET + 12,  /*!< Error warning interrupt occurs on CAN */
        DLL_ERR_EACT            =  DLL_ERR_ID_OFFSET + 13,  /*!< CAN controller is in status error active */
        DLL_ERR_DOI             =  DLL_ERR_ID_OFFSET + 14,  /*!< Data overrun interrupt occurs on CAN */
        DLL_ERR_RX_OVRN         =  DLL_ERR_ID_OFFSET + 15,  /*!< Overrun in the RxQueue */

        MEM_ERR_ALLOC_MEMORY    =  MEM_ERR_ID_OFFSET + 11,  /*!< Allocate memory failed */
        MEM_ERR_FREE_MEMORY     =  MEM_ERR_ID_OFFSET + 12,  /*!< Free memory failed */

        TPL_ERR_TX_OVRN         =  TPL_ERR_ID_OFFSET + 1,   /*!< No free Entry in the TxQueue of the TPL available */
        TPL_ERR_CONF_FILTER     =  TPL_ERR_ID_OFFSET + 2,   /*!< Too many PGNs tried to register in the config filter */
        TPL_ERR_UNEXP_BAM_FRM   =  TPL_ERR_ID_OFFSET + 11,  /*!< Unexpected BAM frame received */
        TPL_ERR_UNEXP_RTS_FRM   =  TPL_ERR_ID_OFFSET + 12,  /*!< Unexpected RTS frame received */
        TPL_ERR_UNEXP_CTS_FRM   =  TPL_ERR_ID_OFFSET + 13,  /*!< Unexpected CTS frame received */
        TPL_ERR_UNEXP_EOM_FRM   =  TPL_ERR_ID_OFFSET + 14,  /*!< Unexpected EOM frame received */
        TPL_ERR_UNEXP_CA_FRM    =  TPL_ERR_ID_OFFSET + 15,  /*!< Unexpected CA frame received */
        TPL_ERR_UNEXP_DT_FRM    =  TPL_ERR_ID_OFFSET + 16,  /*!< Unexpected DT frame received */
        TPL_ERR_RX_OVRN         =  TPL_ERR_ID_OFFSET + 17,  /*!< No free Rx Msg Buffer in the TPL for a global message available */
        TPL_ERR_TX_TIMEOUT0     =  TPL_ERR_ID_OFFSET + 18,  /*!< Timer overrun for Tx Timeout T0 */
        TPL_ERR_TX_TIMEOUT2     =  TPL_ERR_ID_OFFSET + 19,  /*!< Timer overrun for Tx Timeout T2 */
        TPL_ERR_RX_TIMEOUT0     =  TPL_ERR_ID_OFFSET + 20,  /*!< Timer overrun for Rx Timeout T0 */
        TPL_ERR_RX_TIMEOUT1     =  TPL_ERR_ID_OFFSET + 21,  /*!< Timer overrun for Rx Timeout T1 */
        TPL_ERR_RX_TIMEOUT2     =  TPL_ERR_ID_OFFSET + 22,  /*!< Timer overrun for Rx Timeout T2 */
        TPL_ERR_RX_LONG         =  TPL_ERR_ID_OFFSET + 23,  /*!< The length of the received message is too long for a seg msg */
        TPL_ERR_SEND_MSG        =  TPL_ERR_ID_OFFSET + 24,  /*!< Error by Sending: Can't send a segmented message */
        TPL_ERR_SEND_CA         =  TPL_ERR_ID_OFFSET + 25,  /*!< Sending a CA message failed */
        TPL_ERR_SEND_NACK       =  TPL_ERR_ID_OFFSET + 26,  /*!< Sending a NACK message failed */

        NWM_ERR_DEVICE_REG      =  NWM_ERR_ID_OFFSET + 1,   /*!< The device is already registered in the device list */
        NWM_ERR_INVALID_HDL     =  NWM_ERR_ID_OFFSET + 2,   /*!< The device handle is invalid */
        NWM_ERR_INVALID_ADDR    =  NWM_ERR_ID_OFFSET + 3,   /*!< The device address is invalid */
        NWM_ERR_NO_COMM         =  NWM_ERR_ID_OFFSET + 11,  /*!< The device is not able to start the CAN communication (starting CAN failed) */
        NWM_ERR_NO_ADDR         =  NWM_ERR_ID_OFFSET + 12,  /*!< The device is not able to claim an address and is therefore not allowed to take part at network communication any longer */
        NWM_ERR_LIST_FULL       =  NWM_ERR_ID_OFFSET + 13,  /*!< The maximum number of nodes in the network is exceeded */

        APL_ERR_TIME_EXCEEDED   =  APL_ERR_ID_OFFSET + 1,   /*!< APL_Main() was not called in the required sequence */
        APL_ERR_TX_LONG         =  APL_ERR_ID_OFFSET + 2,   /*!< The data field of the transmit message is too long */
        APL_ERR_NO_MEMORY       =  APL_ERR_ID_OFFSET + 3,   /*!< No memory for the data field of the transmit message allocated */
        APL_ERR_REG_REQUEST     =  APL_ERR_ID_OFFSET + 4,   /*!< An error occurred during registration of a request PGN */
        APL_ERR_TX_NO_ADDR      =  APL_ERR_ID_OFFSET + 5,   /*!< Device has no address claimed */
        APL_ERR_INVALID_PARAM   =  APL_ERR_ID_OFFSET + 7,   /*!< Invalid parameter passed to an API function */
        APL_ERR_REQ_RESPONSE    =  APL_ERR_ID_OFFSET + 11,  /*!< A request message couldn't be answered from the request handler due to a queue overrun */

        CYC_ERR_NOT_INITIALIZED =  CYC_ERR_ID_OFFSET + 1,   /*!< The unit is not yet initialized */
        CYC_ERR_RX_REGISTRATION =  CYC_ERR_ID_OFFSET + 2,   /*!< The maximal number of receive messages is exceeded */
        CYC_ERR_TX_REGISTRATION =  CYC_ERR_ID_OFFSET + 3,   /*!< The maximal number of transmit messages is exceeded */
        CYC_ERR_TIME_EXCEEDED   =  CYC_ERR_ID_OFFSET + 4,   /*!< CYC_Main() was not called in the required sequence */
        CYC_ERR_RX_TIMEOUT      =  CYC_ERR_ID_OFFSET + 11,  /*!< A registered message wasn't received in the given time */
        CYC_ERR_TX_INVALID_HDL  =  CYC_ERR_ID_OFFSET + 12,  /*!< A message couldn't be sent due to an invalid address handle */
        CYC_ERR_TX_QUEUE_OVRN   =  CYC_ERR_ID_OFFSET + 13,  /*!< A message couldn't be sent due to an overrun of the transmit queue */
        CYC_ERR_RX_INVALID_LENGTH   =  CYC_ERR_ID_OFFSET + 14, /*!< The length of the received message is too long for the receive buffer */

        REQ_ERR_INVALID_PARAM   =  REQ_ERR_ID_OFFSET + 1,   /*!< Invalid parameter passed to an API function */

        CDP_ERR_TIME_EXCEEDED   =  CDP_ERR_ID_OFFSET + 1,   /*!< CDP_Main() was not called in the required sequence */
        CDP_ERR_ADDR_FORMAT     =  CDP_ERR_ID_OFFSET + 2,   /*!< The addressing format of the CAN diagnostic protocol is invalid */
        CDP_ERR_CONF_PGN        =  CDP_ERR_ID_OFFSET + 3,   /*!< There is no PGN entry free to register a CDP message */
        CDP_ERR_UNKNOWN_PGN     =  CDP_ERR_ID_OFFSET + 4,   /*!< PGN is not registered */
        CDP_ERR_STATE_READY_TX  =  CDP_ERR_ID_OFFSET + 5,   /*!< PGN is not ready for transmitting a CAN diagnostic message */
        CDP_ERR_STATE_READY_RX  =  CDP_ERR_ID_OFFSET + 6,   /*!< PGN is not ready for receiving a CAN diagnostic message */
        CDP_ERR_NO_MEMORY       =  CDP_ERR_ID_OFFSET + 7,   /*!< No memory for the data field allocated */
        CDP_ERR_ALLOC_MEMORY    =  CDP_ERR_ID_OFFSET + 11,  /*!< Allocate memory failed */
        CDP_ERR_FREE_MEMORY     =  CDP_ERR_ID_OFFSET + 12,  /*!< Free memory failed */
        CDP_ERR_RX_LENGTH       =  CDP_ERR_ID_OFFSET + 13,  /*!< The length of the received CAN diagnostic protocol message is too large for the available receive buffer */
        CDP_ERR_RX_TIMEOUT_FC   =  CDP_ERR_ID_OFFSET + 14,  /*!< The CAN diagnostic protocol flow control message wasn't received in the given time */
        CDP_ERR_RX_TIMEOUT_CF   =  CDP_ERR_ID_OFFSET + 15,  /*!< The CAN diagnostic protocol consecutive frame message wasn't received in the given time */
        CDP_ERR_TX_TIMEOUT      =  CDP_ERR_ID_OFFSET + 16,  /*!< The CAN diagnostic protocol message wasn't sent in the given time */
        CDP_ERR_PCI_INVALID     =  CDP_ERR_ID_OFFSET + 17,  /*!< The CAN diagnostic protocol control information was invalid */

        DIAG_ERR_MEM_ABORTED_TX     =  DIAG_ERR_ID_OFFSET + 11, /*!< A memory access session was aborted due to a transmit problem (sending a memory access message failed) */
        DIAG_ERR_MEM_ABORTED_RX     =  DIAG_ERR_ID_OFFSET + 12, /*!< A memory access session was aborted due to a receive problem (a memory access message wasn't received in the expected time) */
        DIAG_ERR_MEM_ABORTED_KEY    =  DIAG_ERR_ID_OFFSET + 13, /*!< A memory access session was aborted due to security reasons (an invalid key was received) */
        DIAG_ERR_MEM_ABORTED_DATA   =  DIAG_ERR_ID_OFFSET + 14, /*!< A memory access session was aborted due to addressing problems (invalid data length was received) */
        DIAG_ERR_MEM_BUSY           =  DIAG_ERR_ID_OFFSET + 15, /*!< A memory access session was declined because the device is busy (another session is in process) */
        DIAG_ERR_MEM_BUSY_FAILED    =  DIAG_ERR_ID_OFFSET + 16, /*!< Transmit a memory access response 'busy' failed */
        DIAG_ERR_MEM_INVALID_MSG    =  DIAG_ERR_ID_OFFSET + 17, /*!< Invalid message received (the received PGN was not registered for the diagnostic unit) */

        USR_ERR_REQ_RESPONSE    =  USR_ERR_ID_OFFSET + 11,  /*!< A request message couldn't be answered from the request handler due to a queue overrun */

        UNKNOWN_ERR_ID          =  UNKNOWN_ERR_ID_OFFSET + 0,    /*!< Error code is not recognized */
        OK_ERR_ID                                               /*!< No error   */
    };
    Q_ENUMS(ErrorLevel)
    Q_ENUMS(ErrorCode)
    Q_ENUMS(ErrorIdentifier)

    /**
     * @brief Default constructor when the error code is known
     * @param errorCode Code received from Fieldbuss Access
     * @param parent
     */
    explicit FieldbusAccessError(ushort errorCode, uint addInfo = 0, QObject *parent = 0);

    /**
     * @brief Default constructor without error code. Members set to unknown.
     * @param parent
     */
    explicit FieldbusAccessError(QObject *parent = 0);
    ~FieldbusAccessError();

    /**
     * @brief Get a readable description for the specific ErrorCode
     * @param code The error code
     * @return Readable description for the error code
     */
    Q_INVOKABLE static QString ErrorCodeToString(ErrorCode code);

    /**
     * @brief Get the bus error was received from
     * @return Bus number
     */
    int bus() const;

    /**
     * @brief Sets the source bus for the error
     * @param bus Bus number
     */
    void setBus(int bus);

    /**
     * @brief Get the error code
     * @return Error code
     */
    ErrorCode code() const;

    /**
     * @brief level Get the error level
     * @return Error level
     */
    ErrorLevel level() const;

    void setLevel(ErrorLevel level);

    /**
     * @brief Get the error identifier
     * @return
     */
    ErrorIdentifier identifier() const;

    /**
     * @brief Get the error additional information
     * @return
     */
    uint addInfo() const;

    /**
     * @brief Set members of this instance using another instance as reference
     * @param error
     */

    void setMembers(const FieldbusAccessError &error);

    /**
     * @brief Set members using bit-encoded value
     * @param errorCode Bit-encoded error code
     */
    void setMembers(const ushort &errorCode);

    /**
     * @brief Set additional info of member
     * @param uint addInfo code
     */
    void setAddInfo(const uint addInfo);

    /**
     * @brief Combined version of setMembers and setAddInfo
     * @param data QByteArray[6] byte 0-1 ushort errorcode, byte 2-5 uint addInfo
     * @param bus Bus number error was received from
     */
    void setData(const QByteArray data, int bus = 0);

    //QVariant data(int role);

    /**
     * @brief Get the description for this instance
     * @return Readable description for instace error code
     */
    QString description();

    /**
     * @brief Get the full description for this instance
     * @return Readable description for instace error code, level, identifier and additional information
     */
    QString descriptionFullString();

    /**
     * @brief Reset values for code, level and identifier
     */
    void reset();

    /**
     * @brief Get the level for this instance as a readable QString
     * @return
     */
    Q_INVOKABLE QString errorLevelToQString();

    /**
     * @brief Get a readable level for a specified level
     * @param level Level to be printable
     * @return Level as QString
     */
    Q_INVOKABLE static QString ErrorLevelToQString(const ErrorLevel level);

    /**
     * @brief Get the id for this instance as a readable QString
     * @return
     */
    Q_INVOKABLE QString idToQString();

    /**
     * @brief Get a readable identifier for a specified id
     * @param id Identifier to be printable
     * @return Identifier as QString
     */
    Q_INVOKABLE static QString IdToQString(const ErrorIdentifier id);

    /**
     * @brief Get the addInfo for this instance as a readable QString
     * @return
     */
    Q_INVOKABLE QString addInfoToQString();

    /**
     * @brief Get a readable string for a specified addInfo number
     * @param uint addInfo to be printable
     * @return uint addInfo code as QString
     */
    Q_INVOKABLE static QString AddInfoToQString(uint addInfo);

    /**
     * @brief Find out if an error has been received
     * @return bool True if an error has been received
     */
    bool errorExists() const;
    void setErrorExists(bool exists);

    QDateTime started() const;
    QDateTime ended() const;

signals:
    void busChanged(int bus);
    void levelChanged(ErrorLevel level);
    void codeChanged(ErrorCode code);
    void identifierChanged(ErrorIdentifier id);
    void additionalInfoChanged(uint addInfo);
    void descriptionChanged(QString descr);
    void errorExistsChanged(bool arg);
    void errorReceived();
    void startedChanged(QDateTime t);
    void endedChanged(QDateTime t);

private:
    int m_bus;
    ErrorCode m_code;
    ErrorLevel m_level;
    ErrorIdentifier m_identifier;
    uint m_addInfo;
    bool m_errorExists;
    QDateTime m_started;
    QDateTime m_ended;

    /**
     * @brief printBits Inspects the QByteArray and returns a verbose output of its bits, together with a title header
     * @param title
     * @param data
     * @return QString inspection result
     */
    QString printBits(QString title, QByteArray data);
    void setStarted(QDateTime time);
    void setEnded(QDateTime time);
};

#endif // FIELDBUSACCESSERROR_H

/* WARNING: AUTO-GENERATED FILE!
 * MANUAL EDITS WILL BE OVERWRITTEN BY "UPDATE PROJECT" IN LINX MANAGER PLUGIN.
 */

#include "dataenginebase.h"
#include <QDebug>

DataEngineBase::DataEngineBase(QObject *parent) : QObject(parent)
{
    m_connectionTimer.setInterval(1000);
    m_connectionTimer.start();
    connect(&m_connectionTimer, SIGNAL(timeout()), this, SLOT(checkConnectionSlot()));

    m_connectionState = Disconnected;
    m_clientName = "QmlBackend";
    m_host = "localhost";
    m_port = 0x1235;

    //Observer initialization
    m_observer = new QtObserver(this);
    m_sap.SetDataObserver (m_observer);

    connect (m_observer, SIGNAL (dataChanged (int, bool)), this, SLOT (receiveSignal (int, bool)));
    connect (m_observer, SIGNAL (dataChanged (int, signed char)), this, SLOT (receiveSignal (int, signed char)));
    connect (m_observer, SIGNAL (dataChanged (int, short)), this, SLOT (receiveSignal (int, short)));
    connect (m_observer, SIGNAL (dataChanged (int, int)), this, SLOT (receiveSignal (int, int)));
    connect (m_observer, SIGNAL (dataChanged (int, float)), this, SLOT (receiveSignal (int, float)));
    connect (m_observer, SIGNAL (dataChanged (int, unsigned int)), this, SLOT (receiveSignal (int, unsigned int)));
    connect (m_observer, SIGNAL (dataChanged (int, unsigned short)), this, SLOT (receiveSignal (int, unsigned short)));
    connect (m_observer, SIGNAL (dataChanged (int, unsigned char)), this, SLOT (receiveSignal (int, unsigned char)));
    connect (m_observer, SIGNAL (dataChanged (int, unsigned char*, unsigned int)), this, SLOT (receiveSignal (int, unsigned char*, unsigned int)));
    connect (m_observer, SIGNAL (newSignal (int, QString, DataType)), this, SLOT (handleNewSignal (int, QString, DataType)));

    m_subscriber = new QTimer();
    m_subscriber->setInterval(1000);
    connect(m_subscriber, SIGNAL(timeout()), this, SLOT(attemptSubscribe()));

}

DataEngineBase::~DataEngineBase()
{
    disconnectFromServer();
}

void DataEngineBase::initConnection(QString host, int port, QString clientName)
{
    // Connect and subscribe to signals
    setHost(host);
    setPort(port);
    setClientName(clientName);
    connectToServer();
    subscribeToSignals();
}

void DataEngineBase::checkConnectionSlot()
{
    ConnectionState state;
    state = (ConnectionState) m_sap.IsConnectedToServer();

    if(state != m_connectionState){
        m_connectionState = state;
        emit connectionStateChanged();
    }
}

void DataEngineBase::connectToServer()
{
    m_sap.Connect((char*) m_clientName.toStdString().c_str(), (char*)m_host.toStdString().c_str(), m_port);
}

void DataEngineBase::disconnectFromServer()
{
    m_sap.Disconnect();
}

void DataEngineBase::subscribeToSignals()
{
    m_subscriber->start();
}

void DataEngineBase::attemptSubscribe()
{
    if (!m_sap.IsConnectedToServer()) {
        qDebug() << "DataEngineBase::attemptSubscribe: Async Subscribe failed. No connection. Waiting a bit before next attempt.";
    }
    else {
        m_subscriber->stop();
        qDebug() << "DataEngineBase::attemptSubscribe: Async Subscribe successful. Subscribing...";
        setupSignalSubscriptions();
    }
}



void DataEngineBase::handleNewSignal (int id, QString signalName, DataType type)
{
    Q_UNUSED(type)
    qDebug() << QString ("DataEngineBase::handleNewSignal: Subscribing to signal named: %1, with id: %2").arg (signalName).arg (id);
    signalIdsByName[signalName] = id;
    signalNamesById[id] = signalName;
}

// Signal Catchers
void DataEngineBase::receiveSignal(int id, bool value)
{
    handleSignal(id, QVariant(value));
}
void DataEngineBase::receiveSignal(int id, signed char value)
{
    handleSignal(id, QVariant(value));
}
void DataEngineBase::receiveSignal(int id, int value)
{
    handleSignal(id, QVariant(value));
}
void DataEngineBase::receiveSignal(int id, short value)
{
    handleSignal(id, QVariant(value));
}
void DataEngineBase::receiveSignal(int id, float value)
{
    handleSignal(id, QVariant(value));
}
void DataEngineBase::receiveSignal(int id, unsigned int value)
{
    handleSignal(id, QVariant(value));
}
void DataEngineBase::receiveSignal(int id, unsigned char value)
{
    handleSignal(id, QVariant(value));
}
void DataEngineBase::receiveSignal(int id, unsigned short value)
{
    handleSignal(id, QVariant(value));
}
void DataEngineBase::receiveSignal(int id, unsigned char *value, unsigned int msgSize)
{
    // Look up qt type of signal
    QString qtType = lookupQtTypeNameByID(id);

    if (qtType == "QString") {
        handleSignal(id, QVariant(QString::fromUtf8((const char*)value,msgSize)));
    }
    else {
        // Default to raw QByteArray
        const char* v = reinterpret_cast<const char*>(value);
        QByteArray a(v, msgSize);
        handleSignal(id, QVariant(a));
    }
    delete value;
}

void DataEngineBase::handleSignal(int id, QVariant value)
{
    if (signalTypeDefs.contains(signalNamesById[id]))
        signalTypeDefs[signalNamesById[id]].signal->receiveValue(value);
    else
        qDebug() << QString("DataEngineBase::handleSignal: Recieved an unknown signal (id: %1)").arg(id);
}

void DataEngineBase::sendSignal(int id, QVariant value)
{
    QString qtType = lookupQtTypeNameByID(id);
    if (qtType == "UNDEFINED") {
        qDebug() << QString("DataEngineBase::sendSignal: Unknown signal id (provided id: %1)").arg(id);
        return;
    }

    if (qtType == "int") {
        m_sap.SetValue(id, value.toInt());
    }
    else if (qtType == "float") {
        m_sap.SetValue(id, value.toFloat());
    }
    else if (qtType == "short") {
        m_sap.SetValue(id, value.value<short>());
    }
    else if (qtType == "bool") {
        m_sap.SetValue(id, value.toBool());
    }
    else if (qtType == "signed char") {
        m_sap.SetValue(id, value.value<signed char>());
    }
    else if (qtType == "unsigned int") {
        m_sap.SetValue(id, value.value<unsigned int>());
    }
    else if (qtType == "unsigned short") {
        m_sap.SetValue(id, value.value<unsigned short>());
    }
    else if (qtType == "unsigned char") {
        m_sap.SetValue(id, value.value<unsigned char>());
    }
    else if (qtType == "QString") {
        int size = value.toString().toUtf8().size();
        if (size > MAXBLOBSIZE) {
            qDebug() << "TRYING TO SEND A BLOB LARGER THAN MAX SIZE! Aborting!";
            return;
        }
        char blob[size]; // 246 = MAXBLOBSIZE
        strcpy(blob,value.toString().toUtf8());
        m_sap.SetValue(id,(unsigned char*)blob,strlen(blob));
    }
    else if (qtType == "QByteArray") {
        char *blob = value.toByteArray().data();
        m_sap.SetValue(id,(unsigned char*)blob,value.toByteArray().length());
    }
    else
        qDebug() << QString("DataEngineBase::sendSignal: Unknown type [%1]!").arg(qtType);
}

void DataEngineBase::setupSignalSubscriptions()
{
    QMap<QString,SIGNALTYPEDEF>::iterator i;
    for (i = signalTypeDefs.begin(); i != signalTypeDefs.end(); ++i){
        char* nameBuffer = i.key().toLocal8Bit().data();

        m_sap.Subscribe(
                    nameBuffer,
                    i.value().dataType,
                    i.value().signalType,
                    i.value().persistent
                    );
    }
}

QString DataEngineBase::lookupQtTypeNameByID(int id)
{
    QString type;
    if (signalTypeDefs.contains(signalNamesById[id]))
        type = signalTypeDefs[signalNamesById[id]].qtTypeName;
    else
        type = "UNDEFINED";

    return type;
}

DataType DataEngineBase::propertyTypeToDataType(QString propertyType)
{
    DataType dt = DATATYPE_BOOL;

    if(!propertyType.compare("bool"))
    {
        dt = DATATYPE_BOOL;
    }
    if(!propertyType.compare("char"))
    {
        dt = DATATYPE_CHAR;
    }
    if(!propertyType.compare("short"))
    {
        dt = DATATYPE_SHORT;
    }
    if(!propertyType.compare("int"))
    {
         dt = DATATYPE_INT;
    }
    if(!propertyType.compare("float"))
    {
        dt = DATATYPE_FLOAT;
    }
    if(!propertyType.compare("unsigned int"))
    {
        dt = DATATYPE_UNSIGNED_INT;
    }
    if(!propertyType.compare("unsigned short"))
    {
        dt = DATATYPE_UNSIGNED_SHORT;
    }
    if(!propertyType.compare("unsigned char"))
    {
        dt = DATATYPE_UNSIGNED_CHAR;
    }
    if(!propertyType.compare("QString") || !propertyType.compare("QByeArray"))
    {
        dt = DATATYPE_BLOB;
    }

    return dt;
}

// Getters
DataEngineBase::ConnectionState DataEngineBase::connectionState() const
{
    return m_connectionState;
}

QString DataEngineBase::clientName() const
{
    return m_clientName;
}

QString DataEngineBase::host() const
{
    return m_host;
}

int DataEngineBase::port() const
{
    return m_port;
}

// Setters
void DataEngineBase::setConnectionState(DataEngineBase::ConnectionState state)
{
    if(state != m_connectionState){
        m_connectionState = state;
        emit connectionStateChanged();
    }
}

void DataEngineBase::setClientName(QString arg)
{
    if (m_clientName != arg) {
        m_clientName = arg;
        emit clientNameChanged(arg);
    }
}

void DataEngineBase::setHost(QString arg)
{
    if (m_host != arg) {
        m_host = arg;
        emit hostChanged(arg);
    }
}

void DataEngineBase::setPort(int arg)
{
    if (m_port != arg) {
        m_port = arg;
        emit portChanged(arg);
    }
}

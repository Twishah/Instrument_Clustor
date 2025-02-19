/* WARNING: AUTO-GENERATED FILE!
 * MANUAL EDITS WILL BE OVERWRITTEN BY "UPDATE PROJECT" IN LINX MANAGER PLUGIN.
 */

#ifndef DATAENGINEBASE_H
#define DATAENGINEBASE_H

#include <QObject>
#include <QMap>
#include <sapcore.h>
#include "qtobserver.h"
#include <QVariant>
#include "dataenginesignal.h"


class DataEngineBase : public QObject
{
    Q_OBJECT
    Q_ENUMS (ConnectionState)
    Q_PROPERTY(ConnectionState connectionState READ connectionState NOTIFY connectionStateChanged)
    Q_PROPERTY(QString clientName READ clientName WRITE setClientName NOTIFY clientNameChanged)
    Q_PROPERTY(QString host READ host WRITE setHost NOTIFY hostChanged)
    Q_PROPERTY(int port READ port WRITE setPort NOTIFY portChanged)

public:

#define MAXBLOBSIZE 248

    struct SIGNALTYPEDEF {
        DataType dataType;
        SignalType signalType;
        QString qtTypeName;
        bool persistent;
        int pgn;
        DataEngineSignal* signal;
    };

    enum ConnectionState{Disconnected = 0, Connected};  // Enum to indicate the DE connection state

    explicit DataEngineBase(QObject *parent = 0);
    ~DataEngineBase();

    // Getters
    ConnectionState connectionState() const;
    QString clientName() const;
    QString host() const;
    int port() const;

    // Setters
    void setConnectionState(ConnectionState state);
    void setClientName(QString arg);
    void setHost(QString arg);
    void setPort(int arg);

    // Functions
    void initConnection(QString host, int port, QString clientName);
    void connectToServer();
    void disconnectFromServer();
    void subscribeToSignals();

signals:
    void connectionStateChanged();
    void clientNameChanged(QString arg);
    void hostChanged(QString arg);
    void portChanged(int arg);

public slots:
    void handleNewSignal (int id, QString signalName, DataType type);

    void checkConnectionSlot();
    void receiveSignal(int id, bool value);
    void receiveSignal(int id, signed char value);
    void receiveSignal(int id, short value);
    void receiveSignal(int id, int value);
    void receiveSignal(int id, float value);
    void receiveSignal(int id, unsigned int value);
    void receiveSignal(int id, unsigned short value);
    void receiveSignal(int id, unsigned char value);
    void receiveSignal(int id, unsigned char* value, unsigned int msgSize);

protected:
    SAP m_sap;
    QMap<QString, int> signalIdsByName;
    QMap<int, QString> signalNamesById;
    QMap<QString, SIGNALTYPEDEF> signalTypeDefs;

    void handleSignal(int id, QVariant value);
    void sendSignal(int id, QVariant value);

    void setupSignalSubscriptions();
    QString lookupQtTypeNameByID(int id);

private slots:
    void attemptSubscribe();

private:
    QtObserver* m_observer;
    QTimer m_connectionTimer;

    ConnectionState m_connectionState;
    QString m_hostName;
    QString m_clientName;
    QString m_host;
    int m_port;

    QTimer *m_subscriber;

    DataType propertyTypeToDataType(QString propertyType);

};

#endif // DATAENGINEBASE_H

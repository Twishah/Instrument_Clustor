#ifndef QTOBSERVER_H
#define QTOBSERVER_H

#include <QObject>
#include <QTimer>
#include <sapcore.h>


#define CLIENTNAME "SubscribeReceiver"

class QtObserver : public QObject, public ISAPObserver
{
    Q_OBJECT
    //  Q_ENUMS(DataType)
public:
    QtObserver (QObject* parent = 0);

    void DataChanged (int id, signed char value);
    void DataChanged (int id, short value);
    void DataChanged (int id, int value);
    void DataChanged (int id, unsigned char value);
    void DataChanged (int id, unsigned short value);
    void DataChanged (int id, unsigned int value);
    void DataChanged (int id, bool value);
    void DataChanged (int id, float value);
    void DataChanged (int id, unsigned char* value, unsigned int msgSize); // BLOB

    void SyncChanged (int id, int value);
    void HandleMissedHeartBeat();
    bool HeartBeat();

    void NewSignal (int id, char* signalName, DataType type, Status err);

private:
    QTimer *m_syncTimer;
    int m_syncValue;
    int m_syncValueId;
    int m_heartBeat;
    int m_heartBeatId;

signals:
    void dataChanged (int index, signed char value);
    void dataChanged (int index, short value);
    void dataChanged (int index, int value);
    void dataChanged (int index, unsigned char value);
    void dataChanged (int index, unsigned short value);
    void dataChanged (int index, unsigned int value);
    void dataChanged (int index, bool value);
    void dataChanged (int index, float value);
    void dataChanged (int index, unsigned char* value, unsigned int msgSize);

    void syncChanged (int index, int value);

    void newSignal (int id, QString signalName, DataType type);

private slots:
    void handleHeartBeat();

};

#endif // QTOBSERVER_H

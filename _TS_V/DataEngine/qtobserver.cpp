#include "qtobserver.h"
#include <QDebug>
#include <QMetaType>

QtObserver::QtObserver (QObject* parent) :
    QObject (parent)
{
    qRegisterMetaType<DataType> ("DataType");

    m_syncTimer = new QTimer(this);
    m_syncValueId = -1;
    m_syncValue = 1; // Toggles between 1 and 2
    m_heartBeatId = -1;
    m_heartBeat = -1;
    connect (m_syncTimer, SIGNAL (timeout()), this, SLOT (handleHeartBeat()));
    m_syncTimer->setInterval (1000);
    m_syncTimer->start();
}

void QtObserver::DataChanged (int id, bool value)
{
//    qDebug ("data: %d %d", id, value);

    emit QtObserver::dataChanged (id, value);
}

void QtObserver::DataChanged (int id, signed char value)
{
//    qDebug ("data: %d %d", id, value);

    emit QtObserver::dataChanged (id, value);
}

void QtObserver::DataChanged (int id, float value)
{
//    qDebug ("data: %d %f", id, value);

    emit QtObserver::dataChanged (id, value);
}

void QtObserver::DataChanged (int id, short value)
{
//    qDebug ("data: %d %d", id, value);

    emit QtObserver::dataChanged (id, value);
}

void QtObserver::DataChanged (int id, int value)
{
//    qDebug ("data: %d %d", id, value);

    emit QtObserver::dataChanged (id, value);
}

void QtObserver::DataChanged (int id, unsigned char value)
{
//    qDebug ("data: %d %d", id, value);

    emit QtObserver::dataChanged (id, value);
}

void QtObserver::DataChanged (int id, unsigned short value)
{
//    qDebug ("data: %d %d", id, value);

    emit QtObserver::dataChanged (id, value);
}

void QtObserver::DataChanged (int id, unsigned int value)
{
//    qDebug ("data: %d %d", id, value);

    emit QtObserver::dataChanged (id, value);
}

void QtObserver::DataChanged(int id, unsigned char *value, unsigned int msgSize)
{
    emit QtObserver::dataChanged(id, value, msgSize);
}

void QtObserver::SyncChanged(int id, int value)
{
//    qDebug() << "SubscribeReceiver::SyncChanged Got VALUE, id:" << id << " val:" << value;
    if (id == m_syncValueId) {
        m_heartBeatId = id;
        m_heartBeat = value;
//        qDebug() << "Sending new syncvalue id:" << id << " val:" << value;
//    } //else {
    }
    emit QtObserver::syncChanged(id, value);
}

// toggle between 1 and 2 and return true if the heartBeat has toggled before timeout
bool QtObserver::HeartBeat()
{
//    qDebug ("SubscribeReceiver%d::HeartBeat %d", m_heartBeatId,  m_heartBeat);
    if (m_syncValue == m_heartBeat)
    {
        return true;
    } else {
        return false;
    }
}

void QtObserver::HandleMissedHeartBeat()
{
//    qDebug ("Sync (subscribereceiver %d) missed a heartbeat", m_heartBeatId);
    m_syncValue = 3 - m_syncValue;
}

void QtObserver::handleHeartBeat()
{
    m_syncValue = 3 - m_syncValue;
//    qDebug("**** SubscribeReceiver::handleHeartBeat ****");
    if (m_heartBeat <= 0)
    {
        qDebug ("Out of sync! id=%d\n", m_heartBeatId);
        m_syncTimer->stop();
    }
    else if (!HeartBeat()) {
        HandleMissedHeartBeat();
    }
}

void QtObserver::NewSignal(int id, char* signalName, DataType type, Status err)
{
//    qDebug() << "SubscribeReceiver::NewSignal New Signal received: " << id << signalName << type;

    if(type == DATATYPE_SYNC && QString(signalName).compare(CLIENTNAME) == 0) {
        m_syncValueId = id;
//        qDebug() << "SubscribeReceiver::NewSignal Setting sync ID to " << m_syncValueId;
        m_syncTimer->start();
    }

    if (err == STATUS_OK)
    {
        emit QtObserver::newSignal(id, QString(signalName), type);
    }
    else
    {
        qDebug() << "Illegal subscription (too many producers?)";
    }
}

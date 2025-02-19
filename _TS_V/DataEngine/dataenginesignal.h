/* WARNING: AUTO-GENERATED FILE!
 * MANUAL EDITS WILL BE OVERWRITTEN BY "UPDATE PROJECT" IN LINX MANAGER PLUGIN.
 */

#ifndef DATAENGINESIGNAL_H
#define DATAENGINESIGNAL_H

#include <QObject>
#include <QVariant>
#include <QSet>
#include "fieldbusaccesserror.h"

class DataEngineSignal : public QObject
{
    Q_OBJECT
    Q_PROPERTY(ErrorStatus status READ status NOTIFY statusChanged)
    Q_PROPERTY(QList<QObject*> errors READ errors NOTIFY errorsChanged)


public:
    explicit DataEngineSignal(bool rxFilter, bool txFilter, QVariant value = QVariant(), int pgn = -1, QObject *parent = 0);
    ~DataEngineSignal();

    enum ErrorStatus {
        OK = 0,
        SIGNALERROR = 1,
        STACKERROR = 2
    };
    Q_ENUMS(ErrorStatus)

    ErrorStatus status() const
    {
        return m_status;
    }

    bool rxFilter() const
    {
        return m_rxFilter;
    }

    bool txFilter() const
    {
        return m_txFilter;
    }

    QList<QObject*> errors() const
    {
        QList<QObject*> errs;
        foreach (FieldbusAccessError* err, m_errors) {
            errs.append((QObject*)err);
        }
        return errs;
    }

signals:
    void valueChanged(QVariant value);
    void sendValue(QVariant arg);
    void statusChanged(ErrorStatus arg);
    void errorsChanged(QList<QObject*> arg);

public slots:
    void receiveValue(QVariant value);
    void setValue(QVariant value);
    void setStatus(ErrorStatus status);
    void addError(FieldbusAccessError* error);
    void removeError(FieldbusAccessError* error);

protected:
    QVariant m_value;
    ErrorStatus m_status;
    int m_pgn;
    bool m_rxFilter;
    bool m_txFilter;
    QSet<FieldbusAccessError*> m_errors;
};



// CONSUMER WRAPPERS
class ConsumerSignal : public DataEngineSignal
{
    Q_OBJECT
    Q_PROPERTY(QVariant value READ value NOTIFY valueChanged)

public:
    explicit ConsumerSignal(bool rxFilter, bool txFilter, QVariant value, int pgn = -1, QObject *parent = 0);

    QVariant value() const
    {
        return m_value;
    }

signals:
    void valueChanged(QVariant arg);
};

class IntConsumerSignal : public DataEngineSignal
{
    Q_OBJECT
    Q_PROPERTY(int value READ value NOTIFY valueChanged)

public:
    explicit IntConsumerSignal(bool rxFilter, bool txFilter, int value, int pgn = -1, QObject *parent = 0);

    int value() const
    {
        return m_value.toInt();
    }

signals:
    void valueChanged(int arg);
};

class UIntConsumerSignal : public DataEngineSignal
{
    Q_OBJECT
    Q_PROPERTY(uint value READ value NOTIFY valueChanged)

public:
    explicit UIntConsumerSignal(bool rxFilter, bool txFilter, uint value, int pgn = -1, QObject *parent = 0);

    uint value() const
    {
        return m_value.toUInt();
    }

signals:
    void valueChanged(uint arg);
};

class ShortConsumerSignal : public DataEngineSignal
{
    Q_OBJECT
    Q_PROPERTY(short value READ value NOTIFY valueChanged)

public:
    explicit ShortConsumerSignal(bool rxFilter, bool txFilter, short value, int pgn = -1, QObject *parent = 0);

    short value() const
    {
        return m_value.value<short>();
    }

signals:
    void valueChanged(short arg);
};

class UShortConsumerSignal : public DataEngineSignal
{
    Q_OBJECT
    Q_PROPERTY(unsigned short value READ value NOTIFY valueChanged)

public:
    explicit UShortConsumerSignal(bool rxFilter, bool txFilter, unsigned short value, int pgn = -1, QObject *parent = 0);

    unsigned short value() const
    {
        return m_value.value<unsigned short>();
    }

signals:
    void valueChanged(unsigned short arg);
};

class CharConsumerSignal : public DataEngineSignal
{
    Q_OBJECT
    Q_PROPERTY(signed char value READ value NOTIFY valueChanged)

public:
    explicit CharConsumerSignal(bool rxFilter, bool txFilter, signed char value, int pgn = -1, QObject *parent = 0);

    signed char value() const
    {
        return m_value.value<signed char>();
    }

signals:
    void valueChanged(signed char arg);
};

class UCharConsumerSignal : public DataEngineSignal
{
    Q_OBJECT
    Q_PROPERTY(unsigned char value READ value NOTIFY valueChanged)

public:
    explicit UCharConsumerSignal(bool rxFilter, bool txFilter, unsigned char value, int pgn = -1, QObject *parent = 0);

    unsigned char value() const
    {
        return m_value.value<unsigned char>();
    }

signals:
    void valueChanged(unsigned char arg);
};

class BoolConsumerSignal : public DataEngineSignal
{
    Q_OBJECT
    Q_PROPERTY(bool value READ value NOTIFY valueChanged)

public:
    explicit BoolConsumerSignal(bool rxFilter, bool txFilter, bool value, int pgn = -1, QObject *parent = 0);

    bool value() const
    {
        return m_value.toBool();
    }

signals:
    void valueChanged(bool arg);
};

class FloatConsumerSignal : public DataEngineSignal
{
    Q_OBJECT
    Q_PROPERTY(float value READ value NOTIFY valueChanged)

public:
    explicit FloatConsumerSignal(bool rxFilter, bool txFilter, float value, int pgn = -1, QObject *parent = 0);

    float value() const
    {
        return m_value.toFloat();
    }

signals:
    void valueChanged(float arg);
};

class QByteArrayConsumerSignal : public DataEngineSignal
{
    Q_OBJECT
    Q_PROPERTY(QByteArray value READ value NOTIFY valueChanged)

public:
    explicit QByteArrayConsumerSignal(bool rxFilter, bool txFilter, QByteArray value, int pgn = -1, QObject *parent = 0);

    QByteArray value() const
    {
        return m_value.toByteArray();
    }

signals:
    void valueChanged(QByteArray arg);
};

class QStringConsumerSignal : public DataEngineSignal
{
    Q_OBJECT
    Q_PROPERTY(QString value READ value NOTIFY valueChanged)

public:
    explicit QStringConsumerSignal(bool rxFilter, bool txFilter, QString value, int pgn = -1, QObject *parent = 0);

    QString value() {
        return m_value.toString();
    }

signals:
    void valueChanged(QString arg);
};


// PRODUCER WRAPPERS
class ProducerSignal : public DataEngineSignal
{
    Q_OBJECT
    Q_PROPERTY(QVariant value READ value WRITE setValue NOTIFY valueChanged)

public:
    explicit ProducerSignal(bool rxFilter, bool txFilter, QVariant value, int pgn = -1, QObject *parent = 0);

    QVariant value() const
    {
        return m_value;
    }


signals:
    void valueChanged(QVariant arg);
    void sendValue(QVariant arg);

public slots:
    void setValue(QVariant value);
};

class IntProducerSignal : public DataEngineSignal
{
    Q_OBJECT
    Q_PROPERTY(int value READ value WRITE setValue NOTIFY valueChanged)

public:
    explicit IntProducerSignal(bool rxFilter, bool txFilter, int value, int pgn = -1, QObject *parent = 0);

    int value() {
        return m_value.toInt();
    }

public slots:
    void setValue(int v);

signals:
    void valueChanged(int arg);
    void sendValue(int arg);
};

class UIntProducerSignal : public DataEngineSignal
{
    Q_OBJECT
    Q_PROPERTY(uint value READ value WRITE setValue NOTIFY valueChanged)

public:
    explicit UIntProducerSignal(bool rxFilter, bool txFilter, uint value, int pgn = -1, QObject *parent = 0);

    uint value() {
        return m_value.toUInt();
    }

public slots:
    void setValue(uint v);

signals:
    void valueChanged(uint arg);
    void sendValue(uint arg);
};

class ShortProducerSignal : public DataEngineSignal
{
    Q_OBJECT
    Q_PROPERTY(short value READ value WRITE setValue NOTIFY valueChanged)

public:
    explicit ShortProducerSignal(bool rxFilter, bool txFilter, short value, int pgn = -1, QObject *parent = 0);

    short value() {
        return m_value.value<short>();
    }

public slots:
    void setValue(short v);

signals:
    void valueChanged(short arg);
    void sendValue(short arg);
};

class UShortProducerSignal : public DataEngineSignal
{
    Q_OBJECT
    Q_PROPERTY(ushort value READ value WRITE setValue NOTIFY valueChanged)

public:
    explicit UShortProducerSignal(bool rxFilter, bool txFilter, ushort value, int pgn = -1, QObject *parent = 0);

    ushort value() {
        return m_value.value<ushort>();
    }

public slots:
    void setValue(ushort v);

signals:
    void valueChanged(ushort arg);
    void sendValue(ushort arg);
};

class CharProducerSignal : public DataEngineSignal
{
    Q_OBJECT
    Q_PROPERTY(signed char value READ value WRITE setValue NOTIFY valueChanged)

public:
    explicit CharProducerSignal(bool rxFilter, bool txFilter, signed char value, int pgn = -1, QObject *parent = 0);

    signed char value() {
        return m_value.value<signed char>();
    }

public slots:
    void setValue(signed char v);

signals:
    void valueChanged(signed char arg);
    void sendValue(signed char arg);
};

class UCharProducerSignal : public DataEngineSignal
{
    Q_OBJECT
    Q_PROPERTY(unsigned char value READ value WRITE setValue NOTIFY valueChanged)

public:
    explicit UCharProducerSignal(bool rxFilter, bool txFilter, unsigned char value, int pgn = -1, QObject *parent = 0);

    unsigned char value() {
        return m_value.value<unsigned char>();
    }

public slots:
    void setValue(unsigned char v);

signals:
    void valueChanged(unsigned char arg);
    void sendValue(unsigned char arg);
};

class BoolProducerSignal : public DataEngineSignal
{
    Q_OBJECT
    Q_PROPERTY(bool value READ value WRITE setValue NOTIFY valueChanged)

public:
    explicit BoolProducerSignal(bool rxFilter, bool txFilter, bool value, int pgn = -1, QObject *parent = 0);

    bool value() {
        return m_value.toBool();
    }

public slots:
    void setValue(bool v);

signals:
    void valueChanged(bool arg);
    void sendValue(bool arg);
};

class FloatProducerSignal : public DataEngineSignal
{
    Q_OBJECT
    Q_PROPERTY(float value READ value WRITE setValue NOTIFY valueChanged)

public:
    explicit FloatProducerSignal(bool rxFilter, bool txFilter, float value, int pgn = -1, QObject *parent = 0);

    float value() {
        return m_value.toFloat();
    }

public slots:
    void setValue(float v);

signals:
    void valueChanged(float arg);
    void sendValue(float arg);
};

class QByteArrayProducerSignal : public DataEngineSignal
{
    Q_OBJECT
    Q_PROPERTY(QByteArray value READ value WRITE setValue NOTIFY valueChanged)

public:
    explicit QByteArrayProducerSignal(bool rxFilter, bool txFilter, QByteArray value, int pgn = -1, QObject *parent = 0);

    QByteArray value() {
        return m_value.toByteArray();
    }

public slots:
    void setValue(QByteArray v);

signals:
    void valueChanged(QByteArray arg);
    void sendValue(QByteArray arg);
};

class QStringProducerSignal : public DataEngineSignal
{
    Q_OBJECT
    Q_PROPERTY(QString value READ value WRITE setValue NOTIFY valueChanged)

public:
    explicit QStringProducerSignal(bool rxFilter, bool txFilter, QString value, int pgn = -1, QObject *parent = 0);

    QString value() {
        return m_value.toString();
    }

public slots:
    void setValue(QString v);

signals:
    void valueChanged(QString arg);
    void sendValue(QString arg);
};


#endif // DATAENGINESIGNAL_H

/* WARNING: AUTO-GENERATED FILE!
 * MANUAL EDITS WILL BE OVERWRITTEN BY "UPDATE PROJECT" IN LINX MANAGER PLUGIN.
 */

#include "dataenginesignal.h"

DataEngineSignal::DataEngineSignal(bool rxFilter, bool txFilter, QVariant value, int pgn, QObject *parent) : QObject(parent)
{
    m_value = value;
    m_pgn = pgn;
    m_status = OK;
    m_rxFilter = rxFilter;
    m_txFilter = txFilter;
}

DataEngineSignal::~DataEngineSignal()
{

}

void DataEngineSignal::receiveValue(QVariant value)
{
    if (m_value == value && m_rxFilter)
        return;

    m_value = value;
    emit valueChanged(m_value);
}

void DataEngineSignal::setValue(QVariant value)
{
    if (m_value == value && m_txFilter)
        return;

    m_value = value;
    emit valueChanged(m_value);
    emit sendValue(m_value);
}

void DataEngineSignal::setStatus(DataEngineSignal::ErrorStatus status)
{
    if (m_status == status)
        return;

    m_status = status;
    emit statusChanged(status);

}

void DataEngineSignal::addError(FieldbusAccessError *error)
{
    m_errors.insert(error);
    emit errorsChanged(errors());
}

void DataEngineSignal::removeError(FieldbusAccessError *error)
{
    m_errors.remove(error);
    emit errorsChanged(errors());
}


ConsumerSignal::ConsumerSignal(bool rxFilter, bool txFilter, QVariant value, int pgn, QObject *parent) : DataEngineSignal(rxFilter, txFilter, value, pgn, parent)
{
    connect(
                this,
                &DataEngineSignal::valueChanged,
                this,
                [this](){ emit valueChanged(this->value()); }
    );
}

IntConsumerSignal::IntConsumerSignal(bool rxFilter, bool txFilter, int value, int pgn, QObject *parent)  : DataEngineSignal(rxFilter, txFilter, QVariant(value), pgn, parent)
{
    connect(
                this,
                &DataEngineSignal::valueChanged,
                this,
                [this](){ emit valueChanged(this->value()); }
    );

}

UIntConsumerSignal::UIntConsumerSignal(bool rxFilter, bool txFilter, uint value, int pgn, QObject *parent)  : DataEngineSignal(rxFilter, txFilter, QVariant(value), pgn, parent)
{
    connect(
                this,
                &DataEngineSignal::valueChanged,
                this,
                [this](){ emit valueChanged(this->value()); }
    );

}

ShortConsumerSignal::ShortConsumerSignal(bool rxFilter, bool txFilter, short value, int pgn, QObject *parent)  : DataEngineSignal(rxFilter, txFilter, QVariant(value), pgn, parent)
{
    connect(
                this,
                &DataEngineSignal::valueChanged,
                this,
                [this](){ emit valueChanged(this->value()); }
    );

}

UShortConsumerSignal::UShortConsumerSignal(bool rxFilter, bool txFilter, unsigned short value, int pgn, QObject *parent)  : DataEngineSignal(rxFilter, txFilter, QVariant(value), pgn, parent)
{
    connect(
                this,
                &DataEngineSignal::valueChanged,
                this,
                [this](){ emit valueChanged(this->value()); }
    );

}

CharConsumerSignal::CharConsumerSignal(bool rxFilter, bool txFilter, signed char value, int pgn, QObject *parent)  : DataEngineSignal(rxFilter, txFilter, QVariant(value), pgn, parent)
{
    connect(
                this,
                &DataEngineSignal::valueChanged,
                this,
                [this](){ emit valueChanged(this->value()); }
    );

}

UCharConsumerSignal::UCharConsumerSignal(bool rxFilter, bool txFilter, unsigned char value, int pgn, QObject *parent)  : DataEngineSignal(rxFilter, txFilter, QVariant(value), pgn, parent)
{
    connect(
                this,
                &DataEngineSignal::valueChanged,
                this,
                [this](){ emit valueChanged(this->value()); }
    );

}

BoolConsumerSignal::BoolConsumerSignal(bool rxFilter, bool txFilter, bool value, int pgn, QObject *parent)  : DataEngineSignal(rxFilter, txFilter, QVariant(value), pgn, parent)
{
    connect(
                this,
                &DataEngineSignal::valueChanged,
                this,
                [this](){ emit valueChanged(this->value()); }
    );

}

FloatConsumerSignal::FloatConsumerSignal(bool rxFilter, bool txFilter, float value, int pgn, QObject *parent)  : DataEngineSignal(rxFilter, txFilter, QVariant(value), pgn, parent)
{
    connect(
                this,
                &DataEngineSignal::valueChanged,
                this,
                [this](){ emit valueChanged(this->value()); }
    );

}

QByteArrayConsumerSignal::QByteArrayConsumerSignal(bool rxFilter, bool txFilter, QByteArray value, int pgn, QObject *parent)  : DataEngineSignal(rxFilter, txFilter, QVariant(value), pgn, parent)
{
    connect(
                this,
                &DataEngineSignal::valueChanged,
                this,
                [this](){ emit valueChanged(this->value()); }
    );

}

QStringConsumerSignal::QStringConsumerSignal(bool rxFilter, bool txFilter, QString value, int pgn, QObject *parent)  : DataEngineSignal(rxFilter, txFilter, QVariant(value), pgn, parent)
{
    connect(
                this,
                &DataEngineSignal::valueChanged,
                this,
                [this](){ emit valueChanged(this->value()); }
    );

}

ProducerSignal::ProducerSignal(bool rxFilter, bool txFilter, QVariant value, int pgn, QObject *parent) : DataEngineSignal(rxFilter, txFilter, value, pgn, parent)
{
    connect(
                this,
                &DataEngineSignal::valueChanged,
                this,
                [this](){ emit valueChanged(this->value()); }
    );
    connect(
                this,
                &DataEngineSignal::sendValue,
                this,
                [this](){ emit sendValue(this->value()); }
    );

}

void ProducerSignal::setValue(QVariant value)
{
    if (m_value == value && m_txFilter)
        return;

    m_value = value;
    emit valueChanged(m_value);
    emit sendValue(m_value);
}

IntProducerSignal::IntProducerSignal(bool rxFilter, bool txFilter, int value, int pgn, QObject *parent)  : DataEngineSignal(rxFilter, txFilter, QVariant(value), pgn, parent)
{
    connect(
                this,
                &DataEngineSignal::valueChanged,
                this,
                [this](){ emit valueChanged(this->value()); }
    );
    connect(
                this,
                &DataEngineSignal::sendValue,
                this,
                [this](){ emit sendValue(this->value()); }
    );

}

void IntProducerSignal::setValue(int v)
{
    if (m_value.toInt() == v && m_txFilter)
        return;

    m_value = QVariant(v);
    emit valueChanged(v);
    emit sendValue(v);
}

UIntProducerSignal::UIntProducerSignal(bool rxFilter, bool txFilter, uint value, int pgn, QObject *parent)  : DataEngineSignal(rxFilter, txFilter, QVariant(value), pgn, parent)
{
    connect(
                this,
                &DataEngineSignal::valueChanged,
                this,
                [this](){ emit valueChanged(this->value()); }
    );
    connect(
                this,
                &DataEngineSignal::sendValue,
                this,
                [this](){ emit sendValue(this->value()); }
    );

}

void UIntProducerSignal::setValue(uint v)
{
    if (m_value.toUInt() == v && m_txFilter)
        return;

    m_value = QVariant(v);
    emit valueChanged(v);
    emit sendValue(v);
}

ShortProducerSignal::ShortProducerSignal(bool rxFilter, bool txFilter, short value, int pgn, QObject *parent)  : DataEngineSignal(rxFilter, txFilter, QVariant(value), pgn, parent)
{
    connect(
                this,
                &DataEngineSignal::valueChanged,
                this,
                [this](){ emit valueChanged(this->value()); }
    );
    connect(
                this,
                &DataEngineSignal::sendValue,
                this,
                [this](){ emit sendValue(this->value()); }
    );

}

void ShortProducerSignal::setValue(short v)
{
    if (m_value.value<short>() == v && m_txFilter)
        return;

    m_value = QVariant(v);
    emit valueChanged(v);
    emit sendValue(v);
}

UShortProducerSignal::UShortProducerSignal(bool rxFilter, bool txFilter, ushort value, int pgn, QObject *parent)  : DataEngineSignal(rxFilter, txFilter, QVariant(value), pgn, parent)
{
    connect(
                this,
                &DataEngineSignal::valueChanged,
                this,
                [this](){ emit valueChanged(this->value()); }
    );
    connect(
                this,
                &DataEngineSignal::sendValue,
                this,
                [this](){ emit sendValue(this->value()); }
    );

}

void UShortProducerSignal::setValue(ushort v)
{
    if (m_value.value<ushort>() == v && m_txFilter)
        return;

    m_value = QVariant(v);
    emit valueChanged(v);
    emit sendValue(v);
}

CharProducerSignal::CharProducerSignal(bool rxFilter, bool txFilter, signed char value, int pgn, QObject *parent)  : DataEngineSignal(rxFilter, txFilter, QVariant(value), pgn, parent)
{
    connect(
                this,
                &DataEngineSignal::valueChanged,
                this,
                [this](){ emit valueChanged(this->value()); }
    );
    connect(
                this,
                &DataEngineSignal::sendValue,
                this,
                [this](){ emit sendValue(this->value()); }
    );

}

void CharProducerSignal::setValue(signed char v)
{
    if (m_value.value<signed char>() == v && m_txFilter)
        return;

    m_value = QVariant(v);
    emit valueChanged(v);
    emit sendValue(v);
}

UCharProducerSignal::UCharProducerSignal(bool rxFilter, bool txFilter, unsigned char value, int pgn, QObject *parent)  : DataEngineSignal(rxFilter, txFilter, QVariant(value), pgn, parent)
{
    connect(
                this,
                &DataEngineSignal::valueChanged,
                this,
                [this](){ emit valueChanged(this->value()); }
    );
    connect(
                this,
                &DataEngineSignal::sendValue,
                this,
                [this](){ emit sendValue(this->value()); }
    );

}

void UCharProducerSignal::setValue(unsigned char v)
{
    if (m_value.value<unsigned char>() == v && m_txFilter)
        return;

    m_value = QVariant(v);
    emit valueChanged(v);
    emit sendValue(v);
}

BoolProducerSignal::BoolProducerSignal(bool rxFilter, bool txFilter, bool value, int pgn, QObject *parent)  : DataEngineSignal(rxFilter, txFilter, QVariant(value), pgn, parent)
{
    connect(
                this,
                &DataEngineSignal::valueChanged,
                this,
                [this](){ emit valueChanged(this->value()); }
    );
    connect(
                this,
                &DataEngineSignal::sendValue,
                this,
                [this](){ emit sendValue(this->value()); }
    );

}

void BoolProducerSignal::setValue(bool v)
{
    if (m_value.toBool() == v && m_txFilter)
        return;

    m_value = QVariant(v);
    emit valueChanged(v);
    emit sendValue(v);
}

FloatProducerSignal::FloatProducerSignal(bool rxFilter, bool txFilter, float value, int pgn, QObject *parent)  : DataEngineSignal(rxFilter, txFilter, QVariant(value), pgn, parent)
{
    connect(
                this,
                &DataEngineSignal::valueChanged,
                this,
                [this](){ emit valueChanged(this->value()); }
    );
    connect(
                this,
                &DataEngineSignal::sendValue,
                this,
                [this](){ emit sendValue(this->value()); }
    );

}

void FloatProducerSignal::setValue(float v)
{
    if (m_value.toFloat() == v && m_txFilter)
        return;

    m_value = QVariant(v);
    emit valueChanged(v);
    emit sendValue(v);
}

QByteArrayProducerSignal::QByteArrayProducerSignal(bool rxFilter, bool txFilter, QByteArray value, int pgn, QObject *parent)  : DataEngineSignal(rxFilter, txFilter, QVariant(value), pgn, parent)
{
    connect(
                this,
                &DataEngineSignal::valueChanged,
                this,
                [this](){ emit valueChanged(this->value()); }
    );
    connect(
                this,
                &DataEngineSignal::sendValue,
                this,
                [this](){ emit sendValue(this->value()); }
    );

}

void QByteArrayProducerSignal::setValue(QByteArray v)
{
    if (m_value.toByteArray() == v && m_txFilter)
        return;

    m_value = QVariant(v);
    emit valueChanged(v);
    emit sendValue(v);
}

QStringProducerSignal::QStringProducerSignal(bool rxFilter, bool txFilter, QString value, int pgn, QObject *parent)  : DataEngineSignal(rxFilter, txFilter, QVariant(value), pgn, parent)
{
    connect(
                this,
                &DataEngineSignal::valueChanged,
                this,
                [this](){ emit valueChanged(this->value()); }
    );
    connect(
                this,
                &DataEngineSignal::sendValue,
                this,
                [this](){ emit sendValue(this->value()); }
    );

}

void QStringProducerSignal::setValue(QString v)
{
    if (m_value.toString() == v && m_txFilter)
        return;

    m_value = QVariant(v);
    emit valueChanged(v);
    emit sendValue(v);
}

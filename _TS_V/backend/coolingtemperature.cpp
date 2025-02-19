#include "coolingtemperature.h"

CoolingTemperature::CoolingTemperature(QObject *parent) : QObject(parent)
{
    m_coolingTempMCU = 0;
}

/* SETTERS */
void CoolingTemperature::setCoolingTempMCU(int coolingTempMCU)
{
//    qDebug() << "Setting the cooling temperature of the MCU";
    if (m_coolingTempMCU == coolingTempMCU)
        return;

    m_coolingTempMCU = coolingTempMCU;
    //emit coolingTempMCUChanged(m_coolingTempMCU);

//    qDebug() << "Cooling temperature of the MCU changed!";
    calculateCoolingTemperature(m_coolingTempMCU);
}

void CoolingTemperature::setCoolingTempCelsiusCpp(QString coolingTempCelsiusCpp)
{
//    qDebug() << "Setting the cooling temperature in Celsius";
    if (m_coolingTempCelsiusCpp == coolingTempCelsiusCpp)
        return;

    m_coolingTempCelsiusCpp = coolingTempCelsiusCpp;
    emit coolingTempCelsiusCppChanged(m_coolingTempCelsiusCpp);
}

void CoolingTemperature::setCoolingTempFahrenheitCpp(QString coolingTempFahrenheitCpp)
{
//    qDebug() << "Setting the cooling temperature in Fahrenheit";
    if (m_coolingTempFahrenheitCpp == coolingTempFahrenheitCpp)
        return;

    m_coolingTempFahrenheitCpp = coolingTempFahrenheitCpp;
    emit coolingTempFahrenheitCppChanged(m_coolingTempFahrenheitCpp);
}

/* GETTERS */
int CoolingTemperature::getCoolingTempMCU() const
{
//    qDebug() << "Getting the cooling temperature of the MCU";
    return m_coolingTempMCU;
}

QString CoolingTemperature::getCoolingTempCelsiusCpp() const
{
//    qDebug() << "Getting the cooling temperature in Celsius";
    return m_coolingTempCelsiusCpp;
}

QString CoolingTemperature::getCoolingTempFahrenheitCpp() const
{
//    qDebug() << "Getting the cooling temperature in Fahrenheit";
    return m_coolingTempFahrenheitCpp;
}

/* CALCULATIONS */
void CoolingTemperature::calculateCoolingTemperature(int coolingTempMCU)
{
    setCoolingTempCelsiusCpp(calculateCoolingTempCelsius(coolingTempMCU));
    setCoolingTempFahrenheitCpp(calculateCoolingTempFahrenheit(coolingTempMCU));

//    qDebug() << "Sending result of CT from C++";
}

QString CoolingTemperature::calculateCoolingTempCelsius(int coolingTempMCU)
{
    int value = 0;
    QString result = "0°C";

    if (coolingTempMCU > 210) {
        value = 210;
    }
    else if (coolingTempMCU < -40)
        value = -40;
    else {
        value = coolingTempMCU;
    }

    result = QString::number(value) + "°C";
    //qDebug() << result;
    return result;
}

QString CoolingTemperature::calculateCoolingTempFahrenheit(int coolingTempMCU)
{
    int valueCelsius = 0;
    int value = 32;
    QString result = "32°F";

    if (coolingTempMCU > 210) {
        valueCelsius = 210;
    }
    else if (coolingTempMCU < -40)
        valueCelsius = -40;
    else {
        valueCelsius = coolingTempMCU;
    }

    value = round((1.8 * valueCelsius) + 32);

    result = QString::number(value) + "°F";
    //qDebug() << result;
    return result;
}


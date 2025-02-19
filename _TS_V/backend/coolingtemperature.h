#ifndef COOLINGTEMPERATURE_H
#define COOLINGTEMPERATURE_H

#include <QObject>
#include <QDebug>
#include <QString>

#include <iostream>
#include <cmath>
using namespace std;

class CoolingTemperature : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int coolingTempMCU READ getCoolingTempMCU WRITE setCoolingTempMCU)
    Q_PROPERTY(QString coolingTempCelsiusCpp READ getCoolingTempCelsiusCpp WRITE setCoolingTempCelsiusCpp NOTIFY coolingTempCelsiusCppChanged)
    Q_PROPERTY(QString coolingTempFahrenheitCpp READ getCoolingTempFahrenheitCpp WRITE setCoolingTempFahrenheitCpp NOTIFY coolingTempFahrenheitCppChanged)


public:
    explicit CoolingTemperature(QObject *parent = nullptr);

    void setCoolingTempMCU(int coolingTempMCU);
    void setCoolingTempCelsiusCpp(QString coolingTempCelsiusCpp);
    void setCoolingTempFahrenheitCpp(QString coolingTempFahrenheitCpp);

    int getCoolingTempMCU() const;
    QString getCoolingTempCelsiusCpp() const;
    QString getCoolingTempFahrenheitCpp() const;

signals:
    //void coolingTempMCUChanged(int coolingTempMCU);
    void coolingTempCelsiusCppChanged(QString coolingTempCelsiusCpp);
    void coolingTempFahrenheitCppChanged(QString coolingTempFahrenheitCpp);

public slots:


private:
    int m_coolingTempMCU;
    QString m_coolingTempCelsiusCpp;
    QString m_coolingTempFahrenheitCpp;

    const int cTemp_min = -99;
    const int cTemp_max = 999;

    void calculateCoolingTemperature(int coolingTempMCU);
    QString calculateCoolingTempCelsius(int coolingTempMCU);
    QString calculateCoolingTempFahrenheit(int coolingTempMCU);

};

#endif // COOLINGTEMPERATURE_H

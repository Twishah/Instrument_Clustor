#include "maintenancehistory.h"

MaintenanceHistory::MaintenanceHistory(QObject *parent)
{
    setParent(parent);
    m_date1 = "";
    m_hourMeter1 = 0.0;
    m_date2 = "";
    m_hourMeter2 = 0.0;
}

QString MaintenanceHistory::get_date1()
{
    return m_date1;
}

void MaintenanceHistory::set_date1(QString date1)
{
    m_date1 = date1;
    emit date1Changed(m_date1);
}

double MaintenanceHistory::get_hourMeter1()
{
    return m_hourMeter1;
}

void MaintenanceHistory::set_hourMeter1(double hourMeter1)
{
    m_hourMeter1 = hourMeter1;
    emit hourMeter1Changed(m_hourMeter1);
}

QString MaintenanceHistory::get_date2()
{
    return m_date2;
}

void MaintenanceHistory::set_date2(QString date2)
{
    m_date2 = date2;
    emit date2Changed(m_date2);
}

double MaintenanceHistory::get_hourMeter2()
{
    return m_hourMeter2;
}

void MaintenanceHistory::set_hourMeter2(double hourMeter2)
{
    m_hourMeter2 = hourMeter2;
    emit hourMeter2Changed(m_hourMeter2);
}

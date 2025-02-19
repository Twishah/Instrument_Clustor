#include "mechanichistory.h"

MechanicHistory::MechanicHistory(QObject *parent)
{
    setParent(parent);
    m_dateMecHist = "";
    m_timeMecHist = "";
    m_hourmeterMecHist = 0;
}



QString MechanicHistory::get_dateMecHist()
{
    return m_dateMecHist;
}

void MechanicHistory::set_dateMecHist(QString dateMecHist)
{
    m_dateMecHist = dateMecHist;
    emit dateMecHistChanged(m_dateMecHist);
}

QString MechanicHistory::get_timeMecHist()
{
    return m_timeMecHist;
}

void MechanicHistory::set_timeMecHist(QString timeMecHist)
{
    m_timeMecHist = timeMecHist;
    emit timeMecHistChanged(m_timeMecHist);
}

double MechanicHistory::get_hourmeterMecHist()
{
    return m_hourmeterMecHist;
}

void MechanicHistory::set_hourmeterMecHist(double hourmeterMecHist)
{
    m_hourmeterMecHist = hourmeterMecHist;
    emit hourmeterMecHistChanged(m_hourmeterMecHist);
}

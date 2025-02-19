
#include "preheating.h"

Pre_heating_settings::Pre_heating_settings(QObject *parent)
{
    setParent(parent);

    m_start_minutes = 0;
    m_start_hours = 0;
    m_active = false;
    m_am_pm = "";
    m_date = { false, false, false, false, false, false, false };
}

/**
* @brief Gets the work start minutes
* @return The work start minutes.
*/
int Pre_heating_settings::start_minutes()
{
    return m_start_minutes;
}

/**
* @brief Gets the work start hours
* @return The work start hours.
*/
int Pre_heating_settings::start_hours()
{
    return m_start_hours;
}

/**
* @brief Gets the pre heating state on/off
* @return The activate state.
*/
bool Pre_heating_settings::active()
{
    return m_active;
}

/**
* @brief Gets the am pm info
* @return The am pm info.
*/
QString Pre_heating_settings::am_pm()
{
    return m_am_pm;
}

/**
* @brief Gets the list of dates when pre heating should be actif
* @return The date list.
*/
bool Pre_heating_settings::get_date(int index)
{
    return m_date[index];
}

/**
* @brief Sets the work start minutes
*/
void Pre_heating_settings::set_start_minutes(int start_minutes)
{
    m_start_minutes = start_minutes;
}

/**
* @brief Sets the work start hours
*/
void Pre_heating_settings::set_start_hours(int start_hours)
{
    m_start_hours = start_hours;
}

/**
* @brief Sets the pre heating state
*/
void Pre_heating_settings::set_active(bool active)
{
    m_active = active;
    emit activeChanged(m_active);
}

/**
* @brief Sets the am pm info
*/
void Pre_heating_settings::set_am_pm(QString am_pm)
{
    if(am_pm == "PM" || am_pm == "AM")
        m_am_pm = am_pm;
}

/**
* @brief Sets the active dates
*/
void Pre_heating_settings::set_date(int index, bool state)
{
    m_date[index] = state;
}

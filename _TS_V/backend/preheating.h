#ifndef PREHEATING_H
#define PREHEATING_H

/******************************************************************************
 * Include Files
******************************************************************************/
#include <QObject>
#include <QtQml>

/******************************************************************************
 * Class Declaration
******************************************************************************/
/*
 * The pre heating settings
 * structure
 */

class Pre_heating_settings : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int start_minutes READ start_minutes WRITE set_start_minutes)
    Q_PROPERTY(int start_hours READ start_hours WRITE set_start_hours)
    Q_PROPERTY(QString am_pm READ am_pm WRITE set_am_pm)
    Q_PROPERTY(bool active READ active WRITE set_active NOTIFY activeChanged)

public:
    explicit Pre_heating_settings(QObject *parent = 0);

    int start_minutes();
    int start_hours();
    bool active();
    QString am_pm();
    bool get_date(int index);

    void set_start_minutes(int start_minutes);
    void set_start_hours(int start_hours);
    void set_active(bool active);
    void set_am_pm(QString am_pm);
    void set_date(int index, bool state);


signals:
    void activeChanged(bool active);


private:
    int m_start_minutes;
    int m_start_hours;
    bool m_active;
    QString m_am_pm;
    QList<bool> m_date;

};

#endif // PREHEATING_H

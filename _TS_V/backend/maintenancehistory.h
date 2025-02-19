#ifndef MAINTENANCEHISTORY_H
#define MAINTENANCEHISTORY_H

#include <QObject>

class MaintenanceHistory : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString date1 READ get_date1 WRITE set_date1 NOTIFY date1Changed)
    Q_PROPERTY(double hourMeter1 READ get_hourMeter1 WRITE set_hourMeter1 NOTIFY hourMeter1Changed)
    Q_PROPERTY(QString date2 READ get_date2 WRITE set_date2 NOTIFY date2Changed)
    Q_PROPERTY(double hourMeter2 READ get_hourMeter2 WRITE set_hourMeter2 NOTIFY hourMeter2Changed)

public:
    explicit MaintenanceHistory(QObject *parent = 0);

    /* Functions used for maintenance history management of an item */

    /* Functions used for old history date management */
    Q_INVOKABLE QString get_date1();
    void set_date1(QString date1);

    /* Functions used for old history hour meter management */
    Q_INVOKABLE double get_hourMeter1();
    void set_hourMeter1(double hourMeter1);

    /* Functions used for new history date management */
    Q_INVOKABLE QString get_date2();
    void set_date2(QString date2);

    /* Functions used for new history hour meter management */
    Q_INVOKABLE double get_hourMeter2();
    void set_hourMeter2(double hourMeter2);

signals:
    void date1Changed(QString date1);
    void hourMeter1Changed(double hourMeter1);
    void date2Changed(QString date2);
    void hourMeter2Changed(double hourMeter2);

public slots:



private:
    // maintenance history of an item
    QString m_date1;
    double m_hourMeter1;
    QString m_date2;
    double m_hourMeter2;
};

#endif // MAINTENANCEHISTORY_H

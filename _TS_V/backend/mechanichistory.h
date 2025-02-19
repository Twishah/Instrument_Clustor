#ifndef MECHANICHISTORY_H
#define MECHANICHISTORY_H

#include <QObject>
#include <QDebug>

class MechanicHistory : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString dateMecHist READ get_dateMecHist WRITE set_dateMecHist NOTIFY dateMecHistChanged)
    Q_PROPERTY(QString timeMecHist READ get_timeMecHist WRITE set_timeMecHist NOTIFY timeMecHistChanged)
    Q_PROPERTY(double hourmeterMecHist READ get_hourmeterMecHist WRITE set_hourmeterMecHist NOTIFY hourmeterMecHistChanged)


public:
    explicit MechanicHistory(QObject *parent = 0);

    /* Functions used for mechanic usage history management of an item */

    /* Functions used for mechanic usage history date management */
    Q_INVOKABLE QString get_dateMecHist();
    void set_dateMecHist(QString dateMecHist);

    /* Functions used for mechanic usage history time management */
    Q_INVOKABLE QString get_timeMecHist();
    void set_timeMecHist(QString timeMecHist);

    /* Functions used for mechanic usage history hour meter management */
    Q_INVOKABLE double get_hourmeterMecHist();
    void set_hourmeterMecHist(double hourmeterMecHist);

signals:
    void dateMecHistChanged(QString dateMecHist);
    void timeMecHistChanged(QString timeMecHist);
    void hourmeterMecHistChanged(double hourmeterMecHist);

public slots:


private:
    // mechanic usage history of an item
    QString m_dateMecHist;
    QString m_timeMecHist;
    double m_hourmeterMecHist;
};

#endif // MECHANICHISTORY_H

#ifndef DATETIMEMANAGER_H
#define DATETIMEMANAGER_H

#include <QObject>
#include <QProcess>
#include <QDateTime>
#include <QDate>
#include <QTime>
#include <QTimeZone>
#include <QString>
#include <QDebug>


class DateTimeManager : public QObject
{
    Q_OBJECT

    Q_PROPERTY (QDateTime dateTime READ getCurrentDateTime() NOTIFY dateTimeChanged)

public:
    explicit DateTimeManager(QObject *parent = 0);

    QDateTime getCurrentDateTime() const;
    Q_INVOKABLE QDateTime getUTCDateTime() const;
    Q_INVOKABLE void setTimeZone(const QString& timeZoneId);
    Q_INVOKABLE void setTimeFormat(const QString& format);
    Q_INVOKABLE void setDaylightSavingTime(bool daylightSavingTime);
    Q_INVOKABLE bool getDaylightSavingTime();
    Q_INVOKABLE QString formatDateTime(const QDateTime& dateTime, const QString& format) const;
    Q_INVOKABLE QString getTimeFormat(void);
    Q_INVOKABLE QString getCurrentTime() const;
    Q_INVOKABLE QString getCurrentTimeCustomFormat(QString timeFormat) const;
    Q_INVOKABLE QDateTime getCurrentTimeObj() const;
    Q_INVOKABLE int getYear();
    Q_INVOKABLE int getMonth();
    Q_INVOKABLE int getDay();
    Q_INVOKABLE int getHour();
    Q_INVOKABLE int getMinutes();
    Q_INVOKABLE int getSeconds();
    Q_INVOKABLE void setManualMode(bool manualMode);
    Q_INVOKABLE bool getManualMode();
    Q_INVOKABLE int setManualDateTime(int year, int month, int day, int hour, int minute);
    Q_INVOKABLE int setAutoDateTime(int year, int month, int day, int hour, int minute);


signals:
    void dateTimeChanged(QDateTime dateTime);

public slots:

private:
    QTimeZone m_timeZone;
    QString m_timeFormat;
    bool m_daylightSavingTime;
    bool m_manualMode;
};

#endif // TIMERTC_H

#include "dateTimeManager.h"


DateTimeManager::DateTimeManager(QObject *parent) {

    setParent(parent);
    // Set default time zone
    m_timeZone = QTimeZone::systemTimeZone();
    // Set default time format to 24-hour
    m_timeFormat = "HH:mm";
    m_daylightSavingTime = false;
    m_manualMode = false;
}

/**
* @brief Gets current date time
* @return The current date and time
*/
QDateTime DateTimeManager::getCurrentDateTime() const
{
    return QDateTime::currentDateTime().toTimeZone(m_timeZone);
}

QDateTime DateTimeManager::getUTCDateTime() const
{
    return QDateTime::currentDateTime();
}

int DateTimeManager::getYear()
{
    return getCurrentTimeObj().date().year();
}

int DateTimeManager::getMonth()
{
    return getCurrentTimeObj().date().month();
}

int DateTimeManager::getDay()
{
    return getCurrentTimeObj().date().day();
}

int DateTimeManager::getHour()
{
    return getCurrentTimeObj().time().hour();
}

int DateTimeManager::getMinutes()
{
    return getCurrentTimeObj().time().minute();
}

int DateTimeManager::getSeconds()
{
    return getCurrentTimeObj().time().second();
}

/**
* @brief Sets the time zone
*/
void DateTimeManager::setTimeZone(const QString& timeZoneId)
{
    setManualMode(false);
    m_timeZone = QTimeZone(timeZoneId.toUtf8());
}

/**
* @brief Sets the time format
*/
void DateTimeManager::setTimeFormat(const QString& format)
{
    m_timeFormat = format;
}

QString DateTimeManager::getTimeFormat(void)
{
    return m_timeFormat;
}

void DateTimeManager::setDaylightSavingTime(bool daylightSavingTime)
{
    if (m_daylightSavingTime != daylightSavingTime) {
        m_daylightSavingTime = daylightSavingTime;
    }
}

bool DateTimeManager::getDaylightSavingTime()
{
    return m_daylightSavingTime;
}

void DateTimeManager::setManualMode(bool manualMode) {
    if (m_manualMode != manualMode) {
        m_manualMode = manualMode;
    }
}

bool DateTimeManager::getManualMode() {

    return m_manualMode;
}

int DateTimeManager::setManualDateTime(int year, int month, int day, int hour, int minute) {
    QProcess setTime;
    QString dateCommand = "date";
    QStringList arguments;
    arguments << QString("%1%2%3%4%5")
        .arg(month, 2, 10, QChar('0'))
        .arg(day, 2, 10, QChar('0'))
        .arg(hour, 2, 10, QChar('0'))
        .arg(minute, 2, 10, QChar('0'))
        .arg(year % 100, 2, 10, QChar('0'));
    qDebug() << arguments;
    setTime.start(dateCommand, arguments);
    setTime.waitForFinished();

    int exitCode = setTime.exitCode();
    QByteArray output = setTime.readAllStandardOutput();
    QByteArray error = setTime.readAllStandardError();

    qDebug() << "Output:" << output;
    qDebug() << "Error:" << error;

    if (exitCode != 0) {
        // Handle the error here, e.g., display an error message to the user
        qDebug() << "Error: Invalid date";
    } else {
        setManualMode(true);

        // Synchronize the hardware clock to the system clock (done by K20hwclock.sh during normal shutdown procedure)
        QProcess setHwClock;
        dateCommand = "hwclock";
        QStringList argumentsHwClock;
        argumentsHwClock << QString("%1").arg("--systohc");
//        qDebug() << argumentsHwClock;
        setHwClock.start(dateCommand, argumentsHwClock);
        setHwClock.waitForFinished();
//        int exitCode = setHwClock.exitCode();
//        qDebug() << exitCode;
//        QByteArray outputHwClock = setHwClock.readAllStandardOutput();
//        QByteArray errorHwClock = setHwClock.readAllStandardError();
//        qDebug() << "OutputHwClock:" << outputHwClock;
//        qDebug() << "ErrorHwClock:" << errorHwClock;

        // Set the timestamp file to current datetime (done by S25save-rtc.sh during normal shutdown procedure)
        QProcess setTimestamp;
        dateCommand = "sh";
        QStringList argumentsTimestamp = {"-c","date -u +%4Y%2m%2d%2H%2M%2S 2>/dev/null > /etc/timestamp"};
        setTimestamp.start(dateCommand, argumentsTimestamp);
        setTimestamp.waitForFinished();
    }

    emit dateTimeChanged(getCurrentTimeObj());

    return exitCode;
}


int DateTimeManager::setAutoDateTime(int year, int month, int day, int hour, int minute) {
    QProcess setTime;
    QString dateCommand = "date";
    QStringList arguments;
    arguments << QString("%1%2%3%4%5")
        .arg(month, 2, 10, QChar('0'))
        .arg(day, 2, 10, QChar('0'))
        .arg(hour, 2, 10, QChar('0'))
        .arg(minute, 2, 10, QChar('0'))
        .arg(year % 100, 2, 10, QChar('0'));
    qDebug() << arguments;
    setTime.start(dateCommand, arguments);
    setTime.waitForFinished();

    int exitCode = setTime.exitCode();
    QByteArray output = setTime.readAllStandardOutput();
    QByteArray error = setTime.readAllStandardError();

    qDebug() << "Output:" << output;
    qDebug() << "Error:" << error;

    if (exitCode != 0) {
        // Handle the error here, e.g., display an error message to the user
        qDebug() << "Error: Invalid date";
    } else {
        setManualMode(false);

        // Synchronize the hardware clock to the system clock (done by K20hwclock.sh during normal shutdown procedure)
        QProcess setHwClock;
        dateCommand = "hwclock";
        QStringList argumentsHwClock;
        argumentsHwClock << QString("%1").arg("--systohc");
        setHwClock.start(dateCommand, argumentsHwClock);
        setHwClock.waitForFinished();

        // Set the timestamp file to current datetime (done by S25save-rtc.sh during normal shutdown procedure)
        QProcess setTimestamp;
        dateCommand = "sh";
        QStringList argumentsTimestamp = {"-c","date -u +%4Y%2m%2d%2H%2M%2S 2>/dev/null > /etc/timestamp"};
        setTimestamp.start(dateCommand, argumentsTimestamp);
        setTimestamp.waitForFinished();


    }

    emit dateTimeChanged(getCurrentTimeObj());

    return exitCode;
}

/**
* @brief Return Date Time
* @return The current date and time in string with proper format
*/
QString DateTimeManager::formatDateTime(const QDateTime& dateTime, const QString& format) const
{
    return dateTime.toString(format);
}

/**
* @brief Return Time
* @return The current time in string with proper format
*/
QString DateTimeManager::getCurrentTime() const {
    QDateTime currentDateTime;
    if (m_manualMode) {
        currentDateTime = QDateTime::currentDateTime();
    } else {
        currentDateTime = QDateTime::currentDateTime().toTimeZone(m_timeZone);
        if (m_daylightSavingTime) {
            currentDateTime = currentDateTime.addSecs(3600); // Add 1 hour
        }
    }
    return currentDateTime.toString(m_timeFormat);
}

/**
* @brief Return Time
* @return The current time in string with proper format
*/
QString DateTimeManager::getCurrentTimeCustomFormat(QString timeFormat) const {
    QDateTime currentDateTime;
    if (m_manualMode) {
        currentDateTime = QDateTime::currentDateTime();
    } else {
        currentDateTime = QDateTime::currentDateTime().toTimeZone(m_timeZone);
        if (m_daylightSavingTime) {
            qDebug() << "getCurrentTime daylightSaving";
            currentDateTime = currentDateTime.addSecs(3600); // Add 1 hour
        }
    }
    return currentDateTime.toString(timeFormat);
}

QDateTime DateTimeManager::getCurrentTimeObj() const {
    QDateTime currentDateTime;
    if (m_manualMode) {
        currentDateTime = QDateTime::currentDateTime();
    } else {
        currentDateTime = QDateTime::currentDateTime().toTimeZone(m_timeZone);
        if (m_daylightSavingTime) {
            currentDateTime = currentDateTime.addSecs(3600); // Add 1 hour
        }
    }
    return currentDateTime;
}


#ifndef ERRORMANAGER_H
#define ERRORMANAGER_H

#include <unordered_map>
#include <QObject>
#include <QString>
#include <QVariantMap>
#include <QFile>
#include <QByteArray>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QDebug>
#include <iostream>
#include <QTextStream>
#include <QCoreApplication>
#include "errordtc.h"
#include "errorinfo.h"

class ErrorManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int currentErrorLenght NOTIFY currentErrorLenghtChanged)                         // Number of active DTCs
    Q_PROPERTY(bool onCurrentErrorPage READ getOnCurrentErrorPage WRITE setOnCurrentErrorPage)  // Used to know if the user is on PG_list or PG_listDetails
    Q_PROPERTY(int socAlert WRITE setSocAlert NOTIFY socAlertChanged)                           // state of charge gauge alert (2 veryLow / 3 Low / 0 OK)
public:
    explicit ErrorManager(QObject *parent = 0);
    Q_INVOKABLE void addError(const QString& errorCode, const QString& hourMeterValue); // Create a DTC triggered from the MCU
    Q_INVOKABLE QVariantMap getCurrentErrorAt(int index);   // Get a specific active DTC
    Q_INVOKABLE QVariantMap getHistoryErrorAt(int index);   // Get a specif past DTC
    Q_INVOKABLE int getCurrentErrorLength();                // Get m_currentError size
    Q_INVOKABLE int getHistoryErrorLength();                // Get m_historyError size
    Q_INVOKABLE bool getOnCurrentErrorPage();
    Q_INVOKABLE void setOnCurrentErrorPage(bool value);
    Q_INVOKABLE void setSocAlert(int value);
    Q_INVOKABLE QVariantMap getBuzzerPattern();             // Give the buzzer pattern to play according to active DTCs and charge alert (info pop-up not include)

    Q_INVOKABLE void setBuzzerIsInCoolDown(QString code, bool value);
    Q_INVOKABLE void startBuzzerCooldown(QString code);
    Q_INVOKABLE void setBeepsDone(QString code, bool value);
private:
    std::unordered_map<std::string, ErrorDTC> m_errorList;  // Contains all DTCs data
    std::vector<ErrorInfo> m_currentError;                  // All active DTCs
    std::vector<ErrorInfo> m_historyError;                  // All past DTCs
    bool m_onCurrentErrorPage;
    int m_socAlert;
    bool loadDTC();                                         // Init function to fill m_errorList
    bool loadHistory();                                     // Init function to fill m_historyError
    void sortErrorInfo(std::vector<ErrorInfo>& vector);
    void deleteCurrentError(const QString& dtcErrorCode);   // Delete a current error from m_currentError
    bool addErrorToHistory(const ErrorInfo& errorInfo);     // write a dtc in the history file
signals:
    void newErrorPop(QVariantMap newError);
    void currentErrorLenghtChanged();
    void historyErrorLenghtChanged();
    void socAlertChanged();
};

#endif // ERRORMANAGER_H

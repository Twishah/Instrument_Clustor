#ifndef ERRORINFO_H
#define ERRORINFO_H

#include <QString>
#include <QDateTime>
#include <QTimer>
#include <QJsonObject>

struct ErrorInfo
{
    QString dtcCode;
    QString textToDisplayLabel;     // Text to display on pop-up and at the top of pg_listDetails
    QString correctiveActionLabel;  // Text to display at the bottom of pg_listDetails
    QString errorType;              // Warning/Caution/Maintenance
    QString dtcIconId;              // ID used to display the correct error icon if there is one
    int buzzerPattern;              // (1,2,3,4,5)
    int priority;                   // Priority of the DTC (1,2,3), used to sort.
    QDateTime creationDateTime;
    QString hourMeter;
    QTimer *dtcTimeOut;             // When this timer is reached, this error is deleted from current error list
    QTimer *buzzerTimeOut;          // When this timer is reached, the buzzer will not emit sound anymore for this DTC except if the coolDownTimer is done
    QTimer *buzzerCooldown;         // When a DTC is reactivated, there is a waiting time before the buzzer can sound again
    bool buzzerIsInCoolDown;        // Used to know if the buzzer of this DTC is in cooldown
    bool beepsDone;                 // Used to prevent buzzer patterns > 3 to buzz again after an interuption by a other buzzer pattern

    ErrorInfo(){}

    ErrorInfo(const QJsonObject& jsonObj) {
        dtcCode = jsonObj["dtcCode"].toString();
        textToDisplayLabel = jsonObj["textToDisplayLabel"].toString();
        correctiveActionLabel = jsonObj["correctiveActionLabel"].toString();
        errorType = jsonObj["errorType"].toString();
        dtcIconId = jsonObj["dtcIconId"].toString();
        priority = jsonObj["priority"].toInt();
        creationDateTime = QDateTime::fromString(jsonObj["creationDateTime"].toString(), Qt::ISODate);
        hourMeter = jsonObj["hourMeter"].toString();
        buzzerIsInCoolDown = true;
        dtcTimeOut = NULL;
        buzzerTimeOut = NULL;
        buzzerCooldown = NULL;
        buzzerPattern = 0;
        beepsDone = true;
    }
};

#endif // ERRORINFO_H

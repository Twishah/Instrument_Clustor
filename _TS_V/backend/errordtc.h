#ifndef ERRORDTC_H
#define ERRORDTC_H

#include <QString>
#include <QJsonObject>

struct ErrorDTC
{
   QString dtcCode;
   QString textToDisplayLabel;
   QString correctiveActionLabel;
   QString errorType;
   QString dtcIconId;
   int buzzerPattern;

   ErrorDTC(){}
   ErrorDTC(const QJsonObject& obj)
   {
       dtcCode = obj["DTC Code (Hex)"].toString();
       textToDisplayLabel = obj["ID Text to display"].toString();
       correctiveActionLabel = obj["ID Corrective action to display"].toString();
       errorType = obj["Pop-up display / ID icon Alarm"].toString();
       dtcIconId = obj["ID Icon DTC"].toString();
       buzzerPattern = obj["N buzzer blowing pattern"].toInt();
   }
};

#endif // ERRORDTC_H

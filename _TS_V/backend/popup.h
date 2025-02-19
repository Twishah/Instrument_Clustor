#ifndef POPUP_H
#define POPUP_H

#include <QObject>
#include <QDateTime>
#include <QtQml>

struct PopUp
{
    QString pictSource;
    QString errorMessage;
    int priority;
    int buzzerType;
    int duration;
    QDateTime creationDateTime;
};

#endif // POPUP_H

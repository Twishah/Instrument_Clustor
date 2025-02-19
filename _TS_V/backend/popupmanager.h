#ifndef POPUPMANAGER_H
#define POPUPMANAGER_H

#include <QObject>
#include <QVariantMap>
#include <vector>
#include "popup.h"

class PopUpManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool cutOffLever READ getCutOffLever WRITE setCutOffLever)

public:
    explicit PopUpManager(QObject *parent = 0);

    Q_INVOKABLE QVariantMap getPopUpToDisplay();
    Q_INVOKABLE void addPopUp(QString pictSource, QString errorMessage, int priority, int buzzerType);
    Q_INVOKABLE int size();
    Q_INVOKABLE void deletePopUp();
    Q_INVOKABLE bool getCutOffLever();
    Q_INVOKABLE void setCutOffLever(bool value);

private:
    std::vector<PopUp> m_popups;
    bool m_cutOffLever;     //security lever need to be cutoff or not

signals:
    void firstPopUpChanged();
};

#endif // POPUPMANAGER_H

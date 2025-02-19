#include "popupmanager.h"

PopUpManager::PopUpManager(QObject *parent)
{
    setParent(parent);
}

QVariantMap PopUpManager::getPopUpToDisplay()
{
    if (m_popups.size() < 1)
        return (QVariantMap());

    QVariantMap popup;

    popup["pictSource"] = m_popups[0].pictSource;
    popup["errorMessage"] = m_popups[0].errorMessage;
    popup["priority"] = m_popups[0].priority;
    popup["buzzerType"] = m_popups[0].buzzerType;
    popup["creationDateTime"] = m_popups[0].creationDateTime;
    popup["duration"] = m_popups[0].duration;

    return(popup);
}

void PopUpManager::addPopUp(QString pictSource, QString errorMessage, int priority, int buzzerType)
{
    PopUp newPopUp;

    if (pictSource == "qrc:/graphics/Popups/2.5 Cut off pop-up.png") {
        for(size_t i = 0; i < m_popups.size(); i++) {
            if (m_popups[i].pictSource == pictSource) {
                return;
            }
        }
    }

    newPopUp.pictSource = pictSource;
    newPopUp.errorMessage = errorMessage;
    newPopUp.priority = priority;
    newPopUp.buzzerType = buzzerType;
    newPopUp.creationDateTime = QDateTime::currentDateTime();
    newPopUp.duration = priority == 1 ? 5000 : priority == 2 ? 3000 : 1000;

    m_popups.push_back(newPopUp);

    std::sort(m_popups.begin(), m_popups.end(), [](const PopUp &a, const PopUp& b) {
        if (a.priority != b.priority)
            return a.priority < b.priority;
        else
            return a.creationDateTime > b.creationDateTime;
    });

    emit firstPopUpChanged();
}

void PopUpManager::deletePopUp()
{
    if (m_popups.size() < 1)
        return;
    m_popups.erase(m_popups.begin());
    emit firstPopUpChanged();
}

int PopUpManager::size()
{
    return (m_popups.size());
}

bool PopUpManager::getCutOffLever()
{
    return (m_cutOffLever);
}

void PopUpManager::setCutOffLever(bool value)
{
    if (m_cutOffLever != value)
        m_cutOffLever = value;
}

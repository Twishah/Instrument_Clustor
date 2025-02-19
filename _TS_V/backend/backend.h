/******************************************************************************
 *
 * File:        backend.h
 *
 * Description: The backend is the main handler for operations behind the UI.
 *
 * Copyright (C) 2020 CrossControl AB
 * All rights reserved.
 * Contact: CrossControl AB (info@crosscontrol.com)
 *
 * Code Template Revision: 1.2
 *
******************************************************************************/

/******************************************************************************
 * Nesting Header
******************************************************************************/
#ifndef BACKEND_H
#define BACKEND_H

/******************************************************************************
 * Include Files
******************************************************************************/
#include <QObject>
#include <QProcess>
#include <QTimer>
//#include <QDateTime>
#include <QQuickView>

#include "displayConfigHandler.h"
#include "ipaddress.h"

#include "hwbutton.h"

/******************************************************************************
 * Manifest Constants, Macros
******************************************************************************/
const int IPADDRESS_POLLING_TIME = 1000; // milliseconds

/******************************************************************************
 * Class Declaration
******************************************************************************/
/**
 * @brief The BackEnd class is the main controller of some actions behind the UI,
 * except pure CCAux features that have separate handlers.
 */
class BackEnd : public QObject
{
    Q_OBJECT

    /**
    * @brief Get or set the page selection state from the main menu.
    */
    Q_PROPERTY(int state READ state WRITE setState NOTIFY stateChanged)

    /**
    * @brief Get or set the page selection pointer.
    */
    Q_PROPERTY(QObject *currentPage READ currentPage WRITE setCurrentPage NOTIFY currentPageChanged)

    /**
    * @brief Get the primary IP address of the display unit.
    */
    Q_PROPERTY(QString ipAddress1 READ ipAddress1 NOTIFY ipAddress1Changed)

    /**
    * @brief Get the secondary IP address of displays that support this.
    */
    Q_PROPERTY(QString ipAddress2 READ ipAddress2 NOTIFY ipAddress2Changed)

    /**
    * @brief Get the model name of the display unit, for example "CCpilot VS"
    */
    Q_PROPERTY(QString displayName READ displayName NOTIFY displayNameChanged)

    /**
    * @brief Get the configuration of the display unit, which contains info
    * about hardware and other display specific properties.
    */
    Q_PROPERTY(QObject *currentConfig READ currentConfig CONSTANT)

public:
    explicit BackEnd(QObject *parent = 0);
    ~BackEnd();

    /**
    * @brief Initializes the backend, sets up its objects and gets the current display
    * configuration.
    */
    void init();

    Q_INVOKABLE bool getSK1SK2combined();
    Q_INVOKABLE bool getSK1SK3combined();
    Q_INVOKABLE bool getAccsignal();

    Q_INVOKABLE void menuPressed();
    Q_INVOKABLE void upPressed();
    Q_INVOKABLE void downPressed();
    Q_INVOKABLE void enterPressed();

signals:
    void stateChanged(int state);
    void currentPageChanged(QObject *currentPage);

    void ipAddress1Changed();
    void ipAddress2Changed();
    void displayNameChanged();

    void hardwareButtonStateChanged(int buttonNo, int buttonPressed);
    void mechanicMode1Activated();
    void mechanicMode2Activated();

public slots:
    /**
    * @brief Sets the page selection state.
    * @param state [in] The new state.
    */
    void setState(int state)
    {
        if (m_state == state)
            return;

        m_state = state;
        emit stateChanged(m_state);
    }

    /**l
    * @brief Sets the page selection currentPage.
    * @param currentPage [in] The new currentPage.
    */
    void setCurrentPage(QObject *currentPage)
    {
        if (m_currentPage == currentPage)
            return;

        m_currentPage = currentPage;
        emit currentPageChanged(m_currentPage);
    }

private slots:
    void ipTimerTimeout();
    void updateHwButtonState(int buttonNo, bool buttonPressed);
    void changeToMechanicMode1();
    void changeToMechanicMode2();
    void verifyAppState();

private:
    /**
    * @brief Gets the current page selection state.
    * @return The current page state enum.
    */
    int state() const { return m_state; }

    QObject* currentPage() { return m_currentPage; }

    /**
    * @brief Gets the primary IP address as a string.
    * @return The primary IP address.
    */
    QString ipAddress1();

    /**
    * @brief Sets the current primary IP adress.
    * @param value [in] The current primary IP address as a string ("aaa.bbb.ccc.ddd").
    */
    void setIpAddress1(QString value);

    /**
    * @brief Gets the secondary IP address as a string.
    * @return The secondary IP address.
    */
    QString ipAddress2();

    /**
    * @brief Sets the current secondary IP adress.
    * @param value [in] The current secondary IP address as a string ("aaa.bbb.ccc.ddd").
    */
    void setIpAddress2(QString value);

    /**
    * @brief Gets the model name of the display unit, for example "CCpilot VS".
    * @return The model name of the display unit.
    */
    QString displayName();

    /**
    * @brief Sets the model name of the display unit, for example "CCpilot VS".
    * @param value [in] The model name of the display unit.
    */
    void setDisplayName(QString value);

    /**
    * @brief Gets the current configuraton of the display unit.
    * @return The current configuraton of the display unit.
    */
    DisplayConfiguration *currentConfig();

    // Member objects
    IpAddress *m_ipAddressHandler;
    QTimer *m_ipAddressTimer;
    HWButton *m_hwButtonHandler;

    DisplayConfigHandler m_displayConfigHandler;

    // Members
    int m_state;

    QObject *m_currentPage;

    QString m_ipAddress1;
    QString m_ipAddress2;

    QString m_displayName;
};

#endif // BACKEND_H

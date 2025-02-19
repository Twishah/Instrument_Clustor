/******************************************************************************
 *
 * File:        backend.cpp
 *
 * Description: Contains the class methods for the BackEnd of the application.
 *
 * Copyright (C) 2020 CrossControl AB
 * All rights reserved.
 * Contact: CrossControl AB (info@crosscontrol.com)
 *
 * Code Template Revision: 1.2
 *
******************************************************************************/

/******************************************************************************
 * Include Files
******************************************************************************/
#include <QDebug>
#include <QNetworkInterface>
#include <QString>
#include <string>

#include "appstate.h"
#include "backend.h"
#include "CCAux/VersionHandler.h"
#include "CCAux/PowerConfigHandler.h"

/******************************************************************************
 * Class Methods
******************************************************************************/
BackEnd::BackEnd(QObject *parent)
    : QObject(parent)
{
    m_ipAddress1 = "-";
    m_ipAddress2 = "-";

    m_ipAddressHandler = new IpAddress();
    m_ipAddressTimer   = new QTimer();
    m_currentPage      = new QObject();

    m_state            = (int)MyAppState::AppState::MAIN;
}

BackEnd::~BackEnd()
{
    delete m_ipAddressHandler;
    delete m_ipAddressTimer;
    delete m_hwButtonHandler;
}

void BackEnd::init()
{
    // Detect and setup the current display configuration
    m_displayConfigHandler.init();
    DisplayConfiguration *currentConfig = m_displayConfigHandler.current();
    QString displayName                 = currentConfig->name();
    setDisplayName(displayName);

    qDebug() << "Current display configuration: " << displayName;

    // Setup hardware button handler, does not cause any harm on displays not supporting this
    m_hwButtonHandler = new HWButton(currentConfig->hwButtonInputId());
    connect(m_hwButtonHandler, &HWButton::buttonChanged, this, &BackEnd::updateHwButtonState);
    connect(m_hwButtonHandler, &HWButton::mechanicModeL1Activated, this, &BackEnd::changeToMechanicMode1);
    connect(m_hwButtonHandler, &HWButton::mechanicModeL2Activated, this, &BackEnd::changeToMechanicMode2);
    connect(m_hwButtonHandler, &HWButton::appStateNeeded, this, &BackEnd::verifyAppState);

    connect(m_ipAddressTimer, &QTimer::timeout, this, &BackEnd::ipTimerTimeout);
    m_ipAddressTimer->setInterval(IPADDRESS_POLLING_TIME); // 1 sec
    m_ipAddressTimer->start();



//    // Initialize the timer
//    timer = new QTimer(this);
//    connect(timer, SIGNAL(timeout()), this, SLOT(checkButtonPress()));

//    // Set the initial state
//    currentState = Idle;

//    // Start the timer
//    timer->start(100); // Adjust the interval as needed
}

void BackEnd::menuPressed()
{
    QMetaObject::invokeMethod(m_currentPage, "menuPressed");
}

void BackEnd::upPressed()
{
    QMetaObject::invokeMethod(m_currentPage, "upPressed");
}

void BackEnd::downPressed()
{
    QMetaObject::invokeMethod(m_currentPage, "downPressed");
}

void BackEnd::enterPressed()
{
    QMetaObject::invokeMethod(m_currentPage, "enterPressed");
}

QString BackEnd::ipAddress1()
{
    return m_ipAddress1;
}

void BackEnd::setIpAddress1(QString value)
{
    if (value != m_ipAddress1)
    {
        m_ipAddress1 = value;
        emit ipAddress1Changed();
    }
}

QString BackEnd::ipAddress2()
{
    return m_ipAddress2;
}

void BackEnd::setIpAddress2(QString value)
{
    if (value != m_ipAddress2)
    {
        m_ipAddress2 = value;
        emit ipAddress2Changed();
    }
}

QString BackEnd::displayName()
{
    return m_displayName;
}

void BackEnd::setDisplayName(QString value)
{
    if (value != m_displayName)
    {
        m_displayName = value;
        emit displayNameChanged();
    }
}

DisplayConfiguration *BackEnd::currentConfig()
{
    return m_displayConfigHandler.current();
}

void BackEnd::ipTimerTimeout()
{
    QString ip1 = m_ipAddressHandler->get("eth0");
    QString ip2 = m_ipAddressHandler->get("eth1");

    if (ip1 == "")
    {
        ip1 = "0.0.0.0";
    }

    setIpAddress1(ip1);
    setIpAddress2(ip2);
}

void BackEnd::updateHwButtonState(int buttonNo, bool buttonPressed)
{
    //qDebug() << "call button state!";
    emit hardwareButtonStateChanged(buttonNo, buttonPressed);
}

void BackEnd::changeToMechanicMode1()
{
    //qDebug() << "call MM L1!";
    emit mechanicMode1Activated();
    m_hwButtonHandler->set_flag_secretCode(false);
}

void BackEnd::changeToMechanicMode2()
{
    //qDebug() << "call MM L2!";
    emit mechanicMode2Activated();
    m_hwButtonHandler->set_flag_secretCode(false);
}

void BackEnd::verifyAppState() {
    //qDebug() << "call secret code!";
//    qDebug() << "m_state: " << m_state;
    if (m_state == (int)MyAppState::AppState::MAIN || m_state == (int)MyAppState::AppState::MENU_MECA_1 || m_state == (int)MyAppState::AppState::LIST) {
        m_hwButtonHandler->set_flag_secretCode(true);
        //qDebug() << "Flag of Secret Code changed to TRUE";
    }
    else {
        m_hwButtonHandler->set_flag_secretCode(false);
    }
}

bool BackEnd::getSK1SK2combined()
{
    return m_hwButtonHandler->getSK1SK2combined();
}

bool BackEnd::getSK1SK3combined()
{
    return m_hwButtonHandler->getSK1SK3combined();
}

bool BackEnd::getAccsignal()
{

    bool retValue = false;

#ifdef TARGET_ARM_IMX6
    CrossControl::CONFIGHANDLE config = CrossControl::GetConfig();

    CrossControl::CCStatus onOffSignalEnabled;
    CrossControl::eErr err = CrossControl::Config_getOnOffSignalState(config, &onOffSignalEnabled);

    CrossControl::Config_release(config);

    if (err == CrossControl::ERR_SUCCESS)
    {
        retValue = onOffSignalEnabled == CrossControl::CCStatus::Disabled;
    }
    else
    {
        qWarning() << "Couldn't get on/off signal state";
    }
#endif

    return retValue;
}

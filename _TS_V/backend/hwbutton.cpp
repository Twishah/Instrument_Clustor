/******************************************************************************
 *
 * File:        hwbutton.cpp
 *
 * Description: Contains the class methods for the HWButton class.
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
#include "hwbutton.h"
#include <QDebug>
#include <fcntl.h>
#include <linux/input.h>
#include <unistd.h>

/******************************************************************************
 * Class Methods
******************************************************************************/
HWButton::HWButton(int hwButtonInputId, QObject *parent)
    : QObject(parent)
{
    // --------------- Button Press set up --------------------------
    const QString &device = QString("/dev/input/event%1").arg(hwButtonInputId);
    m_buttonsFd           = ::open(device.toLocal8Bit().constData(), O_RDONLY, 0);
    if (!m_buttonsFd)
    {
        // "Failed to open input device"
        qDebug() << "Failed to open input device";
    }
    else
    {
        m_notifier = new QSocketNotifier(m_buttonsFd, QSocketNotifier::Read, this);
        connect(m_notifier, SIGNAL(activated(int)), this, SLOT(processButtonEvent()));
    }

    for (uint i = 0; i < m_buttons.size(); i++)
    {
        m_buttons[i] = Released;
    }

    // Initialize the button index
    buttonIndex = 0;

    // Initialize flags
    flag_buttonUpPressed = false;
    flag_buttonDownPressed = false;
    flag_buttonEnterPressed = false;
    flag_buttonMenuPressed = false;
    flag_secretCode = false;

    // Initialize sequence state
    currentSequenceState = Idle;

    // Define the desired button sequence
    desiredSequence = {2, 3, 4, 2};

    // Define the desired mSecs of long press for button combination
    mSecs_longPress = 10000;

    // Initialize the sequence index
    currentSequenceIndex = 0;

    // Initialize the timer
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(checkButtonPress()));
    connect(timer, SIGNAL(timeout()), this, SLOT(checkButtonSequence()));

    // Start the timer
    timer->start(100); // To check the press time and the sequence every 100 ms
}

HWButton::~HWButton()
{
    ::close(m_buttonsFd);
    delete m_notifier;
}

void HWButton::processButtonEvent()
{
    struct input_event event;
    int n = read(m_buttonsFd, &event, sizeof(input_event));
    if (n != 16)
    {
        // "Unexpected lenght read"
        return;
    }

    if (event.type != EV_KEY)
        return;

    /*int */buttonIndex = 0;

    switch (event.code)
    {
    case KEY_F1:
        buttonIndex = 1;
        break;
    case KEY_F2:
        buttonIndex = 2;
        break;
    case KEY_F3:
        buttonIndex = 3;
        break;
    case KEY_F4:
        buttonIndex = 4;
        break;
    case KEY_F5:
        buttonIndex = 5;
        break;
    case KEY_F6:
        buttonIndex = 6;
        break;
    case KEY_F7:
        buttonIndex = 7;
        break;
    case KEY_F8:
        buttonIndex = 8;
        break;
    case KEY_F9:
        buttonIndex = 9;
        break;
    case KEY_F10:
        buttonIndex = 10;
        break;
    }

    if (buttonIndex > 0)
    {
        if (event.value == 1)
        {
            setButton(buttonIndex, Pressed);
            //qDebug() << "PRESSED";

            pressStartTime = QDateTime::currentMSecsSinceEpoch();

            // For detecting a button sequence
            if (currentSequenceState == Idle && buttonIndex == desiredSequence[currentSequenceIndex])
            {
                // Button press matches the expected sequence
                currentSequenceState = InProgress;
                currentSequenceIndex++;
                //qDebug() << "Some similarities detected!";
            }
            else
            {
                // Button press does not match the expected sequence, reset the state
                currentSequenceState = Idle;
                currentSequenceIndex = 0;
            }


            // For detecting a button combination
            if (buttonIndex == 1) {
                if (!flag_buttonUpPressed) {
                    flag_buttonUpPressed = true;
                }
                else {
                    flag_buttonUpPressed = false;
                }
            }
            else if (buttonIndex == 2) {
                if (!flag_buttonDownPressed) {
                    flag_buttonDownPressed = true;
                }
                else {
                    flag_buttonDownPressed = false;
                }
            }
            else if (buttonIndex == 3) {
                if (!flag_buttonEnterPressed) {
                    flag_buttonEnterPressed = true;
                }
                else {
                    flag_buttonEnterPressed = false;
                }
            }
            else if (buttonIndex == 4) {
                if (!flag_buttonMenuPressed) {
                    flag_buttonMenuPressed = true;
                }
                else {
                    flag_buttonMenuPressed = false;
                }
            }

            if ((flag_buttonUpPressed && flag_buttonEnterPressed) || (flag_buttonUpPressed && flag_buttonDownPressed)) {
                if (!flag_secretCode) {
                    //qDebug() << "Maybe is a secret code";
                    emit appStateNeeded();
                }
            }
        }

        else
        {
            setButton(buttonIndex, Released);
            //qDebug() << "RELEASED";

            qint64 pressDuration = QDateTime::currentMSecsSinceEpoch() - pressStartTime;
            if (pressDuration >= mSecs_longPress)
            {
                // Very long press detected
                //qDebug() << "Very long press";
            }
            else if (pressDuration >= 1000) {
                // Long press detected
                //qDebug() << "Long press";
            }
            else {
                // Short press detected
                //qDebug() << "Short press";
            }

            if (buttonIndex == 1 && flag_buttonUpPressed) {
                checkButtonCombinationPress(pressDuration);
                flag_buttonUpPressed = false;
            }
            else if (buttonIndex == 2 && flag_buttonDownPressed) {
                checkButtonCombinationPress(pressDuration);
                flag_buttonDownPressed = false;
            }
            else if (buttonIndex == 3 && flag_buttonEnterPressed) {
                checkButtonCombinationPress(pressDuration);
                flag_buttonEnterPressed = false;
            }

            else if (buttonIndex == 4 && flag_buttonMenuPressed) {
                checkButtonCombinationPress(pressDuration);
                flag_buttonMenuPressed = false;
            }

            buttonIndex = 0;
        }
    }
    //qDebug() << "buttonIndex: " << buttonIndex;
}

void HWButton::checkButtonPress()
{
    if (buttonIndex == 1 || buttonIndex == 2 || buttonIndex == 3 || buttonIndex == 4)
    {
        qint64 pressDuration = QDateTime::currentMSecsSinceEpoch() - pressStartTime;
        if (pressDuration >= mSecs_longPress) {
            // Very long press detected, perform very long press action continuously
            qDebug() << "Very long press (continuous)";
            checkButtonCombinationPress(pressDuration);
        }
        else if (pressDuration >= 1000)
        {
            // Long press detected, perform long press action continuously
            //qDebug() << "Long press (continuous)";
        }
        else {
            // Short press detected, perform short press action continuously
            //qDebug() << "Short press (continuous)";
        }
    }
}

void HWButton::checkButtonCombinationPress(qint64 pressDuration) {
    if (flag_buttonUpPressed && flag_buttonMenuPressed) {
        qDebug() << "Combination UP + MENU buttons detected";
    }
    else if (flag_buttonUpPressed && flag_buttonDownPressed) {
        qDebug() << "Combination UP + DOWN buttons detected";
        if (currentSequenceIndex >= desiredSequence.size())
        {
            // Reset the state for the next sequence detection
            currentSequenceState = Idle;
            currentSequenceIndex = 0;

            // Complete button sequence detected
            qDebug() << "Button sequence detected: DOWN-ENTER-MENU-DOWN + UP";
            if(flag_secretCode == true)
            {
                emit mechanicModeL2Activated();
                flag_secretCode = false;

            }

        }
    }
    else if (flag_buttonUpPressed && flag_buttonEnterPressed) {
        if (pressDuration >= mSecs_longPress) {
            qDebug() << "Combination UP + ENTER buttons detected in 10 secs";            
            if(flag_secretCode == true)
            {
                emit mechanicModeL1Activated();
                flag_secretCode = false;

            }
        }
        else {
            qDebug() << "Combination UP + ENTER buttons detected";
        }
    }
    else if (flag_buttonUpPressed && flag_buttonMenuPressed) {
        qDebug() << "Combination UP + MENU/BACK buttons detected";
    }
    else {
        currentSequenceState = Idle;
        currentSequenceIndex = 0;
        flag_secretCode = false;
    }
}

void HWButton::checkButtonSequence()
{
    // Reset the state if the expected sequence is not completed within a certain time
    if (currentSequenceState == InProgress)
    {
        currentSequenceState = Idle;
        //currentSequenceIndex = 0;
    }
}

bool HWButton::getSK1SK3combined()
{
    if(flag_buttonUpPressed && flag_buttonEnterPressed)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool HWButton::getSK1SK2combined()
{
    return (flag_buttonUpPressed && flag_buttonDownPressed);
}


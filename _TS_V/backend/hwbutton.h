﻿/******************************************************************************
 *
 * File:        hwbutton.h
 *
 * Description: Based on the demo code from CrossControl knowledge base for
 * detecting and routing hardware button presses
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
#ifndef HWBUTTON_H
#define HWBUTTON_H

/******************************************************************************
 * Include Files
******************************************************************************/
#include <QObject>
#include <QSocketNotifier>
#include <array>

#include <QTimer>
#include <QDateTime>


/******************************************************************************
 * Class Declaration
******************************************************************************/
class HWButton : public QObject
{
    Q_OBJECT

public:
    /******************************************************************************
     * Enum to indicate the button state
    ******************************************************************************/
    /**
     * @brief ButtonState to indicate if a button is pressed or released
     */
    enum ButtonState
    {
        Pressed = 0,
        Released
    };

    /**
     * @brief Standard constructor
     */
    explicit HWButton(QObject *parent = 0);

    /**
     * @brief Constructor
     */
    explicit HWButton(int hwButtonInputId = 0, QObject *parent = 0);

    ~HWButton();

    void set_flag_secretCode(bool secretCode) {
        flag_secretCode = secretCode;
    }
    bool get_flag_secretCode() {
        return flag_secretCode;
    }

    bool getSK1SK3combined();

    bool getSK1SK2combined();


private:
    // Private members
    int m_buttonsFd;
    QSocketNotifier *m_notifier;

    std::array<ButtonState, 10> m_buttons;


    qint64 pressStartTime;
    QTimer *timer;
    int buttonIndex = 0;
    bool flag_buttonUpPressed = false;
    bool flag_buttonDownPressed = false;
    bool flag_buttonEnterPressed = false;
    bool flag_buttonMenuPressed = false;
    enum ButtonSequenceState
    {
        Idle,
        InProgress
    };
    ButtonSequenceState currentSequenceState;
    int currentSequenceIndex = 0;
    QList<int> desiredSequence;
    bool flag_secretCode = false;
    int mSecs_longPress = 5000;

signals:
    /**
    * @brief Signal that tells that the indexed button was pressed or released
    * @param buttonNo [in] Index of the button
    * @param buttonPressed [in] Button is pressed (true/false)
    */
    void buttonChanged(int buttonNo, bool buttonPressed);
    void mechanicModeL1Activated();
    void mechanicModeL2Activated();
    void appStateNeeded();

private slots:
    /**
    * @brief Reaction from the QSocketNotifier that a hw button was pressed or released
    */
    void processButtonEvent();
    void checkButtonPress();
    void checkButtonCombinationPress(qint64 pressDuration);
    void checkButtonSequence();


public slots:
    /**
    * @brief Sets the button pressed state of the currently pressed hw button and
    * emits a signal that can be notified in the UI
    * @param index [in] The index of the button
    * @param arg [in] The new state (Pressed/Released) of the button
    */
    void setButton(int index, ButtonState arg)
    {
        if (m_buttons[index - 1] != arg)
        {
            m_buttons[index - 1] = arg;
            emit buttonChanged(index, arg == ButtonState::Pressed);
        }
    }
};

#endif // HWBUTTON_H

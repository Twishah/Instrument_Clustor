/******************************************************************************
 *
 * File:        appstate.h
 *
 * Description: This file contains the helper class MyAppState which is used
 * to contol the menu and page selections in the application.
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
#ifndef APPSTATE_H
#define APPSTATE_H
#pragma once

/******************************************************************************
 * Include Files
******************************************************************************/
#include <QObject>
#include <QtQml>

/******************************************************************************
 * Class Declaration
******************************************************************************/
/**
* @brief The MyAppState is an enum class that can be used to control the page
* selection in the application.
*/
class MyAppState : public QObject
{
	Q_OBJECT

public:
	/**
	 * @brief Enumeration of the available pages. New pages can be added.
	 */
	enum class AppState
	{
		MAIN,
		MAIN_HOUR_METER,
		MENU,
		MENU_HOUR_METER,
		MENU_MECA_1,
		MENU_MECA_2,
		DISPLAY_SET,
		VEHICULE_SET,
		PTO_SET,
		MONITOR,
		OP_MANAGEMENT,
		MAINTENANCE,
		MAINTENANCE_LVL2,
		ERROR_HISTORY,
		ER_HI_1_DETAIL,
		PRE_HEATING,
		FLOW_LIMIT_LOCK,
		MECA_MODE_HISTORY,
		DIAGNOSTIC_MODE,
		RESET_HOUR_METER,
		DS_1_BRIGHTNESS,
		DS_1_DATE_TIME,
		DS_1_LANGUAGE,
		DS_1_SOUND,
		DS_1_UNIT,
		DS_2_BRIGHTNESS_DAY,
		DS_2_BRIGHTNESS_NIGHT,
		DS_2_DATE_TIME_SET,
		DS_2_DATE_TIME_HOUR,
		DS_2_DATE_TIME_DAYLIGHT,
		DS_2_UNIT_TEMP,
		DS_2_UNIT_SPEED,
		DS_2_UNIT_PRESSURE,
		DS_2_UNIT_VOLUME,
		DS_3_DATE_TIME_AUTO,
		DS_3_DATE_TIME_MANUAL,
		EH_1_DETAIL,
		MM_1_HISTORY,
		MM_1_RESET,
		MM_1_INTERVAL,
		MM_2_RESET,
		MM_2_INTERVAL_CHANGE,
		OMM_1_CALENDAR,
		OMM_1_TIME,
		PH_1_DAY,
		PTO_1_FLOW_LIMIT,
		PTO_2_ICON,
		VS_1_ENGINE,
		DM_1_INSTRUMENT,
		DM_1_MAIN_CONTROL,
		DM_1_BATTERY_ECU,
		DM_1_TCU,
		DM_1_DIAG_MAIN_CONTROL,
		DM_1_RESET,
		POPUP,
		LIST,
		IMMOBILIZER_SETTINGS,
		TIME_TO_ACTIVATE,
		IMMOBILIZER_ACTIVATION, // 58
		LI_1_DETAILS,
		IMMOBILIZER,
		ENTER_TRANS_PIN, // 61, better: ChangeTransPin usw
		ENTER_DRIVER_PIN,
		ENTER_OWNER_PIN,
		NEW_TRANS_PIN,
		NEW_DRIVER_PIN, // 65
		NEW_OWNER_PIN,
		RCS_FORWARD,
		RCS_BACKWARD,
		FILTER_REGENERATION,
		SOOT_LEVEL,
		ASH_LEVEL,
		ENTERED_WRONG_OWNER_PIN,
		NB_STATE
	};
	Q_ENUMS(AppState)

	/**
	 * @brief Initialization by registering the enum to be accessible from QML
	 */
	static void init()
	{
		qRegisterMetaType<MyAppState::AppState>("MyAppState::AppState");
		qmlRegisterType<MyAppState>("MyQmlModule", 1, 0, "MyAppState");
	}
};
#endif // APPSTATE_H

/******************************************************************************
 *
 * File:        main.cpp
 *
 * Description: This is the main class file where the application main function
 * is implemented, containing intialization of the application and its handlers.
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
#ifdef TARGET_ARM_IMX6
#include <Config.h>
#endif
#include <QGuiApplication>
#include <QQuickItem>
#include <QQuickView>
#include <QtQml>

#include "CCAux/BackLightHandler.h"
#include "CCAux/BuzzerHandler.h"
#include "CCAux/PowerConfigHandler.h"
#include "CCAux/VersionHandler.h"
#include "backend/appstate.h"
#include "backend/backend.h"
#include "backend/remainingtime.h"
#include "backend/coolingtemperature.h"
#include "backend/dataManager.h"
#include "backend/ptosettings.h"
#include "backend/dateTimeManager.h"
#include "backend/popupmanager.h"
#include "backend/errormanager.h"

#include "DataEngine/dataengine.h"

#include "backend/can_handler3.h"
#include "backend/translation.h"

#include "backend/runprocess.h"

#include "backend/startupinfo.h"

/******************************************************************************
 * The Main.
******************************************************************************/
int main(int argc, char *argv[])
{
	QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
	QGuiApplication app(argc, argv);

	// get the target setting from the .pro-file:
#if defined(TARGET_ARM_IMX5) || defined(TARGET_ARM_IMX6) || defined(TARGET_ARM_IMX8)
	bool targetARM = true;
#else
	// virtual machine
	bool targetARM = false;
#endif

#ifdef BN9
	bool excavatorBN9_b = true;
#else
	bool excavatorBN9_b = false;

#endif

	QQuickView *view = new QQuickView;
	QObject::connect(view->engine(), &QQmlEngine::quit, &app, &QGuiApplication::quit);

	view->engine()->setOfflineStoragePath("/home/root/.local/share/fmc_hmi/QML/OfflineStorage");
	MyAppState::init();

	if(targetARM == true)
	{
		QFontDatabase::addApplicationFont("/opt/DFPGothicP-W5-OEM-90-1.ttf");
	}

	DataManager dm;
	dm.init();
	qmlRegisterUncreatableType<DataManager>("CrossControl", 1, 0, "DataManager", "Don't instance");
	view->rootContext()->setContextProperty("dm", &dm);
	qmlRegisterType<Flow_limit_acc>("MyQmlModule", 1, 0, "Flow_limit_acc");
	qmlRegisterType<Pre_heating_settings>("MyQmlModule", 1, 0, "Pre_heating_settings");
	qmlRegisterType<MaintenanceHistory>("MyQmlModule", 1, 0, "MaintenanceHistory");
	qmlRegisterType<MechanicHistory>("MyQmlModule", 1, 0, "MechanicHistory");

	QString lang = dm.getLanguage();


	TranslationHandler trans;
	view->rootContext()->setContextProperty("translator", (QObject*)&trans);
	trans.selectLanguage(lang);


	PopUpManager pum;
	qmlRegisterUncreatableType<PopUpManager>("CrossControl", 1, 0, "PopUpManager", "Don't instance");
	view->rootContext()->setContextProperty("pum", &pum);

	ErrorManager errorManager;
	qmlRegisterUncreatableType<ErrorManager>("CrossControl", 1, 0, "ErrorManager", "Don't instance");
	view->rootContext()->setContextProperty("errorManager", &errorManager);

	BuzzerHandler buzzerHandler;
	buzzerHandler.init();
	qmlRegisterUncreatableType<BuzzerHandler>("CrossControl", 1, 0, "BuzzerHandler", "Don't instance");
	view->rootContext()->setContextProperty("buzzerHandler", &buzzerHandler);

	VersionHandler versionHandler;
	versionHandler.init();
	qmlRegisterUncreatableType<VersionHandler>("CrossControl", 1, 0, "VersionHandler", "Don't instance");
	view->rootContext()->setContextProperty("versionHandler", &versionHandler);

	PowerConfigHandler powerConfigHandler;
	powerConfigHandler.init();
	qmlRegisterUncreatableType<PowerConfigHandler>("CrossControl", 1, 0, "PowerConfigHandler", "Don't instance");
	view->rootContext()->setContextProperty("powerConfigHandler", &powerConfigHandler);

	BackEnd backEnd;
	backEnd.init();
	qmlRegisterUncreatableType<BackEnd>("CrossControl", 1, 0, "BackEnd", "Don't instance");
	view->rootContext()->setContextProperty("backEnd", &backEnd);

	RemainingTime remainingTime;
	view->rootContext()->setContextProperty("RemainingTime", &remainingTime);

	CoolingTemperature coolingTemperature;
	view->rootContext()->setContextProperty("CoolingTemperature", &coolingTemperature);

	DateTimeManager dateTimeManager;
	QDateTime currentDateTime = dateTimeManager.getCurrentDateTime();
	qDebug() << "Current date and time:" << dateTimeManager.formatDateTime(currentDateTime, "yyyy-MM-dd hh:mm:ss");

	if(dm.getFormatHour())
	{
		dateTimeManager.setTimeFormat("AP hh:mm"); // Set 12-hour time format
		qDebug() << "Current time (12-hour format):" << dateTimeManager.getCurrentTime();

	} else {
		dateTimeManager.setTimeFormat("HH:mm"); // Set 24-hour time format
		qDebug() << "Current time (24-hour format):" << dateTimeManager.getCurrentTime();
	}

	dateTimeManager.setDaylightSavingTime(dm.getDaylightSavingTime());

	dateTimeManager.setTimeZone(dm.getTimeZone());

	dateTimeManager.setManualMode(dm.getDateTimeMode());

	view->rootContext()->setContextProperty("dateTimeManager", &dateTimeManager);


	qRegisterMetaType<BuzzerHandler::Tone>("BuzzerHandler::Tone");
	qmlRegisterType<BuzzerHandler>("MyQmlModule", 1, 0, "BuzzerHandler");

	// this will set the "targetARM" property to true if the software is built for ARM
	view->rootContext()->setContextProperty("targetARM", QVariant(targetARM));

	/* Default window size when running in LinX Linux VM. You can test different resolutions
	 * and aspect ratios to check that the UI is scaling propertly. The app should support the
	 * currently smallest unit VI2 of 320x240 pixels up to 1280x800 and beyond... */
	int displayWidth = 320; int displayHeight = 240;

	qmlRegisterUncreatableType<DataEngine>("Crosscontrol", 1, 0, "DataEngine", "Cannot create dataEngine as qml object");
	DataEngine dataEngine;
	view->rootContext()->setContextProperty("dataEngine", &dataEngine);

	BackLightHandler backLightHandler;
	int targetBrightness = 255;
	int storedDayBrightness = dm.getDayBrightness();
	int storedNightBrightness = dm.getNightBrightness();

	// If EEPROM brightness value is 0, set it to default value
	if(storedDayBrightness == 0)
	{
		dm.setDayBrightness(255);// default value if EEPROM value is 0: 100% of 255
	}

	// If EEPROM brightness value is 0, set it to default value
	if(storedNightBrightness == 0)
	{
		dm.setNightBrightness(77); // default value if EEPROM value is 0: 30% of 255
	}

	backLightHandler.init(targetBrightness);
	qmlRegisterUncreatableType<BackLightHandler>("CrossControl", 1, 0, "BackLightHandler", "Don't instance");
	view->rootContext()->setContextProperty("backLightHandler", &backLightHandler);

	//Create the CAN_Handler3 class to start when the main application is started
	CAN_Handler3 CANHandler;
	view->rootContext()->setContextProperty("_CanHandler", &CANHandler);

	// RunProcess : to be able to run commands
	RunProcess runProcess;
	qmlRegisterUncreatableType<RunProcess>("CrossControl", 1, 0, "RunProcess", "Don't instance");
	view->rootContext()->setContextProperty("RunProcess", &runProcess);

	StartupInfo startupInfo;

#ifdef TARGET_ARM_IMX6
	CrossControl::CONFIGHANDLE config = CrossControl::GetConfig();

	CrossControl::CCStatus onOffSignalEnabled;
	CrossControl::eErr err = CrossControl::Config_getOnOffSignalState(config, &onOffSignalEnabled);

	// Set trigger mode to level
	CrossControl::Config_setOnOffTriggerMode(config, CrossControl::CONFIG_ONOFF_LEVEL_TRIGGER);

	// Set suspend max time to 1 minute
	CrossControl::Config_setSuspendMaxTime(config, 1);

	// Set external on/off signal trigger time to 10 sec and the action to Actionsuspend
	// NoAction = 0, ActionSuspend = 1, ActionShutDown = 2
	CrossControl::Config_setOnOffSigAction(config, CrossControl::ActionSuspend);
	CrossControl::Config_setExtOnOffSigTrigTime(config, 10);

	CrossControl::Config_release(config);

	if (err == CrossControl::ERR_SUCCESS)
	{
		startupInfo.m_manualStartMode = onOffSignalEnabled == CrossControl::CCStatus::Disabled;
		if (startupInfo.m_manualStartMode) {
			backEnd.setState((int)MyAppState::AppState::MAIN_HOUR_METER);
		}
		else {
			backEnd.setState((int)MyAppState::AppState::MAIN);
		}
	}
	else
	{
		qWarning() << "Couldn't get on/off signal state";
	}
#endif

	view->rootContext()->setContextProperty("startupInfo", &startupInfo);

	view->rootContext()->setContextProperty("excavatorBN9", QVariant(excavatorBN9_b));

	if (targetARM)
	{
		// Set window size and the view to automatically maximize on the screen
		view->setResizeMode(QQuickView::SizeRootObjectToView);
		view->setSource(QStringLiteral("qrc:/main.qml"));

		while (QFile::exists("/tmp/.await-yanmar-intro-video")) {
		}

		view->showFullScreen();

		// Get the dimensions of the window (= screen dimensions) after maximization
		displayWidth  = 320;
		displayHeight = 240;
		view->rootContext()->setContextProperty("displayWidth", QVariant(displayWidth));
		view->rootContext()->setContextProperty("displayHeight", QVariant(displayHeight));
	}
	else
	{
		// LinX Linux VM development, use fixed size and just show the window
		view->setWidth(displayWidth);
		view->setHeight(displayHeight);

		view->rootContext()->setContextProperty("displayWidth", QVariant(displayWidth));
		view->rootContext()->setContextProperty("displayHeight", QVariant(displayHeight));

		view->setSource(QStringLiteral("qrc:/main.qml"));
		view->show();
	}

	QString resolution = QString("Screen resolution: %1x%2").arg(displayWidth).arg(displayHeight);
	qDebug() << resolution;

	dataEngine.fieldbusAccessError()->reset();

	return app.exec();
}

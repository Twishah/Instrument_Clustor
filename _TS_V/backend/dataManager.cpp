/******************************************************************************
 *
 * File:        dataManager.cpp
 *
 * Description: Load and save data from/in Json configuration file
 *
 * Copyright (C) 2023 T&S
 * All rights reserved.
 *
 * Code Template Revision: 1.0
 *
******************************************************************************/

/******************************************************************************
 * Include Files
******************************************************************************/

#include "dataManager.h"

/******************************************************************************
 * Class Methods
******************************************************************************/

DataManager::DataManager(QObject *parent)
	: m_file("/opt/fmc_hmi/configuration.json"),
	  m_backupFile("/opt/fmc_hmi/configuration.backup.json"),
	  m_defaultFile("/opt/fmc_hmi/configuration.default.json")
//    : m_file("/media/sf_shared_LinX/T-S-YANM0-23-502458_HMI_V7e/configuration.json"), // PC emulation
//      m_backupFile("/media/sf_shared_LinX/T-S-YANM0-23-502458_HMI_V7e/configuration.backup.json"), // PC emulation
//      m_defaultFile("/media/sf_shared_LinX/T-S-YANM0-23-502458_HMI_V7e/configuration.default.json") // PC emulation
{
	setParent(parent);

	m_indexLanguage = 2;
	m_language = "de";
	m_engineStopTimeIndex  = 1;
	m_engineStopTime = 1;
	m_indexPTO = 1;
	m_preHeating = new Pre_heating_settings(this);
	m_indexLockState = 1;
	m_dateTimeMode = 0;
	m_formatHour = 0;
	m_daylightSavingTime = 0;
	m_timeZone = "UTC+00:00";
	m_timeZoneIndex = 15;
	m_interval_hydraulicOil = 500;
	m_interval_hydraulicOilRetFilter = 1200;
	m_interval_hydraulicOilRetLineFilter = 1100;
	m_interval_travelReductionOil = 3500;
	m_mecHist_nbMax = MEC_HIST_NB_MAX;
	m_rcsBackward = 5;
	m_rcsForward = 5;
	m_ImmobActive = 1;
	m_ImmobActivationTime = 10;
	m_soundSetting = 1;
	m_supressBuzzerDTC = 0;
	m_supressBuzzerFlashingLight = 0;

	for(int i = 0; i < ACC_NB_MAX; i++)
	{
		m_acc_as[i] = new Flow_limit_acc(this);
	}

	m_dayBrightness = 255; // default value is 100% of 255
	m_nightBrightness = 77; // default value is 30% of 255

	for(int i = 0; i < MAIN_HIST_NB_MAX; i++)
	{
		m_maintenance_history[i] = new MaintenanceHistory(this);
	}

	for(int i = 0; i < MEC_HIST_NB_MAX; i++)
	{
		m_mechanic_history.push_back(new MechanicHistory(this));
	}

	m_OpTimeResetDate = "01/01/2024";
	m_OpTimeResetTime = "00:00";
	m_OpTimeResetHourmeter = 0.0;

	m_tempIsCelsius = 1;
	m_speedIsKmh = 1;
	m_pressure = 0;
	m_volume = 0;
}

DataManager::~DataManager()
{
	delete m_preHeating;
	for(int i = 0; i < ACC_NB_MAX; i++)
	{
		delete m_acc_as[i];
	}
	for(int i = 0; i < MAIN_HIST_NB_MAX; i++)
	{
		delete m_maintenance_history[i];
	}

	m_mechanic_history.clear();
	MEC_HIST_NB_MAX = 0;
	m_mecHist_nbMax = 0;
}

QJsonDocument DataManager::readDocument(QFile &file)
{
	qDebug() << "Reading document from file" << file.fileName();
	QJsonDocument document;

	if (file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QByteArray bytes = file.readAll();
		file.close();

		QJsonParseError jsonError;
		document = QJsonDocument::fromJson(bytes, &jsonError);

		if (jsonError.error != QJsonParseError::NoError)
		{
			qWarning() << "Couldn't parse JSON document:" << jsonError.errorString();
		}
	}
	else
	{
		qWarning() << "Couldn't open file" << file.fileName();
	}

	return document;
}

bool DataManager::writeDocument(QFile &file)
{
	qDebug() << "Writing document to file" << file.fileName();
	bool retCode = false;

	if (file.open(QIODevice::WriteOnly | QIODevice::Text))
	{
		// Serialize the updated object to a QByteArray
		QByteArray bytes = m_document.toJson(QJsonDocument::Indented);

		// Truncate the file and write the updated data
		file.resize(0);
		file.write(bytes);
		file.close();

		retCode = true;
	}
	else
	{
		qWarning() << "Couldn't open file" << file.fileName();
	}

	return retCode;
}

void DataManager::init()
{
	QJsonDocument document = readDocument(m_file);
	QJsonDocument backupDocument = readDocument(m_backupFile);
	QJsonDocument defaultDocument;

	if (document.isObject())
	{
		m_document = document;

		// Restore the backup file if it is invalid
		if (!backupDocument.isObject())
		{
			writeDocument(m_backupFile);
		}
	}
	else if (backupDocument.isObject())
	{
		m_document = backupDocument;
		// Restore the main file as it was invalid
		writeDocument(m_file);
	}
	else if ((defaultDocument = readDocument(m_defaultFile)).isObject())
	{
		m_document = defaultDocument;
		// Restore both the main file and the backup file as both were invalid
		writeDocument(m_file);
		writeDocument(m_backupFile);
	}
	else
	{
		qCritical() << "Couldn't read JSON document from any files";
	}

	if (m_document.isObject())
	{
		 QJsonObject jsonObj = m_document.object();
		 /* Load language data */
		 if( jsonObj.contains( "locale" ) )
		 {
			 QJsonObject obj = jsonObj.value( "locale" ).toObject();
			 QStringList keys = obj.keys();
			 for( auto key: keys )
			 {
				 auto value = obj.take( key );
				 if( key == "language" )
				 {
					 m_language = value.toString();
					 qDebug() << key << " : " << value.toString();
				 }
				 if( key == "index" )
				 {
					 m_indexLanguage = value.toInt();
					 qDebug() << key << " : " << value.toInt();
				 }
			 }
		 }
		 /* Load flow limit settings data */
		 if (jsonObj.contains("pto_settings")) {
			 QJsonObject ptoSettingsObj = jsonObj.value("pto_settings").toObject();

			 // Loop through each accessory
			 QStringList accKeys = ptoSettingsObj.keys();
			 int i = 0;
			 for (const QString& accKey : accKeys) {
				 QJsonObject accObj = ptoSettingsObj.value(accKey).toObject();

					 // Populate the flow_limit_acc struct with data from the JSON object
					 //Flow_limit_acc acc;
					 m_acc_as[i]->set_accessory_icon_source(accObj.value("accessory_icon_source").toString());
					 m_acc_as[i]->set_pto1_left(accObj.value("pto1_left").toInt());
					 m_acc_as[i]->set_pto1_right(accObj.value("pto1_right").toInt());
					 m_acc_as[i]->set_pto2_left(accObj.value("pto2_left").toInt());
					 m_acc_as[i]->set_pto2_right(accObj.value("pto2_right").toInt());

				 if( i < (ACC_NB_MAX - 1) )
					 i++;
				 else {
					 break;
				 }

			}
		 }
		 if( jsonObj.contains( "pto_index" ) )
		 {
			 QJsonObject obj = jsonObj.value( "pto_index" ).toObject();
			 QStringList keys = obj.keys();
			 for( auto key: keys )
			 {
				 auto value = obj.take( key );
				 if( key == "current_index" )
				 {
					 m_indexPTO = value.toInt();
					 qDebug() << key << " : " << value.toInt();
				 }
			 }
		 }
		 /* Load engine stop timer data */
		 if( jsonObj.contains( "engine" ) )
		 {
			 QJsonObject obj = jsonObj.value( "engine" ).toObject();
			 QStringList keys = obj.keys();
			 for( auto key: keys )
			 {
				 auto value = obj.take( key );
				 if( key == "stopTime" )
				 {
					 m_engineStopTime = value.toInt();
					 qDebug() << key << " : " << value.toInt();
				 }
				 if( key == "index" )
				 {
					 m_engineStopTimeIndex = value.toInt();
					 qDebug() << key << " : " << value.toInt();
				 }
			 }
		 }
		 /* Load pre heating settings */
		 if( jsonObj.contains( "pre_heating" ) )
		 {
			 QJsonObject obj = jsonObj.value( "pre_heating" ).toObject();
			 QStringList keys = obj.keys();
			 for( auto key: keys )
			 {
				 auto value = obj.take( key );
				 if( key == "start_minutes" )
				 {
					 m_preHeating->set_start_minutes(value.toInt());
					 qDebug() << key << " : " << value.toInt();
				 }
				 if( key == "start_hours" )
				 {
					 m_preHeating->set_start_hours(value.toInt());
					 qDebug() << key << " : " << value.toInt();
				 }
				 if( key == "active" )
				 {
					 m_preHeating->set_active(value.toBool());
					 qDebug() << key << " : " << value.toBool();
				 }
				 if( key == "am_pm" )
				 {
					 m_preHeating->set_am_pm(value.toString());
					 qDebug() << key << " : " << value.toString();
				 }
				 if( key == "date" )
				 {
					 QJsonArray dateArray = value.toArray();
					 for(int i=0; i<dateArray.size(); i++)
					 {
						 m_preHeating->set_date(i, dateArray.at(i).toBool());
					 }
				 }
			 }
		 }
		 /* Load lock state of aux flow limit depending on Mechanic Mode */
		 if( jsonObj.contains( "lockState_auxFlowLimit" ) )
		 {
			 QJsonObject obj = jsonObj.value( "lockState_auxFlowLimit" ).toObject();
			 QStringList keys = obj.keys();
			 for( auto key: keys )
			 {
				 auto value = obj.take( key );
				 if( key == "index" )
				 {
					 m_indexLockState = value.toInt();
					 qDebug() << key << " : " << value.toInt();
				 }
			 }
		 }
		 /* Load date time mode */
		 if( jsonObj.contains( "dateTime_mode" ) )
		 {
			 QJsonObject obj = jsonObj.value( "dateTime_mode" ).toObject();
			 QStringList keys = obj.keys();
			 for( auto key: keys )
			 {
				 auto value = obj.take( key );
				 if( key == "index" )
				 {
					 m_dateTimeMode = value.toInt();
					 qDebug() << key << " : " << value.toInt();
				 }
			 }
		 }
		 /* Load date time format hour */
		 if( jsonObj.contains( "dateTime_formatHour" ) )
		 {
			 QJsonObject obj = jsonObj.value( "dateTime_formatHour" ).toObject();
			 QStringList keys = obj.keys();
			 for( auto key: keys )
			 {
				 auto value = obj.take( key );
				 if( key == "index" )
				 {
					 m_formatHour = value.toInt();
					 qDebug() << key << " : " << value.toInt();
				 }
			 }
		 }
		 /* Load date time daylight saving time */
		 if( jsonObj.contains( "dateTime_daylightSavingTime" ) )
		 {
			 QJsonObject obj = jsonObj.value( "dateTime_daylightSavingTime" ).toObject();
			 QStringList keys = obj.keys();
			 for( auto key: keys )
			 {
				 auto value = obj.take( key );
				 if( key == "index" )
				 {
					 m_daylightSavingTime = value.toInt();
					 qDebug() << key << " : " << value.toInt();
				 }
			 }
		 }
		 /* Load date time auto: time zone */
		 if( jsonObj.contains( "dateTime_auto_timeZone" ) )
		 {
			 QJsonObject obj = jsonObj.value( "dateTime_auto_timeZone" ).toObject();
			 QStringList keys = obj.keys();
			 for( auto key: keys )
			 {
				 auto value = obj.take( key );
				 if( key == "value" )
				 {
					 m_timeZone = value.toString();
					 qDebug() << key << " : " << value.toString();
				 }
				 if( key == "index" )
				 {
					 m_timeZoneIndex = value.toInt();
					 qDebug() << key << " : " << value.toInt();
				 }
			 }
		 }
		 /* Load sound setting */
		 if( jsonObj.contains( "sound_setting" ) )
		 {
			 QJsonObject obj = jsonObj.value( "sound_setting" ).toObject();
			 QStringList keys = obj.keys();
			 for( auto key: keys )
			 {
				 auto value = obj.take( key );
				 if( key == "value" )
				 {
					 m_soundSetting = value.toInt();
					 qDebug() << key << " : " << value.toString();
				 }
			 }
		 }
		 /* Load brightness data */
		 if( jsonObj.contains( "brightness" ) )
		 {
			 QJsonObject obj = jsonObj.value( "brightness" ).toObject();
			 QStringList keys = obj.keys();
			 for( auto key: keys )
			 {
				 auto value = obj.take( key );
				 if( key == "dayBrightness" )
				 {
					 m_dayBrightness = value.toInt();
					 qDebug() << key << " : " << value.toInt();
				 }
				 if( key == "nightBrightness" )
				 {
					 m_nightBrightness = value.toInt();
					 qDebug() << key << " : " << value.toInt();
				 }
			 }
		 }

		 /* Load maintenance intervals */
		 if( jsonObj.contains( "maintenance_hydraulicOil" ) )
		 {
			 QJsonObject obj = jsonObj.value( "maintenance_hydraulicOil" ).toObject();
			 QStringList keys = obj.keys();
			 for( auto key: keys )
			 {
				 auto value = obj.take( key );
				 if( key == "interval_value" )
				 {
					 m_interval_hydraulicOil = value.toInt();
					 qDebug() << key << " : " << value.toInt();
				 }
			 }
		 }
		 if( jsonObj.contains( "maintenance_hydraulicOilRetFilter" ) )
		 {
			 QJsonObject obj = jsonObj.value( "maintenance_hydraulicOilRetFilter" ).toObject();
			 QStringList keys = obj.keys();
			 for( auto key: keys )
			 {
				 auto value = obj.take( key );
				 if( key == "interval_value" )
				 {
					 m_interval_hydraulicOilRetFilter = value.toInt();
					 qDebug() << key << " : " << value.toInt();
				 }
			 }
		 }
		 if( jsonObj.contains( "maintenance_hydraulicOilRetLineFilter" ) )
		 {
			 QJsonObject obj = jsonObj.value( "maintenance_hydraulicOilRetLineFilter" ).toObject();
			 QStringList keys = obj.keys();
			 for( auto key: keys )
			 {
				 auto value = obj.take( key );
				 if( key == "interval_value" )
				 {
					 m_interval_hydraulicOilRetLineFilter = value.toInt();
					 qDebug() << key << " : " << value.toInt();
				 }
			 }
		 }
		 if( jsonObj.contains( "maintenance_travelReductionOil" ) )
		 {
			 QJsonObject obj = jsonObj.value( "maintenance_travelReductionOil" ).toObject();
			 QStringList keys = obj.keys();
			 for( auto key: keys )
			 {
				 auto value = obj.take( key );
				 if( key == "interval_value" )
				 {
					 m_interval_travelReductionOil = value.toInt();
					 qDebug() << key << " : " << value.toInt();
				 }
			 }
		 }

		 /* Load maintenance history data */
		 if (jsonObj.contains("maintenance_history")) {
			 QJsonObject mainHistObj = jsonObj.value("maintenance_history").toObject();

			 // Loop through each accessory
			 QStringList mainHistKeys = mainHistObj.keys();
			 int i = 0;
			 for (const QString& mainHistKey : mainHistKeys) {
				 QJsonObject obj = mainHistObj.value(mainHistKey).toObject();

					 // Populate the maintenance_history struct with data from the JSON object
					 //Maintenance_history data;
					 m_maintenance_history[i]->set_date1(obj.value("date1").toString());
					 m_maintenance_history[i]->set_hourMeter1(obj.value("hourMeter1").toDouble());
					 m_maintenance_history[i]->set_date2(obj.value("date2").toString());
					 m_maintenance_history[i]->set_hourMeter2(obj.value("hourMeter2").toDouble());

					 qDebug() << "date1" << " : " << obj.value("date1").toString();
					 qDebug() << "hourMeter1" << " : " << obj.value("hourMeter1").toDouble();
					 qDebug() << "date2" << " : " << obj.value("date2").toString();
					 qDebug() << "hourMeter2" << " : " << obj.value("hourMeter2").toDouble();

				 if( i < (MAIN_HIST_NB_MAX - 1) )
					 i++;
				 else {
					 break;
				 }
			}
		 }

		 /* Load mechanic usage history data */
		 if( jsonObj.contains( "mechanic_history_nb_max" ) )
		 {
			 QJsonObject obj = jsonObj.value( "mechanic_history_nb_max" ).toObject();
			 QStringList keys = obj.keys();
			 for( auto key: keys )
			 {
				 auto value = obj.take( key );
				 if( key == "nb_max" )
				 {
					 m_mecHist_nbMax = value.toInt();
					 qDebug() << key << " : " << value.toInt();
					 MEC_HIST_NB_MAX = m_mecHist_nbMax;
				 }
			 }
		 }
		 if (jsonObj.contains("mechanic_history")) {
			 QJsonObject mecHistObj = jsonObj.value("mechanic_history").toObject();

			 // Loop through each accessory
			 QStringList mecHistKeys = mecHistObj.keys();
			 int i = 0;
			 for (const QString& mecHistKey : mecHistKeys) {
				 QJsonObject obj = mecHistObj.value(mecHistKey).toObject();

					 // Populate the mechanic_history struct with data from the JSON object
					 //Mechanic_history data;
					m_mechanic_history.push_back(new MechanicHistory(this)); // !!!

					m_mechanic_history[i]->set_dateMecHist(obj.value("date_mec").toString());
					m_mechanic_history[i]->set_timeMecHist(obj.value("time_mec").toString());
					m_mechanic_history[i]->set_hourmeterMecHist(obj.value("hourmeter_mec").toDouble());

					qDebug() << "date_mec "<< i << " : " << obj.value("date_mec").toString();
					qDebug() << "time_mec "<< i << " : " << obj.value("time_mec").toString();
					qDebug() << "hourmeter_mec "<< i << " : " << obj.value("hourmeter_mec").toDouble();


				 if( i < (MEC_HIST_NB_MAX - 1) ) {
					 i++;
				 }
				 else {
					 break;
				 }
			}
		 }

		 /* Load brightness data */
		 if( jsonObj.contains( "OpTimeReset" ) )
		 {
			 QJsonObject obj = jsonObj.value( "OpTimeReset" ).toObject();
			 QStringList keys = obj.keys();
			 for( auto key: keys )
			 {
				 auto value = obj.take( key );
				 if( key == "date" )
				 {
					 m_OpTimeResetDate = value.toString();
					 qDebug() << key << " : " << value.toString();
				 }
				 if( key == "time" )
				 {
					 m_OpTimeResetTime = value.toString();
					 qDebug() << key << " : " << value.toString();
				 }
				 if( key == "hourmeter" )
				 {
					 m_OpTimeResetHourmeter = value.toDouble();
					 qDebug() << key << " : " << value.toDouble();
				 }
			 }
		 }

		 /* Load temperature unit */
		 if( jsonObj.contains( "TempUnit_isCelsius" ) )
		 {
			 QJsonObject obj = jsonObj.value( "TempUnit_isCelsius" ).toObject();
			 QStringList keys = obj.keys();
			 for( auto key: keys )
			 {
				 auto value = obj.take( key );
				 if( key == "index" )
				 {
					 m_tempIsCelsius = value.toInt();
					 qDebug() << key << " : " << value.toInt();
				 }
			 }
		 }

		 /* Load speed unit */
		 if( jsonObj.contains( "speed_unit_isKmh" ) )
		 {
			 QJsonObject obj = jsonObj.value( "speed_unit_isKmh" ).toObject();
			 QStringList keys = obj.keys();
			 for( auto key: keys )
			 {
				 auto value = obj.take( key );
				 if( key == "index" )
				 {
					 m_speedIsKmh = value.toInt();
					 qDebug() << key << " : " << value.toInt();
				 }
			 }
		 }
		 /* Load pressure unit */
		 if( jsonObj.contains( "pressure_unit" ) )
		 {
			 QJsonObject obj = jsonObj.value( "pressure_unit" ).toObject();
			 QStringList keys = obj.keys();
			 for( auto key: keys )
			 {
				 auto value = obj.take( key );
				 if( key == "index" )
				 {
					 m_pressure = value.toInt();
					 qDebug() << key << " : " << value.toInt();
				 }
			 }
		 }


		 /* Load RCS settings */
		 if( jsonObj.contains( "rcs_settings" ) )
		 {
			 QJsonObject obj = jsonObj.value( "rcs_settings" ).toObject();
			 QStringList keys = obj.keys();
			 for( auto key: keys )
			 {
				 auto value = obj.take( key );
				 if( key == "rcs_forward" )
				 {
					 m_rcsForward = value.toInt();
					 qDebug() << key << " : " << value.toInt();
				 }
				 if( key == "rcs_backward" )
				 {
					 m_rcsBackward = value.toInt();
					 qDebug() << key << " : " << value.toInt();
				 }
			 }
		 }

		 /* Load immobilizer activation */
		 if( jsonObj.contains( "immob_active" ) )
		 {
			 QJsonObject obj = jsonObj.value( "immob_active" ).toObject();
			 QStringList keys = obj.keys();
			 for( auto key: keys )
			 {
				 auto value = obj.take( key );
				 if( key == "index" )
				 {
					 m_ImmobActive = value.toInt();
					 qDebug() << key << " : " << value.toInt();
				 }
			 }
		 }

				  /* Load volume unit */
		 if( jsonObj.contains( "volume_unit" ) )
		 {
			 QJsonObject obj = jsonObj.value( "volume_unit" ).toObject();
			 QStringList keys = obj.keys();
			 for( auto key: keys )
			 {
				 auto value = obj.take( key );
				 if( key == "index" )
				 {
					 m_volume = value.toInt();
					 qDebug() << key << " : " << value.toInt();
				 }
			 }
		 }

		 /* Load immobilizer activation time */
		 if( jsonObj.contains( "immob_activation_time" ) )
		 {
			 QJsonObject obj = jsonObj.value( "immob_activation_time" ).toObject();
			 QStringList keys = obj.keys();
			 for( auto key: keys )
			 {
				 auto value = obj.take( key );
				 if( key == "index" )
				 {
					 m_ImmobActivationTime = value.toInt();
					 qDebug() << key << " : " << value.toInt();
				 }
			 }
		 }


		 /* Load buzzer-items */
		 if( jsonObj.contains( "buzzer" ) )
		 {
			 QJsonObject obj = jsonObj.value( "buzzer" ).toObject();
			 QStringList keys = obj.keys();
			 for( auto key: keys )
			 {
				 auto value = obj.take( key );
				 if( key == "supressBuzzerDTC" )
				 {
					 m_supressBuzzerDTC = value.toInt();
					 qDebug() << key << " : " << value.toInt();
				 }
				 else if( key == "supressBuzzerFlashingLight" )
				 {
					 m_supressBuzzerFlashingLight = value.toInt();
					 qDebug() << key << " : " << value.toInt();
				 }
			 }
		 }

	}
}

bool DataManager::saveJSON(QJsonObject content, QString contentName)
{
	QJsonObject rootObject = m_document.object();
	bool retCode = true;

	// If the new content differs from the previous one (avoid repeatedly
	// writing the same content to the configuration files)
	if (rootObject[contentName] != content)
	{
		// Serialize the updated object to a QByteArray
		rootObject.insert(contentName, content);
		m_document.setObject(rootObject);

		// Truncate the file and write the updated data
		bool fileOK = writeDocument(m_file);
		bool backupFileOK = writeDocument(m_backupFile);
		retCode = fileOK && backupFileOK;
	}

	return retCode;
}

/* ---- LANGUAGES ---- */
int DataManager::getIndexLanguage()
{
	return m_indexLanguage;
}

QString DataManager::getLanguage()
{
	return m_language;
}

void DataManager::selectLanguage(QString language_code, int index)
{
	m_language = language_code;
	m_indexLanguage = index;
	QJsonObject locale;
	locale.insert("language", language_code);
	locale.insert("index", index);

	saveJSON(locale, "locale");
}

/* ---- PTO SETTINGS ---- */
Flow_limit_acc* DataManager::getPtoSettings(int index_acc)
{
	if (index_acc >= ACC_NB_MAX) return (0);

	return m_acc_as[index_acc];
}

void DataManager::savePtoSettings()
{
	QJsonObject acc_x;
	QJsonObject content;
	for(int i=0; i<ACC_NB_MAX; i++)
	{
		acc_x.insert("accessory_icon_source", m_acc_as[i]->accessory_icon_source());
		acc_x.insert("pto1_left", m_acc_as[i]->pto1_left());
		acc_x.insert("pto1_right", m_acc_as[i]->pto1_right());
		acc_x.insert("pto2_left", m_acc_as[i]->pto2_left());
		acc_x.insert("pto2_right", m_acc_as[i]->pto2_right());
		content.insert("ACC_" + QString::number(i+1), acc_x);
	}

	saveJSON(content, "pto_settings");
}

int DataManager::get_indexPTO()
{
	return m_indexPTO;
}

void DataManager::save_indexPTO()
{
	QJsonObject content;
	content.insert("current_index", m_indexPTO);
	saveJSON(content, "pto_index");
}

void DataManager::set_indexPTO(int indexPTO)
{
	m_indexPTO = indexPTO;
	emit indexPTOChanged(m_indexPTO);
}

/* ---- ENGINE STOP TIME ---- */
int DataManager::getIndexStopTime()
{

	return m_engineStopTimeIndex;
}

int DataManager::engineStopTime()
{
	return m_engineStopTime;
}

int DataManager::get_engineStopTime()
{
	return m_engineStopTime;
}

void DataManager::set_engineStopTime(int stopTime)
{
	if (stopTime >= 100)
		m_engineStopTime = stopTime / 10;
	else
		m_engineStopTime = stopTime;

	if(stopTime <= 6) {
		m_engineStopTimeIndex = stopTime;
	}
	else if(stopTime == 8) {
		m_engineStopTimeIndex = 7;
	}
	else if(stopTime == 10) {
		m_engineStopTimeIndex = 8;
	}
	else {
		m_engineStopTimeIndex = (stopTime / 100);
	}

	emit engineStopTimeChanged(m_engineStopTime);
}

void DataManager::saveEngineStopTime()
{
	QJsonObject engine;
	engine.insert("stopTime", m_engineStopTime);
	engine.insert("index", m_engineStopTimeIndex);

	saveJSON(engine, "engine");
}

/* ---- PRE HEATING SETTINGS ---- */
Pre_heating_settings* DataManager::getPreHeating()
{
	return m_preHeating;
}

void DataManager::savePreHeatingSettings()
{
	QJsonObject preHeating;
	QJsonArray dateArray;
	preHeating.insert("start_minutes", m_preHeating->start_minutes());
	preHeating.insert("start_hours", m_preHeating->start_hours());
	preHeating.insert("active", m_preHeating->active());
	preHeating.insert("am_pm", m_preHeating->am_pm());

	for(int i=0; i < WEEK_DAYS; i++)
		dateArray.append(m_preHeating->get_date(i));

	preHeating.insert("date", dateArray);

	saveJSON(preHeating, "pre_heating");
}

bool DataManager::getPreHeatingDate(int index)
{
	return m_preHeating->get_date(index);
}

void DataManager::setPreHeatingDate(int index, bool state)
{
	m_preHeating->set_date(index, state);
}

/* ---- AUX FLOW LIMIT LOCK OF MECHANIC MODE ---- */
int DataManager::get_indexLockState()
{
	return m_indexLockState;
}

void DataManager::set_indexLockState(int indexLockState)
{
	m_indexLockState = indexLockState;
	emit indexLockStateChanged(m_indexLockState);
}

void DataManager::saveLockSate()
{
	QJsonObject lockState_auxFlowLimit;
	lockState_auxFlowLimit.insert("index", m_indexLockState);

	saveJSON(lockState_auxFlowLimit, "lockState_auxFlowLimit");
}

/* ---- DATE TIME MODE (date and time) ---- */
int DataManager::getDateTimeMode()
{
	return m_dateTimeMode;
}

void DataManager::saveDateTimeMode() {
	QJsonObject dateTime_mode;
	dateTime_mode.insert("index", m_dateTimeMode);

	saveJSON(dateTime_mode, "dateTime_mode");
}

void DataManager::setDateTimeMode(int dateTimeMode)
{
	m_dateTimeMode = dateTimeMode;
	emit dateTimeModeChanged(m_dateTimeMode);
}

/* ---- FORMAT HOUR (date and time) ---- */
int DataManager::getFormatHour()
{
	return m_formatHour;
}

void DataManager::saveFormatHour() {
	QJsonObject dateTime_formatHour;
	dateTime_formatHour.insert("index", m_formatHour);

	saveJSON(dateTime_formatHour, "dateTime_formatHour");
}

void DataManager::setFormatHour(int formatHour)
{
	m_formatHour = formatHour;
	emit formatHourChanged(m_formatHour);
}

/* ---- DAYLIGHT SAVING TIME (date and time) ---- */
int DataManager::getDaylightSavingTime()
{
	return m_daylightSavingTime;
}

void DataManager::saveDaylightSavingTime() {
	QJsonObject dateTime_daylightSavingTime;
	dateTime_daylightSavingTime.insert("index", m_daylightSavingTime);

	saveJSON(dateTime_daylightSavingTime, "dateTime_daylightSavingTime");
}

void DataManager::setDaylightSavingTime(int daylightSavingTime)
{
	m_daylightSavingTime = daylightSavingTime;
	emit daylightSavingTimeChanged(m_daylightSavingTime);
}


/* ---- TIME ZONE (date and time auto) ---- */

QString DataManager::getTimeZone()
{
	return m_timeZone;
}

int DataManager::getTimeZoneIndex()
{
	return m_timeZoneIndex;
}

void DataManager::saveTimeZone() {
	QJsonObject dateTime_auto_timeZone;
	dateTime_auto_timeZone.insert("value", m_timeZone);
	dateTime_auto_timeZone.insert("index", m_timeZoneIndex);

	saveJSON(dateTime_auto_timeZone, "dateTime_auto_timeZone");
}

void DataManager::setTimeZone(const QString timeZone)
{
	m_timeZone = timeZone;
	emit timeZoneChanged(m_timeZone);
}

void DataManager::setTimeZoneIndex(int index)
{
	m_timeZoneIndex = index;
}

/* ---- BRIGHTNESS ---- */
int DataManager::getDayBrightness()
{
	return m_dayBrightness;
}

int DataManager::getNightBrightness()
{
	return m_nightBrightness;
}


void DataManager::setDayBrightness(int dayBrightness)
{
	m_dayBrightness = dayBrightness;
	//emit dayBrightnessChanged(m_dayBrightness);
}

void DataManager::setNightBrightness(int nightBrightness)
{
	m_nightBrightness = nightBrightness;
	//emit nightBrightnessChanged(m_nightBrightness);
}

void DataManager::saveBrightness()
{
	QJsonObject brightness;
	brightness.insert("dayBrightness", m_dayBrightness);
	brightness.insert("nightBrightness", m_nightBrightness);

	saveJSON(brightness, "brightness");
}




/* ---- OPERATIONAL TIME MEASUREMENT ---- */

QString DataManager::getOpTimeResetDate()
{
	return m_OpTimeResetDate;
}

QString DataManager::getOpTimeResetTime()
{
	return m_OpTimeResetTime;
}

double DataManager::getOpTimeResetHourmeter()
{
	return m_OpTimeResetHourmeter;
}

void DataManager::setOpTimeResetDate(QString resetDate)
{
	m_OpTimeResetDate = resetDate;
}

void DataManager::setOpTimeResetTime(QString resetTime)
{
	m_OpTimeResetTime = resetTime;
}

void DataManager::setOpTimeResetHourmeter(double hourmeterAtReset)
{
	m_OpTimeResetHourmeter = hourmeterAtReset;
}

void DataManager::saveOpTimeResetEvent()
{
	QJsonObject resetEvent;
	resetEvent.insert("date", m_OpTimeResetDate);
	resetEvent.insert("time", m_OpTimeResetTime);
	resetEvent.insert("hourmeter", m_OpTimeResetHourmeter);

	saveJSON(resetEvent, "OpTimeReset");
}


/* ---- MAINTENANCE INTERVAL ---- */
int DataManager::get_interval_hydraulicOil()
{
	return m_interval_hydraulicOil;
}

void DataManager::save_interval_hydraulicOil()
{
	QJsonObject maintenance_hydraulicOil;
	maintenance_hydraulicOil.insert("interval_value", m_interval_hydraulicOil);

	saveJSON(maintenance_hydraulicOil, "maintenance_hydraulicOil");
}

void DataManager::set_interval_hydraulicOil(int interval_hydraulicOil)
{
	m_interval_hydraulicOil = interval_hydraulicOil;
	save_interval_hydraulicOil();
	emit interval_hydraulicOilChanged(m_interval_hydraulicOil);
}

int DataManager::get_interval_hydraulicOilRetFilter()
{
	return m_interval_hydraulicOilRetFilter;
}

void DataManager::save_interval_hydraulicOilRetFilter()
{
	QJsonObject maintenance_hydraulicOilRetFilter;
	maintenance_hydraulicOilRetFilter.insert("interval_value", m_interval_hydraulicOilRetFilter);

	saveJSON(maintenance_hydraulicOilRetFilter, "maintenance_hydraulicOilRetFilter");
}

void DataManager::set_interval_hydraulicOilRetFilter(int interval_hydraulicOilRetFilter)
{
	m_interval_hydraulicOilRetFilter = interval_hydraulicOilRetFilter;
	save_interval_hydraulicOilRetFilter();
	emit interval_hydraulicOilRetFilterChanged(m_interval_hydraulicOilRetFilter);
}

int DataManager::get_interval_hydraulicOilRetLineFilter()
{
	return m_interval_hydraulicOilRetLineFilter;
}

void DataManager::save_interval_hydraulicOilRetLineFilter()
{
	QJsonObject maintenance_hydraulicOilRetLineFilter;
	maintenance_hydraulicOilRetLineFilter.insert("interval_value", m_interval_hydraulicOilRetLineFilter);

	saveJSON(maintenance_hydraulicOilRetLineFilter, "maintenance_hydraulicOilRetLineFilter");
}

void DataManager::set_interval_hydraulicOilRetLineFilter(int interval_hydraulicOilRetLineFilter)
{
	m_interval_hydraulicOilRetLineFilter = interval_hydraulicOilRetLineFilter;
	save_interval_hydraulicOilRetLineFilter();
	emit interval_hydraulicOilRetLineFilterChanged(m_interval_hydraulicOilRetLineFilter);
}

int DataManager::get_interval_travelReductionOil()
{
	return m_interval_travelReductionOil;
}

void DataManager::save_interval_travelReductionOil()
{
	QJsonObject maintenance_travelReductionOil;
	maintenance_travelReductionOil.insert("interval_value", m_interval_travelReductionOil);

	saveJSON(maintenance_travelReductionOil, "maintenance_travelReductionOil");
}

void DataManager::set_interval_travelReductionOil(int interval_travelReductionOil)
{
	m_interval_travelReductionOil = interval_travelReductionOil;
	save_interval_travelReductionOil();
	emit interval_travelReductionOilChanged(m_interval_travelReductionOil);
}


/* ---- MAINTENANCE HISTORY ---- */
MaintenanceHistory* DataManager::get_maintenance_history(int index_mainHist)
{
	return m_maintenance_history[index_mainHist];
}

void DataManager::save_maintenance_history()
{
	QJsonObject data;
	QJsonObject maintenance_history;
	for(int i=0; i<MAIN_HIST_NB_MAX; i++)
	{
		data.insert("date1", m_maintenance_history[i]->get_date1());
		data.insert("hourMeter1", m_maintenance_history[i]->get_hourMeter1());
		data.insert("date2", m_maintenance_history[i]->get_date2());
		data.insert("hourMeter2", m_maintenance_history[i]->get_hourMeter2());

		maintenance_history.insert("DATA_" + QString::number(i+1), data);

		qDebug() << data;
	}

	saveJSON(maintenance_history, "maintenance_history");
}


/* ---- MECHANIC USAGE HISTORY ---- */
MechanicHistory *DataManager::get_mechanic_history(int index_mecHist)
{
	return m_mechanic_history[index_mecHist];
}

void DataManager::save_mechanic_history()
{
	QJsonObject data;
	QJsonObject mechanic_history;

	for(int i=0; i<MEC_HIST_NB_MAX; i++)
	{
		data.insert("date_mec", m_mechanic_history[i]->get_dateMecHist());
		data.insert("time_mec", m_mechanic_history[i]->get_timeMecHist());
		data.insert("hourmeter_mec", m_mechanic_history[i]->get_hourmeterMecHist());

		//qDebug() << "SAVE mecHist " << i+1 << " : " << m_mechanic_history[i]->get_dateMecHist() << " " << m_mechanic_history[i]->get_timeMecHist() << " " << m_mechanic_history[i]->get_hourmeterMecHist();
		//qDebug() << "SAVE mecHist " << i+1 << " : " << data;

		QString nbData = QString::number(i+1);
		if ((i+1) < 10) {
			nbData = "0" + nbData;
		}

		mechanic_history.insert("DATA_" + nbData, data);
	}

	saveJSON(mechanic_history, "mechanic_history");
}

int DataManager::get_mecHist_nbMax()
{
	return m_mecHist_nbMax;
}

void DataManager::save_mecHist_nbMax()
{
	QJsonObject mechanic_history_nb_max;
	mechanic_history_nb_max.insert("nb_max", m_mecHist_nbMax);

	saveJSON(mechanic_history_nb_max, "mechanic_history_nb_max");

	// To create a new element in the begining of the vector
	if (m_mecHist_nbMax > MEC_HIST_NB_MAX) {
		m_mechanic_history.insert(m_mechanic_history.begin(), new MechanicHistory(this));
	}
	// To erase the last element and add a new one
	else if (m_mecHist_nbMax == MEC_HIST_NB_MAX) {
		m_mechanic_history.pop_back();
		m_mechanic_history.insert(m_mechanic_history.begin(), new MechanicHistory(this));
	}
	// To clear the vector when reset is needed
	else {
		m_mechanic_history.clear();
	}
	MEC_HIST_NB_MAX = m_mecHist_nbMax;
}

void DataManager::set_mecHist_nbMax(int mecHist_nbMax)
{
	m_mecHist_nbMax = mecHist_nbMax;
	emit mecHist_nbMaxChanged(m_mecHist_nbMax);
}

void DataManager::set_mechanic_history(int index_mecHist, QString date, QString time, int hourmeter) {
	MechanicHistory* myMecHist = new MechanicHistory(this);
	myMecHist->set_dateMecHist(date);
	myMecHist->set_timeMecHist(time);
	myMecHist->set_hourmeterMecHist(hourmeter);
	m_mechanic_history.insert(m_mechanic_history.begin() + index_mecHist, myMecHist);
}

/* ---- TEMPERATURE UNIT TempUnit_isCelsius ---- */
int DataManager::getTempUnitIsCelsius()
{
	return m_tempIsCelsius;
}

void DataManager::saveTemperatureUnit() {
	QJsonObject TempUnit_isCelsius;
	TempUnit_isCelsius.insert("index", m_tempIsCelsius);

	saveJSON(TempUnit_isCelsius, "TempUnit_isCelsius");
}

void DataManager::setTemperatureUnitCelsius(int temperatureUnitisCelsius)
{
	m_tempIsCelsius = temperatureUnitisCelsius;
	emit tempUnitChanged(m_tempIsCelsius);
}

/* ---- RCS SETTINGS ---- */
int DataManager::getRCSForward()
{
	return m_rcsForward;
}

int DataManager::getRCSBackward()
{
	return m_rcsBackward;
}

void DataManager::saveRCSSettings()
{
	QJsonObject RCSSettings;
	RCSSettings.insert("rcs_forward", m_rcsForward);
	RCSSettings.insert("rcs_backward", m_rcsBackward);
	saveJSON(RCSSettings, "rcs_settings");
}

void DataManager::setRCSForward(int rcsForward)
{

	m_rcsForward = rcsForward;
	emit rcsForwardChanged(m_rcsForward);
}

void DataManager::setRCSBackward(int rcsBackward)
{
	m_rcsBackward = rcsBackward;
	emit rcsBackwardChanged(m_rcsBackward);
}



/* ---- IMMOBILIZER PARAMETERS ---- */
int DataManager::get_isImmobActive()
{
	return m_ImmobActive;
}

int DataManager::get_ImmobActivationTime()
{
	return m_ImmobActivationTime;
}

void DataManager::set_immobActive(int isActive)
{
	m_ImmobActive = isActive;
	emit immobActiveChanged(m_ImmobActive);
}

void DataManager::set_immobActivationTime(int minutes)
{
	m_ImmobActivationTime = minutes;
	emit immobActivationTimeChanged(m_ImmobActivationTime);
}

void DataManager::saveImmobActive()
{
	QJsonObject immob_active;
	immob_active.insert("index", m_ImmobActive);

	saveJSON(immob_active, "immob_active");
}

void DataManager::saveImmobActivationTime()
{
	QJsonObject immob_activation_time;
	immob_activation_time.insert("index", m_ImmobActivationTime);

	saveJSON(immob_activation_time, "immob_activation_time");
}

/* ---- SPEED UNIT speed_unit_isKmh ---- */
int DataManager::getSpeedUnitIsKmh()
{
	return m_speedIsKmh;
}

void DataManager::saveSpeedUnit() {
	QJsonObject speed_unit_isKmh;
	speed_unit_isKmh.insert("index", m_speedIsKmh);

	saveJSON(speed_unit_isKmh, "speed_unit_isKmh");
}

void DataManager::setSpeedUnitIsKmh(int speedUnitIsKmh)
{
	m_speedIsKmh = speedUnitIsKmh;
	emit speedUnitChanged(m_speedIsKmh);
}

/* ---- PRESSURE UNIT pressure_unit ---- */
int DataManager::getPressureUnit()
{
	return m_pressure;
}

void DataManager::savePressureUnit() {
	QJsonObject pressure_unit;
	pressure_unit.insert("index", m_pressure);

	saveJSON(pressure_unit, "pressure_unit");
}

void DataManager::setPressureUnit(int pressureUnit)
{
	m_pressure = pressureUnit;
	emit pressureUnitChanged(m_pressure);
}

/* ---- PRESSURE UNIT volume_unit ---- */
int DataManager::getVolumeUnit()
{
	return m_volume;
}

void DataManager::saveVolumeUnit() {
	QJsonObject volume_unit;
	volume_unit.insert("index", m_volume);

	saveJSON(volume_unit, "volume_unit");
}

void DataManager::setVolumeUnit(int volumeUnit)
{
	m_volume = volumeUnit;
	emit volumeUnitChanged(m_volume);
}

/* ---- SOUND SETTING ---- */
int DataManager::getSoundSetting()
{
	return m_soundSetting;
}

void DataManager::saveSoundSetting() {
	QJsonObject sound_setting;
	sound_setting.insert("value", m_soundSetting);

	saveJSON(sound_setting, "sound_setting");
}

void DataManager::setSoundSetting(int soundSetting)
{
	m_soundSetting = soundSetting;
	emit soundSettingChanged(m_soundSetting);
}


/* ---- Buzzer SETTING ---- */
int DataManager::getSupressBuzzerDTC()
{
	return m_supressBuzzerDTC;
}

void DataManager::saveSupressBuzzerDTC() {
	QJsonObject buzzer;
	buzzer.insert("supressBuzzerDTC", m_supressBuzzerDTC);
	saveJSON(buzzer, "supressBuzzerDTC");
}

void DataManager::setSupressBuzzerDTC(int supressBuzzerDtc)
{
	m_supressBuzzerDTC = supressBuzzerDtc;
	emit supressBuzzerDtcChanged(supressBuzzerDtc);
}

int DataManager::getSupressBuzzerFlashingLight()
{
	return m_supressBuzzerFlashingLight;
}

void DataManager::saveSupressBuzzerFlashingLight() {
	QJsonObject buzzer;
	buzzer.insert("supressBuzzerFlashingLight", m_supressBuzzerFlashingLight);
	saveJSON(buzzer, "supressBuzzerFlashingLight");
}

void DataManager::setSupressBuzzerFlashingLight(int supressBuzzerFlashingLight)
{
	m_supressBuzzerFlashingLight = supressBuzzerFlashingLight;
	emit supressBuzzerFlashingLightChanged(supressBuzzerFlashingLight);
}

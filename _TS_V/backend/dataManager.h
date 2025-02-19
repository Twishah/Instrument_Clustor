/******************************************************************************
 *
 * File:        dataManager.h
 *
 * Description: Load and save data from/in Json configuration file
 * List of data stored in display device :
 *  - time
 *  - date
 *  - brightness
 *  - language
 *  - automatic engine stop time
 *  - flow limit settings
 *
 * Copyright (C) 2023 T&S
 * All rights reserved.
 *
 * Code Template Revision: 1.0
 *
******************************************************************************/

/******************************************************************************
 * Nesting Header
******************************************************************************/
#ifndef DATAMANAGER_H
#define DATAMANAGER_H

/******************************************************************************
 * Include Files
******************************************************************************/
#include <QGuiApplication>
#include <QProcess>

#include <QObject>
#include <QtQml>
#include <array>
#include <QFile>
#include <QDebug>
#include <QJsonObject>
#include <QJsonParseError>

#include "ptosettings.h"
#include "preheating.h"
#include "maintenancehistory.h"
#include "mechanichistory.h"

/******************************************************************************
 * Manifest Constants, Macros
******************************************************************************/

// Maximum of 5 accessory stored in memory
const int ACC_NB_MAX = 7;

// Number of week days
const int WEEK_DAYS = 7;

// Number of items to be maintained
const int MAIN_HIST_NB_MAX = 4;

// Number of access in mechanic mode (usage history)
static int MEC_HIST_NB_MAX = 0;


/******************************************************************************
 * Class Declaration
******************************************************************************/
/**
 * @brief The DataManager class is responsible for the Json file manipulation
 * All permanent data are stored in configuration.json file
 */
class DataManager : public QObject
{
	Q_OBJECT

	Q_PROPERTY(int engineStopTime READ engineStopTime WRITE set_engineStopTime NOTIFY engineStopTimeChanged)
	Q_PROPERTY(int indexPTO READ get_indexPTO WRITE set_indexPTO NOTIFY indexPTOChanged)
	Q_PROPERTY(int indexLockState READ get_indexLockState WRITE set_indexLockState NOTIFY indexLockStateChanged)

	Q_PROPERTY(int dateTimeMode READ getDateTimeMode WRITE setDateTimeMode NOTIFY dateTimeModeChanged)
	Q_PROPERTY(int formatHour READ getFormatHour WRITE setFormatHour NOTIFY formatHourChanged)
	Q_PROPERTY(int daylightSavingTime READ getDaylightSavingTime WRITE setDaylightSavingTime NOTIFY daylightSavingTimeChanged)
	Q_PROPERTY(QString timeZone READ getTimeZone WRITE setTimeZone NOTIFY timeZoneChanged)
	Q_PROPERTY(int soundSetting READ getSoundSetting WRITE setSoundSetting NOTIFY soundSettingChanged)

	Q_PROPERTY(int supressBuzzerDtc READ getSupressBuzzerDTC WRITE setSupressBuzzerDTC NOTIFY supressBuzzerDtcChanged)
	Q_PROPERTY(int supressBuzzerFlashingLight READ getSupressBuzzerFlashingLight WRITE setSupressBuzzerFlashingLight NOTIFY supressBuzzerFlashingLightChanged)

	Q_PROPERTY(int interval_hydraulicOil READ get_interval_hydraulicOil WRITE set_interval_hydraulicOil NOTIFY interval_hydraulicOilChanged)
	Q_PROPERTY(int interval_hydraulicOilRetFilter READ get_interval_hydraulicOilRetFilter WRITE set_interval_hydraulicOilRetFilter NOTIFY interval_hydraulicOilRetFilterChanged)
	Q_PROPERTY(int interval_hydraulicOilRetLineFilter READ get_interval_hydraulicOilRetLineFilter WRITE set_interval_hydraulicOilRetLineFilter NOTIFY interval_hydraulicOilRetLineFilterChanged)
	Q_PROPERTY(int interval_travelReductionOil READ get_interval_travelReductionOil WRITE set_interval_travelReductionOil NOTIFY interval_travelReductionOilChanged)

	Q_PROPERTY(int mecHist_nbMax READ get_mecHist_nbMax WRITE set_mecHist_nbMax NOTIFY mecHist_nbMaxChanged)

	Q_PROPERTY(int tempUnitIsCelsius READ getTempUnitIsCelsius WRITE setTemperatureUnitCelsius NOTIFY tempUnitChanged)

	Q_PROPERTY(int rcsFoward READ getRCSForward WRITE setRCSForward NOTIFY rcsForwardChanged)
	Q_PROPERTY(int rcsBackward READ getRCSBackward WRITE setRCSBackward NOTIFY rcsBackwardChanged)

	Q_PROPERTY(int isImmobActive READ get_isImmobActive WRITE set_immobActive NOTIFY immobActiveChanged)
	Q_PROPERTY(int immobActivationTime READ get_ImmobActivationTime WRITE set_immobActivationTime NOTIFY immobActivationTimeChanged)

	Q_PROPERTY(int speedUnitIsKmh READ getSpeedUnitIsKmh WRITE setSpeedUnitIsKmh NOTIFY speedUnitChanged)
	Q_PROPERTY(int pressureUnit READ getPressureUnit WRITE setPressureUnit NOTIFY pressureUnitChanged)
	Q_PROPERTY(int volumeUnit READ getVolumeUnit WRITE setVolumeUnit NOTIFY volumeUnitChanged)


public:
	explicit DataManager(QObject *parent = 0);
	~DataManager();

	/**
	* @brief Initializes the data manager, sets up its objects and gets all the values from
	* configuration file.
	*/
	void init();

	bool saveJSON(QJsonObject content, QString contentName);

	/* Functions used for language management */
	Q_INVOKABLE int getIndexLanguage();
	Q_INVOKABLE void selectLanguage(QString language_code, int index);
	QString getLanguage(void);

	/* Functions used for pto settings management */
	Q_INVOKABLE Flow_limit_acc* getPtoSettings(int index_acc);
	Q_INVOKABLE void savePtoSettings();
	Q_INVOKABLE int get_indexPTO();
	Q_INVOKABLE void save_indexPTO();
	void set_indexPTO(int indexPTO);

	/* Functions used for engine stop time management */
	Q_INVOKABLE int getIndexStopTime();
	Q_INVOKABLE void saveEngineStopTime();
	Q_INVOKABLE int get_engineStopTime();
	int engineStopTime();
	void set_engineStopTime(int stopTime);

	/* Functions used for pre heating management */
	Q_INVOKABLE Pre_heating_settings* getPreHeating();
	Q_INVOKABLE void savePreHeatingSettings();
	Q_INVOKABLE bool getPreHeatingDate(int index);
	Q_INVOKABLE void setPreHeatingDate(int index, bool state);

	/* Functions used for aux flow limit LOCK state of Mechanic Mode management */
	Q_INVOKABLE int get_indexLockState();
	Q_INVOKABLE void saveLockSate();
	void set_indexLockState(int indexLockState);

	/* Functions used for date time mode management */
	Q_INVOKABLE int getDateTimeMode();
	Q_INVOKABLE void saveDateTimeMode();
	void setDateTimeMode(int dateTimeMode);

	/* Functions used for format hour management */
	Q_INVOKABLE int getFormatHour();
	Q_INVOKABLE void saveFormatHour();
	void setFormatHour(int formatHour);

	/* Functions used for daylight saving time management */
	Q_INVOKABLE int getDaylightSavingTime();
	Q_INVOKABLE void saveDaylightSavingTime();
	void setDaylightSavingTime(int daylightSavingTime);

	/* Functions used for sound setting saving time management */
	Q_INVOKABLE int getSoundSetting();
	Q_INVOKABLE void saveSoundSetting();
	void setSoundSetting(int soundSetting);

	/* Functions used for time zone management */
	Q_INVOKABLE QString getTimeZone();
	Q_INVOKABLE int getTimeZoneIndex();
	Q_INVOKABLE void saveTimeZone();
	Q_INVOKABLE void setTimeZoneIndex(int index);
	void setTimeZone(const QString timeZone);

	/* Functions used for brightness settings */
	Q_INVOKABLE int getDayBrightness();
	Q_INVOKABLE int getNightBrightness();
	Q_INVOKABLE void setDayBrightness(int dayBrightness);
	Q_INVOKABLE void setNightBrightness(int nightBrightness);
	Q_INVOKABLE void saveBrightness();

	/* Functions used for maintenance interval management */
	Q_INVOKABLE int get_interval_hydraulicOil();
	Q_INVOKABLE void save_interval_hydraulicOil();
	void set_interval_hydraulicOil(int interval_hydraulicOil);

	Q_INVOKABLE int get_interval_hydraulicOilRetFilter();
	Q_INVOKABLE void save_interval_hydraulicOilRetFilter();
	void set_interval_hydraulicOilRetFilter(int interval_hydraulicOilRetFilter);

	Q_INVOKABLE int get_interval_hydraulicOilRetLineFilter();
	Q_INVOKABLE void save_interval_hydraulicOilRetLineFilter();
	void set_interval_hydraulicOilRetLineFilter(int interval_hydraulicOilRetLineFilter);

	Q_INVOKABLE int get_interval_travelReductionOil();
	Q_INVOKABLE void save_interval_travelReductionOil();
	void set_interval_travelReductionOil(int interval_travelReductionOil);


	/* Functions used for maintenance history management */
	Q_INVOKABLE MaintenanceHistory* get_maintenance_history(int index_mainHist);
	Q_INVOKABLE void save_maintenance_history();

	/* Functions used for mechanic usage history management */
	Q_INVOKABLE MechanicHistory* get_mechanic_history(int index_mecHist);
	Q_INVOKABLE void save_mechanic_history();
	Q_INVOKABLE int get_mecHist_nbMax();
	Q_INVOKABLE void save_mecHist_nbMax();
	void set_mecHist_nbMax(int mecHist_nbMax);
	Q_INVOKABLE void set_mechanic_history(int index_mecHist, QString date, QString time, int hourmeter);

	/* Functions used for Operational Time Measurement */
	Q_INVOKABLE QString getOpTimeResetDate();
	Q_INVOKABLE QString getOpTimeResetTime();
	Q_INVOKABLE double getOpTimeResetHourmeter();
	Q_INVOKABLE void setOpTimeResetDate(QString resetDate);
	Q_INVOKABLE void setOpTimeResetTime(QString resetTime);
	Q_INVOKABLE void setOpTimeResetHourmeter(double hourmeterAtReset);
	Q_INVOKABLE void saveOpTimeResetEvent();

	/* Functions used for temperature unit */
	Q_INVOKABLE int getTempUnitIsCelsius();
	Q_INVOKABLE void saveTemperatureUnit();
	void setTemperatureUnitCelsius(int temperatureUnitisCelsius);

	/* Functions used for RCS settings */
	Q_INVOKABLE int getRCSForward();
	Q_INVOKABLE int getRCSBackward();
	Q_INVOKABLE void setRCSForward(int rcsForward);
	Q_INVOKABLE void setRCSBackward(int rcsBackward);
	Q_INVOKABLE void saveRCSSettings();

	/* Functions used for Immobilizer settings */
	Q_INVOKABLE int get_isImmobActive();
	Q_INVOKABLE int get_ImmobActivationTime();
	Q_INVOKABLE void set_immobActive(int isActive);
	Q_INVOKABLE void set_immobActivationTime(int minutes);
	Q_INVOKABLE void saveImmobActive();
	Q_INVOKABLE void saveImmobActivationTime();

	/* Functions used for Supress-Buzzer-DTC */
	Q_INVOKABLE int getSupressBuzzerDTC();
	Q_INVOKABLE void saveSupressBuzzerDTC();
	void setSupressBuzzerDTC(int);

	/* Functions used for Supress-Buzzer-FlashingLights */
	Q_INVOKABLE int getSupressBuzzerFlashingLight();
	Q_INVOKABLE void saveSupressBuzzerFlashingLight();
	void setSupressBuzzerFlashingLight(int);

	/* Functions used for speed unit */
	Q_INVOKABLE int getSpeedUnitIsKmh();
	Q_INVOKABLE void saveSpeedUnit();
	void setSpeedUnitIsKmh(int speedUnitIsKmh);

	/* Functions used for pressure unit */
	Q_INVOKABLE int getPressureUnit();
	Q_INVOKABLE void savePressureUnit();
	void setPressureUnit(int pressureUnit);

	/* Functions used for volume unit */
	Q_INVOKABLE int getVolumeUnit();
	Q_INVOKABLE void saveVolumeUnit();
	void setVolumeUnit(int volumeUnit);

public slots:


signals:
	void engineStopTimeChanged(int stopTime);
	void indexPTOChanged(int indexPTO);

	void indexLockStateChanged(int indexLockState);

	void dateChanged(QString date);
	void timeChanged(QString time);
	void timePeriodFormatChanged(bool timePeriodFormat);

	void dateTimeModeChanged(int dateTimeMode);
	void formatHourChanged(int formatHour);
	void daylightSavingTimeChanged(int daylightSavingTime);
	void timeZoneChanged(QString timeZone);
	void soundSettingChanged(int soundSetting);

	void interval_hydraulicOilChanged(int interval_hydraulicOil);
	void interval_hydraulicOilRetFilterChanged(int interval_hydraulicOilRetFilter);
	void interval_hydraulicOilRetLineFilterChanged(int interval_hydraulicOilRetLineFilter);
	void interval_travelReductionOilChanged(int interval_travelReductionOil);

	void mecHist_nbMaxChanged(int mecHist_nbMax);

	void tempUnitChanged(int tempIsCelsius);

	void rcsForwardChanged(int rcsValue);
	void rcsBackwardChanged(int rcsValue);

	void immobActiveChanged(int isImmobActive);
	void immobActivationTimeChanged(int ImmobActivationTime);

	void speedUnitChanged(int speedIsKmh);
	void pressureUnitChanged(int pressure);
	void volumeUnitChanged(int volume);

	void supressBuzzerDtcChanged(int supressBuzzerDTC);
	void supressBuzzerFlashingLightChanged(int supressBuzzerFlashingLight);

private:
	/*!
	 * The first configuration file that init() tries to initialize m_document
	 * from, and the first file that saveJSON() writes m_document to.
	 */
	QFile m_file;
	/*!
	 * The second configuration file that init() tries to initialize m_document
	 * from, and the second file that saveJSON() writes m_document to.
	 */
	QFile m_backupFile;
	/*!
	 * The last configuration file that init() tries to initialize m_document
	 * from. This file is never written to by saveJSON().
	 */
	QFile m_defaultFile;
	/*!
	 * The in-memory copy of the configuration file.
	 */
	QJsonDocument m_document;

	//languages
	int m_indexLanguage;
	QString m_language;

	//pto settings
	std::array<Flow_limit_acc*, ACC_NB_MAX> m_acc_as;
	int m_indexPTO;

	//engine stop timer
	int m_engineStopTime;
	int m_engineStopTimeIndex;

	//pre heating
	Pre_heating_settings* m_preHeating;

	//aux flow limit lock
	int m_indexLockState;

	//date and time
	QString m_date;
	QString m_time;
	QTime m_currentTime; // aux
	QDate m_currentDate; // aux

	//date and time settings
	int m_dateTimeMode;
	int m_formatHour;
	int m_daylightSavingTime;
	QString m_timeZone;
	int m_timeZoneIndex;

	// Brightness settings
	int m_dayBrightness;
	int m_nightBrightness;

	// maintenance interval
	int m_interval_hydraulicOil;
	int m_interval_hydraulicOilRetFilter;
	int m_interval_hydraulicOilRetLineFilter;
	int m_interval_travelReductionOil;

	// maintenance history
	std::array<MaintenanceHistory*, MAIN_HIST_NB_MAX> m_maintenance_history;

	// mechanic usage history
	int m_mecHist_nbMax;
	std::vector<MechanicHistory*> m_mechanic_history;

	// Operational time measurement
	QString m_OpTimeResetDate;
	QString m_OpTimeResetTime;
	double m_OpTimeResetHourmeter;

	// Temperature unit is celsius (1) or fahrenheit (0)
	int m_tempIsCelsius;

	// RCS values
	int m_rcsForward;
	int m_rcsBackward;

	// Immobilizer
	int m_ImmobActive;
	int m_ImmobActivationTime;

	// Speed unit is Kmh (1) or mph (0)
	int m_speedIsKmh;

	// Pressure unit is Bar (0) or Mpa (1) or PSI (2)
	int m_pressure;

	// Volume unit is L (0) or gal(US) (1) or gal(UK) (2)
	int m_volume;

	// Sound setting
	int m_soundSetting;

	int m_supressBuzzerDTC;
	int m_supressBuzzerFlashingLight;

	/*!
	 * Reads a JSON document from the given \a file.
	 *
	 * \return a non-null QJsonDocument if reading and parsing the file
	 * succeeds, or a null QJsonDocument if it fails.
	 */
	static QJsonDocument readDocument(QFile &file);
	/*!
	 * Writes m_document to the given \a file.
	 *
	 * \return \c true if writing to the file succeeds, or \c false if it fails.
	 */
	bool writeDocument(QFile &file);
};


#endif // DATAMANAGER_H

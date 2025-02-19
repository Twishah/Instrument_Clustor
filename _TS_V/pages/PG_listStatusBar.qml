import QtQuick 2.0
import MyQmlModule 1.0
import QtGraphicalEffects 1.0
import QtQuick.Controls 2.4
import "../components"

Flickable {
	id: listStatusID

	width: parent.width
	height: parent.height
	anchors.topMargin: backEnd.currentConfig.headerHeight
	contentWidth: listStatusID.width
	contentHeight: heightItem * lengthItems // calculate container height to fit all items

	boundsBehavior: Flickable.StopAtBounds

	Keys.forwardTo: controller

	property int currentIndex: 0
	property int selectedIndex: 0
	property int lengthItems: 1
	property int heightItem: 71
	property int maxLengthItems: 17

	property bool isCelsius: dm.tempUnitIsCelsius
	property bool isKmh: dm.speedUnitIsKmh
	property int pressureUnit: dm.pressureUnit
	property int volumeUnit: dm.volumeUnit


	// CAN values for Maintenance Mode
	property double hydraulicOilMCU: 0 // TODO: link to dataengine values
	property double hydraulicOilRetFilterMCU: 0 // TODO: link to dataengine values
	property double hydraulicOilRetLineFilterMCU: 0 // TODO: link to dataengine values
	property double travelReductionOilMCU: 0 // TODO: link to dataengine values
	property double hydraulicOilMCUReset: 0
	property double hydraulicOilRetFilterMCUReset: 0
	property double hydraulicOilRetLineFilterMCUReset: 0
	property double travelReductionOilMCUReset: 0
	property double interval_hydraulicOilMCUNew: dm.interval_hydraulicOil
	property double interval_hydraulicOilRetFilterMCUNew: dm.interval_hydraulicOilRetFilter
	property double interval_hydraulicOilRetLineFilterMCUNew: dm.interval_hydraulicOilRetLineFilter
	property double interval_travelReductionOilMCUNew: dm.interval_travelReductionOil

	// CAN values for Monitor Mode 2 versions
	property int hydraulicOilTemperature: dataEngine.hydraulicTemperature.value
	property bool outRangeHydraulicTemp: false

	// CAN values only for Monitor Mode V8e
	property int accelPedalV8e: _CanHandler.AccelPedalPos
	property bool outRangeAccelPedalV8e: false
	property int brakePedalV8e: _CanHandler.BrakePedalPos
	property bool outRangeBrakePedalV8e: false
	property double batteryVoltage12VMCU: dataEngine.lowSideVoltage.value
	property bool outRangeBattery12V: false
	property double batteryVoltage48VBMS: dataEngine.highSideVoltage.value
	property bool outRangeBattery48V: false
	property int batteryOn: dataEngine.ind_HVBatteryOn.value
	property bool outRangeBatteryOn: false
	property int ptoSpeed: dataEngine.zFETC13ePTOActualSpeedFeedback.value
	property bool outRangePtoSpeed: false
	property int fanSpeedMCU: dataEngine.coolingFanSpeed.value
	property bool outRangeFanSpeed: false

	// CAN values only for Monitor Mode V7
	property int accelPedalV7: _CanHandler.dmdDrvPedl
	property bool outRangeAccelPedalV7: false
	property int brakePedalV7: _CanHandler.dmdInchPedl
	property bool outRangeBrakePedalV7: false
	property int coolantTemperatureMCU: dataEngine.coolingTemperature.value
	property bool outRangeCoolantTemp: false
	property double batteryVoltage: dataEngine.eCU_Batt.value
	property bool outRangeBatteryVoltage: false
	property int starterOutput: _CanHandler.startRelay
	property bool outRangeStarterOutput: false
	property double fuelPressureRail: _CanHandler.railP
	property bool outRangeFuelPressureRail: false
	property int engineSpeed: _CanHandler.engSpeed
	property bool outRangeEngineSpeed: false
	property double fuelPerHour: _CanHandler.fuelPerHour
	property bool outRangeFuelPerHour: false
	property double druckMA: dataEngine.pMa.value
	property bool outRangeDruckMA: false
	property double druckMB: dataEngine.pMb.value
	property bool outRangeDruckMB: false
	property int actualEngineLoad: _CanHandler.engPercentLoadAtCurrentSpeed
	property bool outRangeActualEngineLoad:  false
	property int creepmodeGesch: _CanHandler.dmdCrpPoti
	property bool outRangeCreepmodeGesch: false
	property int creepmodeDreh: _CanHandler.dmdHndThr
	property bool outRangeCreepmodeDreh: false
	property int sootLevelState: dataEngine.dPFSootState.value
	property int sootLevelValue: dataEngine.dPFSootLoad.value
	property int ashLevelState: dataEngine.dPFAshloadState.value
	property int ashLevelValue: dataEngine.dPFAshLoad.value

	property bool outRangeDailyOpHours: false
	property bool outRangeHourmeter: false
	property bool outRangeAutoIdleHours: false
	property bool outRangeOperatingHoursAcc1: false
	property bool outRangeOperatingHoursAcc2: false
	property bool outRangeOpHoursMission: false

	// Var for maintenance interval verification
	property double percent_hydraulicOil: calculateElapsedTimePercentage(hydraulicOilMCU, containerMaintenance.interval_hydraulicOilMCU)
	property double percent_hydraulicOilRetFilter: calculateElapsedTimePercentage(hydraulicOilRetFilterMCU, containerMaintenance.interval_hydraulicOilRetFilterMCU)
	property double percent_hydraulicOilRetLineFilter: calculateElapsedTimePercentage(hydraulicOilRetLineFilterMCU, containerMaintenance.interval_hydraulicOilRetLineFilterMCU)
	property double percent_travelReductionOil: calculateElapsedTimePercentage(travelReductionOilMCU, containerMaintenance.interval_travelReductionOilMCU)

	property var maintenanceReach: [false, false, false, false]

	// WHEN CAN VALUE IS RECEIVED IN THE PROPER PROPERTY ABOVE HERE
	onPercent_hydraulicOilChanged: {
		verifyIndicatorMaintenance(0, percent_hydraulicOil)
		pg_largeList.verifyMaintenanceElapsedTime()
	}

	onPercent_hydraulicOilRetFilterChanged: {
		verifyIndicatorMaintenance(1, percent_hydraulicOilRetFilter)
		pg_largeList.verifyMaintenanceElapsedTime()
	}

	onPercent_hydraulicOilRetLineFilterChanged: {
		verifyIndicatorMaintenance(2, percent_hydraulicOilRetLineFilter)
		pg_largeList.verifyMaintenanceElapsedTime()
	}

	onPercent_travelReductionOilChanged: {
		verifyIndicatorMaintenance(3, percent_travelReductionOil)
		pg_largeList.verifyMaintenanceElapsedTime()
	}

	//Timer for checking min/max values
	Timer {
	   id: minMaxTimer
	   interval: 1000
	   running: true
	   repeat: true
	   triggeredOnStart: true
	   onTriggered: {

		   // check the batteryVoltage12VMCU min/max : 0-15V
		   if((batteryVoltage12VMCU >= 0) && (batteryVoltage12VMCU <= 15))
		   {
			   outRangeBattery12V = false // in range
		   }
		   else
		   {
			   outRangeBattery12V = true // out of range
		   }

		   // check the batteryVoltage48VBMS min/max : 0-100V
		   if((batteryVoltage48VBMS >= 0) && (batteryVoltage48VBMS <= 100))
		   {
			   outRangeBattery48V = false // in range
		   }
		   else
		   {
			   outRangeBattery48V = true // out of range
		   }

		   // check the ptoSpeed min/max : 0-5060rpm
		   if((ptoSpeed >= 0) && (ptoSpeed <= 5060))
		   {
			   outRangePtoSpeed = false // in range
		   }
		   else
		   {
			   outRangePtoSpeed = true // out of range
		   }

		   // check the coolantTemperatureMCU min/max : -40-210°C
		   if((coolantTemperatureMCU >= -40) && (coolantTemperatureMCU <= 210))
		   {
			   outRangeCoolantTemp = false // in range
		   }
		   else
		   {
			   outRangeCoolantTemp = true // out of range
		   }

		   // check the hydraulicOilTemperature min/max : -40-210°C
		   if((hydraulicOilTemperature >= -40) && (hydraulicOilTemperature <= 210))
		   {
			   outRangeHydraulicTemp = false // in range
		   }
		   else
		   {
			   outRangeHydraulicTemp = true // out of range
		   }

		   // check the fanSpeedMCU min/max : 0-100%
		   if((fanSpeedMCU >= 0) && (fanSpeedMCU <= 100))
		   {
			   outRangeFanSpeed = false // in range
		   }
		   else
		   {
			   outRangeFanSpeed = true // out of range
		   }

		   // check the accelPedal min/max : 0-100%
		   if((accelPedalV8e >= 0) && (accelPedalV8e <= 100))
		   {
			   outRangeAccelPedalV8e = false // in range
		   }
		   else
		   {
			   outRangeAccelPedalV8e = true // out of range
		   }

		   // check the accelPedal min/max : 0-100%
		   if((accelPedalV7 >= 0) && (accelPedalV7 <= 100))
		   {
			   outRangeAccelPedalV7 = false // in range
		   }
		   else
		   {
			   outRangeAccelPedalV7 = true // out of range
		   }

		   // check the brakePedal min/max : 0-100%
		   if((brakePedalV8e >= 0) && (brakePedalV8e <= 100))
		   {
			   outRangeBrakePedalV8e = false // in range
		   }
		   else
		   {
			   outRangeBrakePedalV8e = true // out of range
		   }

		   // check the brakePedal min/max : 0-100%
		   if((brakePedalV7 >= 0) && (brakePedalV7 <= 100))
		   {
			   outRangeBrakePedalV7 = false // in range
		   }
		   else
		   {
			   outRangeBrakePedalV7 = true // out of range
		   }

		   // check the dailyOperationsHours min/max : 0-maxHourMeter
		   if((dataEngine.opHours_DailyWorkload.value >= 0.0) && (dataEngine.opHours_DailyWorkload.value.toFixed(1) <= 24.0))
		   {
			   outRangeDailyOpHours = false // in range
		   }
		   else
		   {
			   outRangeDailyOpHours = true // out of range
		   }

		   // check the hourMeter min/max : 0-9999.9h
		   if((dataEngine.opHours_Total.value >= 0) && (dataEngine.opHours_Total.value.toFixed(1) <= maxHourMeter))
		   {
			   outRangeHourmeter = false // in range
		   }
		   else
		   {
			   outRangeHourmeter = true // out of range
		   }
		   // check the autoIdleHours min/max : 0.1-9999.9h
		   if((dataEngine.opHours_EngineIdleTime.value >= 0) && (dataEngine.opHours_EngineIdleTime.value.toFixed(1) <= maxHourMeter))
		   {

			   outRangeAutoIdleHours = false // in range
		   }
		   else
		   {
			   outRangeAutoIdleHours = true // out of range
		   }

		   if( (dataEngine.opHours_ACC1.value >= 0) && (dataEngine.opHours_ACC1.value.toFixed(1) <= maxHourMeter) )
		   {
			   outRangeOperatingHoursAcc1 = false // in range
		   }
		   else
		   {
			   outRangeOperatingHoursAcc1 = true // out of range
		   }

		   if( (dataEngine.opHours_ACC2.value >= 0) && (dataEngine.opHours_ACC2.value.toFixed(1) <= maxHourMeter) )
		   {
			   outRangeOperatingHoursAcc2 = false // in range
		   }
		   else
		   {
			   outRangeOperatingHoursAcc2 = true // out of range
		   }

		   if( (dataEngine.opHours_Mission.value >= 0) && (dataEngine.opHours_Mission.value.toFixed(1) <= maxHourMeter) )
		   {
			   outRangeOpHoursMission = false // in range
		   }
		   else
		   {
			   outRangeOpHoursMission = true // out of range
		   }

		   // check the batteryOn min/max : 0-3
		   if((batteryOn >= 0) && (batteryOn <= 3))
		   {
			   outRangeBatteryOn = false // in range
		   }
		   else
		   {
			   outRangeBatteryOn = true // out of range
		   }

		   // check the batteryVoltage min/max : 0-160V
		   if((batteryVoltage >= 0) && (batteryVoltage <= 160))
		   {
			   outRangeBatteryVoltage = false // in range
		   }
		   else
		   {
			   outRangeBatteryVoltage = true // out of range
		   }

		   // check the starterOutput min/max : 0-1
		   if((starterOutput === 0) || (starterOutput === 1))
		   {
			   outRangeStarterOutput = false // in range
		   }
		   else
		   {
			   outRangeStarterOutput = true // out of range
		   }

		   // check the fuelPressureRail min/max : 0-251 MPa
		   if((fuelPressureRail >= 0) && (fuelPressureRail <= 251))
		   {
			   outRangeFuelPressureRail = false // in range
		   }
		   else
		   {
			   outRangeFuelPressureRail = true // out of range
		   }

		   // check the engineSpeed min/max : 0-8031 rpm
		   if((engineSpeed >= 0) && (engineSpeed <= 8031))
		   {
			   outRangeEngineSpeed = false // in range
		   }
		   else
		   {
			   outRangeEngineSpeed = true // out of range
		   }

		   // check the fuelPerHour min/max : 0-3212.75 l/h
		   if((fuelPerHour >= 0) && (fuelPerHour <= 3212.75))
		   {
			   outRangeFuelPerHour = false // in range
		   }
		   else
		   {
			   outRangeFuelPerHour = true // out of range
		   }

		   // check the actualEngineLoad min/max : 0-125%
		   if((actualEngineLoad >= 0) && (actualEngineLoad <= 125))
		   {
			   outRangeActualEngineLoad = false // in range
		   }
		   else
		   {
			   outRangeActualEngineLoad = true // out of range
		   }

		   // check the creepmodeGesch min/max : 0-100%
		   if((creepmodeGesch >= 0) && (creepmodeGesch <= 100))
		   {
			   outRangeCreepmodeGesch = false // in range
		   }
		   else
		   {
			   outRangeCreepmodeGesch = true // out of range
		   }

		   // check the creepmodeDreh min/max : 0-100%
		   if((creepmodeDreh >= 0) && (creepmodeDreh <= 100))
		   {
			   outRangeCreepmodeDreh = false // in range
		   }
		   else
		   {
			   outRangeCreepmodeDreh = true // out of range
		   }
	   }
	}

	Timer {
		id: triggerMaintenanceDTC
		interval: 4500
		running: true
		repeat: true
		onTriggered: {
			triggerMaintenanceDTC.interval = 1000;
			var p_hydraulicOil = calculateElapsedTimePercentage(hydraulicOilMCU, containerMaintenance.interval_hydraulicOilMCU);
			var p_hydraulicOilRetFilter = calculateElapsedTimePercentage(hydraulicOilRetFilterMCU, containerMaintenance.interval_hydraulicOilRetFilterMCU)
			var p_hydraulicOilRetLineFilter = calculateElapsedTimePercentage(hydraulicOilRetLineFilterMCU, containerMaintenance.interval_hydraulicOilRetLineFilterMCU)
			var p_travelReductionOil = calculateElapsedTimePercentage(travelReductionOilMCU, containerMaintenance.interval_travelReductionOilMCU)
			if (!controller.isMechanicMode1 && !controller.isMechanicMode2 && !startupInfo.isManualStartMode() && pg_home.autoControlDone === true) {
				if (p_hydraulicOil >= 100 || p_hydraulicOilRetFilter >= 100 || p_hydraulicOilRetLineFilter >= 100 || p_travelReductionOil >= 100 ) {
						errorManager.addError("MAINTENANCE", dataEngine.opHours_Total.value.toFixed(3));
				}
			}
		}
	}

	function calculateElapsedTimePercentage(value, interval) {
		var percent = 0.0
		if (interval > 0) {
			percent = 100.0 * value / interval
			if (percent > 100.0) {
				percent = 100.0
			}
		}
		else {
			if (value > 0) {
				percent = 100.0
			}
			else {
				percent = 0.0
			}
		}
		return percent
	}

	function verifyIndicatorMaintenance(ind, percent) {
		var currentIconPict = repMaintenance.itemAt(ind).iconPict
		var resultIconPict = ""

		maintenanceReach[ind] = false;
		if (percent >= 100.0) {
			if (currentIconPict !== containerMaintenance.iconPictRed[ind]) {
				resultIconPict = containerMaintenance.iconPictRed[ind]
				repMaintenance.itemAt(ind).iconPict = resultIconPict
				maintenanceReach[ind] = true;
			}
		}
		else if (percent >= 90.0) {
			if (currentIconPict !== containerMaintenance.iconPictOrange[ind]) {
				resultIconPict = containerMaintenance.iconPictOrange[ind]
				repMaintenance.itemAt(ind).iconPict = resultIconPict
			}
		}
		else {
			if (currentIconPict !== containerMaintenance.iconPictWhite[ind]) {
				resultIconPict = containerMaintenance.iconPictWhite[ind]
				repMaintenance.itemAt(ind).iconPict = resultIconPict
			}
		}
	}

	// To reset the indexes everytime that we open this page
	function resetIndexes() {
		listStatusID.currentIndex = 0
		listStatusID.selectedIndex = 0
		if (listStatusID.currentIndex > listStatusID.lengthItems) {
			listStatusID.currentIndex = listStatusID.lengthItems
		}
		contentY = 0
	}

	// To enter into the list of Vehicle Settings
	function selectVehicleSettingsList() {
		listStatusID.lengthItems = 3
		listStatusID.resetIndexes()
	}

	// To enter into the list of immobilizer settings
	function selectImmobilizerSettingsList() {
		listStatusID.lengthItems = 5
		listStatusID.resetIndexes()
	}

	function selectFilterRegeneration() {
		listStatusID.lengthItems = containerFileterRegeneration.nbIteams
		listStatusID.resetIndexes()
	}

	// To enter into the list of Monitor Mode
	function selectMonitorModeList() {
		listStatusID.lengthItems = containerMonitor.nbIteams;
		//listStatusID.resetIndexes()
	}

	// To enter into the list of Date and Time Settings
	function selectDateTimeSettingsList() {
		listStatusID.lengthItems = containerDateTimeSet.nbIteams
		listStatusID.resetIndexes()
	}

	function selectBrightnessModeList()
	{
		listStatusID.lengthItems = containerBrightnessSet.nbIteams
	}

	// To enter into the list of Maintenance Mode
	function selectMaintenanceList() {
		listStatusID.lengthItems = containerMaintenance.nbIteams
		listStatusID.resetIndexes()

		// To establish the initial value according to the elapse time of Maintenance
		for (var i=0; i<4; i++) {
			var percentValues = [percent_hydraulicOil, percent_hydraulicOilRetFilter, percent_hydraulicOilRetLineFilter, percent_travelReductionOil]
			verifyIndicatorMaintenance(i, percentValues[i])
		}
	}

	function selectUnitSettingsList() {
		listStatusID.lengthItems = containerUnitSet.nbIteams
		listStatusID.resetIndexes()
	}

	// Diagnostic Mode : MCU list
	function selectMCUList() {
		listStatusID.lengthItems = 10 ; //containerMCU.nbIteams
		listStatusID.resetIndexes()
	}

	// To reset the parameter selected in Maintenance reset
	function selectResetMaintenanceParameter() {
		if (currentIndex === 0) {
			listStatusID.hydraulicOilMCUReset = 1
		}
		else if (currentIndex === 1) {
			listStatusID.hydraulicOilRetFilterMCUReset = 1
		}
		else if (currentIndex === 2) {
			listStatusID.hydraulicOilRetLineFilterMCUReset = 1
		}
		else if (currentIndex === 3) {
			listStatusID.travelReductionOilMCUReset = 1
		}
	}

	function saveIntervalValueValidated(interval) {
		//var percentNew = 0.0
		if (currentIndex === 0) {
			listStatusID.interval_hydraulicOilMCUNew = interval
			//percentNew = calculateElapsedTimePercentage(hydraulicOilMCU, interval)
		}
		else if (currentIndex === 1) {
			listStatusID.interval_hydraulicOilRetFilterMCUNew = interval
			//percentNew = calculateElapsedTimePercentage(hydraulicOilRetFilterMCU, interval)
		}
		else if (currentIndex === 2) {
			listStatusID.interval_hydraulicOilRetLineFilterMCUNew = interval
			//percentNew = calculateElapsedTimePercentage(hydraulicOilRetLineFilterMCU, interval)
		}
		else if (currentIndex === 3) {
			listStatusID.interval_travelReductionOilMCUNew = interval
			//percentNew = calculateElapsedTimePercentage(travelReductionOilMCU, interval)
		}
		//verifyIndicatorMaintenance(currentIndex, percentNew)
	}


	// To trasition to VS Auto Engine Stop Timer
	function selectAutoEngineStopTimer() {
		backEnd.setState(MyAppState.VS_1_ENGINE)
		backEnd.setCurrentPage(pg_listIcon)
		pg_listStatusBar.visible = false
		if (isV7)
			pgHeader.titleString = qsTrId("LBL_0026") + translator.emptyString
		else
			pgHeader.titleString = qsTrId("LBL_0289") + translator.emptyString
		pg_listIcon.selectStopTimerModel()
		pg_listIcon.visible = true
		console.log("Auto Engine Stop Timer page selected")
	}

	function selectDateTimeSetting() {
		backEnd.setState(MyAppState.DS_2_DATE_TIME_SET)
		backEnd.setCurrentPage(pg_listIcon)
		pg_listStatusBar.visible = false
		pgHeader.titleString = qsTrId("LBL_0013") + translator.emptyString
		pg_listIcon.selectDateTimeModeModel()
		pg_listIcon.modelSelected.currentIndex = dm.dateTimeMode
		pg_listIcon.visible = true
		console.log("Date and time page selected bis")
	}

	function selectFormatHourSwitching() {
		backEnd.setState(MyAppState.DS_2_DATE_TIME_HOUR)
		backEnd.setCurrentPage(pg_listIcon)
		pg_listStatusBar.visible = false
		pgHeader.titleString = qsTrId("LBL_0019") + translator.emptyString
		pg_listIcon.selectFormatHourModel()
		pg_listIcon.visible = true
		console.log("12/24 hour switching page selected")
	}

	function selectDaylightSavingTime() {
		backEnd.setState(MyAppState.DS_2_DATE_TIME_DAYLIGHT)
		backEnd.setCurrentPage(pg_listIcon)
		pg_listStatusBar.visible = false
		pgHeader.titleString = qsTrId("LBL_0020") + translator.emptyString
		pg_listIcon.selectDaylightModel()
		pg_listIcon.visible = true
		console.log("Daylight saving time page selected")
	}

	function selectDayBrightness() {
		backEnd.setState(MyAppState.DS_2_BRIGHTNESS_DAY)
		backEnd.setCurrentPage(pg_gauge)
		pg_listStatusBar.visible = false
		pgHeader.titleString = qsTrId("LBL_0023") + translator.emptyString
		pg_gauge.selectDayBrightnessModel()
		pg_gauge.visible = true
		console.log("Day brightness setting page selected.")
	}

	function selectNightBrightness() {
		backEnd.setState(MyAppState.DS_2_BRIGHTNESS_NIGHT)
		backEnd.setCurrentPage(pg_gauge)
		pg_listStatusBar.visible = false
		pgHeader.titleString = qsTrId("LBL_0024") + translator.emptyString
		pg_gauge.selectNightBrightnessModel()
		pg_gauge.visible = true
		console.log("Night brightness setting page selected.")
	}

	function selectResetMaintenanceMode() {
		backEnd.setState(MyAppState.MM_2_RESET)
		backEnd.setCurrentPage(pg_listIcon)
		pg_listStatusBar.visible = false
		pgHeader.titleString = qsTrId("LBL_0053") + translator.emptyString
		pg_listIcon.selectResetModel()
		pg_listIcon.visible = true
		console.log("Reset page selected")
	}

	function selectIntervalMaintenanceMode() {
		backEnd.setState(MyAppState.MM_2_INTERVAL_CHANGE)
		backEnd.setCurrentPage(pg_passcode)
		pg_listStatusBar.visible = false
		pgHeader.titleString = qsTrId("LBL_0061") + translator.emptyString
		pg_passcode.calculateCurrentNumbers(containerMaintenance.maintenanceIntervals[currentIndex])
		pg_passcode.visible = true
		console.log("Interval change page selected")
	}

	function selectTemperatureUnit() {
		backEnd.setState(MyAppState.DS_2_UNIT_TEMP)
		backEnd.setCurrentPage(pg_listIcon)
		pg_listStatusBar.visible = false
		pgHeader.titleString = qsTrId("LBL_0022") + translator.emptyString
		pg_listIcon.selectTemperatureUnitModel()
		pg_listIcon.visible = true
		console.log("Temperature Unit page selected")
	}

	function selectSpeedUnit() {
		backEnd.setState(MyAppState.DS_2_UNIT_SPEED)
		backEnd.setCurrentPage(pg_listIcon)
		pg_listStatusBar.visible = false
		pgHeader.titleString = qsTrId("LBL_0285") + translator.emptyString
		pg_listIcon.selectSpeedUnitModel()
		pg_listIcon.visible = true
		console.log("Speed Unit page selected")
	}

	function selectPressureUnit() {
		backEnd.setState(MyAppState.DS_2_UNIT_PRESSURE)
		backEnd.setCurrentPage(pg_listIcon)
		pg_listStatusBar.visible = false
		pgHeader.titleString = qsTrId("LBL_0286") + translator.emptyString
		pg_listIcon.selectPressureUnitModel()
		pg_listIcon.visible = true
		console.log("Pressure Unit page selected")
	}

	function selectVolumeUnit() {
		backEnd.setState(MyAppState.DS_2_UNIT_VOLUME)
		backEnd.setCurrentPage(pg_listIcon)
		pg_listStatusBar.visible = false
		pgHeader.titleString = qsTrId("LBL_0284") + translator.emptyString
		pg_listIcon.selectVolumeUnitModel()
		pg_listIcon.visible = true
		console.log("Volume Unit page selected")
	}

	function selectImmobilizerOnOff() {
//		console.log("Immoblizer On Off")
		backEnd.setState(MyAppState.IMMOBILIZER_ACTIVATION)
		backEnd.setCurrentPage(pg_immobilizerActivation)
		pg_listStatusBar.visible = false
		pgHeader.titleString = qsTrId("LBL_0339") + translator.emptyString // LBL_0339 == Immobilizer on/off
		pg_immobilizerActivation.visible = true
	}

	function selectImmobilizerTimeToActivate() {
		console.log("Immoblizer Time to activate")
		backEnd.setState(MyAppState.TIME_TO_ACTIVATE)

		if (0 === 1) {
			backEnd.setCurrentPage(pg_pinCode)
			pg_listStatusBar.visible = false
			pgHeader.titleString = qsTrId("LBL_0340") + translator.emptyString // LBL_0340 == Time to activation
			pg_pinCode.visible = true
			pg_pinCode.currentInfoMsg = qsTrId("LBL_0347") + translator.emptyString // "Current owner PIN"
		}
		else {
			backEnd.setCurrentPage(pg_immoblizerTimeValidation)
			pg_listStatusBar.visible = false
			pgHeader.titleString = qsTrId("LBL_0340") + translator.emptyString // LBL_0340 == Time to activation
			pg_immoblizerTimeValidation.visible = true
		}
	}

	function selectImmobilizerTransPin() {
		console.log("Change immobilizer transporter pin")
		backEnd.setState(MyAppState.ENTER_TRANS_PIN)
		backEnd.setCurrentPage(pg_pinCode)
		pg_listStatusBar.visible = false
		pgHeader.titleString = qsTrId("LBL_0380") + translator.emptyString
		pg_pinCode.visible = true
		pg_pinCode.currentInfoMsg = qsTrId("LBL_0347") + translator.emptyString
	}

	function selectImmobilizerDriverPin() {
		console.log("Change immobilizer driver pin")
		backEnd.setState(MyAppState.ENTER_DRIVER_PIN)
		backEnd.setCurrentPage(pg_pinCode)
		pg_listStatusBar.visible = false
		pgHeader.titleString = qsTrId("LBL_0382") + translator.emptyString
		pg_pinCode.visible = true
		pg_pinCode.currentInfoMsg = qsTrId("LBL_0347") + translator.emptyString
	}

	function selectImmobilizerOwnerPin() {
		console.log("Change immobilizer owner pin")
		backEnd.setState(MyAppState.ENTER_OWNER_PIN)
		backEnd.setCurrentPage(pg_pinCode)
		pg_listStatusBar.visible = false
		pgHeader.titleString = qsTrId("LBL_0346") + translator.emptyString
		pg_pinCode.visible = true
		pg_pinCode.currentInfoMsg = qsTrId("LBL_0347") + translator.emptyString
	}

	function selectSootLevel() {
		console.log("Soot level")
		backEnd.setState(MyAppState.SOOT_LEVEL)
		backEnd.setCurrentPage(pg_sootLevel)
		pg_listStatusBar.visible = false
		pgHeader.titleString = qsTrId("LBL_0308") + translator.emptyString
		pg_sootLevel.visible = true
	}

	function selectAshLevel() {
		console.log("Ash level")
		backEnd.setState(MyAppState.ASH_LEVEL)
		backEnd.setCurrentPage(pg_ashLevel)
		pg_listStatusBar.visible = false
		pgHeader.titleString = qsTrId("LBL_0309") + translator.emptyString
		pg_ashLevel.visible = true
	}

	function selectRCSForward() {
		console.log("RCS Forward settings")
		backEnd.setState(MyAppState.RCS_FORWARD)
		backEnd.setCurrentPage(pg_rcsForward)
		pg_listStatusBar.visible = false
		pgHeader.titleString = qsTrId("LBL_0287") + translator.emptyString
		pg_rcsForward.visible = true
	}

	function selectRCSBackward() {
		console.log("RCS Backward settings")
		backEnd.setState(MyAppState.RCS_BACKWARD)
		backEnd.setCurrentPage(pg_rcsBackward)
		pg_listStatusBar.visible = false
		pgHeader.titleString = qsTrId("LBL_0288") + translator.emptyString
		pg_rcsBackward.visible = true
	}
	function menuPressed()
	{
		if (startupInfo.isManualStartMode()) {
			pg_home2.restartTimeoutTimer()
		}

		if ((backEnd.state === MyAppState.DS_1_DATE_TIME) || (backEnd.state === MyAppState.DS_1_BRIGHTNESS) || (backEnd.state === MyAppState.DS_1_UNIT)) {
			backEnd.setState(MyAppState.DISPLAY_SET)
			backEnd.setCurrentPage(pg_largeList)
			pg_listStatusBar.visible = false
			pgHeader.titleString = qsTrId("LBL_0005") + translator.emptyString
			pg_largeList.visible = true
			console.log("Display settings page selected")
		}
		else if (backEnd.state === MyAppState.MM_1_RESET) {
			backEnd.setState(MyAppState.MAINTENANCE)
			backEnd.setCurrentPage(pg_largeList)
			pg_largeList.verifyMaintenanceElapsedTime()
			pg_listStatusBar.visible = false
			pgHeader.titleString = qsTrId("LBL_0057") + translator.emptyString
			pgHeader.visible = true
			pg_largeList.visible = true
			console.log("Maintenance Mode page selected")
		}
		else if (backEnd.state === MyAppState.MM_1_INTERVAL) {
			backEnd.setState(MyAppState.MAINTENANCE)
			backEnd.setCurrentPage(pg_largeList)
			pg_largeList.verifyMaintenanceElapsedTime()
			pg_listStatusBar.visible = false
			pgHeader.titleString = qsTrId("LBL_0057") + translator.emptyString
			pgHeader.visible = true
			pg_largeList.visible = true
			console.log("Maintenance Mode page selected")
		}
		else if(backEnd.state === MyAppState.DM_1_DIAG_MAIN_CONTROL){
			backEnd.setState(MyAppState.DIAGNOSTIC_MODE)
			console.log("Diagnostic Mode page selected")
			backEnd.setCurrentPage(pg_menu)
			pg_listStatusBar.visible = false
			pg_menu.visible = true
			pgHeader.visible = false
			pgHeader.mainMenu = false
			rectList.visible = false
			rectMenu.visible = true
		}
		else {
			// View Menu page
			if (controller.isMechanicMode1) {
				backEnd.setState(MyAppState.MENU_MECA_1)
			}
			else if (controller.isMechanicMode2) {
				backEnd.setState(MyAppState.MENU_MECA_2)
			}
			else {
				backEnd.setState(MyAppState.MENU)
			}
			backEnd.setCurrentPage(pg_menu)
			pg_listStatusBar.visible = false
			pgHeader.visible = false
			pg_menu.visible = true
			rectList.visible = false
			rectMenu.visible = true
		}
		//listStatusID.resetIndexes()
	}

	function upPressed()
	{
		if (startupInfo.isManualStartMode()) {
			pg_home2.restartTimeoutTimer()
		}

		listStatusID.currentIndex = (listStatusID.currentIndex - 1 + listStatusID.lengthItems) % listStatusID.lengthItems
		var itemY = currentIndex * heightItem;
		if (itemY < contentY) {
			contentY = itemY;
		} else if (itemY + heightItem > contentY + height) {
			contentY = itemY + heightItem - height + 2;
		}
	}

	function downPressed()
	{
		if (startupInfo.isManualStartMode()) {
			pg_home2.restartTimeoutTimer()
		}

		listStatusID.currentIndex = (listStatusID.currentIndex + 1) % listStatusID.lengthItems
		var itemY = currentIndex * heightItem;
		if (itemY + heightItem > contentY + height) {
			contentY = itemY + heightItem - height + 2;
		} else if (itemY < contentY) {
			contentY = itemY;
		}
	}

	function enterPressed()
	{
		if (startupInfo.isManualStartMode()) {
			pg_home2.restartTimeoutTimer()
		}

		selectedIndex = currentIndex
		if (backEnd.state === MyAppState.VEHICULE_SET && containerVehicle.isVisible[selectedIndex]) {
			if (selectedIndex === 0) {
				listStatusID.selectRCSForward()
			} else if (selectedIndex === 1){
				listStatusID.selectRCSBackward()
			} else if (selectedIndex === 2){
				listStatusID.selectAutoEngineStopTimer()
			}
		}
		else if (backEnd.state === MyAppState.DS_1_DATE_TIME) {
			if (selectedIndex === 0) {
				listStatusID.selectDateTimeSetting()
			}
			else if (selectedIndex === 1) {
				listStatusID.selectFormatHourSwitching()
			}
			else if (selectedIndex === 2) {
				if (dm.dateTimeMode === 0) {
				   listStatusID.selectDaylightSavingTime()
				}
			}
		}
		else if(backEnd.state === MyAppState.DS_1_BRIGHTNESS)
		{
			if (selectedIndex === 0) {
				listStatusID.selectDayBrightness()
			}
			else if (selectedIndex === 1) {
				listStatusID.selectNightBrightness()
			}
		}
		else if(backEnd.state === MyAppState.DS_1_UNIT){
			if (selectedIndex === 0) {
				listStatusID.selectTemperatureUnit()
			} else if(selectedIndex === 1) {
				listStatusID.selectSpeedUnit()
			} else if(selectedIndex === 2) {
				listStatusID.selectPressureUnit()
			} else if(selectedIndex === 3) {
				listStatusID.selectVolumeUnit()
			}
		}
		else if (backEnd.state === MyAppState.MM_1_RESET) {
			listStatusID.selectResetMaintenanceMode()
		}
		else if (backEnd.state === MyAppState.MM_1_INTERVAL) {
			listStatusID.selectIntervalMaintenanceMode()
		}
		else if (backEnd.state === MyAppState.IMMOBILIZER_SETTINGS && containerImmobilizerSettings.isVisible[selectedIndex]) {
			if (selectedIndex === 0) {
				listStatusID.selectImmobilizerOnOff()
			}
			else if (selectedIndex === 1) {
				listStatusID.selectImmobilizerTimeToActivate()
			}
			else if (selectedIndex === 2) {
				listStatusID.selectImmobilizerTransPin()
			}
			else if (selectedIndex === 3) {
				listStatusID.selectImmobilizerDriverPin()
			}
			else if (selectedIndex === 4) {
				listStatusID.selectImmobilizerOwnerPin()
			}
		} else if(backEnd.state === MyAppState.FILTER_REGENERATION)
		{
			if (selectedIndex === 0) {
				listStatusID.selectSootLevel()
			}
			else if (selectedIndex === 1) {
				listStatusID.selectAshLevel()
			}
		}
	}


	Column  {
		id: containerVehicle
		width: parent.width
		height: parent.height
		visible: backEnd.state === MyAppState.VEHICULE_SET || pg_popUp.lastState === MyAppState.VEHICULE_SET ? true : false

		property int nbIteams: 3

		Rectangle { //designFix
			width: 300
			height: 1
			color: color_gray_bar
		}

		property var iconSources: [
			"qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 55X55/6.100_Ride control forward_WH.png",
			"qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 55X55/6.101 Ride control backward_WH.png",
			isV7 ? "qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 55X55/6.86_Auto engine stop_WH.png" : "qrc:/graphics/VehicleSettings/7.55 Auto stop - white.png"
		]

		property var textTitles: [
			isKmh ? pg_rcsForward.rcsForwardValue + " km/h" : (pg_rcsForward.rcsForwardValue*0.625).toFixed(1) + " mph",
			isKmh ? pg_rcsBackward.rcsBackwardValue + " km/h" : (pg_rcsBackward.rcsBackwardValue*0.625).toFixed(1) + " mph",
			isV7 ? dm.engineStopTime + " min" : dm.engineStopTime + " sec"
		]

		property var isVisible: [
						adjustRCSForwardVisible,
						adjustRCSBackwardVisible,
						adjustAutoEngineStopTimeVisible
		]

		Repeater {
			id: repVehicle
			model: listStatusID.maxLengthItems

			Comp_listItemStatusBarIcon {
				id: listVehicle
				iconPict: index >= containerVehicle.nbIteams ? "" : containerVehicle.iconSources[index]
				titleText: index >= containerVehicle.nbIteams ? "" : containerVehicle.textTitles[index]
				opacity: index >= containerVehicle.nbIteams ? 0 : containerVehicle.isVisible[index] === 1 ? 1 : 0.3
				isCurrent: listStatusID.currentIndex === index ? true : false
				fontSize: 17
			}
		}
	}

	Column  {
		id: containerMonitor
		width: parent.width
		height: parent.height
		visible: backEnd.state === MyAppState.MONITOR || pg_popUp.lastState === MyAppState.MONITOR ? true : false

		property int nbIteams: isV7 ? 17 : 9
		property var iconSources :
			if (isV7) {
				[
				"qrc:/graphics/MonitorMode/7.56 Battery voltage 12V - white.png", // Battery voltage 12V
				"qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 55X55/6.143_Engine_start_WH.png", // Starter output
				"qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 55X55/6.142_Fuel_ pressure_WH.png", // Fuel pressure rail
				"qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 55X55/6.116_Engine_speed_WH.png", // Engine speed
				"qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 55X55/6.137_Pedal adjustment_WH.png", // Accel pedal
				"qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 55X55/6.144_Fuel_per_hour_WH.png", // Fuel per hour
				"qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 55X55/6.138_Brake_on_WH.png", // Brake pedal
				"qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 55X55/6.140_Hydraulic oil pressure_WH.png", // Druck MA
				"qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 55X55/6.140_Hydraulic oil pressure_WH.png", // Druck MB
				"qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 55X55/6.88_Coolant temperature high low_WH.png", // Coolant temp
				"qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 55X55/6.107 Hydraulic temperatur_WH.png", // Hydraulic Oil temp
				"qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 55X55/6.154_Engine load per cent_WH.png", // Actual Engine load
				"qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 55X55/6.92_Road vehicle, filter_WH.png", // Soot Level
				"qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 55X55/6.120_Soot_WH.png", // Ash level
				"qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 55X55/6.155_Creep speed_WH.png", // Creepmode Geschwindigkeit
				"qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 55X55/6.141_Engine_rotational speed_WH.png", // Creepmode Drehzahl
				"qrc:/graphics/MechanicMode/7.86 Instrument display - white.png" // HMI
				]
			}
			else {
				[
				"qrc:/graphics/MonitorMode/7.56 Battery voltage 12V - white.png", // Batterie Voltage 12V
				"qrc:/graphics/02_Main_Icons PNG/02_Main_Icons PNG 55x55/2.91_Main battery_wh.png", // Batterie Voltage 48V
				"qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 55X55/6.147_Electric_Power_WH.png", // Batterie ON
				"qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 55X55/6.105 Electric Motor_WH.png", // PTO speed
				"qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 55X55/6.137_Pedal adjustment_WH.png", // Driving pedal
				"qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 55X55/6.138_Brake_on_WH.png", // Brake pedal
				"qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 55X55/6.107 Hydraulic temperatur_WH.png", // Hydraulic oil temp
				"qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 55X55/6.47_Ventilation.png", // Fan speed
				"qrc:/graphics/MechanicMode/7.86 Instrument display - white.png" // HMI
				]
			}

		property var textTitles :
			if (isV7) {
				[
				(canError18FEF700 || outRangeBatteryVoltage)? "ERROR" : listStatusID.batteryVoltage.toFixed(1)+"V", // Battery voltage 12V
				(canError18FF1100 || outRangeStarterOutput)? "ERROR" : listStatusID.starterOutput === 1 ? "ON" : "OFF", // Starter output
				(canError18FEDB00 || outRangeFuelPressureRail)? "ERROR" : pressureUnit === 0 ? (10*listStatusID.fuelPressureRail).toFixed(1)+"bar" : pressureUnit === 1 ? (listStatusID.fuelPressureRail).toFixed(1)+"MPa" : (145.038*listStatusID.fuelPressureRail).toFixed(1)+"PSI", // Fuel pressure rail
				(canErrorCF00400  || outRangeEngineSpeed)? "ERROR" : listStatusID.engineSpeed+"rpm", // Engine speed
				(canError18FF2403 || outRangeAccelPedalV7)? "ERROR" : listStatusID.accelPedalV7+"%", // Drive pedal
				(canError18FEF200 || outRangeFuelPerHour)? "ERROR" : listStatusID.fuelPerHour.toFixed(1)+"l/h", // Fuel per hour
				(canError18FF2403 || outRangeBrakePedalV7)? "ERROR" : listStatusID.brakePedalV7+"%", // Brake pedal
				(canError18FF2703 || outRangeDruckMB)? "ERROR" : pressureUnit === 0 ? listStatusID.druckMB.toFixed(0)+"bar" : pressureUnit === 1 ? (listStatusID.druckMB/10).toFixed(0)+"MPa" : ((listStatusID.druckMB/10)*14.5).toFixed(0)+"PSI", // Druck MB
				(canError18FF2703 || outRangeDruckMA)? "ERROR" : pressureUnit === 0 ? listStatusID.druckMA.toFixed(0)+"bar" : pressureUnit === 1 ? (listStatusID.druckMA/10).toFixed(0)+"MPa" : ((listStatusID.druckMA/10)*14.5).toFixed(0)+"PSI", // Druck MA
				(canError18FFCE47 || outRangeCoolantTemp) ? "ERROR" : (isCelsius ? listStatusID.coolantTemperatureMCU.toFixed(0) + "°C" : (32 + 1.8*listStatusID.coolantTemperatureMCU).toFixed(0) + "°F"), // Coolant temperature
				(canError18FFCE47 || outRangeHydraulicTemp) ? "ERROR" : (isCelsius ? listStatusID.hydraulicOilTemperature.toFixed(0) + "°C" : (32 + 1.8*listStatusID.hydraulicOilTemperature).toFixed(0) + "°F"), // Hydraulic oil temp
				(canErrorCF003FE  || outRangeActualEngineLoad)? "ERROR" : listStatusID.actualEngineLoad+"%", // Actual engine load
				(sootLevelValue < 0 || sootLevelValue > 250 || sootLevelState === 14 || sootLevelState === 15 || canError18FFCC47) ? "ERROR" : sootLevelValue + "%", // Soot value
				(ashLevelValue < 0 || ashLevelValue > 250 || ashLevelState === 14 || ashLevelState === 15 || canError18FFCC47) ? "ERROR" : ashLevelValue + "%", // Ash value
				(canError18FF2403 || outRangeCreepmodeGesch)? "ERROR" : listStatusID.creepmodeGesch+"%", // Creepmode Geschwindigkeit
				(canError18FF2403 || outRangeCreepmodeDreh)? "ERROR" : listStatusID.creepmodeDreh+"%", // Creepmode Drehzahl
				"S/V : " + root.version.slice(4,24)
				]
			}
			else {
				[
				(canError18F11447 || outRangeBattery12V) ? "ERROR" : listStatusID.batteryVoltage12VMCU.toFixed(1) + "V", // Batterie Voltage 12V
				(canError18F11447 || outRangeBattery48V) ? "ERROR" : listStatusID.batteryVoltage48VBMS.toFixed(1) + "V", // Batterie Voltage 48V
				(canError18FFCB47 || outRangeBatteryOn)? "ERROR" : listStatusID.batteryOn === 1 ? "ON" : "OFF", // Batterie ON
				(canError18FF2B03 || outRangePtoSpeed) ? "ERROR" : listStatusID.ptoSpeed + "rpm", // PTO speed
				(canErrorCFF7147  || outRangeAccelPedalV8e) ? "ERROR" : listStatusID.accelPedalV8e + "%", // Driving pedal
				(canErrorCFF7147  || outRangeBrakePedalV8e) ? "ERROR" : listStatusID.brakePedalV8e + "%", // Brake pedal
				(canError18FFCE47 || outRangeHydraulicTemp) ? "ERROR" : (isCelsius ? listStatusID.hydraulicOilTemperature.toFixed(0) + "°C" : (32 + 1.8*listStatusID.hydraulicOilTemperature).toFixed(0) + "°F"), // Hydraulic oil temp
				(canError18FFCB47 || outRangeFanSpeed) ? "ERROR" : listStatusID.fanSpeedMCU.toFixed(0) + "%", // Fan speed
				"S/V : " + root.version.slice(4,24)
				]
			}

		Rectangle { //designFix
			width: 300
			height: 1
			color: color_gray_bar
		}
		Repeater {
			id: repMonitor
			model: listStatusID.maxLengthItems

			Comp_listItemStatusBarIcon {
				id: listMonitor
				iconPict: index >= containerMonitor.nbIteams ? "" : containerMonitor.iconSources[index]
				titleText: index >= containerMonitor.nbIteams ? "" : containerMonitor.textTitles[index]
				isCurrent: listStatusID.currentIndex === index ? true : false
				isSOH: false
				fontSize: 17
			}
		}
	}

	Column  {
		id: containerDateTimeSet
		width: parent.width
		height: parent.height
		visible: backEnd.state === MyAppState.DS_1_DATE_TIME || pg_popUp.lastState === MyAppState.DS_1_DATE_TIME ? true : false

		property int nbIteams: 3
		property var iconSources : ["qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 55X55/6.165 Automatic date and time setting WH.png",
									"qrc:/graphics/DisplaySettings/7.49 12-24 hour switching - white.png",
									"qrc:/graphics/DisplaySettings/7.50 Daylight saving time setting - white.png" ]

		property var textTitles : [ dm.dateTimeMode === 1 ? qsTrId("LBL_0016") + translator.emptyString : qsTrId("LBL_0360") + translator.emptyString,
									dm.formatHour === 1 ? "12h" : "24h",
									dm.daylightSavingTime === 1 ? "ON" : "OFF" ]

		Rectangle { //designFix
			width: 300
			height: 1
			color: color_gray_bar
		}

		Repeater {
			id: repDateTimeSet
			model: listStatusID.maxLengthItems

			Comp_listItemStatusBarIcon {
				id: listDateTimeSet
				iconPict: index >= containerDateTimeSet.nbIteams ? "" : containerDateTimeSet.iconSources[index]
				titleText: index >= containerDateTimeSet.nbIteams ? "" : containerDateTimeSet.textTitles[index]
				isCurrent: listStatusID.currentIndex === index ? true : false
				fontSize: 17
			}
		}
	}

	Column {
		id: containerMaintenance
		width: parent.width
		height: parent.height
		visible: backEnd.state === MyAppState.MM_1_INTERVAL || backEnd.state === MyAppState.MM_1_RESET || pg_popUp.lastState === MyAppState.MM_1_INTERVAL || pg_popUp.lastState === MyAppState.MM_1_RESET ? true : false

		property int nbIteams: isV7 ? 9 : 6
		property var iconPictWhite: isV7 ? [ "qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 55X55/6.94_Engine lubricating oil_WH.png",
			"qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 55X55/6.93_Engine oil filter_WH.png",
			"qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 55X55/6.91_Engine intake air filter_WH.png",
			"qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 55X55/6.90_Fuel filter_WH.png",
			"qrc:/graphics/MaintenanceMode/7.71 Hydraulic oil - white.png",
			"qrc:/graphics/MaintenanceMode/7.74 Hydraulic oil return filter - white.png",
			"qrc:/graphics/MaintenanceMode/7.74 Hydraulic oil return filter - white.png",
			"qrc:/graphics/MaintenanceMode/7.77 Travel reduction oil - white.png",
			"qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 55X55/6.92_Road vehicle, filter_WH.png"]
			:
			["qrc:/graphics/MaintenanceMode/7.71 Hydraulic oil - white.png",
			"qrc:/graphics/MaintenanceMode/7.74 Hydraulic oil return filter - white.png",
			"qrc:/graphics/MaintenanceMode/7.74 Hydraulic oil return filter - white.png",
			"qrc:/graphics/MaintenanceMode/7.77 Travel reduction oil - white.png",
			"qrc:/graphics/02_Main_Icons PNG/02_Main_Icons PNG 55x55/2.91_Main battery_wh.png",
			"qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 55X55/6.147_Electric_Power_WH.png"]

		property var iconPictOrange: isV7 ? [ "qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 55X55/6.94_Engine lubricating oil_OR.png",
			"qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 55X55/6.93_Engine oil filter_OR.png",
			"qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 55X55/6.91_Engine intake air filter_OR.png",
			"qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 55X55/6.90_Fuel Filter_OR.png",
			"qrc:/graphics/MaintenanceMode/7.72 Hydraulic oil - orange.png",
			"qrc:/graphics/MaintenanceMode/7.75 Hydraulic oil return filter - orange.png",
			"qrc:/graphics/MaintenanceMode/7.75 Hydraulic oil return filter - orange.png",
			"qrc:/graphics/MaintenanceMode/7.78 Travel reduction oil - orange.png",
			"qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 55X55/6.92_Road vehicle, filter_OR.png"]
			:
			["qrc:/graphics/MaintenanceMode/7.72 Hydraulic oil - orange.png",
			"qrc:/graphics/MaintenanceMode/7.75 Hydraulic oil return filter - orange.png",
			"qrc:/graphics/MaintenanceMode/7.75 Hydraulic oil return filter - orange.png",
			"qrc:/graphics/MaintenanceMode/7.78 Travel reduction oil - orange.png",
			"qrc:/graphics/02_Main_Icons PNG/02_Main_Icons PNG 55x55/2.91_Main battery_or.png",
			"qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 55X55/6.147_Electric_Power_OR.png"]

		property var iconPictRed: isV7 ? [ "qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 55X55/6.94_Engine lubricating oil_RD.png",
			"qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 55X55/6.93_Engine oil filter_RD.png",
			"qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 55X55/6.91_Engine intake air filter_RD.png",
			"qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 55X55/6.90_Fuel Filter_RD.png",
			"qrc:/graphics/MaintenanceMode/7.73 Hydraulic oil - red.png",
			"qrc:/graphics/MaintenanceMode/7.76 Hydraulic oil return filter - red.png",
			"qrc:/graphics/MaintenanceMode/7.76 Hydraulic oil return filter - red.png",
			"qrc:/graphics/MaintenanceMode/7.79 Travel reduction oil - red.png",
			"qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 55X55/6.92_Road vehicle, filter_RD.png"]
			:
			["qrc:/graphics/MaintenanceMode/7.73 Hydraulic oil - red.png",
			"qrc:/graphics/MaintenanceMode/7.76 Hydraulic oil return filter - red.png",
			"qrc:/graphics/MaintenanceMode/7.76 Hydraulic oil return filter - red.png",
			"qrc:/graphics/MaintenanceMode/7.79 Travel reduction oil - red.png",
			"qrc:/graphics/02_Main_Icons PNG/02_Main_Icons PNG 55x55/2.91_Main battery_rd.png",
			"qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 55X55/6.147_Electric_Power_RD.png"]

		property int interval_hydraulicOilMCU: dm.interval_hydraulicOil
		property int interval_hydraulicOilRetFilterMCU: dm.interval_hydraulicOilRetFilter
		property int interval_hydraulicOilRetLineFilterMCU: dm.interval_hydraulicOilRetLineFilter
		property int interval_travelReductionOilMCU: dm.interval_travelReductionOil
		property var maintenanceIntervals: [containerMaintenance.interval_hydraulicOilMCU, containerMaintenance.interval_hydraulicOilRetFilterMCU, containerMaintenance.interval_hydraulicOilRetLineFilterMCU, containerMaintenance.interval_travelReductionOilMCU]
		property var maintenanceValues: [listStatusID.hydraulicOilMCU, listStatusID.hydraulicOilRetFilterMCU, listStatusID.hydraulicOilRetLineFilterMCU, listStatusID.travelReductionOilMCU]

		Rectangle { //designFix
			width: 300
			height: 1
			color: color_gray_bar
		}

		Repeater {
			id: repMaintenance
			model: listStatusID.maxLengthItems

			Comp_listItemStatusBarIcon {
				id: listMaintenance
				iconPict: index >= containerMaintenance.nbIteams ? "" : containerMaintenance.iconPictWhite[index]
				titleText: index >= containerMaintenance.nbIteams ? "" : parseInt(containerMaintenance.maintenanceValues[index]) + "/" + parseInt(containerMaintenance.maintenanceIntervals[index])
				isCurrent:  listStatusID.currentIndex === index ? true : false
				fontSize: 17
				textVisible: canErrorHydraulicOilMaintenance ? blinkingPictoIsVisible : true
			}
		}
	}

	Column {
		id: containerBrightnessSet
		width: parent.width
		height: parent.height
		visible: backEnd.state === MyAppState.DS_1_BRIGHTNESS || pg_popUp.lastState === MyAppState.DS_1_BRIGHTNESS ? true : false

		property int nbIteams: 2
		property var iconSources : ["qrc:/graphics/DisplaySettings/7.53 Day brightness setting - white.png",
									"qrc:/graphics/DisplaySettings/7.54 Night brightness setting - white.png"]
		property var textTitles : [ pg_gauge.backLightDayPercentage + "%",
									pg_gauge.backLightNightPercentage + "%" ]

		Rectangle { //designFix
			width: 300
			height: 1
			color: color_gray_bar
		}

		Repeater {
			id: repBrightnessSet
			model: listStatusID.maxLengthItems

			Comp_listItemStatusBarIcon {
				id: listBrightnessSet
				iconPict: index >= containerBrightnessSet.nbIteams ? "" : containerBrightnessSet.iconSources[index]
				titleText: index >= containerBrightnessSet.nbIteams ? "" : containerBrightnessSet.textTitles[index]
				isCurrent:  listStatusID.currentIndex === index ? true : false
				fontSize: 20
			}
		}
	}

	Column {
		id: containerUnitSet
		width: parent.width
		height: parent.height
		visible: backEnd.state === MyAppState.DS_1_UNIT || pg_popUp.lastState === MyAppState.DS_1_UNIT ? true : false

		property int nbIteams: 4
		property var sources: ["qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 25x25/6.74_Temperature_WH.png",
							   "qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 25x25/6.152_Speedmeter_WH.png",
							   "qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 25x25/6.76_Pressure_WH.png",
							   "qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 25x25/6.73_Volume_WH.png"]
		property var titleText : [isCelsius === true ? "°C" : "°F",
								  isKmh === true ? "Km/h" : "mph",
								  pressureUnit === 0 ? "Bar" : pressureUnit===1 ? "MPa" : "PSI",
								  volumeUnit === 0 ? "L" : volumeUnit === 1 ? "gal(US)" : "gal(UK)"]
		property var textAsIcon: [qsTrId("LBL_0022") + translator.emptyString,
									qsTrId("LBL_0285") + translator.emptyString,
									qsTrId("LBL_0286") + translator.emptyString,
									qsTrId("LBL_0284") + translator.emptyString]


		Rectangle { //designFix
			width: 300
			height: 1
			color: color_gray_bar
		}

		Repeater {
			id: repUnitSet
			model: containerUnitSet.nbIteams

			Comp_listItemStatusBarIcon {
				id: listUnit
				iconPict: index >= containerUnitSet.nbIteams ? "" : containerUnitSet.sources[index]
				titleText: index >= containerUnitSet.nbIteams ? "" : containerUnitSet.titleText[index]
				iconIsText: true
				textAsIcon: index >= containerUnitSet.nbIteams ? "" : containerUnitSet.textAsIcon[index]
				textAsIconLeftMargin: 40
				isCurrent:  listStatusID.currentIndex === index ? true : false
				fontSize: 17
			}
		}
	}

	Column {
		id: containerMCU
		width: parent.width
		height: parent.height
		visible: backEnd.state === MyAppState.DM_1_DIAG_MAIN_CONTROL || pg_popUp.lastState === MyAppState.DM_1_DIAG_MAIN_CONTROL ? true : false

		property int nbIteams: 10 // TODO: why not 6
		property var textDetails: [ qsTrId("LBL_0083") + translator.emptyString,
									qsTrId("LBL_0082") + translator.emptyString,
									qsTrId("LBL_0084") + translator.emptyString,
									qsTrId("LBL_0336") + translator.emptyString,
									qsTrId("LBL_0337") + translator.emptyString,
									qsTrId("LBL_0338") + translator.emptyString ]
		property var textTitles : [ canError18FFE047 ? "ERROR" : outRangeHourmeter ? "99999.9" : dataEngine.opHours_Total.value.toFixed(1) + "h",
									canError18FEE747 ? "ERROR" : outRangeDailyOpHours ? "24.0" : dataEngine.opHours_DailyWorkload.value.toFixed(1) + "h",
									canErrorAutoIdleHours ? "ERROR" : outRangeAutoIdleHours ? "99999.9" : dataEngine.opHours_EngineIdleTime.value.toFixed(1) + "h",
									outRangeOperatingHoursAcc1 ? "99999.9" : dataEngine.opHours_ACC1.value.toFixed(1) + "h",
									outRangeOperatingHoursAcc2 ? "99999.9" : dataEngine.opHours_ACC2.value.toFixed(1) + "h",
									outRangeOpHoursMission ? "99999.9" : dataEngine.opHours_Mission.value.toFixed(1) + "h" ]
		Rectangle { //designFix
			width: 300
			height: 1
			color: color_gray_bar
		}

		Repeater {
			id: repMCU
			model: listStatusID.maxLengthItems

			Comp_listItemStatusBarIcon {
				id: listMCU
				titleText: index >= containerMCU.nbIteams ? "" : containerMCU.textTitles[index] ? containerMCU.textTitles[index] : ""
				iconIsText: true
				textAsIcon: index >= containerMCU.nbIteams ? "" : containerMCU.textDetails[index] ? containerMCU.textDetails[index] : ""
				isCurrent:  listStatusID.currentIndex === index ? true : false
				fontSize: 17
			}
		}
	}


	Column  {
		id: containerImmobilizerSettings
		width: parent.width
		height: parent.height
		visible: backEnd.state === MyAppState.IMMOBILIZER_SETTINGS || pg_popUp.lastState === MyAppState.IMMOBILIZER_SETTINGS ? true : false

		property int nbIteams: 5
		property var iconSources : ["qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 70x70/6.15_Lock WH.png",
									"qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 70x70/6.10_Lock time WH.png",
									"qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 70x70/6.16_Password Trans WH.png",
									"qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 70x70/6.17_Password Driver WH.png",
									"qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 70x70/6.18_Password Owner WH.png"]

		// TODO : Connect to CAN communication
		property var textTitles : [ pg_immobilizerActivation.switchValueSaved ? "ON" : "OFF",
									pg_immoblizerTimeValidation.validationTimeValueSaved.toString()+" min",
									"",
									"",
									"" ]

		property var isVisible: [ btnImmobActivationVisible,
								  btnImmobTimeToActivationVisible,
								  btnImmobTransPinVisible,
								  btnImmobDriverPinVisible,
								  btnImmobOwnerPinVisible]

		Rectangle { //designFix
			width: 300
			height: 1
			color: color_gray_bar
		}

		Repeater {
			id: repImmobilizerSettings
			model: listStatusID.maxLengthItems

			Comp_listItemStatusBarIcon {
				id: listImmobilizerSettings
				iconPict: index >= containerImmobilizerSettings.nbIteams ? "" : containerImmobilizerSettings.iconSources[index]
				titleText: index >= containerImmobilizerSettings.nbIteams ? "" : containerImmobilizerSettings.textTitles[index]
				isCurrent: listStatusID.currentIndex === index ? true : false
				fontSize: 17
				opacity: index >= containerImmobilizerSettings.nbIteams ? 0 : containerImmobilizerSettings.isVisible[index] === 1 ? 1 : 0.3
			}
		}
	}

	Column  {
		id: containerFileterRegeneration
		width: parent.width
		height: parent.height
		visible: backEnd.state === MyAppState.FILTER_REGENERATION || pg_popUp.lastState === MyAppState.FILTER_REGENERATION ? true : false

		property int nbIteams: 2
		property var iconSources : ["qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 70x70/6.92_Road vehicle, filter_WH.png",
									"qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 70x70/6.120_Soot_WH.png"]

		// TODO : Connect to CAN communication
		property var textTitles : [dataEngine.dPFSootLoad.value === 254 ? "ERROR" : pg_sootLevel.sootLevelValueShow + "%",
								   dataEngine.dPFAshLoad.value === 254 ? "ERROR" : pg_ashLevel.ashLevelValueShow + "%"]

		Rectangle { //designFix
			width: 300
			height: 1
			color: color_gray_bar
		}

		Repeater {
			id: repFilterRegeneration
			model: listStatusID.maxLengthItems

			Comp_listItemStatusBarIcon {
				id: listFilterRegeneration
				iconPict: index >= containerFileterRegeneration.nbIteams ? "" : containerFileterRegeneration.iconSources[index]
				titleText: index >= containerFileterRegeneration.nbIteams ? "" : containerFileterRegeneration.textTitles[index]
				isCurrent: listStatusID.currentIndex === index ? true : false
				fontSize: 17
			}
		}
	}
}

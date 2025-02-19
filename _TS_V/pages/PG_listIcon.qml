import QtQuick 2.6
import MyQmlModule 1.0
import QtGraphicalEffects 1.0
import "../components"

Rectangle {
	id: listIconID

	height: parent.height
	anchors.top: parent.top
	anchors.topMargin: backEnd.currentConfig.headerHeight
	visible: false
	opacity: visible ? 1.0 : 0.0
	Behavior on opacity { NumberAnimation { easing.type: Easing.InOutQuad; duration: 600 } }
	focus: true
	Keys.forwardTo: controller
	color: color_black


	property Item modelSelected : { null }
	property string headerIconStr: "qrc:/graphics/Icons/7.41 Language settings - white.png"

	property bool cautionTonesEnabled: dm.soundSetting === 1 ? true : false

	property int outlineThickness: 2

	property int hourMeterReset: 0
	property double hourMeter: dataEngine.opHours_Total.value

	property int factoryReset: 0
	property bool factoryResetSession: false

	onModelSelectedChanged: {
		if (modelSelected !== dateTimeModeModel) {
			if (modelSelected !== diagInstDisplayModel && modelSelected !== diagMCUModel
					&& modelSelected !== diagBattECUModel && modelSelected !== diagTCUModel) {
				modelSelected.currentIndex = modelSelected.selectedIndex
			}
			else {
				modelSelected.currentIndex = 0
			}
		}
		downPressed();
		upPressed();
		upPressed();
		downPressed();
	}

	onVisibleChanged: {
		if (modelSelected !== null) {
			if (modelSelected !== dateTimeModeModel) {
				if (modelSelected !== diagInstDisplayModel && modelSelected !== diagMCUModel
						&& modelSelected !== diagBattECUModel && modelSelected !== diagTCUModel) {
					modelSelected.currentIndex = modelSelected.selectedIndex
				}
				else {
					modelSelected.currentIndex = 0
				}
			}
		}
		downPressed();
		upPressed();
		upPressed();
		downPressed();

		if(visible === true) {
			console.log("Page PG_listIcon entered")
		}
	}

	// To come back to the menu page when hourmeter is higher than 10.0
	// (reset the hourmeter is not possible anymore)
	onHourMeterChanged: {
		if (visible && modelSelected === hourMeterResetModel) {
			if (hourMeter > 10.0) {
				pg_menu.isMenu2simplified = true
				pg_menu.selectMenuItems()
				backToMenu()
			}
		}
	}

	function selectStopTimerModel() {
		modelSelected = stopTimerModel
		headerIconStr = isV7 ? "qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 55X55/6.86_Auto engine stop_WH.png" : "qrc:/graphics/VehicleSettings/7.55 Auto stop - white.png"
	}

	function selectLanguagesModel() {
		modelSelected = languagesModel
		headerIconStr = "qrc:/graphics/Icons/7.41 Language settings - white.png"
	}

	function selectAuxFlowLimitLockModel() {
		modelSelected = auxFlowLimitLockModel
		headerIconStr = "qrc:/graphics/MechanicMode/7.82 PTO lock - white.png"
	}

	function selectDateTimeModeModel() {
		modelSelected = dateTimeModeModel
		dateTimeModeModel.selectedIndex = dm.dateTimeMode
		headerIconStr = "qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 55X55/6.165 Automatic date and time setting WH.png"
	}

	function selectTimeZoneModel() {
		modelSelected = timeZoneModel
		headerIconStr = "qrc:/graphics/DisplaySettings/7.51 Time zone - white.png"
	}

	function selectFormatHourModel() {
		formatHourModel.currentTime12h = dateTimeManager.formatDateTime(dateTimeManager.getCurrentTimeObj(), "AP hh:mm")
		formatHourModel.currentTime24h = dateTimeManager.formatDateTime(dateTimeManager.getCurrentTimeObj(), "HH:mm")
		modelSelected = formatHourModel
		headerIconStr = "qrc:/graphics/DisplaySettings/7.49 12-24 hour switching - white.png"
	}

	function selectDaylightModel() {
		daylightModel.selectedIndex = !dm.getDaylightSavingTime()

		var currentSetting = dateTimeManager.getDaylightSavingTime()
		if(currentSetting)
		{
			daylightModel.hourON = (dateTimeManager.getTimeFormat() === "HH:mm") ? "     " + dateTimeManager.getCurrentTimeCustomFormat("hh:mm") : dateTimeManager.getCurrentTimeCustomFormat("hh:mm AP")
			dateTimeManager.setDaylightSavingTime(false)
			daylightModel.hourOFF = (dateTimeManager.getTimeFormat() === "HH:mm") ? "     " + dateTimeManager.getCurrentTimeCustomFormat("hh:mm") : dateTimeManager.getCurrentTimeCustomFormat("hh:mm AP")
		} else
		{
			daylightModel.hourOFF = (dateTimeManager.getTimeFormat() === "HH:mm") ? "     " + dateTimeManager.getCurrentTimeCustomFormat("hh:mm") : dateTimeManager.getCurrentTimeCustomFormat("hh:mm AP")
			dateTimeManager.setDaylightSavingTime(true)
			daylightModel.hourON = (dateTimeManager.getTimeFormat() === "HH:mm") ? "     " + dateTimeManager.getCurrentTimeCustomFormat("hh:mm") : dateTimeManager.getCurrentTimeCustomFormat("hh:mm AP")
		}
		dateTimeManager.setDaylightSavingTime(currentSetting)

		modelSelected = daylightModel
		headerIconStr = "qrc:/graphics/DisplaySettings/7.50 Daylight saving time setting - white.png"
	}

	function selectSoundSettingModel() {
		modelSelected = soundSettingModel
		headerIconStr = "qrc:/graphics/DisplaySettings/7.44 Sound settings - white.png"
	}

	function selectResetModel() {
		modelSelected = resetModel
		headerIconStr = "qrc:/graphics/MaintenanceMode/7.80 Reset - white.png"
	}

	function selectTemperatureUnitModel() {
		modelSelected = tempUnitModel
		headerIconStr = "qrc:/graphics/DisplaySettings/7.52 Temperature - white.png"
	}

	function selectSpeedUnitModel() {
		modelSelected = speedUnitModel
		headerIconStr = "qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 55X55/6.152_Speedmeter_WH.png"
	}

	function selectPressureUnitModel() {
		modelSelected = pressureUnitModel
		headerIconStr = "qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 55X55/6.76_Pressure_WH.png"
	}

	function selectVolumeUnitModel() {
		modelSelected = volumeUnitModel
		headerIconStr = "qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 55X55/6.73_Volume_WH.png"
	}

	function selectDiagInstrumentDisplayModel() {
		modelSelected = diagInstDisplayModel
		headerIconStr = "qrc:/graphics/MechanicMode/7.86 Instrument display - white.png"
	}

	function selectDiagMCUModel() {
		modelSelected = diagMCUModel
		diagMCUModel.partNumber = String.fromCharCode(_CanHandler.McuSOFTPartNumber) // TODO: link to dataengine values
		diagMCUModel.softVersion = String.fromCharCode(_CanHandler.McuSOFTVersion) // TODO: link to dataengine values
		diagMCUModel.serialNumber = String.fromCharCode(48)
		diagMCUModel.softPartNUmber = String.fromCharCode(_CanHandler.McuSOFTSoftwarePartNumber)
		headerIconStr = "qrc:/graphics/MechanicMode/7.87 Main control unit - white.png"
	}

	function selectDiagBattECUModel() {
		modelSelected = diagBattECUModel
		diagBattECUModel.partNumber1 = String.fromCharCode(48) // TODO: link to dataengine values
		diagBattECUModel.partNumber2 = String.fromCharCode(48) // TODO: link to dataengine values
		diagBattECUModel.softVersionMain = String.fromCharCode(48) // TODO: link to dataengine values
		diagBattECUModel.softVersionMajor = String.fromCharCode(48) // TODO: link to dataengine values
		diagBattECUModel.softVersionMinor = String.fromCharCode(48) // TODO: link to dataengine values
		headerIconStr = "qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 55X55/6.133_ECU_Battery_WH.png"
	}

	function selectDiagTCUModel() {
		modelSelected = diagTCUModel
		headerIconStr = "qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 55X55/6.132_TCU_WH.png"
	}

	function selectFactorySettingsModel() {
		modelSelected = diagFactoryresetModel
		headerIconStr = "qrc:/graphics/MechanicMode/7.89 Reset - white.png"
	}

	function selectResetHourMeterModel() {
		modelSelected = hourMeterResetModel
		headerIconStr = "qrc:/graphics/MechanicMode/7.85 Reset hourmeter - white.png"
	}

	function selectResetOpTimeMeasureModel() {
		modelSelected = opTimeResetModel
		headerIconStr = "qrc:/graphics/OperationalManagementMode/7.80 Reset - white.png"
		opTimeResetModel.currentIndex = 0
		opTimeResetModel.selectedIndex = 0
	}

	function backToVehicleSettings() {
		backEnd.setState(MyAppState.VEHICULE_SET)
		backEnd.setCurrentPage(pg_listStatusBar)
		pg_listIcon.visible = false
		pgHeader.titleString = qsTrId("LBL_0025") + translator.emptyString
		pg_listStatusBar.visible = true
	}

	function backToOpTimeMeasurment() {
		backEnd.setState(MyAppState.OMM_1_TIME)
		backEnd.setCurrentPage(pg_opTimeMeas)
		pg_listIcon.visible = false
		pgHeader.titleString = qsTrId("LBL_0050") + translator.emptyString
		pg_opTimeMeas.visible = true
		console.log("Time measurement page selected")
	}

	function selectDateTimeAuto() {
		backEnd.setState(MyAppState.DS_3_DATE_TIME_AUTO)
		pgHeader.titleString = qsTrId("LBL_0015") + translator.emptyString
		pg_listIcon.selectTimeZoneModel()
		console.log("Time zone (automatic) page selected")
	}

	function selectDateTimeManual() {
		backEnd.setState(MyAppState.DS_3_DATE_TIME_MANUAL)
		backEnd.setCurrentPage(pg_dateSelection)
		pgHeader.titleString = qsTrId("LBL_0017") + translator.emptyString
		pg_listIcon.visible = false

		pg_dateSelection.initializeDateTimeManu()

		pg_dateSelection.visible = true
		console.log("Date and time (manual) page selected")
	}

	function selectDateTime() {
		pgHeader.visible = true
		pgHeader.mainMenu = false
		pgHeader.titleString = qsTrId("LBL_0012") + translator.emptyString
		pg_listStatusBar.visible = true
		pg_listIcon.visible = false
		backEnd.setState(MyAppState.DS_1_DATE_TIME)
		backEnd.setCurrentPage(pg_listStatusBar)
	}

	function selectTimeZone() {
		backEnd.setState(MyAppState.DS_2_DATE_TIME_SET)
		pgHeader.mainMenu = false
		pgHeader.visible = true
		pgHeader.titleString = qsTrId("LBL_0013") + translator.emptyString
		pg_listIcon.selectDateTimeModeModel()
	}

	function selectDaySetting() {
		backEnd.setState(MyAppState.PRE_HEATING)
		backEnd.setCurrentPage(pg_preHeating)
		pg_listIcon.visible = false
		pgHeader.titleString = qsTrId("LBL_0063") + translator.emptyString
		pg_menu.visible = true
		console.log("Pre-heating settings selected: " + currentIndex)
	}

	function selectMaintenanceReset() {
		backEnd.setState(MyAppState.MM_1_RESET)
		backEnd.setCurrentPage(pg_listStatusBar)
		pg_listIcon.visible = false
		pgHeader.titleString = qsTrId("LBL_0057") + translator.emptyString
		pg_listStatusBar.visible = true
		console.log("Maintenance time and reset page selected")
	}

	function selectHourMeterReset() {
		backEnd.setState(MyAppState)
		backEnd.setCurrentPage(pg_menu)
		pg_listIcon.visible = false
		pgHeader.titleString = qsTrId("LBL_0058") + translator.emptyString
		pg_listStatusBar.visible = true
		console.log("Maintenance time and reset page selected")
	}

	function selectUnitSettings() {
		backEnd.setState(MyAppState.DS_1_UNIT)
		backEnd.setCurrentPage(pg_listStatusBar)
		pg_listIcon.visible = false
		pgHeader.titleString = qsTrId("LBL_0021") + translator.emptyString
		pg_listStatusBar.visible = true
		console.log("Display Unit settings selected.")
	}

	function backToMenu() {
		if (controller.isMechanicMode1) {
			backEnd.setState(MyAppState.MENU_MECA_1)
//			backEnd.setState(MyAppState.MENU)
		}
		else if (controller.isMechanicMode2) {
			backEnd.setState(MyAppState.MENU_MECA_2)
		}
		else {
			backEnd.setState(MyAppState.MENU)
		}
		backEnd.setCurrentPage(pg_menu)
		pg_listIcon.visible = false
		pgHeader.visible = false
		pg_menu.visible = true
		console.log("Menu selected")
		rectList.visible = false
		rectMenu.visible = true
	}

	function backToSettings() {
		backEnd.setState(MyAppState.DISPLAY_SET)
		backEnd.setCurrentPage(pg_largeList)
		pg_largeList.selectDisplaySettingsModel(false)
		pg_listIcon.visible = false
		pg_largeList.visible = true
		pgHeader.titleString = qsTrId("LBL_0005") + translator.emptyString
		console.log("Display Setting selected.")
	}

	function backToDiagnosticMenu(){
		backEnd.setState(MyAppState.DIAGNOSTIC_MODE)
		console.log("Diagnostic Mode page selected")
		backEnd.setCurrentPage(pg_menu)
		pg_listIcon.visible = false;
		pg_menu.visible = true;
		backEnd.setCurrentPage(pg_menu);
		pgHeader.visible = false
		rectList.visible = false
		rectMenu.visible = true
	}

	function backToDisplaySettings() {
		backEnd.setState(MyAppState.DISPLAY_SET)
		backEnd.setCurrentPage(pg_largeList)
		pg_largeList.visible = true
		pg_listIcon.visible = false
		pgHeader.titleString = qsTrId("LBL_0005") + translator.emptyString
	}

	function menuPressed()
	{
		if (startupInfo.isManualStartMode()) {
			pg_home2.restartTimeoutTimer()
		}

		if (backEnd.state === MyAppState.DS_1_LANGUAGE) {
			pg_listIcon.backToDisplaySettings()
		}
		else if (backEnd.state === MyAppState.VS_1_ENGINE) {
			//dm.saveEngineStopTime()
			pg_listIcon.backToVehicleSettings()
		}
		else if (backEnd.state === MyAppState.DS_3_DATE_TIME_AUTO) {
			pg_listIcon.selectTimeZone()
		}
		else if (backEnd.state === MyAppState.DS_2_DATE_TIME_SET) {
			 pg_listIcon.selectDateTime()
		}
		else if (backEnd.state === MyAppState.DS_2_DATE_TIME_HOUR) {
			 pg_listIcon.selectDateTime()
		}
		else if (backEnd.state === MyAppState.DS_2_DATE_TIME_DAYLIGHT) {
			 pg_listIcon.selectDateTime()
		}
		else if(backEnd.state === MyAppState.DS_1_SOUND){
			pg_listIcon.backToSettings()
		}
		else if (backEnd.state === MyAppState.DS_2_UNIT_TEMP) {
			//go back to ds1 unit page
			 pg_listIcon.selectUnitSettings()
		}
		else if (backEnd.state === MyAppState.DS_2_UNIT_SPEED) {
			//go back to ds1 unit page
			 pg_listIcon.selectUnitSettings()
		}
		else if (backEnd.state === MyAppState.DS_2_UNIT_PRESSURE) {
			//go back to ds1 unit page
			 pg_listIcon.selectUnitSettings()
		}
		else if (backEnd.state === MyAppState.DS_2_UNIT_VOLUME) {
			//go back to ds1 unit page
			 pg_listIcon.selectUnitSettings()
		}
		else if (backEnd.state === MyAppState.MM_2_RESET) {
			pg_listIcon.selectMaintenanceReset()
		}
		else if (   (backEnd.state === MyAppState.DM_1_INSTRUMENT)
				 || (backEnd.state === MyAppState.DM_1_MAIN_CONTROL)
				 || (backEnd.state === MyAppState.DM_1_RESET)
				 ) {
			pg_listIcon.backToDiagnosticMenu()
		}
		else if (backEnd.state === MyAppState.OMM_1_TIME) {
			pg_listIcon.backToOpTimeMeasurment()
		}
		else if (backEnd.state === MyAppState.DM_1_BATTERY_ECU) {
			backEnd.setState(MyAppState.DIAGNOSTIC_MODE)
			backEnd.setCurrentPage(pg_menu)
			pg_listIcon.visible = false
			pg_menu.visible = true
			pgHeader.visible = false
			pgHeader.mainMenu = false
			rectList.visible = false
			rectMenu.visible = true
			console.log("Diagnostic Mode page selected")
		}
		else if (backEnd.state === MyAppState.DM_1_TCU) {
			backEnd.setState(MyAppState.DIAGNOSTIC_MODE)
			backEnd.setCurrentPage(pg_menu)
			pg_listIcon.visible = false
			pg_menu.visible = true
			pgHeader.visible = false
			pgHeader.mainMenu = false
			rectList.visible = false
			rectMenu.visible = true
			console.log("Diagnostic Mode page selected")
		}
		else {
			pg_listIcon.backToMenu()
		}
	}

	function enterPressed()
	{
		if (startupInfo.isManualStartMode()) {
			pg_home2.restartTimeoutTimer()
		}

		if (backEnd.state === MyAppState.DS_1_LANGUAGE) {
			languagesModel.selectedIndex = languagesModel.currentIndex
			languagesModel.sources[languagesModel.currentIndex].action()
			pg_listIcon.backToDisplaySettings()
		}
		else if (backEnd.state === MyAppState.VS_1_ENGINE) {
			stopTimerModel.selectedIndex = stopTimerModel.currentIndex
			stopTimerModel.sources[stopTimerModel.currentIndex].action()
			dm.saveEngineStopTime()
			pg_listIcon.backToVehicleSettings()
		}
		else if (backEnd.state === MyAppState.FLOW_LIMIT_LOCK) {
			auxFlowLimitLockModel.selectedIndex = auxFlowLimitLockModel.currentIndex
			auxFlowLimitLockModel.sources[auxFlowLimitLockModel.currentIndex].action()
			dm.saveLockSate()
			pg_listIcon.backToMenu()
		}
		else if (backEnd.state === MyAppState.DS_2_DATE_TIME_SET) {
			// No action if auto mode is selected for V7 or not allowed for V8e
//			if(dateTimeModeModel.currentIndex === 1 || (!isV7 && btnFctDateTimeAutoVisible === 1)){
			if(dateTimeModeModel.currentIndex === 1 || (btnFctDateTimeAutoVisible === 1)){
				dateTimeModeModel.selectedIndex = dateTimeModeModel.currentIndex
				dateTimeModeModel.sources[dateTimeModeModel.currentIndex].action()
			}
		}
		else if (backEnd.state === MyAppState.DS_2_DATE_TIME_HOUR) {
			formatHourModel.selectedIndex = formatHourModel.currentIndex
			formatHourModel.sources[formatHourModel.currentIndex].action()
			pg_listIcon.selectDateTime()
			dm.saveFormatHour()
		}
		else if (backEnd.state === MyAppState.DS_2_DATE_TIME_DAYLIGHT) {
			daylightModel.selectedIndex = daylightModel.currentIndex
			daylightModel.sources[daylightModel.currentIndex].action()
			pg_listIcon.selectDateTime()
			dm.saveDaylightSavingTime()
		}
		else if (backEnd.state === MyAppState.DS_3_DATE_TIME_AUTO) {
			timeZoneModel.selectedIndex = timeZoneModel.currentIndex
			timeZoneModel.sources[timeZoneModel.currentIndex].action()
			dm.dateTimeMode = 0
			pg_listIcon.selectTimeZone()
			dm.saveDateTimeMode()
			dm.saveTimeZone();
		}
		else if (backEnd.state === MyAppState.MM_2_RESET) {
			resetModel.sources[resetModel.currentIndex].action()
			pg_listIcon.selectMaintenanceReset()
		}
		else if (backEnd.state === MyAppState.DS_2_UNIT_TEMP) {
			tempUnitModel.selectedIndex = tempUnitModel.currentIndex
			tempUnitModel.sources[tempUnitModel.currentIndex].action()
			pg_listIcon.selectUnitSettings()
		}
		else if (backEnd.state === MyAppState.DS_2_UNIT_SPEED) {
			speedUnitModel.selectedIndex = speedUnitModel.currentIndex
			speedUnitModel.sources[speedUnitModel.currentIndex].action()
			pg_listIcon.selectUnitSettings()
		}
		else if (backEnd.state === MyAppState.DS_2_UNIT_PRESSURE) {
			pressureUnitModel.selectedIndex = pressureUnitModel.currentIndex
			pressureUnitModel.sources[pressureUnitModel.currentIndex].action()
			pg_listIcon.selectUnitSettings()
		}
		else if (backEnd.state === MyAppState.DS_2_UNIT_VOLUME) {
			volumeUnitModel.selectedIndex = volumeUnitModel.currentIndex
			volumeUnitModel.sources[volumeUnitModel.currentIndex].action()
			pg_listIcon.selectUnitSettings()
		}
		else if (backEnd.state === MyAppState.DS_1_SOUND) {
			soundSettingModel.selectedIndex = soundSettingModel.currentIndex
			soundSettingModel.sources[soundSettingModel.currentIndex].action()
			pg_listIcon.backToSettings()
		}
		else if (backEnd.state === MyAppState.DM_1_RESET) {
			diagFactoryresetModel.selectedIndex = diagFactoryresetModel.currentIndex
			diagFactoryresetModel.sources[diagFactoryresetModel.currentIndex].action()
			pg_listIcon.backToDiagnosticMenu()
		}
		else if (backEnd.state === MyAppState.RESET_HOUR_METER) {
			hourMeterResetModel.selectedIndex = hourMeterResetModel.currentIndex
			hourMeterResetModel.sources[hourMeterResetModel.currentIndex].action()
			pg_listIcon.backToMenu()
		}
		else if(backEnd.state === MyAppState.OMM_1_TIME) {
			opTimeResetModel.selectedIndex = opTimeResetModel.currentIndex
			opTimeResetModel.sources[opTimeResetModel.currentIndex].action()
			pg_listIcon.backToOpTimeMeasurment()
		}
	}

	function upPressed()
	{
		if (startupInfo.isManualStartMode()) {
			pg_home2.restartTimeoutTimer()
		}

		modelSelected.currentIndex = (modelSelected.currentIndex - 1 + modelSelected.nbItems) % modelSelected.nbItems

		var itemY = modelSelected.currentIndex * (34 + outlineThickness);

		if (itemY < container.contentY) {
			container.contentY = itemY;
		} else if (itemY + 34 > container.contentY + container.height) {
			container.contentY = itemY + (34 + outlineThickness * 3) - container.height;
		}
	}

	function downPressed()
	{
		if (startupInfo.isManualStartMode()) {
			pg_home2.restartTimeoutTimer()
		}

		modelSelected.currentIndex = (modelSelected.currentIndex + 1) % modelSelected.nbItems
		var itemY = modelSelected.currentIndex * (34 + outlineThickness);

		if (itemY + 34 > container.contentY + container.height) {
			container.contentY = itemY + (34 + outlineThickness * 3) - container.height;
		} else if (itemY < container.contentY) {
			container.contentY = itemY;
		}
	}

	Item {
		id: dateTimeModeModel

		property int currentIndex: dm.getDateTimeMode()
		property int selectedIndex: dm.getDateTimeMode()
		property int nbItems: 2
		property var sources: [
			{
				"title": qsTrId("LBL_0014") + translator.emptyString,
				"action": function() {pg_listIcon.selectDateTimeAuto()},
				"opacity": btnFctDateTimeAutoVisible === 1 ? 1 : 0.3
			},
			{
				"title": qsTrId("LBL_0016") + translator.emptyString,
				"action": function() {
					pg_listIcon.selectDateTimeManual()
				},
				"opacity": 1
			}
		]
	}

	Item {
		id: formatHourModel

		property int currentIndex: dm.getFormatHour()
		property int selectedIndex: dm.getFormatHour()
		property string currentTime12h: dateTimeManager.formatDateTime(dateTimeManager.getCurrentTimeObj(), "AP hh:mm")
		property string currentTime24h: dateTimeManager.formatDateTime(dateTimeManager.getCurrentTimeObj(), "HH:mm")
		property int nbItems: 2
		property var sources: [
			{
				"title": "24h       " + currentTime24h,
				"action": function() { dm.formatHour = 0; dateTimeManager.setTimeFormat("HH:mm"); pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5); }
			},
			{
				"title": "12h       " + currentTime12h,
				"action": function() { dm.formatHour = 1; dateTimeManager.setTimeFormat("AP hh:mm"); pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5); }
			}
		]
	}

	Item {
		id: daylightModel

		property int currentIndex: !dm.getDaylightSavingTime()
		property int selectedIndex: !dm.getDaylightSavingTime()
		property int nbItems: 2
		property string hourON: (dateTimeManager.getTimeFormat() === "HH:mm") ? dateTimeManager.getCurrentTimeCustomFormat("hh:mm") : dateTimeManager.getCurrentTimeCustomFormat("hh:mm AP")
		property string hourOFF: (dateTimeManager.getTimeFormat() === "HH:mm") ? dateTimeManager.getCurrentTimeCustomFormat("hh:mm") : dateTimeManager.getCurrentTimeCustomFormat("hh:mm AP")
		property var sources: [
			{
				"title": "ON                            " + hourON,
				"action": function() { dm.daylightSavingTime = 1; dateTimeManager.setDaylightSavingTime(true); pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5); }
			},
			{
				"title": "OFF                           " + hourOFF,
				"action": function() { dm.daylightSavingTime = 0; dateTimeManager.setDaylightSavingTime(false); pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5); }
			}
		]
	}

	Item {
		id: timeZoneModel

		property int currentIndex: dm.getTimeZoneIndex()
		property int selectedIndex: dm.getTimeZoneIndex()
		property int nbItems: 34
		property var timeZoneOffsets: [
			-12, -11, -10, -9, -8, -7, -6, -5, -4.5, -4, -3.5, -3, -2, -1,
			0, 1, 2, 3, 3.5, 4, 4.5, 5, 5.5, 5.75, 6, 6.5, 7, 8, 9, 9.5, 10, 11, 12, 13
		]
		property var sources: [
			{
				"action": function() { dm.timeZone = "UTC-12:00"; dm.setTimeZoneIndex(0); dateTimeManager.setTimeZone("UTC-12:00"); pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5); }
			},
			{
				"action": function() { dm.timeZone = "UTC-11:00"; dm.setTimeZoneIndex(1); dateTimeManager.setTimeZone("UTC-11:00"); pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5); }
			},
			{
				"action": function() { dm.timeZone = "UTC-10:00"; dm.setTimeZoneIndex(2); dateTimeManager.setTimeZone("UTC-10:00"); pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5); }
			},
			{
				"action": function() { dm.timeZone = "UTC-09:00"; dm.setTimeZoneIndex(3); dateTimeManager.setTimeZone("UTC-09:00"); pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5); }
			},
			{
				"action": function() { dm.timeZone = "UTC-08:00"; dm.setTimeZoneIndex(4); dateTimeManager.setTimeZone("UTC-08:00"); pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5); }
			},
			{
				"action": function() { dm.timeZone = "UTC-07:00"; dm.setTimeZoneIndex(5); dateTimeManager.setTimeZone("UTC-07:00"); pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5); }
			},
			{
				"action": function() { dm.timeZone = "UTC-06:00"; dm.setTimeZoneIndex(6); dateTimeManager.setTimeZone("UTC-06:00"); pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5); }
			},
			{
				"action": function() { dm.timeZone = "UTC-05:00"; dm.setTimeZoneIndex(7); dateTimeManager.setTimeZone("UTC-05:00"); pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5); }
			},
			{
				"action": function() { dm.timeZone = "UTC-04:30"; dm.setTimeZoneIndex(8); dateTimeManager.setTimeZone("UTC-04:30"); pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5); }
			},
			{
				"action": function() { dm.timeZone = "UTC-04:00"; dm.setTimeZoneIndex(9); dateTimeManager.setTimeZone("UTC-04:00"); pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5); }
			},
			{
				"action": function() { dm.timeZone = "UTC-03:30"; dm.setTimeZoneIndex(10); dateTimeManager.setTimeZone("UTC-03:30"); pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5); }
			},
			{
				"action": function() { dm.timeZone = "UTC-03:00"; dm.setTimeZoneIndex(11); dateTimeManager.setTimeZone("UTC-03:00"); pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5); }
			},
			{
				"action": function() { dm.timeZone = "UTC-02:00"; dm.setTimeZoneIndex(12); dateTimeManager.setTimeZone("UTC-02:00"); pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5); }
			},
			{
				"action": function() { dm.timeZone = "UTC-01:00"; dm.setTimeZoneIndex(13); dateTimeManager.setTimeZone("UTC-01:00"); pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5); }
			},
			{
				"action": function() { dm.timeZone = "UTC+00:00"; dm.setTimeZoneIndex(14); dateTimeManager.setTimeZone("UTC+00:00"); pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5); }
			},
			{
				"action": function() { dm.timeZone = "UTC+01:00"; dm.setTimeZoneIndex(15); dateTimeManager.setTimeZone("UTC+01:00"); pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5); }
			},
			{
				"action": function() { dm.timeZone = "UTC+02:00"; dm.setTimeZoneIndex(16); dateTimeManager.setTimeZone("UTC+02:00"); pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5); }
			},
			{
				"action": function() { dm.timeZone = "UTC+03:00"; dm.setTimeZoneIndex(17); dateTimeManager.setTimeZone("UTC+03:00"); pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5); }
			},
			{
				"action": function() { dm.timeZone = "UTC+03:30"; dm.setTimeZoneIndex(18); dateTimeManager.setTimeZone("UTC+03:30"); pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5); }
			},
			{
				"action": function() { dm.timeZone = "UTC+04:00"; dm.setTimeZoneIndex(19); dateTimeManager.setTimeZone("UTC+04:00"); pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5); }
			},
			{
				"action": function() { dm.timeZone = "UTC+04:30"; dm.setTimeZoneIndex(20); dateTimeManager.setTimeZone("UTC+04:30"); pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5); }
			},
			{
				"action": function() { dm.timeZone = "UTC+05:00"; dm.setTimeZoneIndex(21); dateTimeManager.setTimeZone("UTC+05:00"); pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5); }
			},
			{
				"action": function() { dm.timeZone = "UTC+05:30"; dm.setTimeZoneIndex(22); dateTimeManager.setTimeZone("UTC+05:30"); pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5); }
			},
			{
				"action": function() { dm.timeZone = "UTC+05:45"; dm.setTimeZoneIndex(23); dateTimeManager.setTimeZone("UTC+05:45"); pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5); }
			},
			{
				"action": function() { dm.timeZone = "UTC+06:00"; dm.setTimeZoneIndex(24); dateTimeManager.setTimeZone("UTC+06:00"); pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5); }
			},
			{
				"action": function() { dm.timeZone = "UTC+06:30"; dm.setTimeZoneIndex(25); dateTimeManager.setTimeZone("UTC+06:30"); pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5); }
			},
			{
				"action": function() { dm.timeZone = "UTC+07:00"; dm.setTimeZoneIndex(26); dateTimeManager.setTimeZone("UTC+07:00"); pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5); }
			},
			{
				"action": function() { dm.timeZone = "UTC+08:00"; dm.setTimeZoneIndex(27); dateTimeManager.setTimeZone("UTC+08:00"); pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5); }
			},
			{
				"action": function() { dm.timeZone = "UTC+09:00"; dm.setTimeZoneIndex(28); dateTimeManager.setTimeZone("UTC+09:00"); pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5); }
			},
			{
				"action": function() { dm.timeZone = "UTC+09:30"; dm.setTimeZoneIndex(29); dateTimeManager.setTimeZone("UTC+09:30"); pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5); }
			},
			{
				"action": function() { dm.timeZone = "UTC+10:00"; dm.setTimeZoneIndex(30); dateTimeManager.setTimeZone("UTC+10:00"); pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5); }
			},
			{
				"action": function() { dm.timeZone = "UTC+11:00"; dm.setTimeZoneIndex(31); dateTimeManager.setTimeZone("UTC+11:00"); pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5); }
			},
			{
				"action": function() { dm.timeZone = "UTC+12:00"; dm.setTimeZoneIndex(32); dateTimeManager.setTimeZone("UTC+12:00"); pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5); }
			},
			{
				"action": function() { dm.timeZone = "UTC+13:00"; dm.setTimeZoneIndex(33); dateTimeManager.setTimeZone("UTC+13:00"); pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5); }
			},
		]

		function getTimeZoneTitle(offset) {
			var offsetHours = Math.trunc(offset);
			var offsetMinutes = Math.abs((offset % 1) * 60);
			var sign = offset >= 0 ? "+" : "-";
			var timeZone = "UTC" + sign + Math.abs(offsetHours);
			if (offsetMinutes > 0) {
				timeZone += ":" + (offsetMinutes < 10 ? "0" : "") + offsetMinutes;
			} else {
				timeZone += ":00";
			}

			var dateTime = new Date();
			var dateTimeWithOffset = new Date(dateTime.getTime() + offset * 60 * 60 * 1000);  // Apply the time zone offset in milliseconds
			var formattedDate = Qt.formatDate(dateTimeWithOffset, "dd.MM.yyyy");
			var formattedTime = (dateTimeManager.getTimeFormat() === "HH:mm") ? Qt.formatTime(dateTimeWithOffset, "HH:mm") : Qt.formatTime(dateTimeWithOffset, "hh:mm AP");
			return timeZone + " " + formattedDate + " " + formattedTime;
		}

	}

	Item {
		id: languagesModel

		property int currentIndex: dm.getIndexLanguage()
		property int selectedIndex: dm.getIndexLanguage()
		property int nbItems: 11
		property var sources: [
			{
				"title": "English",
				"action": function() { dm.selectLanguage("en", 0); translator.selectLanguage("en"); pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5);
					if (dm.formatHour !== 1) {dm.formatHour = 1; dateTimeManager.setTimeFormat("AP hh:mm"); dm.saveFormatHour(); formatHourModel.selectedIndex = dm.getFormatHour(); formatHourModel.currentIndex = dm.getFormatHour();}
					if (dm.timeZone !== "UTC+00:00" && dm.dateTimeMode === 0) {dm.timeZone = "UTC+00:00"; dm.setTimeZoneIndex(14); dateTimeManager.setTimeZone("UTC+00:00"); dm.saveTimeZone(); timeZoneModel.selectedIndex = dm.getTimeZoneIndex(); timeZoneModel.currentIndex = dm.getTimeZoneIndex();} }
			},
			{
				"title": "Français",
				"action": function() { if (dm.getIndexLanguage() === 0) {if (dm.formatHour !== 0) {dm.formatHour = 0; dateTimeManager.setTimeFormat("HH:mm"); dm.saveFormatHour(); formatHourModel.selectedIndex = dm.getFormatHour(); formatHourModel.currentIndex = dm.getFormatHour();}}
					dm.selectLanguage("fr", 1); translator.selectLanguage("fr"); pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5);
					if (dm.timeZone !== "UTC+01:00" && dm.dateTimeMode === 0) {dm.timeZone = "UTC+01:00"; dm.setTimeZoneIndex(15); dateTimeManager.setTimeZone("UTC+01:00"); dm.saveTimeZone(); timeZoneModel.selectedIndex = dm.getTimeZoneIndex(); timeZoneModel.currentIndex = dm.getTimeZoneIndex();} }
			},
			{
				"title": "Deutsch",
				"action": function() { if (dm.getIndexLanguage() === 0) {if (dm.formatHour !== 0) {dm.formatHour = 0; dateTimeManager.setTimeFormat("HH:mm"); dm.saveFormatHour(); formatHourModel.selectedIndex = dm.getFormatHour(); formatHourModel.currentIndex = dm.getFormatHour();}}
					dm.selectLanguage("de", 2); translator.selectLanguage("de"); pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5);
					if (dm.timeZone !== "UTC+01:00" && dm.dateTimeMode === 0) {dm.timeZone = "UTC+01:00"; dm.setTimeZoneIndex(15); dateTimeManager.setTimeZone("UTC+01:00"); dm.saveTimeZone(); timeZoneModel.selectedIndex = dm.getTimeZoneIndex(); timeZoneModel.currentIndex = dm.getTimeZoneIndex();} }
			},
			{
				"title": "Italiano",
				"action": function() { if (dm.getIndexLanguage() === 0) {if (dm.formatHour !== 0) {dm.formatHour = 0; dateTimeManager.setTimeFormat("HH:mm"); dm.saveFormatHour(); formatHourModel.selectedIndex = dm.getFormatHour(); formatHourModel.currentIndex = dm.getFormatHour();}}
					dm.selectLanguage("it", 3); translator.selectLanguage("it"); pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5);
					if (dm.timeZone !== "UTC+02:00" && dm.dateTimeMode === 0) {dm.timeZone = "UTC+02:00"; dm.setTimeZoneIndex(16); dateTimeManager.setTimeZone("UTC+02:00"); dm.saveTimeZone(); timeZoneModel.selectedIndex = dm.getTimeZoneIndex(); timeZoneModel.currentIndex = dm.getTimeZoneIndex();} }
			},
			{
				"title": "Español",
				"action": function() { if (dm.getIndexLanguage() === 0) {if (dm.formatHour !== 0) {dm.formatHour = 0; dateTimeManager.setTimeFormat("HH:mm"); dm.saveFormatHour(); formatHourModel.selectedIndex = dm.getFormatHour(); formatHourModel.currentIndex = dm.getFormatHour();}}
					dm.selectLanguage("es", 4); translator.selectLanguage("es"); pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5);
					if (dm.timeZone !== "UTC+01:00" && dm.dateTimeMode === 0) {dm.timeZone = "UTC+01:00"; dm.setTimeZoneIndex(15); dateTimeManager.setTimeZone("UTC+01:00"); dm.saveTimeZone(); timeZoneModel.selectedIndex = dm.getTimeZoneIndex(); timeZoneModel.currentIndex = dm.getTimeZoneIndex();} }
			},
			{
				"title": "Português",
				"action": function() { if (dm.getIndexLanguage() === 0) {if (dm.formatHour !== 0) {dm.formatHour = 0; dateTimeManager.setTimeFormat("HH:mm"); dm.saveFormatHour(); formatHourModel.selectedIndex = dm.getFormatHour(); formatHourModel.currentIndex = dm.getFormatHour();}}
					dm.selectLanguage("pt", 5); translator.selectLanguage("pt"); pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5);
					if (dm.timeZone !== "UTC+00:00" && dm.dateTimeMode === 0) {dm.timeZone = "UTC+00:00"; dm.setTimeZoneIndex(14); dateTimeManager.setTimeZone("UTC+00:00"); dm.saveTimeZone(); timeZoneModel.selectedIndex = dm.getTimeZoneIndex(); timeZoneModel.currentIndex = dm.getTimeZoneIndex();} }
			},
			{
				"title": "Suomi",
				"action": function() { if (dm.getIndexLanguage() === 0) {if (dm.formatHour !== 0) {dm.formatHour = 0; dateTimeManager.setTimeFormat("HH:mm"); dm.saveFormatHour(); formatHourModel.selectedIndex = dm.getFormatHour(); formatHourModel.currentIndex = dm.getFormatHour();}}
					dm.selectLanguage("fi", 6); translator.selectLanguage("fi"); pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5);
					if (dm.timeZone !== "UTC+02:00" && dm.dateTimeMode === 0) {dm.timeZone = "UTC+02:00"; dm.setTimeZoneIndex(16); dateTimeManager.setTimeZone("UTC+02:00"); dm.saveTimeZone(); timeZoneModel.selectedIndex = dm.getTimeZoneIndex(); timeZoneModel.currentIndex = dm.getTimeZoneIndex();} }
			},
			{
				"title": "Svenska",
				"action": function() { if (dm.getIndexLanguage() === 0) {if (dm.formatHour !== 0) {dm.formatHour = 0; dateTimeManager.setTimeFormat("HH:mm"); dm.saveFormatHour(); formatHourModel.selectedIndex = dm.getFormatHour(); formatHourModel.currentIndex = dm.getFormatHour();}}
					dm.selectLanguage("sv", 7); translator.selectLanguage("sv"); pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5);
					if (dm.timeZone !== "UTC+01:00" && dm.dateTimeMode === 0) {dm.timeZone = "UTC+01:00"; dm.setTimeZoneIndex(15); dateTimeManager.setTimeZone("UTC+01:00"); dm.saveTimeZone(); timeZoneModel.selectedIndex = dm.getTimeZoneIndex(); timeZoneModel.currentIndex = dm.getTimeZoneIndex();} }
			},
			{
				"title": "Nederland",
				"action": function() { if (dm.getIndexLanguage() === 0) {if (dm.formatHour !== 0) {dm.formatHour = 0; dateTimeManager.setTimeFormat("HH:mm"); dm.saveFormatHour(); formatHourModel.selectedIndex = dm.getFormatHour(); formatHourModel.currentIndex = dm.getFormatHour();} }
					dm.selectLanguage("nl", 8); translator.selectLanguage("nl"); pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5);
					if (dm.timeZone !== "UTC+01:00" && dm.dateTimeMode === 0) {dm.timeZone = "UTC+01:00"; dm.setTimeZoneIndex(15); dateTimeManager.setTimeZone("UTC+01:00"); dm.saveTimeZone(); timeZoneModel.selectedIndex = dm.getTimeZoneIndex(); timeZoneModel.currentIndex = dm.getTimeZoneIndex();} }
			},
			{
				"title": "Polski",
				"action": function() { if (dm.getIndexLanguage() === 0) {if (dm.formatHour !== 0) {dm.formatHour = 0; dateTimeManager.setTimeFormat("HH:mm"); dm.saveFormatHour(); formatHourModel.selectedIndex = dm.getFormatHour(); formatHourModel.currentIndex = dm.getFormatHour();} }
					dm.selectLanguage("pl", 9); translator.selectLanguage("pl"); pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5);
					if (dm.timeZone !== "UTC+01:00" && dm.dateTimeMode === 0) {dm.timeZone = "UTC+01:00"; dm.setTimeZoneIndex(15); dateTimeManager.setTimeZone("UTC+01:00"); dm.saveTimeZone(); timeZoneModel.selectedIndex = dm.getTimeZoneIndex(); timeZoneModel.currentIndex = dm.getTimeZoneIndex();} }
			},
			{
				"title": "Dansk",
				"action": function() { if (dm.getIndexLanguage() === 0) {if (dm.formatHour !== 0) {dm.formatHour = 0; dateTimeManager.setTimeFormat("HH:mm"); dm.saveFormatHour(); formatHourModel.selectedIndex = dm.getFormatHour(); formatHourModel.currentIndex = dm.getFormatHour();} }
					dm.selectLanguage("da", 10); translator.selectLanguage("da"); pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5);
					if (dm.timeZone !== "UTC+02:00" && dm.dateTimeMode === 0) {dm.timeZone = "UTC+02:00"; dm.setTimeZoneIndex(16); dateTimeManager.setTimeZone("UTC+02:00"); dm.saveTimeZone(); timeZoneModel.selectedIndex = dm.getTimeZoneIndex(); timeZoneModel.currentIndex = dm.getTimeZoneIndex();} }
			}
		]
	}

	Item {
		id: stopTimerModel

		property int nbItems: isV7 ? 9 : 13
		property int currentIndex: (dm.getIndexStopTime() >= nbItems) ? (nbItems - 1) : dm.getIndexStopTime()
		property int selectedIndex: currentIndex
		property var sources: isV7 ? [
			{
			 "title": "0 " + qsTrId("LBL_0028") + translator.emptyString,
			 "action": function() { dm.engineStopTime = 0; pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5); }
			},
			{
				"title": "1 " + qsTrId("LBL_0027") + translator.emptyString,
				"action": function() { dm.engineStopTime = 1; pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5); }
			},
			{
				"title": "2 " + qsTrId("LBL_0028") + translator.emptyString,
				"action": function() { dm.engineStopTime = 2; pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5); }
			},
			{
				"title": "3 " + qsTrId("LBL_0028") + translator.emptyString,
				"action": function() { dm.engineStopTime = 3; pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5); }
			},
			{
				"title": "4 " + qsTrId("LBL_0028") + translator.emptyString,
				"action": function() { dm.engineStopTime = 4; pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5); }
			},
			{
				"title": "5 " + qsTrId("LBL_0028") + translator.emptyString,
				"action": function() { dm.engineStopTime = 5; pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5); }
			},
			{
				"title": "6 " + qsTrId("LBL_0028") + translator.emptyString,
				"action": function() { dm.engineStopTime = 6; pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5); }
			},
			{
				"title": "8 " + qsTrId("LBL_0028") + translator.emptyString,
				"action": function() { dm.engineStopTime = 8; pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5); }
			},
			{
				"title": "10 " + qsTrId("LBL_0028") + translator.emptyString,
				"action": function() { dm.engineStopTime = 10; pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5); }
			}
		] : [
			 {
				 "title": "0 " + "sec",
				 "action": function() { dm.engineStopTime = 0 ; pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5); }
			 },
			 {
				 "title": "10 " + "sec",
				 "action": function() { dm.engineStopTime = 100 ; pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5); }
			 },
			 {
				 "title": "20 " + "sec",
				 "action": function() { dm.engineStopTime = 200; pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5); }
			 },
			 {
				 "title": "30 " + "sec",
				 "action": function() { dm.engineStopTime = 300; pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5); }
			 },
			 {
				 "title": "40 " + "sec",
				 "action": function() { dm.engineStopTime = 400; pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5); }
			 },
			 {
				 "title": "50 " + "sec",
				 "action": function() { dm.engineStopTime = 500; pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5); }
			 },
			 {
				 "title": "60 " + "sec",
				 "action": function() { dm.engineStopTime = 600; pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5); }
			 },
			 {
				 "title": "70 " + "sec",
				 "action": function() { dm.engineStopTime = 700; pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5); }
			 },
			 {
				 "title": "80 " + "sec",
				 "action": function() { dm.engineStopTime = 800; pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5); }
			 },
			 {
				 "title": "90 " + "sec",
				 "action": function() { dm.engineStopTime = 900; pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5); }
			 },
			 {
				 "title": "100 " + "sec",
				 "action": function() { dm.engineStopTime = 1000; pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5); }
			 },
			 {
				 "title": "110 " + "sec",
				 "action": function() { dm.engineStopTime = 1100; pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5); }
			 },
			 {
				 "title": "120 " + "sec",
				 "action": function() { dm.engineStopTime = 1200; pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5); }
			 }
		 ]
		Timer {
			id: resetconf
			running: true
			interval: 4000
			repeat: false
			onTriggered: {
				if (isV7 && dm.engineStopTime > 10) {
					dm.engineStopTime = 10;
					dm.saveEngineStopTime()
					stopTimerModel.currentIndex = dm.getIndexStopTime()
					stopTimerModel.selectedIndex = dm.getIndexStopTime()
				}
				if (!isV7 && (dm.engineStopTime !== 0) && (dm.engineStopTime < 10)) {
					dm.engineStopTime = 100
					dm.saveEngineStopTime()
					stopTimerModel.currentIndex = dm.getIndexStopTime()
					stopTimerModel.selectedIndex = dm.getIndexStopTime()
				}
			}
		}
	}

	Item {
		id: auxFlowLimitLockModel

		property int currentIndex: dm.get_indexLockState() // 1: unlocked; 0: locked
		property int selectedIndex: dm.get_indexLockState()
		property int nbItems: 2
		property var sources: [
			{
				"title": qsTrId("LBL_0076") + translator.emptyString,
				"action": function() { dm.indexLockState = 0; pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5); }
			},
			{
				"title": qsTrId("LBL_0077") + translator.emptyString,
				"action": function() { dm.indexLockState = 1; pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5); }
			}
		]
	}

	Item {
		id: resetModel

		property int currentIndex: 0
		property int selectedIndex: 0
		property int nbItems: 2
		property bool isHourMeter: backEnd.state === MyAppState.RESET_HOUR_METER ? true : false
		property var sources: [
			{
				"title": qsTrId("LBL_0054") + translator.emptyString,
				"action": function() {}
			},
			{
				"title": qsTrId("LBL_0055") + translator.emptyString,
				"action": function() {
					pg_listLargeStatusBar.updateMaintenanceHistory(pg_listStatusBar.currentIndex)
					pg_listStatusBar.selectResetMaintenanceParameter()
					pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5);
				}
			}
		]
	}

	Item {
		id: tempUnitModel

		property int currentIndex: pg_listStatusBar.isCelsius === true ? 0 : 1
		property int selectedIndex: pg_listStatusBar.isCelsius === true ? 0 : 1
		property int nbItems: 2
		property var sources: [
			// popup with no buzzer and go back to ds1 unit page
			{
				"title": "°C",
				"action": function() { pg_listStatusBar.isCelsius = true; dm.tempUnitIsCelsius = 1; dm.saveTemperatureUnit(); pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5); }
			},
			{
				"title": "°F",
				"action": function() { pg_listStatusBar.isCelsius = false; dm.tempUnitIsCelsius = 0; dm.saveTemperatureUnit(); pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5); }
			}
		]
	}

	Item {
		id: speedUnitModel

		property int currentIndex: pg_listStatusBar.isKmh === true ? 0 : 1
		property int selectedIndex: pg_listStatusBar.isKmh === true ? 0 : 1
		property int nbItems: 2
		property var sources: [
			// popup with no buzzer and go back to ds1 unit page
			{
				"title": "Km/h",
				"action": function() { pg_listStatusBar.isKmh = true; dm.speedUnitIsKmh = 1; dm.saveSpeedUnit() ; pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5);}
			},
			{
				"title": "mph",
				"action": function() { pg_listStatusBar.isKmh = false; dm.speedUnitIsKmh = 0; dm.saveSpeedUnit() ; pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5);}
			}
		]
	}

	Item {
		id: pressureUnitModel

		property int currentIndex: pg_listStatusBar.pressureUnit
		property int selectedIndex: pg_listStatusBar.pressureUnit
		property int nbItems: 3
		property var sources: [
			// popup with no buzzer and go back to ds1 unit page
			{
				"title": "bar",
				"action": function() { pg_listStatusBar.pressureUnit = 0; dm.pressureUnit = 0; dm.savePressureUnit() ; pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5);}
			},
			{
				"title": "MPa",
				"action": function() { pg_listStatusBar.pressureUnit = 1; dm.pressureUnit = 1; dm.savePressureUnit() ; pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5);}
			},
			{
				"title": "PSI",
				"action": function() { pg_listStatusBar.pressureUnit = 2; dm.pressureUnit = 2; dm.savePressureUnit() ; pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5);}
			}
		]
	}
	Item {
		id: volumeUnitModel

		property int currentIndex: pg_listStatusBar.volumeUnit
		property int selectedIndex: pg_listStatusBar.volumeUnit
		property int nbItems: 3
		property var sources: [
			// popup with no buzzer and go back to ds1 unit page
			{
				"title": "L",
				"action": function() { pg_listStatusBar.volumeUnit = 0; dm.volumeUnit = 0; dm.saveVolumeUnit() ; pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5);}
			},
			{
				"title": "gal(US)",
				"action": function() { pg_listStatusBar.volumeUnit = 1; dm.volumeUnit = 1; dm.saveVolumeUnit() ; pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5);}
			},
			{
				"title": "gal(UK)",
				"action": function() { pg_listStatusBar.volumeUnit = 2; dm.volumeUnit = 2; dm.saveVolumeUnit() ; pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5);}
			}
		]
	}
	Item {
		id: soundSettingModel

		property int currentIndex: (dm.soundSetting === 1 ? 0 : 1)
		property int selectedIndex: (dm.soundSetting === 1 ? 0 : 1)
		property int nbItems: 2
		property var sources: [
			// popup with no buzzer and go back to display settings page
			{
				"title": "ON" ,
				"action": function() { cautionTonesEnabled = true; dm.soundSetting = 1; dm.saveSoundSetting(); pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 0); }
			},
			{
				"title": "OFF",
				"action": function() { cautionTonesEnabled = false; dm.soundSetting = 0; dm.saveSoundSetting(); pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 0); }
			}
		]
	}


	Item {
		id: diagInstDisplayModel

		property int currentIndex: 0
		property int nbItems: 4
		property var sources: [
			{
				"title": "P/N : MONITOR 3.5\"",
				"action": function() { }
			},
			{
				"title": "S/N : 17AB80-17300",
				"action": function() { }
			},
			{
				"title": "S/P : 17AB80-17000",
				"action": function() { }
			},
			{
				"title": "S/V : " + version.slice(4,24),
				"action": function() { }
			}
		]
	}


	Item {
		id: diagMCUModel

		property string partNumber: String.fromCharCode(_CanHandler.McuSOFTPartNumber) // TODO: link to dataengine values
		property string softVersion: String.fromCharCode(_CanHandler.McuSOFTVersion) // TODO: link to dataengine values
		property string serialNumber: String.fromCharCode(48) // TODO: link to dataengine values
		property string softPartNUmber: String.fromCharCode(_CanHandler.McuSOFTSoftwarePartNumber) // TODO: link to dataengine values
		property int currentIndex: 0
		property int nbItems: 4
		property var sources: [
			{
				"title": "P/N : CONTROLLER ACTIA",
				"action": function() { }
			},
			{
				"title": "S/N : " + diagMCUModel.serialNumber,
				"action": function() { }
			},
			{
				"title": "S/P : 17AB80-179" + (canErrorMCUSoftPartNum ? "00" : diagMCUModel.softPartNUmber), // TODO: link to dataengine values
				"action": function() { }
			},
			{
				"title": "S/V : " +  (canErrorMCUSoftVersion ? "0.00" : diagMCUModel.softVersion), // TODO: link to dataengine values
				"action": function() { }
			}
		]
	}


	Item {
		id: diagBattECUModel

		property string partNumber1: String.fromCharCode(48) // TODO: link to dataengine values
		property string partNumber2: String.fromCharCode(48) // TODO: link to dataengine values
		property string softVersionMain: String.fromCharCode(48) // TODO: link to dataengine values
		property string softVersionMajor: String.fromCharCode(48) // TODO: link to dataengine values
		property string softVersionMinor: String.fromCharCode(48) // TODO: link to dataengine values
		property int currentIndex: 0
		property int nbItems: 4
		property var sources: [
			{
				"title": "P/N : ",
				"action": function() { }
			},
			{
				"title": "S/N : ",
				"action": function() { }
			},
			{
				"title":  "S/P : ", // TODO: link to dataengine values
				"action": function() { }
			},
			{
				"title": "S/V : ", // TODO: link to dataengine values
				"action": function() { }
			}
		]
	}

	Item {
		id: diagTCUModel

		property string partNumber:  String.fromCharCode(dataEngine.sOFTTransmissionPartNumber.value)
		property string serialNumber: String.fromCharCode(48) // TODO: link to dataengine values
		property string softVersion: String.fromCharCode(dataEngine.sOFTSoftwarePartNumber.value)
		property string softPartNumber: String.fromCharCode(dataEngine.sOFTSoftwareVersion.value)

		property int currentIndex: 0
		property int nbItems: 4
		property var sources: [
			{
				"title": "P/N : " + (canError18FEDA03 ? "0" : diagTCUModel.partNumber),
				"action": function() { }
			},
			{
				"title": "S/N : 0",
				"action": function() { }
			},
			{
				"title":  "S/P : " + (canError18FEDA03 ? "0" : diagTCUModel.softPartNumber), // TODO: link to dataengine values
				"action": function() { }
			},
			{
				"title": "S/V : " + (canError18FEDA03 ? "0" : diagTCUModel.softVersion), // TODO: link to dataengine values
				"action": function() { }
			}
		]
	}

	Item {
		id: diagFactoryresetModel

		property int currentIndex: 0
		property int selectedIndex: 0
		property int nbItems: 2
		property string resultDate: ""
		property string resultTime: ""
		property var sources: [
			{
				"title": qsTrId("LBL_0054") + translator.emptyString,
				"action": function() { } // do nothing
			},
			{
				"title": qsTrId("LBL_0055") + translator.emptyString,
				"action": function() {
					factoryReset = 1
					factoryResetSession = true // true after a factory reset until the display is shutdown, this is used to forbid mechanic mode history update just after a factory reset

					// Start screen = Yanmar
					// Shut down screen = Yanmar
					RunProcess.launch("rm /opt/etc/weston-background.png")
					RunProcess.launch("ln -sf /opt/IntroVideo.ShutdownGreeting.png /opt/etc/ShutdownGreeting.png")
					RunProcess.launch("ln -sf /opt/etc/init.d/AnimationScripts/videoScript.sh /opt/etc/rc5.d/S04StartSplashVideo")

					// PTO setting shortcut on home page = disabled
					dm.indexPTO = 0
					dm.save_indexPTO()

					// Date and time screen = automatic
					dm.dateTimeMode = 0
					dm.saveDateTimeMode()

					// Language screen = german
					// Time zone screen = UTC
					// 12/24-hour switch screen = 12h
					dm.selectLanguage("de", 2);
					translator.selectLanguage("de");
					dm.formatHour = 1;
					dateTimeManager.setTimeFormat("AP hh:mm");
					dm.saveFormatHour();
					formatHourModel.selectedIndex = dm.getFormatHour();
					formatHourModel.currentIndex = dm.getFormatHour();
					dm.timeZone = "UTC+00:00";
					dm.setTimeZoneIndex(14);
					dateTimeManager.setTimeZone("UTC+00:00"); // this function also sets manual mode to false
					dm.saveTimeZone();
					timeZoneModel.selectedIndex = dm.getTimeZoneIndex();
					timeZoneModel.currentIndex = dm.getTimeZoneIndex();

					// Daylight saving time screen = OFF
					dm.daylightSavingTime = 0;
					dateTimeManager.setDaylightSavingTime(false);
					dm.saveDaylightSavingTime()

					// Temperature screen = °C
					dm.tempUnitIsCelsius = true
					dm.saveTemperatureUnit()
					pg_listStatusBar.isCelsius = true;

					// Speed screen = Km/h
					dm.speedUnitIsKmh = true
					dm.saveSpeedUnit()
					pg_listStatusBar.isKmh = true;

					// Pressure screen = Bar
					dm.pressureUnit = 0
					dm.savePressureUnit()
					pg_listStatusBar.pressureUnit = 0;

					// Volume screen = L
					dm.volumeUnit = 0
					dm.saveVolumeUnit()
					pg_listStatusBar.volumeUnit = 0;

					// Day brightness screen= 100%
					// Night brightness screen= 30%
					pg_gauge.resetBrightness()

					// Auto E-motor stop timer screen = 5 min
					if (isV7)
						dm.engineStopTime = 5
					else
						dm.engineStopTime = 600

					dm.saveEngineStopTime()

					// Sound setting is ON
					cautionTonesEnabled = true
					dm.soundSetting = 1
					dm.saveSoundSetting()

					// All accessory icon screen = AUX
					// All gauge on PTO1/PTO2 screen = 100%
					for(var presetIndex = 0; presetIndex < 5; presetIndex++)
					{
						dm.getPtoSettings(presetIndex).accessory_icon_source = "qrc:/graphics/02_Main_Icons PNG/02_Main_Icons PNG 25x25/2.111 AUX"
						dm.getPtoSettings(presetIndex).pto1_left = 10
						dm.getPtoSettings(presetIndex).pto1_right = 10
						dm.getPtoSettings(presetIndex).pto2_left = 10
						dm.getPtoSettings(presetIndex).pto2_right = 10
					}

					dm.getPtoSettings(0).accessory_icon_source = "qrc:/graphics/02_Main_Icons PNG/02_Main_Icons PNG 25x25/2.111 AUX"
					dm.getPtoSettings(0).pto1_left = 10
					dm.getPtoSettings(0).pto1_right = 10
					dm.getPtoSettings(0).pto2_left = 10
					dm.getPtoSettings(0).pto2_right = 10

					dm.getPtoSettings(1).accessory_icon_source = "qrc:/graphics/02_Main_Icons PNG/02_Main_Icons PNG 25x25/2.105_Forage harvester_ cutterhead"
					dm.getPtoSettings(1).pto1_left = 5
					dm.getPtoSettings(1).pto1_right = 5
					dm.getPtoSettings(1).pto2_left = 5
					dm.getPtoSettings(1).pto2_right = 5

					dm.getPtoSettings(2).accessory_icon_source = "qrc:/graphics/02_Main_Icons PNG/02_Main_Icons PNG 25x25/2.106 Rotary brush"
					dm.getPtoSettings(2).pto1_left = 8
					dm.getPtoSettings(2).pto1_right = 8
					dm.getPtoSettings(2).pto2_left = 8
					dm.getPtoSettings(2).pto2_right = 8

					dm.getPtoSettings(3).accessory_icon_source = "qrc:/graphics/02_Main_Icons PNG/02_Main_Icons PNG 25x25/2.110 Mulcher"
					dm.getPtoSettings(3).pto1_left = 2
					dm.getPtoSettings(3).pto1_right = 2
					dm.getPtoSettings(3).pto2_left = 2
					dm.getPtoSettings(3).pto2_right = 2

					dm.getPtoSettings(4).accessory_icon_source = "qrc:/graphics/02_Main_Icons PNG/02_Main_Icons PNG 25x25/2.108 Trencher conveyor"
					dm.getPtoSettings(4).pto1_left = 10
					dm.getPtoSettings(4).pto1_right = 10
					dm.getPtoSettings(4).pto2_left = 10
					dm.getPtoSettings(4).pto2_right = 10

					dm.getPtoSettings(5).accessory_icon_source = "qrc:/graphics/02_Main_Icons PNG/02_Main_Icons PNG 25x25/2.104_Loader bucket grapple"
					dm.getPtoSettings(5).pto1_left = 7
					dm.getPtoSettings(5).pto1_right = 7
					dm.getPtoSettings(5).pto2_left = 7
					dm.getPtoSettings(5).pto2_right = 7

					dm.getPtoSettings(6).accessory_icon_source = "qrc:/graphics/02_Main_Icons PNG/02_Main_Icons PNG 25x25/2.109 Vibration plate"
					dm.getPtoSettings(6).pto1_left = 6
					dm.getPtoSettings(6).pto1_right = 6
					dm.getPtoSettings(6).pto2_left = 6
					dm.getPtoSettings(6).pto2_right = 6

					dm.savePtoSettings();
					pg_home.updatePtoSetting()

					// Calendar screen = reset the memory
					pg_calendar.resetDB()

					// Operation time measurement = reset hourmeter
					var dayValue = dateTimeManager.getDay() < 10 ? "0" + dateTimeManager.getDay().toString() : dateTimeManager.getDay().toString()
					var monthValue = dateTimeManager.getMonth() < 10 ? "0" + dateTimeManager.getMonth().toString() : dateTimeManager.getMonth().toString()
					var yearValue = dateTimeManager.getYear().toString()
					resultDate = dayValue + "/" + monthValue + "/" + yearValue
					dm.setOpTimeResetDate(resultDate)

					var hourValue = dateTimeManager.getHour() < 10 ? "0" + dateTimeManager.getHour().toString() : dateTimeManager.getHour().toString()
					var minValue = dateTimeManager.getMinutes() < 10 ? "0" + dateTimeManager.getMinutes().toString() : dateTimeManager.getMinutes().toString()
					resultTime = hourValue + ":" + minValue
					dm.setOpTimeResetTime(resultTime)

					dm.setOpTimeResetHourmeter(dataEngine.opHours_Total.value.toFixed(1))

					dm.saveOpTimeResetEvent()

					// History maintenance screen = reset the memory
					pg_listLargeStatusBar.resetAllHistory()

					// Interval maintenance screen = reset to original values

					// Day setting screen in Pre-heating screen = delete all day
					// Pre-heating screen = OFF
					for (var i = 0; i < 7; i++) {
						pg_preHeating.unsetDay(i)
					}
					dm.getPreHeating().active = 0
					dm.savePreHeatingSettings()

					// AUX flow limit lock = unlock
					dm.indexLockState = 1
					dm.saveLockSate()

					// RCS default settings are 5km/h
					dm.rcsBackward = 5
					dm.rcsFoward = 5
					dm.saveRCSSettings()

					// History mechanic mode = reset
					pg_listMechanic.resetAllUsageHistory()

					pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5);
				}
			}
		]
	}

	Item {
		id: hourMeterResetModel

		property int currentIndex: 0
		property int selectedIndex: 0
		property int nbItems: 2
		property var sources: [
			{
				"title": qsTrId("LBL_0054") + translator.emptyString,
				"action": function() { }
			},
			{
				"title": qsTrId("LBL_0055") + translator.emptyString,
				"action": function() {
					listIconID.hourMeterReset = 1
					pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5);
					pg_menu.isMenu2simplified = true
					pg_menu.selectMenuItems()
				}
			}
		]
	}

	Item {
		id: opTimeResetModel

		property int currentIndex: 0
		property int selectedIndex: 0
		property int nbItems: 2
		property string resultDate: ""
		property string resultTime: ""
		property int resultHourmeter: 0
		property var sources: [
			{
				// NO
				"title": qsTrId("LBL_0054") + translator.emptyString,
				"action": function() {

				}
			},
			{
				// YES
				"title": qsTrId("LBL_0055") + translator.emptyString,
				"action": function() {
					var dayValue = dateTimeManager.getDay() < 10 ? "0" + dateTimeManager.getDay().toString() : dateTimeManager.getDay().toString()
					var monthValue = dateTimeManager.getMonth() < 10 ? "0" + dateTimeManager.getMonth().toString() : dateTimeManager.getMonth().toString()
					var yearValue = dateTimeManager.getYear().toString()
					resultDate = dayValue + "/" + monthValue + "/" + yearValue
					dm.setOpTimeResetDate(resultDate)

					var hourValue = dateTimeManager.getHour() < 10 ? "0" + dateTimeManager.getHour().toString() : dateTimeManager.getHour().toString()
					var minValue = dateTimeManager.getMinutes() < 10 ? "0" + dateTimeManager.getMinutes().toString() : dateTimeManager.getMinutes().toString()
					resultTime = hourValue + ":" + minValue
					dm.setOpTimeResetTime(resultTime)

					dm.setOpTimeResetHourmeter(dataEngine.opHours_Total.value.toFixed(1))

					dm.saveOpTimeResetEvent()

					pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5);
				}
			}
		]
	}


	Rectangle {
		id: menuBackground
		width: headerIcon.width + (outlineThickness * 2)
		height: !modelSelected ? 0 : modelSelected.nbItems < 4 ? headerIcon.height + headerIcon.anchors.topMargin + ((34 + outlineThickness) * 4) + outlineThickness : headerIcon.height + headerIcon.anchors.topMargin + ((34 + outlineThickness) * modelSelected.nbItems) + outlineThickness
		color: color_gray_bar
		anchors.top: parent.top
	}

	Rectangle {
		id: headerIcon
		width: parent.width - comp_navigationBar.width
		height: 67
		color: color_gray
		x: 2
		anchors {
			top : parent.top
			topMargin: 2
		}
		Image {
			id: icon
			source: headerIconStr
			anchors {
				verticalCenter: parent.verticalCenter
				horizontalCenter: parent.horizontalCenter
			}
			fillMode: Image.Pad
		}
	}

	Flickable {
		id: container

		anchors.top: headerIcon.bottom

		width: parent.width
		height: parent.height - headerIcon.height
		boundsBehavior: Flickable.StopAtBounds

		rotation: 0

		Repeater {
			model: !modelSelected ? 0 : modelSelected.nbItems < 4 ? 4 : modelSelected.nbItems

			Comp_listIcon {
				id: listItem
				title: modelSelected === timeZoneModel ? timeZoneModel.getTimeZoneTitle(timeZoneModel.timeZoneOffsets[index]) : index >= modelSelected.nbItems ? "" : modelSelected.sources[index].title
				isCurrent: modelSelected.currentIndex === index ? true : false
				isHighlightable: ((modelSelected === diagInstDisplayModel) || (modelSelected === diagMCUModel) || (modelSelected === diagBattECUModel) || (modelSelected === diagTCUModel)) ? false : true
				isSelectable: ((modelSelected === diagInstDisplayModel) || (modelSelected === diagMCUModel) || (modelSelected === diagBattECUModel) || (modelSelected === diagTCUModel)) ? false : true
				isSelected: modelSelected !== diagInstDisplayModel && modelSelected !== diagMCUModel && modelSelected !== diagBattECUModel && modelSelected !== diagTCUModel ? modelSelected.selectedIndex === index ? true : false : false
				anchors.top: index === 0 ? parent.top : parent.children[index-1].bottom
				anchors.topMargin: 2
				x: 2
				visible: container.children[0].y / ((-35 * (index + 1)) + 1) >= 1 ? false : true
				textVisible: (modelSelected === diagMCUModel) ? ((canErrorMCUSoftPartNum && index===2) || (canErrorMCUSoftVersion && index===3)) ? blinkingPictoIsVisible : true : true
				isCheckbox: modelSelected === hourMeterResetModel || modelSelected === diagFactoryresetModel || modelSelected === resetModel || modelSelected === opTimeResetModel || index >= modelSelected.nbItems ? false : true
				opacity: modelSelected === dateTimeModeModel && dateTimeModeModel.sources[index] ? dateTimeModeModel.sources[index].opacity : 1
			}
		}
	}
}



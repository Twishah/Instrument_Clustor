import QtQuick 2.11
import MyQmlModule 1.0
import QtGraphicalEffects 1.0
import QtQuick.Controls 2.4
import "../components"

Flickable {
	id: listLargeStatusID

	width: parent.width
	height: parent.height
	anchors.topMargin: backEnd.currentConfig.headerHeight
	contentWidth: listLargeStatusID.width
	contentHeight: heightItem * lengthItems // calculate container height to fit all items

	boundsBehavior: Flickable.StopAtBounds

	Keys.forwardTo: controller

	property double currentIndex: 0
	property double selectedIndex: 0
	property double lengthItems: 4
	property double heightItem: 71

	// CAN values for Maintenance Mode: History
	property string date1_engineLubricatingOilMCU: ""
	property string date2_engineLubricatingOilMCU: ""
	property double hourmeter1_engineLubricatingOilMCU: 0
	property double hourmeter2_engineLubricatingOilMCU: 0
	property string date1_engineOilFilterMCU: ""
	property string date2_engineOilFilterMCU: ""
	property double hourmeter1_engineOilFilterMCU: 0
	property double hourmeter2_engineOilFilterMCU: 0
	property string date1_engineIntakeAirFilterMCU: ""
	property string date2_engineIntakeAirFilterMCU: ""
	property double hourmeter1_engineIntakeAirFilterMCU: 0
	property double hourmeter2_engineIntakeAirFilterMCU: 0
	property string date1_fuelFilterMCU: ""
	property string date2_fuelFilterMCU: ""
	property double hourmeter1_fuelFilterMCU: 0
	property double hourmeter2_fuelFilterMCU: 0
	property string date1_hydraulicOilMCU: dm.get_maintenance_history(0).date1
	property string date2_hydraulicOilMCU: dm.get_maintenance_history(0).date2
	property double hourmeter1_hydraulicOilMCU: dm.get_maintenance_history(0).hourMeter1
	property double hourmeter2_hydraulicOilMCU: dm.get_maintenance_history(0).hourMeter2
	property string date1_hydraulicOilRetFilterMCU: dm.get_maintenance_history(1).date1
	property string date2_hydraulicOilRetFilterMCU: dm.get_maintenance_history(1).date2
	property double hourmeter1_hydraulicOilRetFilterMCU: dm.get_maintenance_history(1).hourMeter1
	property double hourmeter2_hydraulicOilRetFilterMCU: dm.get_maintenance_history(1).hourMeter2
	property string date1_hydraulicOilRetLineFilterMCU: dm.get_maintenance_history(2).date1
	property string date2_hydraulicOilRetLineFilterMCU: dm.get_maintenance_history(2).date2
	property double hourmeter1_hydraulicOilRetLineFilterMCU: dm.get_maintenance_history(2).hourMeter1
	property double hourmeter2_hydraulicOilRetLineFilterMCU: dm.get_maintenance_history(2).hourMeter2
	property string date1_travelReductionOilMCU: dm.get_maintenance_history(3).date1
	property string date2_travelReductionOilMCU: dm.get_maintenance_history(3).date2
	property double hourmeter1_travelReductionOilMCU: dm.get_maintenance_history(3).hourMeter1
	property double hourmeter2_travelReductionOilMCU: dm.get_maintenance_history(3).hourMeter2

	onVisibleChanged: {

		if(visible === true) {
			console.log("Page PG_listLargeStatusBar entered")
		}
	}

	function resetIndexes() {
		currentIndex = 0
		selectedIndex = 0
		contentY = 0
	}

	// To enter into the list of Maintenance History
	function selectMaintenanceHistoryList() {
		listLargeStatusID.lengthItems = isV7 ? 9 : 6
		resetIndexes()
	}

	function updateMaintenanceHistory(ind) {
		var dayValue = dateTimeManager.getDay() < 10 ? "0" + dateTimeManager.getDay().toString() : dateTimeManager.getDay().toString()
		var monthValue = dateTimeManager.getMonth() < 10 ? "0" + dateTimeManager.getMonth().toString() : dateTimeManager.getMonth().toString()
		var yearValue = dateTimeManager.getYear().toString()
		var hourMeterLocal = (dataEngine.opHours_Total.value > maxHourMeter ? maxHourMeter
																			: (dataEngine.opHours_Total.value < 0.0 ? 0
																													: dataEngine.opHours_Total.value))

		if (containerMaintenanceHistory.date2[ind] === "") {
			// First time
			if (containerMaintenanceHistory.date1[ind] === "") {
				dm.get_maintenance_history(ind).date1 = dayValue + "." + monthValue + "." + yearValue
				dm.get_maintenance_history(ind).hourMeter1 = parseInt(hourMeterLocal)
			}
			// Second time
			else {
				dm.get_maintenance_history(ind).date2 = dayValue + "." + monthValue + "." + yearValue
				dm.get_maintenance_history(ind).hourMeter2 = parseInt(hourMeterLocal)
			}
		}
		// Others
		else {
			dm.get_maintenance_history(ind).date1 = dm.get_maintenance_history(ind).date2
			dm.get_maintenance_history(ind).hourMeter1 = parseInt(dm.get_maintenance_history(ind).hourMeter2)
			dm.get_maintenance_history(ind).date2 = dayValue + "." + monthValue + "." + yearValue
			dm.get_maintenance_history(ind).hourMeter2 = parseInt(hourMeterLocal)
		}

		dm.save_maintenance_history()
	}

	function resetAllHistory() {
		for (var i = 0; i < lengthItems; i++) {
			dm.get_maintenance_history(i).date1 = ""
			dm.get_maintenance_history(i).hourMeter1 = 0
			dm.get_maintenance_history(i).date2 = ""
			dm.get_maintenance_history(i).hourMeter2 = 0
		}
		dm.save_maintenance_history()
	}

	function menuPressed()
	{
		if (startupInfo.isManualStartMode()) {
			pg_home2.restartTimeoutTimer()
		}

		if (backEnd.state === MyAppState.MM_1_HISTORY) {
			backEnd.setState(MyAppState.MAINTENANCE)
			backEnd.setCurrentPage(pg_largeList)
			pg_largeList.verifyMaintenanceElapsedTime()
			pg_listLargeStatusBar.visible = false
			pgHeader.titleString = qsTrId("LBL_0057") + translator.emptyString
			pg_largeList.visible = true
			console.log("Maintenance mode page selected")
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
			pg_listLargeStatusBar.visible = false
			pgHeader.visible = false
			pg_menu.visible = true
			rectList.visible = false
			rectMenu.visible = true

			//resetIndexes()
		}
	}

	function upPressed()
	{
		if (startupInfo.isManualStartMode()) {
			pg_home2.restartTimeoutTimer()
		}

		listLargeStatusID.currentIndex = (listLargeStatusID.currentIndex - 1 + listLargeStatusID.lengthItems) % listLargeStatusID.lengthItems
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

		listLargeStatusID.currentIndex = (listLargeStatusID.currentIndex + 1) % listLargeStatusID.lengthItems
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
	}


	Column  {
		id: containerMaintenanceHistory
		width: parent.width
		height: parent.height
		visible: backEnd.state === MyAppState.MM_1_HISTORY || pg_popUp.lastState === MyAppState.MM_1_HISTORY ? true : false

		property var date1 : [date1_engineLubricatingOilMCU, date1_engineOilFilterMCU, date1_engineIntakeAirFilterMCU, date1_fuelFilterMCU, date1_hydraulicOilMCU, date1_hydraulicOilRetFilterMCU, date1_hydraulicOilRetLineFilterMCU, date1_travelReductionOilMCU]
		property var date2 : [date2_engineLubricatingOilMCU, date2_engineOilFilterMCU, date2_engineIntakeAirFilterMCU, date2_fuelFilterMCU, date2_hydraulicOilMCU, date2_hydraulicOilRetFilterMCU, date2_hydraulicOilRetLineFilterMCU, date2_travelReductionOilMCU]
		property var hourmeter1 : [hourmeter1_engineLubricatingOilMCU, hourmeter1_engineOilFilterMCU, hourmeter1_engineIntakeAirFilterMCU, hourmeter1_fuelFilterMCU, hourmeter1_hydraulicOilMCU, hourmeter1_hydraulicOilRetFilterMCU, hourmeter1_hydraulicOilRetLineFilterMCU, hourmeter1_travelReductionOilMCU]
		property var hourmeter2 : [hourmeter2_engineLubricatingOilMCU, hourmeter2_engineOilFilterMCU, hourmeter2_engineIntakeAirFilterMCU, hourmeter2_fuelFilterMCU, hourmeter2_hydraulicOilMCU, hourmeter2_hydraulicOilRetFilterMCU, hourmeter2_hydraulicOilRetLineFilterMCU, hourmeter2_travelReductionOilMCU]
		property var iconSources: isV7 ? ["qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 55X55/6.94_Engine lubricating oil_WH.png",
										  "qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 55X55/6.93_Engine oil filter_WH.png",
										  "qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 55X55/6.91_Engine intake air filter_WH.png",
										  "qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 55X55/6.90_Fuel filter_WH.png",
										  "qrc:/graphics/MaintenanceMode/7.71 Hydraulic oil - white.png",
										  "qrc:/graphics/MaintenanceMode/7.74 Hydraulic oil return filter - white.png",
										  "qrc:/graphics/MaintenanceMode/7.74 Hydraulic oil return filter - white.png",
										  "qrc:/graphics/MaintenanceMode/7.77 Travel reduction oil - white.png",
										  "qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 55X55/6.92_Road vehicle, filter_WH.png"]
										: ["qrc:/graphics/MaintenanceMode/7.71 Hydraulic oil - white.png",
										   "qrc:/graphics/MaintenanceMode/7.74 Hydraulic oil return filter - white.png",
										   "qrc:/graphics/MaintenanceMode/7.74 Hydraulic oil return filter - white.png",
										   "qrc:/graphics/MaintenanceMode/7.77 Travel reduction oil - white.png",
										   "qrc:/graphics/02_Main_Icons PNG/02_Main_Icons PNG 55x55/2.91_Main battery_wh.png",
										   "qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 55X55/6.147_Electric_Power_WH.png"]

		Rectangle { //designFix
			width: 300
			height: 1
			color: color_gray_bar
		}

		Repeater {
			model: listLargeStatusID.lengthItems
			Comp_listItemLargeStatusBarIcon {
				id: listMaintenance
				iconPict: containerMaintenanceHistory.iconSources[index]
				isCurrent:  listLargeStatusID.currentIndex === index ? true : false
				leftText1: containerMaintenanceHistory.date1[index]
				leftText2: containerMaintenanceHistory.date2[index]
				rightText1: containerMaintenanceHistory.date1[index] !== "" ? containerMaintenanceHistory.hourmeter1[index] + "h" : ""
				rightText2: containerMaintenanceHistory.date2[index] !== "" ? containerMaintenanceHistory.hourmeter2[index] + "h" : ""
			}
		}
	}
}

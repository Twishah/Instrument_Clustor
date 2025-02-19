import QtQuick 2.6
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.4
import QtGraphicalEffects 1.0
import CrossControl 1.0
import MyQmlModule 1.0
import "../components"

Rectangle {
	id: gridID

	color: color_gray
	visible: false

	// Keep track of the currently selected menu item
	property int selectIndex: 0

	// Manage light menu for hour version mode
	property bool isLight: false

	// Current Menu Items characteristics
	property var menuSelected: menuItems

	//List of menu items
	property var menuItems: [
		{ name: "qrc:/graphics/Menu/7.33 Display settings - white.png", selectFunction: selectDisplaySettings, isVisible: 1 },
		{ name: "qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 70x70/6.55_Vehicle settings_wh.png", selectFunction: selectVehicleSettings, isVisible: 1},
		{ name: "qrc:/graphics/Menu/7.35 PTO settings - white.png", selectFunction: selectPtoSettings, isVisible: 1},
		{ name: "qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 70x70/6.57_Monitoring mode_WH.png", selectFunction: selectMonitorMode, isVisible: btnMenuMonitorVisible},
		{ name: "qrc:/graphics/Menu/7.37 Operational management mode - white.png", selectFunction: selectOpManagMode, isVisible: 1},
		{ name: "qrc:/graphics/Menu/7.38 Maintenance mode - white.png", selectFunction: selectMaintenanceMode, isVisible: btnMenuMaintenanceVisible },
		{ name: "qrc:/graphics/Menu/7.39 Error history - white.png", selectFunction: selectErrorHistory, isVisible: 1},
		{ name: "qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 70x70/6.15_Lock WH.png", selectFunction: selectImmobilizerSettings, isVisible: btnMenuImmobilizerVisible },
		isV7 ? { name: "qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 70x70/6.61_Filter regeneration_WH.png", selectFunction: selectFilterRegeneration, isVisible: btnMenuFiltrRegenVisible} : { name: "qrc:/graphics/Menu/7.40 Pre-heating settings - white.png", selectFunction: selectPreHeating, isVisible: btnMenuHeatingVisible}

	]

	//List of menu items in light mode
	property var lightMenuItems: [
		{ name: "qrc:/graphics/MechanicMode/7.37 Operational management mode - white.png", selectFunction: selectOpManagMode, isVisible: 1 },
		{ name: "qrc:/graphics/MechanicMode/7.38 Maintenance mode - white.png", selectFunction: selectMaintenanceMode, isVisible: btnMenuMaintenanceVisible }
	]

	//List of menu items in the Mechanic Mode Level 1
	property var mechanicMenuItems1: [
		{ name: "qrc:/graphics/MechanicMode/7.82 PTO lock - white.png", selectFunction: selectAuxFlowLimitLock, isVisible: 1 },
		{ name: "qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 70x70/6.57_Monitoring mode_WH.png", selectFunction: selectMonitorMode, isVisible: btnMenuMonitorVisible },
		{ name: "qrc:/graphics/MechanicMode/7.38 Maintenance mode - white.png", selectFunction: selectMaintenanceMode, isVisible: btnMenuMaintenanceVisible },
		{ name: "qrc:/graphics/MechanicMode/7.37 Operational management mode - white.png", selectFunction: selectOpManagMode, isVisible: 1 },
		{ name: "qrc:/graphics/MechanicMode/7.39 Error history - white.png", selectFunction: selectErrorHistory, isVisible: 1 }
	]

	//List of menu items in the Mechanic Mode Level 2
	property var mechanicMenuItems2: [
		{ name: "qrc:/graphics/MechanicMode/7.82 PTO lock - white.png", selectFunction: selectAuxFlowLimitLock, isVisible: 1 },
		{ name: "qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 70x70/6.57_Monitoring mode_WH.png", selectFunction: selectMonitorMode, isVisible: btnMenuMonitorVisible },
		{ name: "qrc:/graphics/MechanicMode/7.38 Maintenance mode - white.png", selectFunction: selectMaintenanceMode, isVisible: btnMenuMaintenanceVisible },
		{ name: "qrc:/graphics/MechanicMode/7.37 Operational management mode - white.png", selectFunction: selectOpManagMode, isVisible: 1 },
		{ name: "qrc:/graphics/MechanicMode/7.39 Error history - white.png", selectFunction: selectErrorHistory, isVisible: 1 },
		{ name: "qrc:/graphics/MechanicMode/7.83 History mechanic mode - white.png", selectFunction: selectUsageHistory, isVisible: 1 },
		{ name: "qrc:/graphics/MechanicMode/7.84 Diagnostic mode - white.png", selectFunction: selectDiagnosticMode, isVisible: 1 },
		{ name: "qrc:/graphics/MechanicMode/7.85 Reset hourmeter - white.png", selectFunction: selectResetHourMeter, isVisible: 1 }
	]

	//List of menu items in the Diagnostic Mode
	property var diagnosticMenuItems: [
		{ name: "qrc:/graphics/MechanicMode/7.86 Instrument display - white.png", selectFunction: selectInstrumentDisplay, isVisible: 1 },
		{ name: "qrc:/graphics/MechanicMode/7.87 Main control unit - white.png", selectFunction: selectMCU, isVisible: btnDiagMCUVisible },
		{ name: "qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 55X55/6.133_ECU_Battery_WH.png", selectFunction: selectBatteryECU, isVisible: btnDiagECUVisible },
		{ name: "qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 55X55/6.132_TCU_WH.png", selectFunction: selectTCU, isVisible: btnDiagTCUVisible },
		{ name: "qrc:/graphics/MechanicMode/7.88 Diagnostic main control unit - white.png", selectFunction: selectDiagMCU, isVisible: btnDiagMCUVisible },
		{ name: "qrc:/graphics/MechanicMode/7.89 Reset - white.png", selectFunction: selectFactoryReset, isVisible: 1 },
	]

	//List of menu items in the Mechanic Mode Level 2 WITHOUT reset hour meter
	property var mechanicMenuItems2simplified: [
		{ name: "qrc:/graphics/MechanicMode/7.82 PTO lock - white.png", selectFunction: selectAuxFlowLimitLock, isVisible: 1 },
		{ name: "qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 70x70/6.57_Monitoring mode_WH.png", selectFunction: selectMonitorMode, isVisible: btnMenuMonitorVisible },
		{ name: "qrc:/graphics/MechanicMode/7.38 Maintenance mode - white.png", selectFunction: selectMaintenanceMode, isVisible: btnMenuMaintenanceVisible },
		{ name: "qrc:/graphics/MechanicMode/7.37 Operational management mode - white.png", selectFunction: selectOpManagMode, isVisible: 1 },
		{ name: "qrc:/graphics/MechanicMode/7.39 Error history - white.png", selectFunction: selectErrorHistory, isVisible: 1 },
		{ name: "qrc:/graphics/MechanicMode/7.83 History mechanic mode - white.png", selectFunction: selectUsageHistory, isVisible: 1 },
		{ name: "qrc:/graphics/MechanicMode/7.84 Diagnostic mode - white.png", selectFunction: selectDiagnosticMode, isVisible: 1 }
	]
	property bool isMenu2simplified:  controller.isMechanicMode2 ? dataEngine.opHours_Total.value > 10.0 ? true : false : false

	//List of menu items simplified (WITHOUT preheating option)
	property var menuItemsSimplified: [
		{ name: "qrc:/graphics/Menu/7.33 Display settings - white.png", selectFunction: selectDisplaySettings, isVisible: 1 },
		{ name: "qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 70x70/6.55_Vehicle settings_wh.png", selectFunction: selectVehicleSettings, isVisible: 1},
		{ name: "qrc:/graphics/Menu/7.35 PTO settings - white.png", selectFunction: selectPtoSettings, isVisible: 1},
		{ name: "qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 70x70/6.57_Monitoring mode_WH.png", selectFunction: selectMonitorMode, isVisible: btnMenuMonitorVisible},
		{ name: "qrc:/graphics/Menu/7.37 Operational management mode - white.png", selectFunction: selectOpManagMode, isVisible: 1},
		{ name: "qrc:/graphics/Menu/7.38 Maintenance mode - white.png", selectFunction: selectMaintenanceMode, isVisible: btnMenuMaintenanceVisible },
		{ name: "qrc:/graphics/Menu/7.39 Error history - white.png", selectFunction: selectErrorHistory, isVisible: 1},
		isV7 ? { name: "qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 70x70/6.61_Filter regeneration_WH.png", selectFunction: selectFilterRegeneration, isVisible: btnMenuFiltrRegenVisible} : { name: "qrc:/graphics/Menu/7.40 Pre-heating settings - white.png", selectFunction: selectPreHeating, isVisible: btnMenuHeatingVisible},
		{ name: "qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 70x70/6.15_Lock WH.png", selectFunction: selectImmobilizerSettings, isVisible: btnMenuImmobilizerVisible }


	]
	property bool isPreheating: optPreheatingAtStartup

	onVisibleChanged: {
		if (pg_menu.visible)
		{
			if (controller.isMechanicMode1 || controller.isMechanicMode2) {
				controller.stopAutoSwitchMechanicMenu()
			}
		}
		else {
			if (controller.isMechanicMode1 || controller.isMechanicMode2) {
				controller.startAutoSwitchMechanicMenu()
			}
		}

		if (backEnd.state === MyAppState.MENU_HOUR_METER) {
			menuSelected = lightMenuItems
			isLight = true
		}
		else if(backEnd.state === MyAppState.DIAGNOSTIC_MODE){
			menuSelected = diagnosticMenuItems
		}
		else if (controller.isMechanicMode1) {
			menuSelected = mechanicMenuItems1
		}
		else if (controller.isMechanicMode2) {
			if (isMenu2simplified) {
				menuSelected = mechanicMenuItems2simplified
			}
			else {
				menuSelected = mechanicMenuItems2
			}
		}
		else {
			if (isPreheating) {
				menuSelected = menuItems
			}
			else {
				menuSelected = menuItemsSimplified
			}
			isLight = false
		}
	}

	// To change show Preheating Option in Menu or not
	onIsPreheatingChanged: {
		if (isPreheating) {
			menuSelected = menuItems
		}
		else {
			dm.getPreHeating().active = isPreheating
			dm.savePreHeatingSettings()
			menuSelected = menuItemsSimplified
			if (selectIndex > (menuSelected.length - 1)) {
				resetIndex()
			}
		}
	}

	onIsMenu2simplifiedChanged: {
		if (isMenu2simplified) {
			menuSelected = mechanicMenuItems2simplified
			if (selectIndex > (menuSelected.length - 1)) {
				resetIndex()
			}
		}
		else {
			if (controller.isMechanicMode2) {
				menuSelected = mechanicMenuItems2
			}
		}
	}

	function showPage(pageToShow)
	{
		pg_menu.visible = false;
		pageToShow.visible = true;

		if (pageToShow === pg_home || pageToShow === pg_home2) {
			rectList.visible = false;
			rectMenu.visible = false;
		}
		else if (pageToShow === pg_menu) {
			rectList.visible = false;
			rectMenu.visible = true;
		}
		else {
			rectList.visible = true;
			rectMenu.visible = false;
		}
	}

	function selectMenuItems() {
		if (backEnd.state === MyAppState.MENU_HOUR_METER) {
			menuSelected = lightMenuItems
			isLight = true
		}
		else if(backEnd.state === MyAppState.DIAGNOSTIC_MODE){
			menuSelected = diagnosticMenuItems
		}
		else if (controller.isMechanicMode1) {
			menuSelected = mechanicMenuItems1
		}
		else if (controller.isMechanicMode2) {
			if (isMenu2simplified) {
				menuSelected = mechanicMenuItems2simplified
			}
			else {
				menuSelected = mechanicMenuItems2
			}
		}
		else {
			if (isPreheating) {
				menuSelected = menuItems
			}
			else {
				menuSelected = menuItemsSimplified
			}
			isLight = false
		}
		//resetIndex() // We dont want to reset index
	}

	// To reset the indexes everytime that we open this page
	function resetIndex() {
		selectIndex = 0
	}

	function selectNothing() {
		console.log("Submenu blocked.")
	}

	function selectDiagnosticMode() {
		backEnd.setState(MyAppState.DIAGNOSTIC_MODE)
		console.log("Diagnostic Mode page selected")
		backEnd.setCurrentPage(pg_menu)

		pg_menu.selectMenuItems()
		selectIndex = 0;

		pgHeader.visible = false
		pgHeader.mainMenu = false
	}

	function selectInstrumentDisplay() {
		backEnd.setState(MyAppState.DM_1_INSTRUMENT)
		console.log("Instrument Display page selected")
		backEnd.setCurrentPage(pg_listIcon)
		pg_listIcon.selectDiagInstrumentDisplayModel()
		showPage(pg_listIcon);

		pgHeader.visible = true
		pgHeader.mainMenu = false
		pgHeader.titleString = qsTrId("LBL_0079") + translator.emptyString

	}

	function selectMCU() {
		backEnd.setState(MyAppState.DM_1_MAIN_CONTROL)
		console.log("MCU page selected")
		backEnd.setCurrentPage(pg_listIcon)
		pg_listIcon.selectDiagMCUModel()
		showPage(pg_listIcon);

		pgHeader.visible = true
		pgHeader.mainMenu = false
		pgHeader.titleString = qsTrId("LBL_0080") + translator.emptyString
	}

	function selectBatteryECU() {
		backEnd.setState(MyAppState.DM_1_BATTERY_ECU)
		console.log("Battery ECU page selected")
		backEnd.setCurrentPage(pg_listIcon)
		pg_listIcon.selectDiagBattECUModel()
		showPage(pg_listIcon);

		pgHeader.visible = true
		pgHeader.mainMenu = false
		pgHeader.titleString = isV7 ? qsTrId("LBL_0330") + translator.emptyString : qsTrId("LBL_0333") + translator.emptyString
	}

	function selectTCU() {
		backEnd.setState(MyAppState.DM_1_TCU)
		console.log("TCU page selected")
		backEnd.setCurrentPage(pg_listIcon)
		pg_listIcon.selectDiagTCUModel()
		showPage(pg_listIcon);

		pgHeader.visible = true
		pgHeader.mainMenu = false
		pgHeader.titleString = qsTrId("LBL_0331") + translator.emptyString
	}

	function selectDiagMCU() {
		backEnd.setState(MyAppState.DM_1_DIAG_MAIN_CONTROL)
		console.log("Diag MCU page selected")
		backEnd.setCurrentPage(pg_listStatusBar)
		pg_listStatusBar.selectMCUList();
		showPage(pg_listStatusBar);

		pgHeader.visible = true
		pgHeader.mainMenu = false
		pgHeader.titleString = qsTrId("LBL_0081") + translator.emptyString
	}

	function selectFactoryReset() {
		backEnd.setState(MyAppState.DM_1_RESET)
		console.log("Factory reset page selected")
		backEnd.setCurrentPage(pg_listIcon)
		showPage(pg_listIcon);

		pgHeader.visible = true
		pgHeader.mainMenu = false
		pgHeader.titleString = qsTrId("LBL_0092") + translator.emptyString
		pg_listIcon.selectFactorySettingsModel()
	}

	function selectDisplaySettings() {
		backEnd.setState(MyAppState.DISPLAY_SET)
		console.log("Display Settings page selected")
		backEnd.setCurrentPage(pg_largeList)
		pg_largeList.selectDisplaySettingsModel(true);
		showPage(pg_largeList);

		pgHeader.visible = true
		pgHeader.mainMenu = false
		pgHeader.titleString = qsTrId("LBL_0005") + translator.emptyString
	}

	function selectVehicleSettings() {
		backEnd.setState(MyAppState.VEHICULE_SET)
		console.log("Vehicle Settings page selected")
		backEnd.setCurrentPage(pg_listStatusBar)
		showPage(pg_listStatusBar);

		pgHeader.visible = true
		pgHeader.mainMenu = false
		pgHeader.titleString = qsTrId("LBL_0025") + translator.emptyString

		pg_listStatusBar.selectVehicleSettingsList()
	}

	function selectPtoSettings() {
		backEnd.setState(MyAppState.PTO_SET)
		console.log("PTO Settings page selected")
		backEnd.setCurrentPage(pg_lineStatusBarIcon)
		pg_lineStatusBarIcon.updatePtoSetInd()
		showPage(pg_lineStatusBarIcon)

		pgHeader.visible = true
		pgHeader.mainMenu = false
		pgHeader.titleString = qsTrId("LBL_0029") + translator.emptyString
	}

	function selectMonitorMode() {
		backEnd.setState(MyAppState.MONITOR)
		console.log("Monitor Mode page selected")
		backEnd.setCurrentPage(pg_listStatusBar)
		showPage(pg_listStatusBar);

		pgHeader.visible = true
		pgHeader.mainMenu = false
		pgHeader.titleString = qsTrId("LBL_0037") + translator.emptyString

		pg_listStatusBar.selectMonitorModeList()
	}

	function selectOpManagMode() {
		backEnd.setState(MyAppState.OP_MANAGEMENT)
		console.log("Operational Management Mode page selected")
		backEnd.setCurrentPage(pg_largeList)
		pg_largeList.selectOperationalManagementModel();
		showPage(pg_largeList);

		pgHeader.visible = true
		pgHeader.mainMenu = false
		pgHeader.titleString = qsTrId("LBL_0038") + translator.emptyString
	}

	function selectMaintenanceMode() {
		backEnd.setState(MyAppState.MAINTENANCE)
		console.log("Maintenance Mode page selected")
		backEnd.setCurrentPage(pg_largeList)
		pg_largeList.selectMaintenanceModel()
		pg_largeList.verifyMaintenanceElapsedTime()
		showPage(pg_largeList);

		pgHeader.visible = true
		pgHeader.mainMenu = false
		pgHeader.titleString = qsTrId("LBL_0057") + translator.emptyString
	}

	function selectErrorHistory() {
		backEnd.setState(MyAppState.ERROR_HISTORY)
		console.log("Error history page selected")
		backEnd.setCurrentPage(pg_list)
		showPage(pg_list);

		pgHeader.visible = true
		pgHeader.mainMenu = false
		pgHeader.titleString = qsTrId("LBL_0326") + translator.emptyString

	}

	function selectPreHeating() {
		backEnd.setState(MyAppState.PRE_HEATING)
		console.log("Pre Heating page selected")
		backEnd.setCurrentPage(pg_preHeating)
		showPage(pg_preHeating);

		pgHeader.visible = true
		pgHeader.mainMenu = false
		pgHeader.titleString = qsTrId("LBL_0063") + translator.emptyString

		pg_preHeating.resetIndexes()
	}

	function selectImmobilizerSettings() {
		backEnd.setState(MyAppState.IMMOBILIZER_SETTINGS)
		console.log("Immobilizer settings")
		backEnd.setCurrentPage(pg_listStatusBar)
		showPage(pg_listStatusBar);
		pg_listStatusBar.selectImmobilizerSettingsList()
		pgHeader.visible = true
		pgHeader.mainMenu = false
		pgHeader.titleString = qsTrId("LBL_0328") + translator.emptyString
	}

	function selectAuxFlowLimitLock() {
		backEnd.setState(MyAppState.FLOW_LIMIT_LOCK)
		console.log("Aux Flow Limit Lock page selected")
		backEnd.setCurrentPage(pg_listIcon)
		showPage(pg_listIcon);
		pg_listIcon.selectAuxFlowLimitLockModel()

		pgHeader.visible = true
		pgHeader.mainMenu = false
		pgHeader.titleString = qsTrId("LBL_0075") + translator.emptyString

		if(canErrorAny === true)
		{
			dm.indexLockState = 1 // unlock if can error
			dm.saveLockSate()
		}
	}

	function selectResetHourMeter() {
		backEnd.setState(MyAppState.RESET_HOUR_METER)
		console.log("Reset Hour Meter page selected")
		backEnd.setCurrentPage(pg_listIcon)
		pg_listIcon.selectResetHourMeterModel()
		showPage(pg_listIcon);

		pgHeader.visible = true
		pgHeader.mainMenu = false
		pgHeader.titleString = qsTrId("LBL_0093") + translator.emptyString
	}

	function selectUsageHistory() {
		backEnd.setState(MyAppState.MECA_MODE_HISTORY)
		console.log("Mechanic Mode History page selected")
		backEnd.setCurrentPage(pg_listMechanic)
		showPage(pg_listMechanic)

		pgHeader.titleString = qsTrId("LBL_0327") + translator.emptyString
		pgHeader.visible = true
		pgHeader.mainMenu = false

		//pg_listMechanic.resetAllUsageHistory()
		pg_listMechanic.calculateNbItems()
		pg_listMechanic.resetIndexes()
	}

	function selectFilterRegeneration()
	{
		backEnd.setState(MyAppState.FILTER_REGENERATION)
		console.log("Filter Regeneration page selected")
		backEnd.setCurrentPage(pg_listStatusBar)
		showPage(pg_listStatusBar);

		pgHeader.visible = true
		pgHeader.mainMenu = false
		pgHeader.titleString = qsTrId("LBL_0353") + translator.emptyString

		pg_listStatusBar.selectFilterRegeneration()
	}

	function menuPressed()
	{
		if(backEnd.state === MyAppState.DIAGNOSTIC_MODE) {
			controller.selectMechanicModeL2()
			selectIndex = 6 // diagnostic mode cell
		}
		else if (backEnd.state === MyAppState.MENU_MECA_1 || backEnd.state === MyAppState.MENU_MECA_2) {

			// Disable mechanic mode
			controller.disableMechanicMode()

			// Go back to home page
			backEnd.setState(MyAppState.MAIN)
			backEnd.setCurrentPage(pg_home)
			pg_menu.visible = false
			pg_home.visible = true
			rectList.visible = false
			rectMenu.visible = false
			pgHeader.visible = true
			pgHeader.mainMenu = true
		}
		else if (backEnd.state === MyAppState.MENU) {
			// View default page
			backEnd.setState(MyAppState.MAIN)
			backEnd.setCurrentPage(pg_home)
			pg_menu.visible = false
			pg_home.visible = true
			rectList.visible = false
			rectMenu.visible = false
			pgHeader.visible = true
			pgHeader.mainMenu = true
		}
		else if (backEnd.state === MyAppState.MENU_HOUR_METER) {
			pg_home2.restartTimeoutTimer()
			backEnd.setState(MyAppState.MAIN_HOUR_METER)
			backEnd.setCurrentPage(pg_home2)
			pg_menu.visible = false
			pg_home2.visible = true
			pgHeader.visible = false
			pgHeader.mainMenu = true
		}
	}

	function upPressed()
	{
		selectIndex = (selectIndex - 1 + menuSelected.length) % menuSelected.length;
		if (backEnd.state === MyAppState.MENU_HOUR_METER) {
			pg_home2.restartTimeoutTimer()
		}
	}

	function downPressed()
	{
		selectIndex = (selectIndex + 1) % menuSelected.length;
		if (backEnd.state === MyAppState.MENU_HOUR_METER) {
			pg_home2.restartTimeoutTimer()
		}
	}

	function enterPressed()
	{
		if (backEnd.state === MyAppState.MENU_HOUR_METER) {
			pg_home2.restartTimeoutTimer()
		}
		if (menuSelected[selectIndex].selectFunction && menuSelected[selectIndex].isVisible === 1)
		{
			menuSelected[selectIndex].selectFunction();
		}
	}

	// Layout for menu items
	GridLayout {
		id: menuGrid
		anchors.fill: parent
		flow: GridLayout.TopToBottom
		columns: 3
		columnSpacing: 0
		rows: 3
		rowSpacing: 0

		// Create menu items
		Repeater {
			model: 9
			delegate:
			Rectangle {
				id: menuRect
				Layout.fillWidth: true
				Layout.fillHeight: true
				color: index === gridID.selectIndex ? color_blue : color_gray
				opacity:index >= menuSelected.length ? 1 : menuSelected[index].isVisible === 1 ? 1 : 1
				border.width: 1
				border.color: color_gray_bar
				radius: 2

				Button {
					id: menuItem
					Image {
						anchors.fill: parent
						source: index < menuSelected.length ? menuSelected[index].name : ""
						opacity: index < menuSelected.length ? ((menuSelected[index].isVisible === 1) ? 1 : 0.3) : 0.3
						fillMode: Image.Pad
					}

					background: Rectangle {
						implicitWidth: menuRect.width
						implicitHeight: menuRect.height
						color: "transparent"
					}

					//onClicked: navigateToSelectedItem()
					anchors.verticalCenter: parent.verticalCenter
					anchors.horizontalCenter: parent.horizontalCenter

				}
			}
		}
	}

	Timer {
		id: refreshTimer
		running: true
		interval: 1000
		repeat: true
		onTriggered: {
			if (backEnd.state === MyAppState.MENU_HOUR_METER) {
				menuSelected = lightMenuItems
				isLight = true
			}
			else if(backEnd.state === MyAppState.DIAGNOSTIC_MODE){
				menuSelected = diagnosticMenuItems
			}
			else if (controller.isMechanicMode1) {
				menuSelected = mechanicMenuItems1
			}
			else if (controller.isMechanicMode2) {
				if (isMenu2simplified) {
					menuSelected = mechanicMenuItems2simplified
				}
				else {
					menuSelected = mechanicMenuItems2
				}
			}
			else {
				if (isPreheating) {
					menuSelected = menuItems
				}
				else {
					menuSelected = menuItemsSimplified
				}
				isLight = false
			}
		}
	}
}

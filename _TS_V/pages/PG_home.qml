/******************************************************************************
 * pg_home
******************************************************************************/

import QtQuick 2.6

import QtGraphicalEffects 1.0
import QtQuick.Layouts 1.3
import "../components"
import MyQmlModule 1.0

Item {
	id: homeID

	property bool autoControlActive: false
	property int autoControlDuration: 2500
	property bool autoControlDone: false
	property bool toggle: true;
	property bool canErrorPTO_loc: canErrorPTO
	property int indexPTOsaved: dm.indexPTO

	property bool isV7_loc: isV7

	property bool isKmh: dm.speedUnitIsKmh

	onCanErrorPTO_locChanged: {
		if(canErrorPTO === true)
		{
			// if can error, set pto index to 0, but do not save it in the EEPROM
			indexPTOsaved = dm.indexPTO
			mainIndicators.currentIndexPtoSet = 0
			dm.indexPTO = 0
			mainIndicators.isChangingPtoSettings = false
			pg_lineStatusBarIcon.updatePtoSetInd()

			comp_navigationBar.isShowing = false
			//comp_navigationBar.isShowing = true // PC Emulation
			comp_navigationBar.isNavigationMode = false;
		}
		else
		{
			// if can error disappears, reset the PTO index to the saved one
			dm.indexPTO = indexPTOsaved
			mainIndicators.currentIndexPtoSet = indexPTOsaved
			pg_lineStatusBarIcon.updatePtoSetInd()
		}
	}

	onVisibleChanged: {

		if (pg_home.visible) {
			comp_navigationBar.hideEnter = true;
			comp_navigationBar.outsideMainMenu = false;
			controller.stopAutoSwitch();
			rectList.visible = false;
			rectMenu.visible = false;
		}
		else {
			if (!startupInfo.isManualStartMode()) {
				if (!controller.isMechanicMode1 && !controller.isMechanicMode2) {
					controller.startAutoSwitch();
				}
				if (pg_immobilizer.visible === true) {
					comp_navigationBar.outsideMainMenu = false;
				} else {
					comp_navigationBar.outsideMainMenu = true;
				}
			}
		}
	}

	function startAutoControl() {
		autoControlActive = true
		autoControlTimer.start()
		buzzerManager.buzzerPattern = 6;
	}

	function runAutocontrol()
	{
		autoControlTimer.start()
	}

	function increaseIndexPtoSetting() {
		if (mainIndicators.isChangingPtoSettings === true) {
			mainIndicators.currentIndexPtoSet = (mainIndicators.currentIndexPtoSet + 1) % 8
			if (mainIndicators.currentIndexPtoSet === 0) {
				mainIndicators.currentIndexPtoSet = 1;
			}
		}
		else {
			mainIndicators.isChangingPtoSettings = true
		}
	}

	function decreaseIndexPtoSetting() {
		if (mainIndicators.isChangingPtoSettings !== true) {
			mainIndicators.isChangingPtoSettings = true
		}
		mainIndicators.currentIndexPtoSet = (mainIndicators.currentIndexPtoSet - 1 + 8) % 8
		if (mainIndicators.currentIndexPtoSet === 0) {
			mainIndicators.currentIndexPtoSet = 7;
		}
	}

	function validatePtoSetting() {
		mainIndicators.saveIndexPtoSetting()
		mainIndicators.isChangingPtoSettings = false
		pg_lineStatusBarIcon.updatePtoSetInd()

		comp_navigationBar.isShowing = false
		//comp_navigationBar.isShowing = true // PC Emulation
		comp_navigationBar.isNavigationMode = false;

		pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5);
	}

	function revertPtoSetting(mustHide) {
		mainIndicators.revertIndexPtoSetting()
		mainIndicators.isChangingPtoSettings = false
		if (pg_home.visible && mustHide) {
			comp_navigationBar.hideEnter = true
		}
	}

	function updatePtoSetting() {
		mainIndicators.currentIndexPtoSet = mainIndicators.selectedIndexPtoSet
		if (mainIndicators.currentIndexPtoSet !== 0)
		{
			mainIndicators.ptoSettingIconSrc = dm.getPtoSettings(mainIndicators.currentIndexPtoSet - 1).accessory_icon_source
		}
		else {
		   mainIndicators.ptoSettingIconSrc = ""
		}
	}

	function menuPressed() {
		if(     (controller.upButtonPressed === false)
		   &&   (controller.downButtonPressed === false)
		   &&   (controller.enterButtonPressed === false)
				)
		{
			console.log("controller.upButtonPressed: " + controller.upButtonPressed)
			console.log("controller.downButtonPressed: " + controller.downButtonPressed)
			console.log("controller.enterButtonPressed: " + controller.enterButtonPressed)
			backEnd.setState(MyAppState.MENU)
			console.log("Menu page selected")
			pg_home.visible = false;
			pg_menu.selectMenuItems();
			pg_menu.visible = true;
			backEnd.setCurrentPage(pg_menu);
			pgHeader.visible = false
			pg_home.revertPtoSetting(true)
			rectList.visible = false
			rectMenu.visible = true
		}
	}

	function upPressed()
	{
		if(     (controller.downButtonPressed === false)
		   &&   (controller.enterButtonPressed === false)
		   &&   (controller.menuButtonPressed === false)
				)
		{
			pg_home.increaseIndexPtoSetting()
		}
	}

	function downPressed()
	{
		if(     (controller.upButtonPressed === false)
		   &&   (controller.enterButtonPressed === false)
		   &&   (controller.menuButtonPressed === false)
				)
		{
			if(!comp_navigationBar.hideEnter)
				pg_home.decreaseIndexPtoSetting();
		}
	}

	function enterPressed()
	{
		if(     (controller.upButtonPressed === false)
		   &&   (controller.downButtonPressed === false)
		   &&   (controller.menuButtonPressed === false)
				)
		{
			if(!comp_navigationBar.hideEnter){
				pg_home.validatePtoSetting()
				comp_navigationBar.hideEnter = true;
			} else if (errorManager.getCurrentErrorLength() > 0) {
				backEnd.setState(MyAppState.LIST)
				backEnd.setCurrentPage(pg_list)
				pg_list.visible = true
				pg_home.visible = false

				pgHeader.visible = true
				pgHeader.mainMenu = false
				pgHeader.titleString = qsTrId("LBL_0003") + translator.emptyString
				comp_navigationBar.hideEnter = false;

				rectList.visible = true;
				rectMenu.visible = false;
			}
		}
	}

	Timer {
		id: autoControlTimer
		interval: autoControlDuration
		running: false
		repeat: false // only once
		onTriggered: {
			autoControlActive = false;
			autoControlDone = true
		}
	}

	// Component of the main indicators, same Component for both V7 and V8e versions
	Comp_mainIndicators {
		id: mainIndicators
		mainMenu: true
	}

	// Component of the velocity gauge, same Component for both V7 and V8e versions
	Comp_velocityGaugeControl {
		id: powerGauge
		mainMenu: true
	}

	// Component of the capacity gauge, same Component for both V7 and V8e versions
	Comp_capacityGauge {
		id: leftGauge
		mainMenu: true
	}

	// Component of the consumption gauge, needed for the V8e version
	Comp_consumptionGauge {
		id: consumptionGauge
		mainMenu: true
		visible:  !parent.isV7_loc
	}

	// Component of the temperature gauge, needed for the V7 version
	Comp_temperatureGauge {
		id: temperatureGauge
		mainMenu: true
		visible:  parent.isV7_loc
	}

	// Component of the warning pictos (bottom list) for the V7
	Comp_arrayWarningPictos {
		id: warningPictos
		x: 0
		y: pgHeader.height
		visible:  parent.isV7_loc
	}

	// Component of the warning pictos (bottom list) for the V8e

	Comp_arrayWarningPictosV8e {
		id: warningPictosV8e
		x: 0
		y: pgHeader.height
		visible:  !parent.isV7_loc
	}

	// Component of the notice pictos (bottom list) for the V7
	Comp_arrayNoticePictos {
		id: noticePictos
		x: 0
		y: pgHeader.height + warningPictos.height + 116 + 5
		visible:  parent.isV7_loc
	}

	// Component of the notice pictos (bottom list) for the V8e
	Comp_arrayNoticePictosV8 {
		id: noticePictosV8e
		x: 0
		y: pgHeader.height + warningPictos.height + 116 + 5
		visible:  !parent.isV7_loc
	}

	Timer {
		id: updatePictoToggle

		running: autoControlActive? false : true
		repeat: true
		interval: 1000
		property int iteration: 0
		onTriggered: { // this timer sync all toogles from home pages
			toggle = !toggle // sync toggle for all picto
			if (isV7) {
				warningPictos.toggle = toggle;
				noticePictos.toggle = toggle;
			}
			else {
				warningPictosV8e.toggle = toggle;
				noticePictosV8e.toggle = toggle;

				if (pgHeader.mainMenu && iteration >= 2) { //sync switch op hour and time for V8
					if (dataEngine.remainingBatteryDisChargingTime.value > 0xFFAF) {
						RemainingTime.rtMCU = 0.0;
					}
					else {
						RemainingTime.rtMCU = dataEngine.remainingBatteryDisChargingTime.value/3600.0
					}
					pgHeader.titleString =
						pgHeader.swapTimerBool ?
							(pgHeader.isAutocontrolActive ?
								"888%" : (dataEngine.sOC.value.toFixed(1) + "%")):
							(pgHeader.isAutocontrolActive ?
								"8h88" :
								((RemainingTime.remainingTimeCpp > 0xFFAF) ?
									 "-.-hr": RemainingTime.remainingTimeCpp))
					pgHeader.swapTimerBool = !pgHeader.swapTimerBool
					iteration = 0
				}
			}
			mainIndicators.toggle = toggle;
			iteration++;
		}
	}
}

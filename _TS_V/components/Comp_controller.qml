/******************************************************************************
 * Controller component
******************************************************************************/

import QtQuick 2.0
import MyQmlModule 1.0

Item {
	id: controllerRoot

	property bool menuButtonPressed: false
	property bool upButtonPressed: false
	property bool downButtonPressed: false
	property bool enterButtonPressed: false

	property bool isMechanicMode1: false
	property bool isMechanicMode2: false

	property bool upButtonHeldOneSecond: false
	property bool downButtonHeldOneSecond: false

	property bool hideEnter: comp_navigationBar.hideEnter
	property bool outsideMainMenu: comp_navigationBar.outsideMainMenu

	onHideEnterChanged: {
		// when the nav bar changes its appearance (arrows vs AUX/-), stop all the timers detecting button hold
		if(pg_home.autoControlDone === true)
		{
			stopTimersButton.restart()
		}
	}

	onOutsideMainMenuChanged: {
		// when the nav bar changes its appearance (4th softkey: MENU vs return), stop all the timers detecting button hold
		if(pg_home.autoControlDone === true)
		{
			stopTimersButton.restart()
		}
	}

	Timer {
		// simple 50ms delay wich stops all button hold timers
		id: stopTimersButton
		interval: 50
		repeat: false
		onTriggered: {

			holdDownButton1sTimer.stop()
			holdDownButton3sTimer.stop()
			holdMenuButton1sTimer.stop()
			holdUpButton1sTimer.stop()
			holdUpButton3sTimer.stop()
//            console.log(new Date().getTime() + ": button timers stopped")

		}
	}


	function enterPressed()
	{
		enterButtonPressed = true;
	}

	function enterReleased()
	{
		enterButtonPressed = false;
	}

	function upPressed()
	{
		upButtonPressed = true;
	}

	function upReleased()
	{
		upButtonPressed = false;
	}

	function downPressed()
	{
		downButtonPressed = true;
	}

	function downReleased()
	{
		downButtonPressed = false;
	}

	function menuPressed()
	{
		menuButtonPressed = true;
	}

	function menuReleased()
	{
		menuButtonPressed = false;
	}

	function expandMenu()
	{
		comp_navigationBar.isShowing = true;
		comp_navigationBar.isNavigationMode = true;
		navBarTimer.start();
	}

	function collapseMenu()
	{
		comp_navigationBar.isShowing = false
		//comp_navigationBar.isShowing = true // PC Emulation
		comp_navigationBar.isNavigationMode = false;
	}

	function startAutoSwitch()
	{
		autoScreenSWitch.start()
	}

	function stopAutoSwitch()
	{
		autoScreenSWitch.stop()
	}

	function startAutoSwitchMechanicMenu()
	{
		if (autoScreenSWitch.running) {
			autoScreenSWitch.stop()
		}
		autoScreenSwitchToMechanicMenu.start()
	}

	function stopAutoSwitchMechanicMenu()
	{
		if (autoScreenSWitch.running) {
			autoScreenSWitch.stop()
		}
		autoScreenSwitchToMechanicMenu.stop()
	}

	function backToHome()
	{
		backEnd.currentPage.visible = false

		if (!startupInfo.isManualStartMode()) {
			backEnd.setState(MyAppState.MAIN)
			backEnd.setCurrentPage(pg_home)
			pg_home.visible = true
			pgHeader.visible = true
			pgHeader.mainMenu = true
			pgHeader.titleString = "AM 08:00"
		}
		else {
			backEnd.setState(MyAppState.MAIN_HOUR_METER)
			backEnd.setCurrentPage(pg_home2)
			pg_home2.visible = true
			pgHeader.visible = false
		}

		rectList.visible = false
		rectMenu.visible = false
	}

	function backToMechanicMenu()
	{
		if (isMechanicMode1) {
			backEnd.setState(MyAppState.MENU_MECA_1)
		}
		else if (isMechanicMode2) {
			backEnd.setState(MyAppState.MENU_MECA_2)
		}

		makePagesInvisible()

		pg_menu.selectMenuItems()
		pg_menu.visible = true
		backEnd.setCurrentPage(pg_menu)
		pgHeader.visible = false
		pgHeader.mainMenu = false
		rectList.visible = false
		rectMenu.visible = true
		comp_navigationBar.hideEnter = false;
	}

	function makePagesInvisible() {
		// make all pages invisible
		pg_home.visible = false;
		pg_largeList.visible = false
		pg_listStatusBar.visible = false
		pg_lineStatusBarIcon.visible =false
		pg_list.visible = false
		pg_listDetails.visible = false
		pg_listIcon.visible = false
		pg_largeListSelection.visible = false
		pg_ptoSettings.visible = false
		pg_preHeating.visible = false
		pg_calendar.visible = false
		pg_opTimeMeas.visible = false
		pg_dateSelection.visible = false
		pg_gauge.visible = false
		pg_passcode.visible = false
		pg_listLargeStatusBar.visible = false
		pg_listIconMultiple.visible = false
		pg_immobilizer.visible = false
		pg_immobilizerActivation.visible = false
		pg_immoblizerTimeValidation.visible = false
		pg_sootLevel.visible = false
		pg_ashLevel.visible = false
		pg_rcsBackward.visible = false
		pg_rcsForward.visible = false
		pg_pinCode.visible = false
	}

	function disableMechanicMode() {
		isMechanicMode1 = false
		isMechanicMode2 = false
		autoScreenSWitch.restart();
		autoScreenSwitchToMechanicMenu.stop();

		//pg_home.revertPtoSetting(true)

		console.log("Mechanic mode disabled.")
		rectList.visible = false
		rectMenu.visible = false

		makePagesInvisible()

		comp_navigationBar.hideEnter = true;
	}



	function selectMechanicModeL1() {
		backEnd.setState(MyAppState.MENU_MECA_1)
		backEnd.setCurrentPage(pg_menu)
		pg_home.revertPtoSetting(true)
		pg_menu.selectMenuItems()
		pg_menu.selectIndex = 0
		console.log("Menu page MM1 selected")
		rectList.visible = false
		rectMenu.visible = true

		makePagesInvisible()

		pg_menu.visible = true;
		backEnd.setCurrentPage(pg_menu);
		pgHeader.visible = false;
		comp_navigationBar.hideEnter = false;

		if(pg_listIcon.factoryResetSession === false)
		{
			pg_listMechanic.updateUsageHistory()
		}
	}

	function selectMechanicModeL2() {
		backEnd.setState(MyAppState.MENU_MECA_2)
		backEnd.setCurrentPage(pg_menu)
		pg_home.revertPtoSetting(true)
		pg_menu.selectMenuItems()
		console.log("Menu page MM2 selected")
		pg_menu.selectIndex = 0
		rectList.visible = false
		rectMenu.visible = true

		makePagesInvisible()

		pg_menu.visible = true;
		backEnd.setCurrentPage(pg_menu);
		pgHeader.visible = false;
		comp_navigationBar.hideEnter = false;

		if(pg_listIcon.factoryResetSession === false)
		{
			pg_listMechanic.updateUsageHistory()
		}
	}

	onEnterButtonPressedChanged:
	{
		if(enterButtonPressed)
		{
			autoScreenSWitch.restart();
			if (isMechanicMode1 || isMechanicMode2) autoScreenSwitchToMechanicMenu.restart();

			if(!comp_navigationBar.isNavigationMode)
			{
				expandMenu();
			}
			else
			{
				navBarTimer.restart();
				backEnd.enterPressed();
			}
		}
	}

	onUpButtonPressedChanged:
	{
		if(upButtonPressed)
		{
			autoScreenSWitch.restart();
			if (isMechanicMode1 || isMechanicMode2) autoScreenSwitchToMechanicMenu.restart();

			if(!comp_navigationBar.isNavigationMode)
			{
				expandMenu();
			}
			else
			{
				if(comp_navigationBar.hideEnter)
				{
					if (!pg_popUp.visible /*&& pg_popUp.lastState !== MyAppState.MAIN*/) {
						comp_navigationBar.hideEnter = false;
					}
				}
				navBarTimer.restart();
				backEnd.upPressed();
			}
		}
	}

	onDownButtonPressedChanged:
	{
		if(downButtonPressed)
		{
			autoScreenSWitch.restart();
			if (isMechanicMode1 || isMechanicMode2) autoScreenSwitchToMechanicMenu.restart();

			if(!comp_navigationBar.isNavigationMode)
			{
				expandMenu();
			}
			else
			{
				navBarTimer.restart();
				backEnd.downPressed();
			}
		}
	}

	onMenuButtonPressedChanged:
	{
		autoScreenSWitch.restart();
		if (isMechanicMode1 || isMechanicMode2) autoScreenSwitchToMechanicMenu.restart();

		if(menuButtonPressed) {
			if(!comp_navigationBar.isNavigationMode)
			{
				expandMenu();

			}
			else
			{
				if(comp_navigationBar.hideEnter)
				{
					if (!pg_popUp.visible /*&& pg_popUp.lastState !== MyAppState.MAIN*/) {
						comp_navigationBar.hideEnter = false;
					}
				}
				navBarTimer.restart();
				backEnd.menuPressed();
			}
	   }
	}

	Connections {
		target: backEnd
		onHardwareButtonStateChanged: {
			if(pg_home.autoControlActive === false)
			{
				if (buttonNo === backEnd.currentConfig.hwButtonNrOk)
				{
					upButtonPressed = buttonPressed;
				}
				else if (buttonNo === backEnd.currentConfig.hwButtonNrUp)
				{
					downButtonPressed = buttonPressed;
				}
				else if (buttonNo === backEnd.currentConfig.hwButtonNrDown)
				{
					enterButtonPressed = buttonPressed;
				}
				else if (buttonNo === backEnd.currentConfig.hwButtonNrMenu)
				{
					menuButtonPressed = buttonPressed;
				}
			}


		}
		onMechanicMode1Activated : {
			if(readyForInit === true){
				isMechanicMode1 = true
				isMechanicMode2 = false
				console.log("Mechanic Mode 1 asked")
				if(comp_navigationBar.hideEnter)
				{
					comp_navigationBar.hideEnter = false;
				}
				selectMechanicModeL1()
				autoScreenSWitch.running = false
			}
		}
		onMechanicMode2Activated: {
			if(readyForInit === true){
				isMechanicMode1 = false
				isMechanicMode2 = true
				console.log("Mechanic Mode 2 asked")
				if(comp_navigationBar.hideEnter)
				{
					comp_navigationBar.hideEnter = false;
				}
				selectMechanicModeL2()
				autoScreenSWitch.running = false
			}
		}
	}

	Timer {
		id: navBarTimer
		interval: 5000
		repeat: false
		onTriggered: collapseMenu()
	}

	Timer {
		id: autoScreenSWitch
		interval: 60000
		repeat: false
		onTriggered: {

			console.log("autoScreenSWitch onTriggered")
			if (
				(autoBackToHomeForbidden === true) ||
				(backEnd.state === MyAppState.IMMOBILIZER) ||
				(backEnd.state === MyAppState.IMMOBILIZER_ACTIVATION) ||
				(backEnd.state === MyAppState.IMMOBILIZER_SETTINGS) ||
				(backEnd.state === MyAppState.MONITOR) ||
				(backEnd.state === MyAppState.TIME_TO_ACTIVATE) ||
				(backEnd.state === MyAppState.ENTER_TRANS_PIN) ||
				(backEnd.state === MyAppState.ENTER_DRIVER_PIN) ||
				(backEnd.state === MyAppState.ENTER_OWNER_PIN) ||
				(backEnd.state === MyAppState.NEW_TRANS_PIN) ||
				(backEnd.state === MyAppState.NEW_DRIVER_PIN) ||
				(backEnd.state === MyAppState.NEW_OWNER_PIN) ||
				(readyForInit === false)) {
				; // Do nothing
			}
			else {
				console.log("backToHome")
				backToHome()
			}
		}
	}

	Timer {
		id: autoScreenSwitchToMechanicMenu
		interval: 60000
		repeat: false
		onTriggered:  {
			console.log("autoScreenSwitchToMechanicMenu onTriggered")
			if (
				(autoBackToHomeForbidden === true) ||
				(backEnd.state === MyAppState.IMMOBILIZER) ||
				(backEnd.state === MyAppState.IMMOBILIZER_ACTIVATION) ||
				(backEnd.state === MyAppState.IMMOBILIZER_SETTINGS) ||
				(backEnd.state === MyAppState.MONITOR) ||
				(backEnd.state === MyAppState.TIME_TO_ACTIVATE) ||
				(backEnd.state === MyAppState.ENTER_TRANS_PIN) ||
				(backEnd.state === MyAppState.ENTER_DRIVER_PIN) ||
				(backEnd.state === MyAppState.ENTER_OWNER_PIN) ||
				(backEnd.state === MyAppState.NEW_TRANS_PIN) ||
				(backEnd.state === MyAppState.NEW_DRIVER_PIN) ||
				(backEnd.state === MyAppState.NEW_OWNER_PIN) ||
				(readyForInit === false)) {
					; // Do nothing
			}
			else {
				console.log("backToMechanicMenu")
				backToMechanicMenu()
			}
		}
	}

	Timer {
		id: holdMenuButton1sTimer
		interval: 1000
		repeat: false // do not repeat, only launch pressUpButton5HzTimer
		onTriggered: {
			// if the menu button is held 1 second in any screen, go back to the home page
			if(backEnd.state != MyAppState.IMMOBILIZER){
				backToHome()
			}
		}
	}

	Timer {
		id: holdUpButton1sTimer
		interval: 1000
		repeat: false // do not repeat, only launch pressUpButton5HzTimer
		onTriggered: {
			upButtonHeldOneSecond = true
			//upButtonPressed = true // press the button every repeat
			pressUpButton5HzTimer.restart()
		}
	}

	Timer {
		id: pressUpButton5HzTimer
		interval: 200
		repeat: true // repeat every 0.2s
		onTriggered: {
			if(comp_navigationBar.hideEnter === false)
			{
				upButtonPressed = true // press the button every repeat
			}
		}
	}

	Timer {
		id: holdUpButton3sTimer
		interval: 3000
		repeat: false // do not repeat, only launch pressUpButton10HzTimer
		onTriggered: {
			pressUpButton5HzTimer.stop()
			//upButtonPressed = true // press the button every repeat
			pressUpButton10HzTimer.restart()
		}
	}

	Timer {
		id: pressUpButton10HzTimer
		interval: 100
		repeat: true // repeat every 0.1s
		onTriggered: {
			if(comp_navigationBar.hideEnter === false)
			{
				upButtonPressed = true // press the button every repeat
			}
		}
	}

	Timer {
		id: holdDownButton1sTimer
		interval: 1000
		repeat: false // do not repeat, only launch pressUpButton5HzTimer
		onTriggered: {
			downButtonHeldOneSecond = true
			//downButtonPressed = true // press the button every repeat
			pressDownButton5HzTimer.restart()
		}
	}

	Timer {
		id: pressDownButton5HzTimer
		interval: 200
		repeat: true // repeat every 0.2s
		onTriggered: {
			downButtonPressed = true // press the button every repeat
		}
	}

	Timer {
		id: holdDownButton3sTimer
		interval: 3000
		repeat: false // do not repeat, only launch pressUpButton10HzTimer
		onTriggered: {
			pressDownButton5HzTimer.stop()
			//downButtonPressed = true // press the button every repeat
			pressDownButton10HzTimer.restart()
		}
	}

	Timer {
		id: pressDownButton10HzTimer
		interval: 100
		repeat: true // repeat every 0.1s
		onTriggered: {
			downButtonPressed = true // press the button every repeat
		}
	}



	property int    m_myOffset_F:   16777194
	property int    m_myOffset_E:   16777196
	property int    m_myOffset_D:   16777198
	property int    m_myOffset_C:   16777200

	Keys.onPressed: {
		if(pg_home.autoControlActive === false && readyForInit === true)
		{
			if (event.key === Qt.Key_C + m_myOffset_C)
			{
				if (event.isAutoRepeat === false)   // do not allow auto-repeated events. one click -- one action
				{
					if(     (holdMenuButton1sTimer.running === false)
					   &&   (controller.isMechanicMode1 === false)
					   &&   (controller.isMechanicMode2 === false))
					{
						holdMenuButton1sTimer.restart()
					}
					menuButtonPressed = true
				}
			}
			else if (event.key === Qt.Key_D + m_myOffset_D)
			{

				if (event.isAutoRepeat === false)
				{
					enterButtonPressed = true   // "ENTER" pressed
				}
			}
			else if (event.key === Qt.Key_E + m_myOffset_E)
			{

				// isAutoRepeat is false at first button press
				if (event.isAutoRepeat === false)
				{
					if(holdDownButton1sTimer.running === false)
					{
						holdDownButton1sTimer.restart()
					}
					if(holdDownButton3sTimer.running === false)
					{
						holdDownButton3sTimer.restart()
					}
					downButtonPressed = true               //  "DOWN" pressed
				}
				else
				{
					// if button is held, isAutoRepeat for this button becomes true
					// we release the button here, pressDownButton5HzTimer will press it again every 0.2s
					downButtonPressed = false
				}

			}
			else if (event.key === Qt.Key_F + m_myOffset_F)
			{
				// isAutoRepeat is false at first button press
				if (event.isAutoRepeat === false)
				{
					if(holdUpButton1sTimer.running === false)
					{
						holdUpButton1sTimer.restart()
					}
					if(holdUpButton3sTimer.running === false)
					{
						holdUpButton3sTimer.restart()
					}
					upButtonPressed = true               //  "UP" pressed
				}
				else
				{
					// if button is held, isAutoRepeat for this button becomes true
					// we release the button here, pressUpButton5HzTimer will press it again every 0.2s
					upButtonPressed = false
				}

			}
		}
	}

	Keys.onReleased: {
		if (event.key === Qt.Key_C + m_myOffset_C)
		{
			if (event.isAutoRepeat === false)   // do not allow auto-repeated events. one click -- one action
			{
				holdMenuButton1sTimer.stop()
				menuButtonPressed = false
			}
		}
		else if (event.key === Qt.Key_D + m_myOffset_D)
		{
			if (event.isAutoRepeat === false)
			{
				enterButtonPressed = false
			}
		}
		else if (event.key === Qt.Key_E + m_myOffset_E)
		{
			if (event.isAutoRepeat === false)
			{
				holdDownButton1sTimer.stop()
				holdDownButton3sTimer.stop()
				pressDownButton5HzTimer.stop()
				pressDownButton10HzTimer.stop()
				downButtonHeldOneSecond = false
				downButtonPressed = false
			}
		}
		else if (event.key === Qt.Key_F + m_myOffset_F)
		{
			if (event.isAutoRepeat === false)
			{
				holdUpButton1sTimer.stop()
				holdUpButton3sTimer.stop()
				pressUpButton5HzTimer.stop()
				pressUpButton10HzTimer.stop()
				upButtonHeldOneSecond = false
				upButtonPressed = false
			}
		}
	}
}

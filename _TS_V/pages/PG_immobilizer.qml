import QtQuick 2.6
import MyQmlModule 1.0
import QtGraphicalEffects 1.0
import "../components"

Rectangle {
	id: immobilizerID

	width: parent.width
	height: parent.height
	color: color_gray
	anchors.topMargin: backEnd.currentConfig.headerHeight

	property int layerdIndex: 0
	property string currentInfoMsg: qsTrId("LBL_0349") + translator.emptyString // LBL_0349 == "Enter Password"
	property bool errorTxt: false

	property int pinToVerify: 0
	property bool checkTypedPin: false
	property int repeatIndex: 0
	property bool pinValidatedByMCU: false
	property bool endMCUResponseTime: false
	property int mcuTimeout: 10*10 // multiple of 100ms = 10*(N seconds)
	property int mcuScreenCtrl: dataEngine.screenCtrl.value

	// CAN values of the keypad
	property int keypad1: dataEngine.digitalInputKey02.value
	property int keypad2: dataEngine.digitalInputKey01.value
	property int keypad3: dataEngine.digitalInputKey04.value
	property int keypad4: dataEngine.digitalInputKey03.value
	property int keypad5: dataEngine.digitalInputKey06.value
	property int keypad6: dataEngine.digitalInputKey05.value

	property int isKeypadPressed: 0 // 0 if no button of the keypad, else the number of the keypad pressed

	property bool bPinInputIsLocked: (dataEngine.screenCtrl.value === 4) ? true : false;

	// If keypad 1 is pressed, change the current number to 1
	onKeypad1Changed: {
		if (visible === true && !bPinInputIsLocked) // only if pg_immmobilizer is visible
		{
			if(!canError18FED931 && keypad1 === 1 && isKeypadPressed === 0){
				isKeypadPressed = 1
				if(layerdIndex === 0){
					pinComboBox.setThousands(1)
				} else if(layerdIndex === 1){
					pinComboBox.setHundreds(1)
				} else if(layerdIndex === 2){
					pinComboBox.setTens(1)
				} else if(layerdIndex === 3){
					pinComboBox.setUnits(1)
				}
			} else if (isKeypadPressed === 1) {
				validateNumber()
				isKeypadPressed = 0
			}
		}

	}

	// If keypad 2 is pressed, change the current number to 2
	onKeypad2Changed: {
		if(visible === true && !bPinInputIsLocked) // only if pg_immmobilizer is visible
		{
			if(!canError18FED931 && keypad2 === 1 && isKeypadPressed === 0){
				isKeypadPressed = 2
				if(layerdIndex === 0){
					pinComboBox.setThousands(2)
				} else if(layerdIndex === 1){
					pinComboBox.setHundreds(2)
				} else if(layerdIndex === 2){
					pinComboBox.setTens(2)
				} else if(layerdIndex === 3){
					pinComboBox.setUnits(2)
				}
			} else if (isKeypadPressed === 2) {
				validateNumber()
				isKeypadPressed = 0
			}
		}
	}

	// If keypad 3 is pressed, change the current number to 3
	onKeypad3Changed: {
		if(visible === true && !bPinInputIsLocked) // only if pg_immmobilizer is visible
		{
			if(!canError18FED931 && keypad3 === 1 && isKeypadPressed === 0){
				isKeypadPressed = 3
				if(layerdIndex === 0){
					pinComboBox.setThousands(3)
				} else if(layerdIndex === 1){
					pinComboBox.setHundreds(3)
				} else if(layerdIndex === 2){
					pinComboBox.setTens(3)
				} else if(layerdIndex === 3){
					pinComboBox.setUnits(3)
				}
			} else if (isKeypadPressed === 3) {
				validateNumber()
				isKeypadPressed = 0
			}
		}
	}

	// If keypad 4 is pressed, change the current number to 4
	onKeypad4Changed: {
		if(visible === true && !bPinInputIsLocked) // only if pg_immmobilizer is visible
		{
			if(!canError18FED931 && keypad4 === 1 && isKeypadPressed === 0){
				isKeypadPressed = 4
				if(layerdIndex === 0){
					pinComboBox.setThousands(4)
				} else if(layerdIndex === 1){
					pinComboBox.setHundreds(4)
				} else if(layerdIndex === 2){
					pinComboBox.setTens(4)
				} else if(layerdIndex === 3){
					pinComboBox.setUnits(4)
				}
			} else if (isKeypadPressed === 4) {
				validateNumber()
				isKeypadPressed = 0
			}
		}

	}

	// If keypad 5 is pressed, change the current number to 5
	onKeypad5Changed: {
		if(visible === true && !bPinInputIsLocked) // only if pg_immmobilizer is visible
		{
			if(!canError18FED931 && keypad5 === 1 && isKeypadPressed === 0){
				isKeypadPressed = 5
				if(layerdIndex === 0){
					pinComboBox.setThousands(5)
				} else if(layerdIndex === 1){
					pinComboBox.setHundreds(5)
				} else if(layerdIndex === 2){
					pinComboBox.setTens(5)
				} else if(layerdIndex === 3){
					pinComboBox.setUnits(5)
				}
			} else if (isKeypadPressed === 5) {
				validateNumber()
				isKeypadPressed = 0
			}
		}

	}

	// If keypad 6 is pressed, change the current number to 6
	onKeypad6Changed: {
		if(visible === true && !bPinInputIsLocked) // only if pg_immmobilizer is visible
		{
			if(!canError18FED931 && keypad6 === 1 && isKeypadPressed === 0){
				isKeypadPressed = 6
				if(layerdIndex === 0){
					pinComboBox.setThousands(6)
				} else if(layerdIndex === 1){
					pinComboBox.setHundreds(6)
				} else if(layerdIndex === 2){
					pinComboBox.setTens(6)
				} else if(layerdIndex === 3){
					pinComboBox.setUnits(6)
				}
			} else if (isKeypadPressed === 6) {
				validateNumber()
				isKeypadPressed = 0
			}
		}
	}

//    Component.onCompleted: {
//        if (!startupInfo.isManualStartMode()) {
//            backEnd.setState(MyAppState.IMMOBILIZER)
//            backEnd.setCurrentPage(pg_immobilizer)
//            pgHeader.visible = true
//            pgHeader.mainMenu = false
//            pgHeader.titleString = qsTrId("LBL_0328") + translator.emptyString
//            comp_navigationBar.hideEnter = false
//        }
//    }

	onVisibleChanged:
	{
		if(visible === true)
		{
			layerdIndex = 0
			pinComboBox.resetPin()
			errorTxt = false
			console.log("Page PG_Immobilizer entered")

			if(dataEngine.screenCtrl.value === 4)
			{
				errorTxt = true
				currentInfoMsg = "Locked for 15 minutes"
				bPinInputIsLocked = true;
			}

		}
		else {
			console.log("Page PG_Immobilizer left")
		}
	}

	onMcuScreenCtrlChanged:
	{
		if (visible === true) {
			if(dataEngine.screenCtrl.value === 0)
			{
				errorTxt = false
				currentInfoMsg = "Pin is correct"
//				waitMCUPinValidation.start()
				bPinInputIsLocked = false;

				if (waitMCUPinValidation.running === 0) {

					// Go to home page
					console.log("Error-handling, no waitMCUPinValidation-Timer, but dataEngine.screenCtrl.value === 0")
					pg_immobilizer.visible = false
					backEnd.setState(MyAppState.MAIN)
					backEnd.setCurrentPage(pg_home)
					pg_home.visible = true
					pgHeader.visible = true
					pgHeader.mainMenu = true
					pgHeader.titleString = "AM 08:00"
					pg_home.startAutoControl()
					rectList.visible = false
				}
			}
			else if(dataEngine.screenCtrl.value === 1)
			{
				errorTxt = false
				currentInfoMsg = "Enter owner-pin"
				bPinInputIsLocked = false;
			}
			else if(dataEngine.screenCtrl.value === 2)
			{
				errorTxt = false
				currentInfoMsg = qsTrId("LBL_0349") + translator.emptyString // LBL_0349 === "Enter Password"
				bPinInputIsLocked = false;
			}
			else if ((dataEngine.screenCtrl.value === 3) && (enteredPin < 1000) && (dataEngine.immobTransPinLeftTries.value === 0))
			{
				currentInfoMsg = "Transporter PIN expired"
				errorTxt = true
				bPinInputIsLocked = true;
			}
			else if(dataEngine.screenCtrl.value === 3)
			{
				currentInfoMsg = "Wrong password"
//				currentInfoMsg = "Pin is wrong"
				errorTxt = true
				bPinInputIsLocked = true;
			}
			else if(dataEngine.screenCtrl.value === 4)
			{
				errorTxt = true
				currentInfoMsg = "Locked for 15 minutes"
				bPinInputIsLocked = true;
			}
			else if(dataEngine.screenCtrl.value === 5)
			{
				errorTxt = false
				currentInfoMsg = "Enter new pin"
				bPinInputIsLocked = false;
			}
			else
			{
				bPinInputIsLocked = false;
				errorTxt = false
				currentInfoMsg = ""
			}

			if(bPinInputIsLocked === true) {
				console.log("Page PG_Immobilizer: bPinInput Is Locked")
			}
			else {
				console.log("Page PG_Immobilizer: bPinInput Is NOT Locked")
			}
		}
	}

	Timer {
		id: waitMCUPinValidation
		running: false
		interval: 100
		repeat: true // repeat every 100ms
		onTriggered: {

			console.log("repeatIndex pg_immo: " + repeatIndex)

			errorTxt = false
			currentInfoMsg = "Checking pin code..."

			if(   true//(canError18FF8447 === false)
			   && (dataEngine.screenCtrl.value === 0)) // 0 = immobilizer unlocked
			{
				// MCU validates the pin code, and there is nor CAN comm error
				// we cannot validate the pin code if there is a CAN error
				checkTypedPin = false
				endMCUResponseTime = true
				pinValidatedByMCU = true
				repeatIndex = 0
				waitMCUPinValidation.stop()

				// Go to home page
				console.log("Pin validated by MCU, main page appears")
				pg_immobilizer.visible = false
				backEnd.setState(MyAppState.MAIN)
				backEnd.setCurrentPage(pg_home)
				pg_home.visible = true
				pgHeader.visible = true
				pgHeader.mainMenu = true
				pgHeader.titleString = "AM 08:00"
				pg_home.startAutoControl()
				rectList.visible = false
			}

			if(        (canError18FF8447 === false)
					&& (dataEngine.screenCtrl.value === 3)) // 3 = wrong pin
			{
				// Wrong PIN: MCU did not validate the pin code or
				// Transporter pin expired
				if ((enteredPin < 1000) && (dataEngine.immobTransPinLeftTries.value === 0))
				{
					currentInfoMsg = "Transporter PIN expired"
					errorTxt = true
				}
				else { //
					currentInfoMsg = "Wrong password"
//					currentInfoMsg = "Pin is wrong"
					errorTxt = true
				}

				checkTypedPin = false
				endMCUResponseTime = true
				pinValidatedByMCU = false
				repeatIndex = 0

				layerdIndex = 0
				pinComboBox.resetPin()

				waitMCUPinValidation.stop()
			}

			if(        (canError18FF8447 === false)
					&& (dataEngine.screenCtrl.value === 4)) // 4 = delay input
			{
				checkTypedPin = false
				endMCUResponseTime = true // true // keine Auswirkung
				pinValidatedByMCU = false // keine Auswirkung
				repeatIndex = 0

				currentInfoMsg = "locked for 15 minutes"

				errorTxt = true
				layerdIndex = 0
				pinComboBox.resetPin()

				waitMCUPinValidation.stop()
			}


			// Wait 10s for the MCU to answer
			if(repeatIndex >= mcuTimeout)
			{
				// Timeout: MCU did not validate the pin code
				checkTypedPin = false
				endMCUResponseTime = true
				pinValidatedByMCU = false
				repeatIndex = 0

				if(canError18FFAF47 === true)
				{
					currentInfoMsg = "CAN communication error"
				}
				else
				{
					currentInfoMsg = "Validation was not received"
				}
				errorTxt = true
				layerdIndex = 0
				pinComboBox.resetPin()

				waitMCUPinValidation.stop()
			}

			repeatIndex = repeatIndex + 1
		}
	}

	function upPressed()
	{
		if (bPinInputIsLocked) return;

		if(layerdIndex === 0) {
			pinComboBox.increaseThousands()
		}
		else if(layerdIndex === 1) {
			pinComboBox.increaseHundreds()
		}
		else if(layerdIndex === 2) {
			pinComboBox.increaseTens()
		}
		else if(layerdIndex === 3) {
			pinComboBox.increaseUnits()
		}
	}

	function downPressed()
	{
		if (bPinInputIsLocked) return;

		if(layerdIndex === 0) {
			pinComboBox.decreaseThousands()
		}
		else if(layerdIndex === 1) {
			pinComboBox.decreaseHundreds()
		}
		else if(layerdIndex === 2) {
			pinComboBox.decreaseTens()
		}
		else if(layerdIndex === 3) {
			pinComboBox.decreaseUnits()
		}
	}

	function enterPressed()
	{
		if (bPinInputIsLocked) return;
		validateNumber()
	}

	function menuPressed() {
		layerdIndex = 0
		pinComboBox.resetPin()
	}

	// function to validate a number and pass to the next
	// if it is the last number, check the pin code -> go to the main page or retry
	function validateNumber(){
		if  (bPinInputIsLocked) {
			return;
		}

		if(layerdIndex === 0) {
			layerdIndex = 1
			pinComboBox.selectThousands(false)
			pinComboBox.selectHundreds(true)
			pinComboBox.setDoneThousands(true)
		}
		else if(layerdIndex === 1) {
			layerdIndex = 2
			pinComboBox.selectHundreds(false)
			pinComboBox.selectTens(true)
			pinComboBox.setDoneHundreds(true)
		}
		else if(layerdIndex === 2) {
			layerdIndex = 3
			pinComboBox.selectTens(false)
			pinComboBox.selectUnits(true)
			pinComboBox.setDoneTens(true)
		}
		else if(layerdIndex === 3) {
			pinComboBox.selectUnits(false)
			pinComboBox.setDoneUnits(true)
			pinToVerify = pinComboBox.validatePin()
			checkTypedPin = true

			console.log("validatePin")
			pinValidatedByMCU = false
			repeatIndex = 0
			endMCUResponseTime = false
			waitMCUPinValidation.start()

		}
	}

	Rectangle {
		id: pinComboBoxController
		width: parent.width  - comp_navigationBar.width + 2
		height: parent.height - anchors.topMargin

		color: color_gray
		border {
			color: color_gray_bar
			width: 2
		}
		anchors {
			top: parent.top
			left: parent.left
		}

		Comp_pinComboBox {
			id: pinComboBox
			y: parent.height/2 - pinComboBox.height/2 - 6
		}
	}

	Rectangle {
		id: infoBarController
		width: parent.width - comp_navigationBar.width + 2
		height: 35
		color: color_gray
		border {
			color: color_gray_bar
			width: 2
		}
		anchors {
			left: parent.left
			bottom: parent.bottom
		}

		Text {
			id: infoBarText
			text: currentInfoMsg
			font.pixelSize: 25
			font.family: systemFont
			color: errorTxt ? color_red : color_white
			anchors {
				verticalCenter: parent.verticalCenter
				left: parent.left
				leftMargin: 6
			}
		}
	}

}

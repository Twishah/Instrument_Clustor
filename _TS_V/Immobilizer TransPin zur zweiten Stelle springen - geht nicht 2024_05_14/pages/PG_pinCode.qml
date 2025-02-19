import QtQuick 2.6
import MyQmlModule 1.0
import QtGraphicalEffects 1.0
import "../components"

Rectangle {
	id: pinCodeID

	width: parent.width
	height: parent.height
	color: color_gray
	anchors.topMargin: backEnd.currentConfig.headerincreaseHundreds

	property int layerdIndex: 0
	property string currentInfoMsg: ""
	property bool errorTxt: false

	property int pinToVerify: 0
	property bool checkTypedPin: false
	property int repeatIndex: 0
	property bool pinValidatedByMCU: false
	property bool endMCUResponseTime: false
	property int mcuTimeout: 10*10 // multiple of 100ms = 10*(N seconds)

	// CAN values of the keypad
	property int keypad1: dataEngine.digitalInputKey02.value
	property int keypad2: dataEngine.digitalInputKey01.value
	property int keypad3: dataEngine.digitalInputKey04.value
	property int keypad4: dataEngine.digitalInputKey03.value
	property int keypad5: dataEngine.digitalInputKey06.value
	property int keypad6: dataEngine.digitalInputKey05.value

	property int isKeypadPressed: 0 // 0 if no button of the keypad, else the number of the keypad pressed

	// If keypad 1 is pressed, change the current number to 1
	onKeypad1Changed: {
		if(visible === true) // only if pg_pincode is visible
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
		if(visible === true) // only if pg_pincode is visible
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
		if(visible === true) // only if pg_pincode is visible
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
		if(visible === true) // only if pg_pincode is visible
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
		if(visible === true) // only if pg_pincode is visible
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
		if(visible === true) // only if pg_pincode is visible
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

	// If become visible, reset the pinComboBox
	onVisibleChanged: {
		if(visible === true){
			layerdIndex = 0
			pinComboBox.resetPin()
			console.log("Page PG_pinCode entered")
		}
	}

	Timer {
		id: waitMCUPinValidation
		running: false
		interval: 100
		repeat: true // repeat every 100ms
		onTriggered: {

			console.log("repeatIndex pg_pin: " + repeatIndex)

			errorTxt = false
			currentInfoMsg = "Checking pin code..." // TODO translation

			if(canError18FF8447 === false) // no error
			{


				// Go to next page
				console.log("Pin validated by MCU")
				if((backEnd.state === MyAppState.ENTER_TRANS_PIN) && (dataEngine.screenCtrl.value === 5)) // 5 = enter a new pin
				{
					// MCU validates the pin code, and there is nor CAN comm error
					// we cannot validate the pin code if there is a CAN error
					console.log("ENTER_TRANS_PIN")

					checkTypedPin = false
					endMCUResponseTime = true
					pinValidatedByMCU = true
					repeatIndex = 0
					waitMCUPinValidation.stop()

					backEnd.setState(MyAppState.NEW_TRANS_PIN)
					pinComboBox.resetPin()
					currentInfoMsg = qsTrId("LBL_0381") + translator.emptyString
					errorTxt = false
				}
				else if ((backEnd.state === MyAppState.ENTER_DRIVER_PIN) && (dataEngine.screenCtrl.value === 5)) // 5 = correct pin
				{
					// MCU validates the pin code, and there is nor CAN comm error
					// we cannot validate the pin code if there is a CAN error
					console.log("ENTER_DRIVER_PIN")

					checkTypedPin = false
					endMCUResponseTime = true
					pinValidatedByMCU = true
					repeatIndex = 0
					waitMCUPinValidation.stop()

					backEnd.setState(MyAppState.NEW_DRIVER_PIN)
					currentInfoMsg = qsTrId("LBL_0383") + translator.emptyString
					errorTxt = false
				}
				else if ((backEnd.state === MyAppState.ENTER_OWNER_PIN) && (dataEngine.screenCtrl.value === 5)) // 5 = enter a new pin
				{
					// MCU validates the pin code, and there is nor CAN comm error
					// we cannot validate the pin code if there is a CAN error
					console.log("ENTER_OWNER_PIN")

					checkTypedPin = false
					endMCUResponseTime = true
					pinValidatedByMCU = true
					repeatIndex = 0
					waitMCUPinValidation.stop()

					backEnd.setState(MyAppState.NEW_OWNER_PIN)
					currentInfoMsg = qsTrId("LBL_0348") + translator.emptyString
					errorTxt = false
				}
				else if ((backEnd.state === MyAppState.NEW_TRANS_PIN) && ((dataEngine.screenCtrl.value === 95) || (dataEngine.screenCtrl.value === 0) )) // 5 = correct pin
				{
					// MCU validates the pin code, and there is nor CAN comm error
					// we cannot validate the pin code if there is a CAN error
					checkTypedPin = false
					endMCUResponseTime = true
					pinValidatedByMCU = true
					repeatIndex = 0
					waitMCUPinValidation.stop()

					console.log("NEW_TRANS_PIN")
					acceptNewPin()
				}
				else if ((backEnd.state === MyAppState.NEW_DRIVER_PIN) && ((dataEngine.screenCtrl.value === 95) || (dataEngine.screenCtrl.value === 0) )) // 5 = correct pin
				{
					// MCU validates the pin code, and there is nor CAN comm error
					// we cannot validate the pin code if there is a CAN error
					checkTypedPin = false
					endMCUResponseTime = true
					pinValidatedByMCU = true
					repeatIndex = 0
					waitMCUPinValidation.stop()

					console.log("NEW_DRIVER_PIN")
					acceptNewPin()
				}
				else if ((backEnd.state === MyAppState.NEW_OWNER_PIN) && ((dataEngine.screenCtrl.value === 95) || (dataEngine.screenCtrl.value === 0) )) // 5 = correct pin
				{
					// MCU validates the pin code, and there is nor CAN comm error
					// we cannot validate the pin code if there is a CAN error
					checkTypedPin = false
					endMCUResponseTime = true
					pinValidatedByMCU = true
					repeatIndex = 0
					waitMCUPinValidation.stop()

					console.log("NEW_OWNER_PIN")
					acceptNewPin()
				}
				else if((backEnd.state === MyAppState.IMMOBILIZER_ACTIVATION) && (dataEngine.screenCtrl.value === 5)) // 5 = correct pin
				{
					// MCU validates the pin code, and there is nor CAN comm error
					// we cannot validate the pin code if there is a CAN error
					checkTypedPin = false
					endMCUResponseTime = true
					pinValidatedByMCU = true
					repeatIndex = 0
					waitMCUPinValidation.stop()

					backEnd.setCurrentPage(pg_immobilizerActivation)
					pg_pinCode.visible = false
					pg_immobilizerActivation.visible = true
				}
				else if((backEnd.state === MyAppState.TIME_TO_ACTIVATE) && (dataEngine.screenCtrl.value === 5)) // 5 = correct pin
				{
					// MCU validates the pin code, and there is nor CAN comm error
					// we cannot validate the pin code if there is a CAN error
					checkTypedPin = false
					endMCUResponseTime = true
					pinValidatedByMCU = true
					repeatIndex = 0
					waitMCUPinValidation.stop()

					backEnd.setCurrentPage(pg_immoblizerTimeValidation)
					pg_pinCode.visible = false
					pg_immoblizerTimeValidation.visible = true
				}
				errorTxt = false
			}

			if(        (canError18FF8447 === false)
					&& (dataEngine.screenCtrl.value === 3)) // 3 = wrong pin
			{
				// Wrong PIN: MCU did not validate the pin code
				checkTypedPin = false
				endMCUResponseTime = true
				pinValidatedByMCU = false
				repeatIndex = 0

				if(backEnd.state === MyAppState.NEW_OWNER_PIN)
				{
					currentInfoMsg = "Error: first digit must not be 0" // TODO translation
				}
				else if(backEnd.state === MyAppState.NEW_DRIVER_PIN)
				{
					currentInfoMsg = "Error: first digit must not be 0" // TODO translation
				}
				else if(backEnd.state === MyAppState.NEW_TRANS_PIN)
				{
					currentInfoMsg = "Error: first digit must be 0" // TODO translation
				}
				else
				{
					currentInfoMsg = "Wrong password" // TODO translation
				}

				errorTxt = true
				layerdIndex = 0
				pinComboBox.resetPin()

				waitMCUPinValidation.stop()
			}

			// Wait 10s for the MCU to answer
			if(repeatIndex >= mcuTimeout)
			{
				// MCU did not validate the pin code
				checkTypedPin = false
				endMCUResponseTime = true
				pinValidatedByMCU = false
				repeatIndex = 0

				if(canError18FFAF47 === true)
				{
					currentInfoMsg = "CAN communication error" // TODO translation
				}
				else
				{
					currentInfoMsg = "Wrong pin" // TODO translation
				}
				errorTxt = true
				layerdIndex = 0
				pinComboBox.resetPin()

				waitMCUPinValidation.stop()
			}

			repeatIndex = repeatIndex + 1
		}
	}

	function acceptNewPin()
	{
		backToMenu()
		pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5)
		checkTypedPin = false
	}

	function upPressed()
	{
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
		validateNumber()
	}

	function menuPressed() {
		if (layerdIndex === 0) {
			backToMenu()
		} else {
			layerdIndex = 0
			pinComboBox.resetPin()
		}
	}

	function validateNumber(){
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

			if ((backEnd.state === MyAppState.ENTER_TRANS_PIN)||(backEnd.state === MyAppState.ENTER_DRIVER_PIN)||(backEnd.state === MyAppState.ENTER_OWNER_PIN)){

				console.log("check pin")
				pinValidatedByMCU = false
				repeatIndex = 0
				endMCUResponseTime = false
				waitMCUPinValidation.start()

			}
			else if ((backEnd.state === MyAppState.NEW_TRANS_PIN)) {
				console.log("check new transporter pin")

//				console.log("no magic pin")
				pinValidatedByMCU = false
				repeatIndex = 0
				endMCUResponseTime = false
				waitMCUPinValidation.start()

			}
			else if ((backEnd.state === MyAppState.NEW_DRIVER_PIN)) {
				console.log("check new driver pin")

//				console.log("no magic pin")
				pinValidatedByMCU = false
				repeatIndex = 0
				endMCUResponseTime = false
				waitMCUPinValidation.start()

			} else if ((backEnd.state === MyAppState.NEW_OWNER_PIN)) {
				console.log("check new owner pin")

//				console.log("no magic pin")
				pinValidatedByMCU = false
				repeatIndex = 0
				endMCUResponseTime = false
				waitMCUPinValidation.start()

			}
			else if ((backEnd.state === MyAppState.IMMOBILIZER_ACTIVATION)) {

//				console.log("no magic pin")
				console.log("check IMMOBILIZER_ACTIVATION")
				pinValidatedByMCU = false
				repeatIndex = 0
				endMCUResponseTime = false
				waitMCUPinValidation.start()

			}
			else if ((backEnd.state === MyAppState.TIME_TO_ACTIVATE)) {

//				console.log("no magic pin")
				console.log("check TIME_TO_ACTIVATE")
				pinValidatedByMCU = false
				repeatIndex = 0
				endMCUResponseTime = false
				waitMCUPinValidation.start()

			}
			layerdIndex = 0
			pinComboBox.resetPin()
		}
	}

	function backToMenu() {
		backEnd.setState(MyAppState.IMMOBILIZER_SETTINGS)
		backEnd.setCurrentPage(pg_listStatusBar)
		pg_listStatusBar.visible = true
		pg_pinCode.visible = false
		pgHeader.visible = true
		pgHeader.mainMenu = false
		pgHeader.titleString = qsTrId("LBL_0328") + translator.emptyString
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
			topMargin: 25
		}


		Comp_pinComboBox {
			id: pinComboBox
			y: parent.height/2 - pinComboBox.height/2 - 6
		}
	}

	Rectangle {
		id: infoBarController
		width: pinComboBoxController.width
		height: 37
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
			font.pixelSize: 20
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

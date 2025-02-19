import QtQuick 2.6
import MyQmlModule 1.0
import QtGraphicalEffects 1.0
import "../components"

Rectangle {
	id: passcodeID

	width: parent.width
	height: parent.height
	color: color_gray
	anchors.topMargin: backEnd.currentConfig.headerincreaseHundreds

	property int layerdIndex: 0
	property int intervalValue: 0
	property var digits: [0, 0, 0, 0]

	onVisibleChanged: {

		if(visible === true) {
			console.log("Page PG_passcode entered")
		}
	}

	function calculateCurrentNumbers(intervalNumbers) {
		layerdIndex = 0
		intervalLevels.selectThousands(true)
		intervalLevels.selectHundreds(false)
		intervalLevels.selectTens(false)
		intervalLevels.selectUnits(false)

		var intervalValueStr = intervalNumbers.toString()
		var ind = 0
		var maxInd = 4
		digits = []

		for (var j = intervalValueStr.length; j < maxInd; j++) {
			digits.push(0)
			ind++
		}

		for (var i = ind;  i < maxInd; i++) {
			digits.push(intervalNumbers.toString()[i - ind])
		}

		//console.log("Whole number: " + parseInt(digits[0] + digits[1] + digits[2] + digits[3]))

		intervalLevels.assignCurrentNumbers(digits)
		intervalValue = intervalNumbers
	}


	function menuPressed()
	{
		if(layerdIndex === 0) {
			intervalLevels.cancelInterval()
		}
		else if(layerdIndex === 1) {
			intervalLevels.selectHundreds(false)
			intervalLevels.cancelInterval()
		}
		else if(layerdIndex === 2) {
			intervalLevels.selectTens(false)
			intervalLevels.cancelInterval()
		}
		else if(layerdIndex === 3) {
			intervalLevels.selectUnits(false)
			intervalLevels.cancelInterval()
		}

		layerdIndex = 0
		intervalLevels.selectThousands(true)

		pgHeader.visible = true
		pgHeader.mainMenu = false
		pgHeader.titleString = qsTrId("LBL_0325") + translator.emptyString
		pg_listStatusBar.visible = true
		pg_passcode.visible = false
		backEnd.setState(MyAppState.MM_1_INTERVAL)
		backEnd.setCurrentPage(pg_listStatusBar)
		console.log("Maintenance interval change page selected")
	}

	function upPressed()
	{
		if(layerdIndex === 0) {
			intervalLevels.increaseThousands()
		}
		else if(layerdIndex === 1) {
			intervalLevels.increaseHundreds()
		}
		else if(layerdIndex === 2) {
			intervalLevels.increaseTens()
		}
		else if(layerdIndex === 3) {
			intervalLevels.increaseUnits()
		}
	}

	function downPressed()
	{
		if(layerdIndex === 0) {
			intervalLevels.decreaseThousands()
		}
		else if(layerdIndex === 1) {
			intervalLevels.decreaseHundreds()
		}
		else if(layerdIndex === 2) {
			intervalLevels.decreaseTens()
		}
		else if(layerdIndex === 3) {
			intervalLevels.decreaseUnits()
		}
	}

	function enterPressed()
	{
		if(layerdIndex === 0) {
			layerdIndex = 1
			intervalLevels.selectThousands(false)
			intervalLevels.selectHundreds(true)
		}
		else if(layerdIndex === 1) {
			layerdIndex = 2
			intervalLevels.selectHundreds(false)
			intervalLevels.selectTens(true)
		}
		else if(layerdIndex === 2) {
			layerdIndex = 3
			intervalLevels.selectTens(false)
			intervalLevels.selectUnits(true)
		}
		else if(layerdIndex === 3) {
			intervalLevels.selectUnits(false)

			var intervalToSave = intervalLevels.validateInterval()
			//console.log(intervalToSave)

			pgHeader.visible = true
			pgHeader.mainMenu = false
			pgHeader.titleString = qsTrId("LBL_0325") + translator.emptyString
			pg_listStatusBar.saveIntervalValueValidated(intervalToSave)
			pg_listStatusBar.visible = true
			pg_passcode.visible = false
			backEnd.setState(MyAppState.MM_1_INTERVAL)
			backEnd.setCurrentPage(pg_listStatusBar)
			console.log("Interval change validated")

			layerdIndex = 0
			intervalLevels.selectThousands(true)
			pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5);
		}
	}


	Rectangle {
		id: levelsController
		width: parent.width
		height: parent.height
		color: parent.color

		Text {
			id: initValText
			font.pixelSize: 20
			font.family: systemFont
			text: qsTrId("LBL_0062") + translator.emptyString + " " + passcodeID.intervalValue
			color: color_white
			anchors {
				bottom: iconArrow.top
				bottomMargin: 5
				horizontalCenter: levelsController.horizontalCenter
			}
		}

		Text {
			id: hourmeterText
			font.pixelSize: 17
			font.family: systemFont
			text: "h"
			color: color_white
			anchors {
				left: initValText.right
				horizontalCenter: levelsController.horizontalCenter
				verticalCenter: initValText.bottom
				verticalCenterOffset: - hourmeterText.height / 2
			}
		}

		Image {
			id: iconArrow
			source: "qrc:/graphics/Menu/4.3 Arrow down - white.png"
			fillMode: Image.Pad
			anchors {
				top: parent.top
				topMargin: 100
				horizontalCenter: levelsController.horizontalCenter
			}
		}

		Comp_intervalChange {
			id: intervalLevels
			anchors {
				topMargin: 5
				top: iconArrow.bottom
			}
		}

	}
}

import QtQuick 2.11
import MyQmlModule 1.0

Item {
	id: header

	width: 320
	height: backEnd.currentConfig.headerHeight

	property bool isAutocontrolActive: pg_home.autoControlActive
	property bool mainMenu: true            // display design for home page or for other menues
	property string titleString: ""         // current time or title's menu
	property int errorLevel: 0              // Warning = 1, Attention = 2, Notification MCU = 3, Notification Screen = 4
	property bool isErrorVisible: false     // set to true when an error occur

	property var errorInfo: null
	property string dtcIconPict: ""
	property int currentErrorIndex: 0

	property string hourMeterString: isAutocontrolActive ? checkHourMeterString
														 : (canError18FEE747 ? minHourMeterString
																			 : dataEngine.opHours_Total.value > maxHourMeter ? maxHourMeterString
																															 : dataEngine.opHours_Total.value <= 0 ? "0.0"
																																								   : dataEngine.opHours_Total.value.toFixed(1))

	property string currentTime : "" // Current time

	property bool swapTimerBool: false // Use to swap the informations on main page header every 2 seconds : true -> current time and remaining time, false -> hour meter and remaining percentage


	onErrorInfoChanged: { // remove dtc icon pict when no current error
		if (!errorInfo) {
			dtcIconPict = "";
			return
		}

		if (currentErrorIndex >= errorManager.getCurrentErrorLength()) {
			currentErrorIndex = 0;
		}

		if (errorInfo.priority === 1) { //select the corresponding DTC icon
			if (errorInfo.dtcIconId === "A") {
				dtcIconPict = "qrc:/graphics/Header/3.8 Inverter DTC - Small - white.png";
			} else if (errorInfo.dtcIconId === "B") {
				dtcIconPict = "qrc:/graphics/Header/3.12 Motor DTC - Small - white.png";
			} else if (errorInfo.dtcIconId === "C") {
				dtcIconPict = "qrc:/graphics/Header/3.16 MCU DTC - Small - white.png";
			} else if (errorInfo.dtcIconId === "D") {
				dtcIconPict = "qrc:/graphics/Header/3.20 Temperature MCU DTC - Small - white.png";
			} else if (errorInfo.dtcIconId === "E") {
				dtcIconPict = "qrc:/graphics/Header/3.24 Charger DTC - Small - white.png";
			} else if (errorInfo.dtcIconId === "F") {
				dtcIconPict = "qrc:/graphics/Header/3.28 BMC DTC-Small - white.png";
			} else if (errorInfo.dtcIconId === "G") {
				dtcIconPict = "qrc:/graphics/Header/3.32 Battery temperature DTC - Small - white.png";
			} else if (errorInfo.dtcIconId === "H") {
				dtcIconPict = "qrc:/graphics/Header/3.36 Keypad - Small - white.png";
			} else if (errorInfo.dtcIconId === "I") {
				dtcIconPict = "qrc:/graphics/Header/3.40 LCD DTC - Small- white.png";
			} else
				dtcIconPict = "";
		} else {
			if (errorInfo.dtcIconId === "A") {
				dtcIconPict = "qrc:/graphics/Header/3.10 Inverter DTC - Small - black.png";
			} else if (errorInfo.dtcIconId === "B") {
				dtcIconPict = "qrc:/graphics/Header/3.14 Motor DTC - Small - black.png";
			} else if (errorInfo.dtcIconId === "C") {
				dtcIconPict = "qrc:/graphics/Header/3.18 MCU DTC - Small - black.png";
			} else if (errorInfo.dtcIconId === "D") {
				dtcIconPict = "qrc:/graphics/Header/3.22 Temperature MCU DTC - Small - black.png";
			} else if (errorInfo.dtcIconId === "E") {
				dtcIconPict = "qrc:/graphics/Header/3.26 Charger DTC - Small - black.png";
			} else if (errorInfo.dtcIconId === "F") {
				dtcIconPict = "qrc:/graphics/Header/3.30 BMS DTC -Small - black.png";
			} else if (errorInfo.dtcIconId === "G") {
				dtcIconPict = "qrc:/graphics/Header/3.34 Battery temperature DTC - Small - black.png";
			} else if (errorInfo.dtcIconId === "H") {
				dtcIconPict = "qrc:/graphics/Header/3.38 Keypad - Small - black.png";
			} else if (errorInfo.dtcIconId === "I") {
				dtcIconPict = "qrc:/graphics/Header/3.42 LCD DTC - Small - black.png";
			} else
				dtcIconPict = "";
		}
	}

	Connections {
		target: errorManager

		onCurrentErrorLenghtChanged: {
			if (errorManager.getCurrentErrorLength() === 0) {
				header.isErrorVisible = false;
				header.errorInfo = null;
				return;
			} else {
				header.currentErrorIndex = 0;
				header.isErrorVisible = true;
			}
		}
	}

	//Switch error messages or add a blinking effect if only one error
	Timer {
		id: blinkTimer
		interval: 2000
		running: true
		repeat: true
		onTriggered: {
			if (errorManager.getCurrentErrorLength() === 0)
				return;

			errorInfo = errorManager.getCurrentErrorAt(currentErrorIndex);
			if (errorManager.getCurrentErrorLength() === 100) { // blinking effect
				blinkTimer.interval = isErrorVisible ? 500 : 2000;
				isErrorVisible = !isErrorVisible;
			} else {
				currentErrorIndex = (currentErrorIndex + 1) % errorManager.getCurrentErrorLength();
				blinkTimer.interval = 2000;
				isErrorVisible = true;
			}
		}
	}

	// 1 seconds timer to refresh the current time
	Timer {
		id: timeTimer
		interval: 1000
		triggeredOnStart: true
		running: mainMenu
		repeat: true
		onTriggered: {
			currentTime = dateTimeManager.getCurrentTime()
		}
	}

	// Background of the header
	Rectangle {
		id: headerMargin
		height: parent.height - 2
		color: color_black
		anchors.fill: parent

		Image {
			id: headerBackgroundPict
			source: mainMenu ? "qrc:/graphics/Header/5.2 Bar on top home.png" : "qrc:/graphics/Header/5.2.1 Bar on top menu.png"
			height: mainMenu ? parent.height - 2 : parent.height - 3
			anchors.left: parent.left
			anchors.top: parent.top
			fillMode: Image.Pad
		}
	}

	// Left part of the header
	Item {
		id: remainingTimeOrTitleItem
		width: mainMenu ? 80 : 81 + errorBox.width + 3
		height: headerBackgroundPict.height
		anchors.left: parent.left

		// Text showed on the left part of the header
		// In the main page, text swaps between remaining time and remaining percentage
		Text {
			id: remainingTimeOrTitleText
			text: isV7 ? (isAutocontrolActive ? "AM 88:88" : (canError19F0102B && (backEnd.state === MyAppState.MAIN) && (dateTimeManager.getManualMode() === false)) ? (dateTimeManager.getTimeFormat() === "HH:mm") ? "00:00" : "AM 00:00" : mainMenu ? currentTime : titleString) : (isAutocontrolActive ? "888%" : titleString)
			color: color_white
			width: mainMenu ? (isV7 ? 80 : width) : 81 + errorBox.width + 6
			font {
                pixelSize: mainMenu ? 15 : 16
				family: systemFont
			}
			anchors{
				left: (mainMenu && !isV7) ? remainingTimeIcon.right : parent.left
				leftMargin: mainMenu ? 0 : 3
				verticalCenter: parent.verticalCenter
			}
			verticalAlignment: Text.AlignVCenter
			horizontalAlignment: (mainMenu && isV7) ? Text.AlignHCenter : Text.AlignLeft
			//wrapMode: Text.WordWrap
			elide: Text.ElideRight
			opacity: isAutocontrolActive ? 1 : (canError19F0102B && (backEnd.state === MyAppState.MAIN) && (dateTimeManager.getManualMode() === false)) ? (blinkingPictoIsVisible ? 1 : 0) : 1
		}

		// Icon of the remaining time, showed on the main menu
		Image {
			id: remainingTimeIcon
			source: "qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 20x20/6.98_Remaining time_WH.png"
			height: 20
			width: 20
			fillMode: Image.Pad
			anchors {
				left: parent.left
				verticalCenter: parent.verticalCenter
				leftMargin: 3
			}
			visible: mainMenu && !isV7 & swapTimerBool
		}
	}

	Rectangle {
		id: errorBox
		color: !errorInfo ? "transparent" : errorInfo.priority === 1 ? color_red : errorInfo.priority === 2 ? color_yellow_error : color_gray_error
		height: parent.height - 3
		width: 155
		x: 84
		anchors.top: parent.top
		anchors.topMargin: 1
		visible: mainMenu && isErrorVisible

		Image {
			id: errorIcon
			source: !errorInfo ? "" : errorInfo.priority === 1 ? "qrc:/graphics/Header/3.2 WARNING- Small - white.png" : errorInfo.priority === 2 ? "qrc:/graphics/Header/3.4 CAUTION - Small - black.png" : "qrc:/graphics/Header/3.7 Maintenance - Small - black.png"
			fillMode: Image.Pad
			anchors {
				left: parent.left
				leftMargin: 4
				verticalCenter: parent.verticalCenter
			}
		}

		Image {
			id: areaIcon
			source: dtcIconPict
			fillMode: Image.Pad
			width: 22
			height: parent.height
			anchors {
				left: parent.left
				leftMargin: 26
			}
			horizontalAlignment: Image.AlignHCenter
			verticalAlignment: Image.AlignVCenter
		}

		Text {
			id: errorMessage
			text: !errorInfo ? "" : errorInfo.dtcCode === "MAINTENANCE" ? (qsTrId("LBL_0057") + translator.emptyString).toUpperCase() : errorInfo.dtcCode.slice(2)
			color: !errorInfo ? color_black : errorInfo.priority === 1 ? color_white : color_black
			font.pixelSize: 15
			font.family: systemFont
			horizontalAlignment: Text.AlignLeft
			width: !errorInfo ? 101 : errorInfo.dtcCode === "MAINTENANCE" ? 131 : 101
			elide: Text.ElideRight
			anchors {
				right: parent.right
				verticalCenter: parent.verticalCenter
			}
		}
	}

	// Right part of the main header
	Item {
		id: hourMeterOrTime
		width: 80
		height: headerBackgroundPict.height
		anchors {
			right: parent.right
			top: parent.top
		}
		visible: true

		// Text on the right of the main header, swap between current time and hour meter
		Text {
			id: hourMeterOrTimeValue
			text: {
				if (isV7)
					(hourMeterString + "h")
				else if (isAutocontrolActive)
					"AM 88:88"
				else if (swapTimerBool && backEnd.state === MyAppState.MAIN)
					if (canError19F0102B && backEnd.state === MyAppState.MAIN && dateTimeManager.getManualMode() === false)
						if (dateTimeManager.getTimeFormat() === "HH:mm")
							"00:00"
						else
							"AM 00:00"
					else
						currentTime
				else
					(hourMeterString + "h")
			}

			color: color_white
			width : swapTimerBool && backEnd.state === MyAppState.MAIN ? 80 : 80 - hourMeterPict.width
			font {
                pixelSize: 15
				family: systemFont
			}
			anchors {
				right: parent.right
				rightMargin: 3
				bottom: hourMeterPict.bottom
                bottomMargin: 2
			}
			horizontalAlignment: (swapTimerBool && !isV7 && backEnd.state === MyAppState.MAIN) ? Text.AlignHCenter : Text.AlignRight
			opacity: isAutocontrolActive ? 1 : canError18FEE747 ? (blinkingPictoIsVisible ? 1 : 0) : 1
		}

		// Icon of the Hourglass, appears on the left of the hour meter
		Image {
			id: hourMeterPict
			source: "qrc:/graphics/Header/7.1 Hourmeter - home page - white.png"
			fillMode: Image.Pad
			anchors {
				left: parent.left
				verticalCenter: parent.verticalCenter
			}
			visible: isV7 || (!swapTimerBool && !isAutocontrolActive) || (backEnd.state !== MyAppState.MAIN && !isAutocontrolActive)
		}
	}
}

import QtQuick 2.0
import MyQmlModule 1.0
import "../components"

Item {
	id: sootLevelID

	height: parent.height - backEnd.currentConfig.headerHeight
	width: parent.width
	anchors.topMargin: backEnd.currentConfig.headerHeight

	property int outlineThick: 2
	property int sootLevelState: dataEngine.dPFSootState.value
	property int sootLevelValue: dataEngine.dPFSootLoad.value
	property int sootLevelValueShow

	property string iconPict: "qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 70x70/6.92_Road vehicle, filter_WH.png"

	onVisibleChanged: {
		// Error case
		 if(sootLevelValue === 254){
		   sootLevelValueShow = -1
		}
		else if(sootLevelValue <= 250){
			sootLevelValueShow = sootLevelValue
		}
		else {
			sootLevelValueShow = 0
		}

		// Invalid value case
		if(visible === true && (sootLevelValueShow < 0 || sootLevelValueShow > 250 || canError18FFCC47)) {
			visible = false
			backEnd.setState(MyAppState.MAIN)
			backEnd.setCurrentPage(pg_home)
			pg_home.visible = true
			pgHeader.visible = true
			pgHeader.mainMenu = true
			pgHeader.titleString = "AM 08:00"
			rectList.visible = false
			rectMenu.visible = false
		}
	}

	onSootLevelValueChanged: {
		// Error case
		if(sootLevelValue === 254){
		   sootLevelValueShow = -1
		}
		else if(sootLevelValue <= 250){
			sootLevelValueShow = sootLevelValue
		}
		else {
			sootLevelValueShow = 0
		}

	   // Invalid value case
		if(visible === true && (sootLevelValueShow < 0 || sootLevelValueShow > 250 || canError18FFCC47)) {
			visible = false
			backEnd.setState(MyAppState.MAIN)
			backEnd.setCurrentPage(pg_home)
			pg_home.visible = true
			pgHeader.visible = true
			pgHeader.mainMenu = true
			pgHeader.titleString = "AM 08:00"
		}
	}

	function menuPressed() {
		backEnd.setState(MyAppState.FILTER_REGENERATION)
		backEnd.setCurrentPage(pg_listStatusBar)
		pg_listStatusBar.visible = true
		pg_sootLevel.visible = false
		pgHeader.visible = true
		pgHeader.mainMenu = false
		pgHeader.titleString = qsTrId("LBL_0353") + translator.emptyString
	}

	function upPressed()
	{
		console.log("Ash level")
		backEnd.setState(MyAppState.ASH_LEVEL)
		backEnd.setCurrentPage(pg_ashLevel)
		pg_sootLevel.visible = false
		pgHeader.titleString = qsTrId("LBL_0309") + translator.emptyString
		pg_ashLevel.visible = true
		pg_listStatusBar.selectedIndex = 1
		pg_listStatusBar.currentIndex = 1
	}

	function downPressed()
	{
		upPressed();
	}

	// Background
	Rectangle {
		id: sootLevelBackground
		width: parent.width
		height: parent.height
		color: color_gray
		border {
			color: color_gray_bar
			width: outlineThick
		}
	}

	// Top data
	Rectangle {
		id: sootLevelTopContainer
		width: parent.width - comp_navigationBar.width
		height: 72
		color: color_gray

		Image {
			id: sootLevelIcon
			anchors {
				left: parent.left
				leftMargin: 35
				verticalCenter: parent.verticalCenter
			}
			fillMode: Image.Pad
			source: iconPict
		}

		Rectangle {
			id: backgroundText
			width: sootLevelTopContainer.width / 2
			height: parent.height - (outlineThick * 2)
			color: color_gray
			anchors {
				right: parent.right
				rightMargin: outlineThick
				verticalCenter: parent.verticalCenter
			}

			Text {
				id: textStatusBar
				color:  color_white
				font.pixelSize: sootLevelValue > 250 ? 20 : 70
				font.family: systemFont
				anchors {
					verticalCenter: parent.verticalCenter
					horizontalCenter: parent.horizontalCenter
				}
				//text: sootLevelValue === 254 ? "ERROR" : sootLevelValueShow // TODO translation
				text: sootLevelValue <= 250 ? sootLevelValueShow : (sootLevelValue === 255 ? "NOT AVAILABLE" : "ERROR")
			}
		}
	}

	// Gauge component
	Rectangle {
		id: sootLevelGaugeContainer
		width: sootLevelTopContainer.width + outlineThick
		height: 110
		color: color_gray
		anchors {
			leftMargin: 0
			left: parent.left
			topMargin: 0
			top: sootLevelTopContainer.bottom
		}
		border {
			color:  color_gray_bar
			width: outlineThick
		}

		Comp_gauge {
			id: sootLevelGauge
			gaugeValue: sootLevelValueShow
			gaugeState: sootLevelState
			gaugeRange: 150
			gaugeIncrement: 1
		}
	}

	// Error message if sensor failure
	Text {
		id: sootLevelMessage
		text:
		{
			if(sootLevelState === 0) {
				return "Normal mode"
			} else if (sootLevelState === 0x1) {
				return "Heatmode1 requested"
			} else if (sootLevelState === 0x2) {
				return "Heatmode2 requested"
			} else if (sootLevelState === 0x3) {
				return "Regeneration needed LL"
			} else if (sootLevelState === 0x4) {
				return "Regeneration needed HL"
			} else if (sootLevelState === 0x5) {
				return "Service regeneration needed"
			} else if (sootLevelState === 0x6) {
				return "Filter exchange required"
			} else if (sootLevelState === 0xE) {
				return "Sensor failure"
			} else
				return "";
		}
		color: color_white
		font.pixelSize: 22
		font.family: systemFont
		anchors {
			left: parent.left
			bottom: parent.bottom
			leftMargin: 10
		}
	}
}

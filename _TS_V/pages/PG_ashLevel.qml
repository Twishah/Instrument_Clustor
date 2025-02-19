import QtQuick 2.0
import MyQmlModule 1.0
import "../components"

Item {
	id: ashLevelID

	height: parent.height - backEnd.currentConfig.headerHeight
	width: parent.width
	anchors.topMargin: backEnd.currentConfig.headerHeight

	property int outlineThick: 2
	property int ashLevelState: dataEngine.dPFAshloadState.value
	property int ashLevelValue: dataEngine.dPFAshLoad.value
	property int ashLevelValueShow

	property string iconPict: "qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 70x70/6.120_Soot_WH.png"


	onVisibleChanged: {
		// Error case
		if(ashLevelValue === 254){
		   ashLevelValueShow = -1
		}
		else if(ashLevelValue <= 250){
			ashLevelValueShow = ashLevelValue
		}
		else {
			ashLevelValueShow = 0
		}

		// Invalid value case
		if(visible === true && (ashLevelValueShow < 0 || ashLevelValueShow > 250 || canError18FFCC47)) {
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

	onAshLevelValueChanged: {
		// Error case
		if(ashLevelValue === 254){
		   ashLevelValueShow = -1
		}
		// No change case
		else if(ashLevelValue <= 250){
			ashLevelValueShow = ashLevelValue
		}
		else {
			ashLevelValueShow = 0
		}
		// Invalid value case
		if(visible === true && (ashLevelValueShow < 0 || ashLevelValueShow > 250 || canError18FFCC47)) {
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
		pg_ashLevel.visible = false
		pgHeader.visible = true
		pgHeader.mainMenu = false
		pgHeader.titleString = qsTrId("LBL_0353") + translator.emptyString
	}

	function upPressed()
	{
		console.log("Soot level")
		backEnd.setState(MyAppState.SOOT_LEVEL)
		backEnd.setCurrentPage(pg_sootLevel)
		pg_ashLevel.visible = false
		pgHeader.titleString = qsTrId("LBL_0308") + translator.emptyString
		pg_sootLevel.visible = true
		pg_listStatusBar.selectedIndex = 0
		pg_listStatusBar.currentIndex = 0
	}

	function downPressed()
	{
		upPressed();
	}


	// Background
	Rectangle {
		id: ashLevelBackground
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
		id: ashLevelTopContainer
		width: parent.width - comp_navigationBar.width
		height: 72
		color: color_gray

		Image {
			id: ashLevelIcon
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
			width: ashLevelTopContainer.width / 2
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
				font.pixelSize: ashLevelValue > 250 ? 20 : 70
				font.family: systemFont
				anchors {
					verticalCenter: parent.verticalCenter
					horizontalCenter: parent.horizontalCenter
				}
//              text: ashLevelValue === 254 ? "ERROR" : (ashLevelValue === 255 ? "NOT AVAILABLE" : ashLevelValueShow)
				text: ashLevelValue <= 250 ? ashLevelValueShow : (ashLevelValue === 255 ? "NOT AVAILABLE" : "ERROR")
			}
		}
	}

	// Gauge component
	Rectangle {
		id: ashLevelGaugeContainer
		width: ashLevelTopContainer.width + outlineThick
		height: 110
		color: color_gray
		anchors {
			leftMargin: 0
			left: parent.left
			topMargin: 0
			top: ashLevelTopContainer.bottom
		}
		border {
			color:  color_gray_bar
			width: outlineThick
		}

		Comp_gauge {
			id: ashLevelGauge
			gaugeValue: ashLevelValueShow
			gaugeState: ashLevelState
			gaugeRange: 150
			gaugeIncrement: 1
		}
	}

	// Error message if sensor failure
	Text {
		id: ashLevelMessage
		text:
		{
			if(ashLevelState === 0) {
				return "Normal"
			} else if (ashLevelState === 0x1){
				return "Service in 150h"
			} else if (ashLevelState === 0x2){
				return "Filter exchange required"
			} else if (ashLevelState === 0x3){
				return "Warning state"
			} else if (ashLevelState === 0x4){
				return "Locking state"
			} else if (ashLevelState === 0xE){
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

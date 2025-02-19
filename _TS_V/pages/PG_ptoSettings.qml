import QtQuick 2.6
import MyQmlModule 1.0
import QtGraphicalEffects 1.0
import "../components"

// Seite zum Einstellen der PTOs

Item {
	id: ptoSettingsID
	height: 320
	width: 240
	anchors.topMargin: backEnd.currentConfig.headerHeight

	property int layerdIndex: 0 // index depth level, used when there is a sub navigation after pressed "enter" button
	property int menuIndex: 1 // Menu index, used when pressed "up" or "bottom" button
	property int pto1SubIndex: 0
	property int pto2SubIndex: 0
	property int presetIndex: 0

	property string accessory_icon_sourceTemp: "" // Current flow settings changes
	property int pto1Temp_left: 10
	property int pto1Temp_right: 10
	property int pto2Temp_left: 10
	property int pto2Temp_right: 10
	property int backValue: 0

	onVisibleChanged: {

		if(visible === true)
		{
			console.log("Page PG_ptosettings entered")
		}
	}

	function resetIndexes()
	{
		menuIndex = 1
		layerdIndex = 0
	}

	function menuPressed()
	{
		if (layerdIndex === 0) {
			pgHeader.visible = true
			pgHeader.mainMenu = false
			pgHeader.titleString = qsTrId("LBL_0029") + translator.emptyString

			pg_lineStatusBarIcon.visible = true
			pg_ptoSettings.visible = false
			backEnd.setState(MyAppState.PTO_SET)
			backEnd.setCurrentPage(pg_lineStatusBarIcon)
		} else if (layerdIndex === 1)  {
			layerdIndex = 0
		} else if (layerdIndex === 2)  {
			if (menuIndex === 1 && pto1SubIndex === 0) {
				pto1Temp_left = backValue
				pto1Temp_right = backValue
			} else if (menuIndex === 1 && pto1SubIndex === 1) {
				pto1Temp_left = backValue
				pto1Temp_right = backValue
			} else if (menuIndex === 2 && pto2SubIndex === 0) {
				pto2Temp_right = backValue
				pto2Temp_left = backValue
			} else if (menuIndex === 2 && pto2SubIndex === 1) {
				pto2Temp_left = backValue
				pto2Temp_right = backValue
			}
			layerdIndex = 1
		}
	}

	function upPressed()
	{
		if (layerdIndex === 0)
			menuIndex = (menuIndex - 1 + 4) % 4
		else if (layerdIndex === 1) {
			if (menuIndex === 1)
				pto1SubIndex = (pto1SubIndex - 1 + 2) % 2
			else if (menuIndex === 2)
				pto2SubIndex = (pto2SubIndex - 1 + 2) % 2
		} else if (layerdIndex === 2) {
			if (menuIndex === 1 && pto1SubIndex === 0 && pto1Temp_left < 10)
			{
				pto1Temp_left++
				pto1Temp_right++
			}
			else if (menuIndex === 1 && pto1SubIndex === 1 && pto1Temp_right < 10)
			{
				pto1Temp_left++
				pto1Temp_right++
			}
			else if (menuIndex === 2 && pto2SubIndex === 0 && pto2Temp_left < 10)
			{
				pto2Temp_left++
				pto2Temp_right++
			}
			else if (menuIndex === 2 && pto2SubIndex === 1 && pto2Temp_right < 10)
			{
				pto2Temp_left++
				pto2Temp_right++
			}
		}
	}

	function downPressed()
	{
		if (layerdIndex === 0)
			menuIndex = (menuIndex + 1) % 4
		else if (layerdIndex === 1) {
			if (menuIndex === 1)
				pto1SubIndex = (pto1SubIndex + 1) % 2
			else if (menuIndex === 2)
				pto2SubIndex = (pto2SubIndex + 1) % 2
		} else if (layerdIndex === 2) {
			if (menuIndex === 1 && pto1SubIndex === 0 && pto1Temp_left > 1 )
			{
				pto1Temp_right--
				pto1Temp_left--
			}
			else if (menuIndex === 1 && pto1SubIndex === 1 && pto1Temp_right > 1)
			{
				pto1Temp_right--
				pto1Temp_left--
			}
			else if (menuIndex === 2 && pto2SubIndex === 0 && pto2Temp_left > 1)
			{
				pto2Temp_right--
				pto2Temp_left--
			}
			else if (menuIndex === 2 && pto2SubIndex === 1 && pto2Temp_right > 1)
			{
				pto2Temp_right--
				pto2Temp_left--
			}
		}
	}

	function enterPressed()
	{
		if (layerdIndex === 0) { // select an option: icon selection, PTO1, PTO2, OK
			if (menuIndex === 0) { // icon selection
				backEnd.setState(MyAppState.PTO_2_ICON)
				backEnd.setCurrentPage(pg_largeListSelection)
				setSelectedAccLogo()
				pg_largeListSelection.visible = true
				pg_ptoSettings.visible = false

				pgHeader.visible = true
				pgHeader.mainMenu = false
				pgHeader.titleString = qsTrId("LBL_0035") + translator.emptyString
			} else if (menuIndex === 1 && adjustAddCtrlCircuit1Visible === 1) { // PTO1
				layerdIndex = 1
				pto1SubIndex = 0
			} else if (menuIndex === 2 && adjustAddCtrlCircuit2Visible === 1) { // PTO2
				layerdIndex = 1
				pto2SubIndex = 0
			} else if (menuIndex === 3) { // OK
				pg_lineStatusBarIcon.selectedPresetIndex = presetIndex
				dm.indexPTO = pg_lineStatusBarIcon.selectedPresetIndex + 1
				dm.save_indexPTO()

				dm.getPtoSettings(presetIndex).accessory_icon_source = accessory_icon_sourceTemp
				dm.getPtoSettings(presetIndex).pto1_left = pto1Temp_left
				dm.getPtoSettings(presetIndex).pto1_right = pto1Temp_right
				dm.getPtoSettings(presetIndex).pto2_left = pto2Temp_left
				dm.getPtoSettings(presetIndex).pto2_right = pto2Temp_right

				dm.savePtoSettings();

				pg_home.updatePtoSetting()

				pgHeader.visible = true
				pgHeader.mainMenu = false
				pgHeader.titleString = qsTrId("LBL_0029") + translator.emptyString

				pg_lineStatusBarIcon.visible = true
				pg_ptoSettings.visible = false
				backEnd.setState(MyAppState.PTO_SET)
				backEnd.setCurrentPage(pg_lineStatusBarIcon)
				pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5);
			}
		} else if (layerdIndex === 1) { // select a gauge of PTO
			if (menuIndex === 1 && pto1SubIndex === 0) { //select left gauge of PTO1
				backValue = pto1Temp_left
			} else if (menuIndex === 1 && pto1SubIndex === 1) { //select right gauge of PTO1
				backValue = pto1Temp_right
			} else if (menuIndex === 2 && pto2SubIndex == 0) { //select left gauge of PTO2
				backValue = pto2Temp_left
			} else if (menuIndex === 2 && pto2SubIndex == 1) { //select right gauge of PTO2
				backValue = pto2Temp_right
			}
			layerdIndex = 2
		} else if (layerdIndex === 2) { // validate a PTO gauge and go back to the PTO gauge selection
			if (menuIndex === 1 && pto1SubIndex === 0) { //validate left PTO1 gauge
				layerdIndex = 1
			} else if (menuIndex === 1 && pto1SubIndex === 1) { //validate right PTO1 gauge
				layerdIndex = 1
			} else if (menuIndex === 2 && pto2SubIndex === 0) { //validate left PTO2 gauge
				layerdIndex = 1
			} else if (menuIndex === 2 && pto2SubIndex === 1) { //validate right PTO2 gauge
				layerdIndex = 1
			}
		}
	}

	function setSelectedAccLogo() {
		if (accessory_icon_sourceTemp === "qrc:/graphics/02_Main_Icons PNG/02_Main_Icons PNG 25x25/2.111 AUX") {
			pg_largeListSelection.selectedIndex = 0;
		}
		else if (accessory_icon_sourceTemp === "qrc:/graphics/02_Main_Icons PNG/02_Main_Icons PNG 25x25/2.105_Forage harvester_ cutterhead") {
			pg_largeListSelection.selectedIndex = 1;
		}
		else if (accessory_icon_sourceTemp === "qrc:/graphics/02_Main_Icons PNG/02_Main_Icons PNG 25x25/2.106 Rotary brush") {
			pg_largeListSelection.selectedIndex = 2;
		}
		else if (accessory_icon_sourceTemp === "qrc:/graphics/02_Main_Icons PNG/02_Main_Icons PNG 25x25/2.110 Mulcher") {
			pg_largeListSelection.selectedIndex = 3;
		}
		else if (accessory_icon_sourceTemp === "qrc:/graphics/02_Main_Icons PNG/02_Main_Icons PNG 25x25/2.108 Trencher conveyor") {
			pg_largeListSelection.selectedIndex = 4;
		}
		else if (accessory_icon_sourceTemp === "qrc:/graphics/02_Main_Icons PNG/02_Main_Icons PNG 25x25/2.104_Loader bucket grapple") {
			pg_largeListSelection.selectedIndex = 5;
		}
		else if (accessory_icon_sourceTemp === "qrc:/graphics/02_Main_Icons PNG/02_Main_Icons PNG 25x25/2.109 Vibration plate") {
			pg_largeListSelection.selectedIndex = 6;
		}
		pg_largeListSelection.currentIndex =  pg_largeListSelection.selectedIndex;
		pg_largeListSelection.resetY();
	}

	Image {
		id: backgroundPagePicture

		fillMode: Image.Pad
		source: "qrc:/graphics/PtoSettings/5.32 Frame flow limit acc.png"
		anchors {
			left: parent.left
			top: parent.top
			topMargin: -26
			leftMargin: -1
		}
	}

	Rectangle {
		id: accIconHighlight

		width: 273
		height: 39
		color: menuIndex === 0 ? color_blue : color_gray_bar
		anchors {
			top: parent.top
			left: parent.left
		}

		Text {
			id: accIconText
			text: qsTrId("LBL_0035") + translator.emptyString
			font.pixelSize: 16
			font.family: systemFont
			color:  color_white
			anchors {
				left: parent.left
				leftMargin: 10
				verticalCenter: parent.verticalCenter
			}
		}

		Rectangle {
			id: accIconPictureBackground

			width: 68
			height: 35
			color: color_gray
			anchors {
				top: parent.top
				left: parent.left
				topMargin: 2
				leftMargin: 204
			}
			Image {
				id: accIconPictIcon
				fillMode: Image.Pad
				source: accessory_icon_sourceTemp === "" ? "" : accessory_icon_sourceTemp + "_WH.png"
				anchors {
					horizontalCenter: parent.horizontalCenter
					verticalCenter: parent.verticalCenter
				}
			}
		}
	}

	Comp_ptoSettingGauge {
		id: pto1

		title: "AUX1"
		colorRect: menuIndex === 1 && layerdIndex == 0 ? color_blue : "transparent"
		z: menuIndex === 1 ? 1 : 0
		anchors.top: accIconHighlight.bottom

		leftGaugePict: menuIndex === 1 && layerdIndex === 2 && pto1SubIndex === 0 ? "qrc:/graphics/PtoSettings/FramePTO" + pto1Temp_left  + "Blue.png" : "qrc:/graphics/PtoSettings/FramePTO" + pto1Temp_left  + ".png"
		rightGaugePict: menuIndex === 1 && layerdIndex === 2 && pto1SubIndex === 1 ? "qrc:/graphics/PtoSettings/FramePTO" + pto1Temp_right  + "Blue.png" : "qrc:/graphics/PtoSettings/FramePTO" + pto1Temp_right  + ".png"
		leftGaugePictHighlight: menuIndex === 1 && layerdIndex === 1 && pto1SubIndex === 0 ? true : false
		rightGaugePictHighlight: menuIndex === 1 && layerdIndex === 1 && pto1SubIndex === 1 ? true : false
	}

	Comp_ptoSettingGauge {
		id: pto2

		title: "AUX2"
		colorRect: menuIndex === 2 && layerdIndex == 0 ? color_blue : "transparent"
		anchors.bottom: validationRowBackground.top
		z: menuIndex === 2 ? 1 : 0

		leftGaugePict: menuIndex === 2 && layerdIndex === 2 && pto2SubIndex === 0 ? "qrc:/graphics/PtoSettings/FramePTO" + pto2Temp_left  + "Blue.png" : "qrc:/graphics/PtoSettings/FramePTO" + pto2Temp_left  + ".png"
		rightGaugePict: menuIndex === 2 && layerdIndex === 2 && pto2SubIndex === 1 ? "qrc:/graphics/PtoSettings/FramePTO" + pto2Temp_right  + "Blue.png" : "qrc:/graphics/PtoSettings/FramePTO" + pto2Temp_right  + ".png"
		leftGaugePictHighlight: menuIndex === 2 && layerdIndex === 1 && pto2SubIndex === 0 ? true : false
		rightGaugePictHighlight: menuIndex === 2 && layerdIndex === 1 && pto2SubIndex === 1 ? true : false
	}

	Rectangle {
		id: validationRowBackground

		width: 273
		height: 39
		color:  menuIndex === 3 ? color_blue : color_gray_bar
		anchors {
			bottom: parent.bottom
			bottomMargin: 1
			left: parent.left
		}
		Rectangle {
			id: validationRowTextBackground

			width: 68
			height: 35
			color: color_gray
			anchors {
				top: parent.top
				left: parent.left
				topMargin: 3
				leftMargin: 204
			}
			Text {
				id: validationRowText
				text: "OK"
				font.pixelSize: 20
				font.family: systemFont
				color:  color_white
				anchors {
					horizontalCenter: parent.horizontalCenter
					verticalCenter: parent.verticalCenter
				}
			}
		}
	}
}

import QtQuick 2.0

Item {
	id: mainIndicatorsItem
	width: 320
	height: 240 - 2 * backEnd.currentConfig.headerHeight - 10
	y: backEnd.currentConfig.headerHeight

	property bool mainMenu: false                           // display design for main menu or sub menu
	property bool isAutocontrolActive: homeID.autoControlActive

	property int  blinkerLeftCan: dataEngine.ind_BlinkerLeft.value
	property int  highBeamCan: dataEngine.ind_HighBeam.value
	property int  drivingDirectionCan: dataEngine.ind_DrivingDirection.value

	property bool isChangingPtoSettings: false

	property bool isDesactivated: false
	property int selectedIndexPtoSet: dm.indexPTO
	property int currentIndexPtoSet: dm.indexPTO
	property string ptoSettingIconSrc: dm.indexPTO > 0 ? dm.getPtoSettings(dm.indexPTO - 1).accessory_icon_source : ""  // current pto setting icon

	property bool toggle: true;

	onToggleChanged: {
		gearIndicatorIcon.updateToggle(toggle);
		driveDirectionIcon.updateToggle(toggle);
		flasherRightIcon.updateToggle(toggle);
		flasherLeftIcon.updateToggle(toggle);
		highBeamIcon.updateToggle(toggle);
	}

	function saveIndexPtoSetting() {
		if (currentIndexPtoSet > 0) {
			dm.indexPTO = currentIndexPtoSet
			isDesactivated = false
		}
		else {
			dm.indexPTO = 0
			isDesactivated = true
		}
		dm.save_indexPTO()
	}

	function revertIndexPtoSetting() {
		currentIndexPtoSet = selectedIndexPtoSet
	}

	onCurrentIndexPtoSetChanged: {
		if (currentIndexPtoSet > 0)
		{
			ptoSettingIconSrc = dm.getPtoSettings(currentIndexPtoSet - 1).accessory_icon_source
		}
		else {
			ptoSettingIconSrc = ""
		}
	}

	Comp_noticePicto{
		   id: gearIndicatorIcon

		   width: 34
		   height: 34
		   x: parent.width/2 + 28 //  - 5
		   y: parent.height/2 + 35 // - 20

		   nbSignal: 1

		   signal1: isAutocontrolActive ? 1 : dataEngine.ind_RabbitTurtle.value
		   signal1Source: signal1Value === 2 && !signal1canError ? "qrc:/graphics/02_Main_Icons PNG/02_Main_Icons PNG 34x34/2.01_Turtle.png" : "qrc:/graphics/02_Main_Icons PNG/02_Main_Icons PNG 34x34/2.14_Rabbit.png"
		   signal1canError: canError18FFC047
		   noBlink: true

		   visible: true
	   }

	// Picto for PTO settings
	Image {
		id: ptoSettingsIcon
		width: 34
		height: 34
		x: parent.width/2 - 62 + 10
		y: parent.height/2 + 35 - 20 - 5 - 4//-5
		source: pg_home.autoControlActive ? "qrc:/graphics/02_Main_Icons PNG/02_Main_Icons PNG 34x34/2.106 Rotary brush_GN.png" : ptoSettingIconSrc === "" ? "" : ptoSettingIconSrc + "_GN.png"
		fillMode: Image.Pad
		visible: mainIndicatorsItem.mainMenu
	}

	// Picto for driving direction (N, forward or backward)
	Comp_noticePicto{
		   id: driveDirectionIcon

		   width: 30
		   height: 30
		   x: parent.width/2 - width/2
		   y: 87

		   nbSignal: 1

		   signal1: isAutocontrolActive ? 1 : dataEngine.ind_DrivingDirection.value
		   signal1Source: signal1Value === 2 ? "qrc:/graphics/02_Main_Icons PNG/02_Main_Icons PNG 30x30/2.03_Reverse.png" : signal1Value === 1 ? "qrc:/graphics/02_Main_Icons PNG/02_Main_Icons PNG 30x30/2.02_Forward.png" : "qrc:/graphics/02_Main_Icons PNG/02_Main_Icons PNG 30x30/2.04_N green.png"
           signal1SourceAt0: "qrc:/graphics/02_Main_Icons PNG/02_Main_Icons PNG 30x30/2.04_N green.png"
		   signal1canError: canError18FFC047 || dataEngine.ind_DrivingDirection_Blink.value === 1
		   noBlink: true

		   visible: true
	   }

	// Picto of the right flasher
	Comp_noticePicto{
		   id: flasherRightIcon

		   width: 25
		   height: 25
		   x: parent.width/2 + 94
		   y: 28

		   nbSignal: 1

		   signal1: isAutocontrolActive ? 1 : dataEngine.ind_BlinkerRight.value
		   signal1Source: "qrc:/graphics/02_Main_Icons PNG/02_Main_Icons PNG 25x25/2.13_Flasher right.png"
		   signal1canError: canError18FFC047

		   visible: true
	   }

	// Picto of the left flasher
	Comp_noticePicto{
		   id: flasherLeftIcon

		   width: 25
		   height: 25
		   x: parent.width/2 - 119
		   y: 28

		   nbSignal: 1

		   signal1: isAutocontrolActive ? 1 : dataEngine.ind_BlinkerLeft.value
		   signal1Source: "qrc:/graphics/02_Main_Icons PNG/02_Main_Icons PNG 25x25/2.12_Flasher left.png"
		   signal1canError: canError18FFC047

		   visible: true
	   }

	// Picto for high beam
	Comp_noticePicto{
		   id: highBeamIcon

		   width: 25
		   height: 25
		   x: parent.width/2 + 18 + 4
		   y: parent.height/2 + 10

		   nbSignal: 1

		   signal1: isAutocontrolActive ? 1 : dataEngine.ind_HighBeam.value
		   signal1Source: "qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 25x25/6.121_High beam_BU.png"
		   signal1canError: canError18FFC047

		   visible: true
	   }

	Timer {
		id: updatePicto

		running: isAutocontrolActive? false : true
		repeat: true
		interval: 100
		onTriggered:
		{
			gearIndicatorIcon.updateValues();
			gearIndicatorIcon.updateSource();

			driveDirectionIcon.updateValues();
			driveDirectionIcon.updateSource();

			flasherRightIcon.updateValues();
			flasherRightIcon.updateSource();

			flasherLeftIcon.updateValues();
			flasherLeftIcon.updateSource();

			highBeamIcon.updateValues();
			highBeamIcon.updateSource();
		}
	}
}

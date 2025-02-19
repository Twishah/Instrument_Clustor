/******************************************************************************
 * main top item

	Mechanical Mode 1:
		1. Key on
		2. The home screen is displayed.
		3. Press and hold the up button (soft key 1) and Menu button (soft key 3) for 10 seconds
			(accuracy of holding time : 10%)

	Mechanical Mode 2:
		1. Key on
		2. The home screen is displayed or Mechanic Mode Level display.
		3. Press -while pressing the up button (soft key 1)- the
			down button (soft key 2)
			OK button (soft key 3)
			Menu button (soft key 4)
			down button (soft key 2)


******************************************************************************/

import QtQuick 2.6
import QtQuick.Particles 2.0
import QtGraphicalEffects 1.0
import MyQmlModule 1.0
import "./components"
import "./pages"

Item {
	id: root

	//property string colordef_ccPink: "#ffffa0a0" // CC type of pink(?)
	property string colordef_ccRed: "#ffd23e42" // CC type of red
	property string colordef_ccGreen: "#ff9cc647" // CC type of green
	property string colordef_ccOrange: "#fff39200" // CC logo orange
	property string colordef_ccLightGray: "#ff646363" // CC logo light gray
	property string colordef_ccDarkGray: "#ff262626" // CC type of dark gray

	// Colors definitions
	property string color_black: "#ff000000"
	property string color_yellow: "#ffffed00"
	property string color_yellow_error: "#ffefb71b"
	property string color_red: "#ffe31e24"
	property string color_white: "#ffffffff"
	property string color_green: "#ff6ab82d"
	property string color_blue: "#ff2080b3"

	// Other color definitions
	property string color_gray: "#ff333333"
	property string color_gray_bar: "#ff5b5a59" // dorpdownbar, header/footer home,
	property string color_gray_popup: "#ff464646"
	property string color_gray_error: "#ff9b9b9b"
	property string color_gray_separator: "#ff3b3b3b"

	property int    m_currIndex: 0
	property string systemFont: "DFPGothicP-W5-OEM-90"

	property bool checkPreheatingOpt: true // check if the machine has a preheating option
	property bool checkImmobilizerStartup: true // check if the machine has an immobilizer

	property string version: "SW: 0.9.4"

	property bool readyForInit: false
	property bool checkMachineType: true // check if V7 or V8e
	property bool isV7: false // V7 or V8e
	property bool isV8e: false // V7 or V8e

	property bool isDev: false // Change visibilty in dev mode

	property bool optPreheatingAtStartup: false

	property int factoryResetCntSec: 0

	property bool bImmobilizerOnOffTriggerSignal: false

	property var enteredOwnerPin: "FFFF";
	property var enteredPin: "FFFF";

	property int s32MyLastState: 0xFF

	property var u8ImmoByte0: 255 // Can-Msg-Bytes 0 - 7 for Immo
	property var u8ImmoByte1: 255 //
	property var u8ImmoByte2: 255 //
	property var u8ImmoByte3: 255 //
	property var u8ImmoByte4: 255 //
	property var u8ImmoByte5: 255 //
	property var u8ImmoByte6: 255 //
	property var u8ImmoByte7: 255 //


	// CAN errors properties
//	property bool blinkingPictoIsVisible: false
	property bool blinkingPictoIsVisible: pg_home.toggle
	property bool frameTimeoutError: false
	property bool canErrorAny: false
	property bool canErrorMCU: false
	property bool canErrorTCU: false
	property bool canErrorECU: false
	property bool canErrorSAR: false
	property bool canError18FEF147: !false
	property bool canError18FFC047: !false
	property bool canError18FFC147: !false
	property bool canError18FFC447: !false
	property bool canError18FFCB47: !false
	property bool canError18FFCC47: !false
	property bool canError18FFCE47: !false
	property bool canError18FFCF47: !false
	property bool canError18FEE747: !false
	property bool canError18FFE047: !false
	property bool canError18FFC347: !false
	property bool canError18FFD747: !false
	property bool canError18FFAE47: !false
	property bool canError18FFAF47: !false
	property bool canError18FED931: !false
	property bool canError18FF2B03: !false
	property bool canErrorCFF7147:  !false
	property bool canError18F11447: !false
	property bool canError18FEDA03: !false
	property bool canError18FEDA47: !false
	property bool canError18FEF700: !false
	property bool canError18FF1100: !false
	property bool canErrorCF00400:  !false
	property bool canError18FEF200: !false
	property bool canError18FF2403: !false
	property bool canErrorCF003FE:  !false
	property bool canError19F0102B: !false
	property bool canError18FF8447: !false
	property bool canError18FEDB00: !false
	property bool canError18FF2703: !false
	property bool canError18A72847: !false

	property bool canErrorEcoModeSw: false // Not connected to CAN
	property bool canErrorAutoIdleSw: false // Not connected to CAN
	property bool canErrorAutoShutdownSw: false // Not connected to CAN
	property bool canErrorPTO: false // Not connected to CAN
	property bool canErrorAutoIdleHours: false // Not connected to CAN
	property bool canErrorAutoShutdownHours: false // Not connected to CAN
	property bool canErrorBMSState: false // Not connected to CAN
	property bool canErrorInverterState: false // Not connected to CAN
	property bool canErrorFuncMotorState: false // Not connected to CAN
	property bool canErrorBatteryVoltage12V: false // Not connected to CAN
	property bool canErrorCoolingFanSpeed: false // Not connected to CAN
	property bool canErrorHydraulicOilMaintenance: false // Not connected to CAN
	property bool canErrorMCUSoftVersion: false // Not connected to CAN
	property bool canErrorMCUSoftPartNum: false // Not connected to CAN
	property bool canErrorHydraulicTemp: false // Not connected to CAN

	// RTC auto from MCU
	property int mcuRtcYear: 2024
	property int mcuRtcMonth: 4
	property int mcuRtcDay: 11
	property int mcuRtcHour: 12
	property int mcuRtcMinutes: 00
	property int mcuRtcSeconds: 00

	property double maxHourMeter: 99999.9
	property string maxHourMeterString: "99999.9"
	property string minHourMeterString: "00000.0"
	property string checkHourMeterString: "88888.8"

	property int currentDriveMode: 0
	property bool checkDriveMode: true

	property bool buzz7: true
	property int mcuBuzz: 0
	property int mcuBuzz_prev: 0
	property int mcuScreenCTRL: 0xFF

	// Menu visibility booleans for message 18FFAF47
	property int btnMenuMonitorVisible: 0
	property int btnMenuImmobilizerVisible: 0
	property int adjustAddCtrlCircuit1Visible: 0
	property int adjustAddCtrlCircuit2Visible: 0
	property int adjustRCSForwardVisible: 0
	property int adjustRCSBackwardVisible: 0
	property int adjustAutoEngineStopTimeVisible: 0
	property int btnMenuCalendarVisible: 0
	property int btnMenuHeatingVisible: 0
	property int btnFctDateTimeAutoVisible: 0
	property int btnMenuFiltrRegenVisible: 0
	property int btnMenuMaintenanceVisible: 0

	// Menu visibility booleans for message 18FFAE47
	property int btnImmobActivationVisible: 0
	property int btnImmobDriverPinVisible: 0
	property int btnImmobTransPinVisible: 0
	property int btnImmobOwnerPinVisible: 0
	property int btnImmobTimeToActivationVisible: 0
	property int btnDiagMCUVisible: 0
	property int btnDiagECUVisible: 0
	property int btnDiagTCUVisible: 0

	property int machineBranding: dataEngine.cfg_MachineBranding.value
	property var dm1Message: dataEngine.dm1.value

	property bool sk1sk2Pressed: false
	property int i_SK1SK2pressed: 0
	property bool autoBackToHomeForbidden: false

	width: !targetARM ? displayWidth : undefined
	height: !targetARM ? displayHeight : undefined

	visible: true

	// this will provide automatic adaption to screen size and orientation
	property int orientationOverride: 0  // -90 , 0 , 90, 180
	readonly property bool orientationPortrait: Math.abs(orientationOverride % 180) == 90

	onDm1MessageChanged:
	{
		/* Example:
			dm1string: 0014007856341269cecf0c009d01036acecf0c009e01036acecd0d
			DM1: 7856341269cecf0c009d01036acecf0c009e01036acecd0d
			sourceAddress: 00
			LampStatus (Bytes 0 + 1): 0x14 00
			dtcID: 345678
			dtcID: cfce69
			dtcID: 019d00
			dtcID: cfce6a
			dtcID: 019e00
			dtcID: cdce6a
		 */
		// Handle DM1 single frame
		var dm1string = _CanHandler.byteArrayToHexString(dataEngine.dm1.value) // string of the DM1 message
		var dtcCounter = ((dm1string.length-6)/8).toFixed(0);
		var dtcCounter2 = parseInt((dm1string.length-6)/8);

		var dm1strWithoutSrc = dm1string.slice(6,dm1string.length) // string of the DM1 message without the 6 first bytes
//		console.log("DM1: " + dm1strWithoutSrc)
		var dtcSource = dm1string.slice(0, 2)
//		console.log("dtcCounter: " + dtcCounter)
//		console.log("dtcCounter2: " + dtcCounter2)
//		console.log("dm1string: " + dm1string)
//		console.log("sourceAddress: " + dtcSource)

		for(var i = 0; i<dtcCounter2; i++){
			var dtcCode = dm1strWithoutSrc.slice(i*8,i*8+8)
			var dtcID = dtcCode.slice(4,6) + dtcCode.slice(2,4) + dtcCode.slice(0,2);
			// @TODO: hier müsste die Abfrage nach CM rein
//			console.log("dtcID: " + dtcID)
//			console.log(" ")

			if (       !controller.isMechanicMode1
					&& !controller.isMechanicMode2
					&& !startupInfo.isManualStartMode()
					&& pg_home.autoControlDone
//					&& (dtcSource !== "31") && (dtcID !== "00FFFF")
//					&& (dtcSource !== "03") && (dtcID !== "00FFFF")
					&& (dm1string !== "030000ffffffffffff")
					&& (dm1string !== "310000ffffffffffff")
					=== true)
			{
				errorManager.addError(dtcSource + dtcID.toUpperCase().padStart(6, '0'), dataEngine.opHours_Total.value.toFixed(3)); // TODO: link to dataengine values : uncomment when CAN mapping is done
			}
		}
	}

	onMachineBrandingChanged:
	{
		// PGN 65328
		if((canError18FFD747 === false) &&
				(dataEngine.cfg_MachineBranding.value === 4)) // Yanmar-branding
		{
			RunProcess.launch("rm /opt/etc/weston-background.png")
			RunProcess.launch("ln -sf /opt/IntroVideo.ShutdownGreeting.png /opt/etc/ShutdownGreeting.png")
			RunProcess.launch("ln -sf /opt/etc/init.d/AnimationScripts/videoScript.sh /opt/etc/rc5.d/S04StartSplashVideo")
		}
		else
		{
			// (canError18FFD747 === true) || (dataEngine.cfg_MachineBranding.value !== 4)
			var languages = [
				"English",
				"Francais",
				"Deutsch",
				"Italiano",
				"Espanol",
				"Portugues",
				"Suomi",
				"Svenska",
				"Nederland",
				"Polish",
				"Dansk",
			]

			var language = languages[dm.getIndexLanguage()]

			if(language === undefined) {
				console.log("OEM default: EN")
				language = "English"
			}

			RunProcess.launch("ln -sf /opt/OEMGreetings/LBL_0001_" + language + ".png /opt/etc/weston-background.png")
			RunProcess.launch("ln -sf /opt/OEMGreetings/LBL_0002_" + language + ".png /opt/etc/ShutdownGreeting.png")
			RunProcess.launch("rm /opt/etc/rc5.d/S04StartSplashVideo")
		}
	}

	Rectangle {
		id: view
		anchors.fill: parent
		color: color_black

		Keys.forwardTo: Comp_controller {
			id: controller
		}

		PG_grid
		{
			id: pg_menu
			anchors {
				top: parent.top
				left: parent.left
				bottom: parent.bottom
			}

			width: parent.width - comp_navigationBar.width

			visible: false

			opacity: visible ? 1.0 : 0.0
			Behavior on opacity { NumberAnimation { easing.type: Easing.InOutQuad; duration: 600 } }
		}

		PG_largeList
		{
			id: pg_largeList
			anchors {
				top: parent.top
				left: parent.left
				bottom: parent.bottom
			}

			width: parent.width - comp_navigationBar.width

			visible: false

			opacity: visible ? 1.0 : 0.0
			Behavior on opacity { NumberAnimation { easing.type: Easing.InOutQuad; duration: 600 } }
		}

		PG_listStatusBar
		{
			id: pg_listStatusBar
			anchors {
				top: parent.top
				left: parent.left
				bottom: parent.bottom
			}

			width: parent.width - comp_navigationBar.width

			visible: false

			opacity: visible ? 1.0 : 0.0
			Behavior on opacity { NumberAnimation { easing.type: Easing.InOutQuad; duration: 600 } }
		}

		PG_lineStatusBarIcon
		{
			id: pg_lineStatusBarIcon
			anchors {
				top: parent.top
				left: parent.left
				bottom: parent.bottom
			}

			width: parent.width - comp_navigationBar.width

			visible: false

			opacity: visible ? 1.0 : 0.0
			Behavior on opacity { NumberAnimation { easing.type: Easing.InOutQuad; duration: 600 } }
		}

		PG_list
		{
			id: pg_list
			anchors {
				top: parent.top
				left: parent.left
				bottom: parent.bottom
			}

			width: parent.width - comp_navigationBar.width

			visible: false

			opacity: visible ? 1.0 : 0.0
			Behavior on opacity { NumberAnimation { easing.type: Easing.InOutQuad; duration: 600 } }
		}

		PG_listDetails
		{
			id: pg_listDetails
			anchors {
				top: parent.top
				left: parent.left
				bottom: parent.bottom
			}

			width: parent.width - comp_navigationBar.width

			visible: false

			opacity: visible ? 1.0 : 0.0
			Behavior on opacity { NumberAnimation { easing.type: Easing.InOutQuad; duration: 600 } }
		}

		PG_listIcon {
			id: pg_listIcon
			anchors {
				top: parent.top
				left: parent.left
				bottom: parent.bottom
			}

			width: parent.width

			visible: false

			opacity: visible ? 1.0 : 0.0
			Behavior on opacity { NumberAnimation { easing.type: Easing.InOutQuad; duration: 600 } }
		}

		PG_largeListSelection
		{
			id: pg_largeListSelection
			anchors {
				top: parent.top
				left: parent.left
				bottom: parent.bottom
			}

			width: parent.width - comp_navigationBar.width

			visible: false

			opacity: visible ? 1.0 : 0.0
			Behavior on opacity { NumberAnimation { easing.type: Easing.InOutQuad; duration: 600 } }
		}

		PG_ptoSettings
		{
			id: pg_ptoSettings
			anchors {
				top: parent.top
				left: parent.left
				bottom: parent.bottom
			}

			width: parent.width - comp_navigationBar.width

			visible: false

			opacity: visible ? 1.0 : 0.0
			Behavior on opacity { NumberAnimation { easing.type: Easing.InOutQuad; duration: 600 } }
		}

		PG_preHeating
		{
			id: pg_preHeating
			anchors {
				top: parent.top
				left: parent.left
				bottom: parent.bottom
			}

			width: parent.width - comp_navigationBar.width

			visible: false

			opacity: visible ? 1.0 : 0.0
			Behavior on opacity { NumberAnimation { easing.type: Easing.InOutQuad; duration: 600 } }
		}

		PG_calendar
		{
			id: pg_calendar
			anchors {
				top: parent.top
				left: parent.left
				bottom: parent.bottom
			}

			width: parent.width - comp_navigationBar.width

			visible: false

			opacity: visible ? 1.0 : 0.0
			Behavior on opacity { NumberAnimation { easing.type: Easing.InOutQuad; duration: 600 } }
		}

		PG_opTimeMeas
		{
			id: pg_opTimeMeas
			anchors {
				top: parent.top
				left: parent.left
				bottom: parent.bottom
			}

			width: parent.width - comp_navigationBar.width

			visible: false

			opacity: visible ? 1.0 : 0.0
			Behavior on opacity { NumberAnimation { easing.type: Easing.InOutQuad; duration: 600 } }
		}

		PG_dateSelection
		{
			id: pg_dateSelection
			anchors {
				top: parent.top
				left: parent.left
				bottom: parent.bottom
			}

			width: parent.width - comp_navigationBar.width

			visible: false

			opacity: visible ? 1.0 : 0.0
			Behavior on opacity { NumberAnimation { easing.type: Easing.InOutQuad; duration: 600 } }
		}

		PG_gauge {
			id: pg_gauge
			anchors {
				top: parent.top
				left: parent.left
				bottom: parent.bottom
			}

			width: parent.width

			visible: false

			opacity: visible ? 1.0 : 0.0
			Behavior on opacity { NumberAnimation { easing.type: Easing.InOutQuad; duration: 600 } }
		}

		PG_immobilizerTimeValidation {
			id: pg_immoblizerTimeValidation
			anchors {
				top: parent.top
				left: parent.left
				bottom: parent.bottom
			}

			width: parent.width

			visible: false

			opacity: visible ? 1.0 : 0.0
			Behavior on opacity { NumberAnimation { easing.type: Easing.InOutQuad; duration: 600 } }

			Component.onCompleted: {
				if (!canError18FFAE47 && (btnImmobTimeToActivationVisible === 0)) {
					console.log("Set validationTimeValueShowed t0 0 due to invisible ValidationTime")
					pg_immoblizerTimeValidation.validationTimeValueShowed = 0
					pg_immoblizerTimeValidation.validationTimeValueSaved = 0
				}
				console.log("PG_immobilizerTimeValidation, Component.onCompleted, console.log")
				console.warn("PG_immobilizerTimeValidation, Component.onCompleted, console.warn")
				console.error("PG_immobilizerTimeValidation, Component.onCompleted, console.error")

			}
		}

		PG_sootLevel {
			id: pg_sootLevel
			anchors {
				top: parent.top
				left: parent.left
				bottom: parent.bottom
			}

			width: parent.width

			visible: false

			opacity: visible ? 1.0 : 0.0
			Behavior on opacity { NumberAnimation { easing.type: Easing.InOutQuad; duration: 600 } }
		}

		PG_ashLevel {
			id: pg_ashLevel
			anchors {
				top: parent.top
				left: parent.left
				bottom: parent.bottom
			}

			width: parent.width

			visible: false

			opacity: visible ? 1.0 : 0.0
			Behavior on opacity { NumberAnimation { easing.type: Easing.InOutQuad; duration: 600 } }
		}

		PG_RCSBackward {
			id: pg_rcsBackward
			anchors {
				top: parent.top
				left: parent.left
				bottom: parent.bottom
			}

			width: parent.width

			visible: false

			opacity: visible ? 1.0 : 0.0
			Behavior on opacity { NumberAnimation { easing.type: Easing.InOutQuad; duration: 600 } }
		}

		PG_RCSForward {
			id: pg_rcsForward
			anchors {
				top: parent.top
				left: parent.left
				bottom: parent.bottom
			}

			width: parent.width

			visible: false

			opacity: visible ? 1.0 : 0.0
			Behavior on opacity { NumberAnimation { easing.type: Easing.InOutQuad; duration: 600 } }
		}

		PG_passcode
		{
			id: pg_passcode
			anchors {
				top: parent.top
				left: parent.left
				bottom: parent.bottom
			}

			width: parent.width - comp_navigationBar.width

			visible: false

			opacity: visible ? 1.0 : 0.0
			Behavior on opacity { NumberAnimation { easing.type: Easing.InOutQuad; duration: 600 } }
		}

		PG_immobilizer
		{
			id: pg_immobilizer
			anchors {
				top: parent.top
				left: parent.left
				bottom: parent.bottom
			}

			width: parent.width

			visible: false

			opacity: visible ? 1.0 : 0.0
			Behavior on opacity { NumberAnimation { easing.type: Easing.InOutQuad; duration: 600 } }
		}

		PG_listLargeStatusBar
		{
			id: pg_listLargeStatusBar
			anchors {
				top: parent.top
				left: parent.left
				bottom: parent.bottom
			}

			width: parent.width - comp_navigationBar.width

			visible: false

			opacity: visible ? 1.0 : 0.0
			Behavior on opacity { NumberAnimation { easing.type: Easing.InOutQuad; duration: 600 } }
		}

		PG_listIconMultiple
		{
			id: pg_listIconMultiple
			anchors {
				top: parent.top
				left: parent.left
				bottom: parent.bottom
			}

			width: parent.width - comp_navigationBar.width

			visible: false

			opacity: visible ? 1.0 : 0.0
			Behavior on opacity { NumberAnimation { easing.type: Easing.InOutQuad; duration: 600 } }
		}

		PG_listMechanic
		{
			id: pg_listMechanic
			anchors {
				top: parent.top
				left: parent.left
				bottom: parent.bottom
			}

			width: parent.width - comp_navigationBar.width

			visible: false

			opacity: visible ? 1.0 : 0.0
			Behavior on opacity { NumberAnimation { easing.type: Easing.InOutQuad; duration: 600 } }
		}

		PG_immobilizerActivation
		{
			id: pg_immobilizerActivation
			anchors {
				top: parent.top
				left: parent.left
				bottom: parent.bottom
			}

			width: parent.width - comp_navigationBar.width

			visible: false

			opacity: visible ? 1.0 : 0.0
			Behavior on opacity { NumberAnimation { easing.type: Easing.InOutQuad; duration: 600 } }
		}

		PG_pinCode
		{
			id: pg_pinCode
			anchors {
				top: parent.top
				left: parent.left
				bottom: parent.bottom
			}

			width: parent.width

			visible: false

			opacity: visible ? 1.0 : 0.0
			Behavior on opacity { NumberAnimation { easing.type: Easing.InOutQuad; duration: 600 } }
		}
	}

	ShaderEffectSource {
		id: effect
		anchors.fill: view
		sourceItem: view
		hideSource: visible
	}

	Rectangle {
		id: rectList

		width: backEnd.currentPage === pg_gauge ? 67 : 47
		height: 240 - backEnd.currentConfig.headerHeight
		color: color_gray
		border {
			color: color_gray_bar
			width: 2
		}
		anchors {
			right: parent.right
			bottom: parent.bottom
		}

		visible: false

		opacity: visible ? 1.0 : 0.0
		Behavior on opacity { NumberAnimation { easing.type: Easing.InOutQuad; duration: 600 } }
	}

	Rectangle {
		id: rectMenu

		width: 47
		height: 240
		color: color_gray

		anchors.right: parent.right

		visible: false

		opacity: visible ? 1.0 : 0.0
		Behavior on opacity { NumberAnimation { easing.type: Easing.InOutQuad; duration: 600 } }
	}

	Comp_navigationBar {
		id: comp_navigationBar
		visible: readyForInit === true ? true : false
	}

	PG_home {
		id: pg_home
		anchors {
			top: parent.top
			left: parent.left
			bottom: parent.bottom
			//bottomMargin: 4
		}
		width: parent.width

		visible: false

		opacity: visible ? 1.0 : 0.0
		Behavior on opacity { NumberAnimation { easing.type: Easing.InOutQuad; duration: 600 } }
	}


	PG_home2 {
		id: pg_home2
		anchors {
			top: parent.top
			left: parent.left
			bottom: parent.bottom
		}

		width: parent.width

		visible: startupInfo.isManualStartMode()

		opacity: visible ? 1.0 : 0.0
		Behavior on opacity { NumberAnimation { easing.type: Easing.InOutQuad; duration: 600 } }
	}

	Comp_pageHeaderControl {
		id: pgHeader
		anchors {
			top: parent.top
			left: parent.left
		}
		mainMenu: true
		visible: false
		z:999
	}

	Comp_buzzerManager {
		id: buzzerManager
	}

	PG_popUp
	{
		id: pg_popUp
		anchors.top: parent.top
		z: 998
		visible: false
	}

	Timer {
		id: writeCANvalues_100ms
		running: true
		interval: 100
		repeat: true // repeat every 100ms
		onTriggered: {

			// 0x18A74728 - ButtonsAndOutput
//			console.log("bImmobilizerOnOffTriggerSignal = " + bImmobilizerOnOffTriggerSignal);
			if (s32MyLastState !== backEnd.state) {
				console.log("backEnd.state = " + backEnd.state);
				s32MyLastState = backEnd.state;
			}

			var byte5bin = "00" + (bImmobilizerOnOffTriggerSignal === true ? "01" : "00") + "0000"
			var Byte0 = 255 // unused
			var Byte1 = 255 // unused
			var Byte2 = 255 // unused
			var Byte3 = 255 // unused
			var Byte4 = 255 // unused
			var Byte5 = parseInt(byte5bin, 2) // immobActivation
			var Byte6 = 255 // unused
			var Byte7 = 255 // unused
			_CanHandler.sendCAN(413615912, Byte0, Byte1, Byte2, Byte3, Byte4, Byte5, Byte6, Byte7)


			// 0x18FF8428 - Immobilizer
			Byte0 = u8ImmoByte0 // Screen
			Byte1 = u8ImmoByte1 // PopUpMessage, unused
			Byte2 = u8ImmoByte2 // ImmobTypedNewPin
			Byte3 = u8ImmoByte3 // ImmobTypedNewPin
			Byte4 = u8ImmoByte4 // ImmobTypedPin
			Byte5 = u8ImmoByte5 // ImmobTypedPin
			Byte6 = u8ImmoByte6 // unused
			Byte7 = u8ImmoByte7 // unused
			var pinCodeHex = "FFFF"

			if(   (backEnd.state === MyAppState.IMMOBILIZER_ACTIVATION)
			   || (backEnd.state === MyAppState.TIME_TO_ACTIVATE)
			   )
			{
				u8ImmoByte0 = Byte0 = 1; // CntrlOwnerInp: notify the MCU to control the owner pin
				// @TODO: korrekten Wert finden
				if(pg_pinCode.checkTypedPin === true)
				{
					bImmobilizerOnOffTriggerSignal = false
					pinCodeHex = pg_pinCode.pinToVerify.toString(16).toUpperCase().padStart(4, '0'); // convert uint16 to string hexadecimal
					u8ImmoByte4 = Byte4 = parseInt(pinCodeHex.slice(2,4), 16)
					u8ImmoByte5 = Byte5 = parseInt(pinCodeHex.slice(0,2), 16)
					console.log("Entered owner pin to change settings: " + pg_pinCode.pinToVerify)
					enteredOwnerPin = pinCodeHex
				}
			}
			else if((backEnd.state === MyAppState.ENTER_TRANS_PIN)
					|| (backEnd.state === MyAppState.ENTER_DRIVER_PIN)
					|| (backEnd.state === MyAppState.ENTER_OWNER_PIN)
					)
			{
				u8ImmoByte0 = Byte0 = 36; // OwnerAutoNewPIN: notify the MCU to control the owner pin to authorize other PIN modification
				if(pg_pinCode.checkTypedPin === true)
				{
					pinCodeHex = pg_pinCode.pinToVerify.toString(16).toUpperCase().padStart(4, '0'); // convert uint16 to string hexadecimal
					u8ImmoByte4 = Byte4 = parseInt(pinCodeHex.slice(2,4), 16)
					u8ImmoByte5 = Byte5 = parseInt(pinCodeHex.slice(0,2), 16)
					console.log("Entered owner pin to authorizise: " + pg_pinCode.pinToVerify)
					enteredOwnerPin = pinCodeHex
				}
			}
			else if((backEnd.state === MyAppState.NEW_TRANS_PIN))
			{
				u8ImmoByte0 = Byte0 = 41; // NewTransInp: notify the MCU to update the transporter pin, 0x29 =41
				if(pg_pinCode.checkTypedPin === true)
				{
					pinCodeHex = pg_pinCode.pinToVerify.toString(16).toUpperCase().padStart(4, '0'); // convert uint16 to string hexadecimal
					u8ImmoByte2 = Byte2 = parseInt(pinCodeHex.slice(2,4), 16)
					u8ImmoByte3 = Byte3 = parseInt(pinCodeHex.slice(0,2), 16)
					u8ImmoByte4 = Byte4 = parseInt(enteredOwnerPin.slice(2,4), 16)
					u8ImmoByte5 = Byte5 = parseInt(enteredOwnerPin.slice(0,2), 16)
					console.log("Entered new trans pin: " + pg_pinCode.pinToVerify)
					//pg_pinCode.acceptNewPin()
				}
			}
			else if((backEnd.state === MyAppState.NEW_DRIVER_PIN))
			{
				u8ImmoByte0 = Byte0 = 40; // NewDriverInp: notify the MCU to update the driver pin, 0x28 = 40
				if(pg_pinCode.checkTypedPin === true)
				{
					pinCodeHex = pg_pinCode.pinToVerify.toString(16).toUpperCase().padStart(4, '0'); // convert uint16 to string hexadecimal
					u8ImmoByte2 = Byte2 = parseInt(pinCodeHex.slice(2,4), 16)
					u8ImmoByte3 = Byte3 = parseInt(pinCodeHex.slice(0,2), 16)
					u8ImmoByte4 = Byte4 = parseInt(enteredOwnerPin.slice(2,4), 16)
					u8ImmoByte5 = Byte5 = parseInt(enteredOwnerPin.slice(0,2), 16)
					console.log("Entered new driver pin: " + pg_pinCode.pinToVerify)
					//pg_pinCode.acceptNewPin()
				}
			}
			else if((backEnd.state === MyAppState.NEW_OWNER_PIN))
			{
				u8ImmoByte0 = Byte0 = 39; // NewOwnerInp: notify the MCU to update the owner pin, 0x27 = 39
				if(pg_pinCode.checkTypedPin === true)
				{
					pinCodeHex = pg_pinCode.pinToVerify.toString(16).toUpperCase().padStart(4, '0'); // convert uint16 to string hexadecimal
					u8ImmoByte2 = Byte2 = parseInt(pinCodeHex.slice(2,4), 16)
					u8ImmoByte3 = Byte3 = parseInt(pinCodeHex.slice(0,2), 16)
					u8ImmoByte4 = Byte4 = parseInt(enteredOwnerPin.slice(2,4), 16)
					u8ImmoByte5 = Byte5 = parseInt(enteredOwnerPin.slice(0,2), 16)
					console.log("Entered new owner pin: " + pg_pinCode.pinToVerify)
					//pg_pinCode.acceptNewPin()
				}
			}
			else if((backEnd.state === MyAppState.IMMOBILIZER))
			{
//				u8ImmoByte0 = Byte0 = mcuScreenCTRL; // use the MCU-value; TODO: muss dies wirklich angepasst werden?
				if(pg_immobilizer.checkTypedPin === true)
				{
					pinCodeHex = pg_immobilizer.pinToVerify.toString(16).toUpperCase().padStart(4, '0'); // convert uint16 to string hexadecimal
					u8ImmoByte4 = Byte4 = parseInt(pinCodeHex.slice(2,4), 16)
					u8ImmoByte5 = Byte5 = parseInt(pinCodeHex.slice(0,2), 16)
					enteredPin = pg_immobilizer.pinToVerify
					console.log("entered general pin to unlock the machine: " + enteredPin)
				}
			}
			else {
//				console.log("Reset enteredOwnerPin")
				enteredOwnerPin = "FFFF"
				enteredPin = "FFFF"
				u8ImmoByte0 = 255;
				u8ImmoByte2 = Byte2 = 255
				u8ImmoByte3 = Byte3 = 255
			}

			if(pg_immobilizer.checkTypedPin === true)
			{
				// wozu ist dies hier? --> auskommentiert; wichtig, damit die Botschaft länger gesendet wird;
				// nun aber mit u8ImmoByteX kann dies wiede auskommentiert werden
				if ( true === false) {
				//pg_immobilizer.checkTypedPin = false // set to false so that the pin value is sent only for 1 cycle
				pinCodeHex = pg_immobilizer.pinToVerify.toString(16).toUpperCase().padStart(4, '0'); // convert uint16 to string hexadecimal
				//                console.log("pincodeHex: " + pinCodeHex)
				Byte4 = parseInt(pinCodeHex.slice(2,4), 16)
				Byte5 = parseInt(pinCodeHex.slice(0,2), 16)
				//                console.log("Byte4: " + Byte4)
				//                console.log("Byte5: " + Byte5)
			}
			}
			else {
//				u8ImmoByte0 = 255;
				u8ImmoByte1 = 255;
				u8ImmoByte2 = 255;
				u8ImmoByte3 = 255;
				u8ImmoByte4 = 255;
				u8ImmoByte5 = 255;
				u8ImmoByte6 = 255;
				u8ImmoByte7 = 255;
			}

			_CanHandler.sendCAN(419398696, Byte0, Byte1, Byte2, Byte3, Byte4, Byte5, Byte6, Byte7) // 419398696 == 0x18FF8428
//			_CanHandler.sendCAN(419398696, u8ImmoByte0, u8ImmoByte1, u8ImmoByte2, u8ImmoByte3, u8ImmoByte4, u8ImmoByte5, u8ImmoByte6, u8ImmoByte7)


			// Check if SK1 and SK2 are pressed simultaneously
			if((backEnd.getSK1SK2combined() === true) && (sk1sk2Pressed === false))
			{
				// SK1 and SK2 were not pressed simultaneously yet, but now they are
				sk1sk2Pressed = true
				console.log("SK1 SK2 pressed")
			}

			if(sk1sk2Pressed === true)
			{
				if(backEnd.getSK1SK2combined() === false)
				{
					// SK1 and SK2 were simultaneously pressed, but now they are not
					sk1sk2Pressed = false
					i_SK1SK2pressed = 0
					console.log("SK1 SK2 not pressed")
				}
				else
				{
					i_SK1SK2pressed += 1
					if(i_SK1SK2pressed >= 10) // SK1 and SK2 pressed for at least 1s
					{
						i_SK1SK2pressed = 0
						if(autoBackToHomeForbidden === false)
						{
							autoBackToHomeForbidden = true
							pum.addPopUp("", "Autoswitch to home disabled" + translator.emptyString, 4, 5)
						}
						else
						{
							autoBackToHomeForbidden = false
							pum.addPopUp("", "Autoswitch to home enabled" + translator.emptyString, 4, 5)
							if (controller.isMechanicMode1 || controller.isMechanicMode2) {
								controller.startAutoSwitchMechanicMenu()
							}
							else
							{
								controller.startAutoSwitch()
							}
						}
					}
				}
			} // if(sk1sk2Pressed === true)

		}
	}


	Timer {
		id: writeCANvalues
		running: true
		interval: 1000
		repeat: true // repeat every 1s
		onTriggered: {
			//console.log("WRITING CAN")

			// 0x18FEE628 - Datetime
			var Byte0 = dateTimeManager.getSeconds()*4
			var Byte1 = dateTimeManager.getMinutes()
			var Byte2 = dateTimeManager.getHour()
			var Byte3 = dateTimeManager.getMonth()
			var Byte4 = dateTimeManager.getDay()*4
			var Byte5 = dateTimeManager.getYear() - 1985
			var Byte6 = 255 // unused
			var Byte7 = 255 // unused
			_CanHandler.sendCAN(419358248, Byte0, Byte1, Byte2, Byte3, Byte4, Byte5, Byte6, Byte7) // 419358248 == 0x18FEE628

			// 0x18FFDF28 - HMI settings TODO
			var byte0bin = "000000" + ((dm.pressureUnit === 1) || (dm.volumeUnit === 0)) ? "00" // SI units
									: ((dm.pressureUnit === 0) || (dm.volumeUnit === 2)) ? "01" // UK units
									: ((dm.pressureUnit === 2) || (dm.volumeUnit === 1)) ? "10" // US units
									: "11" // no change
			var byte7bin = pg_gauge.backLightNightValuesIndex.toString(2).padStart(4, '0') + pg_gauge.backLightDayValuesIndex.toString(2).padStart(4, '0')
			Byte0 = parseInt(byte0bin, 2)
			Byte1 = (dm.getIndexLanguage() === 2 ? 0 // German
					: dm.getIndexLanguage() === 0 ? 1 // English
					: dm.getIndexLanguage() === 1 ? 2 // French
					: dm.getIndexLanguage() === 4 ? 3 // Spanish
					: dm.getIndexLanguage() === 7 ? 4 // Swedish
					//: dm.getIndexLanguage() === ? 5 // Russian/Czech TODO
					: dm.getIndexLanguage() === 9 ? 6 // Polish
					: dm.getIndexLanguage() === 10 ? 7 // Danish
					: dm.getIndexLanguage() === 3 ? 8 // Italian
					: dm.getIndexLanguage() === 5 ? 9 // Portuguese
					: dm.getIndexLanguage() === 8 ? 10 // Dutch
					//: dm.getIndexLanguage() === ? 11 // American english
					: dm.getIndexLanguage() === 6 ? 12 // Finnish: exists on the display (from BE2) but not defined in the dbc...
					: 255 // Not available or not requested
					 )
			Byte2 = 255
			Byte3 = 255
			Byte4 = 255
			Byte5 = 255
			Byte6 = 255
			Byte7 = parseInt(byte7bin, 2) // Brightness settings
			_CanHandler.sendCAN(419421992, Byte0, Byte1, Byte2, Byte3, Byte4, Byte5, Byte6, Byte7) // 419421992 == 0x18FFDF28


			// 0x18FFD028 - Machine settings 1
			Byte0 = adjustAddCtrlCircuit1Visible ? ((dm.indexPTO > 0) ? dm.getPtoSettings(dm.indexPTO - 1).pto1_left * 10 : 100) : 255
			Byte1 = adjustAddCtrlCircuit2Visible ? ((dm.indexPTO > 0) ? dm.getPtoSettings(dm.indexPTO - 1).pto2_left * 10 : 100) : 255
			Byte2 = 255
			Byte3 = 255
			Byte4 = 255
			Byte5 = dm.get_engineStopTime()
			Byte6 = dm.rcsFoward // RCS forward
			Byte7 = dm.rcsBackward // RCS reverse
			_CanHandler.sendCAN(419418152, Byte0, Byte1, Byte2, Byte3, Byte4, Byte5, Byte6, Byte7) // 419418152 == 0x18FFD028

			// 0x18FFD228 - Machine settings 3
			Byte0 = (dm.indexPTO > 0) ? dm.getPtoSettings(dm.indexPTO - 1).pto1_right * 10 : 100
			Byte1 = (dm.indexPTO > 0) ? dm.getPtoSettings(dm.indexPTO - 1).pto2_right * 10 : 100
			Byte2 = 255
			Byte3 = 255
			Byte4 = 255
			Byte5 = 255
			Byte6 = 255
			Byte7 = 255
			_CanHandler.sendCAN(419418664, Byte0, Byte1, Byte2, Byte3, Byte4, Byte5, Byte6, Byte7) // 419418664 == 0x18FFD228

			// 0x18FFD128 - Machine settings 2 TODO
			Byte0 = 255
			Byte1 = 255
			Byte2 =  pg_immoblizerTimeValidation.validationTimeValueSaved// ImmobTimeToActivation
			Byte3 = 255
			Byte4 = 255
			Byte5 = 255
			Byte6 = 255
			Byte7 = 255 // TODO : AutoEngineStopRemainingSeconds
			_CanHandler.sendCAN(419418408, Byte0, Byte1, Byte2, Byte3, Byte4, Byte5, Byte6, Byte7)



//            // PGN 65335 - 0x18FF3714
//            var byte0bin = (pg_listStatusBar.hydraulicOilRetLineFilterMCUReset=== 1 ? "01" : "00")
//                         + (pg_listStatusBar.hydraulicOilRetFilterMCUReset === 1 ? "01" : "00")
//                         + (pg_listStatusBar.hydraulicOilMCUReset === 1 ? "01" : "00")
//                         + (pg_listIcon.hourMeterReset === 1 ? "01" : "00")
//            var byte1bin = "111111" + (pg_listStatusBar.travelReductionOilMCUReset === 1 ? "01" : "00")
//            var byte6bin = "111111" + (pg_listIcon.factoryReset === 1 ? "01" : "00")
//            var Byte0 = parseInt(byte0bin, 2)
//            var Byte1 = parseInt(byte1bin, 2)
//            var Byte2 = 255
//            var Byte3 = (dm.indexPTO > 0) ? dm.getPtoSettings(dm.indexPTO - 1).pto1_left * 10 : 100
//            var Byte4 = (dm.indexPTO > 0) ? dm.getPtoSettings(dm.indexPTO - 1).pto1_right * 10 : 100
//            var Byte5 = dm.getIndexStopTime()
//            var Byte6 = parseInt(byte6bin, 2)
//            var Byte7 = 255
//            _CanHandler.sendCAN(419378964, Byte0, Byte1, Byte2, Byte3, Byte4, Byte5, Byte6, Byte7)

//            // PGN 65337 - 0x18FF3914
//            byte0bin = (dm.getPreHeatingDate(2) === true ? "01" : "00") // wednesday
//                     + (dm.getPreHeatingDate(1) === true ? "01" : "00") // tuesday
//                     + (dm.getPreHeatingDate(0) === true ? "01" : "00") // monday
//                     + (dm.getPreHeating().active === true ? "01" : "00")
//            byte1bin = (dm.getPreHeatingDate(6) === true ? "01" : "00") // sunday
//                      + (dm.getPreHeatingDate(5) === true ? "01" : "00") // saturday
//                      + (dm.getPreHeatingDate(4) === true ? "01" : "00") // friday
//                      + (dm.getPreHeatingDate(3) === true ? "01" : "00") // thursday
//            Byte0 = parseInt(byte0bin, 2)
//            Byte1 = parseInt(byte1bin, 2)
//            Byte2 = dm.getPreHeating().start_hours
//            Byte3 = dm.getPreHeating().start_minutes
//            Byte4 = (dm.indexPTO > 0) ? dm.getPtoSettings(dm.indexPTO - 1).pto2_left * 10 : 100
//            Byte5 = (dm.indexPTO > 0) ? dm.getPtoSettings(dm.indexPTO - 1).pto2_right * 10 : 100
//            Byte6 = 255
//            Byte7 = 255
//            _CanHandler.sendCAN(419379476, Byte0, Byte1, Byte2, Byte3, Byte4, Byte5, Byte6, Byte7)

//            // PGN 65346 - 0x18FF4214
//            var intervalNew = pg_listStatusBar.interval_hydraulicOilMCUNew.toString(16).toUpperCase(); // convert uint16 to string hexadecimal
//            intervalNew = intervalNew.padStart(4, '0'); // pad with 0s up to 4 characters
//            var filterIntervalNew = pg_listStatusBar.interval_hydraulicOilRetFilterMCUNew.toString(16).toUpperCase(); // convert uint16 to string hexadecimal
//            filterIntervalNew = filterIntervalNew.padStart(4, '0'); // pad with 0s up to 4 characters
//            var retLineIntervalNew = pg_listStatusBar.interval_hydraulicOilRetLineFilterMCUNew.toString(16).toUpperCase(); // convert uint16 to string hexadecimal
//            retLineIntervalNew = retLineIntervalNew.padStart(4, '0'); // pad with 0s up to 4 characters
//            var travelIntervalNew = pg_listStatusBar.interval_travelReductionOilMCUNew.toString(16).toUpperCase(); // convert uint16 to string hexadecimal
//            travelIntervalNew = travelIntervalNew.padStart(4, '0'); // pad with 0s up to 4 characters
//            Byte0 = parseInt(intervalNew.slice(2,4), 16)
//            Byte1 = parseInt(intervalNew.slice(0,2), 16)
//            Byte2 = parseInt(filterIntervalNew.slice(2,4), 16)
//            Byte3 = parseInt(filterIntervalNew.slice(0,2), 16)
//            Byte4 = parseInt(retLineIntervalNew.slice(2,4), 16)
//            Byte5 = parseInt(retLineIntervalNew.slice(0,2), 16)
//            Byte6 = parseInt(travelIntervalNew.slice(2,4), 16)
//            Byte7 = parseInt(travelIntervalNew.slice(0,2), 16)
//            _CanHandler.sendCAN(419381780, Byte0, Byte1, Byte2, Byte3, Byte4, Byte5, Byte6, Byte7)

			if(pg_listIcon.hourMeterReset === 1)
			{
				pg_listIcon.hourMeterReset = 0
			}

			if(pg_listIcon.factoryReset === 1)
			{
				if(factoryResetCntSec === 2)
				{
					pg_listIcon.factoryReset = 0
					factoryResetCntSec = 0
				}
				factoryResetCntSec += 1
			}
			if(pg_listStatusBar.hydraulicOilMCUReset === 1)
			{
				pg_listStatusBar.hydraulicOilMCUReset = 0
			}
			if(pg_listStatusBar.hydraulicOilRetFilterMCUReset === 1)
			{
				pg_listStatusBar.hydraulicOilRetFilterMCUReset = 0
			}
			if(pg_listStatusBar.hydraulicOilRetLineFilterMCUReset === 1)
			{
				pg_listStatusBar.hydraulicOilRetLineFilterMCUReset = 0
			}
			if(pg_listStatusBar.travelReductionOilMCUReset === 1)
			{
				pg_listStatusBar.travelReductionOilMCUReset = 0
			}

		}
	}

	Timer {
		id: sendCANValueInit
		running: true
		interval: 1000
		repeat: true
		triggeredOnStart: true
		onTriggered: {
			console.log("Send message at startup")
			// Message AC (0x18EEFF28)
			var Byte0 = 0
			var Byte1 = 0
			var Byte2 = 0
			var Byte3 = 0
			var Byte4 = 0
			var Byte5 = 60
			var Byte6 = 7<<1
			var Byte7 = 3<<4
			_CanHandler.sendCAN(418316072, Byte0, Byte1, Byte2, Byte3, Byte4, Byte5, Byte6, Byte7)
			checkCANValueInit.start()
		}
	}

	Timer {
		id: checkCANValueInit
		running: false
		interval: 500
		repeat: true
		onTriggered: {
			console.log("Checking the message MachineProperties")
			if(canError18FFD747 === false){
				console.log("MachineProperties received, start of the CAN values init")
				readyForInit = true
				checkCANValueInit.stop()
				sendCANValueInit.stop()

				readCANvaluesInit.restart()
				readCANvalues.restart()
			}
		}
	}

	Timer {
		id: readCANvaluesInit
		running: false
		interval: 10
		repeat: true // repeat every 10ms
		onTriggered: {
			console.log("Waiting for CAN connection...")

			if(dataEngine.connectionState == 1 && readyForInit === true) {

				console.log("CAN connected!!")

				//Check machine type at startup
				if(checkMachineType === true) // check once
				{
					if (dataEngine.cfg_EngineEmissionStandard.value === 1) {
						// 1: Ceu16EngineEmissionStandard_ElectricEngine, siehe machine_cfg.h
						isV8e = true;
						isV7 = false;
						checkMachineType = false
					}
					else if (dataEngine.cfg_EngineEmissionStandard.value === 10) {
						isV8e = false;
						isV7 = true;
						checkMachineType = false
					}

					// If V7 or fct date time auto not visible : select manuel mode and save it
					if(isV7 || _CanHandler.BtnFctDateTimeAutomatic_Visible === 0) {
						dm.dateTimeMode = 1
						dm.saveDateTimeMode()
						dateTimeManager.setManualMode(true)
					}
				}

				// Check immobilizer at startup
				if(checkImmobilizerStartup === true)
				{
					checkImmobilizerStartup = false

					if (canError18A72847 === false) {
						if (dataEngine.btnImmobActivation_Ctrl.value === 1) {
							dm.isImmobActive = 1;
//							console.log("dm.isImmobActive = 1")
						}
						else if (dataEngine.btnImmobActivation_Ctrl.value === 0) {
							dm.isImmobActive = 0;
//							console.log("dm.isImmobActive = 0")
						}
						else {
							// Do nothing
						}
					}
					console.log("dm.isImmobActive = " + dm.isImmobActive )

					if ((dm.isImmobActive === 1) && ((canError18FF8447 === true) || (canError18A72847 === true))) {
						// 18FF8447: MenuNavigationCtrl;
						// 18A72847: Buttons_And_IO_Ctrl
						// There is a CAN error AND the last state was locked: lock the display
						console.log("CAN error: lock the display due to last state")
						if (!startupInfo.isManualStartMode()) {
							pg_immobilizer.visible = true
							backEnd.setState(MyAppState.IMMOBILIZER)
							backEnd.setCurrentPage(pg_immobilizer)
							pgHeader.visible = true
							pgHeader.mainMenu = false
							pgHeader.titleString = qsTrId("LBL_0328") + translator.emptyString
							comp_navigationBar.hideEnter = false
							rectList.visible = true
						}
					}
					else
					{
						console.log("No CAN error for immobilizer and no locked immobilizer in the last state")

						/*  #define Du8MaskNumberNormalRun			0U
							#define Du8MaskNumberOwnerPinInput		1U
							#define Du8MaskNumberGeneralPinInput	2U
							#define Du8MaskNumberMsgWrongPin		3U
							#define Du8MaskNumberDelayPinInput		4U
							#define Du8MaskNumberNewPinInput		5U
						*/

						if ((dataEngine.screenCtrl.value === 1) ||
							(dataEngine.screenCtrl.value === 2) ||
							(dataEngine.screenCtrl.value === 3) ||
							(dataEngine.screenCtrl.value === 4))
						{
							// ScreenCtrl value = show immob general inuput screen (18FF8447)
							console.log("")
							console.log("Immobilizer is locked, screenCtrl == 1 || 2 || 3 || 4")
							console.log("")
							if (!startupInfo.isManualStartMode()) {
								pg_immobilizer.visible = true
								backEnd.setState(MyAppState.IMMOBILIZER)
								backEnd.setCurrentPage(pg_immobilizer)
								pgHeader.visible = true
								pgHeader.mainMenu = false
								pgHeader.titleString = qsTrId("LBL_0328") + translator.emptyString
								comp_navigationBar.hideEnter = false
								rectList.visible = true
							}
						}
						else
						{
							// ScreenCtrl value does not indicate to ask for PIN input at start-up
							console.log("screenCtrl != ( 1 || 2 || 3 || 4 )")
							if (!startupInfo.isManualStartMode()) {
								console.log("Immobilizer is unlocked, main page appears")
								pg_immobilizer.visible = false
								backEnd.setState(MyAppState.MAIN)
								backEnd.setCurrentPage(pg_home)
								pg_home.visible = true
								pgHeader.visible = true
								pgHeader.mainMenu = true
								pgHeader.titleString = "AM 08:00"
								pg_home.startAutoControl()
							}
						}
					}
				}

				readCANvaluesInit.stop()
			}
		}
	}

	Timer {
		id: readCANvalues
		running: false
		interval: 1000
		repeat: true // repeat every 1s
		onTriggered: {

//			console.log("dataEngine.zFSFS1AcceleratorPedalPosition.value: " + dataEngine.zFSFS1AcceleratorPedalPosition.value)
//			console.log("dataEngine.lowSideVoltage.value: " + dataEngine.lowSideVoltage.value)
//			console.log("btnMenuFiltrRegenVisible: " + btnMenuFiltrRegenVisible)

			pg_listStatusBar.fuelPressureRail = _CanHandler.railP

			// Do it everywhere but in the day and night brightness setting pages
			if(!(backEnd.state === MyAppState.DS_2_BRIGHTNESS_DAY) && !(backEnd.state === MyAppState.DS_2_BRIGHTNESS_NIGHT))
			{
				// If 0, day mode
				if(dataEngine.ind_DayNightChangeOver.value === 0) {
					backLightHandler.currentBacklightValue = dm.getDayBrightness()
				}
				// If 1, night mode
				if(dataEngine.ind_DayNightChangeOver.value === 1) {
					backLightHandler.currentBacklightValue = dm.getNightBrightness()
				}
			}

			mcuBuzz = dataEngine.buzzer.value

			// Buzzer from MCU
			if(mcuBuzz === 1)
			{
				// ON
				buzzerManager.buzzerPattern = 1
				mcuBuzz_prev = 1
			}
			else if(mcuBuzz === 2)
			{
				// blink
				buzzerManager.buzzerPattern = blinkingPictoIsVisible ? 1 : 0
				mcuBuzz_prev = 2
			}
			else if(mcuBuzz === 3)
			{
				// no change
				if(mcuBuzz_prev === 0)
				{
					//buzzerManager.buzzerPattern = 0
				}
				else if(mcuBuzz_prev === 1)
				{
					buzzerManager.buzzerPattern = 1
				}
				else if(mcuBuzz_prev === 2)
				{
					buzzerManager.buzzerPattern = blinkingPictoIsVisible ? 1 : 0
				}
			}
			else if(mcuBuzz === 0)
			{
				// OFF
				if((mcuBuzz_prev === 1) || (mcuBuzz_prev === 2)) // only stop the buzzer if it has been triggered by the MCU
				{
					buzzerManager.buzzerPattern = 0
				}
				mcuBuzz_prev = 0

			} // else if


			// V8e flashing sound
			if(isV7 === false)
			{
				if((dataEngine.ind_BlinkerLeft.value === 2) || (dataEngine.ind_BlinkerRight.value === 2))
				{
					buzz7 = true  /// hier supress flasher
				}
				else
				{
					buzz7 = false
				}

				if(buzz7 === true)
				{
					if((buzzerManager.isPattern7running() === false) && (blinkingPictoIsVisible === true))
					{
						buzzerManager.buzzerPattern = 7
					}
				}
				else
				{
					if(buzzerManager.isPattern7running() === true)
					{
						buzzerManager.stopPattern7()
					}
				}
			}



			mcuScreenCTRL = dataEngine.screenCtrl.value

			if (0 && (mcuScreenCTRL === 1)  // if MCU want the display to ask for a owner PIN code (1)
				&& (backEnd.state !== MyAppState.POPUP)
				&& ((backEnd.state === MyAppState.IMMOBILIZER_ACTIVATION) // and display is not already asking for a PIN code
					|| (backEnd.state === MyAppState.TIME_TO_ACTIVATE))) {

				// Then display the immobilizer page to ask for valid Owner-PIN
				console.log("Change to Immobilizer-Page to enter the owner-pin due to Command of the MCU")
//				backEnd.currentPage.visible = false
				backEnd.setCurrentPage(pg_pinCode)
				pg_pinCode.visible = true
				pg_pinCode.currentInfoMsg = qsTrId("LBL_0347") + translator.emptyString

				pgHeader.visible = true
				pgHeader.titleString = qsTrId("LBL_0339") + translator.emptyString
			}

			else if(   ((mcuScreenCTRL === 2) || (mcuScreenCTRL === 1)) // if MCU want the display to ask for a generic PIN code (2) or the owner PIN code (1)
			   && (backEnd.state !== MyAppState.IMMOBILIZER) // and display is not already asking for a PIN code
			   && (backEnd.state !== MyAppState.ENTER_TRANS_PIN)
			   && (backEnd.state !== MyAppState.ENTER_DRIVER_PIN)
			   && (backEnd.state !== MyAppState.ENTER_OWNER_PIN)
			   && (backEnd.state !== MyAppState.NEW_TRANS_PIN)
			   && (backEnd.state !== MyAppState.NEW_DRIVER_PIN)
			   && (backEnd.state !== MyAppState.NEW_OWNER_PIN)
			   && (backEnd.state !== MyAppState.ENTERED_WRONG_OWNER_PIN)
			   && (backEnd.state !== MyAppState.IMMOBILIZER_ACTIVATION)
			   && (backEnd.state !== MyAppState.IMMOBILIZER_SETTINGS)
			   && (backEnd.state !== MyAppState.POPUP))
			{
				// @TODO: die Ausnahmen IMMOBILIZER_SETTINGS evtl. entfernen
				// Then display the immobilizer page to ask for valid PIN code
				console.log("Change to Immobilizer-Page to enter a number due to Command of the MCU")
				backEnd.currentPage.visible = false
				pg_immobilizer.visible = true
				backEnd.setState(MyAppState.IMMOBILIZER)
				backEnd.setCurrentPage(pg_immobilizer)
				pgHeader.visible = true
				pgHeader.mainMenu = false
				pgHeader.titleString = qsTrId("LBL_0328") + translator.emptyString
				comp_navigationBar.hideEnter = false
				rectList.visible = true
			}

			if(checkDriveMode === true) // check once at startup
			{
				checkDriveMode = false
				currentDriveMode = dataEngine.driveMode.value
			}

			// If drive mode changes and autocontrol is finished and pop up manager queue is empty
			if((dataEngine.driveMode.value !== currentDriveMode) && (pg_home.autoControlDone === true) && (pum.size() === 0))
			{
				// V7 modes
				if(isV7 === true)
				{
					if(dataEngine.driveMode.value === 1) // Bucket mode
					{
						pum.addPopUp("qrc:/graphics/Popups/2.12_Bucket_popup.png", " " + translator.emptyString, 4, 5)
					}
					else if(dataEngine.driveMode.value === 2) // Eco mode
					{
						pum.addPopUp("qrc:/graphics/Popups/2.11_ECO_popup.png", " " + translator.emptyString, 4, 5)
					}
					else if(dataEngine.driveMode.value === 3) // Creep mode
					{
						pum.addPopUp("qrc:/graphics/Popups/2.15_Creep_popup.png", " " + translator.emptyString, 4, 5)
					}
					currentDriveMode = dataEngine.driveMode.value
				}
				else // V8e modes
				{
					if(dataEngine.driveMode.value === 1) // Bucket mode
					{
						pum.addPopUp("qrc:/graphics/Popups/2.12_Bucket_popup.png", " " + translator.emptyString, 4, 5)
					}
					else if(dataEngine.driveMode.value === 2) // Eco mode
					{
						pum.addPopUp("qrc:/graphics/Popups/2.11_ECO_popup.png", " " + translator.emptyString, 4, 5)
					}
					else if(dataEngine.driveMode.value === 4) // Forklift mode
					{
						pum.addPopUp("qrc:/graphics/Popups/2.13_Fork_popup.png", " " + translator.emptyString, 4, 5)
					}
					else if(dataEngine.driveMode.value === 5) // Power mode
					{
						pum.addPopUp("qrc:/graphics/Popups/2.14_PWR_popup.png", " " + translator.emptyString, 4, 5)
					}
					else if(dataEngine.driveMode.value === 6) // Test mode
					{
						pum.addPopUp("qrc:/graphics/Popups/2.17_TEST_popup.png", " " + translator.emptyString, 4, 5)
					}
					else if(dataEngine.driveMode.value === 7) // EEPROM mode
					{
						pum.addPopUp("qrc:/graphics/Popups/2.18_EEP_popup.png", " " + translator.emptyString, 4, 5)
					}
					else if(dataEngine.driveMode.value === 8) // PPC active mode
					{
						pum.addPopUp("qrc:/graphics/Popups/2.16_LHD_popup.png", " " + translator.emptyString, 4, 5)
					}
					currentDriveMode = dataEngine.driveMode.value
				}
			}

			if(checkPreheatingOpt === true) // check once at the beginning
			{
				checkPreheatingOpt = false
				if(_CanHandler.BtnMenuHeating_Visible === 0)
				{
					// if the machine does not have the preheating option, disable the function
					dm.getPreHeating().active = false
					dm.savePreHeatingSettings()
					optPreheatingAtStartup = false
				}
				else
				{
					// the machine does have preheating option
					dm.getPreHeating().active = true
					dm.savePreHeatingSettings()
					optPreheatingAtStartup = true
				}

				if(isV7 === true) // if machine is V7: no preheating option
				{
					dm.getPreHeating().active = false
					dm.savePreHeatingSettings()
					optPreheatingAtStartup = false
				}
			}



			var dateSAR = new Date(_CanHandler.sarDate * 86400 * 1000 + _CanHandler.sarTime*1000); // in ms
			var sarYear = dateSAR.getUTCFullYear()
			var sarMonth = dateSAR.getUTCMonth() + 1 // 0 = january
			var sarDate = dateSAR.getUTCDate()
			var sarHour = dateSAR.getUTCHours()
			var sarMinutes = dateSAR.getUTCMinutes()
			var sarSeconds = dateSAR.getUTCSeconds()

			mcuRtcYear =  sarYear < 2020 ? 2020 : (sarYear > 2099 ? 2099 : sarYear) // 2020 - 2099
			mcuRtcMonth = sarMonth < 1 ? 1 : (sarMonth > 12 ? 12 : sarMonth) // 1 - 12
			mcuRtcDay = sarDate < 1 ? 1 : (sarDate > 31 ? 31 : sarDate) // 1 - 31
			mcuRtcHour = sarHour < 0 ? 0 : (sarHour > 23 ? 23 : sarHour) // 0 - 23
			mcuRtcMinutes = sarMinutes < 0 ? 0 : (sarMinutes > 59 ? 59 : sarMinutes) // 0 - 59
			mcuRtcSeconds = sarSeconds < 0 ? 0 : (sarSeconds > 59 ? 59 : sarSeconds) // 0 - 59

//            console.log("dateTimeManager.getUTCDateTime() : " + dateTimeManager.getUTCDateTime())
//            console.log("getCurrentTimeObj() : " + dateTimeManager.getDay() + "-" + dateTimeManager.getMonth() + "-" + dateTimeManager.getYear() + " "
//                                                 + dateTimeManager.getHour() + ":" + dateTimeManager.getMinutes() + ":" + dateTimeManager.getSeconds())
//            console.log("getUTCDateTime() : " + dateTimeManager.getUTCDateTime().getUTCDate() + "-" + (dateTimeManager.getUTCDateTime().getUTCMonth()+1) + "-" + dateTimeManager.getUTCDateTime().getUTCFullYear() + " "
//                                                 + dateTimeManager.getUTCDateTime().getUTCHours() + ":" + dateTimeManager.getUTCDateTime().getUTCMinutes() + ":" + dateTimeManager.getUTCDateTime().getUTCSeconds())
//            console.log("MCU RTC datetime    : " + mcuRtcDay + "-" + mcuRtcMonth + "-" + mcuRtcYear + " "
//                                                 + mcuRtcHour + ":" + mcuRtcMinutes + ":" + mcuRtcSeconds)

			if(     (backEnd.getSK1SK3combined() === false) // forbid datetime modification if user is trying to access mecha mode 1
			   &&   (dateTimeManager.getManualMode() === false) // only in automatic mode
			   &&   (canError19F0102B === false) // and no CAN error
			   &&   (isV7 === false)) // only V8e
			{
				if(     (dateTimeManager.getUTCDateTime().getUTCFullYear() !== mcuRtcYear)
				   ||   ((dateTimeManager.getUTCDateTime().getUTCMonth()+1) !== mcuRtcMonth)
				   ||   (dateTimeManager.getUTCDateTime().getUTCDate() !== mcuRtcDay)
				   ||   (dateTimeManager.getUTCDateTime().getUTCHours() !== mcuRtcHour)
				   ||   (dateTimeManager.getUTCDateTime().getUTCMinutes() !== mcuRtcMinutes))
				{
					// Set display UTC datetime to MCU datetime
					console.log("Set display UTC datetime to MCU datetime")
					dateTimeManager.setAutoDateTime(mcuRtcYear, mcuRtcMonth, mcuRtcDay, mcuRtcHour, mcuRtcMinutes)
				}
			}

			// PGN 65329
			if((checkMachineType === false) && (isV7 === false))
			{
				if (dataEngine.remainingBatteryDisChargingTime.value > 0xFFAF) {
					RemainingTime.rtMCU = 0.0;
				}
				else {
					RemainingTime.rtMCU = dataEngine.remainingBatteryDisChargingTime.value/3600.0
					// remaining time from MCU, also helps compute remaining soc
				}
			}



			// PGN 65333
			dm.interval_hydraulicOil = 0 // TODO: link to dataengine values dataEngine.hydraulicOilInterval.value
			dm.interval_hydraulicOilRetFilter = 0 // TODO: link to dataengine values dataEngine.hydraulicOilFilterInterval.value
			dm.interval_hydraulicOilRetLineFilter = 0 // TODO: link to dataengine values dataEngine.hydraulicOilReturnLineInterval.value
			dm.interval_travelReductionOil = 0 // TODO: link to dataengine values dataEngine.hydraulicOilTravelInterval.value

			// PGN 65486
			if((dataEngine.remainingSecondBeforeAutoEngStop.value > 0) && (dataEngine.remainingSecondBeforeAutoEngStop.value <= 5)) // last 5 seconds
			{
				var strImage;
				if (isV7 === true) {
					strImage = "qrc:/graphics/Popups/2.6 Auto shut down diesel pop-up.png"
				}
				else {
					strImage = "qrc:/graphics/Popups/2.6 Auto shut down pop-up.png"
				}

				if (dataEngine.remainingSecondBeforeAutoEngStop.value === 5)
				{
					pum.deletePopUp()
					pum.addPopUp(strImage, qsTrId("LBL_0271") + translator.emptyString, 3, 5)
				}
				else if (dataEngine.remainingSecondBeforeAutoEngStop.value === 4)
				{
					pum.deletePopUp()
					pum.addPopUp(strImage, qsTrId("LBL_0272") + translator.emptyString, 3, 5)
				}
				else if (dataEngine.remainingSecondBeforeAutoEngStop.value === 3)
				{
					pum.deletePopUp()
					pum.addPopUp(strImage, qsTrId("LBL_0273") + translator.emptyString, 3, 5)
				}
				else if (dataEngine.remainingSecondBeforeAutoEngStop.value === 2)
				{
					pum.deletePopUp()
					pum.addPopUp(strImage, qsTrId("LBL_0274") + translator.emptyString, 3, 5)
				}
				else if (dataEngine.remainingSecondBeforeAutoEngStop.value === 1)
				{
					pum.deletePopUp()
					pum.addPopUp(strImage, qsTrId("LBL_0275") + translator.emptyString, 3, 5)
				}
			}
		}
	}

	Timer {
		id: checkCanHandlerError
		running: true
		interval: 100
		repeat: true // repeat every 100ms
		onTriggered: {

			// If real screen get the actual CAN value else if emulated screen every CAN error is true
			if(targetARM){

				var canErrorDict = _CanHandler.getCanTimeoutError()

				// 18FEF147 50ms, CCVS, nur V8e
				canError18FEF147 = canErrorDict["419361095"] && !isV7

				// 18FFC047 100ms
				canError18FFC047 = canErrorDict["419414087"]

				// 18FFC147 100ms
				canError18FFC147 = canErrorDict["419414343"]

				// 18FFC447 100ms
				canError18FFC447 = canErrorDict["419415111"]

				// 18FFCB47 1s
				canError18FFCB47 = canErrorDict["419416903"]

				// 18FFCC47 1s
				canError18FFCC47 = canErrorDict["419417159"]

				// 18FFCE47 1s
				canError18FFCE47 = canErrorDict["419417671"]

				// 18FFCF47 100ms
				canError18FFCF47 = canErrorDict["419417927"]

				// 18FEE747 1s
				canError18FEE747 = canErrorDict["419358535"]

				// 18FFE047 1s
				canError18FFE047 = canErrorDict["419422279"]

				// 18FFC347 100ms
				canError18FFC347 = canErrorDict["419414855"] && isV7

				// 18FFD747 1s
				canError18FFD747 = canErrorDict["419419975"]

				// 18FFAE47 100ms
				canError18FFAE47 = canErrorDict["419409479"]

				// 18FFAF47 spontan
				canError18FFAF47 = canErrorDict["419409735"]

				// 18FED931 100ms
				canError18FED931 = canErrorDict["419354929"]

				// 18FF2B03, ZFETC13, 100ms
				canError18FF2B03 = canErrorDict["419375875"] && !isV7

				// CFF7147, ZFSFS1 10ms
				canErrorCFF7147  = canErrorDict["218067271"] && !isV7

				// 18F11447 100ms
				canError18F11447 = canErrorDict["217126023"] && !isV7 // rename to canError18F11487; 217126023 = CF11487

				// 18FEDA03 100ms
				canError18FEDA03 = canErrorDict["419355139"]

				// 18FEDA47 100ms
				canError18FEDA47 = canErrorDict["419355207"]

				// 18FEF700 100ms
				canError18FEF700 = canErrorDict["419362560"] && isV7

				// 18FF1100 100ms
				canError18FF1100 = canErrorDict["419369216"] && isV7

				// CF00400 100ms
				canErrorCF00400  = canErrorDict["217056256"] && isV7

				// 18FEF200 100ms
				canError18FEF200 = canErrorDict["419361280"] && isV7

				// 18FF2403 100ms
				canError18FF2403 = canErrorDict["419374083"] && isV7

				// CF00300 100ms
				canErrorCF003FE = canErrorDict["217056000"] && isV7 // @TODO rename to canErrorCF00300

				// 19F0102B 100ms
				canError19F0102B = canErrorDict["435163179"]

				// 18FF8447 100ms
				canError18FF8447 = canErrorDict["419398727"]

				// 18FEDB00 100ms
				canError18FEDB00 = canErrorDict["419355392"] && isV7

				// 18FF2703 100ms
				canError18FF2703 = canErrorDict["419374851"] && isV7

				canError18A72847 = canErrorDict["413608007"]

			} else {
				canError18FEF147 = true
				canError18FFC047 = true
				canError18FFC147 = true
				canError18FFC447 = true
				canError18FFCB47 = true
				canError18FFCC47 = true
				canError18FFCE47 = true
				canError18FFCF47 = true
				canError18FEE747 = true
				canError18FFE047 = true
				canError18FFC347 = true
				canError18FFD747 = true
				canError18FFAE47 = true
				canError18FFAF47 = true
				canError18FED931 = true
				canError18FF2B03 = true
				canErrorCFF7147 = true
				canError18F11447 = true
				canError18FEDA03 = true
				canError18FEDA47 = true
				canError18FEF700 = true
				canError18FF1100 = true
				canErrorCF00400 = true
				canError18FEF200 = true
				canError18FF2403 = true
				canErrorCF003FE = true
				canError19F0102B = true
				canError18FF8447 = true
				canError18FEDB00 = true
				canError18FF2703 = true
			}


				canErrorAny = (   canError18FEF147 || canError18FFC047 || canError18FFC147
							   || canError18FFCE47 || canError18FEE747 || canError18FFC347
							   || (canError18FFD747 && false) || (canError18FFAE47  && false) || (canError18FFAF47 && false)
							   || (canError18FED931 && false) || canError18FF2B03 || canErrorCFF7147
							   || (canError18FEDA03 && false) || (canError18FEDA47 && false) || canError18FEF700
							   || canError18FF1100 || canErrorCF00400 || canError18FEF200
							   || canError18FF2403 || canErrorCF003FE || (canError19F0102B && false)
							   || canError18FF8447 || canError18FEDB00 || canError18FF2703);

			canErrorMCU = false;
			canErrorTCU = false;
			canErrorECU = false;
			canErrorSAR = false;


		}
	}

	Timer {
		id: checkACCsignal
		running: startupInfo.isManualStartMode()
		interval: 100
		repeat: true // repeat every 100ms
		onTriggered: {
			// @TODO: anpassen an die neue Logik
			if(startupInfo.isManualStartMode() === true && readyForInit === true)
			{
				if(backEnd.getAccsignal() === false)
				{
					startupInfo.setManualStartMode(false)

					if(_CanHandler.BtnMenuImmobilizer_Visible === 1) // There is an immobilizer
					{
						if((canError18FF8447 === true) || (canError18A72847 === true))
						{
							// There is a CAN error: lock the display
							backEnd.currentPage.visible = false
							pg_immobilizer.visible = true
							backEnd.setState(MyAppState.IMMOBILIZER)
							backEnd.setCurrentPage(pg_immobilizer)
							pgHeader.visible = true
							pgHeader.mainMenu = false
							pgHeader.titleString = qsTrId("LBL_0328") + translator.emptyString
							comp_navigationBar.hideEnter = false
							rectList.visible = true
						}
						else
						{
							if(dataEngine.btnImmobActivation_Ctrl.value === 1) // The immobilizer is locked
							{
								if((dataEngine.screenCtrl.value === 2 ) // ScreenCtrl value = show immob general inuput screen
									|| (dataEngine.screenCtrl.value === 1)) {

									backEnd.currentPage.visible = false
									pg_immobilizer.visible = true
									backEnd.setState(MyAppState.IMMOBILIZER)
									backEnd.setCurrentPage(pg_immobilizer)
									pgHeader.visible = true
									pgHeader.mainMenu = false
									pgHeader.titleString = qsTrId("LBL_0328") + translator.emptyString
									comp_navigationBar.hideEnter = false
									rectList.visible = true
								}
								else
								{
									// ScreenCtrl value does not indicate to ask for PIN input
									controller.backToHome()
									console.log("controller.backToHome(), screenCtrl.value = " + screenCtrl.value)
									pg_home.autoControlActive = true
									pg_home.runAutocontrol()
									buzzerManager.buzzerPattern = 6;
								}
							}
							else // The immobilizer is not locked
							{
								controller.backToHome()
								pg_home.autoControlActive = true
								pg_home.runAutocontrol()
								buzzerManager.buzzerPattern = 6;
							}
						}
					}
					else // There is no immobilizer
					{
						controller.backToHome()
						pg_home.autoControlActive = true
						pg_home.runAutocontrol()
						buzzerManager.buzzerPattern = 6;
					}
				}
			}
		}
	}

	Timer {
		id: pictoBlinker
		running: true
		interval: 1000
		repeat: true // repeat every 1s
		onTriggered: {
//			blinkingPictoIsVisible = !blinkingPictoIsVisible

		}
	}

	Timer { // Error from current error list can't be deleted while the user is in these menues
		id: blockList
		running: true
		interval: 300
		repeat: true
		onTriggered: {
			if (backEnd.currentPage === pg_list || backEnd.currentPage === pg_listDetails)
				errorManager.onCurrentErrorPage = true;
			else
				errorManager.onCurrentErrorPage = false;
		}
	}

	// Timer to update every second the visibilty of the menu/buton (message 18FFAF47)
	Timer {
		id: visibleListUpdate18FFAF47
		running: true
		interval: 1000
		repeat: true //repeat every second
		onTriggered: {
			if(!canError18FFAF47){
				btnMenuMonitorVisible = _CanHandler.BtnMenuMonitor_Visible
				btnMenuImmobilizerVisible = _CanHandler.BtnMenuImmobilizer_Visible
				adjustAddCtrlCircuit1Visible = _CanHandler.AdjustAddCtrlCircuit1_Visible
				adjustAddCtrlCircuit2Visible  = _CanHandler.AdjustAddCtrlCircuit2_Visible
				adjustRCSForwardVisible = _CanHandler.AdjustRCSForward_Visible
				adjustRCSBackwardVisible  = _CanHandler.AdjustRCSBackward_Visible
				adjustAutoEngineStopTimeVisible = _CanHandler.AdjustAutoEngineStopTime_Visible
				btnMenuCalendarVisible = _CanHandler.BtnMenuCalendar_Visible
				btnMenuHeatingVisible = _CanHandler.BtnMenuHeating_Visible
				btnFctDateTimeAutoVisible = _CanHandler.BtnFctDateTimeAutomatic_Visible
				btnMenuFiltrRegenVisible = _CanHandler.BtnMenuFiltrRegen_Visible
				btnMenuMaintenanceVisible = _CanHandler.BtnMenuMaintenance_Visible
			} else if(isDev){
				btnMenuMonitorVisible = 1
				btnMenuImmobilizerVisible = 1
				adjustAddCtrlCircuit1Visible = 1
				adjustAddCtrlCircuit2Visible  = 1
				adjustRCSForwardVisible = 1
				adjustRCSBackwardVisible  = 1
				adjustAutoEngineStopTimeVisible = 1
				btnMenuCalendarVisible = 1
				btnMenuHeatingVisible = 1
				btnFctDateTimeAutoVisible = 1
				btnMenuFiltrRegenVisible = 1
				btnMenuMaintenanceVisible = 1
			}
		}
	}

	// Timer to update every second the visibilty of the menu/buton (message 18FFAE47)
	Timer {
		id: visibleListUpdate18FFAE47
		running: true
		interval: 1000
		repeat: true //repeat every second
		onTriggered: {
			if(!canError18FFAE47){
				btnImmobActivationVisible = _CanHandler.BtnImmobActivation_Visible
				btnImmobDriverPinVisible = _CanHandler.BtnImmobDriverPin_Visible
				btnImmobTransPinVisible = _CanHandler.BtnImmobTransPin_Visible
				btnImmobOwnerPinVisible = _CanHandler.BtnImmobOwnerPin_Visible
				btnImmobTimeToActivationVisible = _CanHandler.BtnImmobTimeToActivation_Visible
				btnDiagMCUVisible = _CanHandler.BtnDiagMCU_Visible
				btnDiagECUVisible = _CanHandler.BtnDiagECU_Visible
				btnDiagTCUVisible = _CanHandler.BtnDiagTCU_Visible
			} else if(isDev) {
				btnImmobActivationVisible = 1
				btnImmobDriverPinVisible = 1
				btnImmobTransPinVisible = 1
				btnImmobOwnerPinVisible = 1
				btnImmobTimeToActivationVisible = 1
				btnDiagMCUVisible = 1
				btnDiagECUVisible = 1
				btnDiagTCUVisible = 1
			}
		}
	}

}

import QtQuick 2.0
import MyQmlModule 1.0
import "../components"

Item {
	id: gaugeID

	height: parent.height - backEnd.currentConfig.headerHeight
	width: parent.width
	anchors.topMargin: backEnd.currentConfig.headerHeight

	property int outlineThick: 2
	property bool switchValueSaved: (dm.isImmobActive === 1)
	property bool switchValueShowed: (dm.isImmobActive === 1)
	property string iconPict: "qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 70x70/6.10_Lock time WH.png"

	onVisibleChanged: {
		if(visible === true){
			console.log("Page PG_immobilizerActivation entered")
			bImmobilizerOnOffTriggerSignal = false

			// @TODO: dies muss eigentlich immer aufgerufen werden
			if (canError18A72847 === false) {
				if (dataEngine.btnImmobActivation_Ctrl.value === 3) {
					switchValueShowed = switchValueSaved = dm.isImmobActive
				}
				else if (dataEngine.btnImmobActivation_Ctrl.value === 1) {
					switchValueShowed = switchValueSaved = 1;
				}
				else {
					switchValueShowed = switchValueSaved = 0;
				}
			}
		}
	}

	function upPressed() {
		switchValueShowed = !switchValueShowed
	}

	function downPressed() {
		switchValueShowed = !switchValueShowed
	}

	function enterPressed() {
		if (switchValueShowed !== switchValueSaved) {
			bImmobilizerOnOffTriggerSignal = true
		}
//		switchValueSaved = switchValueShowed?1:0 // @BUG: dies darf hier nicht stehen, erst nach erfolgreicher Authorisierung

		if (bImmobilizerOnOffTriggerSignal === true) {
			console.log("Page PG_immobilizerActivation; Change on/off")

			// Eingabe der Owner-Pin
			backEnd.setState(MyAppState.IMMOBILIZER_ACTIVATION)
			pg_immobilizerActivation.visible = false
			if (1===0) {
				backEnd.setCurrentPage(pg_immobilizer)
				pg_immobilizer.visible = true
			}
			else {
				backEnd.setCurrentPage(pg_pinCode)
				pg_pinCode.visible = true
				pg_pinCode.currentInfoMsg = qsTrId("LBL_0347") + translator.emptyString
				pg_pinCode.errorTxt = false
			}
		}

//		dm.isImmobActive = switchValueSaved?1:0
//		console.log("dm.isImmobActive = " + dm.isImmobActive)
//		dm.saveImmobActive()
//		backToMenu()

//		pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5)
	}

	function menuPressed() {
		console.log("Time to validation configuration canceled")
		switchValueShowed = switchValueSaved
		backToMenu()
	}

	function backToMenu() {
		backEnd.setState(MyAppState.IMMOBILIZER_SETTINGS)
		backEnd.setCurrentPage(pg_listStatusBar)
		pg_listStatusBar.visible = true
		pg_immobilizerActivation.visible = false
		pgHeader.visible = true
		pgHeader.mainMenu = false
		pgHeader.titleString = qsTrId("LBL_0328") + translator.emptyString
	}

	Rectangle {
		id: containerTimeValidationSet
		width: parent.width
		height: parent.height
		color: color_gray
		border {
			color: color_gray_bar
			width: outlineThick
		}
		Comp_switchOnOff {
			id: switchOnOffId
			width: parent.width - (2*outlineThick)
			color: color_gray
			onOff: switchValueShowed
			anchors {
				left: parent.left
				leftMargin: outlineThick
				verticalCenter: parent.verticalCenter
			}
		}
	}
}

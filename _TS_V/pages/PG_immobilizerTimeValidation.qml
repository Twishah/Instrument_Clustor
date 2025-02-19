import QtQuick 2.0
import MyQmlModule 1.0
import "../components"

Item {
    id: gaugeID

    height: parent.height - backEnd.currentConfig.headerHeight
    width: parent.width
    anchors.topMargin: backEnd.currentConfig.headerHeight

    property int outlineThick: 2
    property int validationTimeValueSaved: dm.immobActivationTime
    property int validationTimeValueShowed: dm.immobActivationTime

    property string iconPict: "qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 70x70/6.10_Lock time WH.png"

	onVisibleChanged: {
		if(visible === true){
			console.log("Page PG_immobilizerTimeValidation entered")
		}
	}

    function upPressed() {
        validationTimeValueShowed = (validationTimeValueShowed === 60) ? 60 : validationTimeValueShowed + 5
    }

    function downPressed() {
        validationTimeValueShowed = (validationTimeValueShowed === 0) ? 0 : validationTimeValueShowed - 5
    }

    function enterPressed() {
        validationTimeValueSaved = validationTimeValueShowed
        dm.immobActivationTime = validationTimeValueSaved
        dm.saveImmobActivationTime()
        backToMenu()
        pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5)
    }

    function menuPressed() {
        validationTimeValueShowed = validationTimeValueSaved
        backToMenu()
    }

    function backToMenu() {
        backEnd.setState(MyAppState.IMMOBILIZER_SETTINGS)
        backEnd.setCurrentPage(pg_listStatusBar)
        pg_listStatusBar.visible = true
        pg_immoblizerTimeValidation.visible = false
        pgHeader.visible = true
        pgHeader.mainMenu = false
        pgHeader.titleString = pgHeader.titleString = qsTrId("LBL_0328") + translator.emptyString
    }

    // Background
    Rectangle {
        id: containerTimeValidationSet
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
        id: containerTimeValidationTop
        width: parent.width - comp_navigationBar.width
        height: 72
        color: color_blue

        Image {
            id: vaidationTimeIcon
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
            width: containerTimeValidationTop.width / 2
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
                font.pixelSize: 70
                font.family: systemFont
                anchors {
                    verticalCenter: parent.verticalCenter
                    horizontalCenter: parent.horizontalCenter
                }
                text: validationTimeValueShowed
            }
        }
    }

    // Gauge component
    Rectangle {
        id: timeValidationGaugeContainer
        width: containerTimeValidationTop.width + outlineThick
        height: 110
        color: color_gray
        anchors {
            leftMargin: 0
            left: parent.left
            topMargin: 0
            top: containerTimeValidationTop.bottom
        }
        border {
            color: color_gray_bar
            width: outlineThick
        }

        Comp_timeValidationGauge {
            id: timevalidationGauge
            gaugeValue: validationTimeValueShowed
        }
    }

    // Info text
    Text {
        id: countdwonText
        text: qsTrId("LBL_0345") + translator.emptyString + " " + validationTimeValueShowed.toString() + " min"
        color : color_white
        font.pixelSize: 22
        font.family: systemFont
        anchors {
            left: parent.left
            bottom: parent.bottom
            leftMargin: 7
            bottomMargin: 5
        }
    }
}

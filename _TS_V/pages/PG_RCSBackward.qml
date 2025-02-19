import QtQuick 2.0
import MyQmlModule 1.0
import "../components"

Item {
    id: rcsBackwardID

    height: parent.height - backEnd.currentConfig.headerHeight
    width: parent.width
    anchors.topMargin: backEnd.currentConfig.headerHeight

    property int outlineThick: 2
    property int rcsBackwardValue: dm.rcsBackward

    property int maxSpeed: 20
    property int minSpeed: 1

    property bool isKmh: dm.speedUnitIsKmh

    property string iconPict: "qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 70x70/6.101 Ride control backward_WH.png"

    function upPressed() {
        rcsBackwardValue = (rcsBackwardValue === maxSpeed) ? maxSpeed : rcsBackwardValue + 1
    }

    function downPressed() {
        rcsBackwardValue = (rcsBackwardValue === minSpeed) ? minSpeed : rcsBackwardValue - 1
    }

    function enterPressed() {
        dm.rcsBackward = rcsBackwardValue // Set the new backward RCS value
        dm.saveRCSSettings() // Save the new value in the json files
        backToMenu()
        pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5)
    }

    function menuPressed() {
        rcsBackwardValue = dm.rcsBackward // Reset the local RCS backward value
        backToMenu()
    }

    function backToMenu() {
        backEnd.setState(MyAppState.VEHICULE_SET)
        backEnd.setCurrentPage(pg_listStatusBar)
        pg_listStatusBar.visible = true
        pg_rcsBackward.visible = false
        pgHeader.visible = true
        pgHeader.mainMenu = false
        pgHeader.titleString = qsTrId("LBL_0025") + translator.emptyString
    }

    // Background
    Rectangle {
        id: containerRCSBackwardSet
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
        id: containerRCSBackwardTop
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
            width: containerRCSBackwardTop.width / 2
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
                text: isKmh ? rcsBackwardValue : (rcsBackwardValue*0.625).toFixed(1)
            }
        }
    }

    // Gauge component
    Rectangle {
        id: rcsBackwardGaugeContainer
        width: containerRCSBackwardTop.width + outlineThick
        height: 110
        color: color_gray
        anchors {
            leftMargin: 0
            left: parent.left
            topMargin: 0
            top: containerRCSBackwardTop.bottom
        }
        border {
            color: color_gray_bar
            width: outlineThick
        }

        Comp_RCSGauge {
            id: rcsBackwardGauge
            gaugeValue: rcsBackwardValue
        }
    }

    // Info text
//    Text {
//        id: countdwonText
//        text: (isKmh ? rcsBackwardValue : (rcsBackwardValue*0.625).toFixed(1)).toString() + (isKmh ? " km/h" : " mph") // TODO translation
//        color : color_white
//        font.pixelSize: 22
//        font.family: systemFont
//        anchors {
//            left: parent.left
//            bottom: parent.bottom
//            leftMargin: 10
//        }
//    }
}

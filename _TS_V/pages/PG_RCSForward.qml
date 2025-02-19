import QtQuick 2.0
import MyQmlModule 1.0
import "../components"

Item {
    id: rcsForwardID

    height: parent.height - backEnd.currentConfig.headerHeight
    width: parent.width
    anchors.topMargin: backEnd.currentConfig.headerHeight

    property int outlineThick: 2
    property int rcsForwardValue: dm.rcsFoward

    property int maxSpeed: 20
    property int minSpeed: 1

    property string iconPict: "qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 70x70/6.100_Ride control forward_WH.png"

    property bool isKmh: dm.speedUnitIsKmh

    function upPressed() {
        rcsForwardValue = (rcsForwardValue === maxSpeed) ? maxSpeed : rcsForwardValue + 1
    }

    function downPressed() {
        rcsForwardValue = (rcsForwardValue === minSpeed) ? minSpeed : rcsForwardValue - 1
    }

    function enterPressed() {
        dm.rcsFoward = rcsForwardValue // Set the new forward RCS value
        dm.saveRCSSettings() // Save the new value in the json files
        backToMenu()
        pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5)
    }

    function menuPressed() {
        rcsForwardValue = dm.rcsFoward // Reset the local RCS forward value
        backToMenu()
    }

    function backToMenu() {
        backEnd.setState(MyAppState.VEHICULE_SET)
        backEnd.setCurrentPage(pg_listStatusBar)
        pg_listStatusBar.visible = true
        pg_rcsForward.visible = false
        pgHeader.visible = true
        pgHeader.mainMenu = false
        pgHeader.titleString =  qsTrId("LBL_0025") + translator.emptyString
    }

    // Background
    Rectangle {
        id: containerRCSForwardSet
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
        id: containerRCSForwardTop
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
            width: containerRCSForwardTop.width / 2
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
                text: isKmh ? rcsForwardValue : (rcsForwardValue*0.625).toFixed(1)
            }
        }
    }

    // Gauge component
    Rectangle {
        id: rcsForwardGaugeContainer
        width: containerRCSForwardTop.width + outlineThick
        height: 110
        color: color_gray
        anchors {
            leftMargin: 0
            left: parent.left
            topMargin: 0
            top: containerRCSForwardTop.bottom
        }
        border {
            color: color_gray_bar
            width: outlineThick
        }

        Comp_RCSGauge {
            id: rcsForwardGauge
            gaugeValue: rcsForwardValue
        }
    }

//    // Info text
//    Text {
//        id: countdwonText
//        text: (isKmh ? rcsForwardValue : (rcsForwardValue*0.625).toFixed(1)).toString() + (isKmh ? " km/h" : " mph") // TODO translation
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

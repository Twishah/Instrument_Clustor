import QtQuick 2.6
import QtGraphicalEffects 1.0
import QtQuick.Layouts 1.3

Rectangle {
    id: backgroundRow

    property int outlineThick: 2
    property int pos: 0

    width: 269
    height: 44
    color: "transparent"

    anchors {
        left: parent.left
        leftMargin: 3
    }

    border {
        width: outlineThick
        color: isCurrent ? color_blue : color_gray_bar
    }

    property var errorInfo: null
    property string dtcIconPict: ""
    property bool isCurrent: false

    onErrorInfoChanged: { // select the proper DTC Icon to display
        if (errorInfo.priority === 1) {
            if (errorInfo.dtcIconId === "A") {
                dtcIconPict = "qrc:/graphics/ErrorList/3.9 Inverter DTC - Large - white.png";
            } else if (errorInfo.dtcIconId === "B") {
                dtcIconPict = "qrc:/graphics/ErrorList/3.13 Motor DTC - Large - white.png";
            } else if (errorInfo.dtcIconId === "C") {
                dtcIconPict = "qrc:/graphics/ErrorList/3.17 MCU DTC - Large - white.png";
            } else if (errorInfo.dtcIconId === "D") {
                dtcIconPict = "qrc:/graphics/ErrorList/3.21 Temperature MCU DTC - Large - white.png";
            } else if (errorInfo.dtcIconId === "E") {
                dtcIconPict = "qrc:/graphics/ErrorList/3.25 Charger DTC - Large - white.png";
            } else if (errorInfo.dtcIconId === "F") {
                dtcIconPict = "qrc:/graphics/ErrorList/3.29 BMS DTC -Large - white.png";
            } else if (errorInfo.dtcIconId === "G") {
                dtcIconPict = "qrc:/graphics/ErrorList/3.33 Battery temperature DTC - Large - white.png";
            } else if (errorInfo.dtcIconId === "H") {
                dtcIconPict = "qrc:/graphics/ErrorList/3.37 Keypad - Large - white.png";
            } else if (errorInfo.dtcIconId === "I") {
                dtcIconPict = "qrc:/graphics/ErrorList/3.41 LCD DTC - Large - white.png";
            } else
                dtcIconPict = "";
        } else {
            if (errorInfo.dtcIconId === "A") {
                dtcIconPict = "qrc:/graphics/ErrorList/3.11 Inverter DTC - Large - black.png";
            } else if (errorInfo.dtcIconId === "B") {
                dtcIconPict = "qrc:/graphics/ErrorList/3.15 Motor DTC - Large - black.png";
            } else if (errorInfo.dtcIconId === "C") {
                dtcIconPict = "qrc:/graphics/ErrorList/3.19 MCU DTC - Large - black.png";
            } else if (errorInfo.dtcIconId === "D") {
                dtcIconPict = "qrc:/graphics/ErrorList/3.23 Temperature MCU DTC - Large - black.png";
            } else if (errorInfo.dtcIconId === "E") {
                dtcIconPict = "qrc:/graphics/ErrorList/3.27 Charger DTC - Large - black.png";
            } else if (errorInfo.dtcIconId === "F") {
                dtcIconPict = "qrc:/graphics/ErrorList/3.31 BMS DTC -Large - black.png";
            } else if (errorInfo.dtcIconId === "G") {
                dtcIconPict = "qrc:/graphics/ErrorList/3.35 Battery temperature DTC - Large - black.png";
            } else if (errorInfo.dtcIconId === "H") {
                dtcIconPict = "qrc:/graphics/ErrorList/3.39 Keypad - Large - black.png";
            } else if (errorInfo.dtcIconId === "I") {
                dtcIconPict = "qrc:/graphics/ErrorList/3.43 LCD DTC - Large - black.png";
            } else
                dtcIconPict = "";
        }
    }

    Rectangle {
        id: row
        width: parent.width
        height: parent.height - (outlineThick * 2)
        color: errorInfo.priority === 1 ? color_red : errorInfo.priority === 2 ? color_yellow_error : color_gray_error
        anchors {
            left: parent.left
            verticalCenter: parent.verticalCenter
        }

        Rectangle {
            id: leftBorder

            width: outlineThick
            height: parent.height
            color: isCurrent ? color_blue : errorInfo.priority === 1 ? color_red : errorInfo.priority === 2 ? color_yellow_error : color_gray_error
            anchors.left: row.left
        }

        Rectangle {
            id: rightBorder

            width: outlineThick
            height: parent.height
            color: isCurrent ? color_blue : errorInfo.priority === 1 ? color_red : errorInfo.priority === 2 ? color_yellow_error : color_gray_error
            anchors.right: row.right
        }

        Image {
            id: errorLevelIcon
            anchors {
                left: parent.left
                leftMargin: 6
                verticalCenter: parent.verticalCenter
            }
            fillMode: Image.Pad
            source: errorInfo.priority === 1 ? "qrc:/graphics/ErrorList/3.3 WARNING- Large - white.png" : errorInfo.priority === 2 ? "qrc:/graphics/ErrorList/3.5 CAUTION - Large - black.png" : "qrc:/graphics/ErrorList/3.8 Maintenance - Large - black.png"
        }

        Image {
            id: errorDtcIcon
            width: 38
            height: parent.height
            anchors {
                left: parent.left
                leftMargin: 45
            }
            horizontalAlignment: Image.AlignHCenter
            verticalAlignment: Image.AlignVCenter
            fillMode: Image.Pad

            source: dtcIconPict
            visible: true
            }

        Text {
            id: errorCode
            color: errorInfo.priority === 1 ? color_white : color_black
            font.pixelSize: 18
            font.family: systemFont
            anchors {
                left: parent.left
                leftMargin: 108
                verticalCenter: parent.verticalCenter
            }
            text: errorInfo && errorInfo.dtcCode ? errorInfo.dtcCode === "MAINTENANCE" ? (qsTrId("LBL_0057") + translator.emptyString).toUpperCase() : errorInfo.dtcCode.slice(2) : ""
        }
    }
}

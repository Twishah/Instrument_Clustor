import QtQuick 2.6
import QtGraphicalEffects 1.0

Rectangle {
    id: listIconNewItem

    property bool isCurrent: false
    property bool state: false
    property string titreText: ""
    property string iconPict: "qrc:/graphics/PtoSettings/7.47 Selection light OFF.png"
    property string checkboxOFF: "qrc:/graphics/PtoSettings/7.47 Selection light OFF.png"
    property string checkboxON: "qrc:/graphics/PtoSettings/7.46 Selection light ON.png"

    function changeState() {
        if (iconPict === checkboxOFF) {
            iconPict = checkboxON
            state = true
        }
        else if (iconPict === checkboxON) {
            iconPict = checkboxOFF
            state = false
        }
        else {
            iconPict = ""
            state = false
        }
        console.log(state)
    }

    width: 273
    height: 36
    color: isCurrent ? color_blue : color_gray
    border {
        color: color_gray_bar
        width: 1
    }

    Image {
        id: checkboxIcon
        anchors {
            left: parent.left
            leftMargin: 5
            verticalCenter: parent.verticalCenter
        }
        fillMode: Image.Pad
        source: iconPict
    }

    Text {
        id: itemText
        color: color_white
        font.pixelSize: 17
        font.family: systemFont
        anchors {
            left: checkboxIcon.right
            verticalCenter: parent.verticalCenter
            leftMargin: 8
        }
        text: titreText
    }

}

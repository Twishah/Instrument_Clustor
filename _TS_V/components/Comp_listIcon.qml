import QtQuick 2.6
import QtGraphicalEffects 1.0

Rectangle {
    id: listIconItem

    property bool isCurrent: false
    property bool isHighlightable: true
    property bool isSelectable: true
    property bool isSelected: false
    property string title: ""
    property bool isCheckbox: true
    property bool textVisible: false

    width: 271
    height: 34

    color: (isCurrent && isHighlightable) ? color_blue : color_gray

    Image {
        id: checkboxIcon
        anchors {
            left: parent.left
            leftMargin: 5
            verticalCenter: parent.verticalCenter
        }
        fillMode: Image.Pad
        source: isSelectable ? isSelected ? "qrc:/graphics/PtoSettings/7.46 Selection light ON.png" : "qrc:/graphics/PtoSettings/7.47 Selection light OFF.png" : ""
        visible: isCheckbox
    }

    Text {
        id: itemText
        color: color_white
        font.pixelSize: 17
        font.family: systemFont
        anchors {
            left: isCheckbox ? checkboxIcon.right : parent.left
            verticalCenter: parent.verticalCenter
            leftMargin: isCheckbox ? 8 : 5
        }
        text: title
        wrapMode: Text.WordWrap
        elide: Text.ElideRight
        width: isCheckbox ? parent.width - anchors.leftMargin - checkboxIcon.width : parent.width - anchors.leftMargin
        visible: textVisible
    }

}

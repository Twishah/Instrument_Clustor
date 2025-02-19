import QtQuick 2.0

Rectangle {
    id: numberContainer

    property bool isCurrent: false      // when section selected and OK clicked, to navigate

    property int resultNumber: 0
    property int currentNumber: 0
    property bool isArrows: false
    property int fontPxSize: 20

    function confirmValue() {
        resultNumber = currentNumber;
    }

    function cancelValue() {
        currentNumber = resultNumber;
    }

    width: 0.15 * parent.width
    height: 30
    color: isCurrent ? color_blue : color_gray
    border {
        color: isArrows ? (isCurrent ? color_blue : color_gray_bar) : "transparent"
        width: 2
    }

    Text {
        id: numberText
        text: currentNumber < 10 && !pg_passcode.visible ? currentNumber : currentNumber
        color: color_white
        font.pixelSize: fontPxSize
        font.family: systemFont
        anchors {
            horizontalCenter: parent.horizontalCenter
            verticalCenter: parent.verticalCenter
        }
    }

    Image {
        id: arrowUp
        source: isCurrent ? "qrc:/graphics/Menu/5.27 Arrow up - blue.png" : "qrc:/graphics/Menu/5.25 Arrow up - grey.png"
        anchors {
            bottom: numberContainer.top
            bottomMargin: 2
            horizontalCenter: numberContainer.horizontalCenter
        }
        fillMode: Image.Pad
        visible: isArrows
    }

    Image {
        id: arrowDw
        source: isCurrent ? "qrc:/graphics/Menu/5.28 Arrow down - blue.png" : "qrc:/graphics/Menu/5.26 Arrow down - grey.png" //model.iconDwON : model.iconDwOFF
        anchors {
            top: numberContainer.bottom
            topMargin: 2
            horizontalCenter: numberContainer.horizontalCenter
        }
        fillMode: Image.Pad
        visible: isArrows
    }
}

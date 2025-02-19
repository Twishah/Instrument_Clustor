import QtQuick 2.0

Rectangle {
    id: numberContainer

    property bool isCurrent: false      // when section selected and OK clicked, to navigate
    property bool isDone: false
    property int resultNumber: 0
    property int currentNumber: 0
    property int fontPxSize: 20

    function confirmValue() {
        resultNumber = currentNumber;
    }

    function cancelValue() {
        currentNumber = resultNumber;
    }

    width: 55
    height: 55
    color: isCurrent ? color_blue : color_gray
    border {
        color: color_gray_bar
        width: 2
    }

    Text {
        id: numberText
        text: isDone ? "*" : isCurrent ? currentNumber : ""
        color: color_white
        font.pixelSize: 40
        font.family: systemFont
        anchors {
            horizontalCenter: parent.horizontalCenter
            verticalCenter: parent.verticalCenter
        }
    }

    Image {
        id: arrowUp
        source: isCurrent ? "qrc:/graphics/Menu/5.27 Arrow up - blue.png" : ""
        anchors {
            bottom: numberContainer.top
            bottomMargin: 2
            horizontalCenter: numberContainer.horizontalCenter
        }
        fillMode: Image.Pad
        visible: isCurrent
    }

    Image {
        id: arrowDw
        source: isCurrent ? "qrc:/graphics/Menu/5.28 Arrow down - blue.png" : ""
        anchors {
            top: numberContainer.bottom
            topMargin: 2
            horizontalCenter: numberContainer.horizontalCenter
        }
        fillMode: Image.Pad
        visible: isCurrent
    }
}

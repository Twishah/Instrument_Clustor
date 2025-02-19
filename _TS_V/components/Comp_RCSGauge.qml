import QtQuick 2.0

Item {

    id: rcsGauge
    width: parent.width
    height: parent.height

    property int outlineThickness: 2
    property int gaugeValue: 0
    property bool isKmh: dm.speedUnitIsKmh

    // Component Background
    Rectangle {
        id: rcsBackground
        width: parent.width - 2*outlineThickness
        height: parent.height - 2*outlineThickness
        color: color_gray
        anchors{
            left: parent.left
            leftMargin: outlineThickness
            top: parent.top
            topMargin: outlineThickness
        }
    }

    // Gauge background
    Rectangle {
        id: rcsGaugeBackground
        width: 225
        height: 30
        color: color_gray_bar
        anchors{
            horizontalCenter: rcsBackground.horizontalCenter
            bottom: parent.bottom
            bottomMargin: 20
        }
    }

    // First tick
    Rectangle {
        id: rcsGaugeTick1
        width: 3
        height: 5
        color: color_gray_bar
        anchors{
            left: rcsGaugeBackground.left
            bottom: rcsGaugeBackground.top
        }
    }

    // Last tick
    Rectangle {
        id: rcsGaugeTick4
        width: 3
        height: 5
        color: color_gray_bar
        anchors{
            right: rcsGaugeBackground.right
            bottom: rcsGaugeBackground.top
        }
    }

    // Second tick
    Rectangle {
        id:rcsGaugeTick2
        width: 3
        height: 5
        color: color_gray_bar
        x: rcsGaugeTick1.x + (rcsGaugeTick4.x - rcsGaugeTick1.x)/3
        anchors{
            bottom: rcsGaugeBackground.top
        }
    }

    // Third tick
    Rectangle {
        id: rcsGaugeTick3
        width: 3
        height: 5
        color: color_gray_bar
        x: rcsGaugeTick1.x + 2*(rcsGaugeTick4.x - rcsGaugeTick1.x)/3
        anchors{
            bottom: rcsGaugeBackground.top
        }
    }

    Text {
        id: gaugeText0
        color:  "white"
        font.pixelSize: 25
        font.family: systemFont
        anchors {
            bottom: rcsGaugeTick1.top
            horizontalCenter: rcsGaugeTick1.horizontalCenter
        }
        text: "0";
    }

    Text {
        id: gaugeText100
        color:  "white"
        font.pixelSize: 25
        font.family: systemFont
        anchors {
            bottom: rcsGaugeTick4.top
            right: rcsGaugeTick4.right
            rightMargin: -5
        }
        text: isKmh ? "20" : "12.5";
    }

    Repeater {
        id: gaugeRepeater
        model: 20
        delegate: Rectangle {
            id: rcsGaugeBar
            x: rcsGaugeBackground.x + outlineThickness + index * this.width
            y: rcsGaugeBackground.y + outlineThickness
            width: (rcsGaugeBackground.width - 2*outlineThickness) / 20
            height: rcsGaugeBackground.height - 2*outlineThickness
            color: index<gaugeValue ? color_blue : "transparent"
        }
    }
}

import QtQuick 2.0

Item {

    id: timeValidationGauge
    width: parent.width
    height: parent.height

    property int outlineThickness: 2
    property int gaugeValue: 0

    // Component Background
    Rectangle {
        id: timeValidationBackground
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
        id: timeValidationGaugeBackground
        width: 225
        height: 30
        color: color_gray_bar
        anchors{
            horizontalCenter: timeValidationBackground.horizontalCenter
            bottom: parent.bottom
            bottomMargin: 20
        }
    }

    // First tick
    Rectangle {
        id: timeValidationGaugeTick1
        width: 3
        height: 5
        color: color_gray_bar
        anchors{
            left: timeValidationGaugeBackground.left
            bottom: timeValidationGaugeBackground.top
        }
    }

    // Last tick
    Rectangle {
        id: timeValidationGaugeTick4
        width: 3
        height: 5
        color: color_gray_bar
        anchors{
            right: timeValidationGaugeBackground.right
            bottom: timeValidationGaugeBackground.top
        }
    }

    // Second tick
    Rectangle {
        id:timeValidationGaugeTick2
        width: 3
        height: 5
        color: color_gray_bar
        x: timeValidationGaugeTick1.x + (timeValidationGaugeTick4.x - timeValidationGaugeTick1.x)/3
        anchors{
            bottom: timeValidationGaugeBackground.top
        }
    }

    // Third tick
    Rectangle {
        id: timeValidationGaugeTick3
        width: 3
        height: 5
        color: color_gray_bar
        x: timeValidationGaugeTick1.x + 2*(timeValidationGaugeTick4.x - timeValidationGaugeTick1.x)/3
        anchors{
            bottom: timeValidationGaugeBackground.top
        }
    }

    Text {
        id: gaugeText0
        color:  "white"
        font.pixelSize: 25
        font.family: systemFont
        anchors {
            bottom: timeValidationGaugeTick1.top
            horizontalCenter: timeValidationGaugeTick1.horizontalCenter
        }
        text: "0";
    }

    Text {
        id: gaugeText100
        color:  "white"
        font.pixelSize: 25
        font.family: systemFont
        anchors {
            bottom: timeValidationGaugeTick4.top
            right: timeValidationGaugeTick4.right
            rightMargin: -5
        }
        text: "60";
    }

    Repeater {
        id: gaugeRepeater
        model: 12
        delegate: Rectangle {
            id: timeValidationGaugeBar
            x: timeValidationGaugeBackground.x + outlineThickness + index * this.width
            y: timeValidationGaugeBackground.y + outlineThickness
            width: (timeValidationGaugeBackground.width - 2*outlineThickness) / 12
            height: timeValidationGaugeBackground.height - 2*outlineThickness
            color: {
                if (index<(gaugeValue/5)) {
                    return color_blue;
                } else {
                    return "transparent";
                }
            }
        }
    }
}

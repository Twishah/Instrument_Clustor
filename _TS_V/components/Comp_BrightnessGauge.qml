import QtQuick 2.0

Item {

    id: brightnessGauge
    width: 255
    height: 110

    property int outlineThickness: 2
    property int gaugeValue: 70

    // Component Background
    Rectangle {
        id: brightnessBackground
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
        id: brightnessGaugeBackground
        width: 220
        height: 30
        color: color_gray_bar
        anchors{
            horizontalCenter: brightnessBackground.horizontalCenter
            bottom: parent.bottom
            bottomMargin: 20
        }
    }

    // First tick
    Rectangle {
        id: brightnessGgaugeTick1
        width: 3
        height: 5
        color: color_gray_bar
        anchors{
            left: brightnessGaugeBackground.left
            bottom: brightnessGaugeBackground.top
        }
    }

    // Last tick
    Rectangle {
        id: brightnessGgaugeTick4
        width: 3
        height: 5
        color: color_gray_bar
        anchors{
            right: brightnessGaugeBackground.right
            bottom: brightnessGaugeBackground.top
        }
    }

    // Second tick
    Rectangle {
        id: brightnessGgaugeTick2
        width: 3
        height: 5
        color: color_gray_bar
        x: brightnessGgaugeTick1.x + (brightnessGgaugeTick4.x - brightnessGgaugeTick1.x)/3
        anchors{
            bottom: brightnessGaugeBackground.top
        }
    }

    // Third tick
    Rectangle {
        id: brightnessGgaugeTick3
        width: 3
        height: 5
        color: color_gray_bar
        x: brightnessGgaugeTick1.x + 2*(brightnessGgaugeTick4.x - brightnessGgaugeTick1.x)/3
        anchors{
            bottom: brightnessGaugeBackground.top
        }
    }

    Text {
        id: gaugeText0
        color:  "white"
        font.pixelSize: 25
        font.family: systemFont
        anchors {
            bottom: brightnessGgaugeTick1.top
            horizontalCenter: brightnessGgaugeTick1.horizontalCenter
        }
        text: "0";
    }

    Text {
        id: gaugeText100
        color:  "white"
        font.pixelSize: 25
        font.family: systemFont
        anchors {
            bottom: brightnessGgaugeTick4.top
            right: brightnessGgaugeTick4.right
            rightMargin: -5
        }
        text: "100";
    }



    Repeater {
        id: gaugeRepeater
        model: 10
        delegate: Rectangle {
            id: brightnessGaugeBar
            //x: (brightnessGaugeBackground.width - (outlineThickness / 2)) - ((index + 1) * this.width)//gaugePict.x + (outlineThickness / 2)
            x: brightnessGaugeBackground.x + outlineThickness + index * this.width
            y: brightnessGaugeBackground.y + outlineThickness //(gaugePict.y + gaugeBackground.height - (outlineThickness / 2)) - ((index + 1) * this.height)
            width: (brightnessGaugeBackground.width - 2*outlineThickness) / 10//gaugePict.width - outlineThickness
            height: brightnessGaugeBackground.height - 2*outlineThickness//(gaugeBackground.height - outlineThickness) / 8
            color: {
                if (index<(gaugeValue/10)) {
                    return color_blue;
//                } else if (index >= 6 && base.state > index) {
//                    return color_red;
//                } else if (base.state > index) {
//                    return color_white;
                } else {
                    return "transparent";
                }
            }
        }
    }
}

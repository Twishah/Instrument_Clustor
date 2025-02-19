import QtQuick 2.0
import MyQmlModule 1.0

Item {

    id: sootLevelGauge
    width: parent.width
    height: parent.height

    property int outlineThickness: 2
    property int gaugeValue: 0
    property int gaugeState: 0
    property int gaugeRange: 0
    property int gaugeIncrement: 0

    // Component Background
    Rectangle {
        id: sootLevelBackground
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
        id: sootLevelGaugeBackground
        width: 225
        height: 30
        color: color_gray_bar
        anchors{
            horizontalCenter: sootLevelBackground.horizontalCenter
            bottom: parent.bottom
            bottomMargin: 20
        }
    }

    // First tick
    Rectangle {
        id: sootLevelGaugeTick1
        width: 3
        height: 5
        color: color_gray_bar
        anchors{
            left: sootLevelGaugeBackground.left
            bottom: sootLevelGaugeBackground.top
        }
    }

    // Last tick
    Rectangle {
        id: sootLevelGaugeTick4
        width: 3
        height: 5
        color: color_gray_bar
        anchors{
            right: sootLevelGaugeBackground.right
            bottom: sootLevelGaugeBackground.top
        }
    }

    // Second tick
    Rectangle {
        id:sootLevelGaugeTick2
        width: 3
        height: 5
        color: color_gray_bar
        x: sootLevelGaugeTick1.x + (sootLevelGaugeTick4.x - sootLevelGaugeTick1.x)/3
        anchors{
            bottom: sootLevelGaugeBackground.top
        }
    }

    // Third tick
    Rectangle {
        id: sootLevelGaugeTick3
        width: 3
        height: 5
        color: color_gray_bar
        x: sootLevelGaugeTick1.x + 2*(sootLevelGaugeTick4.x - sootLevelGaugeTick1.x)/3
        anchors{
            bottom: sootLevelGaugeBackground.top
        }
    }

    Text {
        id: gaugeText0
        color:  "white"
        font.pixelSize: 25
        font.family: systemFont
        anchors {
            bottom: sootLevelGaugeTick1.top
            horizontalCenter: sootLevelGaugeTick1.horizontalCenter
        }
        text: "0";
    }

    Text {
        id: gaugeText100
        color:  "white"
        font.pixelSize: 25
        font.family: systemFont
        anchors {
            bottom: sootLevelGaugeTick4.top
            right: sootLevelGaugeTick4.right
            rightMargin: -5
        }
        text: gaugeRange.toString();
    }

    Repeater {
        id: gaugeRepeater
        model: gaugeRange
        delegate: Rectangle {
            id: sootLevelGaugeBar
            x: sootLevelGaugeBackground.x + outlineThickness + index * this.width
            y: sootLevelGaugeBackground.y + outlineThickness
            width: (sootLevelGaugeBackground.width - 2*outlineThickness) / gaugeRange
            height: sootLevelGaugeBackground.height - 2*outlineThickness
            color: {
                if (backEnd.state === MyAppState.SOOT_LEVEL){
                    if (index<(gaugeValue/gaugeIncrement)) {
                        if(gaugeValue < 80) {
                            return color_blue
                        } else if(gaugeValue < 120) {
                            return color_yellow
                        } else {
                            return color_red
                        }
                    } else {
                        return "transparent";
                    }
                } else if (backEnd.state === MyAppState.ASH_LEVEL){
                    if (index<(gaugeValue/gaugeIncrement)) {
                        if(gaugeValue < 80) {
                            return color_blue
                        } else if(gaugeValue < 100) {
                            return color_yellow
                        } else {
                            return color_red
                        }
                    } else {
                        return "transparent";
                    }
                } else {
                    return "transparent";
                }
            }
        }
    }
}

import QtQuick 2.6
import QtGraphicalEffects 1.0
import QtQuick.Layouts 1.3

Rectangle {
    property string leftGaugePict: ""
    property bool leftGaugePictHighlight: false
    property string rightGaugePict: ""
    property bool rightGaugePictHighlight: false
    property string title: ""
    property int outlineThickness: 2
    property string colorRect: color_gray

    id: ptoOutline
    width: 273
    height: 69
    color: "transparent"
    border {
        color: colorRect
        width: outlineThickness
    }

    Image {
        id: leftGauge
        fillMode: Image.Pad
        source: leftGaugePict
        anchors {
            left: parent.left
            top: parent.top
            leftMargin: 5
            topMargin: 20
        }
    }
    Image {
        id: leftGaugeHighlight
        fillMode: Image.Pad
        source:  "qrc:/graphics/PtoSettings/FramePTOHighlight.png"
        anchors {
            left: parent.left
            top: parent.top
            leftMargin: 5
            topMargin: 20
        }
        visible: leftGaugePictHighlight
    }
    Image {
        id: rightGauge
        fillMode: Image.Pad
        source: rightGaugePict
        anchors {
            right: parent.right
            top: parent.top
            rightMargin: 4
            topMargin: 20
        }
        transform: Scale {
            xScale: -1
            origin.x: rightGauge.width / 2
            origin.y: rightGauge.height / 2
        }
    }
    Image {
        id: rightGaugeHighlight
        fillMode: Image.Pad
        source:  "qrc:/graphics/PtoSettings/FramePTOHighlight.png"
        anchors {
            right: parent.right
            top: parent.top
            rightMargin: 4
            topMargin: 20
        }
        transform: Scale {
            xScale: -1
            origin.x: rightGauge.width / 2
            origin.y: rightGauge.height / 2
        }
        visible: rightGaugePictHighlight
    }
    Text {
        id: middleText
        text: title
        color:  color_white
        font {
            pixelSize: 14
            family: systemFont
        }
        anchors {
            top: parent.top
            topMargin: 4
            horizontalCenter: parent.horizontalCenter
        }
    }
    Text {
        id: leftText
        text: "L"
        color:  color_white
        font {
            pixelSize: 16
            family: systemFont
        }
        anchors {
            top: parent.top
            topMargin: 2
            left: parent.left
            leftMargin: 5
        }
    }
    Text {
        id: rightText
        text: "R"
        color:  color_white
        font {
            pixelSize: 16
            family: systemFont
        }
        anchors {
            top: parent.top
            topMargin: 2
            right: parent.right
            rightMargin: 5
        }
    }
}

/******************************************************************************
 * ButtonTempl component
******************************************************************************/

import QtQuick 2.0
import QtGraphicalEffects 1.0


Item {
    id: button

    property bool highlighted: false
    property string imgFileName: ""
    property string altFileName:  ""
    property bool useAltImage: false
    signal buttonClick()

    width: parent.width
    height: parent.height

    onUseAltImageChanged: {
        highlighted: false;
    }

    Item {
        id: iconContainer
        anchors.centerIn: parent
        width: parent.width
        height: parent.height

        Keys.forwardTo: controller

        Behavior on opacity { NumberAnimation { easing.type: Easing.InOutQuad; duration: 600 } }

        Image {
            id: iconBody
            source: useAltImage ? altFileName : imgFileName
            anchors.fill: parent
            scale: button.scale
            fillMode: Image.Pad
            anchors.horizontalCenter: iconContainer.horizontalCenter
            anchors.verticalCenter: iconContainer.verticalCenter

            ColorOverlay {
                anchors.fill: parent
                source: parent
                color: highlighted ? "orange" : color_white //!!!
            }
        }

        MouseArea {
            anchors.fill: parent

            onClicked: button.buttonClick();
        }
    }
}

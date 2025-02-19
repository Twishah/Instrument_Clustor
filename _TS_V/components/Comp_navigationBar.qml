/******************************************************************************
 * comp_navigationBar component
******************************************************************************/

import QtQuick 2.0

Item {
    width: 47
    height: parent.height / 4
    x: isShowing ? parent.width - width : parent.width
    z: 1000
    opacity: 0.75

    property bool hideEnter: true
    property bool outsideMainMenu: false
    property bool isShowing: false
    //property bool isShowing: true // PC emulation
    property bool isNavigationMode: false

    Image {
        id: background
        source: "qrc:/graphics/Menu/4.1 Drop-down background.png"
        fillMode: Image.Pad
        anchors {
            left: parent.left
            top: parent.top
            leftMargin: -15
            topMargin: -14
        }
    }

    Column {
        anchors.fill: parent

        Comp_buttonTempl {
            id: buttonUp
            imgFileName: "qrc:/graphics/Menu/4.2 Arrow up - white.png"
            altFileName: "qrc:/graphics/Menu/4.6 AUX -white.png"
            useAltImage: hideEnter
            //highlighted: controller.upButtonPressed
            onButtonClick: { controller.upPressed(); controller.upReleased() }
        }
        Comp_buttonTempl {
            id: buttonDown
            imgFileName: "qrc:/graphics/Menu/4.3 Arrow down - white.png"
            altFileName: "qrc:/graphics/Menu/4.7 Empty white.png"
            useAltImage: hideEnter
            //highlighted: controller.downButtonPressed
            onButtonClick: { controller.downPressed(); controller.downReleased() }
        }
        Comp_buttonTempl {
            id: buttonEnter
            imgFileName: "qrc:/graphics/Menu/4.4 OK - white.png"
            //highlighted: controller.enterButtonPressed
            onButtonClick: { controller.enterPressed(); controller.enterReleased() }
            //opacity: hideEnter ? 0.0 : 1.0
        }
        Comp_buttonTempl {
            id: buttonMenu
            imgFileName: "qrc:/graphics/Menu/4.5 Menu -white.png"
            altFileName: "qrc:/graphics/Menu/4.8 Return white.png"
            useAltImage: outsideMainMenu
            //highlighted: controller.menuButtonPressed
            onButtonClick: { controller.menuPressed(); controller.menuReleased() }
        }
    }

    Behavior on x
    {
        id: animation
        enabled: false

        NumberAnimation {
            target: comp_navigationBar
            property: "x"
            duration: 600
            easing.type: Easing.InOutQuad
        }
    }

    onXChanged: {
        if ((pg_home.visible || pg_home2.visible) && x === 320) {
            if (pg_home.visible) {
                pg_home.revertPtoSetting(false)
                comp_navigationBar.hideEnter = true
            }
        }
    }

    Timer {
        id: hideFirstAnimation
        running: true
        repeat: false
        interval: 500
        onTriggered: animation.enabled = true;
    }
}

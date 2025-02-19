import QtQuick 2.6

Item {
    id: temperatureGaugeItem
    width: 320
    height: 240 - 2 * backEnd.currentConfig.headerHeight - 10
    y: backEnd.currentConfig.headerHeight

    property var temperatureControltab: [0, 12, 25, 37, 50, 62, 75, 87, 100]
    property int temperatureTabIndex: 0
    property int temperatureControl: temperatureControltab[0]
    property bool autoControlRampUp: true
    property bool mainMenu: false                           // display design for main menu or sub menu
    property double temperature: pg_home.autoControlActive ? temperatureControl : canError18FFCE47 ? 100 : dataEngine.gaugeCoolingTemperature.value
    property double angleNeedle: temperature > 100 ? -50 : temperature < 0 ? 0 : -50 * temperature/100 // The 0 of the gauge is 60 degres celsius and the top of the gauge is 120 degrees celsius

    Timer {
        id: autoControlTimer
        interval: pg_home.autoControlDuration/18
        running: true
        repeat: true
        onTriggered: {
            if(pg_home.autoControlActive === true)
            {
                if(temperatureTabIndex == 8)
                {
                    autoControlRampUp = false
                }

                if(autoControlRampUp === true)
                {
                    temperatureTabIndex += 1
                }
                else
                {
                    if(temperatureTabIndex >= 1)
                    {
                        temperatureTabIndex -= 1
                    }
                }

                temperatureControl = temperatureControltab[temperatureTabIndex]
            }
        }
    }

    onTemperatureChanged: {
        angleNeedle = temperature > 100.0 ? -50.0 : temperature < 0 ? 0 : -50.0 * temperature/100.0
    }

    Image {
        id: temperatureGaugeIcon
        x: parent.width/2 + 75
        y: 68  - backEnd.currentConfig.headerHeight
        width: 60
        height: 115
        source: "qrc:/graphics/03_Gauges PNG/03_Gauges PNG 25x25/3.12_Gauge temperature_60x115_V2.png"
        fillMode: Image.Pad
        visible: temperatureGaugeItem.mainMenu
    }

    Image {
        id: coolantTempIcon
        x: parent.width/2 + 120
        y: parent.height/2 - coolantTempIcon.height
        width: 24
        height: 24
        source: "qrc:/graphics/03_Gauges PNG/2.15_Coolant temperature_WH.png"
        fillMode: Image.Pad
        visible: temperatureGaugeItem.mainMenu
    }

    Image {
        id: pointerIcon
        x: parent.width/2
        y: 172  - backEnd.currentConfig.headerHeight
        width: 130
        height: 8
        source: "qrc:/graphics/03_Gauges PNG/3.11_Pointer 2.png"
        fillMode: Image.Pad
        visible: temperatureGaugeItem.mainMenu
        transform: Rotation { origin.x: 0; origin.y: pointerIcon.height/2 ; axis {x: 0; y: 0; z: 1} angle: angleNeedle}

    }

    Item {
        id: textCContainer
        x: temperatureGaugeIcon.x - 12
        y: temperatureGaugeIcon.y - 7

        Text {
            id: textC
            text: "H"
            font.pixelSize: 15
            font.family: systemFont
            color: color_white
            visible: temperatureGaugeItem.mainMenu
        }
    }

    Item {
        id: textGContainer
        x: temperatureGaugeIcon.x + temperatureGaugeIcon.width + 6
        y: temperatureGaugeIcon.y + temperatureGaugeIcon.height - 14

        Text {
            id: textG
            text: "C"
            font.pixelSize: 15
            font.family: systemFont
            color: color_white
            visible: temperatureGaugeItem.mainMenu
        }
    }
}

import QtQuick 2.0
import MyQmlModule 1.0
import "../components"

Item {
    id: gaugeID

    property int outlineThick: 2
    property string iconPict: "qrc:/graphics/DisplaySettings/7.53 Day brightness setting - white.png"

    //property var backLightPercentages: [1, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100]
    property var backLightValues: [3, 26, 51, 77, 102, 128, 153, 179, 204, 230, 255]

    property int backLightPercentage: 100 * backLightHandler.currentBacklightValue/255
    property int backLightValueSaved: backLightHandler.currentBacklightValue
    property int backLightDayPercentage: 100 * dm.getDayBrightness()/255
    property int backLightNightPercentage: 100 * dm.getNightBrightness()/255
    property int backLightDayValuesIndex: backLightDayPercentage / 10
    property int backLightNightValuesIndex: backLightNightPercentage / 10
    property int backLightDayValuesIndexSaved: backLightDayPercentage / 10
    property int backLightNightValuesIndexSaved: backLightNightPercentage / 10

    height: 320
    width: 240
    anchors.topMargin: backEnd.currentConfig.headerHeight

    function resetBrightness()
    {
        backLightDayPercentage = 100
        backLightNightPercentage = 30
        backLightDayValuesIndex = 10
        backLightNightValuesIndex = 3
        backLightDayValuesIndexSaved = 10
        backLightNightValuesIndexSaved = 3

        // Update the brightness values
        dm.setDayBrightness(255)
        backLightDayPercentage = 100 * dm.getDayBrightness()/255
        dm.setNightBrightness(77)
        backLightNightPercentage = 100 * dm.getNightBrightness()/255

        // Save the brightness values
        dm.saveBrightness()
    }

    function selectDayBrightnessModel()
    {
        iconPict = "qrc:/graphics/DisplaySettings/7.53 Day brightness setting - white.png"
        //console.log("lights on : " + dataEngine.lightOn.value)
        backLightValueSaved = backLightHandler.currentBacklightValue
        backLightDayValuesIndexSaved = backLightDayValuesIndex
        console.log("backLightValueSaved : " + backLightValueSaved)
        backLightPercentage = backLightDayPercentage
        var targetDayBrightness = dm.getDayBrightness()
        backLightHandler.currentBacklightValue = targetDayBrightness
        console.log("current backlight value : " + backLightHandler.currentBacklightValue)
    }

    function selectNightBrightnessModel()
    {
        iconPict = "qrc:/graphics/DisplaySettings/7.54 Night brightness setting - white.png"
        backLightValueSaved = backLightHandler.currentBacklightValue
        //console.log("backLightValueSaved : " + backLightValueSaved)
        backLightNightValuesIndexSaved = backLightNightValuesIndex
        backLightPercentage = backLightNightPercentage
        var targetNightBrightness = dm.getNightBrightness()
        backLightHandler.currentBacklightValue = targetNightBrightness
        //console.log("current backlight value : " + backLightHandler.currentBacklightValue)
    }

    function menuPressed()
    {
        if ((backEnd.state === MyAppState.DS_2_BRIGHTNESS_DAY) || (backEnd.state === MyAppState.DS_2_BRIGHTNESS_NIGHT)) {

            //console.log("====== EXITING =======")
            // here we have to set the backlight value back to what it was before accessing this screen
            //console.log("backLightValueSaved : " + backLightValueSaved)
            backLightHandler.currentBacklightValue = backLightValueSaved
            backLightPercentage = 100 * backLightHandler.currentBacklightValue/255
            backLightDayValuesIndex = backLightDayValuesIndexSaved
            backLightNightValuesIndex = backLightNightValuesIndexSaved
            backEnd.setState(MyAppState.DS_1_BRIGHTNESS)
            backEnd.setCurrentPage(pg_listStatusBar)
            pg_gauge.visible = false
            pgHeader.titleString = qsTrId("LBL_0010") + translator.emptyString
            pg_listStatusBar.selectBrightnessModeList()
            pg_listStatusBar.visible = true
            console.log("Display settings page selected")
        }
    }

    function upPressed()
    {
        //console.log("========================")
        //console.log("before increase : " + backLightHandler.currentBacklightValue)
        if(backEnd.state === MyAppState.DS_2_BRIGHTNESS_DAY)
        {
            backLightDayValuesIndex = (backLightDayValuesIndex==10) ? 10 : backLightDayValuesIndex + 1
            //console.log("new day index : " + backLightDayValuesIndex)
            backLightHandler.currentBacklightValue = backLightValues[backLightDayValuesIndex]
        }
        else if(backEnd.state === MyAppState.DS_2_BRIGHTNESS_NIGHT)
        {
            backLightNightValuesIndex = (backLightNightValuesIndex==10) ? 10 : backLightNightValuesIndex + 1
            //console.log("new night index : " + backLightNightValuesIndex)
            backLightHandler.currentBacklightValue = backLightValues[backLightNightValuesIndex]
        }
        //console.log("after increase : " + backLightHandler.currentBacklightValue)
        backLightPercentage = 100 * backLightHandler.currentBacklightValue/255
    }

    function downPressed()
    {
        //console.log("========================")
        //console.log("before decrease : " + backLightHandler.currentBacklightValue)
        if(backEnd.state === MyAppState.DS_2_BRIGHTNESS_DAY)
        {
            backLightDayValuesIndex = (backLightDayValuesIndex==1) ? 1 : backLightDayValuesIndex - 1
            //console.log("new day index : " + backLightDayValuesIndex)
            backLightHandler.currentBacklightValue = backLightValues[backLightDayValuesIndex]
        }
        else if(backEnd.state === MyAppState.DS_2_BRIGHTNESS_NIGHT)
        {
            backLightNightValuesIndex = (backLightNightValuesIndex==1) ? 1 : backLightNightValuesIndex - 1
            //console.log("new night index : " + backLightNightValuesIndex)
            backLightHandler.currentBacklightValue = backLightValues[backLightNightValuesIndex]
        }
        //console.log("after decrease : " + backLightHandler.currentBacklightValue)
        backLightPercentage = 100 * backLightHandler.currentBacklightValue/255
        console.log(" backLightPercentage = " + backLightPercentage)
    }

    function enterPressed()
    {
        /*pop-up N°4 (code : xx/xxx) appears and simultaneously the buzzer blows the
        model N°5, to indicate the validation of the parameters then the screen
        automatically returns to the Brightness settings screen*/
        if (backEnd.state === MyAppState.DS_2_BRIGHTNESS_DAY) {

            // update the day brightness value
            dm.setDayBrightness(backLightHandler.currentBacklightValue)
            dm.saveBrightness()
            backLightDayPercentage = 100 * dm.getDayBrightness()/255

            // set the correct brightness, if the brightness has to change
            if(dataEngine.ind_DayNightChangeOver.value === 1) // 1 -> Night mode
            {
                // set the night backlight value
                 backLightHandler.currentBacklightValue = dm.getNightBrightness()
            }

            // Synchronize saved index with real index
            backLightDayValuesIndexSaved = backLightDayValuesIndex

            // return to the brightness setting page
            pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5);
            backEnd.setState(MyAppState.DS_1_BRIGHTNESS)
            backEnd.setCurrentPage(pg_listStatusBar)
            pg_gauge.visible = false
            pgHeader.titleString = qsTrId("LBL_0010") + translator.emptyString
            pg_listStatusBar.selectBrightnessModeList()
            pg_listStatusBar.visible = true
            console.log("Display settings page selected")
        }
        else if (backEnd.state === MyAppState.DS_2_BRIGHTNESS_NIGHT) {


            // update the night brightness value
            dm.setNightBrightness(backLightHandler.currentBacklightValue)
            dm.saveBrightness()
            backLightNightPercentage = 100 * dm.getNightBrightness()/255

            // set the correct brightness, if the brightness has to change
            if(dataEngine.ind_DayNightChangeOver.value === 0) // 0 -> Day mode
            {
                // set the day backlight value
                backLightHandler.currentBacklightValue = dm.getDayBrightness()
            }

            // Synchronize saved index with real index
            backLightNightValuesIndexSaved = backLightNightValuesIndex

            // return to the brightness setting page
            pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5);
            backEnd.setState(MyAppState.DS_1_BRIGHTNESS)
            backEnd.setCurrentPage(pg_listStatusBar)
            pg_gauge.visible = false
            pgHeader.titleString = qsTrId("LBL_0010") + translator.emptyString
            pg_listStatusBar.selectBrightnessModeList()
            pg_listStatusBar.visible = true
            console.log("Display settings page selected")
        }
    }

    // Background
    Rectangle {
        id: containerDayBrightnessSet
        width: 255
        height: parent.height
        color: color_gray
        border {
            color: color_gray_bar
            width: outlineThick
        }
    }

    // Top data
    Rectangle {
        id: containerDayBrightnessTop
        width: containerDayBrightnessSet.width
        height: 72
        color: color_blue

        Image {
            id: dayBrightnessIcon
            anchors {
                left: parent.left
                leftMargin: 35
                verticalCenter: parent.verticalCenter
            }
            fillMode: Image.Pad
            source: iconPict
        }

        Rectangle {
            id: backgroundText
            width: containerDayBrightnessTop.width / 2
            height: parent.height - outlineThick / 2
            color: color_gray
            anchors {
                right: parent.right
                rightMargin: outlineThick
                verticalCenter: parent.verticalCenter
            }
            border {
                color: color_blue
                width: outlineThick
            }

            Text {
                id: textStatusBar
                color:  color_white
                font.pixelSize: 70
                font.family: systemFont
                anchors {
                    verticalCenter: parent.verticalCenter
                    horizontalCenter: parent.horizontalCenter
                }
                text: backLightPercentage
            }
        }
    }

    // Gauge component
    Rectangle {
        id: brightnessGaugeContainer
        width: containerDayBrightnessSet.width
        height: 110
        color: color_gray
        anchors {
            leftMargin: 0
            left: parent.left
            topMargin: 0
            top: containerDayBrightnessTop.bottom
        }
        border {
            color: color_gray_bar
            width: outlineThick
        }

        Comp_BrightnessGauge {
            id: brightnessGauge
            gaugeValue: backLightPercentage
        }
    }
}

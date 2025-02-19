import QtQuick 2.0
import MyQmlModule 1.0
import QtGraphicalEffects 1.0
import "../components"

Flickable {
    id: largeListID

    width: parent.width
    height: parent.height
    anchors.topMargin: backEnd.currentConfig.headerHeight
    visible: false
    opacity: visible ? 1.0 : 0.0
    Behavior on opacity { NumberAnimation { easing.type: Easing.InOutQuad; duration: 600 } }
    focus: true
    Keys.forwardTo: controller
    boundsBehavior: Flickable.StopAtBounds

    property Item modelSelected : displaySettingsModel
    property int outlineThickness: container.children[0].anchors.topMargin

    onModelSelectedChanged: {
        downPressed();
        upPressed();
        upPressed();
        downPressed();
    }

    function selectDisplaySettingsModel(reset) {
        modelSelected = displaySettingsModel
        if (reset)
            resetIndex();
    }

    function selectOperationalManagementModel() {
        modelSelected = operationalManagementModel
        resetIndex()
    }

    function selectMaintenanceModel() {
        modelSelected = maintenanceModel

        // Change of a property of an element of the model to show the third element or not (depending on the mechanic mode)
        if (controller.isMechanicMode2) {
            maintenanceModel.sources[2].visible = true
            maintenanceModel.nbItems = 3
        }
        else {
            maintenanceModel.sources[2].visible = false
            maintenanceModel.nbItems = 2
        }

        resetIndex()
    }

    function selectLanguage() {
        backEnd.setState(MyAppState.DS_1_LANGUAGE)
        backEnd.setCurrentPage(pg_listIcon)
        pg_largeList.visible = false
        pgHeader.titleString = qsTrId("LBL_0011") + translator.emptyString
        pg_listIcon.selectLanguagesModel()
        pg_listIcon.visible = true
        console.log("Language page selected")
    }

    function selectCalendar() {
        backEnd.setState(MyAppState.OMM_1_CALENDAR)
        backEnd.setCurrentPage(pg_calendar)
        pg_largeList.visible = false
        pgHeader.titleString = qsTrId("LBL_0039") + translator.emptyString
        pg_calendar.visible = true
        console.log("Calendar page selected")
    }

    function selectOPTimeMeas() {
        backEnd.setState(MyAppState.OMM_1_TIME)
        backEnd.setCurrentPage(pg_opTimeMeas)
        pg_largeList.visible = false
        pgHeader.titleString = qsTrId("LBL_0050") + translator.emptyString
        pg_opTimeMeas.visible = true
        console.log("Time measurement page selected")
    }

    function selectDateTime() {
        backEnd.setState(MyAppState.DS_1_DATE_TIME)
        backEnd.setCurrentPage(pg_listStatusBar)
        pg_largeList.visible = false
        pgHeader.titleString = qsTrId("LBL_0012") + translator.emptyString
        pg_listStatusBar.selectDateTimeSettingsList()
        pg_listStatusBar.visible = true
        console.log("Date and Time page selected")
    }

    function selectMaintenanceTimeReset() {
        backEnd.setState(MyAppState.MM_1_RESET)
        backEnd.setCurrentPage(pg_listStatusBar)
        pg_largeList.visible = false
        pgHeader.titleString = qsTrId("LBL_0057") + translator.emptyString
        pg_listStatusBar.selectMaintenanceList()
        pg_listStatusBar.visible = true
        console.log("Maintenance time and reset page selected")
    }

    function selectMaintenanceHistory() {
        backEnd.setState(MyAppState.MM_1_HISTORY)
        backEnd.setCurrentPage(pg_listLargeStatusBar)
        pg_largeList.visible = false
        pgHeader.titleString = qsTrId("LBL_0279") + translator.emptyString
        //pg_listLargeStatusBar.resetAllHistory()
        pg_listLargeStatusBar.selectMaintenanceHistoryList()
        pg_listLargeStatusBar.visible = true
        console.log("Maintenance history page selected")
    }

    function selectMaintenanceInterval() {
        backEnd.setState(MyAppState.MM_1_INTERVAL)
        backEnd.setCurrentPage(pg_listStatusBar)
        pg_largeList.visible = false
        pgHeader.titleString = qsTrId("LBL_0325") + translator.emptyString
        pg_listStatusBar.selectMaintenanceList()
        pg_listStatusBar.visible = true
        console.log("Interval maintenance change page selected")
    }

    function selectUnit() {
        backEnd.setState(MyAppState.DS_1_UNIT)
        backEnd.setCurrentPage(pg_listStatusBar)
        pg_largeList.visible = false
        pgHeader.titleString = qsTrId("LBL_0021") + translator.emptyString
        pg_listStatusBar.selectUnitSettingsList()
        pg_listStatusBar.visible = true
        console.log("Unit page selected")
    }

    function selectSound() {
        backEnd.setState(MyAppState.DS_1_SOUND)
        backEnd.setCurrentPage(pg_listIcon)
        pg_largeList.visible = false
        pgHeader.titleString = qsTrId("LBL_0009") + translator.emptyString
        pg_listIcon.selectSoundSettingModel()
        pg_listIcon.visible = true
        console.log("Sound page selected")
    }

    function selectBrightness() {
        backEnd.setState(MyAppState.DS_1_BRIGHTNESS)
        backEnd.setCurrentPage(pg_listStatusBar)
        pg_largeList.visible = false
        pgHeader.titleString = qsTrId("LBL_0010") + translator.emptyString
        pg_listStatusBar.selectBrightnessModeList()
        pg_listStatusBar.resetIndexes()
        pg_listStatusBar.visible = true
        console.log("Brightness page selected")
    }

    function verifyMaintenance(percent) {
        var result = ""
        if (percent >= 100.0) {
            result = "red"
        }
        else if (percent >= 90.0) {
            result = "orange"
        }
        else {
            result = "white"
        }
        return result
    }

    function verifyMaintenanceElapsedTime() {
        var countWhite = 0
        var countOrange = 0
        var countRed = 0

        var results = []
        results.push(verifyMaintenance(pg_listStatusBar.percent_hydraulicOil))
        results.push(verifyMaintenance(pg_listStatusBar.percent_hydraulicOilRetFilter))
        results.push(verifyMaintenance(pg_listStatusBar.percent_hydraulicOilRetLineFilter))
        results.push(verifyMaintenance(pg_listStatusBar.percent_travelReductionOil))

        for (var i = 0; i < results.length; i++) {
            if (results[i] === "red") {
                countRed++
            }
            else if (results[i] === "orange") {
                countOrange++
            }
            else if (results[i] === "white") {
                countWhite++
            }
        }
        //console.log(countRed + " " + countOrange + " " + countWhite)

        if (countRed >= 1) {
            maintenanceModel.currentIcon = maintenanceModel.sources[0].iconRed
        }
        else if (countOrange >= 1) {
            maintenanceModel.currentIcon = maintenanceModel.sources[0].iconOrange
        }
        else {
            maintenanceModel.currentIcon = maintenanceModel.sources[0].iconWhite
        }
    }

    function resetIndex() {
        modelSelected.currentIndex = 0
        contentY = 0
    }

    function menuPressed()
    {
        // View Menu page
        if (controller.isMechanicMode1) {
            backEnd.setState(MyAppState.MENU_MECA_1)
        }
        else if (controller.isMechanicMode2) {
            backEnd.setState(MyAppState.MENU_MECA_2)
        }
        else if (!startupInfo.isManualStartMode()) {
            backEnd.setState(MyAppState.MENU)
        }
        else if (startupInfo.isManualStartMode()) {
            pg_home2.restartTimeoutTimer()
            backEnd.setState(MyAppState.MENU_HOUR_METER)
        }

        backEnd.setCurrentPage(pg_menu)
        pg_largeList.visible = false
        pgHeader.visible = false
        pg_menu.visible = true
        rectList.visible = false
        rectMenu.visible = true
    }

    function enterPressed()
    {
        if (startupInfo.isManualStartMode()) {
            pg_home2.restartTimeoutTimer()
        }

        modelSelected.sources[modelSelected.currentIndex].action()
    }

    function downPressed()
    {
        if (startupInfo.isManualStartMode()) {
            pg_home2.restartTimeoutTimer()
        }

        modelSelected.currentIndex = (modelSelected.currentIndex + 1) % modelSelected.nbItems
        var itemY = modelSelected.currentIndex * 71;
        if (itemY + 71 > contentY + height) {
            contentY = itemY + 71 - height + 2;
        } else if (itemY < contentY) {
            contentY = itemY;
        }

        // Increment of 2 when Maintenance has 2 elements instead of 3 (like in the mechanic mode)
        if (!controller.isMechanicMode2 && modelSelected === maintenanceModel && maintenanceModel.currentIndex === 2) {
            maintenanceModel.currentIndex = (maintenanceModel.currentIndex - 1 + maintenanceModel.nbItems) % maintenanceModel.nbItems
        }
    }

    function upPressed()
    {
        if (startupInfo.isManualStartMode()) {
            pg_home2.restartTimeoutTimer()
        }

        modelSelected.currentIndex = (modelSelected.currentIndex - 1 + modelSelected.nbItems) % modelSelected.nbItems
        var itemY = modelSelected.currentIndex * 71;
        if (itemY < contentY) {
            contentY = itemY;
        } else if (itemY + container.children[0].height > contentY + height) {
            contentY = itemY + 71 - height + 2;
        }

        // Decrement of 2 when Maintenance has 2 elements instead of 3 (like in the mechanic mode)
        if (!controller.isMechanicMode2 && modelSelected === maintenanceModel && maintenanceModel.currentIndex === 2) {
            maintenanceModel.currentIndex = (maintenanceModel.currentIndex + 1) % maintenanceModel.nbItems
        }
    }

    Item {
        id: displaySettingsModel

        property int currentIndex: 0
        property int nbItems: 5

        property var sources: [
            {
                "icon": "qrc:/graphics/Icons/7.41 Language settings - white.png",
                "title": qsTrId("LBL_0006") + translator.emptyString,
                "visible": true,
                "action":function() { pg_largeList.selectLanguage() }
            },
            {
                "icon": "qrc:/graphics/Icons/7.42 Date and time settings - white.png",
                "title": qsTrId("LBL_0007") + translator.emptyString,
                "visible": true,
                "action": function() { pg_largeList.selectDateTime() }
            },
            {
                "icon": "qrc:/graphics/Icons/7.43 Unit settings - white.png",
                "title": qsTrId("LBL_0008") + translator.emptyString,
                "visible": true,
                "action": function() { pg_largeList.selectUnit() }
            },
            {
                "icon": "qrc:/graphics/Icons/7.44 Sound settings - white.png",
                "title": qsTrId("LBL_0009") + translator.emptyString,
                "visible": true,
                "action": function() { pg_largeList.selectSound() }
            },
            {
                "icon": "qrc:/graphics/Icons/7.45 Brightness settings - white.png",
                "title": qsTrId("LBL_0010") + translator.emptyString,
                "visible": true,
                "action": function() { pg_largeList.selectBrightness() }
            }
        ];
    }

    Item {
        id: operationalManagementModel

        property int currentIndex: 0
        property int nbItems: 2

        property var sources: [
            {
                "icon": "qrc:/graphics/OperationalManagementMode/7.37 Operational management mode - white.png",
                "title":  qsTrId("LBL_0039") + translator.emptyString,
                "visible": true,
                "opacity": btnMenuCalendarVisible === 1 ? 1 : 0.3,
                "action": btnMenuCalendarVisible === 1 ? function() {  pg_largeList.selectCalendar() } : {},
            },
            {
                "icon": "qrc:/graphics/OperationalManagementMode/7.65 Operation time measurement - white.png",
                "title": qsTrId("LBL_0050") + translator.emptyString,
                "visible": true,
                "opacity": 1,
                "action": function() { pg_largeList.selectOPTimeMeas() }
            }
        ];
    }

    Item {
        id: maintenanceModel

        property int currentIndex: 0
        property int nbItems: 3
        property string currentIcon: "qrc:/graphics/MaintenanceMode/7.66 Maintenance time and reset - white.png"

        property var sources: [
            {
                "icon": maintenanceModel.currentIcon,
                "iconWhite": "qrc:/graphics/MaintenanceMode/7.66 Maintenance time and reset - white.png",
                "iconOrange": "qrc:/graphics/MaintenanceMode/7.67 Maintenance time and reset - orange.png",
                "iconRed": "qrc:/graphics/MaintenanceMode/7.68 Maintenance time and reset - red.png",
                "title": maintenanceModel.currentIcon === "qrc:/graphics/MaintenanceMode/7.67 Maintenance time and reset - orange.png" || maintenanceModel.currentIcon === "qrc:/graphics/MaintenanceMode/7.68 Maintenance time and reset - red.png" ? qsTrId("LBL_0357") + translator.emptyString : qsTrId("LBL_0058") + translator.emptyString,
                "visible": true,
                "action": function() { pg_largeList.selectMaintenanceTimeReset() }
            },
            {
                "icon": "qrc:/graphics/MaintenanceMode/7.69 Maintenance history - white.png",
                "iconWhite": "",
                "iconOrange": "",
                "iconRed": "",
                "title": qsTrId("LBL_0059") + translator.emptyString,
                "visible": true,
                "action": function() { pg_largeList.selectMaintenanceHistory() }
            },
            {
                "icon": "qrc:/graphics/MaintenanceMode/7.70 Change maintenance interval - white.png",
                "iconWhite": "",
                "iconOrange": "",
                "iconRed": "",
                "title": qsTrId("LBL_0060") + translator.emptyString,
                "visible": false,
                "action": function() { pg_largeList.selectMaintenanceInterval() }
            }
        ];
    }

    Rectangle {
        id: container

        width: container.children[0].width + 4
        height: modelSelected.nbItems < 3 ? (container.children[0].height + outlineThickness) * 3 + outlineThickness : (container.children[0].height + outlineThickness) * modelSelected.nbItems + outlineThickness
        color: color_gray_bar
        rotation: 0

        Repeater {
            model: modelSelected.nbItems < 3 ? 3 : modelSelected.nbItems

            Comp_listItem {
                id: listItem
                sourceIcon: index >= modelSelected.nbItems ? "" : modelSelected.sources[index].icon
                title: index >= modelSelected.nbItems ? "" : modelSelected.sources[index].title
                isCurrent: modelSelected.currentIndex === index ? true : false
                anchors.top: index === 0 ? parent.top : parent.children[index-1].bottom
                anchors.topMargin: 2
                opacity: modelSelected === operationalManagementModel && modelSelected.sources[index] ? modelSelected.sources[index].opacity : 1
                x: 2
            }
        }
    }
}

import QtQuick 2.6
import MyQmlModule 1.0
import QtGraphicalEffects 1.0
import "../components"

Rectangle {
    id: preHeatingID
    width: parent.width
    height: parent.height
    color: color_gray
    anchors.topMargin: backEnd.currentConfig.headerHeight

    property int layerdIndex: 0 // Menu navigation
    property int menuIndex: 0

    onVisibleChanged: {
        if (pg_preHeating.visible) {
            workStartLevel.is12HourFormat = dm.getFormatHour() === 1 ? true : false
            workStartLevel.selectWorkHOur(false)
            workStartLevel.selectWorkMin(false)
            initializePreheatingTime()
        }
    }

    function initializePreheatingTime() {
        workStartLevel.initializeHeatAndWorkTimes()
    }

    function resetIndexes() {
        layerdIndex = 0
        menuIndex = 0
        activateLevel.isCurrent = false
    }

    function setDay(index){
        dateLevel.updateImageSources(index, true);
        dm.setPreHeatingDate(index, true);
    }

    function unsetDay(index){
        dateLevel.updateImageSources(index, false);
        dm.setPreHeatingDate(index, false);
    }

    function menuPressed()
    {
        if (layerdIndex === 0) {
            // View Menu page
            if (controller.isMechanicMode1) {
                backEnd.setState(MyAppState.MENU_MECA_1)
            }
            else if (controller.isMechanicMode2) {
                backEnd.setState(MyAppState.MENU_MECA_2)
            }
            else {
                backEnd.setState(MyAppState.MENU)
            }
            backEnd.setCurrentPage(pg_menu)
            pg_preHeating.visible = false
            pgHeader.visible = false
            pg_menu.visible = true
            rectList.visible = false
            rectMenu.visible = true
        }
        else if(layerdIndex === 1) {
            if(menuIndex === 1){
                workStartLevel.selectWorkHOur(false);
                workStartLevel.cancelWorkTime();
                layerdIndex = 0;
            } else if (menuIndex === 2) {
                activateLevel.isCurrent = false;
                layerdIndex = 0;
            }

        }
        else if(layerdIndex === 2) {
            if(menuIndex === 1){
                workStartLevel.selectWorkMin(false);
                workStartLevel.cancelWorkTime();
                layerdIndex = 0;
            }
        }
    }

    function upPressed()
    {
        if (layerdIndex === 0) {
            menuIndex = (menuIndex - 1 + levelsController.length) % levelsController.length

        }
        else if(layerdIndex === 1) {
            if(menuIndex === 1){
                workStartLevel.increaseWorkHour();
            } else if(menuIndex === 2){
                activateLevel.onOff = !activateLevel.onOff;
            }

        }
        else if(layerdIndex === 2) {
            if(menuIndex === 1){
                workStartLevel.increaseWorkMin();
            }
        }
    }

    function downPressed()
    {
        if (layerdIndex === 0) {
            menuIndex = (menuIndex + 1) % levelsController.length

        }
        else if(layerdIndex === 1) {
            if(menuIndex === 1){
                workStartLevel.decreaseWorkHour();
            } else if(menuIndex === 2){
                activateLevel.onOff = !activateLevel.onOff;
            }
        }
        else if(layerdIndex === 2) {
            if(menuIndex === 1){
                workStartLevel.decreaseWorkMin();
            }
        }
    }

    function enterPressed()
    {
        if (layerdIndex === 0 ) {
            if(menuIndex === 0) {
                backEnd.setState(MyAppState.PH_1_DAY)
                backEnd.setCurrentPage(pg_listIconMultiple)
                pg_preHeating.visible = false
                pgHeader.titleString = qsTrId("LBL_0067") + translator.emptyString
                pg_listIconMultiple.selectPreHeatingDaySetList()
                pg_listIconMultiple.visible = true
                console.log("Day setting selected")
            } else if(menuIndex === 1) {
                layerdIndex = 1;
                workStartLevel.selectWorkHOur(true);
            } else if(menuIndex === 2) {
                layerdIndex = 1;
                activateLevel.onOff = dm.getPreHeating().active
                activateLevel.isCurrent = true;
            }
        }
        else if(layerdIndex === 1) {    
            if(menuIndex === 1){
                layerdIndex = 2;
                workStartLevel.selectWorkHOur(false);
                workStartLevel.selectWorkMin(true);
            } else if(menuIndex === 2) {
                if(activateLevel.onOff) { // ON
                    pum.addPopUp("qrc:/graphics/Popups/2.8 Pre-heating pop-up.png", qsTrId("LBL_0269") + translator.emptyString, 4, 5);
                }
                else // OFF
                {
                    pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5);
                }
                dm.getPreHeating().active = activateLevel.onOff
                activateLevel.isCurrent = false;
                layerdIndex = 0;
                dm.savePreHeatingSettings()
            }
        }
        else if(layerdIndex === 2) {
            if(menuIndex === 1) {
                layerdIndex = 0;
                workStartLevel.selectWorkMin(false);
                workStartLevel.validateWorkTime();
                dm.savePreHeatingSettings()
            }

        }
    }


    Rectangle {
        id: levelsController
        width: parent.width
        height: parent.height
        color: parent.color
        property int isCurrentIndex: preHeatingID.menuIndex // current index to navigate between levels
        property int length: 3


        Comp_specificClassification_levelDate {
            id: dateLevel
        }

        Comp_specificClassification_levelWorkStart {
            id: workStartLevel
            anchors.top: dateLevel.bottom
        }

        Comp_specificClassification_levelActivate {
            id: activateLevel
            anchors.top: workStartLevel.bottom
        }

    }

}

import QtQuick 2.6
import MyQmlModule 1.0
import QtGraphicalEffects 1.0
import "../components"

Rectangle {
    id: dateSelectionID

    width: parent.width
    height: parent.height
    color: color_gray
    anchors.topMargin: backEnd.currentConfig.headerHeight

    property int layerdIndex: 0

    onVisibleChanged: {
        if (pg_dateSelection.visible) {
            dateTimeLevels.is12HourFormat = dm.getFormatHour()
        }
    }


    function initializeDateTimeManu() {
        layerdIndex = 0
        dateTimeLevels.selectDay(true)
        dateTimeLevels.selectMonth(false)
        dateTimeLevels.selectYear(false)
        dateTimeLevels.selectHour(false)
        dateTimeLevels.selectMin(false)
        dateTimeLevels.updateAllNumbers()
    }

    function menuPressed()
    {
        if(layerdIndex === 0) {
            if(!dateTimeLevels.valideDate)
            {
                dateTimeLevels.resetDateTimeInvalid()
            }
            dateTimeLevels.selectDay(true)
            dateTimeLevels.cancelDate()
        }
        else if(layerdIndex === 1) {
            dateTimeLevels.selectMonth(false)
            dateTimeLevels.cancelDate()
        }
        else if(layerdIndex === 2) {
            dateTimeLevels.selectYear(false)
            dateTimeLevels.cancelDate()
        }
        else if(layerdIndex === 3) {
            dateTimeLevels.selectHour(false)
            dateTimeLevels.cancelTime()

        }
        else if(layerdIndex === 4) {
            dateTimeLevels.selectMin(false)
            dateTimeLevels.cancelTime()
        }

        layerdIndex = 0
        dateTimeLevels.selectDay(true)

        pgHeader.visible = true
        pgHeader.mainMenu = false
        pgHeader.titleString = qsTrId("LBL_0013") + translator.emptyString
        pg_listIcon.selectDateTimeModeModel() // V8e only
        pg_listIcon.visible = true
        pg_dateSelection.visible = false
        backEnd.setState(MyAppState.DS_2_DATE_TIME_SET)
        backEnd.setCurrentPage(pg_listIcon)
    }

    function upPressed()
    {
        if(layerdIndex === 0) {
            if(!dateTimeLevels.valideDate)
            {
                dateTimeLevels.resetDateTimeInvalid()
            }
            dateTimeLevels.increaseDay()
        }
        else if(layerdIndex === 1) {
            dateTimeLevels.increaseMonth()
        }
        else if(layerdIndex === 2) {
            dateTimeLevels.increaseYear()
        }
        else if(layerdIndex === 3) {
            dateTimeLevels.increaseHour()
        }
        else if(layerdIndex === 4) {
            dateTimeLevels.increaseMin()
        }
    }

    function downPressed()
    {
        if(layerdIndex === 0) {
            if(!dateTimeLevels.valideDate)
            {
                dateTimeLevels.resetDateTimeInvalid()
            }
            dateTimeLevels.decreaseDay()
        }
        else if(layerdIndex === 1) {
            dateTimeLevels.decreaseMonth()
        }
        else if(layerdIndex === 2) {
            dateTimeLevels.decreaseYear()
        }
        else if(layerdIndex === 3) {
            dateTimeLevels.decreaseHour()
        }
        else if(layerdIndex === 4) {
            dateTimeLevels.decreaseMin()
        }
    }

    function enterPressed()
    {
        if(layerdIndex === 0) {
            if(!dateTimeLevels.valideDate)
            {
                dateTimeLevels.resetDateTimeInvalid()
            }
            layerdIndex = 1
            dateTimeLevels.selectDay(false)
            dateTimeLevels.selectMonth(true)
        }
        else if(layerdIndex === 1) {
            layerdIndex = 2
            dateTimeLevels.selectMonth(false)
            dateTimeLevels.selectYear(true)
        }
        else if(layerdIndex === 2) {
            layerdIndex = 3
            dateTimeLevels.selectYear(false)
            dateTimeLevels.selectHour(true)
            pgHeader.titleString = qsTrId("LBL_0018") + translator.emptyString
        }
        else if(layerdIndex === 3) {
            layerdIndex = 4
            dateTimeLevels.selectHour(false)
            dateTimeLevels.selectMin(true)
        }
        else if(layerdIndex === 4) {
            dateTimeLevels.selectMin(false)
            dateTimeLevels.selectDay(true)
            dateTimeLevels.saveDateTime()

            if(dateTimeLevels.valideDate === true)
            {
                dateTimeLevels.validateDate()
                dateTimeLevels.validateTime()
                layerdIndex = 0

                pgHeader.visible = true
                pgHeader.mainMenu = false
                pgHeader.titleString = qsTrId("LBL_0013") + translator.emptyString
                pg_listIcon.selectDateTimeModeModel()
                pg_listIcon.visible = true
                pg_dateSelection.visible = false
                backEnd.setState(MyAppState.DS_2_DATE_TIME_SET)
                backEnd.setCurrentPage(pg_listIcon)
                pg_listIcon.selectDateTime()

                pum.addPopUp("qrc:/graphics/Popups/2.4 Setting completed pop-up.png", qsTrId("LBL_0270") + translator.emptyString, 4, 5);
            }
            else {
                layerdIndex = 0
                pgHeader.titleString = qsTrId("LBL_0017") + translator.emptyString
            }
        }
    }


    Rectangle {
        id: levelsController
        width: parent.width
        height: parent.height
        color: parent.color

        Comp_dateTime {
            id: dateTimeLevels
        }

    }
}

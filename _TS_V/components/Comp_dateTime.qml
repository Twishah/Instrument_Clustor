import QtQuick 2.0

Rectangle {
    id: dateTimeContainer

    width: parent.width
    height: parent.height
    color: parent.color

    property string amPm : "AM"

    property int totalMinutes: 0

    property bool is12HourFormat: dm.getFormatHour() === 1 ? true : false

    property bool valideDate: true


    onIs12HourFormatChanged: {
        if(is12HourFormat)
        {
            if (hourContainer.currentNumber < 12) {
                amPm = "AM";
            } else {
                hourContainer.currentNumber = hourContainer.currentNumber % 12
                amPm = "PM";
            }
        } else
        {
            if (amPm === "PM") {
                hourContainer.currentNumber = hourContainer.currentNumber % 12 + 12
            }
        }
    }

    function resetDateTimeInvalid() {
        valideDate = true
        errorText.text = ""
    }

    function saveDateTime() {
        var hour = hourContainer.currentNumber;
        if (is12HourFormat) {
            // Convert 12-hour format to 24-hour format
            if (amPm == "PM" && hour != 12) {
                hour += 12;
            } else if (amPm == "AM" && hour == 12) {
                hour = 0;
            }
        }

        var retCode = dateTimeManager.setManualDateTime(yearContainer.currentNumber,
                                          monthContainer.currentNumber,
                                          dayContainer.currentNumber,
                                          hour,
                                          minContainer.currentNumber);

        if (retCode === 0)
        {
            dm.dateTimeMode = 1;
            dm.saveDateTimeMode();

            dm.daylightSavingTime = 0;
            dateTimeManager.setDaylightSavingTime(false)

            dm.saveDaylightSavingTime();

            valideDate = true;
            errorText.text = ""
        } else {
            valideDate = false;
            errorText.text = qsTrId("LBL_0278") + translator.emptyString
        }
    }

    function selectDay(value) {
        dayContainer.isCurrent = value;
    }

    function increaseDay() {
        dayContainer.currentNumber = (dayContainer.currentNumber + 1) % 31
        if (dayContainer.currentNumber === 0) {
            dayContainer.currentNumber = 31
        }
    }

    function decreaseDay() {
        dayContainer.currentNumber = (dayContainer.currentNumber - 1 + 31) % 31
        if (dayContainer.currentNumber === 0) {
            dayContainer.currentNumber = 31
        }
    }

    function selectMonth(value) {
        monthContainer.isCurrent = value;
    }

    function increaseMonth() {
        monthContainer.currentNumber = (monthContainer.currentNumber + 1) % 12
        if (monthContainer.currentNumber === 0) {
            monthContainer.currentNumber = 12
        }
    }

    function decreaseMonth() {
        monthContainer.currentNumber = (monthContainer.currentNumber - 1 + 12) % 12
        if (monthContainer.currentNumber === 0) {
            monthContainer.currentNumber = 12
        }
    }

    function selectYear(value) {
        yearContainer.isCurrent = value;
    }

    function increaseYear() {
        var range = 99 - 20 + 1
        yearContainer.currentNumber = (yearContainer.currentNumber + (1 % range) - 20) % range + 20
    }

    function decreaseYear() {
        var range = 99 - 20 + 1
        yearContainer.currentNumber = (yearContainer.currentNumber - (1 % range) - 20  + range) % range + 20
    }

    function validateDate() {
        dayContainer.confirmValue()
        monthContainer.confirmValue()
        yearContainer.confirmValue()
    }

    function cancelDate() {
        dayContainer.cancelValue()
        monthContainer.cancelValue()
        yearContainer.cancelValue()
    }


    function selectHour(value) {
        hourContainer.isCurrent = value;
    }

    function increaseHour() {
        if(is12HourFormat)
        {
            hourContainer.currentNumber = (hourContainer.currentNumber + 1) % 12;
            if (hourContainer.currentNumber === 0) {
                hourContainer.currentNumber = 12;
            }

            if (hourContainer.currentNumber === 12 && amPm === "AM") {
                    amPm = "PM";
            } else if (hourContainer.currentNumber == 12 && amPm === "PM") {
                amPm = "AM";
            }
        } else
        {
            hourContainer.currentNumber = (hourContainer.currentNumber + 1) % 24;
        }
    }

    function decreaseHour() {
        if(is12HourFormat)
        {
            hourContainer.currentNumber = (hourContainer.currentNumber - 1 + 12) % 12;
            if (hourContainer.currentNumber === 0) {
                hourContainer.currentNumber = 12;
            }

            if (hourContainer.currentNumber === 11 && amPm === "AM") {
                    amPm = "PM";
            } else if (hourContainer.currentNumber == 11 && amPm === "PM") {
                amPm = "AM";
            }
        } else
        {
            hourContainer.currentNumber = (hourContainer.currentNumber - 1 + 24) % 24;
        }
    }

    function selectMin(value) {
        minContainer.isCurrent = value;
    }

    function increaseMin() {
        minContainer.currentNumber = (minContainer.currentNumber + 1) % 60
    }

    function decreaseMin() {
        minContainer.currentNumber = (minContainer.currentNumber - 1 + 60) % 60
    }

    function validateTime() {
        hourContainer.confirmValue();
        minContainer.confirmValue();

        totalMinutes = hourContainer.currentNumber * 60 + minContainer.currentNumber
    }

    function cancelTime() {
        hourContainer.cancelValue();
        minContainer.cancelValue();
    }

    function updateAllNumbers() {
        dayContainer.currentNumber = dateTimeManager.getDay()
        dayContainer.resultNumber = dayContainer.currentNumber
        monthContainer.currentNumber = dateTimeManager.getMonth()
        monthContainer.resultNumber = monthContainer.currentNumber
        yearContainer.currentNumber = dateTimeManager.getYear().toString().slice(-2)
        yearContainer.resultNumber = yearContainer.currentNumber
        amPm = dateTimeManager.getHour() >= 12 ? "PM" : "AM"

        if(is12HourFormat)
        {
            hourContainer.currentNumber = dateTimeManager.getHour() % 12;
            if (hourContainer.currentNumber === 0) {
                hourContainer.currentNumber = 12
            }
        } else
        {
            hourContainer.currentNumber = dateTimeManager.getHour() % 24;
        }
        hourContainer.resultNumber = hourContainer.currentNumber
        minContainer.currentNumber = dateTimeManager.getMinutes()
        minContainer.resultNumber = minContainer.currentNumber
    }

    Rectangle {
        id: dateContainer

        width: parent.width
        height: 55
        color: parent.color
        anchors {
            topMargin: 50
            top: parent.top
            horizontalCenter: parent.horizontalCenter
        }

        Comp_boxNumber {
            id: dayContainer
            height: 37
            width: 0.165 * parent.width
            fontPxSize: 24
            anchors {
                rightMargin: 10
                right: separatorText1.left
                verticalCenter: parent.verticalCenter
            }
            isArrows: true
            isCurrent: true
            currentNumber: dateTimeManager.getDay()
            resultNumber: dateTimeManager.getDay()
        }

        Text {
            id: separatorText1
            text: "/"
            color: color_white
            font.pixelSize: 30
            font.family: systemFont
            anchors {
                rightMargin: 10
                right: monthContainer.left
                verticalCenter: dayContainer.verticalCenter
            }
        }

        Comp_boxNumber {
            id: monthContainer
            height: 37
            width: 0.165 * parent.width
            fontPxSize: 24
            anchors {
                rightMargin: 20
                right: separatorText2.right
                verticalCenter: parent.verticalCenter
            }
            isArrows: true
            currentNumber: dateTimeManager.getMonth()
            resultNumber: dateTimeManager.getMonth()
        }

        Text {
            id: separatorText2
            text: "/"
            color: color_white
            font.pixelSize: 30
            font.family: systemFont
            anchors {
                rightMargin: 8
                right: yearText.left
                verticalCenter: dayContainer.verticalCenter
            }
        }

        Text {
            id: yearText
            text: "20"
            color: color_white
            font.pixelSize: 24
            font.family: systemFont
            anchors {
                rightMargin: 5
                right: yearContainer.left
                verticalCenter: parent.verticalCenter
            }
        }

        Comp_boxNumber {
            id: yearContainer
            height: 37
            width: 0.165 * parent.width
            fontPxSize: 24
            anchors {
                rightMargin: 20
                right: dateContainer.right
                verticalCenter: parent.verticalCenter
            }
            isArrows: true
            currentNumber: dateTimeManager.getYear().toString().slice(-2)
            resultNumber: dateTimeManager.getYear().toString().slice(-2)
        }
    }

    Rectangle {
        id: timeContainer

        width: parent.width
        height: 55
        color: parent.color
        anchors {
            bottomMargin: 45
            bottom: parent.bottom
            horizontalCenter: parent.horizontalCenter
        }

        Text {
            id: hourFormatText
            text: is12HourFormat ? amPm : ""
            color: color_white
            font.pixelSize: 24
            font.family: systemFont
            anchors {
                rightMargin: 35
                right: hourContainer.left
                verticalCenter: parent.verticalCenter
            }
        }

        Comp_boxNumber {
            id: hourContainer
            height: 37
            width: 0.165 * parent.width
            fontPxSize: 24
            anchors {
                rightMargin: 10
                right: separatorText.left
                verticalCenter: parent.verticalCenter
            }
            isArrows: true
            currentNumber: dateTimeManager.getHour()
            resultNumber: dateTimeManager.getHour()
        }

        Text {
            id: separatorText
            text: ":"
            color: color_white
            font.pixelSize: 30
            font.family: systemFont
            anchors {
                rightMargin: 10
                right: minContainer.left
                verticalCenter: hourContainer.verticalCenter
            }
        }

        Comp_boxNumber {
            id: minContainer
            height: 37
            width: 0.165 * parent.width
            fontPxSize: 24
            anchors {
                rightMargin: 20
                right: timeContainer.right
                verticalCenter: parent.verticalCenter
            }
            isArrows: true
            currentNumber: dateTimeManager.getMinutes()
            resultNumber: dateTimeManager.getMinutes()
        }

        Text {
                id: errorText
                text: ""
                color: color_red
                font.pixelSize: 16
                anchors {
                    top: hourContainer.bottom
                    topMargin: 10
                    horizontalCenter: parent.horizontalCenter
                }
        }
    }
}

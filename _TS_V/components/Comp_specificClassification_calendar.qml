import QtQuick 2.6
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.4
import Qt.labs.calendar 1.0
import "../pages"

Rectangle {
    id: calendarContainer

    // DYNAMIC: regarding the next page (day setting)
    property var states: [true, false, false, false, false, false, false]
    property date dateToShow: new Date()

    property int currentDay: dateToShow.getUTCDate(); // day of the month (1 - 31)
    property int currentWeekDay: ((dateToShow.getUTCDay() + 6) % 7); // getDay() returns Sunday (0) as the first day of week, but we want Monday - Sunday : 0 - 6
    property int currentMonth: dateToShow.getUTCMonth() // january is 0
    property int currentYear: dateToShow.getUTCFullYear() // e.g.: 2023
    property date firstDateCurrentMonth: new Date(currentYear + '-' + String(currentMonth+1).padStart(2, '0') + '-01')
    property int daysInMonth: new Date(currentYear, currentMonth + 1, 0).getDate() // day 0 is the last day of previous month
    property date lastDateCurrentMonth: new Date(currentYear + '-' + String(currentMonth+2).padStart(2, '0') + '-00')
    property int firstDayOfMonth: ((firstDateCurrentMonth.getDay() + 5) % 7); // Monday - Sunday : 0 - 6

    property int calendarDayWidth: 29 // width of one calendar cell
    property int calendarDayHeight: 22 // height of one calendar cell

    property int highlightedIndex: 0 // index of the cell which must be highlighted in blue

    //property var workloadDayTab: [ 0.5, 1.2, 2.0, 3.0, 4.0, 5.0, 8.0, 9.0, 0, 0, 9, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1.0]
    property var workloadDayTab: [ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    property var workloadAmTab: [ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    property var workloadPmTab: [ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    property var workload90DaysTab_comp: [{ date: new Date(), amHours: 0, pmHours: 0, dailyHours: 0}] // all daily workloads with dates
    property double workloadHighlightedWeek: 0.0
    property double workloadDisplayedMonth: 0.0

    width: parent.width
    height: 96
    color: parent.color

    onVisibleChanged:
    {
        updateDisplayedWorkload()
        computeWorkloadWeek()
    }

    onCurrentMonthChanged:
    {
        currentYear = dateToShow.getUTCFullYear() // e.g.: 2023
        firstDateCurrentMonth = new Date(currentYear + '-' + String(currentMonth+1).padStart(2, '0') + '-01')
        daysInMonth = new Date(currentYear, currentMonth + 1, 0).getDate() // day 0 is the last day of previous month
        lastDateCurrentMonth = new Date(currentYear + '-' + String(currentMonth+2).padStart(2, '0') + '-00')
        firstDayOfMonth = ((firstDateCurrentMonth.getDay() + 5) % 7); // Monday - Sunday : 0 - 6

//        console.log("currentDay : " + currentDay)
//        console.log("currentMonth : " + currentMonth)
//        console.log("currentYear : " + currentYear)
//        console.log("daysInMonth : " + daysInMonth)
//        console.log("firstDateCurrentMonth : " + firstDateCurrentMonth)
//        console.log("lastDateCurrentMonth : " + lastDateCurrentMonth)
//        console.log("firstDayOfMonth : " + firstDayOfMonth)

        updateDisplayedWorkload()
    }

    function getMonday(d) {
      var dTemp = new Date(d);
      var day = dTemp.getUTCDay(),
          diff = dTemp.getUTCDate() - day + (day === 0 ? -6:1); // adjust when day is sunday
      return new Date(dTemp.setUTCDate(diff));
    }

    // Compute the total workload for the highlighted week (could be covering different months)
    function computeWorkloadWeek()
    {
        workloadHighlightedWeek = 0.0

        var mondayDate = getMonday(dateToShow)
        mondayDate.setUTCHours(0)
        mondayDate.setUTCMinutes(0)
        mondayDate.setUTCSeconds(0)
        mondayDate.setUTCMilliseconds(0)

        for (var i_dayInWeek = 0; i_dayInWeek < 7; i_dayInWeek++)
        {
            var weekdayDate = new Date(mondayDate);
            weekdayDate.setUTCDate(mondayDate.getUTCDate() + i_dayInWeek)


            if((weekdayDate >= workload90DaysTab_comp[0].date) && (weekdayDate <= workload90DaysTab_comp[workload90DaysTab_comp.length - 1].date))
            {
                for (var j = 0; j < workload90DaysTab_comp.length; j++) // loop over values in workload90DaysTab_comp
                {
                    if(     (weekdayDate.getUTCFullYear() === workload90DaysTab_comp[j].date.getUTCFullYear())
                       &&   (weekdayDate.getUTCMonth() === workload90DaysTab_comp[j].date.getUTCMonth())
                       &&   (weekdayDate.getUTCDate() === workload90DaysTab_comp[j].date.getUTCDate()))
                    {
                        workloadHighlightedWeek += parseFloat(workload90DaysTab_comp[j].dailyHours)
                    }
                }
            }
        }
    }

    // this function updates workloadTabDisplayedMonth according to the month that is displayed in the calendar
    function updateDisplayedWorkload()
    {
        if(dateRows.visible)
        {
            for (var i_grid = 0; i_grid < dateRows.model ; i_grid++) // loop over the grid in the displayed month to reset all dots to transparent
            {
                dateRows.itemAt(i_grid).dotColor0to2H = "transparent"
                dateRows.itemAt(i_grid).dotColor2to4H = "transparent"
                dateRows.itemAt(i_grid).dotColor4to8H = "transparent"
                dateRows.itemAt(i_grid).dotColorOver8H = "transparent"
            }
        }

        workloadDisplayedMonth = 0

        //console.log("workload90DaysTab_comp[workload90DaysTab_comp.length - 1].date : " + workload90DaysTab_comp[workload90DaysTab_comp.length - 1].date)
        //console.log("workload90DaysTab_comp[0].date : " + workload90DaysTab_comp[0].date)
        for (var i = 0; i < daysInMonth; i++) // loop over days in the displayed month
        {
            var dateTemp = new Date(currentYear + '-' + String(currentMonth+1).padStart(2, '0') + '-' + String(i+1).padStart(2, '0'))
            if((dateTemp >= workload90DaysTab_comp[0].date) && (dateTemp <= workload90DaysTab_comp[workload90DaysTab_comp.length - 1].date))
            {
                //console.log("Valid date : " + dateTemp)
                for (var j = 0; j < workload90DaysTab_comp.length; j++) // loop over values in workload90DaysTab_comp
                {
                    if(     (dateTemp.getUTCFullYear() === workload90DaysTab_comp[j].date.getUTCFullYear())
                       &&   (dateTemp.getUTCMonth() === workload90DaysTab_comp[j].date.getUTCMonth())
                       &&   (dateTemp.getUTCDate() === workload90DaysTab_comp[j].date.getUTCDate()))
                    {
//                        console.log("dateTemp : " + dateTemp.getUTCFullYear() + "/" + (dateTemp.getUTCMonth()+1) + "/" + dateTemp.getUTCDate() + " - workload90DaysTab_comp[j].date : " + workload90DaysTab_comp[j].date.getUTCFullYear() + "/" + (workload90DaysTab_comp[j].date.getUTCMonth()+1) + "/" + workload90DaysTab_comp[j].date.getUTCDate())
//                        console.log("i = " + i + ", j = " + j)
//                        console.log("workload90DaysTab_comp[j].dailyHours = " + workload90DaysTab_comp[j].dailyHours)
                        workloadDayTab[i] = workload90DaysTab_comp[j].dailyHours
                        workloadAmTab[i] = workload90DaysTab_comp[j].amHours
                        workloadPmTab[i] = workload90DaysTab_comp[j].pmHours
                        workloadDisplayedMonth += parseFloat(workloadDayTab[i])
                        break
                    }
                    else
                    {
                        workloadDayTab[i] = 0
                        workloadAmTab[i] = 0
                        workloadPmTab[i] = 0
                    }
                }

                //var index = workload90DaysTab_comp.map(function(e) { return e.date; }).indexOf(dateTemp)

            }
            else
            {
                workloadDayTab[i] = 0
                workloadAmTab[i] = 0
                workloadPmTab[i] = 0
            }

            var repeaterIndex = i + firstDayOfMonth // index of the day rectangle

            if(dateRows.visible) // only try to update if the repeater's items are visible
            {

                // 4 dots existence
                var dot1 = false
                var dot2 = false
                var dot3 = false
                var dot4 = false

                if(workloadDayTab[repeaterIndex - firstDayOfMonth]>8.0)
                {
                    // display 4 dots
                    dot1 = true
                    dot2 = true
                    dot3 = true
                    dot4 = true

                    // center them under the day number
                    dateRows.itemAt(repeaterIndex).dot1LeftMargin = 4
                }
                else if(workloadDayTab[repeaterIndex - firstDayOfMonth]>4.0)
                {
                    // display 3 dots
                    dot1 = true
                    dot2 = true
                    dot3 = true

                    // center them under the day number
                    dateRows.itemAt(repeaterIndex).dot1LeftMargin = 7
                }
                else if(workloadDayTab[repeaterIndex - firstDayOfMonth]>2.0)
                {
                    // display 2 dots
                    dot1 = true
                    dot2 = true

                    // center them under the day number
                    dateRows.itemAt(repeaterIndex).dot1LeftMargin = 10
                }
                else if(workloadDayTab[repeaterIndex - firstDayOfMonth]>0.5)
                {
                    // display 1 dot
                    dot1 = true

                    // center it under the day number
                    dateRows.itemAt(repeaterIndex).dot1LeftMargin = 13
                }

                dateRows.itemAt(repeaterIndex).dotColor0to2H = dot1 ? color_white : "transparent"
                dateRows.itemAt(repeaterIndex).dotColor2to4H = dot2 ? color_white : "transparent"
                dateRows.itemAt(repeaterIndex).dotColor4to8H = dot3 ? color_white : "transparent"
                dateRows.itemAt(repeaterIndex).dotColorOver8H = dot4 ? color_white : "transparent"

            }

        }

//        for (j = 0; j < workloadDayTab.length; j++)
//        {
//            console.log("workloadDayTab[" + j + "] = " + workloadDayTab[j])
//        }

    }

    function shownDateIsDateToShow(index)
    {
        if((index + 1 - firstDayOfMonth) == dateToShow.getUTCDate())
        {
            // this is the cell which has to be highlighted
            highlightedIndex = index
            return true
        }
        else
        {
            return false
        }
    }





    GridLayout {
           id: grid
           columns: 7
           rows: 2
           columnSpacing: 1
           rowSpacing: 1
           width: 216
           anchors {
                horizontalCenter: parent.horizontalCenter
                top: parent.top
                topMargin: 5
                bottom: parent.bottom
                bottomMargin: 14
            }

            // models
            property var titles: [ qsTrId("LBL_0043") + translator.emptyString, qsTrId("LBL_0044") + translator.emptyString, qsTrId("LBL_0045") + translator.emptyString,
               qsTrId("LBL_0046") + translator.emptyString, qsTrId("LBL_0047") + translator.emptyString, qsTrId("LBL_0048") + translator.emptyString, qsTrId("LBL_0049") + translator.emptyString ]
            property var colors: [ color_white, color_white, color_white, color_white, color_white, color_blue, color_red ]

           // Weekdays : Mon, Tue, ...
           Repeater {
               id: row0
               model: grid.titles
               Label {
                   Layout.row: 0
                   Layout.column: index
                   Layout.fillWidth: true
                   Layout.fillHeight: false
                   text: modelData
                   font.pixelSize: 10
                   color: grid.colors[index]
                   horizontalAlignment: Text.AlignHCenter
               }
           }


           // Date : 1, 2, 3, ...
           Repeater {

               id: dateRows
               property alias repeat: dateRows
               model: 42 // 7 days * 6 lines

               Rectangle {
                   id: dayRect
                   property alias repeatDay: dayRect
                   width: calendarDayWidth
                   height: calendarDayHeight
                   color: shownDateIsDateToShow(index) ? color_blue : color_gray_bar // highlight the user selected cell

                   property string dotColor0to2H: "transparent"
                   property string dotColor2to4H: "transparent"
                   property string dotColor4to8H: "transparent"
                   property string dotColorOver8H: "transparent"

                   property int dot1LeftMargin: 5

                   Text {
                       id: dayText
                       property alias repeatDayText: dayText
                       text: ((index>=firstDayOfMonth) && ((index + 1 - firstDayOfMonth)<=daysInMonth)) ? (index + 1 - firstDayOfMonth) : ""
                       color: color_white
                       font.pixelSize: 16
                       anchors.centerIn: parent
                   }

                   Rectangle {
                       id: workload02Rec
                       property alias workload02: workload02Rec
                       width: 3
                       height: 3
                       anchors {
                            left: parent.left
                            leftMargin: dayRect.dot1LeftMargin
                            bottom: parent.bottom
                            bottomMargin: 1
                       }
                       color: dayRect.dotColor0to2H
                       //color: ((index>=firstDayOfMonth) && ((index + 1 - firstDayOfMonth)<=daysInMonth) && workloadDayTab[index - firstDayOfMonth]>0.5) ? color_white : "transparent"
                   }

                   Rectangle {
                       id: workload24Rec
                       width: 3
                       height: 3
                       anchors {
                            left: workload02Rec.right//parent.left
                            leftMargin: 3 //11
                            bottom: parent.bottom
                            bottomMargin: 1
                       }
                       color : dayRect.dotColor2to4H
                       //color: ((index>=firstDayOfMonth) && ((index + 1 - firstDayOfMonth)<=daysInMonth) && workloadDayTab[index - firstDayOfMonth]>2.0) ? color_white : "transparent"
                   }

                   Rectangle {
                       id: workload48Rec
                       width: 3
                       height: 3
                       anchors {
                            left: workload24Rec.right//parent.left
                            leftMargin: 3//17
                            bottom: parent.bottom
                            bottomMargin: 1
                       }
                       color : dayRect.dotColor4to8H
                       //color: ((index>=firstDayOfMonth) && ((index + 1 - firstDayOfMonth)<=daysInMonth) && workloadDayTab[index - firstDayOfMonth]>4.0) ? color_white : "transparent"
                   }

                   Rectangle {
                       id: workload8Rec
                       width: 3
                       height: 3
                       anchors {
                            left: workload48Rec.right//parent.left
                            leftMargin: 3//23
                            bottom: parent.bottom
                            bottomMargin: 1
                       }
                       color : dayRect.dotColorOver8H
                       //color: ((index>=firstDayOfMonth) && ((index + 1 - firstDayOfMonth)<=daysInMonth) && workloadDayTab[index - firstDayOfMonth]>=8.0) ? color_white : "transparent"
                   }
               }
           }
       }

    // Week highlight : transparent rectangle with blue border, its location follows the rox of the highlighted cell
    Rectangle {
        onYChanged: {computeWorkloadWeek()}

        id: weekHighlightRec
        width: grid.width + 2 // + 2 because of the border
        height: calendarDayHeight + 2 // + 2 because of the border
        // Math.floor(highlightedIndex/7) is the row number of the highlight date
        // offset : 17 on simulated display, 18 on real display
        y: 18 + Math.floor(highlightedIndex/7)*(calendarDayHeight + grid.rowSpacing)
        anchors {
             horizontalCenter: parent.horizontalCenter
        }
        color: "transparent"
        border {
            color: color_blue
            width: 2
        }
    }
}

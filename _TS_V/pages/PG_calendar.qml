import QtQuick 2.0
import MyQmlModule 1.0
import QtGraphicalEffects 1.0
import QtQuick.LocalStorage 2.0 as Sql
import "../components"

Item {
    id: calendarID
    height: 320
    width: 240
    anchors.topMargin: backEnd.currentConfig.headerHeight

    property date currentDate: dateTimeManager.dateTime//new Date()
    property date dateToShow: new Date()
    property int currentMonth: currentDate.getUTCMonth()
    property int currentYear: currentDate.getUTCFullYear()
    property real morningHours: 0
    property real afternoonHours: 0
    property real currentDayOperationHours: dataEngine.opHours_DailyWorkload.value > 24.0 || dataEngine.opHours_DailyWorkload.value < 0.0 ? 0.0 : dataEngine.opHours_DailyWorkload.value
    property bool dateToShowIsToday: true
    property color rectBorderColor: color_gray
    property var db
    property bool sqlDbOpened: false
    property string dbName: "CalendarHoursDB"
    property date lastDbModifDate: new Date()
    property var workload90DaysTab: [{ date: new Date(), amHours: 0, pmHours: 0, dailyHours: 0}] // contains the daily worked hours over the last 90 days, last value is current day

    // Reset to default properties when accessing the page
    onVisibleChanged: resetCalendarProperties()

    onCurrentDateChanged:
    {
        console.log("   DATE    CHANGED : " + currentDate)

        if(dateTimeManager.getManualMode() === true)
        {
            // if manual mode, shift all dates in the db by the amount (currentDate - (sql db's last row date))
            shiftDataBase()
        }
        else
        {
            // if auto mode

            if(sqlDbOpened)
            {
                // Retrieve last row
                var rsLastRow
                db.transaction(function(tx) {

                    // Retrieve last row
                    rsLastRow = tx.executeSql('SELECT * FROM calendarHours WHERE id=(SELECT max(id) FROM calendarHours)');

                });


                console.log("DATE LAST SQL ROW : " + rsLastRow.rows.item(0).date)

                var lastDate = new Date(rsLastRow.rows.item(0).date)
                lastDate.setUTCHours(0)
                lastDate.setUTCMinutes(0)
                lastDate.setUTCSeconds(0)
                lastDate.setUTCMilliseconds(0)

                var currentDate0h0m0s = new Date(currentDate)
                currentDate0h0m0s.setUTCHours(0)
                currentDate0h0m0s.setUTCMinutes(0)
                currentDate0h0m0s.setUTCSeconds(0)
                currentDate0h0m0s.setUTCMilliseconds(0)

                //console.log("DIFF DATE : " + Math.abs(lastDate - currentDate0h0m0s))

                if(currentDate0h0m0s > lastDate)
                {
                    console.log("Create new entry")
                    // if MCU date is in the future : add a new row in the db
                    dbAddDailyHours(currentDate, isAM(), currentDayOperationHours)
                    // Update workload90DaysTab according to the sql db
                    db.transaction(function(tx) {

                        // Retrieve last row
                        var rsLastRow = tx.executeSql('SELECT * FROM calendarHours WHERE id=(SELECT max(id) FROM calendarHours)')

                        workload90DaysTab.push({date: new Date(rsLastRow.rows.item(0).date),
                                                amHours: rsLastRow.rows.item(0).amHours.toFixed(1),
                                                pmHours: rsLastRow.rows.item(0).pmHours.toFixed(1),
                                                dailyHours: (rsLastRow.rows.item(0).amHours + rsLastRow.rows.item(0).pmHours).toFixed(1)})
                    });

                    // keep only the last 90 days
                    truncateDB()

                    dbPrint()

                    // Update the calendar grid component
                    dateLevel.workload90DaysTab_comp = workload90DaysTab
                    dateLevel.updateDisplayedWorkload()
                    dateLevel.computeWorkloadWeek()

                }
                else if(Math.abs(lastDate - currentDate0h0m0s) == 0)
                {
                    morningHours = rsLastRow.rows.item(0).amHours
                    afternoonHours = rsLastRow.rows.item(0).pmHours
                    // someone already worked on the machine today
                    // -> update the last row
                    console.log("Update last entry")
                    dbUpdateDailyHours(isAM(), currentDayOperationHours) // update the sql db

                    // Update workload90DaysTab according to the sql db
                    db.transaction(function(tx) {

                        // Retrieve last row
                        var rsLastRow = tx.executeSql('SELECT * FROM calendarHours WHERE id=(SELECT max(id) FROM calendarHours)')

                        workload90DaysTab[workload90DaysTab.length-1].amHours = rsLastRow.rows.item(0).amHours.toFixed(1)
                        workload90DaysTab[workload90DaysTab.length-1].pmHours = rsLastRow.rows.item(0).pmHours.toFixed(1)
                        workload90DaysTab[workload90DaysTab.length-1].dailyHours = (rsLastRow.rows.item(0).amHours + rsLastRow.rows.item(0).pmHours).toFixed(1)

                    });

                    // keep only the last 90 days
                    truncateDB()

                    dbPrint()

                    // Update the calendar grid component
                    dateLevel.workload90DaysTab_comp = workload90DaysTab
                    dateLevel.updateDisplayedWorkload()
                    dateLevel.computeWorkloadWeek()
                }
                else
                {
                    // if MCU date is in the past : shift db
                    shiftDataBase()
                }
            }
        }
    }

    onCurrentDayOperationHoursChanged:
    {
        console.log("   CAN VALUE CHANGED : " + currentDayOperationHours)
        dbUpdateDailyHours(isAM(), currentDayOperationHours)

        // Update workload90DaysTab
        db.transaction(function(tx) {

            // Retrieve last row
            var rsLastRow = tx.executeSql('SELECT * FROM calendarHours WHERE id=(SELECT max(id) FROM calendarHours)')

            workload90DaysTab[workload90DaysTab.length-1].amHours = rsLastRow.rows.item(0).amHours.toFixed(1)
            workload90DaysTab[workload90DaysTab.length-1].pmHours = rsLastRow.rows.item(0).pmHours.toFixed(1)
            workload90DaysTab[workload90DaysTab.length-1].dailyHours = (rsLastRow.rows.item(0).amHours + rsLastRow.rows.item(0).pmHours).toFixed(1)

        });

        dbPrint()

        // Update the calendar grid component
        dateLevel.workload90DaysTab_comp = workload90DaysTab
        dateLevel.updateDisplayedWorkload()
        dateLevel.computeWorkloadWeek()
        calendarTotalHoursNum.text = Number(dateLevel.workloadDayTab[dateLevel.currentDay-1]).toFixed(1) + "h"
    }

    Component.onCompleted: {
        // The .sqlite file is stored in /home/root/.local/share/fmc_hmi/QML/OfflineStorage/Databases
        // and its name is the md5 hash of dbName
        db = Sql.LocalStorage.openDatabaseSync(dbName, "1.0", "Daily Hours worked on the excavator", 100000, db);

        console.log("CALENDAR COMPLETED")

        if(!db)
        {
            return
        }
        else
        {
            sqlDbOpened = true
        }
//        //console.log("DB NAME HASH : " + md5(dbName))
//        var getLastModifCmd = "date -r /home/root/.local/share/fmc_hmi/QML/OfflineStorage/Databases/" + md5(dbName) + ".sqlite -u +\"%Y-%m-%d\""
//        //console.log("command : " + getLastModifCmd.toString())
//        var cmdOutput = RunProcess.launch(getLastModifCmd.toString())
//        console.log("Last modified date : " + cmdOutput)

//        lastDbModifDate = new Date(cmdOutput.toString().substring(0, 10)) // get only the first 10 chars (yyyy-mm-dd) because there is an escape char at the end
//        console.log("lastDbModifDate : " + lastDbModifDate)

        // Init processing of the db
        dbInit();

        // keep only the last 90 days
        truncateDB()

        dateLevel.workload90DaysTab_comp = workload90DaysTab
    }

//    Timer {
//        id: readCANvalues
//        running: true
//        interval: 1000
//        repeat: true // repeat every 1s
//        onTriggered: {

//            isAM()
//        }
//     }

//    function md5(inputString) {
//        var hc="0123456789abcdef";
//        function rh(n) {var j,s="";for(j=0;j<=3;j++) s+=hc.charAt((n>>(j*8+4))&0x0F)+hc.charAt((n>>(j*8))&0x0F);return s;}
//        function ad(x,y) {var l=(x&0xFFFF)+(y&0xFFFF);var m=(x>>16)+(y>>16)+(l>>16);return (m<<16)|(l&0xFFFF);}
//        function rl(n,c)            {return (n<<c)|(n>>>(32-c));}
//        function cm(q,a,b,x,s,t)    {return ad(rl(ad(ad(a,q),ad(x,t)),s),b);}
//        function ff(a,b,c,d,x,s,t)  {return cm((b&c)|((~b)&d),a,b,x,s,t);}
//        function gg(a,b,c,d,x,s,t)  {return cm((b&d)|(c&(~d)),a,b,x,s,t);}
//        function hh(a,b,c,d,x,s,t)  {return cm(b^c^d,a,b,x,s,t);}
//        function ii(a,b,c,d,x,s,t)  {return cm(c^(b|(~d)),a,b,x,s,t);}
//        function sb(x) {
//            var i;var nblk=((x.length+8)>>6)+1;var blks=new Array(nblk*16);for(i=0;i<nblk*16;i++) blks[i]=0;
//            for(i=0;i<x.length;i++) blks[i>>2]|=x.charCodeAt(i)<<((i%4)*8);
//            blks[i>>2]|=0x80<<((i%4)*8);blks[nblk*16-2]=x.length*8;return blks;
//        }
//        var i,x=sb(""+inputString),a=1732584193,b=-271733879,c=-1732584194,d=271733878,olda,oldb,oldc,oldd;
//        for(i=0;i<x.length;i+=16) {olda=a;oldb=b;oldc=c;oldd=d;
//            a=ff(a,b,c,d,x[i+ 0], 7, -680876936);d=ff(d,a,b,c,x[i+ 1],12, -389564586);c=ff(c,d,a,b,x[i+ 2],17,  606105819);
//            b=ff(b,c,d,a,x[i+ 3],22,-1044525330);a=ff(a,b,c,d,x[i+ 4], 7, -176418897);d=ff(d,a,b,c,x[i+ 5],12, 1200080426);
//            c=ff(c,d,a,b,x[i+ 6],17,-1473231341);b=ff(b,c,d,a,x[i+ 7],22,  -45705983);a=ff(a,b,c,d,x[i+ 8], 7, 1770035416);
//            d=ff(d,a,b,c,x[i+ 9],12,-1958414417);c=ff(c,d,a,b,x[i+10],17,     -42063);b=ff(b,c,d,a,x[i+11],22,-1990404162);
//            a=ff(a,b,c,d,x[i+12], 7, 1804603682);d=ff(d,a,b,c,x[i+13],12,  -40341101);c=ff(c,d,a,b,x[i+14],17,-1502002290);
//            b=ff(b,c,d,a,x[i+15],22, 1236535329);a=gg(a,b,c,d,x[i+ 1], 5, -165796510);d=gg(d,a,b,c,x[i+ 6], 9,-1069501632);
//            c=gg(c,d,a,b,x[i+11],14,  643717713);b=gg(b,c,d,a,x[i+ 0],20, -373897302);a=gg(a,b,c,d,x[i+ 5], 5, -701558691);
//            d=gg(d,a,b,c,x[i+10], 9,   38016083);c=gg(c,d,a,b,x[i+15],14, -660478335);b=gg(b,c,d,a,x[i+ 4],20, -405537848);
//            a=gg(a,b,c,d,x[i+ 9], 5,  568446438);d=gg(d,a,b,c,x[i+14], 9,-1019803690);c=gg(c,d,a,b,x[i+ 3],14, -187363961);
//            b=gg(b,c,d,a,x[i+ 8],20, 1163531501);a=gg(a,b,c,d,x[i+13], 5,-1444681467);d=gg(d,a,b,c,x[i+ 2], 9,  -51403784);
//            c=gg(c,d,a,b,x[i+ 7],14, 1735328473);b=gg(b,c,d,a,x[i+12],20,-1926607734);a=hh(a,b,c,d,x[i+ 5], 4,    -378558);
//            d=hh(d,a,b,c,x[i+ 8],11,-2022574463);c=hh(c,d,a,b,x[i+11],16, 1839030562);b=hh(b,c,d,a,x[i+14],23,  -35309556);
//            a=hh(a,b,c,d,x[i+ 1], 4,-1530992060);d=hh(d,a,b,c,x[i+ 4],11, 1272893353);c=hh(c,d,a,b,x[i+ 7],16, -155497632);
//            b=hh(b,c,d,a,x[i+10],23,-1094730640);a=hh(a,b,c,d,x[i+13], 4,  681279174);d=hh(d,a,b,c,x[i+ 0],11, -358537222);
//            c=hh(c,d,a,b,x[i+ 3],16, -722521979);b=hh(b,c,d,a,x[i+ 6],23,   76029189);a=hh(a,b,c,d,x[i+ 9], 4, -640364487);
//            d=hh(d,a,b,c,x[i+12],11, -421815835);c=hh(c,d,a,b,x[i+15],16,  530742520);b=hh(b,c,d,a,x[i+ 2],23, -995338651);
//            a=ii(a,b,c,d,x[i+ 0], 6, -198630844);d=ii(d,a,b,c,x[i+ 7],10, 1126891415);c=ii(c,d,a,b,x[i+14],15,-1416354905);
//            b=ii(b,c,d,a,x[i+ 5],21,  -57434055);a=ii(a,b,c,d,x[i+12], 6, 1700485571);d=ii(d,a,b,c,x[i+ 3],10,-1894986606);
//            c=ii(c,d,a,b,x[i+10],15,   -1051523);b=ii(b,c,d,a,x[i+ 1],21,-2054922799);a=ii(a,b,c,d,x[i+ 8], 6, 1873313359);
//            d=ii(d,a,b,c,x[i+15],10,  -30611744);c=ii(c,d,a,b,x[i+ 6],15,-1560198380);b=ii(b,c,d,a,x[i+13],21, 1309151649);
//            a=ii(a,b,c,d,x[i+ 4], 6, -145523070);d=ii(d,a,b,c,x[i+11],10,-1120210379);c=ii(c,d,a,b,x[i+ 2],15,  718787259);
//            b=ii(b,c,d,a,x[i+ 9],21, -343485551);a=ad(a,olda);b=ad(b,oldb);c=ad(c,oldc);d=ad(d,oldd);
//        }
//        return rh(a)+rh(b)+rh(c)+rh(d);
//    }

    function resetDB()
    {
        // delete all rows and reset the autoincrement ID
        db.transaction(function(tx) {

            var dummy = tx.executeSql('DELETE FROM calendarHours'); // delete all rows
            dummy = tx.executeSql('DELETE FROM sqlite_sequence WHERE name=?', "calendarHours"); // reset the autoincrement id

        })

        workload90DaysTab = [{ date: new Date(), amHours: 0, pmHours: 0, dailyHours: 0}]

        // reinit
        dbInit()

        // Update the calendar grid component
        dateLevel.workload90DaysTab_comp = workload90DaysTab
        dateLevel.updateDisplayedWorkload()
        dateLevel.computeWorkloadWeek()
    }

    function truncateDB()
    {
        if(sqlDbOpened)
        {
            console.log("TRUNCATING DB")
            var diffTime = workload90DaysTab[workload90DaysTab.length - 1].date - workload90DaysTab[0].date // difference in ms
            var diffDays = Math.floor(diffTime / (1000 * 60 * 60 * 24)) // difference in days

            // truncate workload90DaysTab
            if(diffDays > 90) // if the db covers more than 90 days
            {
                while(diffDays > 90)
                {
                    workload90DaysTab.shift() // remove first element

                    // update diffDays
                    diffTime = workload90DaysTab[workload90DaysTab.length - 1].date - workload90DaysTab[0].date // difference in ms
                    diffDays = Math.floor(diffTime / (1000 * 60 * 60 * 24)) // difference in days
                }
            }

            // truncate the sql db
            db.transaction(function(tx) {

                // first, we truncate the db (delete all rows and reset the autoincrement ID)
                var dummy = tx.executeSql('DELETE FROM calendarHours'); // delete all rows
                dummy = tx.executeSql('DELETE FROM sqlite_sequence WHERE name=?', "calendarHours"); // reset the autoincrement id

                // Then we recreate the sql table based on workload90DaysTab
                for (var i = 0; i < workload90DaysTab.length; i++)
                {
                    // Format today's date yyyy-mm-dd
                    var dateStr = workload90DaysTab[i].date.getUTCFullYear() + '-' + String(workload90DaysTab[i].date.getUTCMonth()+1).padStart(2, '0') + '-' + String(workload90DaysTab[i].date.getUTCDate()).padStart(2, '0')
                    // Then insert into the sql db
                    dummy = tx.executeSql('INSERT INTO calendarHours (date, amHours, pmHours) VALUES(?,?,?);', [dateStr, workload90DaysTab[i].amHours, workload90DaysTab[i].pmHours]);
                }

            });
        }
    }

    function shiftDataBase ()
    {
        if(sqlDbOpened === true)
        {
            var diffTime = currentDate - workload90DaysTab[workload90DaysTab.length - 1].date // difference in ms
            var diffDays = Math.floor(diffTime / (1000 * 60 * 60 * 24)) // difference in days

            for (var i = 0; i < workload90DaysTab.length; i++) {
                var d = new Date(workload90DaysTab[i].date)
                d.setUTCDate(workload90DaysTab[i].date.getUTCDate() + diffDays)
                console.log(d)
                workload90DaysTab[i].date = d
            }

            db.transaction(function(tx) {

                // First, get the number of rows in the table, it will be accessible in dbLength.rows.item(0).cnt
                var dbLength = tx.executeSql('SELECT COUNT(*) AS cnt FROM calendarHours');
                //console.log("dblength : " + dbLength.rows.item(0).cnt)

                for (var i = 0; i < dbLength.rows.item(0).cnt; i++)
                {
                    // Format today's date yyyy-mm-dd
                    var dateStr = workload90DaysTab[i].date.getUTCFullYear() + '-' + String(workload90DaysTab[i].date.getUTCMonth()+1).padStart(2, '0') + '-' + String(workload90DaysTab[i].date.getUTCDate()).padStart(2, '0')
                    // Then update the dates in the sql db
                    tx.executeSql('UPDATE calendarHours SET date=? WHERE id=?', [dateStr, i+1]);
                }

            });
        }

        // keep only the last 90 days
        truncateDB()

        // Set global properties
        calendarID.morningHours = workload90DaysTab[workload90DaysTab.length - 1].amHours
        calendarID.afternoonHours = workload90DaysTab[workload90DaysTab.length - 1].pmHours
        calendarID.dateToShow = currentDate
        dateToShowIsToday = true

        // Update the calendar grid component
        dateLevel.workload90DaysTab_comp = workload90DaysTab
        dateLevel.updateDisplayedWorkload()
        dateLevel.computeWorkloadWeek()
    }

    // This funcions processes the sql db at application initialization
    // If the db does not exist : create it
    // if it is empty : add the first entry
    // else if the date of the last entry precedes the current date, add a new entry
    function dbInit() {
        var shiftDbAtInit = false

        console.log("DB INIT")

        db.transaction(function(tx) {
            tx.executeSql("CREATE TABLE IF NOT EXISTS calendarHours(id INTEGER PRIMARY KEY AUTOINCREMENT, date TEXT, amHours REAL, pmHours REAL);");


            // Get the number of rows in the table, it will be accessible in dbLength.rows.item(0).cnt
            var dbLength = tx.executeSql('SELECT COUNT(*) AS cnt FROM calendarHours');

//            var d = new Date()
//            d.setUTCDate(currentDate.getUTCDate() - 7)
//            console.log(d)
//            var res = dbAddDailyHours(d, 0.1, 0.2)
//            d = new Date()
//            d.setUTCDate(currentDate.getUTCDate() - 6)
//            console.log(d)
//            res = dbAddDailyHours(d, 1.1, 0.5)
//            d = new Date()
//            d.setUTCDate(currentDate.getUTCDate() - 5)
//            console.log(d)
//            res = dbAddDailyHours(d, 3.1, 0.9)
//            d = new Date()
//            d.setUTCDate(currentDate.getUTCDate() - 4)
//            console.log(d)
//            res = dbAddDailyHours(d, 4.1, 0.9)
//            d = new Date()
//            d.setUTCDate(currentDate.getUTCDate() - 3)
//            console.log(d)
//            res = dbAddDailyHours(d, 5.1, 0.9)
//            d = new Date()
//            d.setUTCDate(currentDate.getUTCDate() - 2)
//            console.log(d)
//            res = dbAddDailyHours(d, 4.1, 2.9)
//            d = new Date()
//            d.setUTCDate(currentDate.getUTCDate() - 1)
//            console.log(d)
//            res = dbAddDailyHours(d, 4.1, 3.9)
//            res = dbAddDailyHours(currentDate, 4.1, 4.9)
//            console.log("adding data : " + res)
//            dbUpdateDailyHours(2.0)

            //var dbName = tx.executeSql('SELECT DB_NAME() AS DataBaseName');

            // if the db is empty, add the first entry with today's date and 0 hours
            if(dbLength.rows.item(0).cnt === 0)
            {
                var d = new Date()
                var res = dbAddDailyHours(d, isAM(), currentDayOperationHours)
            }
            else
            {
                // Retrieve last row
                var rsLastRow = tx.executeSql('SELECT * FROM calendarHours WHERE id=(SELECT max(id) FROM calendarHours)');

                console.log("DATE LAST SQL ROW : " + rsLastRow.rows.item(0).date)

                var lastDate = new Date(rsLastRow.rows.item(0).date)
                lastDate.setUTCHours(0)
                lastDate.setUTCMinutes(0)
                lastDate.setUTCSeconds(0)
                lastDate.setUTCMilliseconds(0)

                var currentDate0h0m0s = new Date(currentDate)
                currentDate0h0m0s.setUTCHours(0)
                currentDate0h0m0s.setUTCMinutes(0)
                currentDate0h0m0s.setUTCSeconds(0)
                currentDate0h0m0s.setUTCMilliseconds(0)

                //console.log("DIFF DATE : " + Math.abs(lastDate - currentDate0h0m0s))

                if(currentDate0h0m0s > lastDate)
                {
                    // last entry in the db was yesterday or before
                    // no work has been done yet today
                    // e.g. :  operator starts his workday
                    console.log("Create new entry")
                    res = dbAddDailyHours(currentDate, isAM(), currentDayOperationHours)
                }
                else if(Math.abs(lastDate - currentDate0h0m0s) == 0)
                {
                    morningHours = rsLastRow.rows.item(0).amHours
                    afternoonHours = rsLastRow.rows.item(0).pmHours
                    // someone already worked on the machine today
                    // -> update the last row
                    console.log("Update last entry")
                    dbUpdateDailyHours(isAM(), currentDayOperationHours)
                }
                else
                {
                    // last entry in the db is in the future
                    // would mean that date was manually set back outside the app -> shift the db and set last row as today
                    console.log("Time travelling ?")
                    shiftDbAtInit = true
                }
            }

            dbPrint()

            // Retrieve data from the sql db into our qml vector
            var rs = tx.executeSql('SELECT id, date, amHours, pmHours FROM calendarHours');

//            var d = calendarID.currentDate
//            d.setUTCDate(currentDate.getUTCDate() - rs.rows.length + 1)
//            console.log("init d : " + d)

            workload90DaysTab.pop() // delete the dummy init value
            for (var i = 0; i < rs.rows.length; i++) {
//                var d = new Date()
//                d.setUTCDate(currentDate.getUTCDate() - rs.rows.length + 1 + i)
//                console.log(d)
                workload90DaysTab.push({date: new Date(rs.rows.item(i).date),
                                        amHours: rs.rows.item(i).amHours.toFixed(1),
                                        pmHours: rs.rows.item(i).pmHours.toFixed(1),
                                        dailyHours: (rs.rows.item(i).amHours + rs.rows.item(i).pmHours).toFixed(1)})
            }

            if(shiftDbAtInit)
            {
                shiftDataBase()
            }

            for (i = 0; i < workload90DaysTab.length; i++) {
                console.log("workload90DaysTab[i] : " + workload90DaysTab[i].date + " - " + workload90DaysTab[i].dailyHours)
            }

            //console.log("workload90DaysTab[workload90DaysTab.length - 1].date : " + workload90DaysTab[workload90DaysTab.length - 1].date)

        });
    }

    function dbPrint() {
        db.transaction(function(tx) {
            // Show all added daily hours
            var rs = tx.executeSql('SELECT id, date, amHours, pmHours FROM calendarHours');

            for (var i = 0; i < rs.rows.length; i++) {
                console.log("ID : " + rs.rows.item(i).id + ", date : " + rs.rows.item(i).date +  ", amHours : " + rs.rows.item(i).amHours+  ", pmHours : " + rs.rows.item(i).pmHours)
            }
        });
    }

    function isAM()
    {
        return dateTimeManager.getHour() < 12 ? true : false
    }


    // This function adds a new row in the db
    // isAM = 1 is data is added in the morning
    function dbAddDailyHours(date, isAM, nbDailyHours) {
        var res = "";
        var nbAmHours = 0
        var nbPmHours = 0
        if(isAM)
        {
            // it is currently the morning, so assign the CAN daily operation hours to morning hours
            nbAmHours = nbDailyHours > 12 ? 12 : nbDailyHours < 0 ? 0 : nbDailyHours // max 12 hours in the morning
            nbPmHours = 0
        }
        else
        {
            // it is currently the afternoon
            nbPmHours = nbDailyHours > 12 ? 12 : nbDailyHours < 0 ? 0 : nbDailyHours // max 12 hours in the afternoon
            nbAmHours = 0 // actually unknown
        }

        // Set global properties
        morningHours = nbAmHours
        afternoonHours = nbPmHours

        // Format today's date yyyy-mm-dd
        var dateStr = date.getUTCFullYear() + '-' + String(date.getUTCMonth()+1).padStart(2, '0') + '-' + String(date.getUTCDate()).padStart(2, '0')

        db.transaction(function(tx) {

            // First, get the number of rows in the table, it will be accessible in dbLength.rows.item(0).cnt
            var dbLength = tx.executeSql('SELECT COUNT(*) AS cnt FROM calendarHours');

            var rs

            if(dbLength.rows.item(0).cnt === 0)
            {
                // Insert the value in a new row
                rs = tx.executeSql('INSERT INTO calendarHours (date, amHours, pmHours) VALUES(?,?,?);', [dateStr, nbAmHours, nbPmHours]);
                if(rs.rowsAffected > 0)
                {
                    res = "OK"
                }
                else
                {
                    res = "Error"
                }
            }
            else
            {
                // Get the date of the first row
                var rsFirstRow = tx.executeSql('SELECT * FROM calendarHours WHERE id=1');

                // Compute the difference between the date of the first row and this function's date argument
                var FirtDate = new Date(rsFirstRow.rows.item(0).date)
                FirtDate.setUTCHours(0)
                FirtDate.setUTCMinutes(0)
                FirtDate.setUTCSeconds(0)
                FirtDate.setUTCMilliseconds(0)

                var currentDate0h0m0s = new Date(date)
                currentDate0h0m0s.setUTCHours(0)
                currentDate0h0m0s.setUTCMinutes(0)
                currentDate0h0m0s.setUTCSeconds(0)
                currentDate0h0m0s.setUTCMilliseconds(0)

                var diffDays = Math.abs((FirtDate - currentDate0h0m0s)/(1000*60*60*24))

                //console.log("diffDays : " + diffDays)
                // if the difference is less than 90 days, than simply insert a new row
                if(diffDays < 90)
                {
                    // Insert the value in a new row
                    rs = tx.executeSql('INSERT INTO calendarHours (date, amHours, pmHours) VALUES(?,?,?);', [dateStr, nbAmHours.toFixed(1), nbPmHours.toFixed(1)]);
                    if(rs.rowsAffected > 0)
                    {
                        res = "OK"
                    }
                    else
                    {
                        res = "Error"
                    }
                }
                else
                {
                    console.log("SQL DB MAX SIZE EXCEEDED : SHIFTING VALUES")
                    // Shift all values
                    for (var i = 1; i < dbLength.rows.item(0).cnt; i++) {
                        var rsRow = tx.executeSql('SELECT * FROM calendarHours WHERE id=?', i+1);
                        tx.executeSql('UPDATE calendarHours SET date=?, amHours=?, pmHours=? WHERE id=?', [rsRow.rows.item(0).date, rsRow.rows.item(0).amHours.toFixed(1), rsRow.rows.item(0).pmHours.toFixed(1), i]);
                    }

                    // update the last one
                    tx.executeSql('UPDATE calendarHours SET date=?, amHours=?, pmHours=? WHERE id=?', [dateStr, nbAmHours.toFixed(1), nbPmHours.toFixed(1), dbLength.rows.item(0).cnt]);

                    // Also shift workload90DaysTab
                    workload90DaysTab.shift()

                    res = "OK"
                }
            }
        });

        return res
    }

    function dbUpdateDailyHours(isAM, nbDailyHours) {
        console.log("UPDATING DB")
        db.transaction(function(tx) {

            var nbAmHours = 0
            var nbPmHours = 0
            if(isAM)
            {
                // it is currently the morning, so assign the CAN daily operation hours to morning hours
                nbAmHours = nbDailyHours > 12 ? 12 : nbDailyHours < 0 ? 0 : nbDailyHours // max 12 hours in the morning
                nbPmHours = 0
            }
            else
            {
                // it is currently the afternoon, substract the morning hours
                nbAmHours = morningHours
                nbPmHours = (nbDailyHours - nbAmHours) > 12 ? 12 : (nbDailyHours - nbAmHours) < 0 ? 0 : (nbDailyHours - nbAmHours) // max 12 hours in the afternoon
            }

            // Update global properties
            morningHours = nbAmHours
            afternoonHours = nbPmHours

            // First, get the number of rows in the table, it will be accessible in dbLength.rows.item(0).cnt
            var dbLength = tx.executeSql('SELECT COUNT(*) AS cnt FROM calendarHours');
            //console.log("dblength : " + dbLength.rows.item(0).cnt)

            // Then update the last row
            tx.executeSql('UPDATE calendarHours SET amHours=?, pmHours=? WHERE id=?', [nbAmHours.toFixed(1), nbPmHours.toFixed(1), dbLength.rows.item(0).cnt]);
        });
    }

    Rectangle {
        width: parent.width + 2
        height: parent.height
        color: color_gray
        border {
            color: color_gray_bar
            width: 2
        }
    }

    function resetCalendarProperties()
    {
        dateToShow = new Date() // default date is today
    }

    function menuPressed()
    {
        if (startupInfo.isManualStartMode()) {
            pg_home2.restartTimeoutTimer()
        }
        // View Operational management page
        pgHeader.visible = true
        pgHeader.mainMenu = false
        pgHeader.titleString = qsTrId("LBL_0038") + translator.emptyString
        pg_largeList.visible = true
        pg_calendar.visible = false
        backEnd.setState(MyAppState.OP_MANAGEMENT)
        backEnd.setCurrentPage(pg_largeList)
    }

    function upPressed()
    {
        if (startupInfo.isManualStartMode()) {
            pg_home2.restartTimeoutTimer()
        }

        var d = calendarID.dateToShow
        var upBrowsingDelta = 1
        d.setUTCDate(dateToShow.getUTCDate() - upBrowsingDelta)
        calendarID.dateToShow = d

        // Check whether the selected date is today
        var todayDate = new Date()
        if((d.getUTCFullYear() === todayDate.getUTCFullYear()) && (d.getUTCMonth() === todayDate.getUTCMonth()) && (d.getUTCDate() === todayDate.getUTCDate()))
        {
            dateToShowIsToday = true
        }
        else
        {
            dateToShowIsToday = false
        }

        Comp_specificClassification_calendar.dateToShow = dateToShow
        console.log("dateToShow : " + dateToShow)
    }

    function downPressed()
    {
        if (startupInfo.isManualStartMode()) {
            pg_home2.restartTimeoutTimer()
        }

        var d = calendarID.dateToShow
        var downBrowsingDelta = 1
        d.setUTCDate(dateToShow.getUTCDate() + downBrowsingDelta)
        calendarID.dateToShow = d

        // Check whether the selected date is today
        var todayDate = new Date()
        if((d.getUTCFullYear() === todayDate.getUTCFullYear()) && (d.getUTCMonth() === todayDate.getUTCMonth()) && (d.getUTCDate() === todayDate.getUTCDate()))
        {
            dateToShowIsToday = true
        }
        else
        {
            dateToShowIsToday = false
        }

        Comp_specificClassification_calendar.dateToShow = dateToShow
        console.log("dateToShow : " + dateToShow)
    }

    function enterPressed()
    {
        if (startupInfo.isManualStartMode()) {
            pg_home2.restartTimeoutTimer()
        }
    }

    // Month/Year display at top
    Item {
            id: calendarDateMonthRect

            width: 0.8 * parent.width
            height: 30
            anchors {
                leftMargin: 5
                left: parent.left
                topMargin: 5
                top: parent.top
            }

            Text {
                id: calendarDateMonthText
                color:  "white"
                font.pixelSize: 20
                font.family: systemFont
                anchors {
                    verticalCenter: parent.verticalCenter
                    horizontalCenter: parent.horizontalCenter
                }
                text: (dateToShow.getUTCMonth() + 1) + "/" + dateToShow.getUTCFullYear();
            }
        }

    // Morning hours area
    Item {
            id: calendarMorningHoursRect

            width: parent.width - calendarDateMonthRect.width
            height: 60
            anchors {
                rightMargin: 0
                right: parent.right
                topMargin: 5
                top: parent.top
            }

            // AM
            Text {
                id: calendarMorningHoursAM
                color:  "white"
                font.pixelSize: 24
                font.family: systemFont
                horizontalAlignment: Text.AlignHCenter
                anchors {
                    top: parent.top
                    verticalCenter: parent.verticalCenter
                    horizontalCenter: parent.horizontalCenter
                }
                text: "AM"
            }

            // Duration
            Text {
                id: calendarMorningHoursNum
                color:  "white"
                font.pixelSize: 20
                font.family: systemFont
                horizontalAlignment: Text.AlignHCenter
                anchors {
                    top: parent.top
                    topMargin: 25
                    verticalCenter: parent.verticalCenter
                    horizontalCenter: parent.horizontalCenter
                }
                text: ( dateToShowIsToday ? morningHours.toFixed(1) : Number(dateLevel.workloadAmTab[dateLevel.currentDay - 1]).toFixed(1)) + "h"
            }
        }

    // Afternoon hours area
    Item {
            id: calendarAfternoonHoursRect

            width: parent.width - calendarDateMonthRect.width
            height: 60
            anchors {
                rightMargin: 0
                right: parent.right
                topMargin: 5
                top: calendarMorningHoursRect.bottom
            }

            // PM
            Text {
                id: calendarAfternoonHoursPM
                color: "white"
                font.pixelSize: 24
                font.family: systemFont
                horizontalAlignment: Text.AlignHCenter
                anchors {
                    top: parent.top
                    verticalCenter: parent.verticalCenter
                    horizontalCenter: parent.horizontalCenter
                }
                text: "PM"
            }

            // Duration
            Text {
                id: calendarAfternoonHoursNum
                color: "white"
                font.pixelSize: 20
                font.family: systemFont
                horizontalAlignment: Text.AlignHCenter
                anchors {
                    top: parent.top
                    topMargin: 25
                    verticalCenter: parent.verticalCenter
                    horizontalCenter: parent.horizontalCenter
                }
                text: ( dateToShowIsToday ? afternoonHours.toFixed(1) : Number(dateLevel.workloadPmTab[dateLevel.currentDay - 1]).toFixed(1)) + "h"
            }
        }

    // Total hours area
    Item {
            id: calendarTotalHoursRect

            width: parent.width - calendarDateMonthRect.width
            height: 60
            anchors {
                rightMargin: 0
                right: parent.right
                topMargin: 5
                top: calendarAfternoonHoursRect.bottom
            }

            // Day
            Text {
                id: calendarTotalHoursPM
                color: "white"
                font.pixelSize: 19
                font.family: systemFont
                anchors {
                    left: parent.left
                    leftMargin: 10
                }
                text: qsTrId("LBL_0040") + translator.emptyString + " :"
            }

            // Duration
            Text {
                id: calendarTotalHoursNum
                color: "white"
                font.pixelSize: 20
                font.family: systemFont
                horizontalAlignment: Text.AlignHCenter
                anchors {
                    top: parent.top
                    topMargin: 25
                    verticalCenter: parent.verticalCenter
                    horizontalCenter: parent.horizontalCenter
                }
                text: Number(dateLevel.workloadDayTab[dateLevel.currentDay-1]).toFixed(1) + "h"
            }
        }

    // Weekly and monthly hours at bottom
    Item {
            id: calendarWeeklyMonthlyHoursRect

            width: 272
            height: 22
            anchors {
                bottomMargin: 1
                bottom: parent.bottom
            }

            // Weekly hours
            Text {
                id: calendarWeeklyHours
                color: "white"
                font.pixelSize: 18
                font.family: systemFont
                anchors {
                    left: parent.left
                    leftMargin: 7
                }
                text: qsTrId("LBL_0041") + translator.emptyString + " : " + dateLevel.workloadHighlightedWeek.toFixed(1) + "h"
            }

            // Monthly hours
            Text {
                id: calendarMonthlyHours
                color: "white"
                font.pixelSize: 18
                font.family: systemFont
                anchors {
                    right: parent.right
                    rightMargin: 4
                }
                text: qsTrId("LBL_0042") + translator.emptyString + " : " + dateLevel.workloadDisplayedMonth.toFixed(1) + "h"
            }
        }

    Rectangle {
            id: calendarGrid
            width: calendarDateMonthRect.width
            height: parent.height - calendarDateMonthRect.height - calendarWeeklyMonthlyHoursRect.height
            color: "transparent"
            anchors {
                leftMargin: 5
                left: parent.left
                topMargin: -2
                top: calendarDateMonthRect.bottom
            }

            Comp_specificClassification_calendar {
                id: dateLevel
                //dateToShow: new Date(2023,0,2)
                dateToShow: calendarID.dateToShow
                workload90DaysTab_comp: workload90DaysTab
            }


    }

}

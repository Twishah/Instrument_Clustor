import QtQuick 2.11
import MyQmlModule 1.0
import QtGraphicalEffects 1.0
import "../components"

Flickable {
	id: listMechanicID


	width: parent.width
	height: parent.height
	anchors {
		top: parent.top
		topMargin: backEnd.currentConfig.headerHeight //+ 1
	}

	contentWidth: listMechanicID.width
	contentHeight: heightItem * lengthItems // calculate container height to fit all items

	boundsBehavior: Flickable.StopAtBounds

	Keys.forwardTo: controller

	property int currentIndex: 0
	property int selectedIndex: 0
	property int maxLengthItems: 30// maximum number of Mechanic Usage History entries
	property int lengthItems: dm.get_mecHist_nbMax()
	property int heightItem: 43

	property bool is12HourFormat: dm.formatHour === 1 ? true : false

	property string resultDate: ""
	property string resultTime: ""
	property int resultHourmeter: 0

	function resetIndexes() {
		selectedIndex = 0
		currentIndex = 0
		contentY = 0
	}

	// To update the graphics
	function calculateNbItems() {
		for (var i = 0; i < lengthItems; i++) {
			repUsageHistory.itemAt(i).dateStr = dm.get_mechanic_history(i).dateMecHist

			if(is12HourFormat)
			{
				var timeStrList = dm.get_mechanic_history(i).timeMecHist.split(':')
				var amPm = parseInt(timeStrList[0]) >= 12 ? "PM" : "AM"
				var mins = timeStrList[1]
				var hour = parseInt(timeStrList[0]) % 12
				if (hour === 0) {
					hour = 12;
				}
				repUsageHistory.itemAt(i).timeStr = hour + ":" + mins + amPm
			}
			else {
				repUsageHistory.itemAt(i).timeStr = dm.get_mechanic_history(i).timeMecHist
			}

			repUsageHistory.itemAt(i).hourMeterHistoryStr = dm.get_mechanic_history(i).hourmeterMecHist + "h"
		}
	}

	// To call it when the user is in the mechanic mode
	function updateUsageHistory() {
		listMechanicID.lengthItems++
		if (listMechanicID.lengthItems > listMechanicID.maxLengthItems) {
			listMechanicID.lengthItems = listMechanicID.maxLengthItems
		}
		dm.mecHist_nbMax = listMechanicID.lengthItems
		dm.save_mecHist_nbMax()
		listMechanicID.lengthItems = dm.get_mecHist_nbMax()

		var dayValue = dateTimeManager.getDay() < 10 ? "0" + dateTimeManager.getDay().toString() : dateTimeManager.getDay().toString()
		var monthValue = dateTimeManager.getMonth() < 10 ? "0" + dateTimeManager.getMonth().toString() : dateTimeManager.getMonth().toString()
		var yearValue = dateTimeManager.getYear().toString()
		resultDate = dayValue + "/" + monthValue + "/" + yearValue
		dm.get_mechanic_history(0).dateMecHist = resultDate
		dm.get_mechanic_history(0).timeMecHist = dateTimeManager.getCurrentTime()

		var hourValue = dateTimeManager.getHour() < 10 ? "0" + dateTimeManager.getHour().toString() : dateTimeManager.getHour().toString()
		var minValue = dateTimeManager.getMinutes() < 10 ? "0" + dateTimeManager.getMinutes().toString() : dateTimeManager.getMinutes().toString()
		resultTime = hourValue + ":" + minValue
		dm.get_mechanic_history(0).timeMecHist = resultTime

		resultHourmeter = parseInt(dataEngine.opHours_Total.value)
		dm.get_mechanic_history(0).hourmeterMecHist = resultHourmeter

		sortAccordingToHourmeter()
		calculateNbItems()
	}

	// To sort elements of the vector of the DataManager according to the hourmeter value
	function sortAccordingToHourmeter() {
		for (var i = 0; i < listMechanicID.lengthItems; i++) {
			for (var j = 0; j < listMechanicID.lengthItems - i - 1; j++) {
				var hm0 = dm.get_mechanic_history(j).hourmeterMecHist
				var hm1 = dm.get_mechanic_history(j+1).hourmeterMecHist
				if (hm0 < hm1) {
					dm.get_mechanic_history(j).hourmeterMecHist = hm1
					dm.get_mechanic_history(j+1).hourmeterMecHist = hm0

					var d0 = dm.get_mechanic_history(j).dateMecHist
					var d1 = dm.get_mechanic_history(j+1).dateMecHist
					dm.get_mechanic_history(j).dateMecHist = d1
					dm.get_mechanic_history(j+1).dateMecHist = d0

					var t0 = dm.get_mechanic_history(j).timeMecHist
					var t1 = dm.get_mechanic_history(j+1).timeMecHist
					dm.get_mechanic_history(j).timeMecHist = t1
					dm.get_mechanic_history(j+1).timeMecHist = t0
				}
			}
		}

		dm.save_mechanic_history()
	}

	// To reset the mechanic usage history
	function resetAllUsageHistory() {
		for (var i = 0; i < lengthItems; i++) {
			repUsageHistory.itemAt(i).dateStr = ""
			repUsageHistory.itemAt(i).timeStr = ""
			repUsageHistory.itemAt(i).hourMeterHistoryStr = ""
		}

		dm.mecHist_nbMax = 0
		listMechanicID.lengthItems = 0
		dm.save_mecHist_nbMax()

		dm.save_mechanic_history()
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
		else {
			backEnd.setState(MyAppState.MENU)
		}
		backEnd.setCurrentPage(pg_menu)
		pg_listMechanic.visible = false
		pgHeader.visible = false
		pg_menu.visible = true
		rectList.visible = false
		rectMenu.visible = true
	}

	onVisibleChanged: {

		if(visible === true) {
			console.log("Page PG_listMechanic entered")
		}
	}

	function upPressed()
	{
		listMechanicID.currentIndex = (listMechanicID.currentIndex - 1 + listMechanicID.lengthItems) % listMechanicID.lengthItems
		var itemY = currentIndex * heightItem;
		if (itemY < contentY) {
			contentY = itemY;
		} else if (itemY + heightItem > contentY + height) {
			contentY = itemY + heightItem - height;
		}
	}

	function downPressed()
	{
		listMechanicID.currentIndex = (listMechanicID.currentIndex + 1) % listMechanicID.lengthItems
		var itemY = currentIndex * heightItem;
		if (itemY + heightItem > contentY + height) {
			contentY = itemY + heightItem - height;
		} else if (itemY < contentY) {
			contentY = itemY;
		}
	}

	function enterPressed()
	{

	}

	Column  {
		id: containerUsageHistory
		width: parent.width
		height: parent.height
		visible: backEnd.state === MyAppState.MECA_MODE_HISTORY || pg_popUp.lastState === MyAppState.MECA_MODE_HISTORY ? true : false

		Repeater {
			id: repUsageHistory
			model: listMechanicID.maxLengthItems
			Comp_listItemUsageHistory {
				id: history
				dateStr: ""
				timeStr: ""
				hourMeterHistoryStr: ""
				isCurrent: listMechanicID.currentIndex === index ? true : false
			}
		}
	}
}

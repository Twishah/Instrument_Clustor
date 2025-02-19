import QtQuick 2.11
import MyQmlModule 1.0
import QtGraphicalEffects 1.0
import QtQuick.Controls 2.4
import "../components"


Rectangle {
	id: listIconMultipleID

	width: parent.width
	height: parent.height
	anchors.topMargin: backEnd.currentConfig.headerHeight
	color: color_black

	property int currentIndex: 0
	property int selectedIndex: 0
	property var selectedItems: [dm.getPreHeatingDate(0), dm.getPreHeatingDate(1),
		dm.getPreHeatingDate(2), dm.getPreHeatingDate(3),
		dm.getPreHeatingDate(4), dm.getPreHeatingDate(5),
		dm.getPreHeatingDate(6)]
	property int lengthItems: 7
	property string headerIconStr: "qrc:/graphics/PreHeatingSettings/7.40 Pre-heating settings - white.png"


	onVisibleChanged: {

		if(visible === true) {
			console.log("Page PG_listIconMultiple entered")
		}
	}

	// To enter into the list of Maintenance History
	function selectPreHeatingDaySetList() {
		listIconMultipleID.lengthItems = 7

		for (var i = 0; i < 7; i++) {
			if (listIconMultipleID.selectedItems[i]) {
				listIconMultipleID.currentIndex = i
				listIconMultipleID.selectedIndex = i
				break
			}
			else {
				listIconMultipleID.currentIndex = 0
				listIconMultipleID.selectedIndex = 0
			}
		}
		initializeContentY()

		listIconMultipleID.headerIconStr = "qrc:/graphics/PreHeatingSettings/7.40 Pre-heating settings - white.png"
	}

	function initializeContentY() {
		var itemY = currentIndex * 34;
		if (itemY < flickable.contentY) {
			flickable.contentY = itemY;
		} else if (itemY + 34 > flickable.contentY + flickable.height) {
			flickable.contentY = itemY + 34 - flickable.height;
		}

		itemY = currentIndex * 34;
		if (itemY + 34 > flickable.contentY + flickable.height) {
			flickable.contentY = itemY + (34 + 1) - flickable.height;
		} else if (itemY < flickable.contentY) {
			flickable.contentY = itemY;
		}
	}

	function updateSelectedDays() {
		listIconMultipleID.selectedItems[0] = listDay1.state
		listIconMultipleID.selectedItems[1] = listDay2.state
		listIconMultipleID.selectedItems[2] = listDay3.state
		listIconMultipleID.selectedItems[3] = listDay4.state
		listIconMultipleID.selectedItems[4] = listDay5.state
		listIconMultipleID.selectedItems[5] = listDay6.state
		listIconMultipleID.selectedItems[6] = listDay7.state
		//console.log(listIconMultipleID.selectedItems)

		for (var i = 0; i < 7; i++) {
			if (listIconMultipleID.selectedItems[i]) {
				pg_preHeating.setDay(i)
			}
			else {
				pg_preHeating.unsetDay(i)
			}
		}

		dm.savePreHeatingSettings()
	}

	function backToPreHeating() {
		backEnd.setState(MyAppState.PRE_HEATING)
		backEnd.setCurrentPage(pg_preHeating)
		pg_listIconMultiple.updateSelectedDays()
		pg_listIconMultiple.visible = false
		pg_preHeating.visible = true
		pgHeader.titleString = qsTrId("LBL_0063") + translator.emptyString
	}

	function menuPressed()
	{
		if (backEnd.state === MyAppState.PH_1_DAY) {
			backToPreHeating()
		}
		else {
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
			pg_listIconMultiple.visible = false
			pgHeader.visible = false
			pg_menu.visible = true
			rectList.visible = false
			rectMenu.visible = true
		}
	}

	function upPressed()
	{
		listIconMultipleID.currentIndex = (listIconMultipleID.currentIndex - 1 + listIconMultipleID.lengthItems) % listIconMultipleID.lengthItems
		var itemY = currentIndex * listDay7.height
		if (itemY < flickable.contentY) {
			flickable.contentY = itemY
		} else if (itemY + listDay7.height > flickable.contentY + flickable.height) {
			flickable.contentY = itemY + listDay7.height - flickable.height
		}
	}

	function downPressed()
	{
		listIconMultipleID.currentIndex = (listIconMultipleID.currentIndex + 1) % listIconMultipleID.lengthItems
		var itemY = currentIndex * listDay7.height
		if (itemY + listDay7.height > flickable.contentY + flickable.height) {
			flickable.contentY = itemY + listDay7.height - flickable.height
		} else if (itemY < flickable.contentY) {
			flickable.contentY = itemY
		}
	}

	function enterPressed()
	{
		listIconMultipleID.selectedIndex = listIconMultipleID.currentIndex
		if (listIconMultipleID.selectedIndex === 0) {
			listDay1.changeState()
		}
		else if (listIconMultipleID.selectedIndex === 1) {
			listDay2.changeState()
		}
		else if (listIconMultipleID.selectedIndex === 2) {
			listDay3.changeState()
		}
		else if (listIconMultipleID.selectedIndex === 3) {
			listDay4.changeState()
		}
		else if (listIconMultipleID.selectedIndex === 4) {
			listDay5.changeState()
		}
		else if (listIconMultipleID.selectedIndex === 5) {
			listDay6.changeState()
		}
		else if (listIconMultipleID.selectedIndex === 6) {
			listDay7.changeState()
		}
	}

	Flickable {
		id: flickable

		width: parent.width
		height: parent.height - headerIcon.height

		contentWidth: containerPreHeatingDaySet.width
		contentHeight: listDay7.height * lengthItems // calculate container height to fit all items

		anchors.top: headerIcon.bottom

		Keys.forwardTo: controller

		property var textTitres: [qsTrId("LBL_0068") + translator.emptyString, qsTrId("LBL_0069") + translator.emptyString, qsTrId("LBL_0070") + translator.emptyString,
			qsTrId("LBL_0071") + translator.emptyString, qsTrId("LBL_0072") + translator.emptyString, qsTrId("LBL_0073") + translator.emptyString, qsTrId("LBL_0074") + translator.emptyString]

		Rectangle {
			id: containerPreHeatingDaySet

			width: parent.width
			height: parent.height
			anchors.top: parent.top

			color: "transparent"
			visible: backEnd.state === MyAppState.PH_1_DAY || pg_popUp.lastState === MyAppState.PH_1_DAY ? true : false

			Comp_listIconNew {
				id: listDay1
				isCurrent:  listIconMultipleID.currentIndex === 0 ? true : false
				titreText: flickable.textTitres[0]
				anchors.top: parent.top
				state: listIconMultipleID.selectedItems[0]
				iconPict: listIconMultipleID.selectedItems[0] ? checkboxON : checkboxOFF
				visible: flickable.children[0].y <= -1*36 + 1 ? false : true
			}

			Comp_listIconNew {
				id: listDay2
				isCurrent:  listIconMultipleID.currentIndex === 1 ? true : false
				titreText: flickable.textTitres[1]
				anchors.top: listDay1.bottom
				state: listIconMultipleID.selectedItems[1]
				iconPict: listIconMultipleID.selectedItems[1] ? checkboxON : checkboxOFF
				visible: flickable.children[0].y <= -2*36 + 1 ? false : true
			}

			Comp_listIconNew {
				id: listDay3
				isCurrent:  listIconMultipleID.currentIndex === 2 ? true : false
				titreText: flickable.textTitres[2]
				anchors.top: listDay2.bottom
				state: listIconMultipleID.selectedItems[2]
				iconPict: listIconMultipleID.selectedItems[2] ? checkboxON : checkboxOFF
				visible: flickable.children[0].y <= -3*36 + 1 ? false : true
			}

			Comp_listIconNew {
				id: listDay4
				isCurrent:  listIconMultipleID.currentIndex === 3 ? true : false
				titreText: flickable.textTitres[3]
				anchors.top: listDay3.bottom
				state: listIconMultipleID.selectedItems[3]
				iconPict: listIconMultipleID.selectedItems[3] ? checkboxON : checkboxOFF
				visible: flickable.children[0].y <= -4*36 + 1 ? false : true
			}

			Comp_listIconNew {
				id: listDay5
				isCurrent:  listIconMultipleID.currentIndex === 4 ? true : false
				titreText: flickable.textTitres[4]
				anchors.top: listDay4.bottom
				state: listIconMultipleID.selectedItems[4]
				iconPict: listIconMultipleID.selectedItems[4] ? checkboxON : checkboxOFF
				visible: flickable.children[0].y <= -5*36 + 1 ? false : true
			}
			Comp_listIconNew {
				id: listDay6
				isCurrent:  listIconMultipleID.currentIndex === 5 ? true : false
				titreText: flickable.textTitres[5]
				anchors.top: listDay5.bottom
				state: listIconMultipleID.selectedItems[5]
				iconPict: listIconMultipleID.selectedItems[5] ? checkboxON : checkboxOFF
				visible: flickable.children[0].y <= -6*36 + 1 ? false : true
			}

			Comp_listIconNew {
				id: listDay7
				isCurrent:  listIconMultipleID.currentIndex === 6 ? true : false
				titreText: flickable.textTitres[6]
				anchors.top: listDay6.bottom
				state: listIconMultipleID.selectedItems[6]
				iconPict: listIconMultipleID.selectedItems[6] ? checkboxON : checkboxOFF
				visible: flickable.children[0].y <= -7*36 + 1 ? false : true
			}
		}
	}


	Rectangle {
		id: headerIcon
		width: 273
		height: 70
		color: color_gray
		anchors {
			top : parent.top
			topMargin: 1
		}
		border {
			color: color_gray_bar
			width: 1
		}

		Image {
			id: icon
			source: headerIconStr
			anchors {
				verticalCenter: parent.verticalCenter
				horizontalCenter: parent.horizontalCenter
			}
			fillMode: Image.Pad
		}
	}
}


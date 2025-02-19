import QtQuick 2.0
import MyQmlModule 1.0
import QtGraphicalEffects 1.0
import QtQuick.Controls 2.4
import "../components"

// Seite mit Auswahl des Werkzeugs für PTO

Flickable {
	id: lineStatusBarIconID

	width: parent.width
	height: parent.height
	anchors.topMargin: backEnd.currentConfig.headerHeight
	contentWidth: container.width
	contentHeight: container.height

	boundsBehavior: Flickable.StopAtBounds
	Keys.forwardTo: controller

	property int currentIndex: dm.indexPTO !== 0 ? dm.indexPTO - 1 : 0
	property int selectedPresetIndex: dm.indexPTO !== 0 ? dm.indexPTO - 1 : -1
	property int rowHeight: container.children[0].height
	property int isUnlock: dm.get_indexLockState() // depending on Aux Flow Limit LOCK from mechanic mode!

	onVisibleChanged: {
		upPressed();
		downPressed();
		downPressed();
		upPressed();

		if(visible === true)
		{
			console.log("Page PG_lineStatusBarIcon entered")
		}
	}

	function updatePtoSetInd() {
		if (dm.indexPTO !== 0) {
			selectedPresetIndex = dm.indexPTO - 1
			currentIndex = selectedPresetIndex
		}
		else {
			currentIndex = 0
			selectedPresetIndex = -1
		}
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
		pg_lineStatusBarIcon.visible = false
		pg_menu.visible = true
		pgHeader.visible = false
		rectList.visible = false
		rectMenu.visible = true
	}

	function enterPressed()
	{
		if (isUnlock === 1) {
			backEnd.setState(MyAppState.PTO_1_FLOW_LIMIT)
			backEnd.setCurrentPage(pg_ptoSettings)
			pg_ptoSettings.visible = true
			pg_lineStatusBarIcon.visible = false
		}

		pg_ptoSettings.resetIndexes()
		if (isUnlock === 1) {
			pg_ptoSettings.presetIndex = currentIndex
			pg_ptoSettings.accessory_icon_sourceTemp = dm.getPtoSettings(currentIndex).accessory_icon_source;
			pg_ptoSettings.pto1Temp_left = dm.getPtoSettings(currentIndex).pto1_left;
			pg_ptoSettings.pto1Temp_right = dm.getPtoSettings(currentIndex).pto1_right;
			pg_ptoSettings.pto2Temp_left = dm.getPtoSettings(currentIndex).pto2_left;
			pg_ptoSettings.pto2Temp_right = dm.getPtoSettings(currentIndex).pto2_right;

			pgHeader.visible = true
			pgHeader.mainMenu = false
			pgHeader.titleString = qsTrId("LBL_X03" + currentIndex) + translator.emptyString
		}
		if (isUnlock === 0) {
			pum.addPopUp("qrc:/graphics/Popups/2.10 PTO lock pop-up.png", qsTrId("LBL_0276") + translator.emptyString, 4, 5)
		}
	}

	function downPressed()
	{
		currentIndex = (currentIndex + 1) % 7
		var itemY = currentIndex * rowHeight;
		if (itemY + rowHeight > contentY + height) {
			contentY = itemY + rowHeight - height;
		} else if (itemY < contentY) {
			contentY = itemY;
		}
	}

	function upPressed()
	{
		currentIndex = (currentIndex - 1 + 7) % 7
		var itemY = currentIndex * rowHeight;
		if (itemY < contentY) {
			contentY = itemY;
		} else if (itemY + rowHeight > contentY + height) {
			contentY = itemY + rowHeight - height;
		}
	}

	Rectangle {
		id: container
		width: width
		height: rowHeight * 7
		color: color_black

		Repeater {
			model: 7

			Comp_listItemLineStatusBarIcon {
				id: listItem
				iconPict: dm.getPtoSettings(index).accessory_icon_source === "" ? ""  : dm.getPtoSettings(index).accessory_icon_source + "_WH.png"
				titleText: qsTrId("LBL_0031").slice(0, -1) + (index+1).toString() + translator.emptyString
				isCurrent: currentIndex === index ? true : false
				isSelected: selectedPresetIndex === index ? true : false
				anchors.top: index === 0 ? parent.top : parent.children[index-1].bottom
			}
		}
	}
}

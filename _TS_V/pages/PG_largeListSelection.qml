import QtQuick 2.0
import MyQmlModule 1.0
import QtGraphicalEffects 1.0
import "../components"

Item {
	id: largeListeSelectionID

	width: parent.width
	height: parent.height
	anchors.topMargin: backEnd.currentConfig.headerHeight

	property int currentIndex: 0
	property int selectedIndex: 0
	property int rowHeight: (69 + 2)

	onVisibleChanged: {
		upPressed();
		downPressed();
		downPressed();
		upPressed();

		if(visible === true) {
			console.log("Page PG_largeListSelection entered")
		}
	}

	function menuPressed()
	{
		backEnd.setState(MyAppState.PTO_1_FLOW_LIMIT)
		backEnd.setCurrentPage(pg_ptoSettings)
		pg_ptoSettings.visible = true
		pg_largeListSelection.visible = false

		pgHeader.visible = true
		pgHeader.mainMenu = false
		pgHeader.titleString = qsTrId("LBL_X03" + pg_lineStatusBarIcon.currentIndex) + translator.emptyString
	}

	function enterPressed()
	{
		selectedIndex = currentIndex

		backEnd.setState(MyAppState.PTO_1_FLOW_LIMIT)
		backEnd.setCurrentPage(pg_ptoSettings)
		pg_ptoSettings.accessory_icon_sourceTemp = container.sourcesOrigin[selectedIndex]
		pg_ptoSettings.visible = true
		pg_largeListSelection.visible = false

		pgHeader.visible = true
		pgHeader.mainMenu = false
		pgHeader.titleString = qsTrId("LBL_X03" + pg_lineStatusBarIcon.currentIndex) + translator.emptyString
	}

	function downPressed()
	{
		currentIndex = (currentIndex + 1) % 7
		var itemY = currentIndex * rowHeight;
		if (itemY + rowHeight > container.contentY + height) {
			container.contentY = itemY + rowHeight - height + 2;
		} else if (itemY < container.contentY) {
			container.contentY = itemY;
		}
	}

	function upPressed()
	{
		currentIndex = (currentIndex - 1 + 7) % 7
		var itemY = currentIndex * rowHeight;
		if (itemY < container.contentY) {
			container.contentY = itemY;
		} else if (itemY + rowHeight > container.contentY + height) {
			container.contentY = itemY + rowHeight - height + 2;
		}
	}

	function resetY()
	{
		container.contentY = 0;
	}

	Image {
		id: backgroundPagePicture

		fillMode: Image.Pad
		source: "qrc:/graphics/PtoSettings/5.16 Frame large list.png"
		anchors {
			left: parent.left
			top: parent.top
			topMargin: -25
			leftMargin: 1
		}
	}

	Flickable {
		id: container
		width: 252
		height: rowHeight * 6
		anchors {
			left: parent.left
			leftMargin: 4
			top: parent.top
			topMargin: 2
		}
		boundsBehavior: Flickable.StopAtBounds
		Keys.forwardTo: controller

		property var sources: [
			"qrc:/graphics/02_Main_Icons PNG/02_Main_Icons PNG 60x60/2.111 AUX_WH.png",
			"qrc:/graphics/02_Main_Icons PNG/02_Main_Icons PNG 60x60/2.105_Forage harvester_ cutterhead_WH.png",
			"qrc:/graphics/02_Main_Icons PNG/02_Main_Icons PNG 60x60/2.106 Rotary brush_WH.png",
			"qrc:/graphics/02_Main_Icons PNG/02_Main_Icons PNG 60x60/2.110 Mulcher_WH.png",
			"qrc:/graphics/02_Main_Icons PNG/02_Main_Icons PNG 60x60/2.108 Trencher conveyor_WH.png",
			"qrc:/graphics/02_Main_Icons PNG/02_Main_Icons PNG 60x60/2.104_Loader bucket grapple_WH.png",
			"qrc:/graphics/02_Main_Icons PNG/02_Main_Icons PNG 60x60/2.109 Vibration plate_WH.png"
		]

		property var sourcesOrigin: [
			"qrc:/graphics/02_Main_Icons PNG/02_Main_Icons PNG 25x25/2.111 AUX",
			"qrc:/graphics/02_Main_Icons PNG/02_Main_Icons PNG 25x25/2.105_Forage harvester_ cutterhead",
			"qrc:/graphics/02_Main_Icons PNG/02_Main_Icons PNG 25x25/2.106 Rotary brush",
			"qrc:/graphics/02_Main_Icons PNG/02_Main_Icons PNG 25x25/2.110 Mulcher",
			"qrc:/graphics/02_Main_Icons PNG/02_Main_Icons PNG 25x25/2.108 Trencher conveyor",
			"qrc:/graphics/02_Main_Icons PNG/02_Main_Icons PNG 25x25/2.104_Loader bucket grapple",
			"qrc:/graphics/02_Main_Icons PNG/02_Main_Icons PNG 25x25/2.109 Vibration plate"
		]

		Column {
			spacing: 2
			Repeater {
				model: container.sources.length
				Comp_listItemLargeListSelection {
					sourcePicture: container.sources[index]
					isCurrent: currentIndex === index ? true : false
					isSelected: selectedIndex === index ? true : false
				}
			}
		}
	}

}

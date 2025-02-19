import QtQuick 2.0
import MyQmlModule 1.0
import QtGraphicalEffects 1.0
import QtQuick.Controls 2.4
import "../components"

Flickable {
	id: errorInfoListID

	width: parent.width
	height: parent.height

	anchors.topMargin: backEnd.currentConfig.headerHeight

	boundsBehavior: Flickable.StopAtBounds
	Keys.forwardTo: controller
	visible: false
	//property int errorIDdummy: 4456705 // 0x440101
	property string mcuLastErrorID: "000000"// TODO: link to dataengine values : dataEngine.dTCID.value.toString(16) // stringified hex from int
	property Item modelSelected : currentErrorPG

	onVisibleChanged: {
		if (visible === false && backEnd.state !== MyAppState.LI_1_DETAILS && backEnd.state !== MyAppState.ER_HI_1_DETAIL) {
			currentErrorPG.currentIndex = 0;
			historyErrorPG.currentIndex = 0;
			historyErrorPG.fileIndex = 0;
			backgroundPage.y = -backEnd.currentConfig.headerHeight - 1;
			contentY = 0;
		}

		if (backEnd.state === MyAppState.LIST) {
			modelSelected = currentErrorPG;
			upPressed();
			downPressed();
		} else if (backEnd.state === MyAppState.ERROR_HISTORY) {
			modelSelected = historyErrorPG;
			upPressed();
			downPressed();
		}

		if(visible === true) {
			console.log("Page PG_list entered")
		}
	}

	function menuPressed()
	{
		// View Menu page
		if (backEnd.state === MyAppState.LIST) {
			if (controller.isMechanicMode1) {
				backEnd.setState(MyAppState.MENU_MECA_1)
				backEnd.setCurrentPage(pg_menu)
				pg_list.visible = false
				pgHeader.visible = false
				pg_menu.visible = true
			}
			else if (controller.isMechanicMode2) {
				backEnd.setState(MyAppState.MENU_MECA_2)
				backEnd.setCurrentPage(pg_menu)
				pg_list.visible = false
				pgHeader.visible = false
				pg_menu.visible = true
			} else {
				backEnd.setState(MyAppState.MAIN);
				backEnd.setCurrentPage(pg_home);
				pg_list.visible = false;
				pg_home.visible = true;
				pgHeader.visible = true
				pgHeader.mainMenu = true

				rectList.visible = false
				rectMenu.visible = false
			}
		} else if (backEnd.state === MyAppState.ERROR_HISTORY) {
			if (controller.isMechanicMode1)
				backEnd.setState(MyAppState.MENU_MECA_1)
			else if (controller.isMechanicMode2)
				backEnd.setState(MyAppState.MENU_MECA_2)
			else
				backEnd.setState(MyAppState.MENU)
			backEnd.setCurrentPage(pg_menu);
			pg_list.visible = false;
			pg_menu.visible = true;
			pgHeader.visible = false

			rectList.visible = false
			rectMenu.visible = true
		}
	}

	function upPressed()
	{
		if (backEnd.state === MyAppState.LIST && repeater.model > 0) {
			modelSelected.currentIndex = (modelSelected.currentIndex - 1 + repeater.model) % repeater.model;
			var itemY = modelSelected.currentIndex * 43;
			if (itemY < contentY) {
				contentY = itemY;
				backgroundPage.y = itemY -backEnd.currentConfig.headerHeight - 1;
			}
			else if (itemY + 43 > contentY + height) {
				contentY = itemY + 43 - height;
				backgroundPage.y = itemY -backEnd.currentConfig.headerHeight - 1 - (43 * 4);
			}
		}
		else if (backEnd.state === MyAppState.ERROR_HISTORY && errorManager.getHistoryErrorLength() > 0) {
			if (historyErrorPG.fileIndex - 1 < 0) {
				historyErrorPG.fileIndex = errorManager.getHistoryErrorLength() - 1
				if (errorManager.getHistoryErrorLength() >= 5)
					historyErrorPG.currentIndex = 4;
				else
					historyErrorPG.currentIndex = errorManager.getHistoryErrorLength() - 1;
				return;
			} else
				historyErrorPG.fileIndex--;
			if (historyErrorPG.currentIndex > 0)
				historyErrorPG.currentIndex--;
		}
	}

	function downPressed()
	{
		if (backEnd.state === MyAppState.LIST) {
			modelSelected.currentIndex = (modelSelected.currentIndex + 1) % repeater.model
			var itemY = modelSelected.currentIndex * 43;
			if (itemY + 43 > contentY + height) {
				contentY = itemY + 43 - height;
				backgroundPage.y += 43
			} else if (itemY < contentY) {
				contentY = itemY;
				backgroundPage.y = -backEnd.currentConfig.headerHeight - 1;
			}
		}
		else if (backEnd.state === MyAppState.ERROR_HISTORY) {
			if (historyErrorPG.fileIndex + 1 >= errorManager.getHistoryErrorLength()) {
				historyErrorPG.currentIndex = 0;
				historyErrorPG.fileIndex = 0
				return;
			} else
				historyErrorPG.fileIndex++
			if (historyErrorPG.currentIndex < 4)
				historyErrorPG.currentIndex++;
		}
	}

	function enterPressed()
	{
		if (repeater.model < 1)
			return;

		if (backEnd.state === MyAppState.LIST) {
			backEnd.setState(MyAppState.LI_1_DETAILS);
			pg_listDetails.errorInfo = errorManager.getCurrentErrorAt(currentErrorPG.currentIndex);
		}
		else if (backEnd.state === MyAppState.ERROR_HISTORY) {
			backEnd.setState(MyAppState.ER_HI_1_DETAIL);
			pg_listDetails.errorInfo = errorManager.getHistoryErrorAt(historyErrorPG.fileIndex);
		}
		backEnd.setCurrentPage(pg_listDetails);
		pg_listDetails.visible = true;
		pg_list.visible = false;
		pgHeader.visible = true;
		pgHeader.mainMenu = false;
		pgHeader.titleString = qsTrId("LBL_0004") + translator.emptyString;
	}

	Item {
		id: currentErrorPG

		property int currentIndex: 0
		property int nbItems: errorManager.getCurrentErrorLength();
	}

	Item {
		id: historyErrorPG

		property int currentIndex: 0
		property int fileIndex: 0
		property int nbItems: {
			if (historyErrorPG.nbItems === 0) {
			  if (errorManager.getHistoryErrorLength() < 5)
				  historyErrorPG.nbItems = errorManager.getHistoryErrorLength();
			  else
				  historyErrorPG.nbItems = 5;
			}
		}
	}

	Image {
		id: backgroundPage

		y: -backEnd.currentConfig.headerHeight - 1
		fillMode: Image.Pad
		source: "qrc:/graphics/ErrorList/5.7 Frame list.png"
	}

	Repeater {
		id: repeater
		anchors.top: parent.top
		anchors.topMargin: 2

		model: modelSelected.nbItems

		Comp_listItemErrorInfoList {
			errorInfo: modelSelected === currentErrorPG ? errorManager.getCurrentErrorAt(index) : errorManager.getHistoryErrorAt(historyErrorPG.fileIndex + index - historyErrorPG.currentIndex)
			isCurrent: modelSelected.currentIndex === index ? true : false
			anchors.top: index === 0 ? parent.top : parent.children[index + 2].bottom
			anchors.topMargin: index === 0 ? 0 : -1
			z: isCurrent ? parent.z + 1 : parent.z
			visible: true
		}
	}

	Connections {
		target: errorManager

		onCurrentErrorLenghtChanged: {
			currentErrorPG.nbItems = errorManager.getCurrentErrorLength();

			if (currentErrorPG.currentIndex > repeater)
				currentErrorPG.currentIndex = 0;
		}

		onHistoryErrorLenghtChanged: {
			if (errorManager.getHistoryErrorLength() < 5)
				historyErrorPG.nbItems = errorManager.getHistoryErrorLength();
			else
				historyErrorPG.nbItems = 5;
		}
	}
}

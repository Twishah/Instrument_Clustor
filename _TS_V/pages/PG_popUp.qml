import QtQuick 2.6
import MyQmlModule 1.0
import QtGraphicalEffects 1.0
import "../components"


Item {
	id: popUpID

	height: 240
	width: 320
	visible: false

	property QtObject lastPage: {null}
	property int lastState: 0

	property var popupInfo: {null}

	onVisibleChanged: {

		if(visible === true) {
			console.log("Page PG_popUp entered")
		}
	}

	function menuPressed() {
		pum.deletePopUp()
	}

	function upPressed() {
	}

	function downPressed() {
	}

	function enterPressed() {
	}

	//Handle "lastPage" and "lastState" variables
	Connections {
		target: backEnd

		onStateChanged: {
			if (backEnd.state !== MyAppState.POPUP && popUpID.lastState !== state) {
				popUpID.lastState = state;
			}
			if (pum.size() !== 0) {
				backEnd.setState(MyAppState.POPUP);
			}

			if (pum.size() === 0) {
				pg_popUp.visible = false;
			}
		}

		onCurrentPageChanged: {
			if (backEnd.currentPage !== pg_popUp && popUpID.lastPage !== currentPage)
				popUpID.lastPage = currentPage;

			if (pum.size() !== 0) {
				popUpID.lastPage.visible = true;
				backEnd.setCurrentPage(pg_popUp);
			}

			if (pum.size() === 0) {
				pg_popUp.visible = false;
			}
		}
	}

	// Handle display of pop-ups
	Connections {
		target: pum

		onFirstPopUpChanged: {
			// if no more popup to display, pop-up page disappears and the user is taken back to the last current page
			if (pum.size() === 0 ) {
				pg_popUp.visible = false;
				if (backEnd.currentPage === pg_popUp) {

					popUpID.lastPage.visible = true;
					backEnd.setCurrentPage(popUpID.lastPage);
					popUpID.lastPage = null;
				}
				if (backEnd.state === MyAppState.POPUP) {
					backEnd.setState(popUpID.lastState);
					popUpID.lastState = 0;
				}
				return;
			}

			// if the popup currently displayed is different from the one that should be, the correct pop-up is displayed and the other one go into the queue
			if (popUpID.popupInfo !== pum.getPopUpToDisplay() || !popUpID.popupInfo) {
				popUpID.popupInfo = pum.getPopUpToDisplay();
				timeoutPopUp.stop();
				timeoutPopUp.interval = popupInfo.duration
				timeoutPopUp.restart();
				if (backEnd.currentPage !== pg_popUp) {
					popUpID.lastPage = backEnd.currentPage;
				}
				if (backEnd.state !== MyAppState.POPUP) {
					popUpID.lastState = backEnd.state;
				}
				backEnd.setState(MyAppState.POPUP);
				backEnd.setCurrentPage(pg_popUp);
				pg_popUp.visible = true;
			}
		}
	}

	Connections {
		target: errorManager

		onNewErrorPop: {
			//In case of a new error from the MCU, the user is taken back
			// to the home page, but only if pin-input screen is not shown

			if ((backEnd.state !== MyAppState.IMMOBILIZER) &&
				(backEnd.state !== MyAppState.NEW_TRANS_PIN) &&
				(backEnd.state !== MyAppState.NEW_DRIVER_PIN) &&
				(backEnd.state !== MyAppState.NEW_OWNER_PIN) &&
				(backEnd.state !== MyAppState.ENTER_TRANS_PIN) &&
				(backEnd.state !== MyAppState.ENTER_DRIVER_PIN) &&
				(backEnd.state !== MyAppState.ENTER_OWNER_PIN) &&
				(backEnd.state !== MyAppState.ENTERED_WRONG_OWNER_PIN)) // block error popups
			{
				if (newError.dtcCode !== "MAINTENANCE") {
					if (backEnd.currentPage !== pg_popUp) {
						backEnd.currentPage.visible = false;
					}
					backEnd.setState(MyAppState.MAIN)
					backEnd.setCurrentPage(pg_home)
					pg_home.visible = true;
					comp_navigationBar.hideEnter = true;
					pg_home.revertPtoSetting(true);
					pgHeader.visible = true
					pgHeader.mainMenu = true
				}

				// create a pop-up according to the new DTC
				var sourcePicture = newError.priority === 1 ? "qrc:/graphics/Popups/2.2 Warning pop-up.png" : newError.priority === 2 ? "qrc:/graphics/Popups/2.3 Caution pop-up.png" : "qrc:/graphics/Popups/2.7 Maintenance pop-up.png";
				pum.addPopUp(sourcePicture, qsTrId(newError.textToDisplayLabel), newError.priority , newError.buzzerPattern);
			}
		}
	}

	Image {
		id: popUpPict
		source: popupInfo && popupInfo.pictSource ? popupInfo.pictSource : ""
		fillMode: Image.Pad
		anchors.horizontalCenter: parent.horizontalCenter
		anchors.verticalCenter: parent.verticalCenter
		visible: popupInfo ? true : false
		Text {
			id: title
			text: popupInfo && popupInfo.errorMessage ? popupInfo.errorMessage : "none"
			font.pixelSize: 14
			font.family: systemFont
			color:  "white"
			wrapMode: Text.WordWrap
			width: parent.width
			maximumLineCount: 3
			horizontalAlignment: Text.AlignHCenter
			anchors {
				top: parent.top
				left: parent.left
				right: parent.right
			}
			leftPadding: 12
			rightPadding: 12
			topPadding: 92
		}
	}

	Timer {
		id: timeoutPopUp
		running: false
		repeat: false
		interval: 1000
		onTriggered: {
			if (popupInfo) {
				if (pum.getCutOffLever() === true && popupInfo && popupInfo.pictSource === "qrc:/graphics/Popups/2.5 Cut off pop-up.png") {
					timeoutPopUp.start();
					return;
				} else {
					popupInfo = null;
					pum.deletePopUp();
				}
			}
		}
	}

//    Timer {
//        id: antiSoftBlock
//        running: true
//        repeat: true
//        interval: 10000
//        onTriggered: {
//            if (popupInfo && timeoutPopUp.running === false) {
//                popupInfo = null;
//                pum.deletePopUp();
//            }
//        }
//    }
}

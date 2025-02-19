import QtQuick 2.0

Item {
	id: buzzerManager

	property int buzzerPattern: 0
	property var currentBuzzer: null
	property int volumeON: 4
	property bool nextPauseIsLong: false
	property int nbBeep: 0
	property bool nextFreqIsLow: false

	property bool bSupressBuzzerDTC: dm.supressBuzzerDtc === 1 ? true : false;
	property bool bSupressBuzzerFlashingLight: dm.supressBuzzerFlashingLight === 1 ? true : false;

	// Get buzzer pattern when a DTC or a low battery alert is triggered
	Timer {
		id: buzzDetector
		interval: 4000
		running: true
		repeat: true
		onTriggered: {
			interval = 200;
			var newBuzzer = errorManager.getBuzzerPattern();

			if (!currentBuzzer || currentBuzzer.code !== newBuzzer.code ) {
				if (buzzerManager.currentBuzzer && buzzerManager.currentBuzzer.buzzPattern === 3) {
					errorManager.setBeepsDone(buzzerManager.currentBuzzer.code, true);
				}
				currentBuzzer = newBuzzer;
				buzzerManager.buzzerPattern = 0;
				buzzerManager.buzzerPattern = currentBuzzer.buzzPattern;
			}
		}
	}

	function stopPattern7()
	{
		pattern7.stop()
		buzzerHandler.setFreq(4000)
		buzzerManager.buzzerPattern = 0
	}

	function isPattern7running()
	{
		return pattern7.running
	}

	// Get buzzer when a new pop up is triggered
	Connections {
		target: pum

		onFirstPopUpChanged: {
			if (pum.size() === 0 )
				return;

			var popUpData = pum.getPopUpToDisplay();
			if (popUpData && popUpData.buzzerType && (popUpData.buzzerType === 4 || popUpData.buzzerType === 5) && buzzerManager.buzzerPattern === 0 && pg_listIcon.cautionTonesEnabled === true) {
				buzzerManager.buzzerPattern = popUpData.buzzerType
			}
		}
	}

	//emit a buzz according to buzzerManager.buzzerPattern
	onBuzzerPatternChanged: {
		buzzerHandler.trigger = false;
		pattern2.stop();
		pattern2.interval = 500;
		pattern3.stop();
		pattern3.interval = 500;
		pattern45.stop();
		pattern6.stop();
		pattern7.stop();
		buzzerManager.nbBeep = 0;
		buzzerManager.nextPauseIsLong = false;
		nextFreqIsLow = true
		//buzzerHandler.setFreq(4000)

		if (buzzerManager.buzzerPattern === 1) {
			console.log("buzzer pattern 1")
			buzzerHandler.trigger = !bSupressBuzzerDTC; // true;
		} else if (buzzerManager.buzzerPattern === 2) {
			console.log("buzzer pattern 2")
			if (!bSupressBuzzerDTC) {
				buzzerHandler.trigger = true;
				pattern2.restart();
			}
		} else if (buzzerManager.buzzerPattern === 3) {
			console.log("buzzer pattern 3")
			if (!bSupressBuzzerDTC) {
				buzzerHandler.trigger = true;
				pattern3.restart();
			}
		} else if (buzzerManager.buzzerPattern === 4 || buzzerManager.buzzerPattern === 5) {
			console.log("buzzer pattern 45")
			if (!bSupressBuzzerDTC) {
				buzzerHandler.trigger = true;
				pattern45.restart();
			}
		} else if (buzzerManager.buzzerPattern === 6) {
			// buzzerPattern 6 für Start-Ton and Pop-Ups
			console.log("buzzer pattern 6")
			if (!bSupressBuzzerDTC) {
				buzzerHandler.trigger = true;
				pattern6.restart();
			}
		}
		else if (buzzerManager.buzzerPattern === 7) {
			console.log("buzzer pattern 7")

			if (!bSupressBuzzerFlashingLight) {
				buzzerHandler.setFreq(1500)
				buzzerHandler.trigger = true;
				pattern7.restart();
			}
		}
	}

	Timer {
		id: pattern2

		running: false
		interval: 500
		repeat: true
		onTriggered: {
			if (buzzerHandler.trigger === false) {
				buzzerHandler.trigger = true;
				pattern2.interval = 500;
			} else if (buzzerHandler.trigger === true) {
				buzzerHandler.trigger = false;
				if (buzzerManager.nextPauseIsLong) {
					pattern2.interval = 500;
					buzzerManager.nextPauseIsLong = false;
				} else {
					pattern2.interval = 200;
					buzzerManager.nextPauseIsLong = true;
				}
			}
			pattern2.restart();
		}
	}

	Timer {
		id: pattern3

		running: false
		interval: 500
		repeat: true
		onTriggered: {
			if (buzzerManager.nbBeep >= 4) {
				if (buzzerManager.currentBuzzer)
					errorManager.setBeepsDone(buzzerManager.currentBuzzer.code, true)
				buzzerManager.buzzerPattern = 0;
				return
			}

			if (buzzerHandler.trigger === false) {
				buzzerHandler.trigger = true;
				pattern3.interval = 500;
			} else if (buzzerHandler.trigger === true) {
				buzzerManager.nbBeep++;
				buzzerHandler.trigger = false;
				if (buzzerManager.nextPauseIsLong) {
					pattern3.interval = 500;
					buzzerManager.nextPauseIsLong = false;
				} else {
					pattern3.interval = 200;
					buzzerManager.nextPauseIsLong = true;
				}
			}
			pattern3.restart();
		}
	}

	Timer {
		id: pattern45

		running: false
		interval: 150
		repeat: false
		triggeredOnStart: false;
		onTriggered: {
			if (buzzerManager.currentBuzzer) {
				errorManager.setBeepsDone(buzzerManager.currentBuzzer.code, true);
			}
			buzzerManager.buzzerPattern = 0;
		}
	}

	// pattern used for autocontrol
	Timer {
		id: pattern6

		running: false
		interval: 500
		repeat: false
		triggeredOnStart: false;
		onTriggered: {
			buzzerManager.buzzerPattern = 0;
		}
	}

	Timer {
		id: pattern7

		running: false
		interval: 500
		repeat: true
		onTriggered: {
			if (buzzerHandler.trigger === false) {
				buzzerHandler.trigger = true;
				//pattern7.interval = 500;
			} else if (buzzerHandler.trigger === true) {
				buzzerHandler.trigger = false;
				if (buzzerManager.nextFreqIsLow) {
					//console.log("low freq")
					//pattern7.interval = 500;
					buzzerHandler.setFreq(1000)
					buzzerManager.nextFreqIsLow = false;
				} else {
					//console.log("high freq")
					//pattern7.interval = 500;
					buzzerHandler.setFreq(1500)
					buzzerManager.nextFreqIsLow = true;
				}
			}
			//pattern7.restart();
		}
	}
}

import QtQuick 2.0
import MyQmlModule 1.0

Rectangle {
	id: intervalChangeContainer

	height: 80
	color: parent.color

	function setThousands(value){
		if(value >= 0 && value <= 9){
			thousandsContainer.currentNumber = value
		}
	}

	function setHundreds(value){
		if(value >= 0 && value <= 9){
			hundredsContainer.currentNumber = value
		}
	}

	function setTens(value){
		if(value >= 0 && value <= 9){
			tensContainer.currentNumber = value
		}
	}

	function setUnits(value){
		if(value >= 0 && value <= 9){
			unitsContainer.currentNumber = value
		}
	}

	function selectThousands(value) {
		thousandsContainer.isCurrent = value;
	}

	function setDoneThousands(value) {
		thousandsContainer.isDone = value
	}

	function increaseThousands() {
		if (backEnd.state === MyAppState.NEW_TRANS_PIN) {
			thousandsContainer.currentNumber = 0;
		}
		else if (((backEnd.state === MyAppState.NEW_OWNER_PIN) ||
			(backEnd.state === MyAppState.NEW_DRIVER_PIN)) &&
				(thousandsContainer.currentNumber === 9))
		{
			thousandsContainer.currentNumber = 1
		}
		else {
			thousandsContainer.currentNumber = (thousandsContainer.currentNumber + 1) % 10
		}
	}

	function decreaseThousands() {
		if (backEnd.state === MyAppState.NEW_TRANS_PIN) {
			thousandsContainer.currentNumber = 0;
		}
		else if (((backEnd.state === MyAppState.NEW_OWNER_PIN) ||
				(backEnd.state === MyAppState.NEW_DRIVER_PIN)) &&
				(thousandsContainer.currentNumber === 1))
		{
			thousandsContainer.currentNumber = 9
		}
		else {
			thousandsContainer.currentNumber = (thousandsContainer.currentNumber - 1 + 10) % 10
		}
	}

	function selectHundreds(value) {
		hundredsContainer.isCurrent = value;
	}

	function setDoneHundreds(value) {
		hundredsContainer.isDone = value
	}

	function increaseHundreds() {
		hundredsContainer.currentNumber = (hundredsContainer.currentNumber + 1) % 10
	}

	function decreaseHundreds() {
		hundredsContainer.currentNumber = (hundredsContainer.currentNumber - 1 + 10) % 10
	}

	function selectTens(value) {
		tensContainer.isCurrent = value;
	}

	function setDoneTens(value) {
		tensContainer.isDone = value
	}

	function increaseTens() {
		tensContainer.currentNumber = (tensContainer.currentNumber + 1) % 10
	}

	function decreaseTens() {
		tensContainer.currentNumber = (tensContainer.currentNumber - 1 + 10) % 10
	}

	function selectUnits(value) {
		unitsContainer.isCurrent = value;
	}

	function setDoneUnits(value) {
		unitsContainer.isDone = value
	}

	function increaseUnits() {
		unitsContainer.currentNumber = (unitsContainer.currentNumber + 1) % 10
	}

	function decreaseUnits() {
		unitsContainer.currentNumber = (unitsContainer.currentNumber - 1 + 10) % 10
	}

	function validatePin() {
		thousandsContainer.confirmValue()
		hundredsContainer.confirmValue()
		tensContainer.confirmValue()
		unitsContainer.confirmValue()

		var validatedPin = thousandsContainer.currentNumber * 1000  + hundredsContainer.currentNumber * 100 + tensContainer.currentNumber * 10 + unitsContainer.currentNumber
		return validatedPin
	}

	function resetPin(){
		if ((backEnd.state === MyAppState.NEW_OWNER_PIN) ||
			(backEnd.state === MyAppState.NEW_DRIVER_PIN))
		{
			thousandsContainer.currentNumber = 1
		}
		else
		{
			thousandsContainer.currentNumber = 0

		}

		hundredsContainer.currentNumber = 0
		tensContainer.currentNumber = 0
		unitsContainer.currentNumber = 0

		thousandsContainer.isCurrent = true
		hundredsContainer.isCurrent = false
		tensContainer.isCurrent = false
		unitsContainer.isCurrent = false

		thousandsContainer.isDone = false
		hundredsContainer.isDone = false
		tensContainer.isDone = false
		unitsContainer.isDone = false

		if (backEnd.state === MyAppState.NEW_TRANS_PIN) {
			// im Falle eines States NEW_TRANS_PIN, kann die erste Null bereits eingeloogt werden
			// --> @TODO: erste Null gleich einloggen, und weiter zur zweiten Stelle
		}

	}

	Rectangle {
		id: pinComboBoxContainer
		height: 80
		color: parent.color

		Comp_pinBox {
			id: thousandsContainer
			anchors {
				left: pinComboBoxContainer.left
				leftMargin: 15
				verticalCenter: parent.verticalCenter
			}
			isCurrent: true
			currentNumber: 0
		}

		Comp_pinBox {
			id: hundredsContainer
			anchors {
				left: thousandsContainer.right
				leftMargin: 5
				verticalCenter: parent.verticalCenter
			}
			currentNumber: 0
		}

		Comp_pinBox {
			id: tensContainer
			anchors {
				left: hundredsContainer.right
				leftMargin: 5
				verticalCenter: parent.verticalCenter
			}
			currentNumber: 0
		}

		Comp_pinBox {
			id: unitsContainer
			anchors {
				left: tensContainer.right
				leftMargin: 5
				verticalCenter: parent.verticalCenter
			}
			currentNumber: 0
		}
	}
}

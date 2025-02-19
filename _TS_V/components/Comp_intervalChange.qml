import QtQuick 2.0

Rectangle {
    id: intervalChangeContainer

    width: parent.width
    height: parent.height
    color: parent.color

    function selectThousands(value) {
        thousandsContainer.isCurrent = value;
    }

    function increaseThousands() {
        thousandsContainer.currentNumber = (thousandsContainer.currentNumber + 1) % 10
    }

    function decreaseThousands() {
        thousandsContainer.currentNumber = (thousandsContainer.currentNumber - 1 + 10) % 10
    }

    function selectHundreds(value) {
        hundredsContainer.isCurrent = value;
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

    function increaseTens() {
        tensContainer.currentNumber = (tensContainer.currentNumber + 1) % 10
    }

    function decreaseTens() {
        tensContainer.currentNumber = (tensContainer.currentNumber - 1 + 10) % 10
    }

    function selectUnits(value) {
        unitsContainer.isCurrent = value;
    }

    function increaseUnits() {
        unitsContainer.currentNumber = (unitsContainer.currentNumber + 1) % 10
    }

    function decreaseUnits() {
        unitsContainer.currentNumber = (unitsContainer.currentNumber - 1 + 10) % 10
    }

    function validateInterval() {
        thousandsContainer.confirmValue()
        hundredsContainer.confirmValue()
        tensContainer.confirmValue()
        unitsContainer.confirmValue()

        var validatedInterval = thousandsContainer.currentNumber * 1000  + hundredsContainer.currentNumber * 100 + tensContainer.currentNumber * 10 + unitsContainer.currentNumber
        return validatedInterval
    }

    function cancelInterval() {
        thousandsContainer.cancelValue()
        hundredsContainer.cancelValue()
        tensContainer.cancelValue()
        unitsContainer.cancelValue()
    }

    function assignCurrentNumbers(currentDigits) {
        thousandsContainer.currentNumber = currentDigits[0]
        hundredsContainer.currentNumber = currentDigits[1]
        tensContainer.currentNumber = currentDigits[2]
        unitsContainer.currentNumber = currentDigits[3]
    }


    Rectangle {
        id: intervalContainer

        width: parent.width
        height: 65
        color: parent.color

        Comp_boxNumber {
            id: thousandsContainer
            anchors {
                left: intervalContainer.left
                leftMargin: 40
                verticalCenter: parent.verticalCenter
            }
            height: 40
            isArrows: true
            isCurrent: true
            currentNumber: 0
        }

        Comp_boxNumber {
            id: hundredsContainer
            anchors {
                left: thousandsContainer.right
                leftMargin: 5
                verticalCenter: parent.verticalCenter
            }
            height: 40
            isArrows: true
            currentNumber: 0
        }

        Comp_boxNumber {
            id: tensContainer
            anchors {
                left: hundredsContainer.right
                leftMargin: 5
                verticalCenter: parent.verticalCenter
            }
            height: 40
            isArrows: true
            currentNumber: 0
        }

        Comp_boxNumber {
            id: unitsContainer
            anchors {
                left: tensContainer.right
                leftMargin: 5
                verticalCenter: parent.verticalCenter
            }
            height: 40
            isArrows: true
            currentNumber: 0
        }

        Text {
            id: separatorText
            text: "h"
            color: color_white
            font.pixelSize: 20
            font.family: systemFont
            anchors {
                left: unitsContainer.right
                leftMargin: 5
                bottom: unitsContainer.bottom
            }
        }
    }
}

import QtQuick 2.6

Item {
	id: consumptionGaugeItem
	width: 320
	height: 240 - 2 * backEnd.currentConfig.headerHeight - 10
	y: backEnd.currentConfig.headerHeight

	property var consumptionControltab: [0, 12, 25, 37, 50, 62, 75, 87, 100]
	property int consumptionTabIndex: 0
	property int consumptionControl: consumptionControltab[0]
	property bool autoControlRampUp: true
	property bool mainMenu: false                           // display design for main menu or sub menu
	property int consumption: pg_home.autoControlActive ? consumptionControl
														: canError18FFCB47 ? 125
																		   : dataEngine.gaugeElectricCurrentConsumption.value >= 131 ? dataEngine.gaugeElectricCurrentConsumption.value - 256
																																	 : dataEngine.gaugeElectricCurrentConsumption.value > 127 ? -125
																																															   : dataEngine.gaugeElectricCurrentConsumption.value
	property double angleNeedle: -50 * (consumption + 125)/250.0 // Angle of the pointer indicating the current consumption

	Timer {
		id: autoControlTimer
		interval: pg_home.autoControlDuration/18
		running: true
		repeat: true
		onTriggered: {
			if(pg_home.autoControlActive === true)
			{
				if(consumptionTabIndex == 8)
				{
					autoControlRampUp = false
				}

				if(autoControlRampUp === true)
				{
					consumptionTabIndex += 1
				}
				else
				{
					if(consumptionTabIndex >= 1)
					{
						consumptionTabIndex -= 1
					}
				}

				consumptionControl = consumptionControltab[consumptionTabIndex]*250/100 - 125
			}
		}
	}

	// Update the angle of the pointer each time the current consumption change
	onConsumptionChanged: {
			angleNeedle = -50 * (consumption + 125)/250.0
	}

	// consumption gauge
	Image {
		id: consumptionGaugeIcon
		x: parent.width/2 + 75
		y: 68  - backEnd.currentConfig.headerHeight
		width: 60
		height: 115
		source: "qrc:/graphics/03_Gauges PNG/03_Gauges PNG 25x25/3.12_Gauge Recuparation_60x115_V1.png"
		fillMode: Image.Pad
		visible: consumptionGaugeItem.mainMenu
	}

	// Image of an electric motor on the right of the gauge
	Image {
		id: eletricMotorIcon
		x: parent.width/2 + 120
		y: parent.height/2 - eletricMotorIcon.height
		width: 25
		height: 25
		source: "qrc:/graphics/02_Main_Icons PNG/02_Main_Icons PNG 25x25/2.98 Electric Motor_WH.png"
		fillMode: Image.Pad
		visible: consumptionGaugeItem.mainMenu
	}

	// Image of the pointer used to show the current consumption
	Image {
		id: pointerIcon
		x: parent.width/2
		y: 172  - backEnd.currentConfig.headerHeight
		width: 130
		height: 8
		source: "qrc:/graphics/03_Gauges PNG/3.11_Pointer 2.png"
		fillMode: Image.Pad
		visible: consumptionGaugeItem.mainMenu
		transform: Rotation { origin.x: 0; origin.y: pointerIcon.height/2 ; axis {x: 0; y: 0; z: 1} angle: angleNeedle}

	}

	// Letter C (Consuming) at the top of the consumption gauge
	Item {
		id: textCContainer
		x: consumptionGaugeIcon.x - 12
		y: consumptionGaugeIcon.y - 7

		Text {
			id: textC
			text: "C"
			font.pixelSize: 15
			font.family: systemFont
			color: color_white
			visible: consumptionGaugeItem.mainMenu
		}
	}

	// Letter G (Generating) at the bottom of the consumption gauge
	Item {
		id: textGContainer
		x: consumptionGaugeIcon.x + consumptionGaugeIcon.width + 6
		y: consumptionGaugeIcon.y + consumptionGaugeIcon.height - 14

		Text {
			id: textG
			text: "G"
			font.pixelSize: 15
			font.family: systemFont
			color: color_white
			visible: consumptionGaugeItem.mainMenu
		}
	}
}

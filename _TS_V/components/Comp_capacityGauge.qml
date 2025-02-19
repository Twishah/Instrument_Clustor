import QtQuick 2.6

Item {
	id: capacityGaugeItem
	width: 320
	height: 240 - 2 * backEnd.currentConfig.headerHeight - 10
	y: backEnd.currentConfig.headerHeight

	property var fuelLevelControltab: [0, 12, 25, 37, 50, 62, 75, 87, 100]
	property int fuelLevelTabIndex: 0
	property int fuelLevelControl: fuelLevelControltab[0]
	property bool autoControlRampUp: true
	property double fuelLevel: pg_home.autoControlActive ? fuelLevelControl : canError18FFCE47 ? 0 : dataEngine.fuelLevel.value > 100 ? 0 : dataEngine.fuelLevel.value
	property double batteryLevel: pg_home.autoControlActive ? fuelLevelControl : canError18FFCB47 ? 0 : dataEngine.sOC.value  > 100 ? 0 : dataEngine.sOC.value
	property bool mainMenu: false                           // display design for main menu or sub menu
	property double gaugeMaxAngle: 50.0
	property double angleNeedle: isV7 ? -180 + (gaugeMaxAngle * fuelLevel/100.0) : -180.0 + (gaugeMaxAngle * batteryLevel/100.0) // angle of the pointer
	property string v8ePictoSource: "qrc:/graphics/03_Gauges PNG/03_Gauges PNG 25x25/3.08_Battery Symbol white.png"
	property int socStatusError: dataEngine.ind_SOC_Status_Error.value
	property int socStatusWarning: dataEngine.ind_SOC_Status_Warning.value

	Timer {
		id: autoControlTimer
		interval: pg_home.autoControlDuration/18
		running: true
		repeat: true
		onTriggered: {
			if(pg_home.autoControlActive === true)
			{
				if(fuelLevelTabIndex == 8)
				{
					autoControlRampUp = false
				}

				if(autoControlRampUp === true)
				{
					fuelLevelTabIndex += 1
				}
				else
				{
					if(fuelLevelTabIndex >= 1)
					{
						fuelLevelTabIndex -= 1
					}
				}

				fuelLevelControl = fuelLevelControltab[fuelLevelTabIndex]
			}
		}
	}

	onBatteryLevelChanged: {
		if(!isV7){
			angleNeedle = -180.0 + (gaugeMaxAngle * batteryLevel/100.0)
		}
	}

	onFuelLevelChanged: {
		if(isV7){
			angleNeedle = -180.0 + (gaugeMaxAngle * fuelLevel/100.0)
		}
	}

	onSocStatusErrorChanged:
	{
		v8ePictoSource = socStatusError !== 0 ? "qrc:/graphics/03_Gauges PNG/03_Gauges PNG 25x25/3.08_Battery Symbol RD.png"
										 : socStatusWarning !== 0 ? "qrc:/graphics/03_Gauges PNG/03_Gauges PNG 25x25/3.08_Battery Symbol YE.png"
														   :  "qrc:/graphics/03_Gauges PNG/03_Gauges PNG 25x25/3.08_Battery Symbol white.png"
	}

	onSocStatusWarningChanged:
	{
		v8ePictoSource = socStatusError !== 0 ? "qrc:/graphics/03_Gauges PNG/03_Gauges PNG 25x25/3.08_Battery Symbol RD.png"
										 : socStatusWarning !== 0 ? "qrc:/graphics/03_Gauges PNG/03_Gauges PNG 25x25/3.08_Battery Symbol YE.png"
														   :  "qrc:/graphics/03_Gauges PNG/03_Gauges PNG 25x25/3.08_Battery Symbol white.png"
	}

	// Image of the fuel gauge
	Image {
		id: capacityGaugeIcon
		x: 24
		y: 68  - backEnd.currentConfig.headerHeight
		width: 60
		height: 115
		source: "qrc:/graphics/03_Gauges PNG/3.18_Gauge fuel_60x115_full.png"
		fillMode: Image.Pad
		visible: capacityGaugeItem.mainMenu
	}

	// Image of the gas station for V7 and battery for V8e
	Comp_indicatorLight{

			id: capacitySymbolWhiteIcon
			x: 12
			y: parent.height/2 - capacitySymbolWhiteIcon.height
			width: isV7 ? 20 : 24
			height: isV7 ? 20 : 24
			source: isV7 ? "qrc:/graphics/03_Gauges PNG/3.07_fuel symbol white.png" : pg_home.autoControlActive ? "qrc:/graphics/03_Gauges PNG/03_Gauges PNG 25x25/3.08_Battery Symbol white.png" : v8ePictoSource
			value: 1//socStatusError !== 0 ? socStatusError : socStatusWarning
			valueBackup: 1//socStatusError !== 0 ? socStatusError : socStatusWarning
			canError: false
	}

	// Image of the pointer for the fuel gauge
	Image {
		id: pointerIcon
		x: parent.width/2
		y: 172  - backEnd.currentConfig.headerHeight
		width: 130
		height: 8
		source: "qrc:/graphics/03_Gauges PNG/3.11_Pointer 2.png"
		fillMode: Image.Pad
		visible: capacityGaugeItem.mainMenu
		transform: Rotation { origin.x: 0; origin.y: pointerIcon.height/2 ; axis {x: 0; y: 0; z: 1} angle: angleNeedle}
	}

	// Item for the letter F (Full) at the top of the fuel gauge
	Item {
		id: textFContainer
		x: capacityGaugeIcon.x + capacityGaugeIcon.width + 3
		y: capacityGaugeIcon.y - 7

		Text {
			id: textF
			text: "F"
			font.pixelSize: 15
			font.family: systemFont
			color: color_white
			visible: capacityGaugeItem.mainMenu
		}
	}

	// Item for the letter E (Empty) at the bottom of the fuel gauge
	Item {
		id: textEContainer
		x: capacityGaugeIcon.x - 15
		y: capacityGaugeIcon.y + capacityGaugeIcon.height - 14

		Text {
			id: textE
			text: "E"
			font.pixelSize: 15
			font.family: systemFont
			color: color_white
			visible: capacityGaugeItem.mainMenu
		}
	}
}

import QtQuick 2.6

Item {
	id: powerGaugeItem
	width: 320
	height: 240 - 2 * backEnd.currentConfig.headerHeight - 10
	y: backEnd.currentConfig.headerHeight

	property bool mainMenu: false                           // display design for main menu or sub menu
	property var velocityControltab: [0, 12, 25, 37, 50, 62, 75, 87, 100]
	property int velocityTabIndex: 0
	property int velocityControl: velocityControltab[0]
	property bool autoControlRampUp: true
	property double machineSpeed: pg_home.autoControlActive ? velocityControl : canError18FFCF47 ? 40 : dataEngine.machineVelocity.value > 40 ? 40 : dataEngine.machineVelocity.value
	property double angleNeedle: 0                // current angle of the needle
	property bool isKmh: dm.speedUnitIsKmh

	Timer {
		id: autoControlTimer
		interval: pg_home.autoControlDuration/18
		running: true
		repeat: true
		onTriggered: {
			if(pg_home.autoControlActive === true)
			{
				if(velocityTabIndex == 8)
				{
					autoControlRampUp = false
				}

				if(autoControlRampUp === true)
				{
					velocityTabIndex += 1
				}
				else
				{
					if(velocityTabIndex >= 1)
					{
						velocityTabIndex -= 1
					}
				}

				velocityControl = velocityControltab[velocityTabIndex]*40/100
			}
		}
	}

	onMachineSpeedChanged:
	{
		angleNeedle = 180*machineSpeed/40.0
	}

	Image {
		id: gaugeIcon
		x: parent.width/2 - width/2
		y: 66  - backEnd.currentConfig.headerHeight
		width: 223
		height: 118
		source: isKmh ? "qrc:/graphics/03_Gauges PNG/03_Gauges PNG 25x25/3.27.1_Gauge_speed_0-40kmH_V3.png" : "qrc:/graphics/03_Gauges PNG/03_Gauges PNG 25x25/3.27.1_Gauge_speed_mph_V2.png"
		fillMode: Image.Pad
		visible: powerGaugeItem.mainMenu
	}

	Text {
		id: kmhIcon
		x: parent.width/2 - width/2
		anchors.bottom: dotIcon.top
		color:  "white"
		font.pixelSize: 18
		font.family: systemFont
		text: isKmh ? "kmh" : "mph"
		visible: powerGaugeItem.mainMenu
	}

	Image {
		id: pointerIcon
		x: parent.width/2 - width/2
		y: dotIcon.y + 4
		width: 223
		height: 14
		source: "qrc:/graphics/03_Gauges PNG/3.02_Pointer 1.png"
		fillMode: Image.Pad
		visible: powerGaugeItem.mainMenu
		transform: Rotation { origin.x: pointerIcon.width/2; origin.y: pointerIcon.height/2; axis {x: 0; y: 0; z: 1} angle: angleNeedle}
	}

	Image {
		id: dotIcon
		x: parent.width/2 - width/2
		y: 166  - backEnd.currentConfig.headerHeight
		width: 24
		height: 24
		source: "qrc:/graphics/03_Gauges PNG/3.01_Dot.png"
		fillMode: Image.Pad
		visible: powerGaugeItem.mainMenu
	}
}

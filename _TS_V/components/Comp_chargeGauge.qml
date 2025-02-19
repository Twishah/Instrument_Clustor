/******************************************************************************
 * Gauge component
 ******************************************************************************/

import QtQuick 2.6

Item {
	id: base
	width: chargeGaugePict.width
	height: chargeGaugePict.height

	property int gaugeFill: 0
	property int chargeTabIndex: 0
	property double fuelLevel: canError18FFCE47 ? 0 : dataEngine.fuelLevel.value
	property double batteryLevel: canError18FFCB47 ? 0 : dataEngine.sOC.value
	property double charge: checkMachineType === true ? 0 : isV7 ? fuelLevel : batteryLevel
	property string v8ePictoSource: "qrc:/graphics/03_Gauges PNG/03_Gauges PNG 25x25/3.08_Battery Symbol white.png"
	property int socStatus: dataEngine.ind_SOC_Status.value
	property int gaugeBorder : 3

	onChargeChanged: {
		gaugeFill = charge <= 0 ? 0 :
					charge <= 14 ? 1 :
					charge <= 27 ? 2 :
					charge <= 40 ? 3 :
					charge <= 52 ? 4 :
					charge <= 64 ? 5 :
					charge <= 76 ? 6 :
					charge <= 88 ? 7 : 8;
	}

	onSocStatusChanged:
	{
		v8ePictoSource = socStatus === 0 ? "qrc:/graphics/Home/Icons/7.2 Main battery - white.png"
										 : socStatus === 1 ? "qrc:/graphics/Home/Icons/7.3 Main battery - yellow.png"
														   : socStatus === 2 ? "qrc:/graphics/Home/Icons/7.4 Main battery - red.png"
																			 : v8ePictoSource
	}

	Rectangle {
		id: backgroundEmptyGauge
		height: chargeGaugePict.height - 3
		width: chargeGaugePict.width - 2
		x: chargeGaugePict.x + 1
		y: chargeGaugePict.y + 2
		color: "#ff353434"
	}

	Repeater {
		id: gaugeRepeater
		model: 8
		delegate: Rectangle {
			id: gaugeBar
			x: chargeGaugePict.x + 2
			y: index <= 4 ? 126 - height * index : 126 - height * (index - 4) - (18 * 4)
			width: 12
			height: index <= 4 ? 18 : 17
			color: index === 0 && base.gaugeFill > 0 ? "#ffE31C26" : base.gaugeFill > index ? "white" : "transparent"
		}
	}

	Image {
		id: chargeGaugePict
		anchors {
			top: parent.top
			left: parent.left
		}
		source: "qrc:/graphics/Home/Gauges/6.1 SOC Gauge 0-segment.png"
		fillMode: Image.Pad
	}

	Image {
		id: errorIconPict
		x: chargeGaugePict.x + chargeGaugePict.width + 5
		y: base.height / 2 - 15
		source: checkMachineType === true ? "" : isV7 ? "qrc:/graphics/03_Gauges PNG/3.07_fuel symbol white.png" : base.v8ePictoSource
		fillMode: Image.Pad
	}

	Image {
		id: fullIconPict
		anchors {
			top: parent.top
			left: chargeGaugePict.right
			leftMargin: 4
			topMargin: -1
		}
		source: "qrc:/graphics/Home/Gauges/6.13 SOC Gauge - Full.png"
		fillMode: Image.Pad
	}

	Image {
		id: emptyIconPict
		anchors {
			bottom: parent.bottom
			left: chargeGaugePict.right
			leftMargin: 4
			bottomMargin: -3
		}
		source: "qrc:/graphics/Home/Gauges/6.12 SOC Gauge - Empty.png"
		fillMode: Image.Pad
	}
}

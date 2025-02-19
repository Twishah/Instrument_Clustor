import QtQuick 2.6

Item {
	id: pictoController
	width: 65
	height: backEnd.currentConfig.headerHeight * 2

	property bool isAutocontrolActive: homeID.autoControlActive
	property bool toggle: true;

	property int leftSpacing: 8
	property int topSpacing: 2
	property int pictoSize: 25
	property int pictoSpacing: 10

	onToggleChanged: {
		pict1Update.updateToggle(toggle);
		pict2Update.updateToggle(toggle);
		pict3Update.updateToggle(toggle);
		pict4Update.updateToggle(toggle);
		pict5Update.updateToggle(toggle);
		pict6Update.updateToggle(toggle);
		pict7Update.updateToggle(toggle);
		pict8Update.updateToggle(toggle);
		pict9Update.updateToggle(toggle);
	}

	Comp_noticePicto{
		   id: pict1Update

		   x: leftSpacing
		   y: topSpacing

		   nbSignal: 3

		   signal1: isAutocontrolActive ? 1 : dataEngine.ind_Alternator.value
		   signal1Source: "qrc:/graphics/03_Gauges PNG/03_Gauges PNG 25x25/3.29_Battery_charge_indicator_light_RD.png"
		   signal1canError: canError18FFC047

		   signal2: dataEngine.ind_AlternatorFailure.value
		   signal2Source: "qrc:/graphics/03_Gauges PNG/03_Gauges PNG 25x25/3.46_Battery_failure_RD.png"
		   signal2canError: canError18FFC047

		   signal3: dataEngine.ind_EngPwrReductionDueToTemp.value
		   signal3Source: "qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 25x25/6.145_Electric_motor_over_temperature_RD.png"
		   signal3canError: canError18FFC447

		   visible: true
	   }

	Comp_noticePicto
	{
		   id: pict2Update

		   x: leftSpacing + 1*(pictoSize + pictoSpacing)
		   y: topSpacing

		   nbSignal: 2

		   signal1: isAutocontrolActive ? 1 : dataEngine.ind_CoolingTempTooHigh.value
		   signal1Source: "qrc:/graphics/02_Main_Icons PNG/02_Main_Icons PNG 25x25/2.15_Coolant temperature_RD.png"
		   signal1canError: canError18FFC047

		   signal2: dataEngine.ind_CoolingTempTooLow.value
		   signal2Source: "qrc:/graphics/02_Main_Icons PNG/02_Main_Icons PNG 25x25/2.15_Coolant temperature_BU.png"
		   signal2canError: canError18FFC047

		   visible: true
	}

	Comp_noticePicto
	{
		   id: pict3Update

		   x: leftSpacing + 2*(pictoSize + pictoSpacing)
		   y: topSpacing

		   nbSignal: 2

		   signal1: isAutocontrolActive ? 1 : dataEngine.ind_Preheating.value
		   signal1Source: "qrc:/graphics/02_Main_Icons PNG/02_Main_Icons PNG 25x25/2.100_Preheating_YE.png"
		   signal1canError: canError18FFC047

		   signal2: dataEngine.ind_ElectricEngineFailure.value
		   signal2Source: "qrc:/graphics/03_Gauges PNG/03_Gauges PNG 25x25/3.32_Electric Motor_failure_RD.png"
		   signal2canError: canError18FFC447

		   visible: true
	}

	Comp_noticePicto
	{
		   id: pict4Update

		   x: leftSpacing + 3*(pictoSize + pictoSpacing)
		   y: topSpacing

		   nbSignal: 3

		   signal1: isAutocontrolActive ? 1 : dataEngine.ind_48VBatteryFailure.value
		   signal1Source: "qrc:/graphics/03_Gauges PNG/03_Gauges PNG 25x25/3.30_Main_Battery_failure_RD.png"
		   signal1canError: canError18FFC447

		   signal2: dataEngine.ind_48VBatteryHighTemperature.value
		   signal2Source: "qrc:/graphics/03_Gauges PNG/03_Gauges PNG 25x25/3.28_Main_Battery_temperature_RD.png"
		   signal2canError: canError18FFC447

		   signal3: dataEngine.ind_48VBatteryLowTemperature.value
		   signal3Source: "qrc:/graphics/03_Gauges PNG/03_Gauges PNG 25x25/3.28_Main_Battery_temperature_BU.png"
		   signal3canError: canError18FFC447

		   visible: true
	   }

	Comp_noticePicto
	{
		   id: pict5Update

		   x: leftSpacing + 4*(pictoSize + pictoSpacing)
		   y: topSpacing

		   nbSignal: 2

		   signal1: isAutocontrolActive ? 1 : dataEngine.ind_GeneralError.value
		   signal1Source: "qrc:/graphics/02_Main_Icons PNG/02_Main_Icons PNG 25x25/2.86.1_Stop_wh.png"
		   signal1canError: canError18FFC047

		   signal2: dataEngine.ind_GeneralWarning.value
		   signal2Source: "qrc:/graphics/02_Main_Icons PNG/02_Main_Icons PNG 25x25/2.19_Warning.png"
		   signal2canError: canError18FFC047

		   visible: true
	}

	Comp_noticePicto
	{
		   id: pict6Update

		   x: leftSpacing + 5*(pictoSize + pictoSpacing)
		   y: topSpacing

		   nbSignal: 2

		   signal1: isAutocontrolActive ? 1 : dataEngine.ind_ECUFailure.value
		   signal1Source: "qrc:/graphics/03_Gauges PNG/03_Gauges PNG 25x25/3.38_ECU_failure_RD.png"
		   signal1canError: canError18FFC147

		   signal2: dataEngine.ind_TransmissionFault.value
		   signal2Source: "qrc:/graphics/03_Gauges PNG/03_Gauges PNG 25x25/3.36_Transmission_failure_RD.png"
		   signal2canError: canError18FFC047

		   visible: true
	}

	Comp_noticePicto
	{
		   id: pict7Update

		   x: leftSpacing + 6*(pictoSize + pictoSpacing)
		   y: topSpacing

		   nbSignal: 2 // TODO add electric motor failure

		   signal1: isAutocontrolActive ? 1 : dataEngine.ind_ElectricSystemFailure.value
		   signal1Source: "qrc:/graphics/03_Gauges PNG/03_Gauges PNG 25x25/3.34_Electricalsystem_malfunction_RD.png"
		   signal1canError: canError18FFC447

		   signal2: dataEngine.ind_LowRecuperation.value
		   signal2Source: "qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 25x25/6.123_Low recuperation capability_RD.png"
		   signal2canError: canError18FFC447

//           signal3: dataEngine.ind_EngPwrReductionDueToTemp.value
//           signal3Source: "qrc:/graphics/06_Menu_Symbols PNG/06_Menu_Symbols PNG 25x25/6.145_Electric_motor_over_temperature_RD.png"
//           signal3canError: 0

		   visible: true
	}

	Comp_noticePicto
	{
		   id: pict8Update

		   x: leftSpacing + 7*(pictoSize + pictoSpacing)
		   y: topSpacing

		   nbSignal: 2

		   signal1: isAutocontrolActive ? 1 : dataEngine.ind_SteeringSystemFailure.value
		   signal1Source: "qrc:/graphics/03_Gauges PNG/03_Gauges PNG 25x25/3.43_Steering_failure_RD.png"
		   signal1canError: canError18FFC047

		   signal2: dataEngine.ind_SeatSensorFailure.value
		   signal2Source: "qrc:/graphics/03_Gauges PNG/03_Gauges PNG 25x25/3.31_Seatsensor_failure_RD.png"
		   signal2canError: canError18FFC047

		   visible: true
	}

	Comp_noticePicto
	{
		   id: pict9Update

		   x: leftSpacing + 8*(pictoSize + pictoSpacing)
		   y: topSpacing

		   nbSignal: 2

		   signal1: isAutocontrolActive ? 1 : dataEngine.ind_HydraulicSystemFailure.value
		   signal1Source: "qrc:/graphics/03_Gauges PNG/03_Gauges PNG 25x25/3.41_Hydraulic_system_failure_RD.png"
		   signal1canError: canError18FFC147

		   signal2: dataEngine.ind_HydraulicOilLevel.value
		   signal2Source: "qrc:/graphics/03_Gauges PNG/03_Gauges PNG 25x25/3.42_Hydraulic_level_RD.png"
		   signal2canError: canError18FFC047

//		   signal3: dataEngine.ind_EngineCoolingFanFailure.value
//		   signal3Source: "qrc:/graphics/03_Gauges PNG/03_Gauges PNG 25x25/3.44_Engine_cooling_fan_failure_RD.png"
//		   signal3canError: canError18FFC447

		   visible: true
	}

	Timer {
		id: updatePicto

		running: isAutocontrolActive? false : true
		repeat: true
		interval: 100
		onTriggered:
		{
			pict1Update.updateValues();
			pict1Update.updateSource();

			pict2Update.updateValues();
			pict2Update.updateSource();

			pict3Update.updateValues();
			pict3Update.updateSource();

			pict4Update.updateValues();
			pict4Update.updateSource();

			pict5Update.updateValues();
			pict5Update.updateSource();

			pict6Update.updateValues();
			pict6Update.updateSource();

			pict7Update.updateValues();
			pict7Update.updateSource();

			pict8Update.updateValues();
			pict8Update.updateSource();

			pict9Update.updateValues();
			pict9Update.updateSource();
		}
	}
}

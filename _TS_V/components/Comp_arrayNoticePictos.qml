import QtQuick 2.6

Item {
	id: noticePictoController
	width: 320
	height: backEnd.currentConfig.headerHeight * 2
	visible: isV7 ? true : false

	property bool isAutocontrolActive: homeID.autoControlActive
	property bool toggle: true;

	property int leftSpacing: 5
	property int topSpacing: 5
	property int pictoSize: 40
	property int pictoSpacing: 5

	onToggleChanged: {
		pict1Update.updateToggle(toggle);
		pict2Update.updateToggle(toggle);
		pict3Update.updateToggle(toggle);
		pict4Update.updateToggle(toggle);
		pict5Update.updateToggle(toggle);
		pict6Update.updateToggle(toggle);
		pict7Update.updateToggle(toggle);
	}

	Comp_noticePicto{
		   id: pict1Update

		   x: leftSpacing
		   y: topSpacing

		   nbSignal: 1

		   signal1: isAutocontrolActive ? 1 : dataEngine.ind_ParkingBrake.value
		   signal1Source: "qrc:/graphics/01_Attention Icons PNG/01_Attention Icons PNG 40x40/1.48_Brake_RD.png"
		   signal1canError: canError18FFC047

		   visible: true
	   }

	Comp_noticePicto{
		   id: pict2Update

		   x: leftSpacing + pictoSize + pictoSpacing
		   y: topSpacing

		   nbSignal: 1

		   signal1: isAutocontrolActive ? 1 : dataEngine.ind_QuickHitchIsOpen.value
		   signal1Source: "qrc:/graphics/01_Attention Icons PNG/01_Attention Icons PNG 40x40/1.22_Loader_bucket_quick_coupler_unlock_RD.png"
		   signal1canError: canError18FFC147

		   visible: true
	   }

	Comp_noticePicto{
		   id: pict3Update

		   x: leftSpacing + 2*(pictoSize + pictoSpacing)
		   y: topSpacing

		   nbSignal: 1

		   signal1: isAutocontrolActive ? 1 : dataEngine.ind_WorkingHydraulic.value
		   signal1Source: "qrc:/graphics/01_Attention Icons PNG/01_Attention Icons PNG 40x40/1.07_Joystick_control_mode_GN.png"
		   signal1SourceAt0: "qrc:/graphics/01_Attention Icons PNG/01_Attention Icons PNG 40x40/1.08_Joystick_control_lock_YE.png"
		   signal1canError: canError18FFC047

		   visible: true
	   }

	Comp_noticePicto{
		   id: pict4Update

		   x: leftSpacing + 3*(pictoSize + pictoSpacing)
		   y: topSpacing

		   nbSignal: 1

		   signal1: isAutocontrolActive ? 1 : dataEngine.ind_DPF_ExhaustLamp.value
		   signal1Source: "qrc:/graphics/01_Attention Icons PNG/01_Attention Icons PNG 40x40/1.53_Exhaust temperature_YE.png"
		   signal1canError: canError18FFC347

		   visible: true
	   }

	Comp_noticePicto{
		   id: pict5Update

		   x: leftSpacing + 4*(pictoSize + pictoSpacing)
		   y: topSpacing

		   nbSignal: 1

		   signal1: isAutocontrolActive ? 1 : dataEngine.driveMode.value === 0 ? 0 : dataEngine.driveMode.value === 14 ? 2 : 1
		   signal1Source:
		   {
			   if(canError18FFCE47 === true || currentDriveMode === 1){
				   return "qrc:/graphics/01_Attention Icons PNG/01_Attention Icons PNG 40x40/1.57_Bucked_Mode_GN.png"
			   } else if(currentDriveMode === 2){
				   return "qrc:/graphics/01_Attention Icons PNG/01_Attention Icons PNG 40x40/1.56_ECO_Mode_GN.png"
			   } else if(currentDriveMode === 3){
				   return "qrc:/graphics/01_Attention Icons PNG/01_Attention Icons PNG 40x40/1.60_Creep_Mode_GN.png"
			   } else {
				   return ""
			   }
		   }
		   signal1canError: canError18FFCE47

		   visible: true
	   }

	Comp_noticePicto{
		   id: pict6Update

		   x: leftSpacing + 5*(pictoSize + pictoSpacing)
		   y: topSpacing

		   nbSignal: 3 // signal1 hoeher priorisiert als signal2; signal2 hoeher priorisiert als signal3;

		   signal1: isAutocontrolActive ? 1 : dataEngine.ind_LoadAlarmError.value
		   signal1Source: "qrc:/graphics/01_Attention Icons PNG/01_Attention Icons PNG 40x40/1.67_Load_warning_RD.png"
		   signal1canError: canError18FFC147

		   signal2: isAutocontrolActive ? 1 : dataEngine.ind_LoadAlarmWarning.value
		   signal2Source: "qrc:/graphics/01_Attention Icons PNG/01_Attention Icons PNG 40x40/1.67_Load_warning_YE.png"
		   signal2canError: canError18FFC147

		   signal3: isAutocontrolActive ? 1 : dataEngine.ind_Overspeed.value
		   signal3Source: "qrc:/graphics/01_Attention Icons PNG/01_Attention Icons PNG 40x40/1.63_Over_speed_YE.png"
		   signal3canError: canError18FFC047

		   visible: true
	   }

	Comp_noticePicto{
		   id: pict7Update

		   x: leftSpacing + 6*(pictoSize + pictoSpacing)
		   y: topSpacing

		   nbSignal: 2

		   signal1: isAutocontrolActive ? 1 : dataEngine.ind_BeltBuckle.value
		   signal1Source: "qrc:/graphics/01_Attention Icons PNG/01_Attention Icons PNG 40x40/1.45_Seat_belt_RD.png"
		   signal1canError: canError18FFC047

		   signal2: isAutocontrolActive ? 1 : dataEngine.ind_SeatSwitch.value
		   signal2Source: "qrc:/graphics/01_Attention Icons PNG/01_Attention Icons PNG 40x40/1.41_Sit_down_RD.png"
		   signal2canError: canError18FFC047

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
		}
	}
}

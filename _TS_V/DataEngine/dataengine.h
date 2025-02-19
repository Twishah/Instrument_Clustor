/* WARNING: AUTO-GENERATED FILE!
 * MANUAL EDITS WILL BE OVERWRITTEN BY "UPDATE PROJECT" IN LINX MANAGER PLUGIN.
 */

#ifndef DATAENGINE_H
#define DATAENGINE_H

#include "dataenginebase.h"
#include "fieldbusaccesserrormodel.h"


class DataEngine : public DataEngineBase
{
    Q_OBJECT

    // Default Diagnostics Properties
    Q_PROPERTY (FieldbusAccessError* latestJ1939Error READ fieldbusAccessError CONSTANT)
    Q_PROPERTY (FieldbusAccessErrorModel* faErrorModel READ faErrorModel CONSTANT)

    // Signal MetaProperties
	Q_PROPERTY (QByteArrayConsumerSignal* dm1 READ dm1 CONSTANT)
	Q_PROPERTY (IntConsumerSignal* parameterGroupNumber READ parameterGroupNumber CONSTANT)
	Q_PROPERTY (FloatConsumerSignal* opHours_Total READ opHours_Total CONSTANT)
	Q_PROPERTY (IntConsumerSignal* brakeSwitch READ brakeSwitch CONSTANT)
	Q_PROPERTY (IntConsumerSignal* wheelBasedVehicleSpeed READ wheelBasedVehicleSpeed CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_DrivingDirection_Blink READ ind_DrivingDirection_Blink CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_SeatSwitch READ ind_SeatSwitch CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_WorkingHydraulic READ ind_WorkingHydraulic CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_SeatSensorFailure READ ind_SeatSensorFailure CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_AlternatorFailure READ ind_AlternatorFailure CONSTANT)
	Q_PROPERTY (IntConsumerSignal* buzzer READ buzzer CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_CoolingTempTooLow READ ind_CoolingTempTooLow CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_GeneralWarning READ ind_GeneralWarning CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_GeneralError READ ind_GeneralError CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_Overspeed READ ind_Overspeed CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_LampTest READ ind_LampTest CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_DrivingDirection READ ind_DrivingDirection CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_RabbitTurtle READ ind_RabbitTurtle CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_Service READ ind_Service CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_ChargeAirTemperature READ ind_ChargeAirTemperature CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_FuelTooLess READ ind_FuelTooLess CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_CoolingTempTooHigh READ ind_CoolingTempTooHigh CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_Preheating READ ind_Preheating CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_BlinkerRight READ ind_BlinkerRight CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_BlinkerTrailer READ ind_BlinkerTrailer CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_HighBeam READ ind_HighBeam CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_HydraulicOilFilter READ ind_HydraulicOilFilter CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_HydraulicOilLevel READ ind_HydraulicOilLevel CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_SteeringSystemFailure READ ind_SteeringSystemFailure CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_BeltBuckle READ ind_BeltBuckle CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_TransmissionFault READ ind_TransmissionFault CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_BlinkerLeft READ ind_BlinkerLeft CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_AccumulatorPressure READ ind_AccumulatorPressure CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_ParkingBrake READ ind_ParkingBrake CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_ChargeAirFilter READ ind_ChargeAirFilter CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_CoolingLevel READ ind_CoolingLevel CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_Alternator READ ind_Alternator CONSTANT)
	Q_PROPERTY (IntConsumerSignal* adBlueTemperature READ adBlueTemperature CONSTANT)
	Q_PROPERTY (IntConsumerSignal* dPFSootState READ dPFSootState CONSTANT)
	Q_PROPERTY (IntConsumerSignal* dPFSootLoad READ dPFSootLoad CONSTANT)
	Q_PROPERTY (IntConsumerSignal* dPFAshloadState READ dPFAshloadState CONSTANT)
	Q_PROPERTY (IntConsumerSignal* dPFAshLoad READ dPFAshLoad CONSTANT)
	Q_PROPERTY (IntConsumerSignal* adBlueTankLevel READ adBlueTankLevel CONSTANT)
	Q_PROPERTY (IntConsumerSignal* adBlueTankLevelState READ adBlueTankLevelState CONSTANT)
	Q_PROPERTY (IntConsumerSignal* additionalCtrlCircuit4_Volume READ additionalCtrlCircuit4_Volume CONSTANT)
	Q_PROPERTY (IntConsumerSignal* additionalCtrlCircuit3_Volume READ additionalCtrlCircuit3_Volume CONSTANT)
	Q_PROPERTY (IntConsumerSignal* additionalCtrlCircuit2_Volume READ additionalCtrlCircuit2_Volume CONSTANT)
	Q_PROPERTY (IntConsumerSignal* additionalCtrlCircuit1_Volume READ additionalCtrlCircuit1_Volume CONSTANT)
	Q_PROPERTY (IntConsumerSignal* handThrottle READ handThrottle CONSTANT)
	Q_PROPERTY (IntConsumerSignal* footPedal READ footPedal CONSTANT)
	Q_PROPERTY (IntConsumerSignal* gaugeLoadPressure READ gaugeLoadPressure CONSTANT)
	Q_PROPERTY (FloatConsumerSignal* machineVelocity READ machineVelocity CONSTANT)
	Q_PROPERTY (FloatConsumerSignal* gaugeCoolingTemperature READ gaugeCoolingTemperature CONSTANT)
	Q_PROPERTY (IntConsumerSignal* gaugeEngineSpeed READ gaugeEngineSpeed CONSTANT)
	Q_PROPERTY (IntConsumerSignal* cfg_MachineGeneration READ cfg_MachineGeneration CONSTANT)
	Q_PROPERTY (IntConsumerSignal* cfg_MachineBranding READ cfg_MachineBranding CONSTANT)
	Q_PROPERTY (IntConsumerSignal* cfg_EngineEmissionStandard READ cfg_EngineEmissionStandard CONSTANT)
	Q_PROPERTY (IntConsumerSignal* cfg_EngineSupplier READ cfg_EngineSupplier CONSTANT)
	Q_PROPERTY (IntConsumerSignal* opHours_ACC4 READ opHours_ACC4 CONSTANT)
	Q_PROPERTY (IntConsumerSignal* opHours_ACC3 READ opHours_ACC3 CONSTANT)
	Q_PROPERTY (IntConsumerSignal* opHours_ACC2 READ opHours_ACC2 CONSTANT)
	Q_PROPERTY (IntConsumerSignal* opHours_ACC1 READ opHours_ACC1 CONSTANT)
	Q_PROPERTY (IntConsumerSignal* opHours_TimeSncLstRegeneration READ opHours_TimeSncLstRegeneration CONSTANT)
	Q_PROPERTY (IntConsumerSignal* gaugeElectricCurrentConsumption READ gaugeElectricCurrentConsumption CONSTANT)
	Q_PROPERTY (IntConsumerSignal* sOH READ sOH CONSTANT)
	Q_PROPERTY (FloatConsumerSignal* sOC READ sOC CONSTANT)
	Q_PROPERTY (IntConsumerSignal* coolingWaterPumpSpeed READ coolingWaterPumpSpeed CONSTANT)
	Q_PROPERTY (IntConsumerSignal* coolingFanSpeed READ coolingFanSpeed CONSTANT)
	Q_PROPERTY (FloatConsumerSignal* opHours_DailyWorkload READ opHours_DailyWorkload CONSTANT)
	Q_PROPERTY (IntConsumerSignal* opHours_EngineIdleTime READ opHours_EngineIdleTime CONSTANT)
	Q_PROPERTY (IntConsumerSignal* opHours_Mission READ opHours_Mission CONSTANT)
	Q_PROPERTY (IntConsumerSignal* remainingSecondBeforeAutoEngStop READ remainingSecondBeforeAutoEngStop CONSTANT)
	Q_PROPERTY (IntConsumerSignal* hMI_Screen READ hMI_Screen CONSTANT)
	Q_PROPERTY (IntConsumerSignal* driveMode READ driveMode CONSTANT)
	Q_PROPERTY (FloatConsumerSignal* fuelLevel READ fuelLevel CONSTANT)
	Q_PROPERTY (IntConsumerSignal* coolingTemperature READ coolingTemperature CONSTANT)
	Q_PROPERTY (IntConsumerSignal* hydraulicTemperature READ hydraulicTemperature CONSTANT)
	Q_PROPERTY (IntConsumerSignal* workingMode READ workingMode CONSTANT)
	Q_PROPERTY (IntConsumerSignal* opHours_ePTO READ opHours_ePTO CONSTANT)
	Q_PROPERTY (IntConsumerSignal* opHours_eDriveTrain READ opHours_eDriveTrain CONSTANT)
	Q_PROPERTY (IntConsumerSignal* remainingBatteryDisChargingTime READ remainingBatteryDisChargingTime CONSTANT)
	Q_PROPERTY (IntConsumerSignal* remainingBatteryChargingTime READ remainingBatteryChargingTime CONSTANT)
	Q_PROPERTY (IntConsumerSignal* digitalInputKey12 READ digitalInputKey12 CONSTANT)
	Q_PROPERTY (IntConsumerSignal* digitalInputKey11 READ digitalInputKey11 CONSTANT)
	Q_PROPERTY (IntConsumerSignal* digitalInputKey10 READ digitalInputKey10 CONSTANT)
	Q_PROPERTY (IntConsumerSignal* digitalInputKey09 READ digitalInputKey09 CONSTANT)
	Q_PROPERTY (IntConsumerSignal* digitalInputKey08 READ digitalInputKey08 CONSTANT)
	Q_PROPERTY (IntConsumerSignal* digitalInputKey07 READ digitalInputKey07 CONSTANT)
	Q_PROPERTY (IntConsumerSignal* digitalInputKey06 READ digitalInputKey06 CONSTANT)
	Q_PROPERTY (IntConsumerSignal* digitalInputKey05 READ digitalInputKey05 CONSTANT)
	Q_PROPERTY (IntConsumerSignal* digitalInputKey04 READ digitalInputKey04 CONSTANT)
	Q_PROPERTY (IntConsumerSignal* digitalInputKey03 READ digitalInputKey03 CONSTANT)
	Q_PROPERTY (IntConsumerSignal* digitalInputKey02 READ digitalInputKey02 CONSTANT)
	Q_PROPERTY (IntConsumerSignal* digitalInputKey01 READ digitalInputKey01 CONSTANT)
	Q_PROPERTY (FloatConsumerSignal* lowSideCurrent READ lowSideCurrent CONSTANT)
	Q_PROPERTY (FloatConsumerSignal* highSideVoltage READ highSideVoltage CONSTANT)
	Q_PROPERTY (FloatConsumerSignal* lowSideVoltage READ lowSideVoltage CONSTANT)
	Q_PROPERTY (FloatConsumerSignal* highSideCurrent READ highSideCurrent CONSTANT)
	Q_PROPERTY (IntConsumerSignal* zFETC13ePTOActualSpeedFeedback READ zFETC13ePTOActualSpeedFeedback CONSTANT)
	Q_PROPERTY (IntConsumerSignal* zFETC13ePTOModeIndicator READ zFETC13ePTOModeIndicator CONSTANT)
	Q_PROPERTY (IntConsumerSignal* zFETC13ePTOMaximumSpeedFeedback READ zFETC13ePTOMaximumSpeedFeedback CONSTANT)
	Q_PROPERTY (IntConsumerSignal* zFETC13ePTORequestedSpeedFdbck READ zFETC13ePTORequestedSpeedFdbck CONSTANT)
	Q_PROPERTY (IntConsumerSignal* zFETC13ePTOMinimumSpeedFeedback READ zFETC13ePTOMinimumSpeedFeedback CONSTANT)
	Q_PROPERTY (IntConsumerSignal* immobTransPinMaximumTries READ immobTransPinMaximumTries CONSTANT)
	Q_PROPERTY (IntConsumerSignal* immobTransPinLeftTries READ immobTransPinLeftTries CONSTANT)
	Q_PROPERTY (IntConsumerSignal* immobGeneralPinMaximumTries READ immobGeneralPinMaximumTries CONSTANT)
	Q_PROPERTY (IntConsumerSignal* immobGeneralPinLeftTries READ immobGeneralPinLeftTries CONSTANT)
	Q_PROPERTY (IntConsumerSignal* immobOwnerPinMaximumTries READ immobOwnerPinMaximumTries CONSTANT)
	Q_PROPERTY (IntConsumerSignal* immobOwnerPinLeftTries READ immobOwnerPinLeftTries CONSTANT)
	Q_PROPERTY (IntConsumerSignal* popUpMessage_Ctrl READ popUpMessage_Ctrl CONSTANT)
	Q_PROPERTY (IntConsumerSignal* screenCtrl READ screenCtrl CONSTANT)
	Q_PROPERTY (IntConsumerSignal* sOFTTransmissionType READ sOFTTransmissionType CONSTANT)
	Q_PROPERTY (IntConsumerSignal* sOFTTransmissionPartNumber READ sOFTTransmissionPartNumber CONSTANT)
	Q_PROPERTY (IntConsumerSignal* sOFTSoftwareVersion READ sOFTSoftwareVersion CONSTANT)
	Q_PROPERTY (IntConsumerSignal* sOFTSoftwarePartNumber READ sOFTSoftwarePartNumber CONSTANT)
	Q_PROPERTY (IntConsumerSignal* sOFTNmbrOfSftwrIdentFields READ sOFTNmbrOfSftwrIdentFields CONSTANT)
	Q_PROPERTY (IntConsumerSignal* sOFTCustomerSoftwareNumber READ sOFTCustomerSoftwareNumber CONSTANT)
	Q_PROPERTY (FloatConsumerSignal* eCU_Batt READ eCU_Batt CONSTANT)
	Q_PROPERTY (IntConsumerSignal* estPumpingPercentTorque READ estPumpingPercentTorque CONSTANT)
	Q_PROPERTY (IntConsumerSignal* actlMaxAvailableEngPercentTorque READ actlMaxAvailableEngPercentTorque CONSTANT)
	Q_PROPERTY (IntConsumerSignal* sCRThermalManagementActive READ sCRThermalManagementActive CONSTANT)
	Q_PROPERTY (IntConsumerSignal* dPFThermalManagementActive READ dPFThermalManagementActive CONSTANT)
	Q_PROPERTY (IntConsumerSignal* mmntaryEngMaxPowerEnableFeedback READ mmntaryEngMaxPowerEnableFeedback CONSTANT)
	Q_PROPERTY (IntConsumerSignal* vhcleAccelerationRateLimitStatus READ vhcleAccelerationRateLimitStatus CONSTANT)
	Q_PROPERTY (IntConsumerSignal* accelPedalPos2 READ accelPedalPos2 CONSTANT)
	Q_PROPERTY (IntConsumerSignal* remoteAccelPedalPos READ remoteAccelPedalPos CONSTANT)
	Q_PROPERTY (IntConsumerSignal* engPercentLoadAtCurrentSpeed READ engPercentLoadAtCurrentSpeed CONSTANT)
	Q_PROPERTY (IntConsumerSignal* accelPedalPos1 READ accelPedalPos1 CONSTANT)
	Q_PROPERTY (IntConsumerSignal* accelPedal2LowIdleSwitch READ accelPedal2LowIdleSwitch CONSTANT)
	Q_PROPERTY (IntConsumerSignal* roadSpeedLimitStatus READ roadSpeedLimitStatus CONSTANT)
	Q_PROPERTY (IntConsumerSignal* accelPedalKickdownSwitch READ accelPedalKickdownSwitch CONSTANT)
	Q_PROPERTY (IntConsumerSignal* accelPedal1LowIdleSwitch READ accelPedal1LowIdleSwitch CONSTANT)
	Q_PROPERTY (IntConsumerSignal* nSpdSnsrMot READ nSpdSnsrMot CONSTANT)
	Q_PROPERTY (IntConsumerSignal* pMa READ pMa CONSTANT)
	Q_PROPERTY (IntConsumerSignal* pMb READ pMb CONSTANT)
	Q_PROPERTY (IntConsumerSignal* nSpdSnsrPmp READ nSpdSnsrPmp CONSTANT)
	Q_PROPERTY (IntConsumerSignal* nSpdSnsrEng READ nSpdSnsrEng CONSTANT)
	Q_PROPERTY (IntConsumerSignal* msgCntr1 READ msgCntr1 CONSTANT)
	Q_PROPERTY (IntConsumerSignal* msgChks1 READ msgChks1 CONSTANT)
	Q_PROPERTY (IntConsumerSignal* hMI_ConfigurableInput04_CfgUnusd READ hMI_ConfigurableInput04_CfgUnusd CONSTANT)
	Q_PROPERTY (IntConsumerSignal* hMI_ConfigurableInput03_CfgUnusd READ hMI_ConfigurableInput03_CfgUnusd CONSTANT)
	Q_PROPERTY (IntConsumerSignal* hMI_ConfigurableInput02_CfgUnusd READ hMI_ConfigurableInput02_CfgUnusd CONSTANT)
	Q_PROPERTY (IntConsumerSignal* hMI_ConfigurableInput01_CfgUnusd READ hMI_ConfigurableInput01_CfgUnusd CONSTANT)
	Q_PROPERTY (IntConsumerSignal* buzzer_Ctrl READ buzzer_Ctrl CONSTANT)
	Q_PROPERTY (IntConsumerSignal* digitalOutput02_Ctrl READ digitalOutput02_Ctrl CONSTANT)
	Q_PROPERTY (IntConsumerSignal* digitalOutput01_Ctrl READ digitalOutput01_Ctrl CONSTANT)
	Q_PROPERTY (IntConsumerSignal* btnImmobActivation_Ctrl READ btnImmobActivation_Ctrl CONSTANT)
	Q_PROPERTY (IntConsumerSignal* digitalOutput02 READ digitalOutput02 CONSTANT)
	Q_PROPERTY (IntConsumerSignal* digitalOutput01 READ digitalOutput01 CONSTANT)
	Q_PROPERTY (IntConsumerSignal* btnImmobActivation READ btnImmobActivation CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_SOC_Status_Warning READ ind_SOC_Status_Warning CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_SOC_Status_Error READ ind_SOC_Status_Error CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_HVBatteryOn READ ind_HVBatteryOn CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_SOC_Status READ ind_SOC_Status CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_LowRecuperation READ ind_LowRecuperation CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_ElectricSystemFailure READ ind_ElectricSystemFailure CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_ElectricEngineFailure READ ind_ElectricEngineFailure CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_48VBatteryFailure READ ind_48VBatteryFailure CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_EngPwrReductionDueToTemp READ ind_EngPwrReductionDueToTemp CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_HVWarning READ ind_HVWarning CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_HVIsolation READ ind_HVIsolation CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_HVFailure READ ind_HVFailure CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_ElectricEngineStartEnable READ ind_ElectricEngineStartEnable CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_ChargingPlugConnected READ ind_ChargingPlugConnected CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_ChargingFlapOpened READ ind_ChargingFlapOpened CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_ChargingActive READ ind_ChargingActive CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_CellBalancing READ ind_CellBalancing CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_ElectricEngineStartWarning READ ind_ElectricEngineStartWarning CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_ElectricEngineStartError READ ind_ElectricEngineStartError CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_48VBatteryLowTemperature READ ind_48VBatteryLowTemperature CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_48VBatteryHighTemperature READ ind_48VBatteryHighTemperature CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_EngineCoolingFanFailure READ ind_EngineCoolingFanFailure CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_OilExchangeRequest READ ind_OilExchangeRequest CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_NCD_Malfunction READ ind_NCD_Malfunction CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_DPFRegenerationDisabled READ ind_DPFRegenerationDisabled CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_DPF_ExhaustLamp READ ind_DPF_ExhaustLamp CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_DPF_AshLoad READ ind_DPF_AshLoad CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_WaterInFuel READ ind_WaterInFuel CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_DieselExhaustFluid READ ind_DieselExhaustFluid CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_DPFRegeneration READ ind_DPFRegeneration CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_EngineWarning READ ind_EngineWarning CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_EngineFailure READ ind_EngineFailure CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_EngineOilLevel READ ind_EngineOilLevel CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_EngineOilPressure READ ind_EngineOilPressure CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_LoadAlarmWarning READ ind_LoadAlarmWarning CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_LoadAlarmError READ ind_LoadAlarmError CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_ImmobilzerIsLocked READ ind_ImmobilzerIsLocked CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_CruiseControlIsActivated READ ind_CruiseControlIsActivated CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_ECUWarning READ ind_ECUWarning CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_ECUFailure READ ind_ECUFailure CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_TestModeIsActive READ ind_TestModeIsActive CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_CanFailure READ ind_CanFailure CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_SelectedGear READ ind_SelectedGear CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_TractionControl_ASR READ ind_TractionControl_ASR CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_UpperCarrierInPosition READ ind_UpperCarrierInPosition CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_ReverseSteering READ ind_ReverseSteering CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_ISOSAE READ ind_ISOSAE CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_RearPlate READ ind_RearPlate CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_FrontPlate READ ind_FrontPlate CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_RearAxleIsInMiddlePosition READ ind_RearAxleIsInMiddlePosition CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_FrontAxleIsInMiddlePosition READ ind_FrontAxleIsInMiddlePosition CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_FourWheelSteering READ ind_FourWheelSteering CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_CrabSteering READ ind_CrabSteering CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_BucketControlChangeOver READ ind_BucketControlChangeOver CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_DayNightChangeOver READ ind_DayNightChangeOver CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_SwingAxleIsLocked READ ind_SwingAxleIsLocked CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_QuickHitchIsOpen READ ind_QuickHitchIsOpen CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_HydraulicSystemFailure READ ind_HydraulicSystemFailure CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_EcoMode READ ind_EcoMode CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_AutoIdle READ ind_AutoIdle CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_AutoEngineStop READ ind_AutoEngineStop CONSTANT)
	Q_PROPERTY (IntConsumerSignal* ind_DrivingDirectionChoosen READ ind_DrivingDirectionChoosen CONSTANT)


public:
    DataEngine();
    ~DataEngine();

    // QML Getters
    FieldbusAccessError *fieldbusAccessError();
    FieldbusAccessErrorModel* faErrorModel();

	QByteArrayConsumerSignal* dm1() {
		return m_dm1;
	}

	IntConsumerSignal* parameterGroupNumber() {
		return m_parameterGroupNumber;
	}

	FloatConsumerSignal* opHours_Total() {
		return m_opHours_Total;
	}

	IntConsumerSignal* brakeSwitch() {
		return m_brakeSwitch;
	}

	IntConsumerSignal* wheelBasedVehicleSpeed() {
		return m_wheelBasedVehicleSpeed;
	}

	IntConsumerSignal* ind_DrivingDirection_Blink() {
		return m_ind_DrivingDirection_Blink;
	}

	IntConsumerSignal* ind_SeatSwitch() {
		return m_ind_SeatSwitch;
	}

	IntConsumerSignal* ind_WorkingHydraulic() {
		return m_ind_WorkingHydraulic;
	}

	IntConsumerSignal* ind_SeatSensorFailure() {
		return m_ind_SeatSensorFailure;
	}

	IntConsumerSignal* ind_AlternatorFailure() {
		return m_ind_AlternatorFailure;
	}

	IntConsumerSignal* buzzer() {
		return m_buzzer;
	}

	IntConsumerSignal* ind_CoolingTempTooLow() {
		return m_ind_CoolingTempTooLow;
	}

	IntConsumerSignal* ind_GeneralWarning() {
		return m_ind_GeneralWarning;
	}

	IntConsumerSignal* ind_GeneralError() {
		return m_ind_GeneralError;
	}

	IntConsumerSignal* ind_Overspeed() {
		return m_ind_Overspeed;
	}

	IntConsumerSignal* ind_LampTest() {
		return m_ind_LampTest;
	}

	IntConsumerSignal* ind_DrivingDirection() {
		return m_ind_DrivingDirection;
	}

	IntConsumerSignal* ind_RabbitTurtle() {
		return m_ind_RabbitTurtle;
	}

	IntConsumerSignal* ind_Service() {
		return m_ind_Service;
	}

	IntConsumerSignal* ind_ChargeAirTemperature() {
		return m_ind_ChargeAirTemperature;
	}

	IntConsumerSignal* ind_FuelTooLess() {
		return m_ind_FuelTooLess;
	}

	IntConsumerSignal* ind_CoolingTempTooHigh() {
		return m_ind_CoolingTempTooHigh;
	}

	IntConsumerSignal* ind_Preheating() {
		return m_ind_Preheating;
	}

	IntConsumerSignal* ind_BlinkerRight() {
		return m_ind_BlinkerRight;
	}

	IntConsumerSignal* ind_BlinkerTrailer() {
		return m_ind_BlinkerTrailer;
	}

	IntConsumerSignal* ind_HighBeam() {
		return m_ind_HighBeam;
	}

	IntConsumerSignal* ind_HydraulicOilFilter() {
		return m_ind_HydraulicOilFilter;
	}

	IntConsumerSignal* ind_HydraulicOilLevel() {
		return m_ind_HydraulicOilLevel;
	}

	IntConsumerSignal* ind_SteeringSystemFailure() {
		return m_ind_SteeringSystemFailure;
	}

	IntConsumerSignal* ind_BeltBuckle() {
		return m_ind_BeltBuckle;
	}

	IntConsumerSignal* ind_TransmissionFault() {
		return m_ind_TransmissionFault;
	}

	IntConsumerSignal* ind_BlinkerLeft() {
		return m_ind_BlinkerLeft;
	}

	IntConsumerSignal* ind_AccumulatorPressure() {
		return m_ind_AccumulatorPressure;
	}

	IntConsumerSignal* ind_ParkingBrake() {
		return m_ind_ParkingBrake;
	}

	IntConsumerSignal* ind_ChargeAirFilter() {
		return m_ind_ChargeAirFilter;
	}

	IntConsumerSignal* ind_CoolingLevel() {
		return m_ind_CoolingLevel;
	}

	IntConsumerSignal* ind_Alternator() {
		return m_ind_Alternator;
	}

	IntConsumerSignal* adBlueTemperature() {
		return m_adBlueTemperature;
	}

	IntConsumerSignal* dPFSootState() {
		return m_dPFSootState;
	}

	IntConsumerSignal* dPFSootLoad() {
		return m_dPFSootLoad;
	}

	IntConsumerSignal* dPFAshloadState() {
		return m_dPFAshloadState;
	}

	IntConsumerSignal* dPFAshLoad() {
		return m_dPFAshLoad;
	}

	IntConsumerSignal* adBlueTankLevel() {
		return m_adBlueTankLevel;
	}

	IntConsumerSignal* adBlueTankLevelState() {
		return m_adBlueTankLevelState;
	}

	IntConsumerSignal* additionalCtrlCircuit4_Volume() {
		return m_additionalCtrlCircuit4_Volume;
	}

	IntConsumerSignal* additionalCtrlCircuit3_Volume() {
		return m_additionalCtrlCircuit3_Volume;
	}

	IntConsumerSignal* additionalCtrlCircuit2_Volume() {
		return m_additionalCtrlCircuit2_Volume;
	}

	IntConsumerSignal* additionalCtrlCircuit1_Volume() {
		return m_additionalCtrlCircuit1_Volume;
	}

	IntConsumerSignal* handThrottle() {
		return m_handThrottle;
	}

	IntConsumerSignal* footPedal() {
		return m_footPedal;
	}

	IntConsumerSignal* gaugeLoadPressure() {
		return m_gaugeLoadPressure;
	}

	FloatConsumerSignal* machineVelocity() {
		return m_machineVelocity;
	}

	FloatConsumerSignal* gaugeCoolingTemperature() {
		return m_gaugeCoolingTemperature;
	}

	IntConsumerSignal* gaugeEngineSpeed() {
		return m_gaugeEngineSpeed;
	}

	IntConsumerSignal* cfg_MachineGeneration() {
		return m_cfg_MachineGeneration;
	}

	IntConsumerSignal* cfg_MachineBranding() {
		return m_cfg_MachineBranding;
	}

	IntConsumerSignal* cfg_EngineEmissionStandard() {
		return m_cfg_EngineEmissionStandard;
	}

	IntConsumerSignal* cfg_EngineSupplier() {
		return m_cfg_EngineSupplier;
	}

	IntConsumerSignal* opHours_ACC4() {
		return m_opHours_ACC4;
	}

	IntConsumerSignal* opHours_ACC3() {
		return m_opHours_ACC3;
	}

	IntConsumerSignal* opHours_ACC2() {
		return m_opHours_ACC2;
	}

	IntConsumerSignal* opHours_ACC1() {
		return m_opHours_ACC1;
	}

	IntConsumerSignal* opHours_TimeSncLstRegeneration() {
		return m_opHours_TimeSncLstRegeneration;
	}

	IntConsumerSignal* gaugeElectricCurrentConsumption() {
		return m_gaugeElectricCurrentConsumption;
	}

	IntConsumerSignal* sOH() {
		return m_sOH;
	}

	FloatConsumerSignal* sOC() {
		return m_sOC;
	}

	IntConsumerSignal* coolingWaterPumpSpeed() {
		return m_coolingWaterPumpSpeed;
	}

	IntConsumerSignal* coolingFanSpeed() {
		return m_coolingFanSpeed;
	}

	FloatConsumerSignal* opHours_DailyWorkload() {
		return m_opHours_DailyWorkload;
	}

	IntConsumerSignal* opHours_EngineIdleTime() {
		return m_opHours_EngineIdleTime;
	}

	IntConsumerSignal* opHours_Mission() {
		return m_opHours_Mission;
	}

	IntConsumerSignal* remainingSecondBeforeAutoEngStop() {
		return m_remainingSecondBeforeAutoEngStop;
	}

	IntConsumerSignal* hMI_Screen() {
		return m_hMI_Screen;
	}

	IntConsumerSignal* driveMode() {
		return m_driveMode;
	}

	FloatConsumerSignal* fuelLevel() {
		return m_fuelLevel;
	}

	IntConsumerSignal* coolingTemperature() {
		return m_coolingTemperature;
	}

	IntConsumerSignal* hydraulicTemperature() {
		return m_hydraulicTemperature;
	}

	IntConsumerSignal* workingMode() {
		return m_workingMode;
	}

	IntConsumerSignal* opHours_ePTO() {
		return m_opHours_ePTO;
	}

	IntConsumerSignal* opHours_eDriveTrain() {
		return m_opHours_eDriveTrain;
	}

	IntConsumerSignal* remainingBatteryDisChargingTime() {
		return m_remainingBatteryDisChargingTime;
	}

	IntConsumerSignal* remainingBatteryChargingTime() {
		return m_remainingBatteryChargingTime;
	}

	IntConsumerSignal* digitalInputKey12() {
		return m_digitalInputKey12;
	}

	IntConsumerSignal* digitalInputKey11() {
		return m_digitalInputKey11;
	}

	IntConsumerSignal* digitalInputKey10() {
		return m_digitalInputKey10;
	}

	IntConsumerSignal* digitalInputKey09() {
		return m_digitalInputKey09;
	}

	IntConsumerSignal* digitalInputKey08() {
		return m_digitalInputKey08;
	}

	IntConsumerSignal* digitalInputKey07() {
		return m_digitalInputKey07;
	}

	IntConsumerSignal* digitalInputKey06() {
		return m_digitalInputKey06;
	}

	IntConsumerSignal* digitalInputKey05() {
		return m_digitalInputKey05;
	}

	IntConsumerSignal* digitalInputKey04() {
		return m_digitalInputKey04;
	}

	IntConsumerSignal* digitalInputKey03() {
		return m_digitalInputKey03;
	}

	IntConsumerSignal* digitalInputKey02() {
		return m_digitalInputKey02;
	}

	IntConsumerSignal* digitalInputKey01() {
		return m_digitalInputKey01;
	}

	FloatConsumerSignal* lowSideCurrent() {
		return m_lowSideCurrent;
	}

	FloatConsumerSignal* highSideVoltage() {
		return m_highSideVoltage;
	}

	FloatConsumerSignal* lowSideVoltage() {
		return m_lowSideVoltage;
	}

	FloatConsumerSignal* highSideCurrent() {
		return m_highSideCurrent;
	}

	IntConsumerSignal* zFETC13ePTOActualSpeedFeedback() {
		return m_zFETC13ePTOActualSpeedFeedback;
	}

	IntConsumerSignal* zFETC13ePTOModeIndicator() {
		return m_zFETC13ePTOModeIndicator;
	}

	IntConsumerSignal* zFETC13ePTOMaximumSpeedFeedback() {
		return m_zFETC13ePTOMaximumSpeedFeedback;
	}

	IntConsumerSignal* zFETC13ePTORequestedSpeedFdbck() {
		return m_zFETC13ePTORequestedSpeedFdbck;
	}

	IntConsumerSignal* zFETC13ePTOMinimumSpeedFeedback() {
		return m_zFETC13ePTOMinimumSpeedFeedback;
	}

	IntConsumerSignal* immobTransPinMaximumTries() {
		return m_immobTransPinMaximumTries;
	}

	IntConsumerSignal* immobTransPinLeftTries() {
		return m_immobTransPinLeftTries;
	}

	IntConsumerSignal* immobGeneralPinMaximumTries() {
		return m_immobGeneralPinMaximumTries;
	}

	IntConsumerSignal* immobGeneralPinLeftTries() {
		return m_immobGeneralPinLeftTries;
	}

	IntConsumerSignal* immobOwnerPinMaximumTries() {
		return m_immobOwnerPinMaximumTries;
	}

	IntConsumerSignal* immobOwnerPinLeftTries() {
		return m_immobOwnerPinLeftTries;
	}

	IntConsumerSignal* popUpMessage_Ctrl() {
		return m_popUpMessage_Ctrl;
	}

	IntConsumerSignal* screenCtrl() {
		return m_screenCtrl;
	}

	IntConsumerSignal* sOFTTransmissionType() {
		return m_sOFTTransmissionType;
	}

	IntConsumerSignal* sOFTTransmissionPartNumber() {
		return m_sOFTTransmissionPartNumber;
	}

	IntConsumerSignal* sOFTSoftwareVersion() {
		return m_sOFTSoftwareVersion;
	}

	IntConsumerSignal* sOFTSoftwarePartNumber() {
		return m_sOFTSoftwarePartNumber;
	}

	IntConsumerSignal* sOFTNmbrOfSftwrIdentFields() {
		return m_sOFTNmbrOfSftwrIdentFields;
	}

	IntConsumerSignal* sOFTCustomerSoftwareNumber() {
		return m_sOFTCustomerSoftwareNumber;
	}

	FloatConsumerSignal* eCU_Batt() {
		return m_eCU_Batt;
	}

	IntConsumerSignal* estPumpingPercentTorque() {
		return m_estPumpingPercentTorque;
	}

	IntConsumerSignal* actlMaxAvailableEngPercentTorque() {
		return m_actlMaxAvailableEngPercentTorque;
	}

	IntConsumerSignal* sCRThermalManagementActive() {
		return m_sCRThermalManagementActive;
	}

	IntConsumerSignal* dPFThermalManagementActive() {
		return m_dPFThermalManagementActive;
	}

	IntConsumerSignal* mmntaryEngMaxPowerEnableFeedback() {
		return m_mmntaryEngMaxPowerEnableFeedback;
	}

	IntConsumerSignal* vhcleAccelerationRateLimitStatus() {
		return m_vhcleAccelerationRateLimitStatus;
	}

	IntConsumerSignal* accelPedalPos2() {
		return m_accelPedalPos2;
	}

	IntConsumerSignal* remoteAccelPedalPos() {
		return m_remoteAccelPedalPos;
	}

	IntConsumerSignal* engPercentLoadAtCurrentSpeed() {
		return m_engPercentLoadAtCurrentSpeed;
	}

	IntConsumerSignal* accelPedalPos1() {
		return m_accelPedalPos1;
	}

	IntConsumerSignal* accelPedal2LowIdleSwitch() {
		return m_accelPedal2LowIdleSwitch;
	}

	IntConsumerSignal* roadSpeedLimitStatus() {
		return m_roadSpeedLimitStatus;
	}

	IntConsumerSignal* accelPedalKickdownSwitch() {
		return m_accelPedalKickdownSwitch;
	}

	IntConsumerSignal* accelPedal1LowIdleSwitch() {
		return m_accelPedal1LowIdleSwitch;
	}

	IntConsumerSignal* nSpdSnsrMot() {
		return m_nSpdSnsrMot;
	}

	IntConsumerSignal* pMa() {
		return m_pMa;
	}

	IntConsumerSignal* pMb() {
		return m_pMb;
	}

	IntConsumerSignal* nSpdSnsrPmp() {
		return m_nSpdSnsrPmp;
	}

	IntConsumerSignal* nSpdSnsrEng() {
		return m_nSpdSnsrEng;
	}

	IntConsumerSignal* msgCntr1() {
		return m_msgCntr1;
	}

	IntConsumerSignal* msgChks1() {
		return m_msgChks1;
	}

	IntConsumerSignal* hMI_ConfigurableInput04_CfgUnusd() {
		return m_hMI_ConfigurableInput04_CfgUnusd;
	}

	IntConsumerSignal* hMI_ConfigurableInput03_CfgUnusd() {
		return m_hMI_ConfigurableInput03_CfgUnusd;
	}

	IntConsumerSignal* hMI_ConfigurableInput02_CfgUnusd() {
		return m_hMI_ConfigurableInput02_CfgUnusd;
	}

	IntConsumerSignal* hMI_ConfigurableInput01_CfgUnusd() {
		return m_hMI_ConfigurableInput01_CfgUnusd;
	}

	IntConsumerSignal* buzzer_Ctrl() {
		return m_buzzer_Ctrl;
	}

	IntConsumerSignal* digitalOutput02_Ctrl() {
		return m_digitalOutput02_Ctrl;
	}

	IntConsumerSignal* digitalOutput01_Ctrl() {
		return m_digitalOutput01_Ctrl;
	}

	IntConsumerSignal* btnImmobActivation_Ctrl() {
		return m_btnImmobActivation_Ctrl;
	}

	IntConsumerSignal* digitalOutput02() {
		return m_digitalOutput02;
	}

	IntConsumerSignal* digitalOutput01() {
		return m_digitalOutput01;
	}

	IntConsumerSignal* btnImmobActivation() {
		return m_btnImmobActivation;
	}

	IntConsumerSignal* ind_SOC_Status_Warning() {
		return m_ind_SOC_Status_Warning;
	}

	IntConsumerSignal* ind_SOC_Status_Error() {
		return m_ind_SOC_Status_Error;
	}

	IntConsumerSignal* ind_HVBatteryOn() {
		return m_ind_HVBatteryOn;
	}

	IntConsumerSignal* ind_SOC_Status() {
		return m_ind_SOC_Status;
	}

	IntConsumerSignal* ind_LowRecuperation() {
		return m_ind_LowRecuperation;
	}

	IntConsumerSignal* ind_ElectricSystemFailure() {
		return m_ind_ElectricSystemFailure;
	}

	IntConsumerSignal* ind_ElectricEngineFailure() {
		return m_ind_ElectricEngineFailure;
	}

	IntConsumerSignal* ind_48VBatteryFailure() {
		return m_ind_48VBatteryFailure;
	}

	IntConsumerSignal* ind_EngPwrReductionDueToTemp() {
		return m_ind_EngPwrReductionDueToTemp;
	}

	IntConsumerSignal* ind_HVWarning() {
		return m_ind_HVWarning;
	}

	IntConsumerSignal* ind_HVIsolation() {
		return m_ind_HVIsolation;
	}

	IntConsumerSignal* ind_HVFailure() {
		return m_ind_HVFailure;
	}

	IntConsumerSignal* ind_ElectricEngineStartEnable() {
		return m_ind_ElectricEngineStartEnable;
	}

	IntConsumerSignal* ind_ChargingPlugConnected() {
		return m_ind_ChargingPlugConnected;
	}

	IntConsumerSignal* ind_ChargingFlapOpened() {
		return m_ind_ChargingFlapOpened;
	}

	IntConsumerSignal* ind_ChargingActive() {
		return m_ind_ChargingActive;
	}

	IntConsumerSignal* ind_CellBalancing() {
		return m_ind_CellBalancing;
	}

	IntConsumerSignal* ind_ElectricEngineStartWarning() {
		return m_ind_ElectricEngineStartWarning;
	}

	IntConsumerSignal* ind_ElectricEngineStartError() {
		return m_ind_ElectricEngineStartError;
	}

	IntConsumerSignal* ind_48VBatteryLowTemperature() {
		return m_ind_48VBatteryLowTemperature;
	}

	IntConsumerSignal* ind_48VBatteryHighTemperature() {
		return m_ind_48VBatteryHighTemperature;
	}

	IntConsumerSignal* ind_EngineCoolingFanFailure() {
		return m_ind_EngineCoolingFanFailure;
	}

	IntConsumerSignal* ind_OilExchangeRequest() {
		return m_ind_OilExchangeRequest;
	}

	IntConsumerSignal* ind_NCD_Malfunction() {
		return m_ind_NCD_Malfunction;
	}

	IntConsumerSignal* ind_DPFRegenerationDisabled() {
		return m_ind_DPFRegenerationDisabled;
	}

	IntConsumerSignal* ind_DPF_ExhaustLamp() {
		return m_ind_DPF_ExhaustLamp;
	}

	IntConsumerSignal* ind_DPF_AshLoad() {
		return m_ind_DPF_AshLoad;
	}

	IntConsumerSignal* ind_WaterInFuel() {
		return m_ind_WaterInFuel;
	}

	IntConsumerSignal* ind_DieselExhaustFluid() {
		return m_ind_DieselExhaustFluid;
	}

	IntConsumerSignal* ind_DPFRegeneration() {
		return m_ind_DPFRegeneration;
	}

	IntConsumerSignal* ind_EngineWarning() {
		return m_ind_EngineWarning;
	}

	IntConsumerSignal* ind_EngineFailure() {
		return m_ind_EngineFailure;
	}

	IntConsumerSignal* ind_EngineOilLevel() {
		return m_ind_EngineOilLevel;
	}

	IntConsumerSignal* ind_EngineOilPressure() {
		return m_ind_EngineOilPressure;
	}

	IntConsumerSignal* ind_LoadAlarmWarning() {
		return m_ind_LoadAlarmWarning;
	}

	IntConsumerSignal* ind_LoadAlarmError() {
		return m_ind_LoadAlarmError;
	}

	IntConsumerSignal* ind_ImmobilzerIsLocked() {
		return m_ind_ImmobilzerIsLocked;
	}

	IntConsumerSignal* ind_CruiseControlIsActivated() {
		return m_ind_CruiseControlIsActivated;
	}

	IntConsumerSignal* ind_ECUWarning() {
		return m_ind_ECUWarning;
	}

	IntConsumerSignal* ind_ECUFailure() {
		return m_ind_ECUFailure;
	}

	IntConsumerSignal* ind_TestModeIsActive() {
		return m_ind_TestModeIsActive;
	}

	IntConsumerSignal* ind_CanFailure() {
		return m_ind_CanFailure;
	}

	IntConsumerSignal* ind_SelectedGear() {
		return m_ind_SelectedGear;
	}

	IntConsumerSignal* ind_TractionControl_ASR() {
		return m_ind_TractionControl_ASR;
	}

	IntConsumerSignal* ind_UpperCarrierInPosition() {
		return m_ind_UpperCarrierInPosition;
	}

	IntConsumerSignal* ind_ReverseSteering() {
		return m_ind_ReverseSteering;
	}

	IntConsumerSignal* ind_ISOSAE() {
		return m_ind_ISOSAE;
	}

	IntConsumerSignal* ind_RearPlate() {
		return m_ind_RearPlate;
	}

	IntConsumerSignal* ind_FrontPlate() {
		return m_ind_FrontPlate;
	}

	IntConsumerSignal* ind_RearAxleIsInMiddlePosition() {
		return m_ind_RearAxleIsInMiddlePosition;
	}

	IntConsumerSignal* ind_FrontAxleIsInMiddlePosition() {
		return m_ind_FrontAxleIsInMiddlePosition;
	}

	IntConsumerSignal* ind_FourWheelSteering() {
		return m_ind_FourWheelSteering;
	}

	IntConsumerSignal* ind_CrabSteering() {
		return m_ind_CrabSteering;
	}

	IntConsumerSignal* ind_BucketControlChangeOver() {
		return m_ind_BucketControlChangeOver;
	}

	IntConsumerSignal* ind_DayNightChangeOver() {
		return m_ind_DayNightChangeOver;
	}

	IntConsumerSignal* ind_SwingAxleIsLocked() {
		return m_ind_SwingAxleIsLocked;
	}

	IntConsumerSignal* ind_QuickHitchIsOpen() {
		return m_ind_QuickHitchIsOpen;
	}

	IntConsumerSignal* ind_HydraulicSystemFailure() {
		return m_ind_HydraulicSystemFailure;
	}

	IntConsumerSignal* ind_EcoMode() {
		return m_ind_EcoMode;
	}

	IntConsumerSignal* ind_AutoIdle() {
		return m_ind_AutoIdle;
	}

	IntConsumerSignal* ind_AutoEngineStop() {
		return m_ind_AutoEngineStop;
	}

	IntConsumerSignal* ind_DrivingDirectionChoosen() {
		return m_ind_DrivingDirectionChoosen;
	}



protected:
    void handleNewError(FieldbusAccessError *error);
    void handleClearedError(FieldbusAccessError *error);
    void handleStackError(bool exists);
    void receiveFieldbusAccess_J1939Error(QVariant value, int bus = 0);

    //ConsumerSignal *m_fieldbusAccessErrorSignal;
    FieldbusAccessError *m_fieldbusAccessError;
    FieldbusAccessErrorModel *m_faErrorModel;

    // Signal Members
	QByteArrayConsumerSignal* m_dm1;
	ConsumerSignal *m_fieldbusAccess_J1939Error_CAN0;
	IntConsumerSignal* m_parameterGroupNumber;
	FloatConsumerSignal* m_opHours_Total;
	IntConsumerSignal* m_brakeSwitch;
	IntConsumerSignal* m_wheelBasedVehicleSpeed;
	IntConsumerSignal* m_ind_DrivingDirection_Blink;
	IntConsumerSignal* m_ind_SeatSwitch;
	IntConsumerSignal* m_ind_WorkingHydraulic;
	IntConsumerSignal* m_ind_SeatSensorFailure;
	IntConsumerSignal* m_ind_AlternatorFailure;
	IntConsumerSignal* m_buzzer;
	IntConsumerSignal* m_ind_CoolingTempTooLow;
	IntConsumerSignal* m_ind_GeneralWarning;
	IntConsumerSignal* m_ind_GeneralError;
	IntConsumerSignal* m_ind_Overspeed;
	IntConsumerSignal* m_ind_LampTest;
	IntConsumerSignal* m_ind_DrivingDirection;
	IntConsumerSignal* m_ind_RabbitTurtle;
	IntConsumerSignal* m_ind_Service;
	IntConsumerSignal* m_ind_ChargeAirTemperature;
	IntConsumerSignal* m_ind_FuelTooLess;
	IntConsumerSignal* m_ind_CoolingTempTooHigh;
	IntConsumerSignal* m_ind_Preheating;
	IntConsumerSignal* m_ind_BlinkerRight;
	IntConsumerSignal* m_ind_BlinkerTrailer;
	IntConsumerSignal* m_ind_HighBeam;
	IntConsumerSignal* m_ind_HydraulicOilFilter;
	IntConsumerSignal* m_ind_HydraulicOilLevel;
	IntConsumerSignal* m_ind_SteeringSystemFailure;
	IntConsumerSignal* m_ind_BeltBuckle;
	IntConsumerSignal* m_ind_TransmissionFault;
	IntConsumerSignal* m_ind_BlinkerLeft;
	IntConsumerSignal* m_ind_AccumulatorPressure;
	IntConsumerSignal* m_ind_ParkingBrake;
	IntConsumerSignal* m_ind_ChargeAirFilter;
	IntConsumerSignal* m_ind_CoolingLevel;
	IntConsumerSignal* m_ind_Alternator;
	IntConsumerSignal* m_adBlueTemperature;
	IntConsumerSignal* m_dPFSootState;
	IntConsumerSignal* m_dPFSootLoad;
	IntConsumerSignal* m_dPFAshloadState;
	IntConsumerSignal* m_dPFAshLoad;
	IntConsumerSignal* m_adBlueTankLevel;
	IntConsumerSignal* m_adBlueTankLevelState;
	IntConsumerSignal* m_additionalCtrlCircuit4_Volume;
	IntConsumerSignal* m_additionalCtrlCircuit3_Volume;
	IntConsumerSignal* m_additionalCtrlCircuit2_Volume;
	IntConsumerSignal* m_additionalCtrlCircuit1_Volume;
	IntConsumerSignal* m_handThrottle;
	IntConsumerSignal* m_footPedal;
	IntConsumerSignal* m_gaugeLoadPressure;
	FloatConsumerSignal* m_machineVelocity;
	FloatConsumerSignal* m_gaugeCoolingTemperature;
	IntConsumerSignal* m_gaugeEngineSpeed;
	IntConsumerSignal* m_cfg_MachineGeneration;
	IntConsumerSignal* m_cfg_MachineBranding;
	IntConsumerSignal* m_cfg_EngineEmissionStandard;
	IntConsumerSignal* m_cfg_EngineSupplier;
	IntConsumerSignal* m_opHours_ACC4;
	IntConsumerSignal* m_opHours_ACC3;
	IntConsumerSignal* m_opHours_ACC2;
	IntConsumerSignal* m_opHours_ACC1;
	IntConsumerSignal* m_opHours_TimeSncLstRegeneration;
	IntConsumerSignal* m_gaugeElectricCurrentConsumption;
	IntConsumerSignal* m_sOH;
	FloatConsumerSignal* m_sOC;
	IntConsumerSignal* m_coolingWaterPumpSpeed;
	IntConsumerSignal* m_coolingFanSpeed;
	FloatConsumerSignal* m_opHours_DailyWorkload;
	IntConsumerSignal* m_opHours_EngineIdleTime;
	IntConsumerSignal* m_opHours_Mission;
	IntConsumerSignal* m_remainingSecondBeforeAutoEngStop;
	IntConsumerSignal* m_hMI_Screen;
	IntConsumerSignal* m_driveMode;
	FloatConsumerSignal* m_fuelLevel;
	IntConsumerSignal* m_coolingTemperature;
	IntConsumerSignal* m_hydraulicTemperature;
	IntConsumerSignal* m_workingMode;
	IntConsumerSignal* m_opHours_ePTO;
	IntConsumerSignal* m_opHours_eDriveTrain;
	IntConsumerSignal* m_remainingBatteryDisChargingTime;
	IntConsumerSignal* m_remainingBatteryChargingTime;
	IntConsumerSignal* m_digitalInputKey12;
	IntConsumerSignal* m_digitalInputKey11;
	IntConsumerSignal* m_digitalInputKey10;
	IntConsumerSignal* m_digitalInputKey09;
	IntConsumerSignal* m_digitalInputKey08;
	IntConsumerSignal* m_digitalInputKey07;
	IntConsumerSignal* m_digitalInputKey06;
	IntConsumerSignal* m_digitalInputKey05;
	IntConsumerSignal* m_digitalInputKey04;
	IntConsumerSignal* m_digitalInputKey03;
	IntConsumerSignal* m_digitalInputKey02;
	IntConsumerSignal* m_digitalInputKey01;
	FloatConsumerSignal* m_lowSideCurrent;
	FloatConsumerSignal* m_highSideVoltage;
	FloatConsumerSignal* m_lowSideVoltage;
	FloatConsumerSignal* m_highSideCurrent;
	IntConsumerSignal* m_zFETC13ePTOActualSpeedFeedback;
	IntConsumerSignal* m_zFETC13ePTOModeIndicator;
	IntConsumerSignal* m_zFETC13ePTOMaximumSpeedFeedback;
	IntConsumerSignal* m_zFETC13ePTORequestedSpeedFdbck;
	IntConsumerSignal* m_zFETC13ePTOMinimumSpeedFeedback;
	IntConsumerSignal* m_immobTransPinMaximumTries;
	IntConsumerSignal* m_immobTransPinLeftTries;
	IntConsumerSignal* m_immobGeneralPinMaximumTries;
	IntConsumerSignal* m_immobGeneralPinLeftTries;
	IntConsumerSignal* m_immobOwnerPinMaximumTries;
	IntConsumerSignal* m_immobOwnerPinLeftTries;
	IntConsumerSignal* m_popUpMessage_Ctrl;
	IntConsumerSignal* m_screenCtrl;
	IntConsumerSignal* m_sOFTTransmissionType;
	IntConsumerSignal* m_sOFTTransmissionPartNumber;
	IntConsumerSignal* m_sOFTSoftwareVersion;
	IntConsumerSignal* m_sOFTSoftwarePartNumber;
	IntConsumerSignal* m_sOFTNmbrOfSftwrIdentFields;
	IntConsumerSignal* m_sOFTCustomerSoftwareNumber;
	FloatConsumerSignal* m_eCU_Batt;
	IntConsumerSignal* m_estPumpingPercentTorque;
	IntConsumerSignal* m_actlMaxAvailableEngPercentTorque;
	IntConsumerSignal* m_sCRThermalManagementActive;
	IntConsumerSignal* m_dPFThermalManagementActive;
	IntConsumerSignal* m_mmntaryEngMaxPowerEnableFeedback;
	IntConsumerSignal* m_vhcleAccelerationRateLimitStatus;
	IntConsumerSignal* m_accelPedalPos2;
	IntConsumerSignal* m_remoteAccelPedalPos;
	IntConsumerSignal* m_engPercentLoadAtCurrentSpeed;
	IntConsumerSignal* m_accelPedalPos1;
	IntConsumerSignal* m_accelPedal2LowIdleSwitch;
	IntConsumerSignal* m_roadSpeedLimitStatus;
	IntConsumerSignal* m_accelPedalKickdownSwitch;
	IntConsumerSignal* m_accelPedal1LowIdleSwitch;
	IntConsumerSignal* m_nSpdSnsrMot;
	IntConsumerSignal* m_pMa;
	IntConsumerSignal* m_pMb;
	IntConsumerSignal* m_nSpdSnsrPmp;
	IntConsumerSignal* m_nSpdSnsrEng;
	IntConsumerSignal* m_msgCntr1;
	IntConsumerSignal* m_msgChks1;
	IntConsumerSignal* m_hMI_ConfigurableInput04_CfgUnusd;
	IntConsumerSignal* m_hMI_ConfigurableInput03_CfgUnusd;
	IntConsumerSignal* m_hMI_ConfigurableInput02_CfgUnusd;
	IntConsumerSignal* m_hMI_ConfigurableInput01_CfgUnusd;
	IntConsumerSignal* m_buzzer_Ctrl;
	IntConsumerSignal* m_digitalOutput02_Ctrl;
	IntConsumerSignal* m_digitalOutput01_Ctrl;
	IntConsumerSignal* m_btnImmobActivation_Ctrl;
	IntConsumerSignal* m_digitalOutput02;
	IntConsumerSignal* m_digitalOutput01;
	IntConsumerSignal* m_btnImmobActivation;
	IntConsumerSignal* m_ind_SOC_Status_Warning;
	IntConsumerSignal* m_ind_SOC_Status_Error;
	IntConsumerSignal* m_ind_HVBatteryOn;
	IntConsumerSignal* m_ind_SOC_Status;
	IntConsumerSignal* m_ind_LowRecuperation;
	IntConsumerSignal* m_ind_ElectricSystemFailure;
	IntConsumerSignal* m_ind_ElectricEngineFailure;
	IntConsumerSignal* m_ind_48VBatteryFailure;
	IntConsumerSignal* m_ind_EngPwrReductionDueToTemp;
	IntConsumerSignal* m_ind_HVWarning;
	IntConsumerSignal* m_ind_HVIsolation;
	IntConsumerSignal* m_ind_HVFailure;
	IntConsumerSignal* m_ind_ElectricEngineStartEnable;
	IntConsumerSignal* m_ind_ChargingPlugConnected;
	IntConsumerSignal* m_ind_ChargingFlapOpened;
	IntConsumerSignal* m_ind_ChargingActive;
	IntConsumerSignal* m_ind_CellBalancing;
	IntConsumerSignal* m_ind_ElectricEngineStartWarning;
	IntConsumerSignal* m_ind_ElectricEngineStartError;
	IntConsumerSignal* m_ind_48VBatteryLowTemperature;
	IntConsumerSignal* m_ind_48VBatteryHighTemperature;
	IntConsumerSignal* m_ind_EngineCoolingFanFailure;
	IntConsumerSignal* m_ind_OilExchangeRequest;
	IntConsumerSignal* m_ind_NCD_Malfunction;
	IntConsumerSignal* m_ind_DPFRegenerationDisabled;
	IntConsumerSignal* m_ind_DPF_ExhaustLamp;
	IntConsumerSignal* m_ind_DPF_AshLoad;
	IntConsumerSignal* m_ind_WaterInFuel;
	IntConsumerSignal* m_ind_DieselExhaustFluid;
	IntConsumerSignal* m_ind_DPFRegeneration;
	IntConsumerSignal* m_ind_EngineWarning;
	IntConsumerSignal* m_ind_EngineFailure;
	IntConsumerSignal* m_ind_EngineOilLevel;
	IntConsumerSignal* m_ind_EngineOilPressure;
	IntConsumerSignal* m_ind_LoadAlarmWarning;
	IntConsumerSignal* m_ind_LoadAlarmError;
	IntConsumerSignal* m_ind_ImmobilzerIsLocked;
	IntConsumerSignal* m_ind_CruiseControlIsActivated;
	IntConsumerSignal* m_ind_ECUWarning;
	IntConsumerSignal* m_ind_ECUFailure;
	IntConsumerSignal* m_ind_TestModeIsActive;
	IntConsumerSignal* m_ind_CanFailure;
	IntConsumerSignal* m_ind_SelectedGear;
	IntConsumerSignal* m_ind_TractionControl_ASR;
	IntConsumerSignal* m_ind_UpperCarrierInPosition;
	IntConsumerSignal* m_ind_ReverseSteering;
	IntConsumerSignal* m_ind_ISOSAE;
	IntConsumerSignal* m_ind_RearPlate;
	IntConsumerSignal* m_ind_FrontPlate;
	IntConsumerSignal* m_ind_RearAxleIsInMiddlePosition;
	IntConsumerSignal* m_ind_FrontAxleIsInMiddlePosition;
	IntConsumerSignal* m_ind_FourWheelSteering;
	IntConsumerSignal* m_ind_CrabSteering;
	IntConsumerSignal* m_ind_BucketControlChangeOver;
	IntConsumerSignal* m_ind_DayNightChangeOver;
	IntConsumerSignal* m_ind_SwingAxleIsLocked;
	IntConsumerSignal* m_ind_QuickHitchIsOpen;
	IntConsumerSignal* m_ind_HydraulicSystemFailure;
	IntConsumerSignal* m_ind_EcoMode;
	IntConsumerSignal* m_ind_AutoIdle;
	IntConsumerSignal* m_ind_AutoEngineStop;
	IntConsumerSignal* m_ind_DrivingDirectionChoosen;


};

#endif // DATAENGINE_H

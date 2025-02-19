/****************************************************************************
** Meta object code from reading C++ file 'dataengine.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../DataEngine/dataengine.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dataengine.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DataEngine_t {
    QByteArrayData data[220];
    char stringdata0[4434];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DataEngine_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DataEngine_t qt_meta_stringdata_DataEngine = {
    {
QT_MOC_LITERAL(0, 0, 10), // "DataEngine"
QT_MOC_LITERAL(1, 11, 16), // "latestJ1939Error"
QT_MOC_LITERAL(2, 28, 20), // "FieldbusAccessError*"
QT_MOC_LITERAL(3, 49, 12), // "faErrorModel"
QT_MOC_LITERAL(4, 62, 25), // "FieldbusAccessErrorModel*"
QT_MOC_LITERAL(5, 88, 3), // "dm1"
QT_MOC_LITERAL(6, 92, 25), // "QByteArrayConsumerSignal*"
QT_MOC_LITERAL(7, 118, 20), // "parameterGroupNumber"
QT_MOC_LITERAL(8, 139, 18), // "IntConsumerSignal*"
QT_MOC_LITERAL(9, 158, 13), // "opHours_Total"
QT_MOC_LITERAL(10, 172, 20), // "FloatConsumerSignal*"
QT_MOC_LITERAL(11, 193, 11), // "brakeSwitch"
QT_MOC_LITERAL(12, 205, 22), // "wheelBasedVehicleSpeed"
QT_MOC_LITERAL(13, 228, 26), // "ind_DrivingDirection_Blink"
QT_MOC_LITERAL(14, 255, 14), // "ind_SeatSwitch"
QT_MOC_LITERAL(15, 270, 20), // "ind_WorkingHydraulic"
QT_MOC_LITERAL(16, 291, 21), // "ind_SeatSensorFailure"
QT_MOC_LITERAL(17, 313, 21), // "ind_AlternatorFailure"
QT_MOC_LITERAL(18, 335, 6), // "buzzer"
QT_MOC_LITERAL(19, 342, 21), // "ind_CoolingTempTooLow"
QT_MOC_LITERAL(20, 364, 18), // "ind_GeneralWarning"
QT_MOC_LITERAL(21, 383, 16), // "ind_GeneralError"
QT_MOC_LITERAL(22, 400, 13), // "ind_Overspeed"
QT_MOC_LITERAL(23, 414, 12), // "ind_LampTest"
QT_MOC_LITERAL(24, 427, 20), // "ind_DrivingDirection"
QT_MOC_LITERAL(25, 448, 16), // "ind_RabbitTurtle"
QT_MOC_LITERAL(26, 465, 11), // "ind_Service"
QT_MOC_LITERAL(27, 477, 24), // "ind_ChargeAirTemperature"
QT_MOC_LITERAL(28, 502, 15), // "ind_FuelTooLess"
QT_MOC_LITERAL(29, 518, 22), // "ind_CoolingTempTooHigh"
QT_MOC_LITERAL(30, 541, 14), // "ind_Preheating"
QT_MOC_LITERAL(31, 556, 16), // "ind_BlinkerRight"
QT_MOC_LITERAL(32, 573, 18), // "ind_BlinkerTrailer"
QT_MOC_LITERAL(33, 592, 12), // "ind_HighBeam"
QT_MOC_LITERAL(34, 605, 22), // "ind_HydraulicOilFilter"
QT_MOC_LITERAL(35, 628, 21), // "ind_HydraulicOilLevel"
QT_MOC_LITERAL(36, 650, 25), // "ind_SteeringSystemFailure"
QT_MOC_LITERAL(37, 676, 14), // "ind_BeltBuckle"
QT_MOC_LITERAL(38, 691, 21), // "ind_TransmissionFault"
QT_MOC_LITERAL(39, 713, 15), // "ind_BlinkerLeft"
QT_MOC_LITERAL(40, 729, 23), // "ind_AccumulatorPressure"
QT_MOC_LITERAL(41, 753, 16), // "ind_ParkingBrake"
QT_MOC_LITERAL(42, 770, 19), // "ind_ChargeAirFilter"
QT_MOC_LITERAL(43, 790, 16), // "ind_CoolingLevel"
QT_MOC_LITERAL(44, 807, 14), // "ind_Alternator"
QT_MOC_LITERAL(45, 822, 17), // "adBlueTemperature"
QT_MOC_LITERAL(46, 840, 12), // "dPFSootState"
QT_MOC_LITERAL(47, 853, 11), // "dPFSootLoad"
QT_MOC_LITERAL(48, 865, 15), // "dPFAshloadState"
QT_MOC_LITERAL(49, 881, 10), // "dPFAshLoad"
QT_MOC_LITERAL(50, 892, 15), // "adBlueTankLevel"
QT_MOC_LITERAL(51, 908, 20), // "adBlueTankLevelState"
QT_MOC_LITERAL(52, 929, 29), // "additionalCtrlCircuit4_Volume"
QT_MOC_LITERAL(53, 959, 29), // "additionalCtrlCircuit3_Volume"
QT_MOC_LITERAL(54, 989, 29), // "additionalCtrlCircuit2_Volume"
QT_MOC_LITERAL(55, 1019, 29), // "additionalCtrlCircuit1_Volume"
QT_MOC_LITERAL(56, 1049, 12), // "handThrottle"
QT_MOC_LITERAL(57, 1062, 9), // "footPedal"
QT_MOC_LITERAL(58, 1072, 17), // "gaugeLoadPressure"
QT_MOC_LITERAL(59, 1090, 15), // "machineVelocity"
QT_MOC_LITERAL(60, 1106, 23), // "gaugeCoolingTemperature"
QT_MOC_LITERAL(61, 1130, 16), // "gaugeEngineSpeed"
QT_MOC_LITERAL(62, 1147, 21), // "cfg_MachineGeneration"
QT_MOC_LITERAL(63, 1169, 19), // "cfg_MachineBranding"
QT_MOC_LITERAL(64, 1189, 26), // "cfg_EngineEmissionStandard"
QT_MOC_LITERAL(65, 1216, 18), // "cfg_EngineSupplier"
QT_MOC_LITERAL(66, 1235, 12), // "opHours_ACC4"
QT_MOC_LITERAL(67, 1248, 12), // "opHours_ACC3"
QT_MOC_LITERAL(68, 1261, 12), // "opHours_ACC2"
QT_MOC_LITERAL(69, 1274, 12), // "opHours_ACC1"
QT_MOC_LITERAL(70, 1287, 30), // "opHours_TimeSncLstRegeneration"
QT_MOC_LITERAL(71, 1318, 31), // "gaugeElectricCurrentConsumption"
QT_MOC_LITERAL(72, 1350, 3), // "sOH"
QT_MOC_LITERAL(73, 1354, 3), // "sOC"
QT_MOC_LITERAL(74, 1358, 21), // "coolingWaterPumpSpeed"
QT_MOC_LITERAL(75, 1380, 15), // "coolingFanSpeed"
QT_MOC_LITERAL(76, 1396, 21), // "opHours_DailyWorkload"
QT_MOC_LITERAL(77, 1418, 22), // "opHours_EngineIdleTime"
QT_MOC_LITERAL(78, 1441, 15), // "opHours_Mission"
QT_MOC_LITERAL(79, 1457, 32), // "remainingSecondBeforeAutoEngStop"
QT_MOC_LITERAL(80, 1490, 10), // "hMI_Screen"
QT_MOC_LITERAL(81, 1501, 9), // "driveMode"
QT_MOC_LITERAL(82, 1511, 9), // "fuelLevel"
QT_MOC_LITERAL(83, 1521, 18), // "coolingTemperature"
QT_MOC_LITERAL(84, 1540, 20), // "hydraulicTemperature"
QT_MOC_LITERAL(85, 1561, 11), // "workingMode"
QT_MOC_LITERAL(86, 1573, 12), // "opHours_ePTO"
QT_MOC_LITERAL(87, 1586, 19), // "opHours_eDriveTrain"
QT_MOC_LITERAL(88, 1606, 31), // "remainingBatteryDisChargingTime"
QT_MOC_LITERAL(89, 1638, 28), // "remainingBatteryChargingTime"
QT_MOC_LITERAL(90, 1667, 17), // "digitalInputKey12"
QT_MOC_LITERAL(91, 1685, 17), // "digitalInputKey11"
QT_MOC_LITERAL(92, 1703, 17), // "digitalInputKey10"
QT_MOC_LITERAL(93, 1721, 17), // "digitalInputKey09"
QT_MOC_LITERAL(94, 1739, 17), // "digitalInputKey08"
QT_MOC_LITERAL(95, 1757, 17), // "digitalInputKey07"
QT_MOC_LITERAL(96, 1775, 17), // "digitalInputKey06"
QT_MOC_LITERAL(97, 1793, 17), // "digitalInputKey05"
QT_MOC_LITERAL(98, 1811, 17), // "digitalInputKey04"
QT_MOC_LITERAL(99, 1829, 17), // "digitalInputKey03"
QT_MOC_LITERAL(100, 1847, 17), // "digitalInputKey02"
QT_MOC_LITERAL(101, 1865, 17), // "digitalInputKey01"
QT_MOC_LITERAL(102, 1883, 14), // "lowSideCurrent"
QT_MOC_LITERAL(103, 1898, 15), // "highSideVoltage"
QT_MOC_LITERAL(104, 1914, 14), // "lowSideVoltage"
QT_MOC_LITERAL(105, 1929, 15), // "highSideCurrent"
QT_MOC_LITERAL(106, 1945, 30), // "zFETC13ePTOActualSpeedFeedback"
QT_MOC_LITERAL(107, 1976, 24), // "zFETC13ePTOModeIndicator"
QT_MOC_LITERAL(108, 2001, 31), // "zFETC13ePTOMaximumSpeedFeedback"
QT_MOC_LITERAL(109, 2033, 30), // "zFETC13ePTORequestedSpeedFdbck"
QT_MOC_LITERAL(110, 2064, 31), // "zFETC13ePTOMinimumSpeedFeedback"
QT_MOC_LITERAL(111, 2096, 25), // "immobTransPinMaximumTries"
QT_MOC_LITERAL(112, 2122, 22), // "immobTransPinLeftTries"
QT_MOC_LITERAL(113, 2145, 27), // "immobGeneralPinMaximumTries"
QT_MOC_LITERAL(114, 2173, 24), // "immobGeneralPinLeftTries"
QT_MOC_LITERAL(115, 2198, 25), // "immobOwnerPinMaximumTries"
QT_MOC_LITERAL(116, 2224, 22), // "immobOwnerPinLeftTries"
QT_MOC_LITERAL(117, 2247, 17), // "popUpMessage_Ctrl"
QT_MOC_LITERAL(118, 2265, 10), // "screenCtrl"
QT_MOC_LITERAL(119, 2276, 20), // "sOFTTransmissionType"
QT_MOC_LITERAL(120, 2297, 26), // "sOFTTransmissionPartNumber"
QT_MOC_LITERAL(121, 2324, 19), // "sOFTSoftwareVersion"
QT_MOC_LITERAL(122, 2344, 22), // "sOFTSoftwarePartNumber"
QT_MOC_LITERAL(123, 2367, 26), // "sOFTNmbrOfSftwrIdentFields"
QT_MOC_LITERAL(124, 2394, 26), // "sOFTCustomerSoftwareNumber"
QT_MOC_LITERAL(125, 2421, 8), // "eCU_Batt"
QT_MOC_LITERAL(126, 2430, 23), // "estPumpingPercentTorque"
QT_MOC_LITERAL(127, 2454, 32), // "actlMaxAvailableEngPercentTorque"
QT_MOC_LITERAL(128, 2487, 26), // "sCRThermalManagementActive"
QT_MOC_LITERAL(129, 2514, 26), // "dPFThermalManagementActive"
QT_MOC_LITERAL(130, 2541, 32), // "mmntaryEngMaxPowerEnableFeedback"
QT_MOC_LITERAL(131, 2574, 32), // "vhcleAccelerationRateLimitStatus"
QT_MOC_LITERAL(132, 2607, 14), // "accelPedalPos2"
QT_MOC_LITERAL(133, 2622, 19), // "remoteAccelPedalPos"
QT_MOC_LITERAL(134, 2642, 28), // "engPercentLoadAtCurrentSpeed"
QT_MOC_LITERAL(135, 2671, 14), // "accelPedalPos1"
QT_MOC_LITERAL(136, 2686, 24), // "accelPedal2LowIdleSwitch"
QT_MOC_LITERAL(137, 2711, 20), // "roadSpeedLimitStatus"
QT_MOC_LITERAL(138, 2732, 24), // "accelPedalKickdownSwitch"
QT_MOC_LITERAL(139, 2757, 24), // "accelPedal1LowIdleSwitch"
QT_MOC_LITERAL(140, 2782, 11), // "nSpdSnsrMot"
QT_MOC_LITERAL(141, 2794, 3), // "pMa"
QT_MOC_LITERAL(142, 2798, 3), // "pMb"
QT_MOC_LITERAL(143, 2802, 11), // "nSpdSnsrPmp"
QT_MOC_LITERAL(144, 2814, 11), // "nSpdSnsrEng"
QT_MOC_LITERAL(145, 2826, 8), // "msgCntr1"
QT_MOC_LITERAL(146, 2835, 8), // "msgChks1"
QT_MOC_LITERAL(147, 2844, 32), // "hMI_ConfigurableInput04_CfgUnusd"
QT_MOC_LITERAL(148, 2877, 32), // "hMI_ConfigurableInput03_CfgUnusd"
QT_MOC_LITERAL(149, 2910, 32), // "hMI_ConfigurableInput02_CfgUnusd"
QT_MOC_LITERAL(150, 2943, 32), // "hMI_ConfigurableInput01_CfgUnusd"
QT_MOC_LITERAL(151, 2976, 11), // "buzzer_Ctrl"
QT_MOC_LITERAL(152, 2988, 20), // "digitalOutput02_Ctrl"
QT_MOC_LITERAL(153, 3009, 20), // "digitalOutput01_Ctrl"
QT_MOC_LITERAL(154, 3030, 23), // "btnImmobActivation_Ctrl"
QT_MOC_LITERAL(155, 3054, 15), // "digitalOutput02"
QT_MOC_LITERAL(156, 3070, 15), // "digitalOutput01"
QT_MOC_LITERAL(157, 3086, 18), // "btnImmobActivation"
QT_MOC_LITERAL(158, 3105, 22), // "ind_SOC_Status_Warning"
QT_MOC_LITERAL(159, 3128, 20), // "ind_SOC_Status_Error"
QT_MOC_LITERAL(160, 3149, 15), // "ind_HVBatteryOn"
QT_MOC_LITERAL(161, 3165, 14), // "ind_SOC_Status"
QT_MOC_LITERAL(162, 3180, 19), // "ind_LowRecuperation"
QT_MOC_LITERAL(163, 3200, 25), // "ind_ElectricSystemFailure"
QT_MOC_LITERAL(164, 3226, 25), // "ind_ElectricEngineFailure"
QT_MOC_LITERAL(165, 3252, 21), // "ind_48VBatteryFailure"
QT_MOC_LITERAL(166, 3274, 28), // "ind_EngPwrReductionDueToTemp"
QT_MOC_LITERAL(167, 3303, 13), // "ind_HVWarning"
QT_MOC_LITERAL(168, 3317, 15), // "ind_HVIsolation"
QT_MOC_LITERAL(169, 3333, 13), // "ind_HVFailure"
QT_MOC_LITERAL(170, 3347, 29), // "ind_ElectricEngineStartEnable"
QT_MOC_LITERAL(171, 3377, 25), // "ind_ChargingPlugConnected"
QT_MOC_LITERAL(172, 3403, 22), // "ind_ChargingFlapOpened"
QT_MOC_LITERAL(173, 3426, 18), // "ind_ChargingActive"
QT_MOC_LITERAL(174, 3445, 17), // "ind_CellBalancing"
QT_MOC_LITERAL(175, 3463, 30), // "ind_ElectricEngineStartWarning"
QT_MOC_LITERAL(176, 3494, 28), // "ind_ElectricEngineStartError"
QT_MOC_LITERAL(177, 3523, 28), // "ind_48VBatteryLowTemperature"
QT_MOC_LITERAL(178, 3552, 29), // "ind_48VBatteryHighTemperature"
QT_MOC_LITERAL(179, 3582, 27), // "ind_EngineCoolingFanFailure"
QT_MOC_LITERAL(180, 3610, 22), // "ind_OilExchangeRequest"
QT_MOC_LITERAL(181, 3633, 19), // "ind_NCD_Malfunction"
QT_MOC_LITERAL(182, 3653, 27), // "ind_DPFRegenerationDisabled"
QT_MOC_LITERAL(183, 3681, 19), // "ind_DPF_ExhaustLamp"
QT_MOC_LITERAL(184, 3701, 15), // "ind_DPF_AshLoad"
QT_MOC_LITERAL(185, 3717, 15), // "ind_WaterInFuel"
QT_MOC_LITERAL(186, 3733, 22), // "ind_DieselExhaustFluid"
QT_MOC_LITERAL(187, 3756, 19), // "ind_DPFRegeneration"
QT_MOC_LITERAL(188, 3776, 17), // "ind_EngineWarning"
QT_MOC_LITERAL(189, 3794, 17), // "ind_EngineFailure"
QT_MOC_LITERAL(190, 3812, 18), // "ind_EngineOilLevel"
QT_MOC_LITERAL(191, 3831, 21), // "ind_EngineOilPressure"
QT_MOC_LITERAL(192, 3853, 20), // "ind_LoadAlarmWarning"
QT_MOC_LITERAL(193, 3874, 18), // "ind_LoadAlarmError"
QT_MOC_LITERAL(194, 3893, 22), // "ind_ImmobilzerIsLocked"
QT_MOC_LITERAL(195, 3916, 28), // "ind_CruiseControlIsActivated"
QT_MOC_LITERAL(196, 3945, 14), // "ind_ECUWarning"
QT_MOC_LITERAL(197, 3960, 14), // "ind_ECUFailure"
QT_MOC_LITERAL(198, 3975, 20), // "ind_TestModeIsActive"
QT_MOC_LITERAL(199, 3996, 14), // "ind_CanFailure"
QT_MOC_LITERAL(200, 4011, 16), // "ind_SelectedGear"
QT_MOC_LITERAL(201, 4028, 23), // "ind_TractionControl_ASR"
QT_MOC_LITERAL(202, 4052, 26), // "ind_UpperCarrierInPosition"
QT_MOC_LITERAL(203, 4079, 19), // "ind_ReverseSteering"
QT_MOC_LITERAL(204, 4099, 10), // "ind_ISOSAE"
QT_MOC_LITERAL(205, 4110, 13), // "ind_RearPlate"
QT_MOC_LITERAL(206, 4124, 14), // "ind_FrontPlate"
QT_MOC_LITERAL(207, 4139, 30), // "ind_RearAxleIsInMiddlePosition"
QT_MOC_LITERAL(208, 4170, 31), // "ind_FrontAxleIsInMiddlePosition"
QT_MOC_LITERAL(209, 4202, 21), // "ind_FourWheelSteering"
QT_MOC_LITERAL(210, 4224, 16), // "ind_CrabSteering"
QT_MOC_LITERAL(211, 4241, 27), // "ind_BucketControlChangeOver"
QT_MOC_LITERAL(212, 4269, 22), // "ind_DayNightChangeOver"
QT_MOC_LITERAL(213, 4292, 21), // "ind_SwingAxleIsLocked"
QT_MOC_LITERAL(214, 4314, 20), // "ind_QuickHitchIsOpen"
QT_MOC_LITERAL(215, 4335, 26), // "ind_HydraulicSystemFailure"
QT_MOC_LITERAL(216, 4362, 11), // "ind_EcoMode"
QT_MOC_LITERAL(217, 4374, 12), // "ind_AutoIdle"
QT_MOC_LITERAL(218, 4387, 18), // "ind_AutoEngineStop"
QT_MOC_LITERAL(219, 4406, 27) // "ind_DrivingDirectionChoosen"

    },
    "DataEngine\0latestJ1939Error\0"
    "FieldbusAccessError*\0faErrorModel\0"
    "FieldbusAccessErrorModel*\0dm1\0"
    "QByteArrayConsumerSignal*\0"
    "parameterGroupNumber\0IntConsumerSignal*\0"
    "opHours_Total\0FloatConsumerSignal*\0"
    "brakeSwitch\0wheelBasedVehicleSpeed\0"
    "ind_DrivingDirection_Blink\0ind_SeatSwitch\0"
    "ind_WorkingHydraulic\0ind_SeatSensorFailure\0"
    "ind_AlternatorFailure\0buzzer\0"
    "ind_CoolingTempTooLow\0ind_GeneralWarning\0"
    "ind_GeneralError\0ind_Overspeed\0"
    "ind_LampTest\0ind_DrivingDirection\0"
    "ind_RabbitTurtle\0ind_Service\0"
    "ind_ChargeAirTemperature\0ind_FuelTooLess\0"
    "ind_CoolingTempTooHigh\0ind_Preheating\0"
    "ind_BlinkerRight\0ind_BlinkerTrailer\0"
    "ind_HighBeam\0ind_HydraulicOilFilter\0"
    "ind_HydraulicOilLevel\0ind_SteeringSystemFailure\0"
    "ind_BeltBuckle\0ind_TransmissionFault\0"
    "ind_BlinkerLeft\0ind_AccumulatorPressure\0"
    "ind_ParkingBrake\0ind_ChargeAirFilter\0"
    "ind_CoolingLevel\0ind_Alternator\0"
    "adBlueTemperature\0dPFSootState\0"
    "dPFSootLoad\0dPFAshloadState\0dPFAshLoad\0"
    "adBlueTankLevel\0adBlueTankLevelState\0"
    "additionalCtrlCircuit4_Volume\0"
    "additionalCtrlCircuit3_Volume\0"
    "additionalCtrlCircuit2_Volume\0"
    "additionalCtrlCircuit1_Volume\0"
    "handThrottle\0footPedal\0gaugeLoadPressure\0"
    "machineVelocity\0gaugeCoolingTemperature\0"
    "gaugeEngineSpeed\0cfg_MachineGeneration\0"
    "cfg_MachineBranding\0cfg_EngineEmissionStandard\0"
    "cfg_EngineSupplier\0opHours_ACC4\0"
    "opHours_ACC3\0opHours_ACC2\0opHours_ACC1\0"
    "opHours_TimeSncLstRegeneration\0"
    "gaugeElectricCurrentConsumption\0sOH\0"
    "sOC\0coolingWaterPumpSpeed\0coolingFanSpeed\0"
    "opHours_DailyWorkload\0opHours_EngineIdleTime\0"
    "opHours_Mission\0remainingSecondBeforeAutoEngStop\0"
    "hMI_Screen\0driveMode\0fuelLevel\0"
    "coolingTemperature\0hydraulicTemperature\0"
    "workingMode\0opHours_ePTO\0opHours_eDriveTrain\0"
    "remainingBatteryDisChargingTime\0"
    "remainingBatteryChargingTime\0"
    "digitalInputKey12\0digitalInputKey11\0"
    "digitalInputKey10\0digitalInputKey09\0"
    "digitalInputKey08\0digitalInputKey07\0"
    "digitalInputKey06\0digitalInputKey05\0"
    "digitalInputKey04\0digitalInputKey03\0"
    "digitalInputKey02\0digitalInputKey01\0"
    "lowSideCurrent\0highSideVoltage\0"
    "lowSideVoltage\0highSideCurrent\0"
    "zFETC13ePTOActualSpeedFeedback\0"
    "zFETC13ePTOModeIndicator\0"
    "zFETC13ePTOMaximumSpeedFeedback\0"
    "zFETC13ePTORequestedSpeedFdbck\0"
    "zFETC13ePTOMinimumSpeedFeedback\0"
    "immobTransPinMaximumTries\0"
    "immobTransPinLeftTries\0"
    "immobGeneralPinMaximumTries\0"
    "immobGeneralPinLeftTries\0"
    "immobOwnerPinMaximumTries\0"
    "immobOwnerPinLeftTries\0popUpMessage_Ctrl\0"
    "screenCtrl\0sOFTTransmissionType\0"
    "sOFTTransmissionPartNumber\0"
    "sOFTSoftwareVersion\0sOFTSoftwarePartNumber\0"
    "sOFTNmbrOfSftwrIdentFields\0"
    "sOFTCustomerSoftwareNumber\0eCU_Batt\0"
    "estPumpingPercentTorque\0"
    "actlMaxAvailableEngPercentTorque\0"
    "sCRThermalManagementActive\0"
    "dPFThermalManagementActive\0"
    "mmntaryEngMaxPowerEnableFeedback\0"
    "vhcleAccelerationRateLimitStatus\0"
    "accelPedalPos2\0remoteAccelPedalPos\0"
    "engPercentLoadAtCurrentSpeed\0"
    "accelPedalPos1\0accelPedal2LowIdleSwitch\0"
    "roadSpeedLimitStatus\0accelPedalKickdownSwitch\0"
    "accelPedal1LowIdleSwitch\0nSpdSnsrMot\0"
    "pMa\0pMb\0nSpdSnsrPmp\0nSpdSnsrEng\0"
    "msgCntr1\0msgChks1\0hMI_ConfigurableInput04_CfgUnusd\0"
    "hMI_ConfigurableInput03_CfgUnusd\0"
    "hMI_ConfigurableInput02_CfgUnusd\0"
    "hMI_ConfigurableInput01_CfgUnusd\0"
    "buzzer_Ctrl\0digitalOutput02_Ctrl\0"
    "digitalOutput01_Ctrl\0btnImmobActivation_Ctrl\0"
    "digitalOutput02\0digitalOutput01\0"
    "btnImmobActivation\0ind_SOC_Status_Warning\0"
    "ind_SOC_Status_Error\0ind_HVBatteryOn\0"
    "ind_SOC_Status\0ind_LowRecuperation\0"
    "ind_ElectricSystemFailure\0"
    "ind_ElectricEngineFailure\0"
    "ind_48VBatteryFailure\0"
    "ind_EngPwrReductionDueToTemp\0ind_HVWarning\0"
    "ind_HVIsolation\0ind_HVFailure\0"
    "ind_ElectricEngineStartEnable\0"
    "ind_ChargingPlugConnected\0"
    "ind_ChargingFlapOpened\0ind_ChargingActive\0"
    "ind_CellBalancing\0ind_ElectricEngineStartWarning\0"
    "ind_ElectricEngineStartError\0"
    "ind_48VBatteryLowTemperature\0"
    "ind_48VBatteryHighTemperature\0"
    "ind_EngineCoolingFanFailure\0"
    "ind_OilExchangeRequest\0ind_NCD_Malfunction\0"
    "ind_DPFRegenerationDisabled\0"
    "ind_DPF_ExhaustLamp\0ind_DPF_AshLoad\0"
    "ind_WaterInFuel\0ind_DieselExhaustFluid\0"
    "ind_DPFRegeneration\0ind_EngineWarning\0"
    "ind_EngineFailure\0ind_EngineOilLevel\0"
    "ind_EngineOilPressure\0ind_LoadAlarmWarning\0"
    "ind_LoadAlarmError\0ind_ImmobilzerIsLocked\0"
    "ind_CruiseControlIsActivated\0"
    "ind_ECUWarning\0ind_ECUFailure\0"
    "ind_TestModeIsActive\0ind_CanFailure\0"
    "ind_SelectedGear\0ind_TractionControl_ASR\0"
    "ind_UpperCarrierInPosition\0"
    "ind_ReverseSteering\0ind_ISOSAE\0"
    "ind_RearPlate\0ind_FrontPlate\0"
    "ind_RearAxleIsInMiddlePosition\0"
    "ind_FrontAxleIsInMiddlePosition\0"
    "ind_FourWheelSteering\0ind_CrabSteering\0"
    "ind_BucketControlChangeOver\0"
    "ind_DayNightChangeOver\0ind_SwingAxleIsLocked\0"
    "ind_QuickHitchIsOpen\0ind_HydraulicSystemFailure\0"
    "ind_EcoMode\0ind_AutoIdle\0ind_AutoEngineStop\0"
    "ind_DrivingDirectionChoosen"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DataEngine[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
     214,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, 0x80000000 | 2, 0x00095409,
       3, 0x80000000 | 4, 0x00095409,
       5, 0x80000000 | 6, 0x00095409,
       7, 0x80000000 | 8, 0x00095409,
       9, 0x80000000 | 10, 0x00095409,
      11, 0x80000000 | 8, 0x00095409,
      12, 0x80000000 | 8, 0x00095409,
      13, 0x80000000 | 8, 0x00095409,
      14, 0x80000000 | 8, 0x00095409,
      15, 0x80000000 | 8, 0x00095409,
      16, 0x80000000 | 8, 0x00095409,
      17, 0x80000000 | 8, 0x00095409,
      18, 0x80000000 | 8, 0x00095409,
      19, 0x80000000 | 8, 0x00095409,
      20, 0x80000000 | 8, 0x00095409,
      21, 0x80000000 | 8, 0x00095409,
      22, 0x80000000 | 8, 0x00095409,
      23, 0x80000000 | 8, 0x00095409,
      24, 0x80000000 | 8, 0x00095409,
      25, 0x80000000 | 8, 0x00095409,
      26, 0x80000000 | 8, 0x00095409,
      27, 0x80000000 | 8, 0x00095409,
      28, 0x80000000 | 8, 0x00095409,
      29, 0x80000000 | 8, 0x00095409,
      30, 0x80000000 | 8, 0x00095409,
      31, 0x80000000 | 8, 0x00095409,
      32, 0x80000000 | 8, 0x00095409,
      33, 0x80000000 | 8, 0x00095409,
      34, 0x80000000 | 8, 0x00095409,
      35, 0x80000000 | 8, 0x00095409,
      36, 0x80000000 | 8, 0x00095409,
      37, 0x80000000 | 8, 0x00095409,
      38, 0x80000000 | 8, 0x00095409,
      39, 0x80000000 | 8, 0x00095409,
      40, 0x80000000 | 8, 0x00095409,
      41, 0x80000000 | 8, 0x00095409,
      42, 0x80000000 | 8, 0x00095409,
      43, 0x80000000 | 8, 0x00095409,
      44, 0x80000000 | 8, 0x00095409,
      45, 0x80000000 | 8, 0x00095409,
      46, 0x80000000 | 8, 0x00095409,
      47, 0x80000000 | 8, 0x00095409,
      48, 0x80000000 | 8, 0x00095409,
      49, 0x80000000 | 8, 0x00095409,
      50, 0x80000000 | 8, 0x00095409,
      51, 0x80000000 | 8, 0x00095409,
      52, 0x80000000 | 8, 0x00095409,
      53, 0x80000000 | 8, 0x00095409,
      54, 0x80000000 | 8, 0x00095409,
      55, 0x80000000 | 8, 0x00095409,
      56, 0x80000000 | 8, 0x00095409,
      57, 0x80000000 | 8, 0x00095409,
      58, 0x80000000 | 8, 0x00095409,
      59, 0x80000000 | 10, 0x00095409,
      60, 0x80000000 | 10, 0x00095409,
      61, 0x80000000 | 8, 0x00095409,
      62, 0x80000000 | 8, 0x00095409,
      63, 0x80000000 | 8, 0x00095409,
      64, 0x80000000 | 8, 0x00095409,
      65, 0x80000000 | 8, 0x00095409,
      66, 0x80000000 | 8, 0x00095409,
      67, 0x80000000 | 8, 0x00095409,
      68, 0x80000000 | 8, 0x00095409,
      69, 0x80000000 | 8, 0x00095409,
      70, 0x80000000 | 8, 0x00095409,
      71, 0x80000000 | 8, 0x00095409,
      72, 0x80000000 | 8, 0x00095409,
      73, 0x80000000 | 10, 0x00095409,
      74, 0x80000000 | 8, 0x00095409,
      75, 0x80000000 | 8, 0x00095409,
      76, 0x80000000 | 10, 0x00095409,
      77, 0x80000000 | 8, 0x00095409,
      78, 0x80000000 | 8, 0x00095409,
      79, 0x80000000 | 8, 0x00095409,
      80, 0x80000000 | 8, 0x00095409,
      81, 0x80000000 | 8, 0x00095409,
      82, 0x80000000 | 10, 0x00095409,
      83, 0x80000000 | 8, 0x00095409,
      84, 0x80000000 | 8, 0x00095409,
      85, 0x80000000 | 8, 0x00095409,
      86, 0x80000000 | 8, 0x00095409,
      87, 0x80000000 | 8, 0x00095409,
      88, 0x80000000 | 8, 0x00095409,
      89, 0x80000000 | 8, 0x00095409,
      90, 0x80000000 | 8, 0x00095409,
      91, 0x80000000 | 8, 0x00095409,
      92, 0x80000000 | 8, 0x00095409,
      93, 0x80000000 | 8, 0x00095409,
      94, 0x80000000 | 8, 0x00095409,
      95, 0x80000000 | 8, 0x00095409,
      96, 0x80000000 | 8, 0x00095409,
      97, 0x80000000 | 8, 0x00095409,
      98, 0x80000000 | 8, 0x00095409,
      99, 0x80000000 | 8, 0x00095409,
     100, 0x80000000 | 8, 0x00095409,
     101, 0x80000000 | 8, 0x00095409,
     102, 0x80000000 | 10, 0x00095409,
     103, 0x80000000 | 10, 0x00095409,
     104, 0x80000000 | 10, 0x00095409,
     105, 0x80000000 | 10, 0x00095409,
     106, 0x80000000 | 8, 0x00095409,
     107, 0x80000000 | 8, 0x00095409,
     108, 0x80000000 | 8, 0x00095409,
     109, 0x80000000 | 8, 0x00095409,
     110, 0x80000000 | 8, 0x00095409,
     111, 0x80000000 | 8, 0x00095409,
     112, 0x80000000 | 8, 0x00095409,
     113, 0x80000000 | 8, 0x00095409,
     114, 0x80000000 | 8, 0x00095409,
     115, 0x80000000 | 8, 0x00095409,
     116, 0x80000000 | 8, 0x00095409,
     117, 0x80000000 | 8, 0x00095409,
     118, 0x80000000 | 8, 0x00095409,
     119, 0x80000000 | 8, 0x00095409,
     120, 0x80000000 | 8, 0x00095409,
     121, 0x80000000 | 8, 0x00095409,
     122, 0x80000000 | 8, 0x00095409,
     123, 0x80000000 | 8, 0x00095409,
     124, 0x80000000 | 8, 0x00095409,
     125, 0x80000000 | 10, 0x00095409,
     126, 0x80000000 | 8, 0x00095409,
     127, 0x80000000 | 8, 0x00095409,
     128, 0x80000000 | 8, 0x00095409,
     129, 0x80000000 | 8, 0x00095409,
     130, 0x80000000 | 8, 0x00095409,
     131, 0x80000000 | 8, 0x00095409,
     132, 0x80000000 | 8, 0x00095409,
     133, 0x80000000 | 8, 0x00095409,
     134, 0x80000000 | 8, 0x00095409,
     135, 0x80000000 | 8, 0x00095409,
     136, 0x80000000 | 8, 0x00095409,
     137, 0x80000000 | 8, 0x00095409,
     138, 0x80000000 | 8, 0x00095409,
     139, 0x80000000 | 8, 0x00095409,
     140, 0x80000000 | 8, 0x00095409,
     141, 0x80000000 | 8, 0x00095409,
     142, 0x80000000 | 8, 0x00095409,
     143, 0x80000000 | 8, 0x00095409,
     144, 0x80000000 | 8, 0x00095409,
     145, 0x80000000 | 8, 0x00095409,
     146, 0x80000000 | 8, 0x00095409,
     147, 0x80000000 | 8, 0x00095409,
     148, 0x80000000 | 8, 0x00095409,
     149, 0x80000000 | 8, 0x00095409,
     150, 0x80000000 | 8, 0x00095409,
     151, 0x80000000 | 8, 0x00095409,
     152, 0x80000000 | 8, 0x00095409,
     153, 0x80000000 | 8, 0x00095409,
     154, 0x80000000 | 8, 0x00095409,
     155, 0x80000000 | 8, 0x00095409,
     156, 0x80000000 | 8, 0x00095409,
     157, 0x80000000 | 8, 0x00095409,
     158, 0x80000000 | 8, 0x00095409,
     159, 0x80000000 | 8, 0x00095409,
     160, 0x80000000 | 8, 0x00095409,
     161, 0x80000000 | 8, 0x00095409,
     162, 0x80000000 | 8, 0x00095409,
     163, 0x80000000 | 8, 0x00095409,
     164, 0x80000000 | 8, 0x00095409,
     165, 0x80000000 | 8, 0x00095409,
     166, 0x80000000 | 8, 0x00095409,
     167, 0x80000000 | 8, 0x00095409,
     168, 0x80000000 | 8, 0x00095409,
     169, 0x80000000 | 8, 0x00095409,
     170, 0x80000000 | 8, 0x00095409,
     171, 0x80000000 | 8, 0x00095409,
     172, 0x80000000 | 8, 0x00095409,
     173, 0x80000000 | 8, 0x00095409,
     174, 0x80000000 | 8, 0x00095409,
     175, 0x80000000 | 8, 0x00095409,
     176, 0x80000000 | 8, 0x00095409,
     177, 0x80000000 | 8, 0x00095409,
     178, 0x80000000 | 8, 0x00095409,
     179, 0x80000000 | 8, 0x00095409,
     180, 0x80000000 | 8, 0x00095409,
     181, 0x80000000 | 8, 0x00095409,
     182, 0x80000000 | 8, 0x00095409,
     183, 0x80000000 | 8, 0x00095409,
     184, 0x80000000 | 8, 0x00095409,
     185, 0x80000000 | 8, 0x00095409,
     186, 0x80000000 | 8, 0x00095409,
     187, 0x80000000 | 8, 0x00095409,
     188, 0x80000000 | 8, 0x00095409,
     189, 0x80000000 | 8, 0x00095409,
     190, 0x80000000 | 8, 0x00095409,
     191, 0x80000000 | 8, 0x00095409,
     192, 0x80000000 | 8, 0x00095409,
     193, 0x80000000 | 8, 0x00095409,
     194, 0x80000000 | 8, 0x00095409,
     195, 0x80000000 | 8, 0x00095409,
     196, 0x80000000 | 8, 0x00095409,
     197, 0x80000000 | 8, 0x00095409,
     198, 0x80000000 | 8, 0x00095409,
     199, 0x80000000 | 8, 0x00095409,
     200, 0x80000000 | 8, 0x00095409,
     201, 0x80000000 | 8, 0x00095409,
     202, 0x80000000 | 8, 0x00095409,
     203, 0x80000000 | 8, 0x00095409,
     204, 0x80000000 | 8, 0x00095409,
     205, 0x80000000 | 8, 0x00095409,
     206, 0x80000000 | 8, 0x00095409,
     207, 0x80000000 | 8, 0x00095409,
     208, 0x80000000 | 8, 0x00095409,
     209, 0x80000000 | 8, 0x00095409,
     210, 0x80000000 | 8, 0x00095409,
     211, 0x80000000 | 8, 0x00095409,
     212, 0x80000000 | 8, 0x00095409,
     213, 0x80000000 | 8, 0x00095409,
     214, 0x80000000 | 8, 0x00095409,
     215, 0x80000000 | 8, 0x00095409,
     216, 0x80000000 | 8, 0x00095409,
     217, 0x80000000 | 8, 0x00095409,
     218, 0x80000000 | 8, 0x00095409,
     219, 0x80000000 | 8, 0x00095409,

       0        // eod
};

void DataEngine::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< FieldbusAccessError* >(); break;
        case 1:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< FieldbusAccessErrorModel* >(); break;
        case 119:
        case 99:
        case 98:
        case 97:
        case 96:
        case 76:
        case 70:
        case 67:
        case 54:
        case 53:
        case 4:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< FloatConsumerSignal* >(); break;
        case 213:
        case 212:
        case 211:
        case 210:
        case 209:
        case 208:
        case 207:
        case 206:
        case 205:
        case 204:
        case 203:
        case 202:
        case 201:
        case 200:
        case 199:
        case 198:
        case 197:
        case 196:
        case 195:
        case 194:
        case 193:
        case 192:
        case 191:
        case 190:
        case 189:
        case 188:
        case 187:
        case 186:
        case 185:
        case 184:
        case 183:
        case 182:
        case 181:
        case 180:
        case 179:
        case 178:
        case 177:
        case 176:
        case 175:
        case 174:
        case 173:
        case 172:
        case 171:
        case 170:
        case 169:
        case 168:
        case 167:
        case 166:
        case 165:
        case 164:
        case 163:
        case 162:
        case 161:
        case 160:
        case 159:
        case 158:
        case 157:
        case 156:
        case 155:
        case 154:
        case 153:
        case 152:
        case 151:
        case 150:
        case 149:
        case 148:
        case 147:
        case 146:
        case 145:
        case 144:
        case 143:
        case 142:
        case 141:
        case 140:
        case 139:
        case 138:
        case 137:
        case 136:
        case 135:
        case 134:
        case 133:
        case 132:
        case 131:
        case 130:
        case 129:
        case 128:
        case 127:
        case 126:
        case 125:
        case 124:
        case 123:
        case 122:
        case 121:
        case 120:
        case 118:
        case 117:
        case 116:
        case 115:
        case 114:
        case 113:
        case 112:
        case 111:
        case 110:
        case 109:
        case 108:
        case 107:
        case 106:
        case 105:
        case 104:
        case 103:
        case 102:
        case 101:
        case 100:
        case 95:
        case 94:
        case 93:
        case 92:
        case 91:
        case 90:
        case 89:
        case 88:
        case 87:
        case 86:
        case 85:
        case 84:
        case 83:
        case 82:
        case 81:
        case 80:
        case 79:
        case 78:
        case 77:
        case 75:
        case 74:
        case 73:
        case 72:
        case 71:
        case 69:
        case 68:
        case 66:
        case 65:
        case 64:
        case 63:
        case 62:
        case 61:
        case 60:
        case 59:
        case 58:
        case 57:
        case 56:
        case 55:
        case 52:
        case 51:
        case 50:
        case 49:
        case 48:
        case 47:
        case 46:
        case 45:
        case 44:
        case 43:
        case 42:
        case 41:
        case 40:
        case 39:
        case 38:
        case 37:
        case 36:
        case 35:
        case 34:
        case 33:
        case 32:
        case 31:
        case 30:
        case 29:
        case 28:
        case 27:
        case 26:
        case 25:
        case 24:
        case 23:
        case 22:
        case 21:
        case 20:
        case 19:
        case 18:
        case 17:
        case 16:
        case 15:
        case 14:
        case 13:
        case 12:
        case 11:
        case 10:
        case 9:
        case 8:
        case 7:
        case 6:
        case 5:
        case 3:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< IntConsumerSignal* >(); break;
        case 2:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QByteArrayConsumerSignal* >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        DataEngine *_t = static_cast<DataEngine *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< FieldbusAccessError**>(_v) = _t->fieldbusAccessError(); break;
        case 1: *reinterpret_cast< FieldbusAccessErrorModel**>(_v) = _t->faErrorModel(); break;
        case 2: *reinterpret_cast< QByteArrayConsumerSignal**>(_v) = _t->dm1(); break;
        case 3: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->parameterGroupNumber(); break;
        case 4: *reinterpret_cast< FloatConsumerSignal**>(_v) = _t->opHours_Total(); break;
        case 5: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->brakeSwitch(); break;
        case 6: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->wheelBasedVehicleSpeed(); break;
        case 7: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_DrivingDirection_Blink(); break;
        case 8: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_SeatSwitch(); break;
        case 9: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_WorkingHydraulic(); break;
        case 10: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_SeatSensorFailure(); break;
        case 11: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_AlternatorFailure(); break;
        case 12: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->buzzer(); break;
        case 13: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_CoolingTempTooLow(); break;
        case 14: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_GeneralWarning(); break;
        case 15: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_GeneralError(); break;
        case 16: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_Overspeed(); break;
        case 17: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_LampTest(); break;
        case 18: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_DrivingDirection(); break;
        case 19: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_RabbitTurtle(); break;
        case 20: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_Service(); break;
        case 21: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_ChargeAirTemperature(); break;
        case 22: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_FuelTooLess(); break;
        case 23: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_CoolingTempTooHigh(); break;
        case 24: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_Preheating(); break;
        case 25: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_BlinkerRight(); break;
        case 26: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_BlinkerTrailer(); break;
        case 27: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_HighBeam(); break;
        case 28: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_HydraulicOilFilter(); break;
        case 29: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_HydraulicOilLevel(); break;
        case 30: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_SteeringSystemFailure(); break;
        case 31: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_BeltBuckle(); break;
        case 32: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_TransmissionFault(); break;
        case 33: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_BlinkerLeft(); break;
        case 34: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_AccumulatorPressure(); break;
        case 35: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_ParkingBrake(); break;
        case 36: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_ChargeAirFilter(); break;
        case 37: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_CoolingLevel(); break;
        case 38: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_Alternator(); break;
        case 39: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->adBlueTemperature(); break;
        case 40: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->dPFSootState(); break;
        case 41: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->dPFSootLoad(); break;
        case 42: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->dPFAshloadState(); break;
        case 43: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->dPFAshLoad(); break;
        case 44: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->adBlueTankLevel(); break;
        case 45: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->adBlueTankLevelState(); break;
        case 46: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->additionalCtrlCircuit4_Volume(); break;
        case 47: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->additionalCtrlCircuit3_Volume(); break;
        case 48: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->additionalCtrlCircuit2_Volume(); break;
        case 49: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->additionalCtrlCircuit1_Volume(); break;
        case 50: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->handThrottle(); break;
        case 51: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->footPedal(); break;
        case 52: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->gaugeLoadPressure(); break;
        case 53: *reinterpret_cast< FloatConsumerSignal**>(_v) = _t->machineVelocity(); break;
        case 54: *reinterpret_cast< FloatConsumerSignal**>(_v) = _t->gaugeCoolingTemperature(); break;
        case 55: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->gaugeEngineSpeed(); break;
        case 56: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->cfg_MachineGeneration(); break;
        case 57: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->cfg_MachineBranding(); break;
        case 58: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->cfg_EngineEmissionStandard(); break;
        case 59: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->cfg_EngineSupplier(); break;
        case 60: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->opHours_ACC4(); break;
        case 61: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->opHours_ACC3(); break;
        case 62: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->opHours_ACC2(); break;
        case 63: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->opHours_ACC1(); break;
        case 64: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->opHours_TimeSncLstRegeneration(); break;
        case 65: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->gaugeElectricCurrentConsumption(); break;
        case 66: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->sOH(); break;
        case 67: *reinterpret_cast< FloatConsumerSignal**>(_v) = _t->sOC(); break;
        case 68: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->coolingWaterPumpSpeed(); break;
        case 69: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->coolingFanSpeed(); break;
        case 70: *reinterpret_cast< FloatConsumerSignal**>(_v) = _t->opHours_DailyWorkload(); break;
        case 71: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->opHours_EngineIdleTime(); break;
        case 72: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->opHours_Mission(); break;
        case 73: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->remainingSecondBeforeAutoEngStop(); break;
        case 74: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->hMI_Screen(); break;
        case 75: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->driveMode(); break;
        case 76: *reinterpret_cast< FloatConsumerSignal**>(_v) = _t->fuelLevel(); break;
        case 77: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->coolingTemperature(); break;
        case 78: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->hydraulicTemperature(); break;
        case 79: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->workingMode(); break;
        case 80: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->opHours_ePTO(); break;
        case 81: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->opHours_eDriveTrain(); break;
        case 82: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->remainingBatteryDisChargingTime(); break;
        case 83: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->remainingBatteryChargingTime(); break;
        case 84: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->digitalInputKey12(); break;
        case 85: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->digitalInputKey11(); break;
        case 86: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->digitalInputKey10(); break;
        case 87: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->digitalInputKey09(); break;
        case 88: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->digitalInputKey08(); break;
        case 89: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->digitalInputKey07(); break;
        case 90: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->digitalInputKey06(); break;
        case 91: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->digitalInputKey05(); break;
        case 92: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->digitalInputKey04(); break;
        case 93: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->digitalInputKey03(); break;
        case 94: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->digitalInputKey02(); break;
        case 95: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->digitalInputKey01(); break;
        case 96: *reinterpret_cast< FloatConsumerSignal**>(_v) = _t->lowSideCurrent(); break;
        case 97: *reinterpret_cast< FloatConsumerSignal**>(_v) = _t->highSideVoltage(); break;
        case 98: *reinterpret_cast< FloatConsumerSignal**>(_v) = _t->lowSideVoltage(); break;
        case 99: *reinterpret_cast< FloatConsumerSignal**>(_v) = _t->highSideCurrent(); break;
        case 100: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->zFETC13ePTOActualSpeedFeedback(); break;
        case 101: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->zFETC13ePTOModeIndicator(); break;
        case 102: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->zFETC13ePTOMaximumSpeedFeedback(); break;
        case 103: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->zFETC13ePTORequestedSpeedFdbck(); break;
        case 104: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->zFETC13ePTOMinimumSpeedFeedback(); break;
        case 105: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->immobTransPinMaximumTries(); break;
        case 106: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->immobTransPinLeftTries(); break;
        case 107: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->immobGeneralPinMaximumTries(); break;
        case 108: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->immobGeneralPinLeftTries(); break;
        case 109: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->immobOwnerPinMaximumTries(); break;
        case 110: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->immobOwnerPinLeftTries(); break;
        case 111: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->popUpMessage_Ctrl(); break;
        case 112: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->screenCtrl(); break;
        case 113: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->sOFTTransmissionType(); break;
        case 114: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->sOFTTransmissionPartNumber(); break;
        case 115: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->sOFTSoftwareVersion(); break;
        case 116: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->sOFTSoftwarePartNumber(); break;
        case 117: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->sOFTNmbrOfSftwrIdentFields(); break;
        case 118: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->sOFTCustomerSoftwareNumber(); break;
        case 119: *reinterpret_cast< FloatConsumerSignal**>(_v) = _t->eCU_Batt(); break;
        case 120: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->estPumpingPercentTorque(); break;
        case 121: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->actlMaxAvailableEngPercentTorque(); break;
        case 122: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->sCRThermalManagementActive(); break;
        case 123: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->dPFThermalManagementActive(); break;
        case 124: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->mmntaryEngMaxPowerEnableFeedback(); break;
        case 125: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->vhcleAccelerationRateLimitStatus(); break;
        case 126: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->accelPedalPos2(); break;
        case 127: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->remoteAccelPedalPos(); break;
        case 128: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->engPercentLoadAtCurrentSpeed(); break;
        case 129: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->accelPedalPos1(); break;
        case 130: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->accelPedal2LowIdleSwitch(); break;
        case 131: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->roadSpeedLimitStatus(); break;
        case 132: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->accelPedalKickdownSwitch(); break;
        case 133: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->accelPedal1LowIdleSwitch(); break;
        case 134: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->nSpdSnsrMot(); break;
        case 135: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->pMa(); break;
        case 136: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->pMb(); break;
        case 137: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->nSpdSnsrPmp(); break;
        case 138: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->nSpdSnsrEng(); break;
        case 139: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->msgCntr1(); break;
        case 140: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->msgChks1(); break;
        case 141: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->hMI_ConfigurableInput04_CfgUnusd(); break;
        case 142: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->hMI_ConfigurableInput03_CfgUnusd(); break;
        case 143: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->hMI_ConfigurableInput02_CfgUnusd(); break;
        case 144: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->hMI_ConfigurableInput01_CfgUnusd(); break;
        case 145: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->buzzer_Ctrl(); break;
        case 146: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->digitalOutput02_Ctrl(); break;
        case 147: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->digitalOutput01_Ctrl(); break;
        case 148: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->btnImmobActivation_Ctrl(); break;
        case 149: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->digitalOutput02(); break;
        case 150: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->digitalOutput01(); break;
        case 151: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->btnImmobActivation(); break;
        case 152: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_SOC_Status_Warning(); break;
        case 153: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_SOC_Status_Error(); break;
        case 154: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_HVBatteryOn(); break;
        case 155: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_SOC_Status(); break;
        case 156: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_LowRecuperation(); break;
        case 157: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_ElectricSystemFailure(); break;
        case 158: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_ElectricEngineFailure(); break;
        case 159: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_48VBatteryFailure(); break;
        case 160: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_EngPwrReductionDueToTemp(); break;
        case 161: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_HVWarning(); break;
        case 162: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_HVIsolation(); break;
        case 163: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_HVFailure(); break;
        case 164: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_ElectricEngineStartEnable(); break;
        case 165: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_ChargingPlugConnected(); break;
        case 166: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_ChargingFlapOpened(); break;
        case 167: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_ChargingActive(); break;
        case 168: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_CellBalancing(); break;
        case 169: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_ElectricEngineStartWarning(); break;
        case 170: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_ElectricEngineStartError(); break;
        case 171: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_48VBatteryLowTemperature(); break;
        case 172: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_48VBatteryHighTemperature(); break;
        case 173: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_EngineCoolingFanFailure(); break;
        case 174: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_OilExchangeRequest(); break;
        case 175: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_NCD_Malfunction(); break;
        case 176: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_DPFRegenerationDisabled(); break;
        case 177: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_DPF_ExhaustLamp(); break;
        case 178: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_DPF_AshLoad(); break;
        case 179: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_WaterInFuel(); break;
        case 180: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_DieselExhaustFluid(); break;
        case 181: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_DPFRegeneration(); break;
        case 182: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_EngineWarning(); break;
        case 183: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_EngineFailure(); break;
        case 184: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_EngineOilLevel(); break;
        case 185: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_EngineOilPressure(); break;
        case 186: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_LoadAlarmWarning(); break;
        case 187: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_LoadAlarmError(); break;
        case 188: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_ImmobilzerIsLocked(); break;
        case 189: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_CruiseControlIsActivated(); break;
        case 190: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_ECUWarning(); break;
        case 191: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_ECUFailure(); break;
        case 192: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_TestModeIsActive(); break;
        case 193: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_CanFailure(); break;
        case 194: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_SelectedGear(); break;
        case 195: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_TractionControl_ASR(); break;
        case 196: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_UpperCarrierInPosition(); break;
        case 197: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_ReverseSteering(); break;
        case 198: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_ISOSAE(); break;
        case 199: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_RearPlate(); break;
        case 200: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_FrontPlate(); break;
        case 201: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_RearAxleIsInMiddlePosition(); break;
        case 202: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_FrontAxleIsInMiddlePosition(); break;
        case 203: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_FourWheelSteering(); break;
        case 204: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_CrabSteering(); break;
        case 205: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_BucketControlChangeOver(); break;
        case 206: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_DayNightChangeOver(); break;
        case 207: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_SwingAxleIsLocked(); break;
        case 208: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_QuickHitchIsOpen(); break;
        case 209: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_HydraulicSystemFailure(); break;
        case 210: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_EcoMode(); break;
        case 211: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_AutoIdle(); break;
        case 212: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_AutoEngineStop(); break;
        case 213: *reinterpret_cast< IntConsumerSignal**>(_v) = _t->ind_DrivingDirectionChoosen(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_o);
}

QT_INIT_METAOBJECT const QMetaObject DataEngine::staticMetaObject = { {
    &DataEngineBase::staticMetaObject,
    qt_meta_stringdata_DataEngine.data,
    qt_meta_data_DataEngine,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DataEngine::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DataEngine::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DataEngine.stringdata0))
        return static_cast<void*>(this);
    return DataEngineBase::qt_metacast(_clname);
}

int DataEngine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = DataEngineBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
   if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 214;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 214;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 214;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 214;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 214;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 214;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

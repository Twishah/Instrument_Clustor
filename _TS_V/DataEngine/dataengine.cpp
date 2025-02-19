/* WARNING: AUTO-GENERATED FILE!
 * MANUAL EDITS WILL BE OVERWRITTEN BY "UPDATE PROJECT" IN LINX MANAGER PLUGIN.
 */

#include "dataengine.h"
#include <QVariant>


DataEngine::DataEngine()
{
    // Initialize static members
    m_fieldbusAccessError = new FieldbusAccessError();
    m_faErrorModel = new FieldbusAccessErrorModel();
    connect(m_faErrorModel, &FieldbusAccessErrorModel::errorAdded, this, &DataEngine::handleNewError);
    connect(m_faErrorModel, &FieldbusAccessErrorModel::errorCleared, this, &DataEngine::handleClearedError);
    connect(m_faErrorModel, &FieldbusAccessErrorModel::stackErrorChanged, this, &DataEngine::handleStackError);

    // Prepare signals for dataengine link initiation
	m_dm1 = new QByteArrayConsumerSignal(false, false, QByteArray(), 0);
	SIGNALTYPEDEF dm1Def;
	dm1Def.dataType = DATATYPE_BLOB;
	dm1Def.qtTypeName = "QByteArray";
	dm1Def.signalType = kSignalTypeConsumer;
	dm1Def.persistent = false;
	dm1Def.pgn = 0;
	dm1Def.signal = m_dm1;
	signalTypeDefs["dm1"] = dm1Def;

	m_fieldbusAccess_J1939Error_CAN0 = new ConsumerSignal(false,false,QVariant(QByteArray()));
	SIGNALTYPEDEF fieldbusAccess_J1939Error_CAN0Def;
	fieldbusAccess_J1939Error_CAN0Def.dataType = DATATYPE_BLOB;
	fieldbusAccess_J1939Error_CAN0Def.qtTypeName = "QByteArray";
	fieldbusAccess_J1939Error_CAN0Def.signalType = kSignalTypeConsumer;
	fieldbusAccess_J1939Error_CAN0Def.persistent = false;
	fieldbusAccess_J1939Error_CAN0Def.pgn = -1;
	fieldbusAccess_J1939Error_CAN0Def.signal = m_fieldbusAccess_J1939Error_CAN0;
	signalTypeDefs["fieldbusAccess_J1939Error_CAN0"] = fieldbusAccess_J1939Error_CAN0Def;
	connect(m_fieldbusAccess_J1939Error_CAN0, &ConsumerSignal::valueChanged, this, [this](QVariant value){receiveFieldbusAccess_J1939Error(value, 0);});

	m_parameterGroupNumber = new IntConsumerSignal(false, false, 0, 59944);
	SIGNALTYPEDEF parameterGroupNumberDef;
	parameterGroupNumberDef.dataType = DATATYPE_INT;
	parameterGroupNumberDef.qtTypeName = "int";
	parameterGroupNumberDef.signalType = kSignalTypeConsumer;
	parameterGroupNumberDef.persistent = false;
	parameterGroupNumberDef.pgn = 59944;
	parameterGroupNumberDef.signal = m_parameterGroupNumber;
	signalTypeDefs["parameterGroupNumber"] = parameterGroupNumberDef;

	m_opHours_Total = new FloatConsumerSignal(false, false, 0.0f, 65255);
	SIGNALTYPEDEF opHours_TotalDef;
	opHours_TotalDef.dataType = DATATYPE_FLOAT;
	opHours_TotalDef.qtTypeName = "float";
	opHours_TotalDef.signalType = kSignalTypeConsumer;
	opHours_TotalDef.persistent = false;
	opHours_TotalDef.pgn = 65255;
	opHours_TotalDef.signal = m_opHours_Total;
	signalTypeDefs["opHours_Total"] = opHours_TotalDef;

	m_brakeSwitch = new IntConsumerSignal(false, false, 0, 65265);
	SIGNALTYPEDEF brakeSwitchDef;
	brakeSwitchDef.dataType = DATATYPE_INT;
	brakeSwitchDef.qtTypeName = "int";
	brakeSwitchDef.signalType = kSignalTypeConsumer;
	brakeSwitchDef.persistent = false;
	brakeSwitchDef.pgn = 65265;
	brakeSwitchDef.signal = m_brakeSwitch;
	signalTypeDefs["brakeSwitch"] = brakeSwitchDef;

	m_wheelBasedVehicleSpeed = new IntConsumerSignal(false, false, 0, 65265);
	SIGNALTYPEDEF wheelBasedVehicleSpeedDef;
	wheelBasedVehicleSpeedDef.dataType = DATATYPE_INT;
	wheelBasedVehicleSpeedDef.qtTypeName = "int";
	wheelBasedVehicleSpeedDef.signalType = kSignalTypeConsumer;
	wheelBasedVehicleSpeedDef.persistent = false;
	wheelBasedVehicleSpeedDef.pgn = 65265;
	wheelBasedVehicleSpeedDef.signal = m_wheelBasedVehicleSpeed;
	signalTypeDefs["wheelBasedVehicleSpeed"] = wheelBasedVehicleSpeedDef;

	m_ind_DrivingDirection_Blink = new IntConsumerSignal(false, false, 0, 65472);
	SIGNALTYPEDEF ind_DrivingDirection_BlinkDef;
	ind_DrivingDirection_BlinkDef.dataType = DATATYPE_INT;
	ind_DrivingDirection_BlinkDef.qtTypeName = "int";
	ind_DrivingDirection_BlinkDef.signalType = kSignalTypeConsumer;
	ind_DrivingDirection_BlinkDef.persistent = false;
	ind_DrivingDirection_BlinkDef.pgn = 65472;
	ind_DrivingDirection_BlinkDef.signal = m_ind_DrivingDirection_Blink;
	signalTypeDefs["ind_DrivingDirection_Blink"] = ind_DrivingDirection_BlinkDef;

	m_ind_SeatSwitch = new IntConsumerSignal(false, false, 0, 65472);
	SIGNALTYPEDEF ind_SeatSwitchDef;
	ind_SeatSwitchDef.dataType = DATATYPE_INT;
	ind_SeatSwitchDef.qtTypeName = "int";
	ind_SeatSwitchDef.signalType = kSignalTypeConsumer;
	ind_SeatSwitchDef.persistent = false;
	ind_SeatSwitchDef.pgn = 65472;
	ind_SeatSwitchDef.signal = m_ind_SeatSwitch;
	signalTypeDefs["ind_SeatSwitch"] = ind_SeatSwitchDef;

	m_ind_WorkingHydraulic = new IntConsumerSignal(false, false, 0, 65472);
	SIGNALTYPEDEF ind_WorkingHydraulicDef;
	ind_WorkingHydraulicDef.dataType = DATATYPE_INT;
	ind_WorkingHydraulicDef.qtTypeName = "int";
	ind_WorkingHydraulicDef.signalType = kSignalTypeConsumer;
	ind_WorkingHydraulicDef.persistent = false;
	ind_WorkingHydraulicDef.pgn = 65472;
	ind_WorkingHydraulicDef.signal = m_ind_WorkingHydraulic;
	signalTypeDefs["ind_WorkingHydraulic"] = ind_WorkingHydraulicDef;

	m_ind_SeatSensorFailure = new IntConsumerSignal(false, false, 0, 65472);
	SIGNALTYPEDEF ind_SeatSensorFailureDef;
	ind_SeatSensorFailureDef.dataType = DATATYPE_INT;
	ind_SeatSensorFailureDef.qtTypeName = "int";
	ind_SeatSensorFailureDef.signalType = kSignalTypeConsumer;
	ind_SeatSensorFailureDef.persistent = false;
	ind_SeatSensorFailureDef.pgn = 65472;
	ind_SeatSensorFailureDef.signal = m_ind_SeatSensorFailure;
	signalTypeDefs["ind_SeatSensorFailure"] = ind_SeatSensorFailureDef;

	m_ind_AlternatorFailure = new IntConsumerSignal(false, false, 0, 65472);
	SIGNALTYPEDEF ind_AlternatorFailureDef;
	ind_AlternatorFailureDef.dataType = DATATYPE_INT;
	ind_AlternatorFailureDef.qtTypeName = "int";
	ind_AlternatorFailureDef.signalType = kSignalTypeConsumer;
	ind_AlternatorFailureDef.persistent = false;
	ind_AlternatorFailureDef.pgn = 65472;
	ind_AlternatorFailureDef.signal = m_ind_AlternatorFailure;
	signalTypeDefs["ind_AlternatorFailure"] = ind_AlternatorFailureDef;

	m_buzzer = new IntConsumerSignal(false, false, 0, 65472);
	SIGNALTYPEDEF buzzerDef;
	buzzerDef.dataType = DATATYPE_INT;
	buzzerDef.qtTypeName = "int";
	buzzerDef.signalType = kSignalTypeConsumer;
	buzzerDef.persistent = false;
	buzzerDef.pgn = 65472;
	buzzerDef.signal = m_buzzer;
	signalTypeDefs["buzzer"] = buzzerDef;

	m_ind_CoolingTempTooLow = new IntConsumerSignal(false, false, 0, 65472);
	SIGNALTYPEDEF ind_CoolingTempTooLowDef;
	ind_CoolingTempTooLowDef.dataType = DATATYPE_INT;
	ind_CoolingTempTooLowDef.qtTypeName = "int";
	ind_CoolingTempTooLowDef.signalType = kSignalTypeConsumer;
	ind_CoolingTempTooLowDef.persistent = false;
	ind_CoolingTempTooLowDef.pgn = 65472;
	ind_CoolingTempTooLowDef.signal = m_ind_CoolingTempTooLow;
	signalTypeDefs["ind_CoolingTempTooLow"] = ind_CoolingTempTooLowDef;

	m_ind_GeneralWarning = new IntConsumerSignal(false, false, 0, 65472);
	SIGNALTYPEDEF ind_GeneralWarningDef;
	ind_GeneralWarningDef.dataType = DATATYPE_INT;
	ind_GeneralWarningDef.qtTypeName = "int";
	ind_GeneralWarningDef.signalType = kSignalTypeConsumer;
	ind_GeneralWarningDef.persistent = false;
	ind_GeneralWarningDef.pgn = 65472;
	ind_GeneralWarningDef.signal = m_ind_GeneralWarning;
	signalTypeDefs["ind_GeneralWarning"] = ind_GeneralWarningDef;

	m_ind_GeneralError = new IntConsumerSignal(false, false, 0, 65472);
	SIGNALTYPEDEF ind_GeneralErrorDef;
	ind_GeneralErrorDef.dataType = DATATYPE_INT;
	ind_GeneralErrorDef.qtTypeName = "int";
	ind_GeneralErrorDef.signalType = kSignalTypeConsumer;
	ind_GeneralErrorDef.persistent = false;
	ind_GeneralErrorDef.pgn = 65472;
	ind_GeneralErrorDef.signal = m_ind_GeneralError;
	signalTypeDefs["ind_GeneralError"] = ind_GeneralErrorDef;

	m_ind_Overspeed = new IntConsumerSignal(false, false, 0, 65472);
	SIGNALTYPEDEF ind_OverspeedDef;
	ind_OverspeedDef.dataType = DATATYPE_INT;
	ind_OverspeedDef.qtTypeName = "int";
	ind_OverspeedDef.signalType = kSignalTypeConsumer;
	ind_OverspeedDef.persistent = false;
	ind_OverspeedDef.pgn = 65472;
	ind_OverspeedDef.signal = m_ind_Overspeed;
	signalTypeDefs["ind_Overspeed"] = ind_OverspeedDef;

	m_ind_LampTest = new IntConsumerSignal(false, false, 0, 65472);
	SIGNALTYPEDEF ind_LampTestDef;
	ind_LampTestDef.dataType = DATATYPE_INT;
	ind_LampTestDef.qtTypeName = "int";
	ind_LampTestDef.signalType = kSignalTypeConsumer;
	ind_LampTestDef.persistent = false;
	ind_LampTestDef.pgn = 65472;
	ind_LampTestDef.signal = m_ind_LampTest;
	signalTypeDefs["ind_LampTest"] = ind_LampTestDef;

	m_ind_DrivingDirection = new IntConsumerSignal(false, false, 0, 65472);
	SIGNALTYPEDEF ind_DrivingDirectionDef;
	ind_DrivingDirectionDef.dataType = DATATYPE_INT;
	ind_DrivingDirectionDef.qtTypeName = "int";
	ind_DrivingDirectionDef.signalType = kSignalTypeConsumer;
	ind_DrivingDirectionDef.persistent = false;
	ind_DrivingDirectionDef.pgn = 65472;
	ind_DrivingDirectionDef.signal = m_ind_DrivingDirection;
	signalTypeDefs["ind_DrivingDirection"] = ind_DrivingDirectionDef;

	m_ind_RabbitTurtle = new IntConsumerSignal(false, false, 0, 65472);
	SIGNALTYPEDEF ind_RabbitTurtleDef;
	ind_RabbitTurtleDef.dataType = DATATYPE_INT;
	ind_RabbitTurtleDef.qtTypeName = "int";
	ind_RabbitTurtleDef.signalType = kSignalTypeConsumer;
	ind_RabbitTurtleDef.persistent = false;
	ind_RabbitTurtleDef.pgn = 65472;
	ind_RabbitTurtleDef.signal = m_ind_RabbitTurtle;
	signalTypeDefs["ind_RabbitTurtle"] = ind_RabbitTurtleDef;

	m_ind_Service = new IntConsumerSignal(false, false, 0, 65472);
	SIGNALTYPEDEF ind_ServiceDef;
	ind_ServiceDef.dataType = DATATYPE_INT;
	ind_ServiceDef.qtTypeName = "int";
	ind_ServiceDef.signalType = kSignalTypeConsumer;
	ind_ServiceDef.persistent = false;
	ind_ServiceDef.pgn = 65472;
	ind_ServiceDef.signal = m_ind_Service;
	signalTypeDefs["ind_Service"] = ind_ServiceDef;

	m_ind_ChargeAirTemperature = new IntConsumerSignal(false, false, 0, 65472);
	SIGNALTYPEDEF ind_ChargeAirTemperatureDef;
	ind_ChargeAirTemperatureDef.dataType = DATATYPE_INT;
	ind_ChargeAirTemperatureDef.qtTypeName = "int";
	ind_ChargeAirTemperatureDef.signalType = kSignalTypeConsumer;
	ind_ChargeAirTemperatureDef.persistent = false;
	ind_ChargeAirTemperatureDef.pgn = 65472;
	ind_ChargeAirTemperatureDef.signal = m_ind_ChargeAirTemperature;
	signalTypeDefs["ind_ChargeAirTemperature"] = ind_ChargeAirTemperatureDef;

	m_ind_FuelTooLess = new IntConsumerSignal(false, false, 0, 65472);
	SIGNALTYPEDEF ind_FuelTooLessDef;
	ind_FuelTooLessDef.dataType = DATATYPE_INT;
	ind_FuelTooLessDef.qtTypeName = "int";
	ind_FuelTooLessDef.signalType = kSignalTypeConsumer;
	ind_FuelTooLessDef.persistent = false;
	ind_FuelTooLessDef.pgn = 65472;
	ind_FuelTooLessDef.signal = m_ind_FuelTooLess;
	signalTypeDefs["ind_FuelTooLess"] = ind_FuelTooLessDef;

	m_ind_CoolingTempTooHigh = new IntConsumerSignal(false, false, 0, 65472);
	SIGNALTYPEDEF ind_CoolingTempTooHighDef;
	ind_CoolingTempTooHighDef.dataType = DATATYPE_INT;
	ind_CoolingTempTooHighDef.qtTypeName = "int";
	ind_CoolingTempTooHighDef.signalType = kSignalTypeConsumer;
	ind_CoolingTempTooHighDef.persistent = false;
	ind_CoolingTempTooHighDef.pgn = 65472;
	ind_CoolingTempTooHighDef.signal = m_ind_CoolingTempTooHigh;
	signalTypeDefs["ind_CoolingTempTooHigh"] = ind_CoolingTempTooHighDef;

	m_ind_Preheating = new IntConsumerSignal(false, false, 0, 65472);
	SIGNALTYPEDEF ind_PreheatingDef;
	ind_PreheatingDef.dataType = DATATYPE_INT;
	ind_PreheatingDef.qtTypeName = "int";
	ind_PreheatingDef.signalType = kSignalTypeConsumer;
	ind_PreheatingDef.persistent = false;
	ind_PreheatingDef.pgn = 65472;
	ind_PreheatingDef.signal = m_ind_Preheating;
	signalTypeDefs["ind_Preheating"] = ind_PreheatingDef;

	m_ind_BlinkerRight = new IntConsumerSignal(false, false, 0, 65472);
	SIGNALTYPEDEF ind_BlinkerRightDef;
	ind_BlinkerRightDef.dataType = DATATYPE_INT;
	ind_BlinkerRightDef.qtTypeName = "int";
	ind_BlinkerRightDef.signalType = kSignalTypeConsumer;
	ind_BlinkerRightDef.persistent = false;
	ind_BlinkerRightDef.pgn = 65472;
	ind_BlinkerRightDef.signal = m_ind_BlinkerRight;
	signalTypeDefs["ind_BlinkerRight"] = ind_BlinkerRightDef;

	m_ind_BlinkerTrailer = new IntConsumerSignal(false, false, 0, 65472);
	SIGNALTYPEDEF ind_BlinkerTrailerDef;
	ind_BlinkerTrailerDef.dataType = DATATYPE_INT;
	ind_BlinkerTrailerDef.qtTypeName = "int";
	ind_BlinkerTrailerDef.signalType = kSignalTypeConsumer;
	ind_BlinkerTrailerDef.persistent = false;
	ind_BlinkerTrailerDef.pgn = 65472;
	ind_BlinkerTrailerDef.signal = m_ind_BlinkerTrailer;
	signalTypeDefs["ind_BlinkerTrailer"] = ind_BlinkerTrailerDef;

	m_ind_HighBeam = new IntConsumerSignal(false, false, 0, 65472);
	SIGNALTYPEDEF ind_HighBeamDef;
	ind_HighBeamDef.dataType = DATATYPE_INT;
	ind_HighBeamDef.qtTypeName = "int";
	ind_HighBeamDef.signalType = kSignalTypeConsumer;
	ind_HighBeamDef.persistent = false;
	ind_HighBeamDef.pgn = 65472;
	ind_HighBeamDef.signal = m_ind_HighBeam;
	signalTypeDefs["ind_HighBeam"] = ind_HighBeamDef;

	m_ind_HydraulicOilFilter = new IntConsumerSignal(false, false, 0, 65472);
	SIGNALTYPEDEF ind_HydraulicOilFilterDef;
	ind_HydraulicOilFilterDef.dataType = DATATYPE_INT;
	ind_HydraulicOilFilterDef.qtTypeName = "int";
	ind_HydraulicOilFilterDef.signalType = kSignalTypeConsumer;
	ind_HydraulicOilFilterDef.persistent = false;
	ind_HydraulicOilFilterDef.pgn = 65472;
	ind_HydraulicOilFilterDef.signal = m_ind_HydraulicOilFilter;
	signalTypeDefs["ind_HydraulicOilFilter"] = ind_HydraulicOilFilterDef;

	m_ind_HydraulicOilLevel = new IntConsumerSignal(false, false, 0, 65472);
	SIGNALTYPEDEF ind_HydraulicOilLevelDef;
	ind_HydraulicOilLevelDef.dataType = DATATYPE_INT;
	ind_HydraulicOilLevelDef.qtTypeName = "int";
	ind_HydraulicOilLevelDef.signalType = kSignalTypeConsumer;
	ind_HydraulicOilLevelDef.persistent = false;
	ind_HydraulicOilLevelDef.pgn = 65472;
	ind_HydraulicOilLevelDef.signal = m_ind_HydraulicOilLevel;
	signalTypeDefs["ind_HydraulicOilLevel"] = ind_HydraulicOilLevelDef;

	m_ind_SteeringSystemFailure = new IntConsumerSignal(false, false, 0, 65472);
	SIGNALTYPEDEF ind_SteeringSystemFailureDef;
	ind_SteeringSystemFailureDef.dataType = DATATYPE_INT;
	ind_SteeringSystemFailureDef.qtTypeName = "int";
	ind_SteeringSystemFailureDef.signalType = kSignalTypeConsumer;
	ind_SteeringSystemFailureDef.persistent = false;
	ind_SteeringSystemFailureDef.pgn = 65472;
	ind_SteeringSystemFailureDef.signal = m_ind_SteeringSystemFailure;
	signalTypeDefs["ind_SteeringSystemFailure"] = ind_SteeringSystemFailureDef;

	m_ind_BeltBuckle = new IntConsumerSignal(false, false, 0, 65472);
	SIGNALTYPEDEF ind_BeltBuckleDef;
	ind_BeltBuckleDef.dataType = DATATYPE_INT;
	ind_BeltBuckleDef.qtTypeName = "int";
	ind_BeltBuckleDef.signalType = kSignalTypeConsumer;
	ind_BeltBuckleDef.persistent = false;
	ind_BeltBuckleDef.pgn = 65472;
	ind_BeltBuckleDef.signal = m_ind_BeltBuckle;
	signalTypeDefs["ind_BeltBuckle"] = ind_BeltBuckleDef;

	m_ind_TransmissionFault = new IntConsumerSignal(false, false, 0, 65472);
	SIGNALTYPEDEF ind_TransmissionFaultDef;
	ind_TransmissionFaultDef.dataType = DATATYPE_INT;
	ind_TransmissionFaultDef.qtTypeName = "int";
	ind_TransmissionFaultDef.signalType = kSignalTypeConsumer;
	ind_TransmissionFaultDef.persistent = false;
	ind_TransmissionFaultDef.pgn = 65472;
	ind_TransmissionFaultDef.signal = m_ind_TransmissionFault;
	signalTypeDefs["ind_TransmissionFault"] = ind_TransmissionFaultDef;

	m_ind_BlinkerLeft = new IntConsumerSignal(false, false, 0, 65472);
	SIGNALTYPEDEF ind_BlinkerLeftDef;
	ind_BlinkerLeftDef.dataType = DATATYPE_INT;
	ind_BlinkerLeftDef.qtTypeName = "int";
	ind_BlinkerLeftDef.signalType = kSignalTypeConsumer;
	ind_BlinkerLeftDef.persistent = false;
	ind_BlinkerLeftDef.pgn = 65472;
	ind_BlinkerLeftDef.signal = m_ind_BlinkerLeft;
	signalTypeDefs["ind_BlinkerLeft"] = ind_BlinkerLeftDef;

	m_ind_AccumulatorPressure = new IntConsumerSignal(false, false, 0, 65472);
	SIGNALTYPEDEF ind_AccumulatorPressureDef;
	ind_AccumulatorPressureDef.dataType = DATATYPE_INT;
	ind_AccumulatorPressureDef.qtTypeName = "int";
	ind_AccumulatorPressureDef.signalType = kSignalTypeConsumer;
	ind_AccumulatorPressureDef.persistent = false;
	ind_AccumulatorPressureDef.pgn = 65472;
	ind_AccumulatorPressureDef.signal = m_ind_AccumulatorPressure;
	signalTypeDefs["ind_AccumulatorPressure"] = ind_AccumulatorPressureDef;

	m_ind_ParkingBrake = new IntConsumerSignal(false, false, 0, 65472);
	SIGNALTYPEDEF ind_ParkingBrakeDef;
	ind_ParkingBrakeDef.dataType = DATATYPE_INT;
	ind_ParkingBrakeDef.qtTypeName = "int";
	ind_ParkingBrakeDef.signalType = kSignalTypeConsumer;
	ind_ParkingBrakeDef.persistent = false;
	ind_ParkingBrakeDef.pgn = 65472;
	ind_ParkingBrakeDef.signal = m_ind_ParkingBrake;
	signalTypeDefs["ind_ParkingBrake"] = ind_ParkingBrakeDef;

	m_ind_ChargeAirFilter = new IntConsumerSignal(false, false, 0, 65472);
	SIGNALTYPEDEF ind_ChargeAirFilterDef;
	ind_ChargeAirFilterDef.dataType = DATATYPE_INT;
	ind_ChargeAirFilterDef.qtTypeName = "int";
	ind_ChargeAirFilterDef.signalType = kSignalTypeConsumer;
	ind_ChargeAirFilterDef.persistent = false;
	ind_ChargeAirFilterDef.pgn = 65472;
	ind_ChargeAirFilterDef.signal = m_ind_ChargeAirFilter;
	signalTypeDefs["ind_ChargeAirFilter"] = ind_ChargeAirFilterDef;

	m_ind_CoolingLevel = new IntConsumerSignal(false, false, 0, 65472);
	SIGNALTYPEDEF ind_CoolingLevelDef;
	ind_CoolingLevelDef.dataType = DATATYPE_INT;
	ind_CoolingLevelDef.qtTypeName = "int";
	ind_CoolingLevelDef.signalType = kSignalTypeConsumer;
	ind_CoolingLevelDef.persistent = false;
	ind_CoolingLevelDef.pgn = 65472;
	ind_CoolingLevelDef.signal = m_ind_CoolingLevel;
	signalTypeDefs["ind_CoolingLevel"] = ind_CoolingLevelDef;

	m_ind_Alternator = new IntConsumerSignal(false, false, 0, 65472);
	SIGNALTYPEDEF ind_AlternatorDef;
	ind_AlternatorDef.dataType = DATATYPE_INT;
	ind_AlternatorDef.qtTypeName = "int";
	ind_AlternatorDef.signalType = kSignalTypeConsumer;
	ind_AlternatorDef.persistent = false;
	ind_AlternatorDef.pgn = 65472;
	ind_AlternatorDef.signal = m_ind_Alternator;
	signalTypeDefs["ind_Alternator"] = ind_AlternatorDef;

	m_adBlueTemperature = new IntConsumerSignal(false, false, 0, 65484);
	SIGNALTYPEDEF adBlueTemperatureDef;
	adBlueTemperatureDef.dataType = DATATYPE_INT;
	adBlueTemperatureDef.qtTypeName = "int";
	adBlueTemperatureDef.signalType = kSignalTypeConsumer;
	adBlueTemperatureDef.persistent = false;
	adBlueTemperatureDef.pgn = 65484;
	adBlueTemperatureDef.signal = m_adBlueTemperature;
	signalTypeDefs["adBlueTemperature"] = adBlueTemperatureDef;

	m_dPFSootState = new IntConsumerSignal(false, false, 0, 65484);
	SIGNALTYPEDEF dPFSootStateDef;
	dPFSootStateDef.dataType = DATATYPE_INT;
	dPFSootStateDef.qtTypeName = "int";
	dPFSootStateDef.signalType = kSignalTypeConsumer;
	dPFSootStateDef.persistent = false;
	dPFSootStateDef.pgn = 65484;
	dPFSootStateDef.signal = m_dPFSootState;
	signalTypeDefs["dPFSootState"] = dPFSootStateDef;

	m_dPFSootLoad = new IntConsumerSignal(false, false, 0, 65484);
	SIGNALTYPEDEF dPFSootLoadDef;
	dPFSootLoadDef.dataType = DATATYPE_INT;
	dPFSootLoadDef.qtTypeName = "int";
	dPFSootLoadDef.signalType = kSignalTypeConsumer;
	dPFSootLoadDef.persistent = false;
	dPFSootLoadDef.pgn = 65484;
	dPFSootLoadDef.signal = m_dPFSootLoad;
	signalTypeDefs["dPFSootLoad"] = dPFSootLoadDef;

	m_dPFAshloadState = new IntConsumerSignal(false, false, 0, 65484);
	SIGNALTYPEDEF dPFAshloadStateDef;
	dPFAshloadStateDef.dataType = DATATYPE_INT;
	dPFAshloadStateDef.qtTypeName = "int";
	dPFAshloadStateDef.signalType = kSignalTypeConsumer;
	dPFAshloadStateDef.persistent = false;
	dPFAshloadStateDef.pgn = 65484;
	dPFAshloadStateDef.signal = m_dPFAshloadState;
	signalTypeDefs["dPFAshloadState"] = dPFAshloadStateDef;

	m_dPFAshLoad = new IntConsumerSignal(false, false, 0, 65484);
	SIGNALTYPEDEF dPFAshLoadDef;
	dPFAshLoadDef.dataType = DATATYPE_INT;
	dPFAshLoadDef.qtTypeName = "int";
	dPFAshLoadDef.signalType = kSignalTypeConsumer;
	dPFAshLoadDef.persistent = false;
	dPFAshLoadDef.pgn = 65484;
	dPFAshLoadDef.signal = m_dPFAshLoad;
	signalTypeDefs["dPFAshLoad"] = dPFAshLoadDef;

	m_adBlueTankLevel = new IntConsumerSignal(false, false, 0, 65484);
	SIGNALTYPEDEF adBlueTankLevelDef;
	adBlueTankLevelDef.dataType = DATATYPE_INT;
	adBlueTankLevelDef.qtTypeName = "int";
	adBlueTankLevelDef.signalType = kSignalTypeConsumer;
	adBlueTankLevelDef.persistent = false;
	adBlueTankLevelDef.pgn = 65484;
	adBlueTankLevelDef.signal = m_adBlueTankLevel;
	signalTypeDefs["adBlueTankLevel"] = adBlueTankLevelDef;

	m_adBlueTankLevelState = new IntConsumerSignal(false, false, 0, 65484);
	SIGNALTYPEDEF adBlueTankLevelStateDef;
	adBlueTankLevelStateDef.dataType = DATATYPE_INT;
	adBlueTankLevelStateDef.qtTypeName = "int";
	adBlueTankLevelStateDef.signalType = kSignalTypeConsumer;
	adBlueTankLevelStateDef.persistent = false;
	adBlueTankLevelStateDef.pgn = 65484;
	adBlueTankLevelStateDef.signal = m_adBlueTankLevelState;
	signalTypeDefs["adBlueTankLevelState"] = adBlueTankLevelStateDef;

	m_additionalCtrlCircuit4_Volume = new IntConsumerSignal(false, false, 0, 65485);
	SIGNALTYPEDEF additionalCtrlCircuit4_VolumeDef;
	additionalCtrlCircuit4_VolumeDef.dataType = DATATYPE_INT;
	additionalCtrlCircuit4_VolumeDef.qtTypeName = "int";
	additionalCtrlCircuit4_VolumeDef.signalType = kSignalTypeConsumer;
	additionalCtrlCircuit4_VolumeDef.persistent = false;
	additionalCtrlCircuit4_VolumeDef.pgn = 65485;
	additionalCtrlCircuit4_VolumeDef.signal = m_additionalCtrlCircuit4_Volume;
	signalTypeDefs["additionalCtrlCircuit4_Volume"] = additionalCtrlCircuit4_VolumeDef;

	m_additionalCtrlCircuit3_Volume = new IntConsumerSignal(false, false, 0, 65485);
	SIGNALTYPEDEF additionalCtrlCircuit3_VolumeDef;
	additionalCtrlCircuit3_VolumeDef.dataType = DATATYPE_INT;
	additionalCtrlCircuit3_VolumeDef.qtTypeName = "int";
	additionalCtrlCircuit3_VolumeDef.signalType = kSignalTypeConsumer;
	additionalCtrlCircuit3_VolumeDef.persistent = false;
	additionalCtrlCircuit3_VolumeDef.pgn = 65485;
	additionalCtrlCircuit3_VolumeDef.signal = m_additionalCtrlCircuit3_Volume;
	signalTypeDefs["additionalCtrlCircuit3_Volume"] = additionalCtrlCircuit3_VolumeDef;

	m_additionalCtrlCircuit2_Volume = new IntConsumerSignal(false, false, 0, 65485);
	SIGNALTYPEDEF additionalCtrlCircuit2_VolumeDef;
	additionalCtrlCircuit2_VolumeDef.dataType = DATATYPE_INT;
	additionalCtrlCircuit2_VolumeDef.qtTypeName = "int";
	additionalCtrlCircuit2_VolumeDef.signalType = kSignalTypeConsumer;
	additionalCtrlCircuit2_VolumeDef.persistent = false;
	additionalCtrlCircuit2_VolumeDef.pgn = 65485;
	additionalCtrlCircuit2_VolumeDef.signal = m_additionalCtrlCircuit2_Volume;
	signalTypeDefs["additionalCtrlCircuit2_Volume"] = additionalCtrlCircuit2_VolumeDef;

	m_additionalCtrlCircuit1_Volume = new IntConsumerSignal(false, false, 0, 65485);
	SIGNALTYPEDEF additionalCtrlCircuit1_VolumeDef;
	additionalCtrlCircuit1_VolumeDef.dataType = DATATYPE_INT;
	additionalCtrlCircuit1_VolumeDef.qtTypeName = "int";
	additionalCtrlCircuit1_VolumeDef.signalType = kSignalTypeConsumer;
	additionalCtrlCircuit1_VolumeDef.persistent = false;
	additionalCtrlCircuit1_VolumeDef.pgn = 65485;
	additionalCtrlCircuit1_VolumeDef.signal = m_additionalCtrlCircuit1_Volume;
	signalTypeDefs["additionalCtrlCircuit1_Volume"] = additionalCtrlCircuit1_VolumeDef;

	m_handThrottle = new IntConsumerSignal(false, false, 0, 65487);
	SIGNALTYPEDEF handThrottleDef;
	handThrottleDef.dataType = DATATYPE_INT;
	handThrottleDef.qtTypeName = "int";
	handThrottleDef.signalType = kSignalTypeConsumer;
	handThrottleDef.persistent = false;
	handThrottleDef.pgn = 65487;
	handThrottleDef.signal = m_handThrottle;
	signalTypeDefs["handThrottle"] = handThrottleDef;

	m_footPedal = new IntConsumerSignal(false, false, 0, 65487);
	SIGNALTYPEDEF footPedalDef;
	footPedalDef.dataType = DATATYPE_INT;
	footPedalDef.qtTypeName = "int";
	footPedalDef.signalType = kSignalTypeConsumer;
	footPedalDef.persistent = false;
	footPedalDef.pgn = 65487;
	footPedalDef.signal = m_footPedal;
	signalTypeDefs["footPedal"] = footPedalDef;

	m_gaugeLoadPressure = new IntConsumerSignal(false, false, 0, 65487);
	SIGNALTYPEDEF gaugeLoadPressureDef;
	gaugeLoadPressureDef.dataType = DATATYPE_INT;
	gaugeLoadPressureDef.qtTypeName = "int";
	gaugeLoadPressureDef.signalType = kSignalTypeConsumer;
	gaugeLoadPressureDef.persistent = false;
	gaugeLoadPressureDef.pgn = 65487;
	gaugeLoadPressureDef.signal = m_gaugeLoadPressure;
	signalTypeDefs["gaugeLoadPressure"] = gaugeLoadPressureDef;

	m_machineVelocity = new FloatConsumerSignal(false, false, 0.0f, 65487);
	SIGNALTYPEDEF machineVelocityDef;
	machineVelocityDef.dataType = DATATYPE_FLOAT;
	machineVelocityDef.qtTypeName = "float";
	machineVelocityDef.signalType = kSignalTypeConsumer;
	machineVelocityDef.persistent = false;
	machineVelocityDef.pgn = 65487;
	machineVelocityDef.signal = m_machineVelocity;
	signalTypeDefs["machineVelocity"] = machineVelocityDef;

	m_gaugeCoolingTemperature = new FloatConsumerSignal(false, false, 0.0f, 65487);
	SIGNALTYPEDEF gaugeCoolingTemperatureDef;
	gaugeCoolingTemperatureDef.dataType = DATATYPE_FLOAT;
	gaugeCoolingTemperatureDef.qtTypeName = "float";
	gaugeCoolingTemperatureDef.signalType = kSignalTypeConsumer;
	gaugeCoolingTemperatureDef.persistent = false;
	gaugeCoolingTemperatureDef.pgn = 65487;
	gaugeCoolingTemperatureDef.signal = m_gaugeCoolingTemperature;
	signalTypeDefs["gaugeCoolingTemperature"] = gaugeCoolingTemperatureDef;

	m_gaugeEngineSpeed = new IntConsumerSignal(false, false, 0, 65487);
	SIGNALTYPEDEF gaugeEngineSpeedDef;
	gaugeEngineSpeedDef.dataType = DATATYPE_INT;
	gaugeEngineSpeedDef.qtTypeName = "int";
	gaugeEngineSpeedDef.signalType = kSignalTypeConsumer;
	gaugeEngineSpeedDef.persistent = false;
	gaugeEngineSpeedDef.pgn = 65487;
	gaugeEngineSpeedDef.signal = m_gaugeEngineSpeed;
	signalTypeDefs["gaugeEngineSpeed"] = gaugeEngineSpeedDef;

	m_cfg_MachineGeneration = new IntConsumerSignal(false, false, 0, 65495);
	SIGNALTYPEDEF cfg_MachineGenerationDef;
	cfg_MachineGenerationDef.dataType = DATATYPE_INT;
	cfg_MachineGenerationDef.qtTypeName = "int";
	cfg_MachineGenerationDef.signalType = kSignalTypeConsumer;
	cfg_MachineGenerationDef.persistent = false;
	cfg_MachineGenerationDef.pgn = 65495;
	cfg_MachineGenerationDef.signal = m_cfg_MachineGeneration;
	signalTypeDefs["cfg_MachineGeneration"] = cfg_MachineGenerationDef;

	m_cfg_MachineBranding = new IntConsumerSignal(false, false, 0, 65495);
	SIGNALTYPEDEF cfg_MachineBrandingDef;
	cfg_MachineBrandingDef.dataType = DATATYPE_INT;
	cfg_MachineBrandingDef.qtTypeName = "int";
	cfg_MachineBrandingDef.signalType = kSignalTypeConsumer;
	cfg_MachineBrandingDef.persistent = false;
	cfg_MachineBrandingDef.pgn = 65495;
	cfg_MachineBrandingDef.signal = m_cfg_MachineBranding;
	signalTypeDefs["cfg_MachineBranding"] = cfg_MachineBrandingDef;

	m_cfg_EngineEmissionStandard = new IntConsumerSignal(false, false, 0, 65495);
	SIGNALTYPEDEF cfg_EngineEmissionStandardDef;
	cfg_EngineEmissionStandardDef.dataType = DATATYPE_INT;
	cfg_EngineEmissionStandardDef.qtTypeName = "int";
	cfg_EngineEmissionStandardDef.signalType = kSignalTypeConsumer;
	cfg_EngineEmissionStandardDef.persistent = false;
	cfg_EngineEmissionStandardDef.pgn = 65495;
	cfg_EngineEmissionStandardDef.signal = m_cfg_EngineEmissionStandard;
	signalTypeDefs["cfg_EngineEmissionStandard"] = cfg_EngineEmissionStandardDef;

	m_cfg_EngineSupplier = new IntConsumerSignal(false, false, 0, 65495);
	SIGNALTYPEDEF cfg_EngineSupplierDef;
	cfg_EngineSupplierDef.dataType = DATATYPE_INT;
	cfg_EngineSupplierDef.qtTypeName = "int";
	cfg_EngineSupplierDef.signalType = kSignalTypeConsumer;
	cfg_EngineSupplierDef.persistent = false;
	cfg_EngineSupplierDef.pgn = 65495;
	cfg_EngineSupplierDef.signal = m_cfg_EngineSupplier;
	signalTypeDefs["cfg_EngineSupplier"] = cfg_EngineSupplierDef;

	m_opHours_ACC4 = new IntConsumerSignal(false, false, 0, 65505);
	SIGNALTYPEDEF opHours_ACC4Def;
	opHours_ACC4Def.dataType = DATATYPE_INT;
	opHours_ACC4Def.qtTypeName = "int";
	opHours_ACC4Def.signalType = kSignalTypeConsumer;
	opHours_ACC4Def.persistent = false;
	opHours_ACC4Def.pgn = 65505;
	opHours_ACC4Def.signal = m_opHours_ACC4;
	signalTypeDefs["opHours_ACC4"] = opHours_ACC4Def;

	m_opHours_ACC3 = new IntConsumerSignal(false, false, 0, 65505);
	SIGNALTYPEDEF opHours_ACC3Def;
	opHours_ACC3Def.dataType = DATATYPE_INT;
	opHours_ACC3Def.qtTypeName = "int";
	opHours_ACC3Def.signalType = kSignalTypeConsumer;
	opHours_ACC3Def.persistent = false;
	opHours_ACC3Def.pgn = 65505;
	opHours_ACC3Def.signal = m_opHours_ACC3;
	signalTypeDefs["opHours_ACC3"] = opHours_ACC3Def;

	m_opHours_ACC2 = new IntConsumerSignal(false, false, 0, 65505);
	SIGNALTYPEDEF opHours_ACC2Def;
	opHours_ACC2Def.dataType = DATATYPE_INT;
	opHours_ACC2Def.qtTypeName = "int";
	opHours_ACC2Def.signalType = kSignalTypeConsumer;
	opHours_ACC2Def.persistent = false;
	opHours_ACC2Def.pgn = 65505;
	opHours_ACC2Def.signal = m_opHours_ACC2;
	signalTypeDefs["opHours_ACC2"] = opHours_ACC2Def;

	m_opHours_ACC1 = new IntConsumerSignal(false, false, 0, 65505);
	SIGNALTYPEDEF opHours_ACC1Def;
	opHours_ACC1Def.dataType = DATATYPE_INT;
	opHours_ACC1Def.qtTypeName = "int";
	opHours_ACC1Def.signalType = kSignalTypeConsumer;
	opHours_ACC1Def.persistent = false;
	opHours_ACC1Def.pgn = 65505;
	opHours_ACC1Def.signal = m_opHours_ACC1;
	signalTypeDefs["opHours_ACC1"] = opHours_ACC1Def;

	m_opHours_TimeSncLstRegeneration = new IntConsumerSignal(false, false, 0, 65507);
	SIGNALTYPEDEF opHours_TimeSncLstRegenerationDef;
	opHours_TimeSncLstRegenerationDef.dataType = DATATYPE_INT;
	opHours_TimeSncLstRegenerationDef.qtTypeName = "int";
	opHours_TimeSncLstRegenerationDef.signalType = kSignalTypeConsumer;
	opHours_TimeSncLstRegenerationDef.persistent = false;
	opHours_TimeSncLstRegenerationDef.pgn = 65507;
	opHours_TimeSncLstRegenerationDef.signal = m_opHours_TimeSncLstRegeneration;
	signalTypeDefs["opHours_TimeSncLstRegeneration"] = opHours_TimeSncLstRegenerationDef;

	m_gaugeElectricCurrentConsumption = new IntConsumerSignal(false, false, 0, 65483);
	SIGNALTYPEDEF gaugeElectricCurrentConsumptionDef;
	gaugeElectricCurrentConsumptionDef.dataType = DATATYPE_INT;
	gaugeElectricCurrentConsumptionDef.qtTypeName = "int";
	gaugeElectricCurrentConsumptionDef.signalType = kSignalTypeConsumer;
	gaugeElectricCurrentConsumptionDef.persistent = false;
	gaugeElectricCurrentConsumptionDef.pgn = 65483;
	gaugeElectricCurrentConsumptionDef.signal = m_gaugeElectricCurrentConsumption;
	signalTypeDefs["gaugeElectricCurrentConsumption"] = gaugeElectricCurrentConsumptionDef;

	m_sOH = new IntConsumerSignal(false, false, 0, 65483);
	SIGNALTYPEDEF sOHDef;
	sOHDef.dataType = DATATYPE_INT;
	sOHDef.qtTypeName = "int";
	sOHDef.signalType = kSignalTypeConsumer;
	sOHDef.persistent = false;
	sOHDef.pgn = 65483;
	sOHDef.signal = m_sOH;
	signalTypeDefs["sOH"] = sOHDef;

	m_sOC = new FloatConsumerSignal(false, false, 0.0f, 65483);
	SIGNALTYPEDEF sOCDef;
	sOCDef.dataType = DATATYPE_FLOAT;
	sOCDef.qtTypeName = "float";
	sOCDef.signalType = kSignalTypeConsumer;
	sOCDef.persistent = false;
	sOCDef.pgn = 65483;
	sOCDef.signal = m_sOC;
	signalTypeDefs["sOC"] = sOCDef;

	m_coolingWaterPumpSpeed = new IntConsumerSignal(false, false, 0, 65483);
	SIGNALTYPEDEF coolingWaterPumpSpeedDef;
	coolingWaterPumpSpeedDef.dataType = DATATYPE_INT;
	coolingWaterPumpSpeedDef.qtTypeName = "int";
	coolingWaterPumpSpeedDef.signalType = kSignalTypeConsumer;
	coolingWaterPumpSpeedDef.persistent = false;
	coolingWaterPumpSpeedDef.pgn = 65483;
	coolingWaterPumpSpeedDef.signal = m_coolingWaterPumpSpeed;
	signalTypeDefs["coolingWaterPumpSpeed"] = coolingWaterPumpSpeedDef;

	m_coolingFanSpeed = new IntConsumerSignal(false, false, 0, 65483);
	SIGNALTYPEDEF coolingFanSpeedDef;
	coolingFanSpeedDef.dataType = DATATYPE_INT;
	coolingFanSpeedDef.qtTypeName = "int";
	coolingFanSpeedDef.signalType = kSignalTypeConsumer;
	coolingFanSpeedDef.persistent = false;
	coolingFanSpeedDef.pgn = 65483;
	coolingFanSpeedDef.signal = m_coolingFanSpeed;
	signalTypeDefs["coolingFanSpeed"] = coolingFanSpeedDef;

	m_opHours_DailyWorkload = new FloatConsumerSignal(false, false, 0.0f, 65504);
	SIGNALTYPEDEF opHours_DailyWorkloadDef;
	opHours_DailyWorkloadDef.dataType = DATATYPE_FLOAT;
	opHours_DailyWorkloadDef.qtTypeName = "float";
	opHours_DailyWorkloadDef.signalType = kSignalTypeConsumer;
	opHours_DailyWorkloadDef.persistent = false;
	opHours_DailyWorkloadDef.pgn = 65504;
	opHours_DailyWorkloadDef.signal = m_opHours_DailyWorkload;
	signalTypeDefs["opHours_DailyWorkload"] = opHours_DailyWorkloadDef;

	m_opHours_EngineIdleTime = new IntConsumerSignal(false, false, 0, 65504);
	SIGNALTYPEDEF opHours_EngineIdleTimeDef;
	opHours_EngineIdleTimeDef.dataType = DATATYPE_INT;
	opHours_EngineIdleTimeDef.qtTypeName = "int";
	opHours_EngineIdleTimeDef.signalType = kSignalTypeConsumer;
	opHours_EngineIdleTimeDef.persistent = false;
	opHours_EngineIdleTimeDef.pgn = 65504;
	opHours_EngineIdleTimeDef.signal = m_opHours_EngineIdleTime;
	signalTypeDefs["opHours_EngineIdleTime"] = opHours_EngineIdleTimeDef;

	m_opHours_Mission = new IntConsumerSignal(false, false, 0, 65504);
	SIGNALTYPEDEF opHours_MissionDef;
	opHours_MissionDef.dataType = DATATYPE_INT;
	opHours_MissionDef.qtTypeName = "int";
	opHours_MissionDef.signalType = kSignalTypeConsumer;
	opHours_MissionDef.persistent = false;
	opHours_MissionDef.pgn = 65504;
	opHours_MissionDef.signal = m_opHours_Mission;
	signalTypeDefs["opHours_Mission"] = opHours_MissionDef;

	m_remainingSecondBeforeAutoEngStop = new IntConsumerSignal(false, false, 0, 65486);
	SIGNALTYPEDEF remainingSecondBeforeAutoEngStopDef;
	remainingSecondBeforeAutoEngStopDef.dataType = DATATYPE_INT;
	remainingSecondBeforeAutoEngStopDef.qtTypeName = "int";
	remainingSecondBeforeAutoEngStopDef.signalType = kSignalTypeConsumer;
	remainingSecondBeforeAutoEngStopDef.persistent = false;
	remainingSecondBeforeAutoEngStopDef.pgn = 65486;
	remainingSecondBeforeAutoEngStopDef.signal = m_remainingSecondBeforeAutoEngStop;
	signalTypeDefs["remainingSecondBeforeAutoEngStop"] = remainingSecondBeforeAutoEngStopDef;

	m_hMI_Screen = new IntConsumerSignal(false, false, 0, 65486);
	SIGNALTYPEDEF hMI_ScreenDef;
	hMI_ScreenDef.dataType = DATATYPE_INT;
	hMI_ScreenDef.qtTypeName = "int";
	hMI_ScreenDef.signalType = kSignalTypeConsumer;
	hMI_ScreenDef.persistent = false;
	hMI_ScreenDef.pgn = 65486;
	hMI_ScreenDef.signal = m_hMI_Screen;
	signalTypeDefs["hMI_Screen"] = hMI_ScreenDef;

	m_driveMode = new IntConsumerSignal(false, false, 0, 65486);
	SIGNALTYPEDEF driveModeDef;
	driveModeDef.dataType = DATATYPE_INT;
	driveModeDef.qtTypeName = "int";
	driveModeDef.signalType = kSignalTypeConsumer;
	driveModeDef.persistent = false;
	driveModeDef.pgn = 65486;
	driveModeDef.signal = m_driveMode;
	signalTypeDefs["driveMode"] = driveModeDef;

	m_fuelLevel = new FloatConsumerSignal(false, false, 0.0f, 65486);
	SIGNALTYPEDEF fuelLevelDef;
	fuelLevelDef.dataType = DATATYPE_FLOAT;
	fuelLevelDef.qtTypeName = "float";
	fuelLevelDef.signalType = kSignalTypeConsumer;
	fuelLevelDef.persistent = false;
	fuelLevelDef.pgn = 65486;
	fuelLevelDef.signal = m_fuelLevel;
	signalTypeDefs["fuelLevel"] = fuelLevelDef;

	m_coolingTemperature = new IntConsumerSignal(false, false, 0, 65486);
	SIGNALTYPEDEF coolingTemperatureDef;
	coolingTemperatureDef.dataType = DATATYPE_INT;
	coolingTemperatureDef.qtTypeName = "int";
	coolingTemperatureDef.signalType = kSignalTypeConsumer;
	coolingTemperatureDef.persistent = false;
	coolingTemperatureDef.pgn = 65486;
	coolingTemperatureDef.signal = m_coolingTemperature;
	signalTypeDefs["coolingTemperature"] = coolingTemperatureDef;

	m_hydraulicTemperature = new IntConsumerSignal(false, false, 0, 65486);
	SIGNALTYPEDEF hydraulicTemperatureDef;
	hydraulicTemperatureDef.dataType = DATATYPE_INT;
	hydraulicTemperatureDef.qtTypeName = "int";
	hydraulicTemperatureDef.signalType = kSignalTypeConsumer;
	hydraulicTemperatureDef.persistent = false;
	hydraulicTemperatureDef.pgn = 65486;
	hydraulicTemperatureDef.signal = m_hydraulicTemperature;
	signalTypeDefs["hydraulicTemperature"] = hydraulicTemperatureDef;

	m_workingMode = new IntConsumerSignal(false, false, 0, 65486);
	SIGNALTYPEDEF workingModeDef;
	workingModeDef.dataType = DATATYPE_INT;
	workingModeDef.qtTypeName = "int";
	workingModeDef.signalType = kSignalTypeConsumer;
	workingModeDef.persistent = false;
	workingModeDef.pgn = 65486;
	workingModeDef.signal = m_workingMode;
	signalTypeDefs["workingMode"] = workingModeDef;

	m_opHours_ePTO = new IntConsumerSignal(false, false, 0, 65508);
	SIGNALTYPEDEF opHours_ePTODef;
	opHours_ePTODef.dataType = DATATYPE_INT;
	opHours_ePTODef.qtTypeName = "int";
	opHours_ePTODef.signalType = kSignalTypeConsumer;
	opHours_ePTODef.persistent = false;
	opHours_ePTODef.pgn = 65508;
	opHours_ePTODef.signal = m_opHours_ePTO;
	signalTypeDefs["opHours_ePTO"] = opHours_ePTODef;

	m_opHours_eDriveTrain = new IntConsumerSignal(false, false, 0, 65508);
	SIGNALTYPEDEF opHours_eDriveTrainDef;
	opHours_eDriveTrainDef.dataType = DATATYPE_INT;
	opHours_eDriveTrainDef.qtTypeName = "int";
	opHours_eDriveTrainDef.signalType = kSignalTypeConsumer;
	opHours_eDriveTrainDef.persistent = false;
	opHours_eDriveTrainDef.pgn = 65508;
	opHours_eDriveTrainDef.signal = m_opHours_eDriveTrain;
	signalTypeDefs["opHours_eDriveTrain"] = opHours_eDriveTrainDef;

	m_remainingBatteryDisChargingTime = new IntConsumerSignal(false, false, 0, 65508);
	SIGNALTYPEDEF remainingBatteryDisChargingTimeDef;
	remainingBatteryDisChargingTimeDef.dataType = DATATYPE_INT;
	remainingBatteryDisChargingTimeDef.qtTypeName = "int";
	remainingBatteryDisChargingTimeDef.signalType = kSignalTypeConsumer;
	remainingBatteryDisChargingTimeDef.persistent = false;
	remainingBatteryDisChargingTimeDef.pgn = 65508;
	remainingBatteryDisChargingTimeDef.signal = m_remainingBatteryDisChargingTime;
	signalTypeDefs["remainingBatteryDisChargingTime"] = remainingBatteryDisChargingTimeDef;

	m_remainingBatteryChargingTime = new IntConsumerSignal(false, false, 0, 65508);
	SIGNALTYPEDEF remainingBatteryChargingTimeDef;
	remainingBatteryChargingTimeDef.dataType = DATATYPE_INT;
	remainingBatteryChargingTimeDef.qtTypeName = "int";
	remainingBatteryChargingTimeDef.signalType = kSignalTypeConsumer;
	remainingBatteryChargingTimeDef.persistent = false;
	remainingBatteryChargingTimeDef.pgn = 65508;
	remainingBatteryChargingTimeDef.signal = m_remainingBatteryChargingTime;
	signalTypeDefs["remainingBatteryChargingTime"] = remainingBatteryChargingTimeDef;

	m_digitalInputKey12 = new IntConsumerSignal(false, false, 0, 65241);
	SIGNALTYPEDEF digitalInputKey12Def;
	digitalInputKey12Def.dataType = DATATYPE_INT;
	digitalInputKey12Def.qtTypeName = "int";
	digitalInputKey12Def.signalType = kSignalTypeConsumer;
	digitalInputKey12Def.persistent = false;
	digitalInputKey12Def.pgn = 65241;
	digitalInputKey12Def.signal = m_digitalInputKey12;
	signalTypeDefs["digitalInputKey12"] = digitalInputKey12Def;

	m_digitalInputKey11 = new IntConsumerSignal(false, false, 0, 65241);
	SIGNALTYPEDEF digitalInputKey11Def;
	digitalInputKey11Def.dataType = DATATYPE_INT;
	digitalInputKey11Def.qtTypeName = "int";
	digitalInputKey11Def.signalType = kSignalTypeConsumer;
	digitalInputKey11Def.persistent = false;
	digitalInputKey11Def.pgn = 65241;
	digitalInputKey11Def.signal = m_digitalInputKey11;
	signalTypeDefs["digitalInputKey11"] = digitalInputKey11Def;

	m_digitalInputKey10 = new IntConsumerSignal(false, false, 0, 65241);
	SIGNALTYPEDEF digitalInputKey10Def;
	digitalInputKey10Def.dataType = DATATYPE_INT;
	digitalInputKey10Def.qtTypeName = "int";
	digitalInputKey10Def.signalType = kSignalTypeConsumer;
	digitalInputKey10Def.persistent = false;
	digitalInputKey10Def.pgn = 65241;
	digitalInputKey10Def.signal = m_digitalInputKey10;
	signalTypeDefs["digitalInputKey10"] = digitalInputKey10Def;

	m_digitalInputKey09 = new IntConsumerSignal(false, false, 0, 65241);
	SIGNALTYPEDEF digitalInputKey09Def;
	digitalInputKey09Def.dataType = DATATYPE_INT;
	digitalInputKey09Def.qtTypeName = "int";
	digitalInputKey09Def.signalType = kSignalTypeConsumer;
	digitalInputKey09Def.persistent = false;
	digitalInputKey09Def.pgn = 65241;
	digitalInputKey09Def.signal = m_digitalInputKey09;
	signalTypeDefs["digitalInputKey09"] = digitalInputKey09Def;

	m_digitalInputKey08 = new IntConsumerSignal(false, false, 0, 65241);
	SIGNALTYPEDEF digitalInputKey08Def;
	digitalInputKey08Def.dataType = DATATYPE_INT;
	digitalInputKey08Def.qtTypeName = "int";
	digitalInputKey08Def.signalType = kSignalTypeConsumer;
	digitalInputKey08Def.persistent = false;
	digitalInputKey08Def.pgn = 65241;
	digitalInputKey08Def.signal = m_digitalInputKey08;
	signalTypeDefs["digitalInputKey08"] = digitalInputKey08Def;

	m_digitalInputKey07 = new IntConsumerSignal(false, false, 0, 65241);
	SIGNALTYPEDEF digitalInputKey07Def;
	digitalInputKey07Def.dataType = DATATYPE_INT;
	digitalInputKey07Def.qtTypeName = "int";
	digitalInputKey07Def.signalType = kSignalTypeConsumer;
	digitalInputKey07Def.persistent = false;
	digitalInputKey07Def.pgn = 65241;
	digitalInputKey07Def.signal = m_digitalInputKey07;
	signalTypeDefs["digitalInputKey07"] = digitalInputKey07Def;

	m_digitalInputKey06 = new IntConsumerSignal(false, false, 0, 65241);
	SIGNALTYPEDEF digitalInputKey06Def;
	digitalInputKey06Def.dataType = DATATYPE_INT;
	digitalInputKey06Def.qtTypeName = "int";
	digitalInputKey06Def.signalType = kSignalTypeConsumer;
	digitalInputKey06Def.persistent = false;
	digitalInputKey06Def.pgn = 65241;
	digitalInputKey06Def.signal = m_digitalInputKey06;
	signalTypeDefs["digitalInputKey06"] = digitalInputKey06Def;

	m_digitalInputKey05 = new IntConsumerSignal(false, false, 0, 65241);
	SIGNALTYPEDEF digitalInputKey05Def;
	digitalInputKey05Def.dataType = DATATYPE_INT;
	digitalInputKey05Def.qtTypeName = "int";
	digitalInputKey05Def.signalType = kSignalTypeConsumer;
	digitalInputKey05Def.persistent = false;
	digitalInputKey05Def.pgn = 65241;
	digitalInputKey05Def.signal = m_digitalInputKey05;
	signalTypeDefs["digitalInputKey05"] = digitalInputKey05Def;

	m_digitalInputKey04 = new IntConsumerSignal(false, false, 0, 65241);
	SIGNALTYPEDEF digitalInputKey04Def;
	digitalInputKey04Def.dataType = DATATYPE_INT;
	digitalInputKey04Def.qtTypeName = "int";
	digitalInputKey04Def.signalType = kSignalTypeConsumer;
	digitalInputKey04Def.persistent = false;
	digitalInputKey04Def.pgn = 65241;
	digitalInputKey04Def.signal = m_digitalInputKey04;
	signalTypeDefs["digitalInputKey04"] = digitalInputKey04Def;

	m_digitalInputKey03 = new IntConsumerSignal(false, false, 0, 65241);
	SIGNALTYPEDEF digitalInputKey03Def;
	digitalInputKey03Def.dataType = DATATYPE_INT;
	digitalInputKey03Def.qtTypeName = "int";
	digitalInputKey03Def.signalType = kSignalTypeConsumer;
	digitalInputKey03Def.persistent = false;
	digitalInputKey03Def.pgn = 65241;
	digitalInputKey03Def.signal = m_digitalInputKey03;
	signalTypeDefs["digitalInputKey03"] = digitalInputKey03Def;

	m_digitalInputKey02 = new IntConsumerSignal(false, false, 0, 65241);
	SIGNALTYPEDEF digitalInputKey02Def;
	digitalInputKey02Def.dataType = DATATYPE_INT;
	digitalInputKey02Def.qtTypeName = "int";
	digitalInputKey02Def.signalType = kSignalTypeConsumer;
	digitalInputKey02Def.persistent = false;
	digitalInputKey02Def.pgn = 65241;
	digitalInputKey02Def.signal = m_digitalInputKey02;
	signalTypeDefs["digitalInputKey02"] = digitalInputKey02Def;

	m_digitalInputKey01 = new IntConsumerSignal(false, false, 0, 65241);
	SIGNALTYPEDEF digitalInputKey01Def;
	digitalInputKey01Def.dataType = DATATYPE_INT;
	digitalInputKey01Def.qtTypeName = "int";
	digitalInputKey01Def.signalType = kSignalTypeConsumer;
	digitalInputKey01Def.persistent = false;
	digitalInputKey01Def.pgn = 65241;
	digitalInputKey01Def.signal = m_digitalInputKey01;
	signalTypeDefs["digitalInputKey01"] = digitalInputKey01Def;

	m_lowSideCurrent = new FloatConsumerSignal(false, false, 0.0f, 61716);
	SIGNALTYPEDEF lowSideCurrentDef;
	lowSideCurrentDef.dataType = DATATYPE_FLOAT;
	lowSideCurrentDef.qtTypeName = "float";
	lowSideCurrentDef.signalType = kSignalTypeConsumer;
	lowSideCurrentDef.persistent = false;
	lowSideCurrentDef.pgn = 61716;
	lowSideCurrentDef.signal = m_lowSideCurrent;
	signalTypeDefs["lowSideCurrent"] = lowSideCurrentDef;

	m_highSideVoltage = new FloatConsumerSignal(false, false, 0.0f, 61716);
	SIGNALTYPEDEF highSideVoltageDef;
	highSideVoltageDef.dataType = DATATYPE_FLOAT;
	highSideVoltageDef.qtTypeName = "float";
	highSideVoltageDef.signalType = kSignalTypeConsumer;
	highSideVoltageDef.persistent = false;
	highSideVoltageDef.pgn = 61716;
	highSideVoltageDef.signal = m_highSideVoltage;
	signalTypeDefs["highSideVoltage"] = highSideVoltageDef;

	m_lowSideVoltage = new FloatConsumerSignal(false, false, 0.0f, 61716);
	SIGNALTYPEDEF lowSideVoltageDef;
	lowSideVoltageDef.dataType = DATATYPE_FLOAT;
	lowSideVoltageDef.qtTypeName = "float";
	lowSideVoltageDef.signalType = kSignalTypeConsumer;
	lowSideVoltageDef.persistent = false;
	lowSideVoltageDef.pgn = 61716;
	lowSideVoltageDef.signal = m_lowSideVoltage;
	signalTypeDefs["lowSideVoltage"] = lowSideVoltageDef;

	m_highSideCurrent = new FloatConsumerSignal(false, false, 0.0f, 61716);
	SIGNALTYPEDEF highSideCurrentDef;
	highSideCurrentDef.dataType = DATATYPE_FLOAT;
	highSideCurrentDef.qtTypeName = "float";
	highSideCurrentDef.signalType = kSignalTypeConsumer;
	highSideCurrentDef.persistent = false;
	highSideCurrentDef.pgn = 61716;
	highSideCurrentDef.signal = m_highSideCurrent;
	signalTypeDefs["highSideCurrent"] = highSideCurrentDef;

	m_zFETC13ePTOActualSpeedFeedback = new IntConsumerSignal(false, false, 0, 65323);
	SIGNALTYPEDEF zFETC13ePTOActualSpeedFeedbackDef;
	zFETC13ePTOActualSpeedFeedbackDef.dataType = DATATYPE_INT;
	zFETC13ePTOActualSpeedFeedbackDef.qtTypeName = "int";
	zFETC13ePTOActualSpeedFeedbackDef.signalType = kSignalTypeConsumer;
	zFETC13ePTOActualSpeedFeedbackDef.persistent = false;
	zFETC13ePTOActualSpeedFeedbackDef.pgn = 65323;
	zFETC13ePTOActualSpeedFeedbackDef.signal = m_zFETC13ePTOActualSpeedFeedback;
	signalTypeDefs["zFETC13ePTOActualSpeedFeedback"] = zFETC13ePTOActualSpeedFeedbackDef;

	m_zFETC13ePTOModeIndicator = new IntConsumerSignal(false, false, 0, 65323);
	SIGNALTYPEDEF zFETC13ePTOModeIndicatorDef;
	zFETC13ePTOModeIndicatorDef.dataType = DATATYPE_INT;
	zFETC13ePTOModeIndicatorDef.qtTypeName = "int";
	zFETC13ePTOModeIndicatorDef.signalType = kSignalTypeConsumer;
	zFETC13ePTOModeIndicatorDef.persistent = false;
	zFETC13ePTOModeIndicatorDef.pgn = 65323;
	zFETC13ePTOModeIndicatorDef.signal = m_zFETC13ePTOModeIndicator;
	signalTypeDefs["zFETC13ePTOModeIndicator"] = zFETC13ePTOModeIndicatorDef;

	m_zFETC13ePTOMaximumSpeedFeedback = new IntConsumerSignal(false, false, 0, 65323);
	SIGNALTYPEDEF zFETC13ePTOMaximumSpeedFeedbackDef;
	zFETC13ePTOMaximumSpeedFeedbackDef.dataType = DATATYPE_INT;
	zFETC13ePTOMaximumSpeedFeedbackDef.qtTypeName = "int";
	zFETC13ePTOMaximumSpeedFeedbackDef.signalType = kSignalTypeConsumer;
	zFETC13ePTOMaximumSpeedFeedbackDef.persistent = false;
	zFETC13ePTOMaximumSpeedFeedbackDef.pgn = 65323;
	zFETC13ePTOMaximumSpeedFeedbackDef.signal = m_zFETC13ePTOMaximumSpeedFeedback;
	signalTypeDefs["zFETC13ePTOMaximumSpeedFeedback"] = zFETC13ePTOMaximumSpeedFeedbackDef;

	m_zFETC13ePTORequestedSpeedFdbck = new IntConsumerSignal(false, false, 0, 65323);
	SIGNALTYPEDEF zFETC13ePTORequestedSpeedFdbckDef;
	zFETC13ePTORequestedSpeedFdbckDef.dataType = DATATYPE_INT;
	zFETC13ePTORequestedSpeedFdbckDef.qtTypeName = "int";
	zFETC13ePTORequestedSpeedFdbckDef.signalType = kSignalTypeConsumer;
	zFETC13ePTORequestedSpeedFdbckDef.persistent = false;
	zFETC13ePTORequestedSpeedFdbckDef.pgn = 65323;
	zFETC13ePTORequestedSpeedFdbckDef.signal = m_zFETC13ePTORequestedSpeedFdbck;
	signalTypeDefs["zFETC13ePTORequestedSpeedFdbck"] = zFETC13ePTORequestedSpeedFdbckDef;

	m_zFETC13ePTOMinimumSpeedFeedback = new IntConsumerSignal(false, false, 0, 65323);
	SIGNALTYPEDEF zFETC13ePTOMinimumSpeedFeedbackDef;
	zFETC13ePTOMinimumSpeedFeedbackDef.dataType = DATATYPE_INT;
	zFETC13ePTOMinimumSpeedFeedbackDef.qtTypeName = "int";
	zFETC13ePTOMinimumSpeedFeedbackDef.signalType = kSignalTypeConsumer;
	zFETC13ePTOMinimumSpeedFeedbackDef.persistent = false;
	zFETC13ePTOMinimumSpeedFeedbackDef.pgn = 65323;
	zFETC13ePTOMinimumSpeedFeedbackDef.signal = m_zFETC13ePTOMinimumSpeedFeedback;
	signalTypeDefs["zFETC13ePTOMinimumSpeedFeedback"] = zFETC13ePTOMinimumSpeedFeedbackDef;

	m_immobTransPinMaximumTries = new IntConsumerSignal(false, false, 0, 65412);
	SIGNALTYPEDEF immobTransPinMaximumTriesDef;
	immobTransPinMaximumTriesDef.dataType = DATATYPE_INT;
	immobTransPinMaximumTriesDef.qtTypeName = "int";
	immobTransPinMaximumTriesDef.signalType = kSignalTypeConsumer;
	immobTransPinMaximumTriesDef.persistent = false;
	immobTransPinMaximumTriesDef.pgn = 65412;
	immobTransPinMaximumTriesDef.signal = m_immobTransPinMaximumTries;
	signalTypeDefs["immobTransPinMaximumTries"] = immobTransPinMaximumTriesDef;

	m_immobTransPinLeftTries = new IntConsumerSignal(false, false, 0, 65412);
	SIGNALTYPEDEF immobTransPinLeftTriesDef;
	immobTransPinLeftTriesDef.dataType = DATATYPE_INT;
	immobTransPinLeftTriesDef.qtTypeName = "int";
	immobTransPinLeftTriesDef.signalType = kSignalTypeConsumer;
	immobTransPinLeftTriesDef.persistent = false;
	immobTransPinLeftTriesDef.pgn = 65412;
	immobTransPinLeftTriesDef.signal = m_immobTransPinLeftTries;
	signalTypeDefs["immobTransPinLeftTries"] = immobTransPinLeftTriesDef;

	m_immobGeneralPinMaximumTries = new IntConsumerSignal(false, false, 0, 65412);
	SIGNALTYPEDEF immobGeneralPinMaximumTriesDef;
	immobGeneralPinMaximumTriesDef.dataType = DATATYPE_INT;
	immobGeneralPinMaximumTriesDef.qtTypeName = "int";
	immobGeneralPinMaximumTriesDef.signalType = kSignalTypeConsumer;
	immobGeneralPinMaximumTriesDef.persistent = false;
	immobGeneralPinMaximumTriesDef.pgn = 65412;
	immobGeneralPinMaximumTriesDef.signal = m_immobGeneralPinMaximumTries;
	signalTypeDefs["immobGeneralPinMaximumTries"] = immobGeneralPinMaximumTriesDef;

	m_immobGeneralPinLeftTries = new IntConsumerSignal(false, false, 0, 65412);
	SIGNALTYPEDEF immobGeneralPinLeftTriesDef;
	immobGeneralPinLeftTriesDef.dataType = DATATYPE_INT;
	immobGeneralPinLeftTriesDef.qtTypeName = "int";
	immobGeneralPinLeftTriesDef.signalType = kSignalTypeConsumer;
	immobGeneralPinLeftTriesDef.persistent = false;
	immobGeneralPinLeftTriesDef.pgn = 65412;
	immobGeneralPinLeftTriesDef.signal = m_immobGeneralPinLeftTries;
	signalTypeDefs["immobGeneralPinLeftTries"] = immobGeneralPinLeftTriesDef;

	m_immobOwnerPinMaximumTries = new IntConsumerSignal(false, false, 0, 65412);
	SIGNALTYPEDEF immobOwnerPinMaximumTriesDef;
	immobOwnerPinMaximumTriesDef.dataType = DATATYPE_INT;
	immobOwnerPinMaximumTriesDef.qtTypeName = "int";
	immobOwnerPinMaximumTriesDef.signalType = kSignalTypeConsumer;
	immobOwnerPinMaximumTriesDef.persistent = false;
	immobOwnerPinMaximumTriesDef.pgn = 65412;
	immobOwnerPinMaximumTriesDef.signal = m_immobOwnerPinMaximumTries;
	signalTypeDefs["immobOwnerPinMaximumTries"] = immobOwnerPinMaximumTriesDef;

	m_immobOwnerPinLeftTries = new IntConsumerSignal(false, false, 0, 65412);
	SIGNALTYPEDEF immobOwnerPinLeftTriesDef;
	immobOwnerPinLeftTriesDef.dataType = DATATYPE_INT;
	immobOwnerPinLeftTriesDef.qtTypeName = "int";
	immobOwnerPinLeftTriesDef.signalType = kSignalTypeConsumer;
	immobOwnerPinLeftTriesDef.persistent = false;
	immobOwnerPinLeftTriesDef.pgn = 65412;
	immobOwnerPinLeftTriesDef.signal = m_immobOwnerPinLeftTries;
	signalTypeDefs["immobOwnerPinLeftTries"] = immobOwnerPinLeftTriesDef;

	m_popUpMessage_Ctrl = new IntConsumerSignal(false, false, 0, 65412);
	SIGNALTYPEDEF popUpMessage_CtrlDef;
	popUpMessage_CtrlDef.dataType = DATATYPE_INT;
	popUpMessage_CtrlDef.qtTypeName = "int";
	popUpMessage_CtrlDef.signalType = kSignalTypeConsumer;
	popUpMessage_CtrlDef.persistent = false;
	popUpMessage_CtrlDef.pgn = 65412;
	popUpMessage_CtrlDef.signal = m_popUpMessage_Ctrl;
	signalTypeDefs["popUpMessage_Ctrl"] = popUpMessage_CtrlDef;

	m_screenCtrl = new IntConsumerSignal(false, false, 0, 65412);
	SIGNALTYPEDEF screenCtrlDef;
	screenCtrlDef.dataType = DATATYPE_INT;
	screenCtrlDef.qtTypeName = "int";
	screenCtrlDef.signalType = kSignalTypeConsumer;
	screenCtrlDef.persistent = false;
	screenCtrlDef.pgn = 65412;
	screenCtrlDef.signal = m_screenCtrl;
	signalTypeDefs["screenCtrl"] = screenCtrlDef;

	m_sOFTTransmissionType = new IntConsumerSignal(false, false, 0, 65242);
	SIGNALTYPEDEF sOFTTransmissionTypeDef;
	sOFTTransmissionTypeDef.dataType = DATATYPE_INT;
	sOFTTransmissionTypeDef.qtTypeName = "int";
	sOFTTransmissionTypeDef.signalType = kSignalTypeConsumer;
	sOFTTransmissionTypeDef.persistent = false;
	sOFTTransmissionTypeDef.pgn = 65242;
	sOFTTransmissionTypeDef.signal = m_sOFTTransmissionType;
	signalTypeDefs["sOFTTransmissionType"] = sOFTTransmissionTypeDef;

	m_sOFTTransmissionPartNumber = new IntConsumerSignal(false, false, 0, 65242);
	SIGNALTYPEDEF sOFTTransmissionPartNumberDef;
	sOFTTransmissionPartNumberDef.dataType = DATATYPE_INT;
	sOFTTransmissionPartNumberDef.qtTypeName = "int";
	sOFTTransmissionPartNumberDef.signalType = kSignalTypeConsumer;
	sOFTTransmissionPartNumberDef.persistent = false;
	sOFTTransmissionPartNumberDef.pgn = 65242;
	sOFTTransmissionPartNumberDef.signal = m_sOFTTransmissionPartNumber;
	signalTypeDefs["sOFTTransmissionPartNumber"] = sOFTTransmissionPartNumberDef;

	m_sOFTSoftwareVersion = new IntConsumerSignal(false, false, 0, 65242);
	SIGNALTYPEDEF sOFTSoftwareVersionDef;
	sOFTSoftwareVersionDef.dataType = DATATYPE_INT;
	sOFTSoftwareVersionDef.qtTypeName = "int";
	sOFTSoftwareVersionDef.signalType = kSignalTypeConsumer;
	sOFTSoftwareVersionDef.persistent = false;
	sOFTSoftwareVersionDef.pgn = 65242;
	sOFTSoftwareVersionDef.signal = m_sOFTSoftwareVersion;
	signalTypeDefs["sOFTSoftwareVersion"] = sOFTSoftwareVersionDef;

	m_sOFTSoftwarePartNumber = new IntConsumerSignal(false, false, 0, 65242);
	SIGNALTYPEDEF sOFTSoftwarePartNumberDef;
	sOFTSoftwarePartNumberDef.dataType = DATATYPE_INT;
	sOFTSoftwarePartNumberDef.qtTypeName = "int";
	sOFTSoftwarePartNumberDef.signalType = kSignalTypeConsumer;
	sOFTSoftwarePartNumberDef.persistent = false;
	sOFTSoftwarePartNumberDef.pgn = 65242;
	sOFTSoftwarePartNumberDef.signal = m_sOFTSoftwarePartNumber;
	signalTypeDefs["sOFTSoftwarePartNumber"] = sOFTSoftwarePartNumberDef;

	m_sOFTNmbrOfSftwrIdentFields = new IntConsumerSignal(false, false, 0, 65242);
	SIGNALTYPEDEF sOFTNmbrOfSftwrIdentFieldsDef;
	sOFTNmbrOfSftwrIdentFieldsDef.dataType = DATATYPE_INT;
	sOFTNmbrOfSftwrIdentFieldsDef.qtTypeName = "int";
	sOFTNmbrOfSftwrIdentFieldsDef.signalType = kSignalTypeConsumer;
	sOFTNmbrOfSftwrIdentFieldsDef.persistent = false;
	sOFTNmbrOfSftwrIdentFieldsDef.pgn = 65242;
	sOFTNmbrOfSftwrIdentFieldsDef.signal = m_sOFTNmbrOfSftwrIdentFields;
	signalTypeDefs["sOFTNmbrOfSftwrIdentFields"] = sOFTNmbrOfSftwrIdentFieldsDef;

	m_sOFTCustomerSoftwareNumber = new IntConsumerSignal(false, false, 0, 65242);
	SIGNALTYPEDEF sOFTCustomerSoftwareNumberDef;
	sOFTCustomerSoftwareNumberDef.dataType = DATATYPE_INT;
	sOFTCustomerSoftwareNumberDef.qtTypeName = "int";
	sOFTCustomerSoftwareNumberDef.signalType = kSignalTypeConsumer;
	sOFTCustomerSoftwareNumberDef.persistent = false;
	sOFTCustomerSoftwareNumberDef.pgn = 65242;
	sOFTCustomerSoftwareNumberDef.signal = m_sOFTCustomerSoftwareNumber;
	signalTypeDefs["sOFTCustomerSoftwareNumber"] = sOFTCustomerSoftwareNumberDef;

	m_eCU_Batt = new FloatConsumerSignal(false, false, 0.0f, 65271);
	SIGNALTYPEDEF eCU_BattDef;
	eCU_BattDef.dataType = DATATYPE_FLOAT;
	eCU_BattDef.qtTypeName = "float";
	eCU_BattDef.signalType = kSignalTypeConsumer;
	eCU_BattDef.persistent = false;
	eCU_BattDef.pgn = 65271;
	eCU_BattDef.signal = m_eCU_Batt;
	signalTypeDefs["eCU_Batt"] = eCU_BattDef;

	m_estPumpingPercentTorque = new IntConsumerSignal(false, false, 0, 61443);
	SIGNALTYPEDEF estPumpingPercentTorqueDef;
	estPumpingPercentTorqueDef.dataType = DATATYPE_INT;
	estPumpingPercentTorqueDef.qtTypeName = "int";
	estPumpingPercentTorqueDef.signalType = kSignalTypeConsumer;
	estPumpingPercentTorqueDef.persistent = false;
	estPumpingPercentTorqueDef.pgn = 61443;
	estPumpingPercentTorqueDef.signal = m_estPumpingPercentTorque;
	signalTypeDefs["estPumpingPercentTorque"] = estPumpingPercentTorqueDef;

	m_actlMaxAvailableEngPercentTorque = new IntConsumerSignal(false, false, 0, 61443);
	SIGNALTYPEDEF actlMaxAvailableEngPercentTorqueDef;
	actlMaxAvailableEngPercentTorqueDef.dataType = DATATYPE_INT;
	actlMaxAvailableEngPercentTorqueDef.qtTypeName = "int";
	actlMaxAvailableEngPercentTorqueDef.signalType = kSignalTypeConsumer;
	actlMaxAvailableEngPercentTorqueDef.persistent = false;
	actlMaxAvailableEngPercentTorqueDef.pgn = 61443;
	actlMaxAvailableEngPercentTorqueDef.signal = m_actlMaxAvailableEngPercentTorque;
	signalTypeDefs["actlMaxAvailableEngPercentTorque"] = actlMaxAvailableEngPercentTorqueDef;

	m_sCRThermalManagementActive = new IntConsumerSignal(false, false, 0, 61443);
	SIGNALTYPEDEF sCRThermalManagementActiveDef;
	sCRThermalManagementActiveDef.dataType = DATATYPE_INT;
	sCRThermalManagementActiveDef.qtTypeName = "int";
	sCRThermalManagementActiveDef.signalType = kSignalTypeConsumer;
	sCRThermalManagementActiveDef.persistent = false;
	sCRThermalManagementActiveDef.pgn = 61443;
	sCRThermalManagementActiveDef.signal = m_sCRThermalManagementActive;
	signalTypeDefs["sCRThermalManagementActive"] = sCRThermalManagementActiveDef;

	m_dPFThermalManagementActive = new IntConsumerSignal(false, false, 0, 61443);
	SIGNALTYPEDEF dPFThermalManagementActiveDef;
	dPFThermalManagementActiveDef.dataType = DATATYPE_INT;
	dPFThermalManagementActiveDef.qtTypeName = "int";
	dPFThermalManagementActiveDef.signalType = kSignalTypeConsumer;
	dPFThermalManagementActiveDef.persistent = false;
	dPFThermalManagementActiveDef.pgn = 61443;
	dPFThermalManagementActiveDef.signal = m_dPFThermalManagementActive;
	signalTypeDefs["dPFThermalManagementActive"] = dPFThermalManagementActiveDef;

	m_mmntaryEngMaxPowerEnableFeedback = new IntConsumerSignal(false, false, 0, 61443);
	SIGNALTYPEDEF mmntaryEngMaxPowerEnableFeedbackDef;
	mmntaryEngMaxPowerEnableFeedbackDef.dataType = DATATYPE_INT;
	mmntaryEngMaxPowerEnableFeedbackDef.qtTypeName = "int";
	mmntaryEngMaxPowerEnableFeedbackDef.signalType = kSignalTypeConsumer;
	mmntaryEngMaxPowerEnableFeedbackDef.persistent = false;
	mmntaryEngMaxPowerEnableFeedbackDef.pgn = 61443;
	mmntaryEngMaxPowerEnableFeedbackDef.signal = m_mmntaryEngMaxPowerEnableFeedback;
	signalTypeDefs["mmntaryEngMaxPowerEnableFeedback"] = mmntaryEngMaxPowerEnableFeedbackDef;

	m_vhcleAccelerationRateLimitStatus = new IntConsumerSignal(false, false, 0, 61443);
	SIGNALTYPEDEF vhcleAccelerationRateLimitStatusDef;
	vhcleAccelerationRateLimitStatusDef.dataType = DATATYPE_INT;
	vhcleAccelerationRateLimitStatusDef.qtTypeName = "int";
	vhcleAccelerationRateLimitStatusDef.signalType = kSignalTypeConsumer;
	vhcleAccelerationRateLimitStatusDef.persistent = false;
	vhcleAccelerationRateLimitStatusDef.pgn = 61443;
	vhcleAccelerationRateLimitStatusDef.signal = m_vhcleAccelerationRateLimitStatus;
	signalTypeDefs["vhcleAccelerationRateLimitStatus"] = vhcleAccelerationRateLimitStatusDef;

	m_accelPedalPos2 = new IntConsumerSignal(false, false, 0, 61443);
	SIGNALTYPEDEF accelPedalPos2Def;
	accelPedalPos2Def.dataType = DATATYPE_INT;
	accelPedalPos2Def.qtTypeName = "int";
	accelPedalPos2Def.signalType = kSignalTypeConsumer;
	accelPedalPos2Def.persistent = false;
	accelPedalPos2Def.pgn = 61443;
	accelPedalPos2Def.signal = m_accelPedalPos2;
	signalTypeDefs["accelPedalPos2"] = accelPedalPos2Def;

	m_remoteAccelPedalPos = new IntConsumerSignal(false, false, 0, 61443);
	SIGNALTYPEDEF remoteAccelPedalPosDef;
	remoteAccelPedalPosDef.dataType = DATATYPE_INT;
	remoteAccelPedalPosDef.qtTypeName = "int";
	remoteAccelPedalPosDef.signalType = kSignalTypeConsumer;
	remoteAccelPedalPosDef.persistent = false;
	remoteAccelPedalPosDef.pgn = 61443;
	remoteAccelPedalPosDef.signal = m_remoteAccelPedalPos;
	signalTypeDefs["remoteAccelPedalPos"] = remoteAccelPedalPosDef;

	m_engPercentLoadAtCurrentSpeed = new IntConsumerSignal(false, false, 0, 61443);
	SIGNALTYPEDEF engPercentLoadAtCurrentSpeedDef;
	engPercentLoadAtCurrentSpeedDef.dataType = DATATYPE_INT;
	engPercentLoadAtCurrentSpeedDef.qtTypeName = "int";
	engPercentLoadAtCurrentSpeedDef.signalType = kSignalTypeConsumer;
	engPercentLoadAtCurrentSpeedDef.persistent = false;
	engPercentLoadAtCurrentSpeedDef.pgn = 61443;
	engPercentLoadAtCurrentSpeedDef.signal = m_engPercentLoadAtCurrentSpeed;
	signalTypeDefs["engPercentLoadAtCurrentSpeed"] = engPercentLoadAtCurrentSpeedDef;

	m_accelPedalPos1 = new IntConsumerSignal(false, false, 0, 61443);
	SIGNALTYPEDEF accelPedalPos1Def;
	accelPedalPos1Def.dataType = DATATYPE_INT;
	accelPedalPos1Def.qtTypeName = "int";
	accelPedalPos1Def.signalType = kSignalTypeConsumer;
	accelPedalPos1Def.persistent = false;
	accelPedalPos1Def.pgn = 61443;
	accelPedalPos1Def.signal = m_accelPedalPos1;
	signalTypeDefs["accelPedalPos1"] = accelPedalPos1Def;

	m_accelPedal2LowIdleSwitch = new IntConsumerSignal(false, false, 0, 61443);
	SIGNALTYPEDEF accelPedal2LowIdleSwitchDef;
	accelPedal2LowIdleSwitchDef.dataType = DATATYPE_INT;
	accelPedal2LowIdleSwitchDef.qtTypeName = "int";
	accelPedal2LowIdleSwitchDef.signalType = kSignalTypeConsumer;
	accelPedal2LowIdleSwitchDef.persistent = false;
	accelPedal2LowIdleSwitchDef.pgn = 61443;
	accelPedal2LowIdleSwitchDef.signal = m_accelPedal2LowIdleSwitch;
	signalTypeDefs["accelPedal2LowIdleSwitch"] = accelPedal2LowIdleSwitchDef;

	m_roadSpeedLimitStatus = new IntConsumerSignal(false, false, 0, 61443);
	SIGNALTYPEDEF roadSpeedLimitStatusDef;
	roadSpeedLimitStatusDef.dataType = DATATYPE_INT;
	roadSpeedLimitStatusDef.qtTypeName = "int";
	roadSpeedLimitStatusDef.signalType = kSignalTypeConsumer;
	roadSpeedLimitStatusDef.persistent = false;
	roadSpeedLimitStatusDef.pgn = 61443;
	roadSpeedLimitStatusDef.signal = m_roadSpeedLimitStatus;
	signalTypeDefs["roadSpeedLimitStatus"] = roadSpeedLimitStatusDef;

	m_accelPedalKickdownSwitch = new IntConsumerSignal(false, false, 0, 61443);
	SIGNALTYPEDEF accelPedalKickdownSwitchDef;
	accelPedalKickdownSwitchDef.dataType = DATATYPE_INT;
	accelPedalKickdownSwitchDef.qtTypeName = "int";
	accelPedalKickdownSwitchDef.signalType = kSignalTypeConsumer;
	accelPedalKickdownSwitchDef.persistent = false;
	accelPedalKickdownSwitchDef.pgn = 61443;
	accelPedalKickdownSwitchDef.signal = m_accelPedalKickdownSwitch;
	signalTypeDefs["accelPedalKickdownSwitch"] = accelPedalKickdownSwitchDef;

	m_accelPedal1LowIdleSwitch = new IntConsumerSignal(false, false, 0, 61443);
	SIGNALTYPEDEF accelPedal1LowIdleSwitchDef;
	accelPedal1LowIdleSwitchDef.dataType = DATATYPE_INT;
	accelPedal1LowIdleSwitchDef.qtTypeName = "int";
	accelPedal1LowIdleSwitchDef.signalType = kSignalTypeConsumer;
	accelPedal1LowIdleSwitchDef.persistent = false;
	accelPedal1LowIdleSwitchDef.pgn = 61443;
	accelPedal1LowIdleSwitchDef.signal = m_accelPedal1LowIdleSwitch;
	signalTypeDefs["accelPedal1LowIdleSwitch"] = accelPedal1LowIdleSwitchDef;

	m_nSpdSnsrMot = new IntConsumerSignal(false, false, 0, 65319);
	SIGNALTYPEDEF nSpdSnsrMotDef;
	nSpdSnsrMotDef.dataType = DATATYPE_INT;
	nSpdSnsrMotDef.qtTypeName = "int";
	nSpdSnsrMotDef.signalType = kSignalTypeConsumer;
	nSpdSnsrMotDef.persistent = false;
	nSpdSnsrMotDef.pgn = 65319;
	nSpdSnsrMotDef.signal = m_nSpdSnsrMot;
	signalTypeDefs["nSpdSnsrMot"] = nSpdSnsrMotDef;

	m_pMa = new IntConsumerSignal(false, false, 0, 65319);
	SIGNALTYPEDEF pMaDef;
	pMaDef.dataType = DATATYPE_INT;
	pMaDef.qtTypeName = "int";
	pMaDef.signalType = kSignalTypeConsumer;
	pMaDef.persistent = false;
	pMaDef.pgn = 65319;
	pMaDef.signal = m_pMa;
	signalTypeDefs["pMa"] = pMaDef;

	m_pMb = new IntConsumerSignal(false, false, 0, 65319);
	SIGNALTYPEDEF pMbDef;
	pMbDef.dataType = DATATYPE_INT;
	pMbDef.qtTypeName = "int";
	pMbDef.signalType = kSignalTypeConsumer;
	pMbDef.persistent = false;
	pMbDef.pgn = 65319;
	pMbDef.signal = m_pMb;
	signalTypeDefs["pMb"] = pMbDef;

	m_nSpdSnsrPmp = new IntConsumerSignal(false, false, 0, 65319);
	SIGNALTYPEDEF nSpdSnsrPmpDef;
	nSpdSnsrPmpDef.dataType = DATATYPE_INT;
	nSpdSnsrPmpDef.qtTypeName = "int";
	nSpdSnsrPmpDef.signalType = kSignalTypeConsumer;
	nSpdSnsrPmpDef.persistent = false;
	nSpdSnsrPmpDef.pgn = 65319;
	nSpdSnsrPmpDef.signal = m_nSpdSnsrPmp;
	signalTypeDefs["nSpdSnsrPmp"] = nSpdSnsrPmpDef;

	m_nSpdSnsrEng = new IntConsumerSignal(false, false, 0, 65319);
	SIGNALTYPEDEF nSpdSnsrEngDef;
	nSpdSnsrEngDef.dataType = DATATYPE_INT;
	nSpdSnsrEngDef.qtTypeName = "int";
	nSpdSnsrEngDef.signalType = kSignalTypeConsumer;
	nSpdSnsrEngDef.persistent = false;
	nSpdSnsrEngDef.pgn = 65319;
	nSpdSnsrEngDef.signal = m_nSpdSnsrEng;
	signalTypeDefs["nSpdSnsrEng"] = nSpdSnsrEngDef;

	m_msgCntr1 = new IntConsumerSignal(false, false, 0, 65319);
	SIGNALTYPEDEF msgCntr1Def;
	msgCntr1Def.dataType = DATATYPE_INT;
	msgCntr1Def.qtTypeName = "int";
	msgCntr1Def.signalType = kSignalTypeConsumer;
	msgCntr1Def.persistent = false;
	msgCntr1Def.pgn = 65319;
	msgCntr1Def.signal = m_msgCntr1;
	signalTypeDefs["msgCntr1"] = msgCntr1Def;

	m_msgChks1 = new IntConsumerSignal(false, false, 0, 65319);
	SIGNALTYPEDEF msgChks1Def;
	msgChks1Def.dataType = DATATYPE_INT;
	msgChks1Def.qtTypeName = "int";
	msgChks1Def.signalType = kSignalTypeConsumer;
	msgChks1Def.persistent = false;
	msgChks1Def.pgn = 65319;
	msgChks1Def.signal = m_msgChks1;
	signalTypeDefs["msgChks1"] = msgChks1Def;

	m_hMI_ConfigurableInput04_CfgUnusd = new IntConsumerSignal(false, false, 0, 42792);
	SIGNALTYPEDEF hMI_ConfigurableInput04_CfgUnusdDef;
	hMI_ConfigurableInput04_CfgUnusdDef.dataType = DATATYPE_INT;
	hMI_ConfigurableInput04_CfgUnusdDef.qtTypeName = "int";
	hMI_ConfigurableInput04_CfgUnusdDef.signalType = kSignalTypeConsumer;
	hMI_ConfigurableInput04_CfgUnusdDef.persistent = false;
	hMI_ConfigurableInput04_CfgUnusdDef.pgn = 42792;
	hMI_ConfigurableInput04_CfgUnusdDef.signal = m_hMI_ConfigurableInput04_CfgUnusd;
	signalTypeDefs["hMI_ConfigurableInput04_CfgUnusd"] = hMI_ConfigurableInput04_CfgUnusdDef;

	m_hMI_ConfigurableInput03_CfgUnusd = new IntConsumerSignal(false, false, 0, 42792);
	SIGNALTYPEDEF hMI_ConfigurableInput03_CfgUnusdDef;
	hMI_ConfigurableInput03_CfgUnusdDef.dataType = DATATYPE_INT;
	hMI_ConfigurableInput03_CfgUnusdDef.qtTypeName = "int";
	hMI_ConfigurableInput03_CfgUnusdDef.signalType = kSignalTypeConsumer;
	hMI_ConfigurableInput03_CfgUnusdDef.persistent = false;
	hMI_ConfigurableInput03_CfgUnusdDef.pgn = 42792;
	hMI_ConfigurableInput03_CfgUnusdDef.signal = m_hMI_ConfigurableInput03_CfgUnusd;
	signalTypeDefs["hMI_ConfigurableInput03_CfgUnusd"] = hMI_ConfigurableInput03_CfgUnusdDef;

	m_hMI_ConfigurableInput02_CfgUnusd = new IntConsumerSignal(false, false, 0, 42792);
	SIGNALTYPEDEF hMI_ConfigurableInput02_CfgUnusdDef;
	hMI_ConfigurableInput02_CfgUnusdDef.dataType = DATATYPE_INT;
	hMI_ConfigurableInput02_CfgUnusdDef.qtTypeName = "int";
	hMI_ConfigurableInput02_CfgUnusdDef.signalType = kSignalTypeConsumer;
	hMI_ConfigurableInput02_CfgUnusdDef.persistent = false;
	hMI_ConfigurableInput02_CfgUnusdDef.pgn = 42792;
	hMI_ConfigurableInput02_CfgUnusdDef.signal = m_hMI_ConfigurableInput02_CfgUnusd;
	signalTypeDefs["hMI_ConfigurableInput02_CfgUnusd"] = hMI_ConfigurableInput02_CfgUnusdDef;

	m_hMI_ConfigurableInput01_CfgUnusd = new IntConsumerSignal(false, false, 0, 42792);
	SIGNALTYPEDEF hMI_ConfigurableInput01_CfgUnusdDef;
	hMI_ConfigurableInput01_CfgUnusdDef.dataType = DATATYPE_INT;
	hMI_ConfigurableInput01_CfgUnusdDef.qtTypeName = "int";
	hMI_ConfigurableInput01_CfgUnusdDef.signalType = kSignalTypeConsumer;
	hMI_ConfigurableInput01_CfgUnusdDef.persistent = false;
	hMI_ConfigurableInput01_CfgUnusdDef.pgn = 42792;
	hMI_ConfigurableInput01_CfgUnusdDef.signal = m_hMI_ConfigurableInput01_CfgUnusd;
	signalTypeDefs["hMI_ConfigurableInput01_CfgUnusd"] = hMI_ConfigurableInput01_CfgUnusdDef;

	m_buzzer_Ctrl = new IntConsumerSignal(false, false, 0, 42792);
	SIGNALTYPEDEF buzzer_CtrlDef;
	buzzer_CtrlDef.dataType = DATATYPE_INT;
	buzzer_CtrlDef.qtTypeName = "int";
	buzzer_CtrlDef.signalType = kSignalTypeConsumer;
	buzzer_CtrlDef.persistent = false;
	buzzer_CtrlDef.pgn = 42792;
	buzzer_CtrlDef.signal = m_buzzer_Ctrl;
	signalTypeDefs["buzzer_Ctrl"] = buzzer_CtrlDef;

	m_digitalOutput02_Ctrl = new IntConsumerSignal(false, false, 0, 42792);
	SIGNALTYPEDEF digitalOutput02_CtrlDef;
	digitalOutput02_CtrlDef.dataType = DATATYPE_INT;
	digitalOutput02_CtrlDef.qtTypeName = "int";
	digitalOutput02_CtrlDef.signalType = kSignalTypeConsumer;
	digitalOutput02_CtrlDef.persistent = false;
	digitalOutput02_CtrlDef.pgn = 42792;
	digitalOutput02_CtrlDef.signal = m_digitalOutput02_Ctrl;
	signalTypeDefs["digitalOutput02_Ctrl"] = digitalOutput02_CtrlDef;

	m_digitalOutput01_Ctrl = new IntConsumerSignal(false, false, 0, 42792);
	SIGNALTYPEDEF digitalOutput01_CtrlDef;
	digitalOutput01_CtrlDef.dataType = DATATYPE_INT;
	digitalOutput01_CtrlDef.qtTypeName = "int";
	digitalOutput01_CtrlDef.signalType = kSignalTypeConsumer;
	digitalOutput01_CtrlDef.persistent = false;
	digitalOutput01_CtrlDef.pgn = 42792;
	digitalOutput01_CtrlDef.signal = m_digitalOutput01_Ctrl;
	signalTypeDefs["digitalOutput01_Ctrl"] = digitalOutput01_CtrlDef;

	m_btnImmobActivation_Ctrl = new IntConsumerSignal(false, false, 0, 42792);
	SIGNALTYPEDEF btnImmobActivation_CtrlDef;
	btnImmobActivation_CtrlDef.dataType = DATATYPE_INT;
	btnImmobActivation_CtrlDef.qtTypeName = "int";
	btnImmobActivation_CtrlDef.signalType = kSignalTypeConsumer;
	btnImmobActivation_CtrlDef.persistent = false;
	btnImmobActivation_CtrlDef.pgn = 42792;
	btnImmobActivation_CtrlDef.signal = m_btnImmobActivation_Ctrl;
	signalTypeDefs["btnImmobActivation_Ctrl"] = btnImmobActivation_CtrlDef;

	m_digitalOutput02 = new IntConsumerSignal(false, false, 0, 42823);
	SIGNALTYPEDEF digitalOutput02Def;
	digitalOutput02Def.dataType = DATATYPE_INT;
	digitalOutput02Def.qtTypeName = "int";
	digitalOutput02Def.signalType = kSignalTypeConsumer;
	digitalOutput02Def.persistent = false;
	digitalOutput02Def.pgn = 42823;
	digitalOutput02Def.signal = m_digitalOutput02;
	signalTypeDefs["digitalOutput02"] = digitalOutput02Def;

	m_digitalOutput01 = new IntConsumerSignal(false, false, 0, 42823);
	SIGNALTYPEDEF digitalOutput01Def;
	digitalOutput01Def.dataType = DATATYPE_INT;
	digitalOutput01Def.qtTypeName = "int";
	digitalOutput01Def.signalType = kSignalTypeConsumer;
	digitalOutput01Def.persistent = false;
	digitalOutput01Def.pgn = 42823;
	digitalOutput01Def.signal = m_digitalOutput01;
	signalTypeDefs["digitalOutput01"] = digitalOutput01Def;

	m_btnImmobActivation = new IntConsumerSignal(false, false, 0, 42823);
	SIGNALTYPEDEF btnImmobActivationDef;
	btnImmobActivationDef.dataType = DATATYPE_INT;
	btnImmobActivationDef.qtTypeName = "int";
	btnImmobActivationDef.signalType = kSignalTypeConsumer;
	btnImmobActivationDef.persistent = false;
	btnImmobActivationDef.pgn = 42823;
	btnImmobActivationDef.signal = m_btnImmobActivation;
	signalTypeDefs["btnImmobActivation"] = btnImmobActivationDef;

	m_ind_SOC_Status_Warning = new IntConsumerSignal(false, false, 0, 65476);
	SIGNALTYPEDEF ind_SOC_Status_WarningDef;
	ind_SOC_Status_WarningDef.dataType = DATATYPE_INT;
	ind_SOC_Status_WarningDef.qtTypeName = "int";
	ind_SOC_Status_WarningDef.signalType = kSignalTypeConsumer;
	ind_SOC_Status_WarningDef.persistent = false;
	ind_SOC_Status_WarningDef.pgn = 65476;
	ind_SOC_Status_WarningDef.signal = m_ind_SOC_Status_Warning;
	signalTypeDefs["ind_SOC_Status_Warning"] = ind_SOC_Status_WarningDef;

	m_ind_SOC_Status_Error = new IntConsumerSignal(false, false, 0, 65476);
	SIGNALTYPEDEF ind_SOC_Status_ErrorDef;
	ind_SOC_Status_ErrorDef.dataType = DATATYPE_INT;
	ind_SOC_Status_ErrorDef.qtTypeName = "int";
	ind_SOC_Status_ErrorDef.signalType = kSignalTypeConsumer;
	ind_SOC_Status_ErrorDef.persistent = false;
	ind_SOC_Status_ErrorDef.pgn = 65476;
	ind_SOC_Status_ErrorDef.signal = m_ind_SOC_Status_Error;
	signalTypeDefs["ind_SOC_Status_Error"] = ind_SOC_Status_ErrorDef;

	m_ind_HVBatteryOn = new IntConsumerSignal(false, false, 0, 65476);
	SIGNALTYPEDEF ind_HVBatteryOnDef;
	ind_HVBatteryOnDef.dataType = DATATYPE_INT;
	ind_HVBatteryOnDef.qtTypeName = "int";
	ind_HVBatteryOnDef.signalType = kSignalTypeConsumer;
	ind_HVBatteryOnDef.persistent = false;
	ind_HVBatteryOnDef.pgn = 65476;
	ind_HVBatteryOnDef.signal = m_ind_HVBatteryOn;
	signalTypeDefs["ind_HVBatteryOn"] = ind_HVBatteryOnDef;

	m_ind_SOC_Status = new IntConsumerSignal(false, false, 0, 65476);
	SIGNALTYPEDEF ind_SOC_StatusDef;
	ind_SOC_StatusDef.dataType = DATATYPE_INT;
	ind_SOC_StatusDef.qtTypeName = "int";
	ind_SOC_StatusDef.signalType = kSignalTypeConsumer;
	ind_SOC_StatusDef.persistent = false;
	ind_SOC_StatusDef.pgn = 65476;
	ind_SOC_StatusDef.signal = m_ind_SOC_Status;
	signalTypeDefs["ind_SOC_Status"] = ind_SOC_StatusDef;

	m_ind_LowRecuperation = new IntConsumerSignal(false, false, 0, 65476);
	SIGNALTYPEDEF ind_LowRecuperationDef;
	ind_LowRecuperationDef.dataType = DATATYPE_INT;
	ind_LowRecuperationDef.qtTypeName = "int";
	ind_LowRecuperationDef.signalType = kSignalTypeConsumer;
	ind_LowRecuperationDef.persistent = false;
	ind_LowRecuperationDef.pgn = 65476;
	ind_LowRecuperationDef.signal = m_ind_LowRecuperation;
	signalTypeDefs["ind_LowRecuperation"] = ind_LowRecuperationDef;

	m_ind_ElectricSystemFailure = new IntConsumerSignal(false, false, 0, 65476);
	SIGNALTYPEDEF ind_ElectricSystemFailureDef;
	ind_ElectricSystemFailureDef.dataType = DATATYPE_INT;
	ind_ElectricSystemFailureDef.qtTypeName = "int";
	ind_ElectricSystemFailureDef.signalType = kSignalTypeConsumer;
	ind_ElectricSystemFailureDef.persistent = false;
	ind_ElectricSystemFailureDef.pgn = 65476;
	ind_ElectricSystemFailureDef.signal = m_ind_ElectricSystemFailure;
	signalTypeDefs["ind_ElectricSystemFailure"] = ind_ElectricSystemFailureDef;

	m_ind_ElectricEngineFailure = new IntConsumerSignal(false, false, 0, 65476);
	SIGNALTYPEDEF ind_ElectricEngineFailureDef;
	ind_ElectricEngineFailureDef.dataType = DATATYPE_INT;
	ind_ElectricEngineFailureDef.qtTypeName = "int";
	ind_ElectricEngineFailureDef.signalType = kSignalTypeConsumer;
	ind_ElectricEngineFailureDef.persistent = false;
	ind_ElectricEngineFailureDef.pgn = 65476;
	ind_ElectricEngineFailureDef.signal = m_ind_ElectricEngineFailure;
	signalTypeDefs["ind_ElectricEngineFailure"] = ind_ElectricEngineFailureDef;

	m_ind_48VBatteryFailure = new IntConsumerSignal(false, false, 0, 65476);
	SIGNALTYPEDEF ind_48VBatteryFailureDef;
	ind_48VBatteryFailureDef.dataType = DATATYPE_INT;
	ind_48VBatteryFailureDef.qtTypeName = "int";
	ind_48VBatteryFailureDef.signalType = kSignalTypeConsumer;
	ind_48VBatteryFailureDef.persistent = false;
	ind_48VBatteryFailureDef.pgn = 65476;
	ind_48VBatteryFailureDef.signal = m_ind_48VBatteryFailure;
	signalTypeDefs["ind_48VBatteryFailure"] = ind_48VBatteryFailureDef;

	m_ind_EngPwrReductionDueToTemp = new IntConsumerSignal(false, false, 0, 65476);
	SIGNALTYPEDEF ind_EngPwrReductionDueToTempDef;
	ind_EngPwrReductionDueToTempDef.dataType = DATATYPE_INT;
	ind_EngPwrReductionDueToTempDef.qtTypeName = "int";
	ind_EngPwrReductionDueToTempDef.signalType = kSignalTypeConsumer;
	ind_EngPwrReductionDueToTempDef.persistent = false;
	ind_EngPwrReductionDueToTempDef.pgn = 65476;
	ind_EngPwrReductionDueToTempDef.signal = m_ind_EngPwrReductionDueToTemp;
	signalTypeDefs["ind_EngPwrReductionDueToTemp"] = ind_EngPwrReductionDueToTempDef;

	m_ind_HVWarning = new IntConsumerSignal(false, false, 0, 65476);
	SIGNALTYPEDEF ind_HVWarningDef;
	ind_HVWarningDef.dataType = DATATYPE_INT;
	ind_HVWarningDef.qtTypeName = "int";
	ind_HVWarningDef.signalType = kSignalTypeConsumer;
	ind_HVWarningDef.persistent = false;
	ind_HVWarningDef.pgn = 65476;
	ind_HVWarningDef.signal = m_ind_HVWarning;
	signalTypeDefs["ind_HVWarning"] = ind_HVWarningDef;

	m_ind_HVIsolation = new IntConsumerSignal(false, false, 0, 65476);
	SIGNALTYPEDEF ind_HVIsolationDef;
	ind_HVIsolationDef.dataType = DATATYPE_INT;
	ind_HVIsolationDef.qtTypeName = "int";
	ind_HVIsolationDef.signalType = kSignalTypeConsumer;
	ind_HVIsolationDef.persistent = false;
	ind_HVIsolationDef.pgn = 65476;
	ind_HVIsolationDef.signal = m_ind_HVIsolation;
	signalTypeDefs["ind_HVIsolation"] = ind_HVIsolationDef;

	m_ind_HVFailure = new IntConsumerSignal(false, false, 0, 65476);
	SIGNALTYPEDEF ind_HVFailureDef;
	ind_HVFailureDef.dataType = DATATYPE_INT;
	ind_HVFailureDef.qtTypeName = "int";
	ind_HVFailureDef.signalType = kSignalTypeConsumer;
	ind_HVFailureDef.persistent = false;
	ind_HVFailureDef.pgn = 65476;
	ind_HVFailureDef.signal = m_ind_HVFailure;
	signalTypeDefs["ind_HVFailure"] = ind_HVFailureDef;

	m_ind_ElectricEngineStartEnable = new IntConsumerSignal(false, false, 0, 65476);
	SIGNALTYPEDEF ind_ElectricEngineStartEnableDef;
	ind_ElectricEngineStartEnableDef.dataType = DATATYPE_INT;
	ind_ElectricEngineStartEnableDef.qtTypeName = "int";
	ind_ElectricEngineStartEnableDef.signalType = kSignalTypeConsumer;
	ind_ElectricEngineStartEnableDef.persistent = false;
	ind_ElectricEngineStartEnableDef.pgn = 65476;
	ind_ElectricEngineStartEnableDef.signal = m_ind_ElectricEngineStartEnable;
	signalTypeDefs["ind_ElectricEngineStartEnable"] = ind_ElectricEngineStartEnableDef;

	m_ind_ChargingPlugConnected = new IntConsumerSignal(false, false, 0, 65476);
	SIGNALTYPEDEF ind_ChargingPlugConnectedDef;
	ind_ChargingPlugConnectedDef.dataType = DATATYPE_INT;
	ind_ChargingPlugConnectedDef.qtTypeName = "int";
	ind_ChargingPlugConnectedDef.signalType = kSignalTypeConsumer;
	ind_ChargingPlugConnectedDef.persistent = false;
	ind_ChargingPlugConnectedDef.pgn = 65476;
	ind_ChargingPlugConnectedDef.signal = m_ind_ChargingPlugConnected;
	signalTypeDefs["ind_ChargingPlugConnected"] = ind_ChargingPlugConnectedDef;

	m_ind_ChargingFlapOpened = new IntConsumerSignal(false, false, 0, 65476);
	SIGNALTYPEDEF ind_ChargingFlapOpenedDef;
	ind_ChargingFlapOpenedDef.dataType = DATATYPE_INT;
	ind_ChargingFlapOpenedDef.qtTypeName = "int";
	ind_ChargingFlapOpenedDef.signalType = kSignalTypeConsumer;
	ind_ChargingFlapOpenedDef.persistent = false;
	ind_ChargingFlapOpenedDef.pgn = 65476;
	ind_ChargingFlapOpenedDef.signal = m_ind_ChargingFlapOpened;
	signalTypeDefs["ind_ChargingFlapOpened"] = ind_ChargingFlapOpenedDef;

	m_ind_ChargingActive = new IntConsumerSignal(false, false, 0, 65476);
	SIGNALTYPEDEF ind_ChargingActiveDef;
	ind_ChargingActiveDef.dataType = DATATYPE_INT;
	ind_ChargingActiveDef.qtTypeName = "int";
	ind_ChargingActiveDef.signalType = kSignalTypeConsumer;
	ind_ChargingActiveDef.persistent = false;
	ind_ChargingActiveDef.pgn = 65476;
	ind_ChargingActiveDef.signal = m_ind_ChargingActive;
	signalTypeDefs["ind_ChargingActive"] = ind_ChargingActiveDef;

	m_ind_CellBalancing = new IntConsumerSignal(false, false, 0, 65476);
	SIGNALTYPEDEF ind_CellBalancingDef;
	ind_CellBalancingDef.dataType = DATATYPE_INT;
	ind_CellBalancingDef.qtTypeName = "int";
	ind_CellBalancingDef.signalType = kSignalTypeConsumer;
	ind_CellBalancingDef.persistent = false;
	ind_CellBalancingDef.pgn = 65476;
	ind_CellBalancingDef.signal = m_ind_CellBalancing;
	signalTypeDefs["ind_CellBalancing"] = ind_CellBalancingDef;

	m_ind_ElectricEngineStartWarning = new IntConsumerSignal(false, false, 0, 65476);
	SIGNALTYPEDEF ind_ElectricEngineStartWarningDef;
	ind_ElectricEngineStartWarningDef.dataType = DATATYPE_INT;
	ind_ElectricEngineStartWarningDef.qtTypeName = "int";
	ind_ElectricEngineStartWarningDef.signalType = kSignalTypeConsumer;
	ind_ElectricEngineStartWarningDef.persistent = false;
	ind_ElectricEngineStartWarningDef.pgn = 65476;
	ind_ElectricEngineStartWarningDef.signal = m_ind_ElectricEngineStartWarning;
	signalTypeDefs["ind_ElectricEngineStartWarning"] = ind_ElectricEngineStartWarningDef;

	m_ind_ElectricEngineStartError = new IntConsumerSignal(false, false, 0, 65476);
	SIGNALTYPEDEF ind_ElectricEngineStartErrorDef;
	ind_ElectricEngineStartErrorDef.dataType = DATATYPE_INT;
	ind_ElectricEngineStartErrorDef.qtTypeName = "int";
	ind_ElectricEngineStartErrorDef.signalType = kSignalTypeConsumer;
	ind_ElectricEngineStartErrorDef.persistent = false;
	ind_ElectricEngineStartErrorDef.pgn = 65476;
	ind_ElectricEngineStartErrorDef.signal = m_ind_ElectricEngineStartError;
	signalTypeDefs["ind_ElectricEngineStartError"] = ind_ElectricEngineStartErrorDef;

	m_ind_48VBatteryLowTemperature = new IntConsumerSignal(false, false, 0, 65476);
	SIGNALTYPEDEF ind_48VBatteryLowTemperatureDef;
	ind_48VBatteryLowTemperatureDef.dataType = DATATYPE_INT;
	ind_48VBatteryLowTemperatureDef.qtTypeName = "int";
	ind_48VBatteryLowTemperatureDef.signalType = kSignalTypeConsumer;
	ind_48VBatteryLowTemperatureDef.persistent = false;
	ind_48VBatteryLowTemperatureDef.pgn = 65476;
	ind_48VBatteryLowTemperatureDef.signal = m_ind_48VBatteryLowTemperature;
	signalTypeDefs["ind_48VBatteryLowTemperature"] = ind_48VBatteryLowTemperatureDef;

	m_ind_48VBatteryHighTemperature = new IntConsumerSignal(false, false, 0, 65476);
	SIGNALTYPEDEF ind_48VBatteryHighTemperatureDef;
	ind_48VBatteryHighTemperatureDef.dataType = DATATYPE_INT;
	ind_48VBatteryHighTemperatureDef.qtTypeName = "int";
	ind_48VBatteryHighTemperatureDef.signalType = kSignalTypeConsumer;
	ind_48VBatteryHighTemperatureDef.persistent = false;
	ind_48VBatteryHighTemperatureDef.pgn = 65476;
	ind_48VBatteryHighTemperatureDef.signal = m_ind_48VBatteryHighTemperature;
	signalTypeDefs["ind_48VBatteryHighTemperature"] = ind_48VBatteryHighTemperatureDef;

	m_ind_EngineCoolingFanFailure = new IntConsumerSignal(false, false, 0, 65475);
	SIGNALTYPEDEF ind_EngineCoolingFanFailureDef;
	ind_EngineCoolingFanFailureDef.dataType = DATATYPE_INT;
	ind_EngineCoolingFanFailureDef.qtTypeName = "int";
	ind_EngineCoolingFanFailureDef.signalType = kSignalTypeConsumer;
	ind_EngineCoolingFanFailureDef.persistent = false;
	ind_EngineCoolingFanFailureDef.pgn = 65475;
	ind_EngineCoolingFanFailureDef.signal = m_ind_EngineCoolingFanFailure;
	signalTypeDefs["ind_EngineCoolingFanFailure"] = ind_EngineCoolingFanFailureDef;

	m_ind_OilExchangeRequest = new IntConsumerSignal(false, false, 0, 65475);
	SIGNALTYPEDEF ind_OilExchangeRequestDef;
	ind_OilExchangeRequestDef.dataType = DATATYPE_INT;
	ind_OilExchangeRequestDef.qtTypeName = "int";
	ind_OilExchangeRequestDef.signalType = kSignalTypeConsumer;
	ind_OilExchangeRequestDef.persistent = false;
	ind_OilExchangeRequestDef.pgn = 65475;
	ind_OilExchangeRequestDef.signal = m_ind_OilExchangeRequest;
	signalTypeDefs["ind_OilExchangeRequest"] = ind_OilExchangeRequestDef;

	m_ind_NCD_Malfunction = new IntConsumerSignal(false, false, 0, 65475);
	SIGNALTYPEDEF ind_NCD_MalfunctionDef;
	ind_NCD_MalfunctionDef.dataType = DATATYPE_INT;
	ind_NCD_MalfunctionDef.qtTypeName = "int";
	ind_NCD_MalfunctionDef.signalType = kSignalTypeConsumer;
	ind_NCD_MalfunctionDef.persistent = false;
	ind_NCD_MalfunctionDef.pgn = 65475;
	ind_NCD_MalfunctionDef.signal = m_ind_NCD_Malfunction;
	signalTypeDefs["ind_NCD_Malfunction"] = ind_NCD_MalfunctionDef;

	m_ind_DPFRegenerationDisabled = new IntConsumerSignal(false, false, 0, 65475);
	SIGNALTYPEDEF ind_DPFRegenerationDisabledDef;
	ind_DPFRegenerationDisabledDef.dataType = DATATYPE_INT;
	ind_DPFRegenerationDisabledDef.qtTypeName = "int";
	ind_DPFRegenerationDisabledDef.signalType = kSignalTypeConsumer;
	ind_DPFRegenerationDisabledDef.persistent = false;
	ind_DPFRegenerationDisabledDef.pgn = 65475;
	ind_DPFRegenerationDisabledDef.signal = m_ind_DPFRegenerationDisabled;
	signalTypeDefs["ind_DPFRegenerationDisabled"] = ind_DPFRegenerationDisabledDef;

	m_ind_DPF_ExhaustLamp = new IntConsumerSignal(false, false, 0, 65475);
	SIGNALTYPEDEF ind_DPF_ExhaustLampDef;
	ind_DPF_ExhaustLampDef.dataType = DATATYPE_INT;
	ind_DPF_ExhaustLampDef.qtTypeName = "int";
	ind_DPF_ExhaustLampDef.signalType = kSignalTypeConsumer;
	ind_DPF_ExhaustLampDef.persistent = false;
	ind_DPF_ExhaustLampDef.pgn = 65475;
	ind_DPF_ExhaustLampDef.signal = m_ind_DPF_ExhaustLamp;
	signalTypeDefs["ind_DPF_ExhaustLamp"] = ind_DPF_ExhaustLampDef;

	m_ind_DPF_AshLoad = new IntConsumerSignal(false, false, 0, 65475);
	SIGNALTYPEDEF ind_DPF_AshLoadDef;
	ind_DPF_AshLoadDef.dataType = DATATYPE_INT;
	ind_DPF_AshLoadDef.qtTypeName = "int";
	ind_DPF_AshLoadDef.signalType = kSignalTypeConsumer;
	ind_DPF_AshLoadDef.persistent = false;
	ind_DPF_AshLoadDef.pgn = 65475;
	ind_DPF_AshLoadDef.signal = m_ind_DPF_AshLoad;
	signalTypeDefs["ind_DPF_AshLoad"] = ind_DPF_AshLoadDef;

	m_ind_WaterInFuel = new IntConsumerSignal(false, false, 0, 65475);
	SIGNALTYPEDEF ind_WaterInFuelDef;
	ind_WaterInFuelDef.dataType = DATATYPE_INT;
	ind_WaterInFuelDef.qtTypeName = "int";
	ind_WaterInFuelDef.signalType = kSignalTypeConsumer;
	ind_WaterInFuelDef.persistent = false;
	ind_WaterInFuelDef.pgn = 65475;
	ind_WaterInFuelDef.signal = m_ind_WaterInFuel;
	signalTypeDefs["ind_WaterInFuel"] = ind_WaterInFuelDef;

	m_ind_DieselExhaustFluid = new IntConsumerSignal(false, false, 0, 65475);
	SIGNALTYPEDEF ind_DieselExhaustFluidDef;
	ind_DieselExhaustFluidDef.dataType = DATATYPE_INT;
	ind_DieselExhaustFluidDef.qtTypeName = "int";
	ind_DieselExhaustFluidDef.signalType = kSignalTypeConsumer;
	ind_DieselExhaustFluidDef.persistent = false;
	ind_DieselExhaustFluidDef.pgn = 65475;
	ind_DieselExhaustFluidDef.signal = m_ind_DieselExhaustFluid;
	signalTypeDefs["ind_DieselExhaustFluid"] = ind_DieselExhaustFluidDef;

	m_ind_DPFRegeneration = new IntConsumerSignal(false, false, 0, 65475);
	SIGNALTYPEDEF ind_DPFRegenerationDef;
	ind_DPFRegenerationDef.dataType = DATATYPE_INT;
	ind_DPFRegenerationDef.qtTypeName = "int";
	ind_DPFRegenerationDef.signalType = kSignalTypeConsumer;
	ind_DPFRegenerationDef.persistent = false;
	ind_DPFRegenerationDef.pgn = 65475;
	ind_DPFRegenerationDef.signal = m_ind_DPFRegeneration;
	signalTypeDefs["ind_DPFRegeneration"] = ind_DPFRegenerationDef;

	m_ind_EngineWarning = new IntConsumerSignal(false, false, 0, 65475);
	SIGNALTYPEDEF ind_EngineWarningDef;
	ind_EngineWarningDef.dataType = DATATYPE_INT;
	ind_EngineWarningDef.qtTypeName = "int";
	ind_EngineWarningDef.signalType = kSignalTypeConsumer;
	ind_EngineWarningDef.persistent = false;
	ind_EngineWarningDef.pgn = 65475;
	ind_EngineWarningDef.signal = m_ind_EngineWarning;
	signalTypeDefs["ind_EngineWarning"] = ind_EngineWarningDef;

	m_ind_EngineFailure = new IntConsumerSignal(false, false, 0, 65475);
	SIGNALTYPEDEF ind_EngineFailureDef;
	ind_EngineFailureDef.dataType = DATATYPE_INT;
	ind_EngineFailureDef.qtTypeName = "int";
	ind_EngineFailureDef.signalType = kSignalTypeConsumer;
	ind_EngineFailureDef.persistent = false;
	ind_EngineFailureDef.pgn = 65475;
	ind_EngineFailureDef.signal = m_ind_EngineFailure;
	signalTypeDefs["ind_EngineFailure"] = ind_EngineFailureDef;

	m_ind_EngineOilLevel = new IntConsumerSignal(false, false, 0, 65475);
	SIGNALTYPEDEF ind_EngineOilLevelDef;
	ind_EngineOilLevelDef.dataType = DATATYPE_INT;
	ind_EngineOilLevelDef.qtTypeName = "int";
	ind_EngineOilLevelDef.signalType = kSignalTypeConsumer;
	ind_EngineOilLevelDef.persistent = false;
	ind_EngineOilLevelDef.pgn = 65475;
	ind_EngineOilLevelDef.signal = m_ind_EngineOilLevel;
	signalTypeDefs["ind_EngineOilLevel"] = ind_EngineOilLevelDef;

	m_ind_EngineOilPressure = new IntConsumerSignal(false, false, 0, 65475);
	SIGNALTYPEDEF ind_EngineOilPressureDef;
	ind_EngineOilPressureDef.dataType = DATATYPE_INT;
	ind_EngineOilPressureDef.qtTypeName = "int";
	ind_EngineOilPressureDef.signalType = kSignalTypeConsumer;
	ind_EngineOilPressureDef.persistent = false;
	ind_EngineOilPressureDef.pgn = 65475;
	ind_EngineOilPressureDef.signal = m_ind_EngineOilPressure;
	signalTypeDefs["ind_EngineOilPressure"] = ind_EngineOilPressureDef;

	m_ind_LoadAlarmWarning = new IntConsumerSignal(false, false, 0, 65473);
	SIGNALTYPEDEF ind_LoadAlarmWarningDef;
	ind_LoadAlarmWarningDef.dataType = DATATYPE_INT;
	ind_LoadAlarmWarningDef.qtTypeName = "int";
	ind_LoadAlarmWarningDef.signalType = kSignalTypeConsumer;
	ind_LoadAlarmWarningDef.persistent = false;
	ind_LoadAlarmWarningDef.pgn = 65473;
	ind_LoadAlarmWarningDef.signal = m_ind_LoadAlarmWarning;
	signalTypeDefs["ind_LoadAlarmWarning"] = ind_LoadAlarmWarningDef;

	m_ind_LoadAlarmError = new IntConsumerSignal(false, false, 0, 65473);
	SIGNALTYPEDEF ind_LoadAlarmErrorDef;
	ind_LoadAlarmErrorDef.dataType = DATATYPE_INT;
	ind_LoadAlarmErrorDef.qtTypeName = "int";
	ind_LoadAlarmErrorDef.signalType = kSignalTypeConsumer;
	ind_LoadAlarmErrorDef.persistent = false;
	ind_LoadAlarmErrorDef.pgn = 65473;
	ind_LoadAlarmErrorDef.signal = m_ind_LoadAlarmError;
	signalTypeDefs["ind_LoadAlarmError"] = ind_LoadAlarmErrorDef;

	m_ind_ImmobilzerIsLocked = new IntConsumerSignal(false, false, 0, 65473);
	SIGNALTYPEDEF ind_ImmobilzerIsLockedDef;
	ind_ImmobilzerIsLockedDef.dataType = DATATYPE_INT;
	ind_ImmobilzerIsLockedDef.qtTypeName = "int";
	ind_ImmobilzerIsLockedDef.signalType = kSignalTypeConsumer;
	ind_ImmobilzerIsLockedDef.persistent = false;
	ind_ImmobilzerIsLockedDef.pgn = 65473;
	ind_ImmobilzerIsLockedDef.signal = m_ind_ImmobilzerIsLocked;
	signalTypeDefs["ind_ImmobilzerIsLocked"] = ind_ImmobilzerIsLockedDef;

	m_ind_CruiseControlIsActivated = new IntConsumerSignal(false, false, 0, 65473);
	SIGNALTYPEDEF ind_CruiseControlIsActivatedDef;
	ind_CruiseControlIsActivatedDef.dataType = DATATYPE_INT;
	ind_CruiseControlIsActivatedDef.qtTypeName = "int";
	ind_CruiseControlIsActivatedDef.signalType = kSignalTypeConsumer;
	ind_CruiseControlIsActivatedDef.persistent = false;
	ind_CruiseControlIsActivatedDef.pgn = 65473;
	ind_CruiseControlIsActivatedDef.signal = m_ind_CruiseControlIsActivated;
	signalTypeDefs["ind_CruiseControlIsActivated"] = ind_CruiseControlIsActivatedDef;

	m_ind_ECUWarning = new IntConsumerSignal(false, false, 0, 65473);
	SIGNALTYPEDEF ind_ECUWarningDef;
	ind_ECUWarningDef.dataType = DATATYPE_INT;
	ind_ECUWarningDef.qtTypeName = "int";
	ind_ECUWarningDef.signalType = kSignalTypeConsumer;
	ind_ECUWarningDef.persistent = false;
	ind_ECUWarningDef.pgn = 65473;
	ind_ECUWarningDef.signal = m_ind_ECUWarning;
	signalTypeDefs["ind_ECUWarning"] = ind_ECUWarningDef;

	m_ind_ECUFailure = new IntConsumerSignal(false, false, 0, 65473);
	SIGNALTYPEDEF ind_ECUFailureDef;
	ind_ECUFailureDef.dataType = DATATYPE_INT;
	ind_ECUFailureDef.qtTypeName = "int";
	ind_ECUFailureDef.signalType = kSignalTypeConsumer;
	ind_ECUFailureDef.persistent = false;
	ind_ECUFailureDef.pgn = 65473;
	ind_ECUFailureDef.signal = m_ind_ECUFailure;
	signalTypeDefs["ind_ECUFailure"] = ind_ECUFailureDef;

	m_ind_TestModeIsActive = new IntConsumerSignal(false, false, 0, 65473);
	SIGNALTYPEDEF ind_TestModeIsActiveDef;
	ind_TestModeIsActiveDef.dataType = DATATYPE_INT;
	ind_TestModeIsActiveDef.qtTypeName = "int";
	ind_TestModeIsActiveDef.signalType = kSignalTypeConsumer;
	ind_TestModeIsActiveDef.persistent = false;
	ind_TestModeIsActiveDef.pgn = 65473;
	ind_TestModeIsActiveDef.signal = m_ind_TestModeIsActive;
	signalTypeDefs["ind_TestModeIsActive"] = ind_TestModeIsActiveDef;

	m_ind_CanFailure = new IntConsumerSignal(false, false, 0, 65473);
	SIGNALTYPEDEF ind_CanFailureDef;
	ind_CanFailureDef.dataType = DATATYPE_INT;
	ind_CanFailureDef.qtTypeName = "int";
	ind_CanFailureDef.signalType = kSignalTypeConsumer;
	ind_CanFailureDef.persistent = false;
	ind_CanFailureDef.pgn = 65473;
	ind_CanFailureDef.signal = m_ind_CanFailure;
	signalTypeDefs["ind_CanFailure"] = ind_CanFailureDef;

	m_ind_SelectedGear = new IntConsumerSignal(false, false, 0, 65473);
	SIGNALTYPEDEF ind_SelectedGearDef;
	ind_SelectedGearDef.dataType = DATATYPE_INT;
	ind_SelectedGearDef.qtTypeName = "int";
	ind_SelectedGearDef.signalType = kSignalTypeConsumer;
	ind_SelectedGearDef.persistent = false;
	ind_SelectedGearDef.pgn = 65473;
	ind_SelectedGearDef.signal = m_ind_SelectedGear;
	signalTypeDefs["ind_SelectedGear"] = ind_SelectedGearDef;

	m_ind_TractionControl_ASR = new IntConsumerSignal(false, false, 0, 65473);
	SIGNALTYPEDEF ind_TractionControl_ASRDef;
	ind_TractionControl_ASRDef.dataType = DATATYPE_INT;
	ind_TractionControl_ASRDef.qtTypeName = "int";
	ind_TractionControl_ASRDef.signalType = kSignalTypeConsumer;
	ind_TractionControl_ASRDef.persistent = false;
	ind_TractionControl_ASRDef.pgn = 65473;
	ind_TractionControl_ASRDef.signal = m_ind_TractionControl_ASR;
	signalTypeDefs["ind_TractionControl_ASR"] = ind_TractionControl_ASRDef;

	m_ind_UpperCarrierInPosition = new IntConsumerSignal(false, false, 0, 65473);
	SIGNALTYPEDEF ind_UpperCarrierInPositionDef;
	ind_UpperCarrierInPositionDef.dataType = DATATYPE_INT;
	ind_UpperCarrierInPositionDef.qtTypeName = "int";
	ind_UpperCarrierInPositionDef.signalType = kSignalTypeConsumer;
	ind_UpperCarrierInPositionDef.persistent = false;
	ind_UpperCarrierInPositionDef.pgn = 65473;
	ind_UpperCarrierInPositionDef.signal = m_ind_UpperCarrierInPosition;
	signalTypeDefs["ind_UpperCarrierInPosition"] = ind_UpperCarrierInPositionDef;

	m_ind_ReverseSteering = new IntConsumerSignal(false, false, 0, 65473);
	SIGNALTYPEDEF ind_ReverseSteeringDef;
	ind_ReverseSteeringDef.dataType = DATATYPE_INT;
	ind_ReverseSteeringDef.qtTypeName = "int";
	ind_ReverseSteeringDef.signalType = kSignalTypeConsumer;
	ind_ReverseSteeringDef.persistent = false;
	ind_ReverseSteeringDef.pgn = 65473;
	ind_ReverseSteeringDef.signal = m_ind_ReverseSteering;
	signalTypeDefs["ind_ReverseSteering"] = ind_ReverseSteeringDef;

	m_ind_ISOSAE = new IntConsumerSignal(false, false, 0, 65473);
	SIGNALTYPEDEF ind_ISOSAEDef;
	ind_ISOSAEDef.dataType = DATATYPE_INT;
	ind_ISOSAEDef.qtTypeName = "int";
	ind_ISOSAEDef.signalType = kSignalTypeConsumer;
	ind_ISOSAEDef.persistent = false;
	ind_ISOSAEDef.pgn = 65473;
	ind_ISOSAEDef.signal = m_ind_ISOSAE;
	signalTypeDefs["ind_ISOSAE"] = ind_ISOSAEDef;

	m_ind_RearPlate = new IntConsumerSignal(false, false, 0, 65473);
	SIGNALTYPEDEF ind_RearPlateDef;
	ind_RearPlateDef.dataType = DATATYPE_INT;
	ind_RearPlateDef.qtTypeName = "int";
	ind_RearPlateDef.signalType = kSignalTypeConsumer;
	ind_RearPlateDef.persistent = false;
	ind_RearPlateDef.pgn = 65473;
	ind_RearPlateDef.signal = m_ind_RearPlate;
	signalTypeDefs["ind_RearPlate"] = ind_RearPlateDef;

	m_ind_FrontPlate = new IntConsumerSignal(false, false, 0, 65473);
	SIGNALTYPEDEF ind_FrontPlateDef;
	ind_FrontPlateDef.dataType = DATATYPE_INT;
	ind_FrontPlateDef.qtTypeName = "int";
	ind_FrontPlateDef.signalType = kSignalTypeConsumer;
	ind_FrontPlateDef.persistent = false;
	ind_FrontPlateDef.pgn = 65473;
	ind_FrontPlateDef.signal = m_ind_FrontPlate;
	signalTypeDefs["ind_FrontPlate"] = ind_FrontPlateDef;

	m_ind_RearAxleIsInMiddlePosition = new IntConsumerSignal(false, false, 0, 65473);
	SIGNALTYPEDEF ind_RearAxleIsInMiddlePositionDef;
	ind_RearAxleIsInMiddlePositionDef.dataType = DATATYPE_INT;
	ind_RearAxleIsInMiddlePositionDef.qtTypeName = "int";
	ind_RearAxleIsInMiddlePositionDef.signalType = kSignalTypeConsumer;
	ind_RearAxleIsInMiddlePositionDef.persistent = false;
	ind_RearAxleIsInMiddlePositionDef.pgn = 65473;
	ind_RearAxleIsInMiddlePositionDef.signal = m_ind_RearAxleIsInMiddlePosition;
	signalTypeDefs["ind_RearAxleIsInMiddlePosition"] = ind_RearAxleIsInMiddlePositionDef;

	m_ind_FrontAxleIsInMiddlePosition = new IntConsumerSignal(false, false, 0, 65473);
	SIGNALTYPEDEF ind_FrontAxleIsInMiddlePositionDef;
	ind_FrontAxleIsInMiddlePositionDef.dataType = DATATYPE_INT;
	ind_FrontAxleIsInMiddlePositionDef.qtTypeName = "int";
	ind_FrontAxleIsInMiddlePositionDef.signalType = kSignalTypeConsumer;
	ind_FrontAxleIsInMiddlePositionDef.persistent = false;
	ind_FrontAxleIsInMiddlePositionDef.pgn = 65473;
	ind_FrontAxleIsInMiddlePositionDef.signal = m_ind_FrontAxleIsInMiddlePosition;
	signalTypeDefs["ind_FrontAxleIsInMiddlePosition"] = ind_FrontAxleIsInMiddlePositionDef;

	m_ind_FourWheelSteering = new IntConsumerSignal(false, false, 0, 65473);
	SIGNALTYPEDEF ind_FourWheelSteeringDef;
	ind_FourWheelSteeringDef.dataType = DATATYPE_INT;
	ind_FourWheelSteeringDef.qtTypeName = "int";
	ind_FourWheelSteeringDef.signalType = kSignalTypeConsumer;
	ind_FourWheelSteeringDef.persistent = false;
	ind_FourWheelSteeringDef.pgn = 65473;
	ind_FourWheelSteeringDef.signal = m_ind_FourWheelSteering;
	signalTypeDefs["ind_FourWheelSteering"] = ind_FourWheelSteeringDef;

	m_ind_CrabSteering = new IntConsumerSignal(false, false, 0, 65473);
	SIGNALTYPEDEF ind_CrabSteeringDef;
	ind_CrabSteeringDef.dataType = DATATYPE_INT;
	ind_CrabSteeringDef.qtTypeName = "int";
	ind_CrabSteeringDef.signalType = kSignalTypeConsumer;
	ind_CrabSteeringDef.persistent = false;
	ind_CrabSteeringDef.pgn = 65473;
	ind_CrabSteeringDef.signal = m_ind_CrabSteering;
	signalTypeDefs["ind_CrabSteering"] = ind_CrabSteeringDef;

	m_ind_BucketControlChangeOver = new IntConsumerSignal(false, false, 0, 65473);
	SIGNALTYPEDEF ind_BucketControlChangeOverDef;
	ind_BucketControlChangeOverDef.dataType = DATATYPE_INT;
	ind_BucketControlChangeOverDef.qtTypeName = "int";
	ind_BucketControlChangeOverDef.signalType = kSignalTypeConsumer;
	ind_BucketControlChangeOverDef.persistent = false;
	ind_BucketControlChangeOverDef.pgn = 65473;
	ind_BucketControlChangeOverDef.signal = m_ind_BucketControlChangeOver;
	signalTypeDefs["ind_BucketControlChangeOver"] = ind_BucketControlChangeOverDef;

	m_ind_DayNightChangeOver = new IntConsumerSignal(false, false, 0, 65473);
	SIGNALTYPEDEF ind_DayNightChangeOverDef;
	ind_DayNightChangeOverDef.dataType = DATATYPE_INT;
	ind_DayNightChangeOverDef.qtTypeName = "int";
	ind_DayNightChangeOverDef.signalType = kSignalTypeConsumer;
	ind_DayNightChangeOverDef.persistent = false;
	ind_DayNightChangeOverDef.pgn = 65473;
	ind_DayNightChangeOverDef.signal = m_ind_DayNightChangeOver;
	signalTypeDefs["ind_DayNightChangeOver"] = ind_DayNightChangeOverDef;

	m_ind_SwingAxleIsLocked = new IntConsumerSignal(false, false, 0, 65473);
	SIGNALTYPEDEF ind_SwingAxleIsLockedDef;
	ind_SwingAxleIsLockedDef.dataType = DATATYPE_INT;
	ind_SwingAxleIsLockedDef.qtTypeName = "int";
	ind_SwingAxleIsLockedDef.signalType = kSignalTypeConsumer;
	ind_SwingAxleIsLockedDef.persistent = false;
	ind_SwingAxleIsLockedDef.pgn = 65473;
	ind_SwingAxleIsLockedDef.signal = m_ind_SwingAxleIsLocked;
	signalTypeDefs["ind_SwingAxleIsLocked"] = ind_SwingAxleIsLockedDef;

	m_ind_QuickHitchIsOpen = new IntConsumerSignal(false, false, 0, 65473);
	SIGNALTYPEDEF ind_QuickHitchIsOpenDef;
	ind_QuickHitchIsOpenDef.dataType = DATATYPE_INT;
	ind_QuickHitchIsOpenDef.qtTypeName = "int";
	ind_QuickHitchIsOpenDef.signalType = kSignalTypeConsumer;
	ind_QuickHitchIsOpenDef.persistent = false;
	ind_QuickHitchIsOpenDef.pgn = 65473;
	ind_QuickHitchIsOpenDef.signal = m_ind_QuickHitchIsOpen;
	signalTypeDefs["ind_QuickHitchIsOpen"] = ind_QuickHitchIsOpenDef;

	m_ind_HydraulicSystemFailure = new IntConsumerSignal(false, false, 0, 65473);
	SIGNALTYPEDEF ind_HydraulicSystemFailureDef;
	ind_HydraulicSystemFailureDef.dataType = DATATYPE_INT;
	ind_HydraulicSystemFailureDef.qtTypeName = "int";
	ind_HydraulicSystemFailureDef.signalType = kSignalTypeConsumer;
	ind_HydraulicSystemFailureDef.persistent = false;
	ind_HydraulicSystemFailureDef.pgn = 65473;
	ind_HydraulicSystemFailureDef.signal = m_ind_HydraulicSystemFailure;
	signalTypeDefs["ind_HydraulicSystemFailure"] = ind_HydraulicSystemFailureDef;

	m_ind_EcoMode = new IntConsumerSignal(false, false, 0, 65473);
	SIGNALTYPEDEF ind_EcoModeDef;
	ind_EcoModeDef.dataType = DATATYPE_INT;
	ind_EcoModeDef.qtTypeName = "int";
	ind_EcoModeDef.signalType = kSignalTypeConsumer;
	ind_EcoModeDef.persistent = false;
	ind_EcoModeDef.pgn = 65473;
	ind_EcoModeDef.signal = m_ind_EcoMode;
	signalTypeDefs["ind_EcoMode"] = ind_EcoModeDef;

	m_ind_AutoIdle = new IntConsumerSignal(false, false, 0, 65473);
	SIGNALTYPEDEF ind_AutoIdleDef;
	ind_AutoIdleDef.dataType = DATATYPE_INT;
	ind_AutoIdleDef.qtTypeName = "int";
	ind_AutoIdleDef.signalType = kSignalTypeConsumer;
	ind_AutoIdleDef.persistent = false;
	ind_AutoIdleDef.pgn = 65473;
	ind_AutoIdleDef.signal = m_ind_AutoIdle;
	signalTypeDefs["ind_AutoIdle"] = ind_AutoIdleDef;

	m_ind_AutoEngineStop = new IntConsumerSignal(false, false, 0, 65473);
	SIGNALTYPEDEF ind_AutoEngineStopDef;
	ind_AutoEngineStopDef.dataType = DATATYPE_INT;
	ind_AutoEngineStopDef.qtTypeName = "int";
	ind_AutoEngineStopDef.signalType = kSignalTypeConsumer;
	ind_AutoEngineStopDef.persistent = false;
	ind_AutoEngineStopDef.pgn = 65473;
	ind_AutoEngineStopDef.signal = m_ind_AutoEngineStop;
	signalTypeDefs["ind_AutoEngineStop"] = ind_AutoEngineStopDef;

	m_ind_DrivingDirectionChoosen = new IntConsumerSignal(false, false, 0, 65473);
	SIGNALTYPEDEF ind_DrivingDirectionChoosenDef;
	ind_DrivingDirectionChoosenDef.dataType = DATATYPE_INT;
	ind_DrivingDirectionChoosenDef.qtTypeName = "int";
	ind_DrivingDirectionChoosenDef.signalType = kSignalTypeConsumer;
	ind_DrivingDirectionChoosenDef.persistent = false;
	ind_DrivingDirectionChoosenDef.pgn = 65473;
	ind_DrivingDirectionChoosenDef.signal = m_ind_DrivingDirectionChoosen;
	signalTypeDefs["ind_DrivingDirectionChoosen"] = ind_DrivingDirectionChoosenDef;



    // Initialize dataengine link
initConnection("localhost",0x1235,"QML_Application");

}

DataEngine::~DataEngine()
{
}

FieldbusAccessError *DataEngine::fieldbusAccessError()
{
    return m_fieldbusAccessError;
}

FieldbusAccessErrorModel *DataEngine::faErrorModel()
{
    return m_faErrorModel;
}

void DataEngine::receiveFieldbusAccess_J1939Error(QVariant value, int bus)
{
    // Update Error Object
    m_fieldbusAccessError->setData(value.value<QByteArray>(), bus);

    // Update Error Model
    m_faErrorModel->addError(value.value<QByteArray>(), bus);

}

void DataEngine::handleNewError(FieldbusAccessError *error)
{
    uint pgn_candidate = error->addInfo();

    if (pgn_candidate == 0 || error->identifier() == FieldbusAccessError::MEM_ERR_ID)
        return; // Not a PGN specific error.

    foreach (SIGNALTYPEDEF s, signalTypeDefs) {
        if (s.pgn < 0)
            continue; // Pure dataengine signal (marked with a pgn of -1). Can't have an attached fieldbusaccess error.

        if (((uint)s.pgn) == pgn_candidate) {
            // Found an affected signal!
            s.signal->addError(error);
            s.signal->setStatus(DataEngineSignal::SIGNALERROR);
        }
    }

}

void DataEngine::handleClearedError(FieldbusAccessError *error)
{
    if (error->addInfo() == 0 || error->identifier() == FieldbusAccessError::MEM_ERR_ID)
        return; // Not a PGN specific error.

    uint errPgn = error->addInfo();
    foreach (SIGNALTYPEDEF s, signalTypeDefs) {
        if (s.pgn < 0)
            continue; // Pure dataengine signal (marked with a pgn of -1). Can't have an attached fieldbusaccess error.

        if (((uint)s.pgn) == errPgn) {
            // Found an affected signal!
            s.signal->removeError(error);
            if (s.signal->errors().size() == 0) {
                if (m_faErrorModel->stackError())
                    s.signal->setStatus(DataEngineSignal::STACKERROR);
                else
                    s.signal->setStatus(DataEngineSignal::OK);
            }
        }
    }

}

void DataEngine::handleStackError(bool exists)
{
    foreach (SIGNALTYPEDEF s, signalTypeDefs) {
        if (s.pgn != -1) {
            if (!exists && s.signal->status() == DataEngineSignal::STACKERROR)
                // Found an affected signal!
                s.signal->setStatus(DataEngineSignal::OK);
            else if (exists && s.signal->status() == DataEngineSignal::OK)
                s.signal->setStatus(DataEngineSignal::STACKERROR);

        }
    }

}



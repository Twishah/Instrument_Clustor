#include "can_handler3.h"

#include <QDebug>
#include <QProcess>

#ifdef TARGET_ARM_IMX6
#include "CCAuxTypes.h"
#include "CanSetting.h"
#endif


CAN_Handler3::CAN_Handler3(QObject *parent) : QObject(parent)
{

#ifdef TARGET_ARM_IMX6
	//Set baud rate of Can0
	void* pCanSetting = CrossControl::GetCanSetting();
	CrossControl::CanSetting_setBaudrate(pCanSetting, 1, 500);
#endif

	//Command line to start Can0.  This can also be done through CCAux
	QProcess CANProcess;
	CANProcess.start("ifconfig can0 up");
	CANProcess.waitForFinished();
	CANProcess.close();

	//-------------------CAN Set Up ----------------------------------
	// Create class to handle CAN communication.  This class is created from the canwrapper classes inluded
	can = new CanWrapper();

	// Create a worker thread that listens to CAN messages and sends data to GUI with signal/slot mecanism
	m_workerThread = new CanWorkerThread();

	// connect signal from worker thread to slot in this class
	connect(m_workerThread, SIGNAL(msgReceived(int,int,int,int,int,int,int,int,int)), this, SLOT(msgReceived(int,int,int,int,int,int,int,int,int)));

	// Init new connection
	QString str = "can0";
	int errorCode;
	int ret = can->Init(str.toUtf8(), errorCode);
	if(!ret)
	{
		qDebug() << "Could not initialize CAN net. Error code: " << QString::number(errorCode);

		return;
	}

	// Enable error messages to be reported
	can->EnableErrorMessages();

	// initialize worker thread
	m_workerThread->Init(can);

	// Start thread
	m_workerThread->start();

	// ----------------Init CAN Signals ----------------------------------------------
//    m_Battery_SOH = 0;

#ifdef TARGET_ARM_IMX6
	CrossControl::CanSetting_release(pCanSetting);
#endif

}

CAN_Handler3::~CAN_Handler3()
{

}

void CAN_Handler3::msgReceived(int ID, int Data_0, int Data_1, int Data_2, int Data_3, int Data_4, int Data_5, int Data_6, int Data_7)
{
	// Extract source address from the ID
	uint8_t SrcAddress = ID & 0x000000FFU;

	uint16_t u16TPPGN;
	uint8_t u8ArrTPMsg[28U] = {0xFFU};
	uint16_t u16TPMsgLength = 0U;


	//When a new message is received by the worker thread this slot is called.  The worker thread will pass the ID of the new message as well as the 8 bytes of data
	//Take the ID and find the CAN message ID
	QByteArray c = QByteArray::number(ID, 16);
	if (c.length() == 7)
	{
		ID = c.mid(1, 4).toInt(nullptr, 16);
	}
	else if (c.length() == 8)
	{
		ID = c.mid(2, 4).toInt(nullptr, 16);
	}

	if ((ID == 0xECFF)  && (SrcAddress == 71)) { // hier muss das TP abgebildet werden
	}

	//Now that we have the CAN message ID, look for the CAN PGN you want and pull out the correct data for the necissary signal in that PGN
	if ((ID == 65242) && (SrcAddress == 71)) // CAN ID is 0x18FEDA47
	{
		//If the old value of is different than the latest value, emit the  signal and change the value
		if (m_McuSOFTNbOfSoftIdentFields != Data_0)
		{
			m_McuSOFTNbOfSoftIdentFields = Data_0;
			emit McuSOFTNbOfSoftIdentFieldsChanged(m_McuSOFTNbOfSoftIdentFields);
		}

		if (m_McuSOFTSoftwarePartNumber != Data_1)
		{
			m_McuSOFTSoftwarePartNumber = Data_1;
			emit McuSOFTSoftwarePartNumberChanged(m_McuSOFTSoftwarePartNumber);
		}

		if (m_McuSOFTVersion != Data_2)
		{
			m_McuSOFTVersion = Data_2;
			emit McuSOFTVersionChanged(m_McuSOFTVersion);
		}

		if (m_McuSOFTPartNumber != Data_3)
		{
			m_McuSOFTPartNumber = Data_3;
			emit McuSOFTPartNumberChanged(m_McuSOFTPartNumber);
		}

		if (m_McuSOFTType != Data_4)
		{
			m_McuSOFTType = Data_4;
			emit McuSOFTTypeChanged(m_McuSOFTType);
		}

		if (m_McuSOFTCustomerSoftNumber != Data_5)
		{
			m_McuSOFTCustomerSoftNumber = Data_5;
			emit McuSOFTCustomerSoftNumberChanged(m_McuSOFTCustomerSoftNumber);
		}
	} else if ((ID == 65393) && (SrcAddress == 71)) {// CAN ID is 0xCFF7147
		//If the old value of is different than the latest value, emit the  signal and change the value
		if (m_BrakePedalPos != (int)(Data_0*0.4))
		{
			m_BrakePedalPos = (int)(Data_0*0.4);
			emit BrakePedalPosChanged(m_BrakePedalPos);
		}

		if (m_AccelPedalPos != (int)(Data_1*0.4))
		{
			m_AccelPedalPos = (int)(Data_1*0.4);
			emit AccelPedalPosChanged(m_AccelPedalPos);
		}
	} else if ((ID == 65455) && (SrcAddress == 71)) {// CAN ID is 0x18FFAF47
		//If the old value of is different than the latest value, emit the  signal and change the value
		if (m_BtnMenuCalendar_Visible != (0b00000001 & Data_0))
		{
			m_BtnMenuCalendar_Visible = 0b00000001 & Data_0;
			emit BtnMenuCalendar_VisibleChanged(m_BtnMenuCalendar_Visible);
		}

		if (m_BtnMenuImmobilizer_Visible != (0b00000001 & (Data_0 >> 1)))
		{
			m_BtnMenuImmobilizer_Visible = 0b00000001 & (Data_0 >> 1);
			emit BtnMenuImmobilizer_VisibleChanged(m_BtnMenuImmobilizer_Visible);
		}

		if (m_BtnMenuHeating_Visible != (0b00000001 & (Data_0 >> 2)))
		{
			m_BtnMenuHeating_Visible = 0b00000001 & (Data_0 >> 2);
			emit BtnMenuHeating_VisibleChanged(m_BtnMenuHeating_Visible);
		}

		if (m_BtnMenuMonitor_Visible != (0b00000001 & (Data_0 >> 3)))
		{
			m_BtnMenuMonitor_Visible = 0b00000001 & (Data_0 >> 3);
			emit BtnMenuMonitor_VisibleChanged(m_BtnMenuMonitor_Visible);
		}

		if (m_BtnMenuMaintenance_Visible != (0b00000001 & (Data_0 >> 4)))
		{
			m_BtnMenuMaintenance_Visible = 0b00000001 & (Data_0 >> 4);
			emit BtnMenuMaintenance_VisibleChanged(m_BtnMenuMaintenance_Visible);
		}

		if (m_BtnMenuFiltrRegen_Visible != (0b00000001 & (Data_0 >> 5)))
		{
			m_BtnMenuFiltrRegen_Visible = 0b00000001 & (Data_0 >> 5);
			emit BtnMenuFiltrRegen_VisibleChanged(m_BtnMenuFiltrRegen_Visible);
		}

		if (m_AdjustAddCtrlCircuit1_Visible != (0b00000001 & Data_2))
		{
			m_AdjustAddCtrlCircuit1_Visible = 0b00000001 & Data_2;
			emit AdjustAddCtrlCircuit1_VisibleChanged(m_AdjustAddCtrlCircuit1_Visible);
		}

		if (m_AdjustAddCtrlCircuit2_Visible != (0b00000001 & (Data_2 >> 1)))
		{
			m_AdjustAddCtrlCircuit2_Visible = 0b00000001 & (Data_2 >> 1);
			emit AdjustAddCtrlCircuit2_VisibleChanged(m_AdjustAddCtrlCircuit2_Visible);
		}

		if (m_AdjustRCSForward_Visible != (0b00000001 & (Data_2 >> 5)))
		{
			m_AdjustRCSForward_Visible = 0b00000001 & (Data_2 >> 5);
			emit AdjustRCSForward_VisibleChanged(m_AdjustRCSForward_Visible);
		}

		if (m_AdjustRCSBackward_Visible != (0b00000001 & (Data_2 >> 6)))
		{
			m_AdjustRCSBackward_Visible = 0b00000001 & (Data_2 >> 6);
			emit AdjustRCSBackward_VisibleChanged(m_AdjustRCSBackward_Visible);
		}

		if (m_AdjustAutoEngineStopTime_Visible != (0b00000001 & (Data_2 >> 7)))
		{
			m_AdjustAutoEngineStopTime_Visible = 0b00000001 & (Data_2 >> 7);
			emit AdjustAutoEngineStopTime_VisibleChanged(m_AdjustAutoEngineStopTime_Visible);
		}

		if (m_BtnFctDateTimeAutomatic_Visible != (0b00000001 & (Data_5 >> 7)))
		{
			m_BtnFctDateTimeAutomatic_Visible = 0b00000001 & (Data_5 >> 7);
			emit BtnFctDateTimeAutomatic_VisibleChanged(m_BtnFctDateTimeAutomatic_Visible);
		}
	} else if ((ID == 65454) && (SrcAddress == 71)) {// CAN ID is 0x18FFAE47
		//If the old value of is different than the latest value, emit the  signal and change the value
		if (m_BtnImmobActivation_Visible != (0b00000001 & Data_0))
		{
			m_BtnImmobActivation_Visible = 0b00000001 & Data_0;
			emit BtnImmobActivation_VisibleChanged(m_BtnImmobActivation_Visible);
		}

		if (m_BtnImmobOwnerPin_Visible != (0b00000001 & (Data_0 >> 1)))
		{
			m_BtnImmobOwnerPin_Visible = 0b00000001 & (Data_0 >> 1);
			emit BtnImmobOwnerPin_VisibleChanged(m_BtnImmobOwnerPin_Visible);
		}

		if (m_BtnImmobDriverPin_Visible != (0b00000001 & (Data_0 >> 2)))
		{
			m_BtnImmobDriverPin_Visible = 0b00000001 & (Data_0 >> 2);
			emit BtnImmobDriverPin_VisibleChanged(m_BtnImmobDriverPin_Visible);
		}

		if (m_BtnImmobTransPin_Visible != (0b00000001 & (Data_0 >> 3)))
		{
			m_BtnImmobTransPin_Visible = 0b00000001 & (Data_0 >> 3);
			emit BtnImmobTransPin_VisibleChanged(m_BtnImmobTransPin_Visible);
		}

		if (m_BtnImmobTimeToActivation_Visible != (0b00000001 & (Data_0 >> 4)))
		{
			m_BtnImmobTimeToActivation_Visible = 0b00000001 & (Data_0 >> 4);
			emit BtnImmobTimeToActivation_VisibleChanged(m_BtnImmobTimeToActivation_Visible);
		}

		if (m_BtnDiagMCU_Visible != (0b00000001 & (Data_1 >> 4)))
		{
			m_BtnDiagMCU_Visible = 0b00000001 & (Data_1 >> 4);
			emit BtnDiagMCU_VisibleChanged(m_BtnDiagMCU_Visible);
		}

		if (m_BtnDiagTCU_Visible != (0b00000001 & (Data_1 >> 5)))
		{
			m_BtnDiagTCU_Visible = 0b00000001 & (Data_1 >> 5);
			emit BtnDiagTCU_VisibleChanged(m_BtnDiagTCU_Visible);
		}

		if (m_BtnDiagECU_Visible != (0b00000001 & (Data_1 >> 1)))
		{
			m_BtnDiagECU_Visible = 0b00000001 & (Data_1 >> 1);
			emit BtnDiagECU_VisibleChanged(m_BtnDiagECU_Visible);
		}
	} else if ((ID == 65316) && (SrcAddress == 3)) {// CAN ID is 0x18FF2403
		//If the old value of is different than the latest value, emit the  signal and change the value
		if (m_dmdDrvPedl != (int)(Data_0*0.4))
		{
			m_dmdDrvPedl = (int)(Data_0*0.4);
			emit dmdDrvPedlChanged(m_dmdDrvPedl);
		}

		if (m_dmdInchPedl != (int)(Data_1*0.4))
		{
			m_dmdInchPedl = (int)(Data_1*0.4);
			emit dmdInchPedlChanged(m_dmdInchPedl);
		}

		if (m_dmdCrpPoti != (int)(Data_2*0.4))
		{
			m_dmdCrpPoti = (int)(Data_2*0.4);
			emit dmdCrpPotiChanged(m_dmdCrpPoti);
		}

		if (m_dmdHndThr != (int)(Data_3*0.4))
		{
			m_dmdHndThr = (int)(Data_3*0.4);
			emit dmdHndThrChanged(m_dmdHndThr);
		}
	} else if ((ID == 61443) && (SrcAddress == 0)) {// CAN ID is 0xCF0030
		//If the old value of is different than the latest value, emit the  signal and change the value
		if (m_engPercentLoadAtCurrentSpeed != Data_2)
		{
			m_engPercentLoadAtCurrentSpeed = Data_2;
			emit engPercentLoadAtCurrentSpeedChanged(m_engPercentLoadAtCurrentSpeed);
		}
	} else if ((ID == 61456) && (SrcAddress == 43)) {// CAN ID is 0x19F0102B

		//If the old value of is different than the latest value, emit the  signal and change the value
		QByteArray Byte3 = QByteArray::number(Data_3, 16);
		QByteArray Byte2 = QByteArray::number(Data_2, 16);
		if (Byte2.length()==1)
			Byte2.prepend(QByteArray::number(0, 8));
		Byte3.append(Byte2);
		uint16_t dateVal_u16 = Byte3.toUInt(nullptr,16);
		if (m_SarDate != dateVal_u16)
		{
			m_SarDate = dateVal_u16;
			emit SarDateChanged(m_SarDate);
		}

		uint32_t timeVal_u32 = 0;
		timeVal_u32 |= Data_4 | Data_5<<8 | Data_6<<16 | Data_7<<24;

		if (m_SarTime != timeVal_u32*0.001)
		{
			m_SarTime = (uint32_t)(timeVal_u32*0.0001);
			emit SarTimeChanged(m_SarTime);
		}
	} else if ((ID == 65297) && (SrcAddress == 0)) {// CAN ID is 0x18FF1100

		//If the old value of is different than the latest value, emit the  signal and change the value
		if (m_StartRelay != (int)(Data_6))
		{
			m_StartRelay = (int)(Data_6);
			emit StartRelayChanged(m_StartRelay);
		}
	} else if ((ID == 65243) && (SrcAddress == 0)) {// CAN ID is 0x18FEDB00

		//If the old value of is different than the latest value, emit the  signal and change the value
		QByteArray Byte3 = QByteArray::number(Data_3, 16);
		QByteArray Byte2 = QByteArray::number(Data_2, 16);
		if (Byte2.length()==1)
			Byte2.prepend(QByteArray::number(0, 8));
		Byte3.append(Byte2);
		float railPVal_f32 = Byte3.toUInt(nullptr,16)*0.00390625;
		if (m_railP != railPVal_f32)
		{
			m_railP = railPVal_f32;
			emit RailPChanged(m_railP);
		}
	} else if ((ID == 61444) && (SrcAddress == 0)) {// CAN ID is 0xCF00400

		//If the old value of is different than the latest value, emit the  signal and change the value
		QByteArray Byte4 = QByteArray::number(Data_4, 16);
		QByteArray Byte3 = QByteArray::number(Data_3, 16);
		if (Byte3.length()==1)
			Byte3.prepend(QByteArray::number(0, 8));
		Byte4.append(Byte3);
		float engSpeedVal_f32 = Byte4.toUInt(nullptr,16)*0.125;
		if (m_engSpeed != engSpeedVal_f32)
		{
			m_engSpeed = engSpeedVal_f32;
			emit EngSpeedChanged(m_engSpeed);
		}
	} else if ((ID == 65266) && (SrcAddress == 0)) {// CAN ID is 0x18FEF200

		//If the old value of is different than the latest value, emit the  signal and change the value
		QByteArray Byte1 = QByteArray::number(Data_1, 16);
		QByteArray Byte0 = QByteArray::number(Data_0, 16);
		if (Byte0.length()==1)
			Byte0.prepend(QByteArray::number(0, 8));
		Byte1.append(Byte0);
		float fuelRateVal_f32 = Byte1.toUInt(nullptr,16)*0.05;
		if (m_fuelPerHour != fuelRateVal_f32)
		{
			m_fuelPerHour = fuelRateVal_f32;
			emit FuelPerHourChanged(m_fuelPerHour);
		}
	}
}

void CAN_Handler3::sendCAN(int ID, int Data_0, int Data_1, int Data_2, int Data_3, int Data_4, int Data_5, int Data_6, int Data_7)
{
	//This is a short example of sending a CAN message.  It simply sends a message which incements the first byte of data each time sendCAN is called.
	//See the sendMsg function in the worker thread class to see what needs to be sent

	//can_send_increment++;
	//m_workerThread->sendMsg(217056504,can_send_increment,3,4,5,6,7,8,9);
	//qDebug() << can_send_increment;
	//qDebug() << "Sending CAN ID : " << ID << ": " << Data_0 << " " << Data_1 << " " << Data_2 << " " << Data_3 << " " << Data_4 << " " << Data_5 << " " << Data_6 << " " << Data_7;
	m_workerThread->sendMsg(ID, Data_0, Data_1, Data_2, Data_3, Data_4, Data_5, Data_6, Data_7);
}

QVariantMap CAN_Handler3::getCanTimeoutError()
{
	return m_workerThread->getCanWorkerTimeoutError();
}

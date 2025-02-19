#ifndef CAN_HANDLER3_H
#define CAN_HANDLER3_H

//Can Includes
#include "canworkerthread.h"
//#include "CanSetting.h"

class CAN_Handler3 : public QObject
{
    //Need to add this to be able to add the QPROPERTY below
    Q_OBJECT
    //The Q_PROPERTY needs to be setup to expose the class signals and slots to QML as is done in the main.cpp file
    Q_PROPERTY(int McuSOFTNbOfSoftIdentFields READ getMcuSOFTNbOfSoftIdentFields NOTIFY McuSOFTNbOfSoftIdentFieldsChanged)
    Q_PROPERTY(int McuSOFTSoftwarePartNumber READ getMcuSOFTSoftwarePartNumber NOTIFY McuSOFTSoftwarePartNumberChanged)
    Q_PROPERTY(int McuSOFTVersion READ getMcuSOFTVersion NOTIFY McuSOFTVersionChanged)
    Q_PROPERTY(int McuSOFTPartNumber READ getMcuSOFTPartNumber NOTIFY McuSOFTPartNumberChanged)
    Q_PROPERTY(int McuSOFTType READ getMcuSOFTType NOTIFY McuSOFTTypeChanged)
    Q_PROPERTY(int McuSOFTCustomerSoftNumber READ getMcuSOFTCustomerSoftNumber NOTIFY McuSOFTCustomerSoftNumberChanged)

    Q_PROPERTY(int BrakePedalPos READ getBrakePedalPos NOTIFY BrakePedalPosChanged)
    Q_PROPERTY(int AccelPedalPos READ getAccelPedalPos NOTIFY AccelPedalPosChanged)

    Q_PROPERTY(int BtnMenuCalendar_Visible READ getBtnMenuCalendar_Visible NOTIFY BtnMenuCalendar_VisibleChanged)
    Q_PROPERTY(int BtnMenuImmobilizer_Visible READ getBtnMenuImmobilizer_Visible NOTIFY BtnMenuImmobilizer_VisibleChanged)
    Q_PROPERTY(int BtnMenuHeating_Visible READ getBtnMenuHeating_Visible NOTIFY BtnMenuHeating_VisibleChanged)
    Q_PROPERTY(int BtnMenuMonitor_Visible READ getBtnMenuMonitor_Visible NOTIFY BtnMenuMonitor_VisibleChanged)
    Q_PROPERTY(int BtnMenuMaintenance_Visible READ getBtnMenuMaintenance_Visible NOTIFY BtnMenuMaintenance_VisibleChanged)
    Q_PROPERTY(int BtnMenuFiltrRegen_Visible READ getBtnMenuFiltrRegen_Visible NOTIFY BtnMenuFiltrRegen_VisibleChanged)
    Q_PROPERTY(int AdjustAddCtrlCircuit1_Visible READ getAdjustAddCtrlCircuit1_Visible NOTIFY AdjustAddCtrlCircuit1_VisibleChanged)
    Q_PROPERTY(int AdjustAddCtrlCircuit2_Visible READ getAdjustAddCtrlCircuit2_Visible NOTIFY AdjustAddCtrlCircuit2_VisibleChanged)
    Q_PROPERTY(int AdjustRCSForward_Visible READ getAdjustRCSForward_Visible NOTIFY AdjustRCSForward_VisibleChanged)
    Q_PROPERTY(int AdjustRCSBackward_Visible READ getAdjustRCSBackward_Visible NOTIFY AdjustRCSBackward_VisibleChanged)
    Q_PROPERTY(int AdjustAutoEngineStopTime_Visible READ getAdjustAutoEngineStopTime_Visible NOTIFY AdjustAutoEngineStopTime_VisibleChanged)
    Q_PROPERTY(int BtnFctDateTimeAutomatic_Visible READ getBtnFctDateTimeAutomatic_Visible NOTIFY BtnFctDateTimeAutomatic_VisibleChanged)

    Q_PROPERTY(int BtnImmobActivation_Visible READ getBtnImmobActivation_Visible NOTIFY BtnImmobActivation_VisibleChanged)
    Q_PROPERTY(int BtnImmobOwnerPin_Visible READ getBtnImmobOwnerPin_Visible NOTIFY BtnImmobOwnerPin_VisibleChanged)
    Q_PROPERTY(int BtnImmobDriverPin_Visible READ getBtnImmobDriverPin_Visible NOTIFY BtnImmobDriverPin_VisibleChanged)
    Q_PROPERTY(int BtnImmobTransPin_Visible READ getBtnImmobTransPin_Visible NOTIFY BtnImmobTransPin_VisibleChanged)
    Q_PROPERTY(int BtnImmobTimeToActivation_Visible READ getBtnImmobTimeToActivation_Visible NOTIFY BtnImmobTimeToActivation_VisibleChanged)
    Q_PROPERTY(int BtnDiagMCU_Visible READ getBtnDiagMCU_Visible NOTIFY BtnDiagMCU_VisibleChanged)
    Q_PROPERTY(int BtnDiagTCU_Visible READ getBtnDiagTCU_Visible NOTIFY BtnDiagTCU_VisibleChanged)
    Q_PROPERTY(int BtnDiagECU_Visible READ getBtnDiagECU_Visible NOTIFY BtnDiagECU_VisibleChanged)

    Q_PROPERTY(int dmdDrvPedl READ getdmdDrvPedl NOTIFY dmdDrvPedlChanged)
    Q_PROPERTY(int dmdInchPedl READ getdmdInchPedl NOTIFY dmdInchPedlChanged)
    Q_PROPERTY(int dmdCrpPoti READ getdmdCrpPoti NOTIFY dmdCrpPotiChanged)
    Q_PROPERTY(int dmdHndThr READ getdmdHndThr NOTIFY dmdHndThrChanged)

    Q_PROPERTY(int sarDate READ getSarDate NOTIFY SarDateChanged)
    Q_PROPERTY(int sarTime READ getSarTime NOTIFY SarTimeChanged)

    Q_PROPERTY(int startRelay READ getStartRelay NOTIFY StartRelayChanged)

    Q_PROPERTY(double railP READ getRailP NOTIFY RailPChanged)

    Q_PROPERTY(double engSpeed READ getEngSpeed NOTIFY EngSpeedChanged)

    Q_PROPERTY(double fuelPerHour READ getFuelPerHour NOTIFY FuelPerHourChanged)

    Q_PROPERTY(int engPercentLoadAtCurrentSpeed READ getEngPercentLoadAtCurrentSpeed NOTIFY engPercentLoadAtCurrentSpeedChanged)

    Q_PROPERTY(bool ErrorExists READ getCanError)
    Q_PROPERTY(int ErrorCode READ getCanErrorCode)

public:
    explicit CAN_Handler3(QObject *parent = 0);
    ~CAN_Handler3();

    int getMcuSOFTNbOfSoftIdentFields() const{
        return m_McuSOFTNbOfSoftIdentFields;}

    int getMcuSOFTSoftwarePartNumber() const{
        return m_McuSOFTSoftwarePartNumber;}

    int getMcuSOFTVersion() const{
        return m_McuSOFTVersion;}

    int getMcuSOFTPartNumber() const{
        return m_McuSOFTPartNumber;}

    int getMcuSOFTType() const{
        return m_McuSOFTType;}

    int getMcuSOFTCustomerSoftNumber() const{
        return m_McuSOFTCustomerSoftNumber;}

    int getBrakePedalPos() const{
        return m_BrakePedalPos;}

    int getAccelPedalPos() const{
        return m_AccelPedalPos;}

    int getBtnMenuCalendar_Visible() const{
        return m_BtnMenuCalendar_Visible;}

    int getBtnMenuImmobilizer_Visible() const{
        return m_BtnMenuImmobilizer_Visible;}

    int getBtnMenuHeating_Visible() const{
        return m_BtnMenuHeating_Visible;}

    int getBtnMenuMonitor_Visible() const{
        return m_BtnMenuMonitor_Visible;}

    int getBtnMenuMaintenance_Visible() const{
        return m_BtnMenuMaintenance_Visible;}

    int getBtnMenuFiltrRegen_Visible() const{
        return m_BtnMenuFiltrRegen_Visible;}

    int getAdjustAddCtrlCircuit1_Visible() const{
        return m_AdjustAddCtrlCircuit1_Visible;}

    int getAdjustAddCtrlCircuit2_Visible() const{
        return m_AdjustAddCtrlCircuit2_Visible;}

    int getAdjustRCSForward_Visible() const{
        return m_AdjustRCSForward_Visible;}

    int getAdjustRCSBackward_Visible() const{
        return m_AdjustRCSBackward_Visible;}

    int getAdjustAutoEngineStopTime_Visible() const{
        return m_AdjustAutoEngineStopTime_Visible;}

    int getBtnFctDateTimeAutomatic_Visible() const{
        return m_BtnFctDateTimeAutomatic_Visible;}

    int getBtnImmobActivation_Visible() const{
        return m_BtnImmobActivation_Visible;}

    int getBtnImmobOwnerPin_Visible() const{
        return m_BtnImmobOwnerPin_Visible;}

    int getBtnImmobDriverPin_Visible() const{
        return m_BtnImmobDriverPin_Visible;}

    int getBtnImmobTransPin_Visible() const{
        return m_BtnImmobTransPin_Visible;}

    int getBtnImmobTimeToActivation_Visible() const{
        return m_BtnImmobTimeToActivation_Visible;}

    int getBtnDiagMCU_Visible() const{
        return m_BtnDiagMCU_Visible;}

    int getBtnDiagTCU_Visible() const{
        return m_BtnDiagTCU_Visible;}

    int getBtnDiagECU_Visible() const{
        return m_BtnDiagECU_Visible;}

    int getdmdDrvPedl() const{
        return m_dmdDrvPedl;}

    int getdmdInchPedl() const{
        return m_dmdInchPedl;}

    int getdmdCrpPoti() const{
        return m_dmdCrpPoti;}

    int getdmdHndThr() const{
        return m_dmdHndThr;}

    int getSarDate() const{
        return m_SarDate;}

    uint32_t getSarTime() const{
        return m_SarTime;}

    int getStartRelay() const{
        return m_StartRelay;}

    double getRailP() const{
        return m_railP;}

    double getEngSpeed() const{
        return m_engSpeed;}

    double getFuelPerHour() const{
        return m_fuelPerHour;}

    int getEngPercentLoadAtCurrentSpeed() const{
        return m_engPercentLoadAtCurrentSpeed;
    }


    Q_INVOKABLE QString byteArrayToHexString(const QByteArray& byteArray)
    {
        return QString::fromUtf8(byteArray.toHex());
    }
    Q_INVOKABLE QVariantMap getCanTimeoutError();
    Q_INVOKABLE void sendCAN(int ID, int Data_0, int Data_1, int Data_2, int Data_3, int Data_4, int Data_5, int Data_6, int Data_7);

    bool getCanError() const{
        return m_workerThread->getCanWorkerError() ;}

    int getCanErrorCode() const{
        return m_workerThread->getCanWorkerErrorCode();}
signals:
    //this needs to be setup to expose the class to QML.  This will tell the QML code when the engine speed value is changed so it is updated
    void McuSOFTNbOfSoftIdentFieldsChanged(int);
    void McuSOFTSoftwarePartNumberChanged(int);
    void McuSOFTVersionChanged(int);
    void McuSOFTPartNumberChanged(int);
    void McuSOFTTypeChanged(int);
    void McuSOFTCustomerSoftNumberChanged(int);

    void BrakePedalPosChanged(int);
    void AccelPedalPosChanged(int);

    void BtnMenuCalendar_VisibleChanged(int);
    void BtnMenuImmobilizer_VisibleChanged(int);
    void BtnMenuHeating_VisibleChanged(int);
    void BtnMenuMonitor_VisibleChanged(int);
    void BtnMenuMaintenance_VisibleChanged(int);
    void BtnMenuFiltrRegen_VisibleChanged(int);
    void AdjustAddCtrlCircuit1_VisibleChanged(int);
    void AdjustAddCtrlCircuit2_VisibleChanged(int);
    void AdjustRCSForward_VisibleChanged(int);
    void AdjustRCSBackward_VisibleChanged(int);
    void AdjustAutoEngineStopTime_VisibleChanged(int);
    void BtnFctDateTimeAutomatic_VisibleChanged(int);

    void BtnImmobActivation_VisibleChanged(int);
    void BtnImmobOwnerPin_VisibleChanged(int);
    void BtnImmobDriverPin_VisibleChanged(int);
    void BtnImmobTransPin_VisibleChanged(int);
    void BtnImmobTimeToActivation_VisibleChanged(int);
    void BtnDiagMCU_VisibleChanged(int);
    void BtnDiagTCU_VisibleChanged(int);
    void BtnDiagECU_VisibleChanged(int);

    void dmdDrvPedlChanged(int);
    void dmdInchPedlChanged(int);
    void dmdCrpPotiChanged(int);
    void dmdHndThrChanged(int);

    void SarDateChanged(int);
    void SarTimeChanged(uint32_t);

    void StartRelayChanged(int);

    void RailPChanged(double);

    void EngSpeedChanged(double);

    void FuelPerHourChanged(double);

    void engPercentLoadAtCurrentSpeedChanged(int);

private:
    //CAN CCAux declarations
//    CrossControl::CANSETTINGHANDLE pCanSetting;
    CanWrapper *can;                    // Can wrapper class
    CanWorkerThread *m_workerThread;    // Thread that blocks and listens for CAN messages

    //CAN Variables
    int m_McuSOFTNbOfSoftIdentFields = 0;
    int m_McuSOFTSoftwarePartNumber = 0;
    int m_McuSOFTVersion = 0;
    int m_McuSOFTPartNumber = 0;
    int m_McuSOFTType = 0;
    int m_McuSOFTCustomerSoftNumber = 0;

    int m_BrakePedalPos = 0;
    int m_AccelPedalPos = 0;

    int m_BtnMenuCalendar_Visible = 0;
    int m_BtnMenuImmobilizer_Visible = 0;
    int m_BtnMenuHeating_Visible = 0;
    int m_BtnMenuMonitor_Visible = 0;
    int m_BtnMenuMaintenance_Visible = 0;
    int m_BtnMenuFiltrRegen_Visible = 0;
    int m_AdjustAddCtrlCircuit1_Visible = 0;
    int m_AdjustAddCtrlCircuit2_Visible = 0;
    int m_AdjustRCSForward_Visible = 0;
    int m_AdjustRCSBackward_Visible = 0;
    int m_AdjustAutoEngineStopTime_Visible = 0;
    int m_BtnFctDateTimeAutomatic_Visible = 0;

    int m_BtnImmobActivation_Visible = 0;
    int m_BtnImmobOwnerPin_Visible = 0;
    int m_BtnImmobDriverPin_Visible = 0;
    int m_BtnImmobTransPin_Visible = 0;
    int m_BtnImmobTimeToActivation_Visible = 0;
    int m_BtnDiagECU_Visible = 0;
    int m_BtnDiagMCU_Visible = 0;
    int m_BtnDiagTCU_Visible = 0;

    int m_dmdDrvPedl = 0;
    int m_dmdInchPedl = 0;
    int m_dmdCrpPoti = 0;
    int m_dmdHndThr = 0;

    int m_SarDate = 0;
    uint32_t m_SarTime = 0;

    int m_StartRelay = 0;

    double m_railP = 0.0;

    double m_engSpeed = 0.0;

    double m_fuelPerHour = 0.0;

    int m_engPercentLoadAtCurrentSpeed = 0;

private slots:
    //CAN message handlers
    void msgReceived(int ID, int Data_0, int Data_1, int Data_2, int Data_3, int Data_4, int Data_5, int Data_6, int Data_7);

};

#endif // CAN_HANDLER3_H

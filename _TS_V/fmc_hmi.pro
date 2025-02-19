QT += quick
CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES +=         main.cpp \
    backend/backend.cpp \
    backend/displayConfigHandler.cpp \
    backend/hwbutton.cpp \
    CCAux/BackLightHandler.cpp \
    CCAux/BuzzerHandler.cpp \
    CCAux/VersionHandler.cpp \
    CCAux/PowerConfigHandler.cpp \
    backend/coolingtemperature.cpp \
    backend/remainingtime.cpp \
    backend/dataManager.cpp \
    backend/ptosettings.cpp \
    backend/preheating.cpp \
    backend/popupmanager.cpp \
    backend/dateTimeManager.cpp \
    backend/canwrapper.cpp \
    backend/canworkerthread.cpp \
    backend/can_handler3.cpp \
    backend/maintenancehistory.cpp \
    backend/mechanichistory.cpp \
    backend/errormanager.cpp \
    backend/runprocess.cpp

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH = /opt/Qt-5.12.0/5.12.0/gcc_64/qml

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH = /opt/Qt-5.12.0/5.12.0/gcc_64/qml

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES +=     qml.qrc \
    qml.qrc

DISTFILES +=     main.qml \
    components/Comp_boxNumber.qml \
    components/Comp_BrightnessGauge.qml \
    components/Comp_buttonTempl.qml \
    components/Comp_buzzerManager.qml \
    components/Comp_controller.qml \
    components/Comp_dateTime.qml \
    components/Comp_intervalChange.qml \
    components/Comp_listIcon.qml \
    components/Comp_listIconNew.qml \
    components/Comp_listItem.qml \
    components/Comp_listItemErrorInfoList.qml \
    components/Comp_listItemLargeListSelection.qml \
    components/Comp_listItemLargeStatusBarIcon.qml \
    components/Comp_listItemLineStatusBarIcon.qml \
    components/Comp_listItemStatusBarIcon.qml \
    components/Comp_listItemUsageHistory.qml \
    components/Comp_navigationBar.qml \
    components/Comp_pageHeaderControl.qml \
    components/Comp_ptoSettingGauge.qml \
    components/Comp_specificClassification_calendar.qml \
    components/Comp_specificClassification_levelActivate.qml \
    components/Comp_specificClassification_levelDate.qml \
    components/Comp_specificClassification_levelWorkStart.qml \
    pages/PG_home.qml \
    pages/PG_preHeating.qml \
    pages/PG_ptoSettings.qml \
    pages/PG_grid.qml \
    pages/PG_largeList.qml \
    pages/PG_list.qml \
    pages/PG_listDetails.qml \
    pages/PG_listIcon.qml \
    pages/PG_listStatusBar.qml \
    pages/PG_dateSelection.qml \
    pages/PG_gauge.qml \
    pages/PG_lineStatusBarIcon.qml \
    pages/PG_largeListSelection.qml \
    pages/PG_calendar.qml \
    pages/PG_opTimeMeas.qml \
    pages/PG_passcode.qml \
    pages/PG_home2.qml \
    pages/PG_listLargeStatusBar.qml \
    pages/PG_popUp.qml \
    pages/PG_listIconMultiple.qml \
    pages/PG_listMechanic.qml \
    Linguist/fmc_hmi_fr.ts \
    Linguist/fmc_hmi_fr.ts \
    Linguist/fmc_hmi_en.ts \
    Linguist/fmc_hmi_fr.ts \
    Linguist/fmc_hmi_en.qm \
    Linguist/fmc_hmi_fr.qm \
    Linguist/fmc_hmi_en.ts \
    Linguist/fmc_hmi_fr.ts \
    Linguist/fmc_hmi_en.qm \
    Linguist/fmc_hmi_fr.qm \
    Linguist/fmc_hmi_da.ts \
    Linguist/fmc_hmi_de.ts \
    Linguist/fmc_hmi_en.ts \
    Linguist/fmc_hmi_es.ts \
    Linguist/fmc_hmi_fi.ts \
    Linguist/fmc_hmi_fr.ts \
    Linguist/fmc_hmi_it.ts \
    Linguist/fmc_hmi_nl.ts \
    Linguist/fmc_hmi_pl.ts \
    Linguist/fmc_hmi_pt.ts \
    Linguist/fmc_hmi_sv.ts \
    configuration.json \
    configuration.backup.json \
    configuration.default.json \
    dtc.json \
    history.json \
    Makefile \
    components/Comp_arrayWarningPictos.qml \
    components/Comp_velocityGaugeControl.qml \
    pages/PG_immobilizer.qml \
    components/Comp_pinComboBox.qml \
    components/Comp_pinBox.qml \
    components/Comp_mainIndicators.qml \
    components/Comp_timeValidationGauge.qml \
    pages/PG_immobilizerActivation.qml \
    components/Comp_switchOnOff.qml \
    pages/PG_pinCode.qml \
    pages/PG_immobilizerTimeValidation.qml \
    components/Comp_capacityGauge.qml \
    pages/PG_sootLevel.qml \
    pages/PG_ashLevel.qml \
    components/Comp_gauge.qml \
    pages/PG_RCSForward.qml \
    pages/PG_RCSBackward.qml \
    components/Comp_indicatorLight.qml \
    components/Comp_arrayNoticePictos.qml \
    components/Comp_arrayNoticePictosV8.qml \
    components/Comp_arrayWarningPictosV8e.qml \
    components/Comp_noticePicto.qml

unix: {
    linux-g++ { # Qt5 x86
       message(Compiling for Qt $$QT_VERSION OS Version - Linux Virtual Machine)
       DEFINES += TARGET_X86
       LIB_PATH = /opt/lib
       INCLUDEPATH += /opt/crosscontrol/include
    }

    linux-arm-none-gnueabi-g++ {
       message(Compiling for Qt $$QT_VERSION LinX Version - Linux ARM iMX5 CCpilot)
       DEFINES += LINUX
       DEFINES += CCAUX
       DEFINES += TARGET_ARM_IMX5
       QML_IMPORT_PATH = /opt/VA/Qt-5.6.3/qml
       LIBS += -lcc-aux2
    }

    linux-oe-g++ { # Qt5 VS/VI2 OS version
       DEFINES += LINUX
       DEFINES += CCAUX
       DEFINES += TARGET_ARM_IMX6
       LIBS += -lcc-aux2
       message(Compiling for Qt $$QT_VERSION OS Version - Linux ARM iMX6 CCpilot)
    }

    linux-imx6-g++ { # Qt5.12.0 LinX version VS/VI2
       DEFINES += LINUX
       DEFINES += CCAUX
       DEFINES += TARGET_ARM_IMX6
       LIBS += -lcc-aux2
       message(Compiling for Qt $$QT_VERSION LinX Version - Linux ARM iMX6 CCpilot)
    }

    linux-imx8-g++ { # i.MX 8
        message(Compiling for Qt $$QT_VERSION LinX Version - Linux ARM iMX8 CCpilot)
        DEFINES += LINUX
        DEFINES += CCAUX
        DEFINES += TARGET_ARM_IMX8
        LIBS += -lcc-aux2
        LIB_PATH = /opt/crosscontrol/arm/imx8/lib
    }
}

HEADERS += \
    ../../CCAux/About.h \
    ../../CCAux/Adc.h \
    ../../CCAux/AuxVersion.h \
    ../../CCAux/Backlight.h \
    ../../CCAux/Battery.h \
    ../../CCAux/Buzzer.h \
    ../../CCAux/CCAuxErrors.h \
    ../../CCAux/CCAuxTypes.h \
    ../../CCAux/CCPlatform.h \
    ../../CCAux/CanSetting.h \
    ../../CCAux/CfgIn.h \
    ../../CCAux/Config.h \
    ../../CCAux/Diagnostic.h \
    ../../CCAux/DiagnosticCodes.h \
    ../../CCAux/DigIO.h \
    ../../CCAux/FirmwareUpgrade.h \
    ../../CCAux/Lightsensor.h \
    ../../CCAux/PWMOut.h \
    ../../CCAux/Power.h \
    ../../CCAux/PowerMgr.h \
    ../../CCAux/Smart.h \
    ../../CCAux/SoftKey.h \
    ../../CCAux/Telematics.h \
    ../../CCAux/TouchScreen.h \
    ../../CCAux/TouchScreenCalib.h \
    ../../CCAux/Video.h \
    backend/backend.h \
    backend/displayConfigHandler.h \
    backend/hwbutton.h \
    backend/ipaddress.h \
    backend/appstate.h \
    CCAux/BackLightHandler.h \
    CCAux/BuzzerHandler.h \
    CCAux/VersionHandler.h \
    CCAux/CCAuxHandlerBase.h \
    CCAux/PowerConfigHandler.h \
    backend/coolingtemperature.h \
    backend/remainingtime.h \
    backend/dataManager.h \
    backend/ptosettings.h \
    backend/preheating.h \
    backend/popupmanager.h \
    backend/popup.h \
    backend/dateTimeManager.h \
    backend/canwrapper.h \
    backend/canworkerthread.h \
    backend/can_handler3.h \
    backend/maintenancehistory.h \
    backend/mechanichistory.h \
    backend/errorinfo.h \
    backend/errormanager.h \
    backend/errordtc.h \
    backend/runprocess.h \
    backend/translation.h \
    backend/startupinfo.h


TRANSLATIONS = Linguist/fmc_hmi_en.ts \
               Linguist/fmc_hmi_fr.ts \
               Linguist/fmc_hmi_de.ts \
               Linguist/fmc_hmi_it.ts \
               Linguist/fmc_hmi_es.ts \
               Linguist/fmc_hmi_pt.ts \
               Linguist/fmc_hmi_fi.ts \
               Linguist/fmc_hmi_sv.ts \
               Linguist/fmc_hmi_nl.ts \
               Linguist/fmc_hmi_pl.ts \
               Linguist/fmc_hmi_da.ts



###### <LINX MANAGER> ######
CONFIG += c++11
isEmpty(LIB_PATH): LIBS += -lsapcore
else: LIBS += -L$$LIB_PATH -lsapcore
pct_confFile.files = ./FA_fmc_hmi.json
pct_confFile.path = $$target.path
DISTFILES += $$pct_confFile.files
INSTALLS += pct_confFile
HEADERS += DataEngine/dataengine.h \
	DataEngine/dataenginebase.h \
	DataEngine/dataenginesignal.h \
	DataEngine/qtobserver.h \
	DataEngine/fieldbusaccesserror.h \
	DataEngine/fieldbusaccesserrormodel.h
SOURCES += DataEngine/dataengine.cpp \
	DataEngine/dataenginebase.cpp \
	DataEngine/dataenginesignal.cpp \
	DataEngine/qtobserver.cpp \
	DataEngine/fieldbusaccesserror.cpp \
	DataEngine/fieldbusaccesserrormodel.cpp
###### </LINX MANAGER> ##########################

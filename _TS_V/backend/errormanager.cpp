#include "errormanager.h"

ErrorManager::ErrorManager(QObject *parent)
{
	setParent(parent);
	m_onCurrentErrorPage = false;
	m_socAlert = 0;
	loadDTC();
	loadHistory();
}

bool ErrorManager::loadDTC()
{
	//opens the JSON file which contains a list of all DTCs in order to load them into m_errorList
	QFile file( ":/dtc.json");

	if (!file.open(QIODevice::ReadOnly)) {
		qCritical() << "Unable to open dtc.json to load data";
		return false;
	}

	QByteArray jsonData = file.readAll();
	QJsonDocument docDTC = QJsonDocument::fromJson(jsonData);
	QJsonArray dtcArray = docDTC.array();
	file.close();

	int lineNumber = 0;
	for (const QJsonValue& value : dtcArray) {
		lineNumber++;
		QJsonObject line = value.toObject();
		if (!line.contains("DTC Code (Hex)")) {
			qWarning() << "DTC Code (Hex) is missing on line" << lineNumber;
			continue;
		}
		if (!line.contains("ID Text to display")) {
			qWarning() << "ID Text to display is missing on line" << lineNumber;
			continue;
		}
		if (!line.contains("ID Corrective action to display")) {
			qWarning() << "ID Corrective action to display is missing on line" << lineNumber;
			continue;
		}
		if (!line.contains("Pop-up display / ID icon Alarm")) {
			qWarning() << "Pop-up display / ID icon Alarm is missing on line" << lineNumber;
			continue;
		}
		if (!line.contains("ID Icon DTC")) {
			qWarning() << "ID Icon DTC is missing on line" << lineNumber;
			continue;
		}
		if (!line.contains("N buzzer blowing pattern")) {
			qWarning() << "N buzzer blowing pattern is missing on line" << lineNumber;
			continue;
		}
		ErrorDTC dtc(line);
		m_errorList[dtc.dtcCode.toStdString()] = dtc;
	}

	//add a DTC for the maintenance error
	ErrorDTC errorDTC;

	errorDTC.dtcCode = "MAINTENANCE";
	errorDTC.textToDisplayLabel = "LBL_0268";
	errorDTC.correctiveActionLabel = "LBL_0111";
	errorDTC.errorType = "Maintenance";
	errorDTC.dtcIconId = "";
	errorDTC.buzzerPattern = 5;

	m_errorList["MAINTENANCE"] = errorDTC;

	return true;
}

bool ErrorManager::loadHistory() {

	//opens the JSON file which contains a list of all DTCs that occurred in order to load them into m_historyError
	QFile file("/opt/fmc_hmi/history.json");
	//QFile file("/media/sf_shared_LinX/T-S-YANM0-23-502458_HMI_V7e/history.json"); // PC emulation
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
		qCritical("Unable to open history.json to load data.");
		return false;
	}
	QTextStream textStream(&file);

	for (int lineNumber = 1; !textStream.atEnd(); lineNumber++) {
		QString line = textStream.readLine();
		QJsonParseError parseError;
		QJsonDocument doc = QJsonDocument::fromJson(line.toUtf8(), &parseError);

		if (line.isEmpty ()) {
//			qDebug() << "line is empty --> continue";
			continue;
		}

		if (parseError.error != QJsonParseError::NoError) {
			qCritical() << "Invalid JSON format in history.json on line" << lineNumber << ":" << parseError.errorString();
			continue;
		}

		QJsonObject jsonObj = doc.object();
		if (!jsonObj.contains("dtcCode")) {
			qWarning() << "History file: missing 'dtcCode' field on line" << lineNumber;
			continue;
		}
		if (!jsonObj.contains("textToDisplayLabel")) {
			qWarning() << "History file: missing 'textToDisplayLabel' field on line" << lineNumber;
			continue;
		}
		if (!jsonObj.contains("correctiveActionLabel")) {
			qWarning() << "History file: missing 'correctiveActionLabel' field on line" << lineNumber;
			continue;
		}
		if (!jsonObj.contains("errorType")) {
			qWarning() << "History file: missing 'errorType' field on line" << lineNumber;
			continue;
		}
		if (!jsonObj.contains("dtcIconId")) {
			qWarning() << "History file: missing 'dtcIconId' field on line" << lineNumber;
			continue;
		}
		if (!jsonObj.contains("priority")) {
			qWarning() << "History file: missing 'priority' field on line" << lineNumber;
			continue;
		}
		if (!jsonObj.contains("creationDateTime")) {
			qWarning() << "History file: missing 'creationDateTime' field on line" << lineNumber;
			continue;
		}
		if (!jsonObj.contains("hourMeter")) {
			qWarning() << "History file: missing 'hourMeter' field on line" << lineNumber;
			continue;
		}

		ErrorInfo error(jsonObj);
		m_historyError.push_back(error);
	}
	file.close();

	sortErrorInfo(m_historyError);
	emit historyErrorLenghtChanged();
	return true;
}

void ErrorManager::sortErrorInfo(std::vector<ErrorInfo>& vector)
{
	std::sort(vector.begin(), vector.end(), [](const ErrorInfo a, const ErrorInfo b) {
		if (a.priority != b.priority)
			return a.priority < b.priority;
		else
			return a.hourMeter.toFloat() > b.hourMeter.toFloat();
	});
}

void ErrorManager::addError(const QString& errorCode, const QString& hourMeterValue)
{
	if (errorCode == "000000" || errorCode == "0" || errorCode == "00000000" || errorCode == "03000000" || errorCode == "000000" || errorCode == "47000000" || errorCode == "31000000" || errorCode == "4D000000" || errorCode == "87000000") {
		return;
	}

	//checks if errorCode is already in the current error vector. If true, reset the timeout timer for this error.
	for(size_t i = 0; i < m_currentError.size(); i++) {
		if (m_currentError[i].dtcCode == errorCode) {
			m_currentError[i].dtcTimeOut->start();
			m_currentError[i].buzzerTimeOut->start();
			return;
		}
	}
	//add a new error in the current error vector
	std::unordered_map<std::string, ErrorDTC>::const_iterator iterator = m_errorList.find(errorCode.toStdString());
	ErrorInfo error;

	if(iterator == m_errorList.end()) {
		 qWarning() << "DTC can't be treated because ID is not recognized:" << errorCode;
		 error.dtcCode = errorCode;
		 error.textToDisplayLabel = "LBL_0283";
		 error.correctiveActionLabel = "";
		 error.errorType = "Caution";
		 error.dtcIconId = "";
		 error.buzzerPattern = 5;
	} else {
		error.dtcCode = iterator->second.dtcCode;
		error.textToDisplayLabel = iterator->second.textToDisplayLabel;
		error.correctiveActionLabel = iterator->second.correctiveActionLabel;
		error.errorType = iterator->second.errorType;
		error.dtcIconId = iterator->second.dtcIconId;
		error.buzzerPattern = iterator->second.buzzerPattern;
	}
	error.hourMeter = hourMeterValue;
	error.creationDateTime = QDateTime::currentDateTime();
	error.beepsDone = false;
	error.buzzerIsInCoolDown = false;

	error.dtcTimeOut = new QTimer();  // When reached, destroy the DTC from current error list
	error.dtcTimeOut->setSingleShot(true);
	connect(error.dtcTimeOut, &QTimer::timeout, [=]() {
		if (ErrorManager::getOnCurrentErrorPage() == false) //if the user is on the current errors page, this error is not deleted
			ErrorManager::deleteCurrentError(error.dtcCode);
		else
			error.dtcTimeOut->start(1000);
	});
	if (error.dtcCode == "MAINTENANCE") {
		error.dtcTimeOut->start(2500);
	}
	else {
		// nach Ablaufen von dtcTimeOut wird ein inaktiver Fehler wieder ausgeblendet
//		error.dtcTimeOut->start(71000);
		error.dtcTimeOut->start(5000);
	}

	error.buzzerCooldown = new QTimer();
	error.buzzerCooldown->setInterval(58800);
	error.buzzerCooldown->setSingleShot(true);
	connect(error.buzzerCooldown, &QTimer::timeout, [=]() {
		ErrorManager::setBuzzerIsInCoolDown(error.dtcCode, false);
		ErrorManager::setBeepsDone(error.dtcCode, false);
	});
	error.buzzerCooldown->stop();
	error.buzzerTimeOut = new QTimer();
	error.buzzerTimeOut->setSingleShot(true);
	connect(error.buzzerTimeOut, &QTimer::timeout, [=]() {
		ErrorManager::setBuzzerIsInCoolDown(error.dtcCode, true);
		ErrorManager::startBuzzerCooldown(error.dtcCode);
	});
	error.buzzerTimeOut->start(11000); // 11s because it takes 10s to read all DTCs on the trame

	if (error.errorType == "Warning")
		error.priority = 1;
	else if (error.errorType == "Caution")
		error.priority = 2;
	else if (error.errorType == "Maintenance")
		error.priority = 3;
	else {
		qWarning() << "errorType is not recognized (set to 3 by default) : " << error.errorType;
		error.priority = 3;
	}

	m_currentError.push_back(error);
	sortErrorInfo(m_currentError);
	emit currentErrorLenghtChanged();

	QVariantMap popupToDisplay;
	popupToDisplay["dtcCode"] = error.dtcCode;
	popupToDisplay["textToDisplayLabel"] = error.textToDisplayLabel;
	if (error.dtcCode == "MAINTENANCE")
		popupToDisplay["buzzerPattern"] = 0;
	else
		popupToDisplay["buzzerPattern"] = error.buzzerPattern;
	popupToDisplay["priority"] = error.priority;
	emit newErrorPop(popupToDisplay);

	addErrorToHistory(error);
}

QVariantMap ErrorManager::getCurrentErrorAt(int index)
{
	QVariantMap result;

	if (index >= getCurrentErrorLength() || index < 0)
		return result;

	try {
		ErrorInfo error = m_currentError.at(index);
		result["dtcCode"] = error.dtcCode;
		result["textToDisplayLabel"] = error.textToDisplayLabel;
		result["correctiveActionLabel"] = error.correctiveActionLabel;
		result["errorType"] = error.errorType;
		result["dtcIconId"] = error.dtcIconId;
		result["buzzerPattern"] = error.buzzerPattern;
		result["priority"] = error.priority;
		result["creationDateTime"] = error.creationDateTime;
		result["hourMeter"] = error.hourMeter;
	} catch (const std::out_of_range& e) {
		qWarning() << "no values found in current_error vector at index: " << index << " details: " << e.what();
	}

	return (result);
}

void ErrorManager::deleteCurrentError(const QString& dtcErrorCode)
{
	for(size_t i = 0; i < m_currentError.size(); i++) {
		if (m_currentError[i].dtcCode == dtcErrorCode) {
			m_currentError[i].dtcTimeOut->stop();
			m_currentError[i].buzzerTimeOut->stop();
			m_currentError[i].buzzerCooldown->stop();
			// add current error to error history page
			if (m_currentError[i].dtcCode != "MAINTENANCE") {
				m_historyError.push_back(m_currentError[i]);
				sortErrorInfo(m_historyError);
				emit historyErrorLenghtChanged();
			}
			delete m_currentError[i].dtcTimeOut;
			delete m_currentError[i].buzzerTimeOut;
			delete m_currentError[i].buzzerCooldown;
			m_currentError.erase(m_currentError.begin() + i);
			emit currentErrorLenghtChanged();
			return;
		}
	}
	 qWarning() << "Error cannot be deleted because code invalid: " << dtcErrorCode;
}

int ErrorManager::getCurrentErrorLength()
{
	return (m_currentError.size());
}

int ErrorManager::getHistoryErrorLength()
{
	return (m_historyError.size());
}

QVariantMap ErrorManager::getHistoryErrorAt(int index)
{
	QVariantMap result;

	if (index >= getHistoryErrorLength() || index < 0)
		return result;
	try {
		ErrorInfo error = m_historyError.at(index);
		result["dtcCode"] = error.dtcCode;
		result["textToDisplayLabel"] = error.textToDisplayLabel;
		result["correctiveActionLabel"] = error.correctiveActionLabel;
		result["errorType"] = error.errorType;
		result["dtcIconId"] = error.dtcIconId;
		result["buzzerPattern"] = 6;
		result["priority"] = error.priority;
		result["creationDateTime"] = error.creationDateTime;
		result["hourMeter"] = error.hourMeter;
	} catch (const std::out_of_range& e) {
		qDebug() << "no values found in history_error vector at index: " << index << " details: " << e.what();
	}

	return (result);
}

bool ErrorManager::addErrorToHistory(const ErrorInfo& errorInfo)
{
	if (errorInfo.dtcCode == "MAINTENANCE")
		return (false);

	QFile historyFile("/opt/fmc_hmi/history.json");
	//QFile historyFile("/media/sf_shared_LinX/T-S-YANM0-23-502458_HMI_V7e/history.json"); // PC emulation

	if (!historyFile.open(QIODevice::Append | QIODevice::Text)) {
		qCritical("cannot open history.json for write.");
		return (false);
	}
	QJsonObject errorObject;
	errorObject["dtcCode"] = errorInfo.dtcCode;
	errorObject["textToDisplayLabel"] = errorInfo.textToDisplayLabel;
	errorObject["correctiveActionLabel"] = errorInfo.correctiveActionLabel;
	errorObject["errorType"] = errorInfo.errorType;
	errorObject["dtcIconId"] = errorInfo.dtcIconId;
	errorObject["priority"] = errorInfo.priority;
	errorObject["creationDateTime"] = errorInfo.creationDateTime.toString(Qt::ISODate);
	errorObject["hourMeter"] = errorInfo.hourMeter;

	QJsonDocument doc(errorObject);
	QString dtcJson = doc.toJson(QJsonDocument::Compact);
	QTextStream out(&historyFile);

	out << "\n" << dtcJson << "\n";
	historyFile.close();
	return (true);
}

bool ErrorManager::getOnCurrentErrorPage()
{
	return (m_onCurrentErrorPage);
}

void ErrorManager::setOnCurrentErrorPage(bool value)
{
	m_onCurrentErrorPage = value;
}

QVariantMap ErrorManager::getBuzzerPattern()
{
	QVariantMap buzzerinfo;
	buzzerinfo["buzzPattern"] = 0;
	buzzerinfo["code"] = "NONE";

	// Check if a current DTC should trigger the buzzer
	for (size_t i = 0; i < m_currentError.size(); i++) {
		if (m_currentError[i].buzzerPattern >= 3 && m_currentError[i].beepsDone == true)
			continue;
		else if (m_currentError[i].buzzerTimeOut->isActive() == true && m_currentError[i].buzzerIsInCoolDown == false) {
			buzzerinfo["buzzPattern"] = m_currentError[i].buzzerPattern;
			buzzerinfo["code"] = m_currentError[i].dtcCode;
			break;
		}
	}

	// check if there is a low battery alert that should trigger the buzz
	if (m_socAlert != 0)
		if (m_socAlert < buzzerinfo.value("buzzPattern").toInt() || buzzerinfo.value("buzzPattern").toInt() == 0) {
			buzzerinfo["buzzPattern"] = m_socAlert;
			buzzerinfo["code"] = "SOC" + m_socAlert;
	}
	return buzzerinfo;
}

void ErrorManager::setSocAlert(int value) {
	if (m_socAlert != value) {
		m_socAlert = value;
		emit socAlertChanged();
	}
}

void ErrorManager::startBuzzerCooldown(QString code) {
	for(size_t i = 0; i < m_currentError.size(); i++)
		if (m_currentError[i].dtcCode == code)
			m_currentError[i].buzzerCooldown->start();
}

void ErrorManager::setBuzzerIsInCoolDown(QString code, bool value)
{
	for(size_t i = 0; i < m_currentError.size(); i++)
		if (m_currentError[i].dtcCode == code)
			m_currentError[i].buzzerIsInCoolDown = value;
}

void ErrorManager::setBeepsDone(QString code, bool value) {
	for(size_t i = 0; i < m_currentError.size(); i++)
		if (m_currentError[i].dtcCode == code)
			m_currentError[i].beepsDone = value;
}

#include "remainingtime.h"

RemainingTime::RemainingTime(QObject *parent) : QObject(parent), m_rtMCU(0.0)
{

}

/* SETTERS */
void RemainingTime::setRtMCU(float rtMCU)
{
//    qDebug() << "Setting the remaining time of the MCU";
	if (qFuzzyCompare(m_rtMCU, rtMCU)) {
		return;
	}

	m_rtMCU = rtMCU;

//    qDebug() << "Remaining time of the MCU changed!";
	calculateRt(m_rtMCU);
}

void RemainingTime::setRemainingTimeCpp(QString remainingTimeCpp)
{
//    qDebug() << "Setting the remaining time";
	if (m_remainingTimeCpp == remainingTimeCpp)
		return;

	m_remainingTimeCpp = remainingTimeCpp;
	emit remainingTimeCppChanged(m_remainingTimeCpp);
}

void RemainingTime::setPercentageSOCCpp(QString percentageSOCCpp)
{
//    qDebug() << "Setting the percentage of SOC";
	if (m_percentageSOCCpp == percentageSOCCpp)
		return;

	m_percentageSOCCpp = percentageSOCCpp;
	emit percentageSOCChangedCpp(m_percentageSOCCpp);
}

/* GETTERS */
float RemainingTime::getRtMCU() const
{
//    qDebug() << "Getting the remaining time of the MCU";
	return m_rtMCU;
}

QString RemainingTime::getRemainingTimeCpp() const
{
//    qDebug() << "Getting the remaining time";
	return m_remainingTimeCpp;
}

QString RemainingTime::getPercentageSOCCpp() const
{
//    qDebug() << "Getting the percentage of SOC";
	return m_percentageSOCCpp;
}

/* CALCULATIONS */
void RemainingTime::calculateRt(float rtMCU)
{
	setRemainingTimeCpp(calculateRemainingTime(rtMCU));
	setPercentageSOCCpp(calculatePercentageSOC(rtMCU));
}

QString RemainingTime::calculateRemainingTime(float rtMCU)
{
	QString resValue = "-.-h";

	// Max limit in case of MCU error
	if (rtMCU > rt_max) {
		return "0h00";
	}
	// Min limit in case of MCU error
	if (rtMCU < rt_min) {
		return "0h00";
	}

	// When the remaining time is HIGHER than 10 mins...
	if (rtMCU > rt_10m)
	{
		// Integral part : hours in terms of hours
		int rt_hours = floor(rtMCU); //qDebug() << rt_hours;

		// Decimal part : minutes in terms of hours and minutes
		float rt_minutesInHours = rtMCU - (float)rt_hours; //qDebug() << rt_minutesInHours;
		//float rt_minutesVal = rt_minutesInHours * 60.0; //qDebug() << rt_minutesVal;
		int rt_minutes = round(rt_minutesInHours * 60.0); //qDebug() << rt_minutes;

		int mod = rt_minutes % 10; //qDebug() << mod;
		if (mod >= 5) {
			rt_minutes += (10 - mod);
		}
		else if (mod > 0) {
			rt_minutes -= mod;
		}

		// Transition to next hour
		if (rt_minutes >= 55) {
			rt_hours += 1;
			rt_minutes = 0;
		}
		//qDebug() << rt_minutes;

		resValue = QString::number(rt_hours) + 'h' + QString::number(rt_minutes);
	}

	//qDebug() << resValue;
	return resValue;
}

QString RemainingTime::calculatePercentageSOC(float rtMCU)
{
	int rt_rate;
	QString resRate = "0%";

	// Max limit in case of MCU error
	if (rtMCU > rt_max) {
		rtMCU = rt_max;
	}
	// Min limit in case of MCU error
	if (rtMCU < rt_min) {
		rtMCU = rt_min;
	}

	// When the remaining time is HIGHER than 10 mins...
	if (rtMCU > rt_min)
	{
		rt_rate = round(100 * ((rtMCU - rt_min) / (rt_max - rt_min)));
		resRate = QString::number(rt_rate) + '%';
	}

	//qDebug() << resRate;
	return resRate;
}

#ifndef REMAININGTIME_H
#define REMAININGTIME_H

#include <QObject>
#include <QTimer>
#include <QDebug>
#include <QString>

#include <iostream>
#include <cmath>
using namespace std;


class RemainingTime : public QObject
{
    Q_OBJECT
    Q_PROPERTY(float rtMCU READ getRtMCU WRITE setRtMCU)
    Q_PROPERTY(QString remainingTimeCpp READ getRemainingTimeCpp WRITE setRemainingTimeCpp NOTIFY remainingTimeCppChanged)
    Q_PROPERTY(QString percentageSOCCpp READ getPercentageSOCCpp WRITE setPercentageSOCCpp NOTIFY percentageSOCChangedCpp)


public:
    explicit RemainingTime(QObject *parent = nullptr);

    void setRtMCU(float rtMCU);
    void setRemainingTimeCpp(QString remainingTimeCpp);
    void setPercentageSOCCpp(QString percentageSOCCpp);

    float getRtMCU() const;
    QString getRemainingTimeCpp() const;
    QString getPercentageSOCCpp() const;

signals:
    //void rtMCUChanged(float rtMCU);
    void remainingTimeCppChanged(QString remainingTimeCpp);
    void percentageSOCChangedCpp(QString percentageSOCCpp);

    void rtResult(QString hour, QString min1, QString min0, QString rate2, QString rate1, QString rate0);

public slots:
    //void calculateRt(float rtMCU);

private:
    float m_rtMCU;
    QString m_remainingTimeCpp;
    QString m_percentageSOCCpp;

    const float rt_10m = 1.0/6.0;
    const float rt_50m = 5.0/6.0;
    const float rt_55m = 5.0/6.0;
    const float rt_min = 0.0;
    const float rt_max = 23.0 + 9.0/10.0;

    void calculateRt(float rtMCU);
    QString calculateRemainingTime(float rtMCU);
    QString calculatePercentageSOC(float rtMCU);
//    int* calculateRemainingTime(float rtMCU);
//    int* calculatePercentageSOC(float rtMCU);
};

#endif // REMAININGTIME_H

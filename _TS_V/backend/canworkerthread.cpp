// Copyright 2012 CrossControl
#include<QDebug>
#include "canworkerthread.h"

#include "canwrapper.h"


#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <sys/uio.h>
#include <net/if.h>
#include <linux/can.h>
#include <linux/can/raw.h>

#include <signal.h>

#include <assert.h>

#include <errno.h>

#include <fcntl.h>

#include <stdio.h>

#include <sys/time.h>

CanWorkerThread::CanWorkerThread(QObject *parent) :
	QThread(parent)
{
}

// Setup worker thread
// Parameter:
// wrapper - pointer to CAN wrapper instance
void CanWorkerThread::Init(CanWrapper *wrapper)
{
	m_running = true;
	m_can = wrapper;
	m_error = false;
	m_errorCode = 0; // no error

	struct timespec currentTime;
	clock_gettime(CLOCK_MONOTONIC, &currentTime);


	CanFrameTimestamp expectedFrame;
	expectedFrame.ID = 419361095; // 0x18FEF147 instant, CCVS; kontrolliert 10.6.24
	expectedFrame.timestamp = currentTime;
	expectedFrame.timeout.tv_sec = 0;
	expectedFrame.timeout.tv_nsec = 250000000; // 5 periods
	expectedFrame.timeoutError = false;
	m_expectedFrames.push_back(expectedFrame);

	expectedFrame.ID = 419414087; // 0x18FFC047 100ms; _FMC_IndicatorLights01; kontrolliert 10.6.24
	expectedFrame.timestamp = currentTime;
	expectedFrame.timeout.tv_sec = 0;
	expectedFrame.timeout.tv_nsec = 500000000; // 5 periods
	expectedFrame.timeoutError = false;
	m_expectedFrames.push_back(expectedFrame);

	expectedFrame.ID = 419414343; // 0x18FFC147 100ms; _FMC_IndicatorLights02; kontrolliert 10.6.24
	expectedFrame.timestamp = currentTime;
	expectedFrame.timeout.tv_sec = 0;
	expectedFrame.timeout.tv_nsec = 500000000; // 5 periods
	expectedFrame.timeoutError = false;
	m_expectedFrames.push_back(expectedFrame);

	expectedFrame.ID = 419415111; // 0x18FFC447 100ms; _FMC_IndicatorLights05_Electric; kontrolliert 10.6.24
	expectedFrame.timestamp = currentTime;
	expectedFrame.timeout.tv_sec = 0;
	expectedFrame.timeout.tv_nsec = 500000000; // 5 periods
	expectedFrame.timeoutError = false;
	m_expectedFrames.push_back(expectedFrame);

	expectedFrame.ID = 419416903; // 0x18FFCB47 1s; _FMC_IndicatedValues05_Electric
	expectedFrame.timestamp = currentTime;
	expectedFrame.timeout.tv_sec = 5;
	expectedFrame.timeout.tv_nsec = 0; // 5 periods
	expectedFrame.timeoutError = false;
	m_expectedFrames.push_back(expectedFrame);

	expectedFrame.ID = 419417159; // 0x18FFCC47 100ms; _FMC_IndicatedValues04_Diesel
	expectedFrame.timestamp = currentTime;
	expectedFrame.timeout.tv_sec = 0;
	expectedFrame.timeout.tv_nsec = 500000000; // 5 periods
	expectedFrame.timeoutError = false;
	m_expectedFrames.push_back(expectedFrame);

	expectedFrame.ID = 419417671; // 0x18FFCE47 1s; _FMC_IndicatedValues02
	expectedFrame.timestamp = currentTime;
	expectedFrame.timeout.tv_sec = 5;
	expectedFrame.timeout.tv_nsec = 0; // 5 periods
	expectedFrame.timeoutError = false;
	m_expectedFrames.push_back(expectedFrame);

	expectedFrame.ID = 419417927; // 0x18FFCF47 100ms, _FMC_IndicatedValues01
	expectedFrame.timestamp = currentTime;
	expectedFrame.timeout.tv_sec = 0;
	expectedFrame.timeout.tv_nsec = 500000000; // 5 periods
	expectedFrame.timeoutError = false;
	m_expectedFrames.push_back(expectedFrame);

	expectedFrame.ID = 419358535; // 0x18FEE747 1s, _FMC_MachineOperatingHours
	expectedFrame.timestamp = currentTime;
	expectedFrame.timeout.tv_sec = 5;
	expectedFrame.timeout.tv_nsec = 0; // 5 periods
	expectedFrame.timeoutError = false;
	m_expectedFrames.push_back(expectedFrame);

	expectedFrame.ID = 419422279; // 0x18FFE047 10s, _FMC_OperatingHours01
	expectedFrame.timestamp = currentTime;
	expectedFrame.timeout.tv_sec = 20;
	expectedFrame.timeout.tv_nsec = 0; // 5 periods
	expectedFrame.timeoutError = false;
	m_expectedFrames.push_back(expectedFrame);

	expectedFrame.ID = 419414855; // 0x18FFC347 100ms, _FMC_IndicatorLights04_Diesel
	expectedFrame.timestamp = currentTime;
	expectedFrame.timeout.tv_sec = 0;
	expectedFrame.timeout.tv_nsec = 500000000; // 5 periods
	expectedFrame.timeoutError = false;
	m_expectedFrames.push_back(expectedFrame);

	expectedFrame.ID = 419419975; // 0x18FFD747 no cycle, MaschineProperties
	expectedFrame.timestamp = currentTime;
	expectedFrame.timeout.tv_sec = 5;
	expectedFrame.timeout.tv_nsec = 0; // 5 periods
	expectedFrame.timeoutError = false;
	m_expectedFrames.push_back(expectedFrame);

	expectedFrame.ID = 419409479; // 0x18FFAE47 100ms, _FMC_VisibleElements02
	expectedFrame.timestamp = currentTime;
	expectedFrame.timeout.tv_sec = 0;
	expectedFrame.timeout.tv_nsec = 500000000; // 5 periods
	expectedFrame.timeoutError = false;
	m_expectedFrames.push_back(expectedFrame);

	expectedFrame.ID = 419409735; // 0x18FFAF47 100ms, _FMC_VisibleElements01
	expectedFrame.timestamp = currentTime;
	expectedFrame.timeout.tv_sec = 0;
	expectedFrame.timeout.tv_nsec = 500000000; // 5 periods
	expectedFrame.timeoutError = false;
	m_expectedFrames.push_back(expectedFrame);

	expectedFrame.ID = 419354929; // 0x18FED931 500ms
	expectedFrame.timestamp = currentTime;
	expectedFrame.timeout.tv_sec = 2;
	expectedFrame.timeout.tv_nsec = 500000000; // 5 periods
	expectedFrame.timeoutError = false;
	m_expectedFrames.push_back(expectedFrame);

	expectedFrame.ID = 419375875; // 0x18FF2B03 100ms, ZFETC13
	expectedFrame.timestamp = currentTime;
	expectedFrame.timeout.tv_sec = 0;
	expectedFrame.timeout.tv_nsec = 500000000; // 5 periods
	expectedFrame.timeoutError = false;
	m_expectedFrames.push_back(expectedFrame);

	expectedFrame.ID = 218067271; // 0xCFF7147 10ms, ZFSFS1
	expectedFrame.timestamp = currentTime;
	expectedFrame.timeout.tv_sec = 0;
	expectedFrame.timeout.tv_nsec = 50000000; // 5 periods
	expectedFrame.timeoutError = false;
	m_expectedFrames.push_back(expectedFrame);

	expectedFrame.ID = 217126023; // 0xCF11487 100ms, DCDC1VC
	expectedFrame.timestamp = currentTime;
	expectedFrame.timeout.tv_sec = 0;
	expectedFrame.timeout.tv_nsec = 500000000; // 5 periods
	expectedFrame.timeoutError = false;
	m_expectedFrames.push_back(expectedFrame);

	expectedFrame.ID = 419355139; // 0x18FEDA03 100ms, SOFT TCU
	expectedFrame.timestamp = currentTime;
	expectedFrame.timeout.tv_sec = 0;
	expectedFrame.timeout.tv_nsec = 500000000; // 5 periods
	expectedFrame.timeoutError = false;
	m_expectedFrames.push_back(expectedFrame);

	expectedFrame.ID = 419355207; // 0x18FEDA47 100ms, SOFT MCU
	expectedFrame.timestamp = currentTime;
	expectedFrame.timeout.tv_sec = 0;
	expectedFrame.timeout.tv_nsec = 500000000; // 5 periods
	expectedFrame.timeoutError = false;
	m_expectedFrames.push_back(expectedFrame);

	expectedFrame.ID = 419362560; // 0x18FEF700 1000ms, VEP
	expectedFrame.timestamp = currentTime;
	expectedFrame.timeout.tv_sec = 5;
	expectedFrame.timeout.tv_nsec = 0; // 5 periods
	expectedFrame.timeoutError = false;
	m_expectedFrames.push_back(expectedFrame);

	expectedFrame.ID = 419369216; // 0x18FF1100 100ms, Y_IOS
	expectedFrame.timestamp = currentTime;
	expectedFrame.timeout.tv_sec = 0;
	expectedFrame.timeout.tv_nsec = 500000000; // 5 periods
	expectedFrame.timeoutError = false;
	m_expectedFrames.push_back(expectedFrame);

	expectedFrame.ID = 217056256; // 0xCF00400 100ms, EEC1
	expectedFrame.timestamp = currentTime;
	expectedFrame.timeout.tv_sec = 0;
	expectedFrame.timeout.tv_nsec = 500000000; // 5 periods
	expectedFrame.timeoutError = false;
	m_expectedFrames.push_back(expectedFrame);

	expectedFrame.ID = 419361280; // 0x18FEF200 100ms, LFE1
	expectedFrame.timestamp = currentTime;
	expectedFrame.timeout.tv_sec = 0;
	expectedFrame.timeout.tv_nsec = 500000000; // 5 periods
	expectedFrame.timeoutError = false;
	m_expectedFrames.push_back(expectedFrame);

	expectedFrame.ID = 419374083; // 0x18FF2403 100ms, DRV4 von BR-TCU
	expectedFrame.timestamp = currentTime;
	expectedFrame.timeout.tv_sec = 0;
	expectedFrame.timeout.tv_nsec = 500000000; // 5 periods
	expectedFrame.timeoutError = false;
	m_expectedFrames.push_back(expectedFrame);

	expectedFrame.ID = 217056000; // 0xCF00300 100ms, EEC2
	expectedFrame.timestamp = currentTime;
	expectedFrame.timeout.tv_sec = 0;
	expectedFrame.timeout.tv_nsec = 500000000; // 5 periods
	expectedFrame.timeoutError = false;
	m_expectedFrames.push_back(expectedFrame);

	expectedFrame.ID = 435163179; // 0x19F0102B 1s SAR
	expectedFrame.timestamp = currentTime;
	expectedFrame.timeout.tv_sec = 5;
	expectedFrame.timeout.tv_nsec = 0; // 5 periods
	expectedFrame.timeoutError = false;
	m_expectedFrames.push_back(expectedFrame);

	expectedFrame.ID = 419398727; // 0x18FF8447 100ms immob ctrl
	expectedFrame.timestamp = currentTime;
	expectedFrame.timeout.tv_sec = 0;
	expectedFrame.timeout.tv_nsec = 500000000; // 5 periods
	expectedFrame.timeoutError = false;
	m_expectedFrames.push_back(expectedFrame);

	expectedFrame.ID = 419355392; // 0x18FEDB00 500ms, EFLP2
	expectedFrame.timestamp = currentTime;
	expectedFrame.timeout.tv_sec = 2;
	expectedFrame.timeout.tv_nsec = 500000000; // 5 periods
	expectedFrame.timeoutError = false;
	m_expectedFrames.push_back(expectedFrame);

	expectedFrame.ID = 419374851; // 0x18FF2703 100ms Snsr1: Druck MA MB
	expectedFrame.timestamp = currentTime;
	expectedFrame.timeout.tv_sec = 0;
	expectedFrame.timeout.tv_nsec = 500000000; // 5 periods
	expectedFrame.timeoutError = false;
	m_expectedFrames.push_back(expectedFrame);

	expectedFrame.ID = 419417415; // 0x18FFCD47 100ms ; wird noch nicht verarbeitet
	expectedFrame.timestamp = currentTime;
	expectedFrame.timeout.tv_sec = 0;
	expectedFrame.timeout.tv_nsec = 500000000; // 5 periods
	expectedFrame.timeoutError = false;
	m_expectedFrames.push_back(expectedFrame);

	expectedFrame.ID = 419422535; // 0x18FFE147 1s, _FMC_OperatingHours02
	expectedFrame.timestamp = currentTime;
	expectedFrame.timeout.tv_sec = 5;
	expectedFrame.timeout.tv_nsec = 0; // 5 periods
	expectedFrame.timeoutError = false;
	m_expectedFrames.push_back(expectedFrame);

	expectedFrame.ID = 419422791; // 0x18FFE247 1s, _FMC_OperatingHours03
	expectedFrame.timestamp = currentTime;
	expectedFrame.timeout.tv_sec = 5;
	expectedFrame.timeout.tv_nsec = 0; // 5 periods
	expectedFrame.timeoutError = false;
	m_expectedFrames.push_back(expectedFrame);

	expectedFrame.ID = 419423047; // 0x18FFE347 1s, _FMC_OperatingHours04_Diesel
	expectedFrame.timestamp = currentTime;
	expectedFrame.timeout.tv_sec = 5;
	expectedFrame.timeout.tv_nsec = 0; // 5 periods
	expectedFrame.timeoutError = false;
	m_expectedFrames.push_back(expectedFrame);

	expectedFrame.ID = 413608007; // 0x18A72847 100ms Buttons and IO Ctrl
	expectedFrame.timestamp = currentTime;
	expectedFrame.timeout.tv_sec = 0;
	expectedFrame.timeout.tv_nsec = 500000000; // 5 periods
	expectedFrame.timeoutError = false;
	m_expectedFrames.push_back(expectedFrame);
}

// This function will be excuted in an own thread when start is called from parent thread
// It will wait for data from CAN (blocking) and signal to GUI when data arrives
void CanWorkerThread::run()
{
	struct can_frame msg;
	int ret;
	int i;
	int errorCode;

	bool rtr;
	bool extended;
	bool error;

	struct timespec currentTime;
	struct timeval tv;

	tv.tv_sec = 1;
	tv.tv_usec = 0;

	while(m_running)
	{
		clock_gettime(CLOCK_MONOTONIC, &currentTime);

		// This call will block but only for one sec to let us abort if m_running = false
		// errorCode is errors related to socket problems, error is can related problems like bus-off
		ret = m_can->GetMsg(msg, extended, rtr, error, errorCode, tv);

		if(ret)
		{
			QString string;

			if(error)   // Error frame
			{
				string = QString("Error frame received, class = " +  QString::number(msg.can_id));
			}
			else
			if(extended)   // Extended frame
			{
				for(size_t i = 0; i < m_expectedFrames.size(); i++) {
					if (m_expectedFrames[i].ID == msg.can_id) {
						m_expectedFrames[i].timestamp = currentTime;
						m_expectedFrames[i].timeoutError = false;
					}
				}

				if(rtr)
				{
					string = QString("RTR ID: %1 LENGTH: %2").arg(msg.can_id).arg(msg.can_dlc);
				}
				else
				{
					string = QString("ID: %1 LENGTH: %2 DATA: ").arg(msg.can_id).arg(msg.can_dlc);

					ID = msg.can_id;
					Data_0 = msg.data[0];
					Data_1 = msg.data[1];
					Data_2 = msg.data[2];
					Data_3 = msg.data[3];
					Data_4 = msg.data[4];
					Data_5 = msg.data[5];
					Data_6 = msg.data[6];
					Data_7 = msg.data[7];

					for(i = 0; i < msg.can_dlc; i++)
					{
						string.append(QString::number(msg.data[i]) + " ");
					}
				}
			}
			else    // Standard frame
			{
				if(rtr)
				{
					string = QString("RTR ID: %1 LENGTH: %2").arg(msg.can_id).arg(msg.can_dlc);
				}
				else
				{
					string = QString("ID: %1 LENGTH: %2 DATA: ").arg(msg.can_id).arg(msg.can_dlc);

					ID = msg.can_id;
					Data_0 = msg.data[0];
					Data_1 = msg.data[1];
					Data_2 = msg.data[2];
					Data_3 = msg.data[3];
					Data_4 = msg.data[4];
					Data_5 = msg.data[5];
					Data_6 = msg.data[6];
					Data_7 = msg.data[7];

					for(i = 0; i < msg.can_dlc; i++)
					{
						string.append(QString::number(msg.data[i]) + " ");
					}
				}
			 }

			// Send string to GUI
			// Because this is an own thread, we must emit a signal rater than making a direct call
			// Because we are in a different thread than the GUI thread, this will put the data onto a queue
			// And will be processed by the GUI thread
			emit msgReceived(ID, Data_0, Data_1, Data_2, Data_3, Data_4, Data_5, Data_6, Data_7);

		}
//        else
//        {
//            if(errorCode)
//            {
//                QString string = QString("Error detected, errorcode: " + QString::number(errorCode));

//                //emit msgReceived(string);
//            }
//        }

		clock_gettime(CLOCK_MONOTONIC, &currentTime);
		timespec delay;
		for(size_t i = 0; i < m_expectedFrames.size(); i++) {
			 delay = diff_timespec(&currentTime, &m_expectedFrames[i].timestamp);
			 if (delay.tv_sec == m_expectedFrames[i].timeout.tv_sec)
			 {
				 if(delay.tv_nsec > m_expectedFrames[i].timeout.tv_nsec)
				 {
					 //error
					 //qDebug() << "ID: " << m_expectedFrames[i].ID << ", error : ";
					 m_expectedFrames[i].timeoutError = true;
				 }
			 }
			 else
			 {
				 if(delay.tv_sec > m_expectedFrames[i].timeout.tv_sec)
				 {
					 //error
					 //qDebug() << "ID: " << m_expectedFrames[i].ID << ", error : ";
					 m_expectedFrames[i].timeoutError = true;
				 }
			 }

		}

		m_error = error;
		m_errorCode = errorCode;
	}
}


struct timespec CanWorkerThread::diff_timespec( const struct timespec *time1,
												const struct timespec *time0) {

  struct timespec diff = {.tv_sec = time1->tv_sec - time0->tv_sec, //
	  .tv_nsec = time1->tv_nsec - time0->tv_nsec};
  if (diff.tv_nsec < 0) {
	diff.tv_nsec += 1000000000; // nsec/sec
	diff.tv_sec--;
  }

  return diff;
}

// Make thread to stop. Because the thread might be waiting on a blocking call, the call must be unblocked first to actually make the
// thread stop
void CanWorkerThread::shutDown()
{
	m_running = false;
}

QVariantMap CanWorkerThread::getCanWorkerTimeoutError()
{
	QVariantMap map_timeoutError;

	for(size_t i = 0; i < m_expectedFrames.size(); i++) {
		QString stringID = QString::number(m_expectedFrames[i].ID);
		map_timeoutError[stringID] = m_expectedFrames[i].timeoutError;
	}

	return map_timeoutError;
}

bool CanWorkerThread::getCanWorkerError()
{
	return m_error;
}

int CanWorkerThread::getCanWorkerErrorCode()
{
	return m_errorCode;
}

void CanWorkerThread::sendMsg(int ID, int Data_0, int Data_1, int Data_2, int Data_3, int Data_4, int Data_5, int Data_6, int Data_7)
{
	struct can_frame send_can_msg;
	//ID_uchar = ID;
	send_can_msg.can_id = ID;
	send_can_msg.can_dlc = 8;

	//Data_0_uchar = Data_0;
	send_can_msg.data[0] = Data_0;
	send_can_msg.data[1] = Data_1;
	send_can_msg.data[2] = Data_2;
	send_can_msg.data[3] = Data_3;
	send_can_msg.data[4] = Data_4;
	send_can_msg.data[5] = Data_5;
	send_can_msg.data[6] = Data_6;
	send_can_msg.data[7] = Data_7;
	int test;
	bool message_sent = m_can->SendMsg(send_can_msg, true, false, test);
	//qDebug() << send_can_msg.can_id << send_can_msg.data[0];
	//qDebug() << "CAN handler send error: " << test;

}

// Copyright 2012 CrossControl

#ifndef CANWORKERTHREAD_H
#define CANWORKERTHREAD_H

#include <QThread>
#include <QVariantMap>

#include "canwrapper.h"
#include <linux/types.h>
#include <map>

class CanWorkerThread : public QThread
{
    Q_OBJECT
public:
    explicit CanWorkerThread(QObject *parent = 0);

    void Init(CanWrapper *wrapper); // Initialize

    void run();         // start thread

    void shutDown();    // Make thread shut down

    struct timespec diff_timespec( const struct timespec *time1, const struct timespec *time0);

    QVariantMap getCanWorkerTimeoutError();

    bool getCanWorkerError();

    int getCanWorkerErrorCode();

signals:
    void msgReceived(int ID, int Data_0, int Data_1, int Data_2, int Data_3, int Data_4, int Data_5, int Data_6, int Data_7);

public slots:
    void sendMsg (int ID, int Data_0, int Data_1, int Data_2, int Data_3, int Data_4, int Data_5, int Data_6, int Data_7);

private:
    CanWrapper *m_can;  // Pointer to can wrapper class

    bool m_running;     // Set to false to stop thread

    bool m_error;

    int m_errorCode;

    int ID;
    int Data_0;
    int Data_1;
    int Data_2;
    int Data_3;
    int Data_4;
    int Data_5;
    int Data_6;
    int Data_7;

    unsigned char ID_uchar;
    unsigned char Data_0_uchar;
    unsigned char Data_1_uchar;
    unsigned char Data_2_uchar;
    unsigned char Data_3_uchar;
    unsigned char Data_4_uchar;
    unsigned char Data_5_uchar;
    unsigned char Data_6_uchar;
    unsigned char Data_7_uchar;

    struct CanFrameTimestamp
    {
       uint32_t ID; // ID of the CAN frame
       timespec timestamp; // timestamp of the last received frame
       timespec timeout; // authorized duration without receiving the frame, after that an error is raised
       bool timeoutError; // true if the frame is not received before timeout
    };

    std::vector<CanFrameTimestamp> m_expectedFrames;

    struct find_id : std::unary_function<CanFrameTimestamp, bool> {
        uint32_t ID;
        find_id(uint32_t ID):ID(ID) { }
        bool operator()(CanFrameTimestamp const& m) const {
            return m.ID == ID;
        }
    };
};

#endif // CANWORKERTHREAD_H

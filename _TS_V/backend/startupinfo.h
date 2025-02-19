#ifndef STARTUPINFO_H
#define STARTUPINFO_H

#include <QObject>

class StartupInfo : public QObject
{
    Q_OBJECT
public:
    bool m_manualStartMode = false;

    Q_INVOKABLE bool isManualStartMode() const
    {
        return m_manualStartMode;
    }

    Q_INVOKABLE bool setManualStartMode(bool value)
    {
        if(value != m_manualStartMode)
        {
            m_manualStartMode = value;
        }
    }
};

#endif // STARTUPINFO_H

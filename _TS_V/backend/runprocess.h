#ifndef RUNPROCESS_H
#define RUNPROCESS_H

#include <QProcess>
#include <QVariant>

using namespace std;

class RunProcess : public QObject
{
    Q_OBJECT
public:
    explicit RunProcess(QObject *parent = nullptr);
    ~RunProcess();

    Q_INVOKABLE QString launch(const QString &program);


signals:

public slots:

private:

protected:
    QProcess *m_process;

};

#endif // RUNPROCESS_H

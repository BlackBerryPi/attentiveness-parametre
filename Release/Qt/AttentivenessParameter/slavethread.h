#ifndef SLAVETHREAD_H
#define SLAVETHREAD_H

#include <QMutex>
#include <QThread>
#include <QWaitCondition>
#include <QFile>

class SlaveThread : public QThread
{
    Q_OBJECT

public:
    explicit SlaveThread(QObject *parent = nullptr);
    ~SlaveThread();

    void startSlave(const QString &portName, int waitTimeout, const QString &response);

signals:
    void request(const QString &s);
    void error(const QString &s);
    void timeout(const QString &s);

private:
    void run() override;

    QString m_portName;
    QString m_response;
    int m_waitTimeout = 0;
    QMutex m_mutex;
    bool m_quit = false;

    QFile *logFile;
};
//! [0]
#endif // SLAVETHREAD_H

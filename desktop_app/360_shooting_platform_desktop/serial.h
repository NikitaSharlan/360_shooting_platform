#ifndef SERIAL_H
#define SERIAL_H

#include <QObject>
#include <QLabel>
#include <QTimer>
#include <QSet>
#include <QSerialPortInfo>

class SerialMonitor : public QObject {
    Q_OBJECT

public:
    explicit SerialMonitor(QLabel *statusLabel, QObject *parent = nullptr);

private slots:
    void checkPorts();

private:
    QLabel *lbl_Status;
    QSet<QString> previousPorts;

    QSet<QString> getCurrentPorts();
};

#endif // SERIAL_H

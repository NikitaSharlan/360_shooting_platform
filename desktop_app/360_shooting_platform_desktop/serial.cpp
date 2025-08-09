#include "serial.h"

SerialMonitor::SerialMonitor(QLabel *statusLabel, QObject *parent)
    : QObject(parent), lbl_Status(statusLabel) {
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &SerialMonitor::checkPorts);
    timer->start(1000);

    previousPorts = getCurrentPorts();
}

void SerialMonitor::checkPorts() {
    QSet<QString> currentPorts = getCurrentPorts();
    if (currentPorts != previousPorts) {
        QStringList newPorts = (currentPorts - previousPorts).values();
        if (!newPorts.isEmpty()) {
            lbl_Status->setText("COM device connected: " + newPorts.join(", "));
        } else {
            lbl_Status->setText("COM device disconnected");
        }
        previousPorts = currentPorts;
    }
}

QSet<QString> SerialMonitor::getCurrentPorts() {
    QSet<QString> ports;
    for (const QSerialPortInfo &info : QSerialPortInfo::availablePorts()) {
        ports.insert(info.portName());
    }
    return ports;
}

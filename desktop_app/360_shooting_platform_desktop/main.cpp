#include <QApplication>
#include "mainwindow.h"
#include "serial.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MainWindow w;
    w.show();

    // Создаём монитор COM-портов и передаём QLabel из MainWindow
    SerialMonitor *monitor = new SerialMonitor(w.getStatusLabel(), &w);

    return app.exec();
}

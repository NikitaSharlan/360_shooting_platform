#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QLabel* getStatusLabel() const;  // 👈 Публичный метод доступа

private:
    Ui::MainWindow *ui;
    QLabel *statusLabel;             // 👈 Метка для отображения статуса
};

#endif // MAINWINDOW_H

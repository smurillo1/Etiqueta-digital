#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPortInfo>
#include <QSerialPort>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QSerialPort serial;

public:

    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:

    void on_conectar_clicked();

    void on_desconectar_clicked();

    void on_atualizar_clicked();

    void dadosRecebidos();
private:

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

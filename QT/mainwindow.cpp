#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    for(auto& item : QSerialPortInfo::availablePorts())
           ui->box_serial->addItem(item.portName());


    connect(&serial,SIGNAL(readyRead()),this,SLOT(dadosRecebidos()));
    serial.setBaudRate(115200);
    ui->connection_status->setText("<b><font color='red'>Desconectado<\font><\b>");
    ui->tabWidget->setTabText(0,"Conexão");
    ui->tabWidget->setTabText(1,"Produto");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::dadosRecebidos()
{
 auto data = serial.readAll();
 auto dados = QJsonDocument::fromJson(data).object().toVariantMap();

 if(dados.contains("repor_produtos"))
     if(dados["repor_produtos"].toBool())
        ui->reposicao->setText("<b><font color='red'>PRECISA REPOR<\font><\b>");
     else
        ui->reposicao->setText("");
}

void MainWindow::on_conectar_clicked()
{
    serial.setPortName(ui->box_serial->currentText());

    if(serial.open(QIODevice::ReadWrite)){
        ui->connection_status->setText("<b><font color='green'>Conectado<\font><\b>");
    }
    else {
        ui->connection_status->setText("<b><font color='red'>Erro<\font><\b>");
    }
}

void MainWindow::on_desconectar_clicked()
{
    serial.setPortName("");
    serial.setBaudRate(0);

    serial.close();
    ui->connection_status->setText("<b><font color='red'>Desconectado<\font><\b>");

}

void MainWindow::on_atualizar_clicked()
{
    QString nome = "\"nome\":\""+ui->nome->text()+"\",";
    QString preco_bruto = "\"preco_bruto\":"+ui->preco_bruto->text()+",";
    QString desconto = "\"desconto\":"+ui->desconto->text()+",";
    QString desconto_atacado = "\"desconto_atacado\":"+ui->desconto_atacado->text()+",";
    nome="{"+nome+preco_bruto+desconto+desconto_atacado+"}";
    serial.write(nome.toStdString().c_str());
}

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString placas  = ui->lineEdit->text();
    QString modelo  = ui->spinBox->text();
    QString km      = ui->spinBox_2->text();
    QString marca   = ui->lineEdit_4->text();


    qDebug() << "Placas: " << placas << endl <<
                "Modelo: " << modelo << endl <<
                "km:     " << km << endl <<
                "Marca:  " << marca << endl;

    Automovil a;

    a.setPlacas(placas.toStdString());
    a.setModelo(modelo.toInt());
    a.setKm(km.toInt());
    a.setMarca(marca.toStdString());

    taller.agregar(a);
}

void MainWindow::on_pushButton_2_clicked()
{
//    taller.mostrar();
    QString salida;
    ui->plainTextEdit->clear();

    for (size_t i = 0; i < taller.size(); i++) {
        Automovil &a = taller[i];

        salida += "Placas: " +
                QString::fromStdString(a.getPlacas()) +
                "\n" +
                "Modelo: " +
                QString::number(a.getModelo()) +
                "\n" +
                "Km: " +
                QString::number(a.getKm()) +
                "\n" +
                "Marca: " +
                QString::fromStdString(a.getMarca()) +
                "\n";

    }
    ui->plainTextEdit->insertPlainText(salida);
}

void MainWindow::on_actionGuardar_triggered()
{
//    qDebug() << "Guardar";
    QString ubicacion = QFileDialog::getSaveFileName(
                this,
                "Guardar Archivo",
                "C:\\",
                "TXT (*.txt)"
                );
    qDebug() << ubicacion;

    taller.respaldar(ubicacion.toStdString());

}

void MainWindow::on_actionAbrir_triggered()
{
    QString ubicacion =
            QFileDialog::getOpenFileName(
                this,
                "Abrir Archivo",
                "C:\\",
                "TXT (*.txt)"
                );

    qDebug() << ubicacion;

    taller.recuperar(ubicacion.toStdString());
}

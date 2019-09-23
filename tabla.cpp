#include "tabla.h"
#include "ui_tabla.h"

Tabla::Tabla(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Tabla)
{
    ui->setupUi(this);

    crearColumnas();
}

Tabla::~Tabla()
{
    delete ui;
}

void Tabla::mostrarTabla(Taller &taller)
{
    ui->tableWidget->setRowCount(taller.size());

    for(size_t i = 0; i < taller.size(); i++) {
        Automovil &a = taller[i];

        QString placas =
                QString::fromStdString(a.getPlacas());
        QString marca =
                QString::fromStdString(a.getMarca());
        QString modelo =
                QString::number(a.getModelo());
        QString km =
                QString::number(a.getKm());

        QTableWidgetItem *iPlacas = new
                QTableWidgetItem(placas);
        QTableWidgetItem *iMarca = new
                QTableWidgetItem(marca);
        QTableWidgetItem *iModelo = new
                QTableWidgetItem(modelo);
        QTableWidgetItem *iKm = new
                QTableWidgetItem(km);

        ui->tableWidget->setItem(i, 0, iPlacas);
        ui->tableWidget->setItem(i, 1, iMarca);
        ui->tableWidget->setItem(i, 2, iModelo);
        ui->tableWidget->setItem(i, 3, iKm);
    }
}

void Tabla::crearColumnas()
{
    ui->tableWidget->setColumnCount(4);
    QStringList headers;
    headers << "Placas" << "Marca" << "Modelo" << "Km";
    ui->tableWidget->setHorizontalHeaderLabels(headers);
}




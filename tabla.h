#ifndef TABLA_H
#define TABLA_H

#include <QMainWindow>
#include "taller.h"
namespace Ui {
class Tabla;
}

class Tabla : public QMainWindow
{
    Q_OBJECT

public:
    explicit Tabla(QWidget *parent = nullptr);
    ~Tabla();

    void mostrarTabla(Taller &taller);

private:
    Ui::Tabla *ui;

    void crearColumnas();
};

#endif // TABLA_H

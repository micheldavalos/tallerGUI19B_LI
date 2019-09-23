#ifndef TALLER_H
#define TALLER_H

#include "automovil.h"
#include <vector>

class Taller
{
    vector<Automovil> arreglo;

public:
    Taller();
    void agregar(const Automovil &a);
    void mostrar();
    void respaldar(const string &ubicacion);
    void recuperar(const string &ubicacion);
    void inicializar(size_t n, const Automovil &a);
    void ordenar();
    void insertar(size_t p, const Automovil &a);
    size_t size()
    {
        return arreglo.size();
    }
    void eliminar(size_t p);

    Automovil& operator[](size_t i)
    {
        return arreglo[i];
    }
};

#endif // TALLER_H

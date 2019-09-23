#include "automovil.h"

int Automovil::getModelo() const
{
    return modelo;
}

void Automovil::setModelo(int value)
{
    modelo = value;
}

int Automovil::getKm() const
{
    return km;
}

void Automovil::setKm(int value)
{
    km = value;
}

string Automovil::getPlacas() const
{
    return placas;
}

void Automovil::setPlacas(const string &value)
{
    placas = value;
}

Automovil::Automovil()
{

}

void Automovil::setMarca(string valor)
{
    marca = valor;
}

string Automovil::getMarca()
{
    return marca;
}

#ifndef AUTOMOVIL_H
#define AUTOMOVIL_H

#include <iostream>
using namespace std;

class Automovil
{
private:
    string marca;
    int modelo;
    int km;
    string placas;

public:
    Automovil();
    void setMarca(string valor);
    string getMarca();
    int getModelo() const;
    void setModelo(int value);
    int getKm() const;
    void setKm(int value);
    string getPlacas() const;
    void setPlacas(const string &value);

    friend ostream& operator<<(ostream &out,
                               Automovil a)
    {
        out << a.placas << endl <<
               a.km     << endl <<
               a.modelo << endl <<
               a.marca  << endl;

        return out;
    }

    bool operator<(const Automovil &a) const
    {
        return modelo < a.getModelo();
    }
};

#endif // AUTOMOVIL_H

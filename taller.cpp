#include "taller.h"
#include <iomanip>
#include <fstream>
#include <algorithm>

Taller::Taller()
{

}

void Taller::agregar(const Automovil &a)
{
    arreglo.push_back(a);
}

void Taller::mostrar()
{
    cout << left;
    cout << setw(8) << "Placas" <<
            setw(8) << "Marca"  <<
            setw(5) << "Km"     <<
            setw(7) << "Modelo" <<
            endl;
    for (size_t i = 0; i < arreglo.size(); ++i) {
        Automovil &a = arreglo[i];

        cout << setw(8) << a.getPlacas();
        cout << setw(8) << a.getMarca();
        cout << setw(5) << a.getKm();
        cout << setw(7) << a.getModelo() << endl;
    }
}

void Taller::respaldar(const string &ubicacion)
{
//    ofstream archivo("C:\\Users\\Usuario\\Desktop\\taller.txt");
    ofstream archivo(ubicacion);

    if (archivo.is_open()) {
        for (size_t i = 0; i < arreglo.size(); ++i) {
            Automovil &a = arreglo[i];
            archivo << a;
        }
    }
}

void Taller::recuperar(const string &ubicacion)
{
    ifstream archivo(ubicacion);

    if (archivo.is_open()) {
        while (!archivo.eof()) {
            string linea;
            Automovil a;

            getline(archivo, linea);
            if (archivo.eof()) {
                break;
            }
            a.setPlacas(linea);

            getline(archivo, linea);
            int km = stoi(linea);
            a.setKm(km);

            getline(archivo, linea);
            int modelo = stoi(linea);
            a.setModelo(modelo);

            getline(archivo, linea);
            a.setMarca(linea);

            agregar(a);
        }
    }
}

void Taller::inicializar(size_t n, const Automovil &a)
{
    arreglo = vector<Automovil>(n, a);
}

void Taller::ordenar()
{
    sort(arreglo.begin(), arreglo.end());
}

void Taller::insertar(size_t p, const Automovil &a)
{
    arreglo.insert(arreglo.begin()+p, a);
}

void Taller::eliminar(size_t p)
{
    arreglo.erase(arreglo.begin()+p);
}









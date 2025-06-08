#include <iostream>
#include <cstdlib>
#include <cstring>
#include "TipoProducto.h"
#include "FuncionesGlobales.h"

using namespace std;

// Constructor por defecto
TipoProducto::TipoProducto() {
    idTipoProducto = 0;
    strcpy(nombre, "");
}

// Constructor con parámetros
TipoProducto::TipoProducto(int _idTipoProducto, const char* _nombre) {
    idTipoProducto = _idTipoProducto;
    strcpy(nombre, _nombre);
}

// Métodos getter
int TipoProducto::getIdTipoProducto() {
    return idTipoProducto;
}

char* TipoProducto::getNombre() {
    return nombre;
}

// Métodos setter
void TipoProducto::setIdTipoProducto(int _idTipoProducto) {
    idTipoProducto = _idTipoProducto;
}

void TipoProducto::setNombre(const char* _nombre) {
    strcpy(nombre, _nombre);
}

// Método para cargar datos
void TipoProducto::cargar() {
    cout << "ID TIPO PRODUCTO: ";
    cin >> idTipoProducto;
    cout << "NOMBRE: ";
    cargarCadena(nombre, 49);
}

// Método para mostrar datos
void TipoProducto::mostrar() {
    cout << "ID Tipo Producto: " << idTipoProducto << endl;
    cout << "Nombre: " << nombre << endl;
}

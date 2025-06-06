#include <iostream>
#include <cstdlib>
#include <cstring>
#include "Proveedor.h"
#include "FuncionesGlobales.h"

using namespace std;

// Constructor por defecto
proveedor::proveedor() {
    Dni = 0;
    Cuit = 0;
    telefono = 0;
    strcpy(nombre, "");
    strcpy(email, "");
    strcpy(direccion, "");
}

// Constructor con parámetros
proveedor::proveedor(int _Dni, int _Cuit, int _telefono, const char* _nombre, const char* _email, const char* _direccion) {
    Dni = _Dni;
    Cuit = _Cuit;
    telefono = _telefono;
    strcpy(nombre, _nombre);
    strcpy(email, _email);
    strcpy(direccion, _direccion);
}

// Métodos getter
int proveedor::getDni() {
    return Dni;
}

int proveedor::getCuit() {
    return Cuit;
}

int proveedor::gettelefono() {
    return telefono;
}

char* proveedor::getnombre() {
    return nombre;
}

char* proveedor::getemail() {
    return email;
}

char* proveedor::getdireccion() {
    return direccion;
}

// Métodos setter
void proveedor::setDni(int _dni) {
    Dni = _dni;
}

void proveedor::setCuit(int _Cuit) {
    Cuit = _Cuit;
}

void proveedor::settelefono(int _telefono) {
    telefono = _telefono;
}

void proveedor::setnombre(const char* _nombre) {
    strcpy(nombre, _nombre);
}

void proveedor::setemail(const char* _email) {
    strcpy(email, _email);
}

void proveedor::setdireccion(const char* _direccion) {
    strcpy(direccion, _direccion);
}

// Método para cargar datos
void proveedor::cargar() {
    cout << "DNI: ";
    cin >> Dni;
    cout << "CUIT: ";
    cin >> Cuit;
    cout << "TELEFONO: ";
    cin >> telefono;
    cout << "NOMBRE: ";
    cargarCadena(nombre, 49);
    cout << "EMAIL: ";
    cargarCadena(email, 49);
    cout << "DIRECCION: ";
    cargarCadena(direccion, 99);
}

// Método para mostrar datos
void proveedor::mostrar() {
    cout << "DNI: " << Dni << endl;
    cout << "CUIT: " << Cuit << endl;
    cout << "Telefono: " << telefono << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Email: " << email << endl;
    cout << "Direccion: " << direccion << endl;
}

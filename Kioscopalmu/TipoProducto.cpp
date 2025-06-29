#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;
#include "FuncionesGlobales.h"
#include "TipoProducto.h"
#include "ArchivoTipoProducto.h"

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

void agregarTipoProducto() {
    ArchivoTipoProducto archivo("tipos.dat");
    TipoProducto tipo;
    tipo.cargar();

    if (archivo.Guardar(tipo)) {
        cout << "Tipo guardado correctamente!" << endl;
    } else {
        cout << "Error al guardar!" << endl;
    }
}

void listarTipoProductos() {
    ArchivoTipoProducto archivo("tipos.dat");
    int cantidad = archivo.CantidadRegistros();

    if (cantidad == 0) {
        cout << "No hay tipos cargados." << endl;
        return;
    }

    TipoProducto* tipos = new TipoProducto[cantidad];
    archivo.Leer(cantidad, tipos);

    for (int i = 0; i < cantidad; i++) {
        cout << "\n--- Registro " << i+1 << " ---" << endl;
        tipos[i].mostrar();
    }

    delete[] tipos;
}
void Buscarporidtp(){

    ArchivoTipoProducto archivo("tipos.dat");
    int id;
        cout << "ID a buscar: ";
        cin >> id;

        int pos = archivo.Buscar(id);
        if(pos != -1) {
            TipoProducto tipo = archivo.Leer(pos);
            cout << "Encontrado en posicion " << pos << ":" << endl;
            tipo.mostrar();
        } else{
            cout << "No encontrado!" << endl;
                }

}
void Cantidadregistrostp(){

    ArchivoTipoProducto archivo("tipos.dat");
    cout << "Cantidad de registros: " << archivo.CantidadRegistros() << endl;
}

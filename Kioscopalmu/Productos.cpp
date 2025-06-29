#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;
#include "FuncionesGlobales.h"
#include "Productos.h"
#include "ArchivoProductos.h"

// Constructor por defecto
Productos::Productos() {
    nroProducto = 0;
    strcpy(nombre, "");
    idTipoProducto = 0;
    precio = 0.0;
    stock = 0;
}

// Constructor con parámetros
Productos::Productos(int _nroProducto, const char* _nombre, int _idTipoProducto, float _precio, int _stock) {
    nroProducto = _nroProducto;
    strcpy(nombre, _nombre);
    idTipoProducto = _idTipoProducto;
    precio = _precio;
    stock = _stock;
}

// Métodos getter
int Productos::getNroProducto() {
    return nroProducto;
}

char* Productos::getNombre() {
    return nombre;
}

int Productos::getIdTipoProducto() {
    return idTipoProducto;
}

float Productos::getPrecio() {
    return precio;
}

int Productos::getStock() {
    return stock;
}

// Métodos setter
void Productos::setNroProducto(int _nroProducto) {
    nroProducto = _nroProducto;
}

void Productos::setNombre(const char* _nombre) {
    strcpy(nombre, _nombre);
}

void Productos::setIdTipoProducto(int _idTipoProducto) {
    idTipoProducto = _idTipoProducto;
}

void Productos::setPrecio(float _precio) {
    precio = _precio;
}

void Productos::setStock(int _stock) {
    stock = _stock;
}

// Método para cargar datos
void Productos::cargar() {
    cout << "NUMERO DE PRODUCTO: ";
    cin >> nroProducto;
    cout << "NOMBRE: ";
    cargarCadena(nombre, 49);
    cout << "ID TIPO PRODUCTO: ";
    cin >> idTipoProducto;
    cout << "PRECIO: ";
    cin >> precio;
    cout << "STOCK: ";
    cin >> stock;
}

// Método para mostrar datos
void Productos::mostrar() {
    cout << "Numero de Producto: " << nroProducto << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "ID Tipo Producto: " << idTipoProducto << endl;
    cout << "Precio: $" << precio << endl;
    cout << "Stock: " << stock << endl;
}

// Metodos del menu

void altaProducto() {

    ArchivoProductos archivo("productos.dat");
    Productos prod;
    prod.cargar();

        if(archivo.Guardar(prod)) {
                cout << "Producto guardado correctamente!" << endl;
                } else {
                cout << "Error al guardar!" << endl;
                }

                    }
void listarProductos() {

        ArchivoProductos archivo("productos.dat");
        int cantidad = archivo.CantidadRegistros();

        cout << "Cantidad de productos: " << cantidad << endl;

            if(cantidad > 0) {
                Productos *prods = new Productos[cantidad];
                archivo.Leer(cantidad, prods);

                for(int i = 0; i < cantidad; i++) {
                    cout << "\n--- Registro " << i+1 << " ---" << endl;
                    prods[i].mostrar();
                                                    }
                    delete[] prods;
                                }
                            }
void buscarProductos(){

        ArchivoProductos archivo("productos.dat");
        int nro;
            cout << "Numero de producto a buscar: ";
            cin >> nro;

            int pos = archivo.Buscar(nro);
            if(pos != -1) {
            Productos prod = archivo.Leer(pos);
            cout << "Encontrado en posicion " << pos << ":" << endl;
                    prod.mostrar();
                            }
                            else {
                                cout << "No encontrado!" << endl;
                                }

                        }
void cantidadProductos(){

ArchivoProductos archivo("productos.dat");
    cout << "Cantidad de registros: " << archivo.CantidadRegistros() << endl;

}

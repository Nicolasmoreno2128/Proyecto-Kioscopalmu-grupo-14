#include <iostream>
#include <cstdlib>
#include "Compras.h"
#include "FuncionesGlobales.h"

using namespace std;
#include "Fecha.h"

// Constructor por defecto
Compras::Compras() {
    idCompra = 0;
    nroProducto = 0;
    CUITproveedor = 0;
    fecha = Fecha(1,1,2025); // Fecha por defecto
    cantidad = 0;
    importe = 0.0;
}

// Constructor con parámetros
Compras::Compras(int _idCompra, int _nroProducto, int _CUITproveedor, Fecha _fecha, int _cantidad, float _importe) {
    idCompra = _idCompra;
    nroProducto = _nroProducto;
    CUITproveedor = _CUITproveedor;
    fecha = _fecha;
    cantidad = _cantidad;
    importe = _importe;
}

// Métodos getter
int Compras::getIdCompra() {
    return idCompra;
}

int Compras::getNroProducto() {
    return nroProducto;
}

int Compras::getCUITproveedor() {
    return CUITproveedor;
}

Fecha Compras::getFecha() {
    return fecha;
}

int Compras::getCantidad() {
    return cantidad;
}

float Compras::getImporte() {
    return importe;
}

// Métodos setter
void Compras::setIdCompra(int _idCompra) {
    idCompra = _idCompra;
}

void Compras::setNroProducto(int _nroProducto) {
    nroProducto = _nroProducto;
}

void Compras::setCUITproveedor(int _CUITproveedor) {
    CUITproveedor = _CUITproveedor;
}

void Compras::setFecha(Fecha _fecha) {
    fecha = _fecha;
}

void Compras::setCantidad(int _cantidad) {
    cantidad = _cantidad;
}

void Compras::setImporte(float _importe) {
    importe = _importe;
}

// Método para cargar datos
void Compras::cargar() {
    cout << "ID COMPRA: ";
    cin >> idCompra;
    cout << "NUMERO DE PRODUCTO: ";
    cin >> nroProducto;
    cout << "CUIT PROVEEDOR: ";
    cin >> CUITproveedor;
    cout << "FECHA DE COMPRA:" << endl;
    fecha.Cargar();
    cout << "CANTIDAD: ";
    cin >> cantidad;
    cout << "IMPORTE: ";
    cin >> importe;
}

// Método para mostrar datos
void Compras::mostrar() {
    cout << "ID Compra: " << idCompra << endl;
    cout << "Numero de Producto: " << nroProducto << endl;
    cout << "CUIT Proveedor: " << CUITproveedor << endl;
    cout << "Fecha: ";
    fecha.Mostrar();
    cout << "Cantidad: " << cantidad << endl;
    cout << "Importe: $" << importe << endl;
}

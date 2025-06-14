#include <iostream>
#include <cstring>
///Clases y archivos:
///Proveedores (int DNI, int CUIT, char NOMBRE[], char DIRECCION[], char CORREO[], int TELEFONO)
///Productos (int nroProducto, char Nombre[], int idTipoProducto, float Precio, int Stock)
///Tipo de productos (int idTipoProducto, char Nombre[])
///Compras (int idCompra, int nroProducto, int CUITproveedor, Fecha fecha, int cantidad, float importe)
///Fecha (int día, int mes, int anio)

/*Comentario del Profesor:
Conviene que los id sean autonumericos, aunque si quieren pueden usar dni o el cuit como identificador.
en Productos el tipo de producto, puede ser una clase en vez de usar un int
Vayan pensando en los archivos.dat
Tengan en cuenta lo anterior y avancen.*/

using namespace std;
#include "TipoProducto.h"
#include "TipoProducto.cpp"
#include "FuncionesGlobales.h"
#include "Fecha.h"
#include "proveedor.h"
//#include "proveedor.cpp"
#include "Productos.h"
#include "Productos.cpp"
#include "Compras.h"
#include "Compras.cpp"

int main()
{
    cout << "Sistema de Gestion - KioscoPalmu" << endl;

    // Ejemplo de uso de las clases
    cout << "\n=== EJEMPLO DE USO ===" << endl;

    // Crear un tipo de producto
    char tipoNombre[50];
    strcpy(tipoNombre, "Bebidas");
    TipoProducto tipo1;
    tipo1.setIdTipoProducto (1);
    tipo1.setNombre ("Bebidas");

    // Crear un producto
    char prodNombre[50];
    strcpy(prodNombre, "Agua");
    Productos prod1(101, prodNombre, 1, 50000.50, 10);

    // Crear una fecha
    Fecha fecha1(15, 11, 2024);

    // Crear una compra
    Compras compra1(1, 101, 123456789, fecha1, 2, 1000.00);

    cout << "\nDatos cargados exitosamente!" << endl;
    cout << "Las clases estan listas para usar." << endl;

    return 0;
}

#include <iostream>
///Clases y archivos:
///Proveedores (int DNI, int CUIT, string NOMBRE, string DIRECCION, string CORREO, int TELEFONO)
///Productos (int nroProducto, string Nombre, int idTipoProducto, float Precio, int Stock)
///Tipo de productos (int idTipoProducto, string Nombre)
///Compras (int idCompra, int nroProducto, int CUITproveedor, Fecha fecha, int cantidad, float importe)
///Fecha (int día, int mes, int anio)
/*Comentario:
Conviene que los id sean autonumericos, aunque si quieren pueden usar dni o el cuit como identificador.
en Productos el tipo de producto, puede ser una clase en vez de usar un int
Vayan pensando en los archivos.dat
Tengan en cuenta lo anterior y avancen.*/

using namespace std;
#include "Fecha.h"
#include "FuncionesGlobales.h"
#include "proveedor.h"



int main()
{
    proveedor helloword(40471807,404718070, 1135171006, "Nicolais", "manuelestrada", "nycoelcapoarrobahotmail.com");
    //helloword.mostrar();
    return 0;
}

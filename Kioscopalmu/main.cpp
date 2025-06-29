#include <iostream>
#include <cstring>
using namespace std;

// Incluir todos los headers
#include "FuncionesGlobales.h"
#include "Fecha.h"
#include "TipoProducto.h"
#include "proveedor.h"
#include "Productos.h"
#include "Compras.h"
#include "menu.h"

// Incluir las clases archivo
#include "ArchivoTipoProducto.h"
#include "ArchivoProveedor.h"
#include "ArchivoProductos.h"
#include "ArchivoCompras.h"

// Prototipos de funciones de prueba
void testTipoProducto();
void testProveedor();
void testProductos();
void testCompras();
void mostrarMenuPrincipal();
void menuExportaciones();

int main()
{
    mostrarMenuPrincipal(); // Prueba menu .cpp y .h

}

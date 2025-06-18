#include <iostream>
#include "Menu.h"
#include "ArchivoTipoProducto.h"
#include "TipoProducto.h"

using namespace std;


/// MENU FUNCIONAL PARA EL TIPOO DE PRODUCTO
// FALTA REALIZAR EL TRASPASO DE LAS DEMAS CLASES AL MENU
/*
void mostrarMenuPrincipal() {
    int opcion;
    do {

        cout << "=== SISTEMA DE GESTION KIOSCOPALMU ===" << endl;

        cout << "\n===== MENU PRINCIPAL =====" << endl;
        cout << "1. Tipo de Producto" << endl;
        cout << "2. Productos" << endl;
        cout << "3. Proveedores" << endl;
        cout << "4. Compras" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1: menuTipoProducto(); break;
            case 2: menuProductos(); break;
            case 3: menuProveedores(); break;
            case 4: menuCompras(); break;
            case 0: cout << "Saliendo del programa." << endl; break;
            default: cout << "Opcion invalida. Intente nuevamente.\n"; break;
        }
    } while(opcion != 0);
}

// TIPO DE PRODUCTO
void menuTipoProducto() {
    int opcion;
    do {
        cout << "\n--- MENU TIPO DE PRODUCTO ---" << endl;
        cout << "1. Agregar tipo" << endl;
        cout << "2. Listar tipos" << endl;
        cout << "0. Volver" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1: agregarTipoProducto(); break;
            case 2: listarTipoProductos(); break;
            case 0: break;
            default: cout << "Opcion invalida.\n"; break;
        }
    } while(opcion != 0);
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

// Las siguientes funciones ya estaban declaradas antes:
void menuProductos() {}
void altaProducto() {}
void listarProductos() {}

void menuProveedores() {}
void altaProveedor() {}
void listarProveedores() {}

void menuCompras() {}
void registrarCompra() {}
void listarCompras() {}
*/

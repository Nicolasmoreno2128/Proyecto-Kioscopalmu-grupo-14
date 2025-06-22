#include <iostream>
#include "Menu.h"
#include "ArchivoTipoProducto.h"
#include "TipoProducto.h"
#include "Productos.h"
#include "ArchivoProductos.h"
#include "proveedor.h"
#include "ArchivoProveedor.h"
#include "FuncionesGlobales.h"

using namespace std;


/// MENU FUNCIONAL PARA EL TIPOO DE PRODUCTO
// FALTA REALIZAR EL TRASPASO DE LAS DEMAS CLASES AL MENU

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
            case 3: menuProveedor(); break;
            case 4: menuCompras(); break;
            case 0: cout << "Saliendo del programa." << endl; break;
            default: cout << "Opcion invalida. Intente nuevamente.\n"; break;
        }
    } while(opcion != 0);
}

// INICIA MENU TIPO DE PRODUCTO
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
//FINALIZA MENU TIPO DE PRODUCTOS

/// COMIENZA MENU DE PRODUCTO

void menuProductos() {
cout << "\n=== MENU PRODUCTOS ===" << endl;
int opcion;
    do {
        cout << "\n--- MENU DE PRODUCTO ---" << endl;
        cout << "1. Agregar Producto" << endl;
        cout << "2. Listar todos los productos" << endl;
        cout << "3. Buscar por numero" << endl;
        cout << "4. Cantidad de productos" << endl;
        cout << "0. Volver" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1: altaProducto(); break;
            case 2: listarProductos(); break;
            case 3: buscarProductos(); break;
            case 4: cantidadProductos(); break;
            case 0: break;
            default: cout << "Opcion invalida.\n"; break;
        }
    } while(opcion != 0);
}
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

/// FINALIZA Menu productos


// COMIENZA MENU DE PROVEEDOR
void menuProveedor() {
int opcion;
    do {
        cout << "\n--- MENU DE PROVEEDOR ---" << endl;
        cout << "1. Agregar Proveedor" << endl;
        cout << "2. Listar todos los proveedores" << endl;
        cout << "3. Buscar por DNI" << endl;
        cout << "4. Buscar por CUIT" << endl;
        cout << "5. Cantidad de proveedores registrados" << endl;
        cout << "0. Volver" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1: altaProveedor(); break;
            case 2: listarProveedores(); break;
            case 3: buscarProveedoresDNI(); break;
            case 4: buscarProveedoresCUIT(); break;
            case 5: CantidadProveedores(); break;
            case 0: break;
            default: cout << "Opcion invalida.\n"; break;
        }
    } while(opcion != 0);
}



void altaProveedor() {
    ArchivoProveedor archivo("proveedores.dat");
    proveedor prov;
    prov.cargar();

        if(archivo.Guardar(prov)) {
            cout << "Proveedor guardado correctamente!" << endl;
        } else {
                cout << "Error al guardar!" << endl;
                }
}
void listarProveedores() {
    ArchivoProveedor archivo("proveedores.dat");
    int cantidad = archivo.CantidadRegistros();
        cout << "Cantidad de proveedores: " << cantidad << endl;

            if(cantidad > 0) {
                proveedor *provs = new proveedor[cantidad];
                archivo.Leer(cantidad, provs);

            for(int i = 0; i < cantidad; i++) {
                        cout << "\n--- Registro " << i+1 << " ---" << endl;
                        provs[i].mostrar();
                                                }
                    delete[] provs;
                            }
}
void buscarProveedoresDNI(){
        ArchivoProveedor archivo("proveedores.dat");
        int dni;
            cout << "DNI a buscar: ";
            cin >> dni;

        int pos = archivo.Buscar(dni);
            if(pos != -1) {
                proveedor prov = archivo.Leer(pos);
                cout << "Encontrado en posicion " << pos << ":" << endl;
                prov.mostrar();
                } else {
                cout << "No encontrado!" << endl;
                }
}
void buscarProveedoresCUIT(){
    ArchivoProveedor archivo("proveedores.dat");
    char cuit[25];
            cout << "CUIT a buscar: ";
            cargarCadena(cuit,25);

        int pos = archivo.BuscarPorCuit(cuit);
            if(pos != -1) {
                proveedor prov = archivo.Leer(pos);
                cout << "Encontrado en posicion " << pos << ":" << endl;
                prov.mostrar();
            } else {
                    cout << "No encontrado!" << endl;
                    }
}
void CantidadProveedores(){
    ArchivoProveedor archivo("proveedores.dat");
    cout << "Cantidad de registros: " << archivo.CantidadRegistros() << endl;
}

//Menu Compras
void menuCompras() {}
void registrarCompra() {}
void listarCompras() {}



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

int main()
{
    cout << "=== SISTEMA DE GESTION KIOSCOPALMU ===" << endl;
    cout << "=== PRUEBA DE CLASES ARCHIVO ===" << endl << endl;

    int opcion;
    do {
        mostrarMenuPrincipal();
        cout << "Ingrese opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                testTipoProducto();
                break;
            case 2:
                testProveedor();
                break;
            case 3:
                testProductos();
                break;
            case 4:
                testCompras();
                break;
            case 0:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion invalida!" << endl;
        }

        if(opcion != 0) {
            cout << "\nPresione Enter para continuar...";
            cin.ignore();
            cin.get();
        }

    } while(opcion != 0);

    return 0;
}

void mostrarMenuPrincipal() {
    cout << "\n=== MENU PRINCIPAL ===" << endl;
    cout << "1. Probar TipoProducto" << endl;
    cout << "2. Probar Proveedor" << endl;
    cout << "3. Probar Productos" << endl;
    cout << "4. Probar Compras" << endl;
    cout << "0. Salir" << endl;
    cout << "========================" << endl;
}

void testTipoProducto() {
    cout << "\n=== PRUEBA TIPO PRODUCTO ===" << endl;

    ArchivoTipoProducto archivo("tipos.dat");
    int opcion;

    do {
        cout << "\n1. Agregar tipo" << endl;
        cout << "2. Listar todos" << endl;
        cout << "3. Buscar por ID" << endl;
        cout << "4. Cantidad de registros" << endl;
        cout << "0. Volver" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1: {
                TipoProducto tipo;
                tipo.cargar();

                if(archivo.Guardar(tipo)) {
                    cout << "Tipo guardado correctamente!" << endl;
                } else {
                    cout << "Error al guardar!" << endl;
                }
                break;
            }
            case 2: {
                int cantidad = archivo.CantidadRegistros();
                cout << "Cantidad de tipos: " << cantidad << endl;

                if(cantidad > 0) {
                    TipoProducto *tipos = new TipoProducto[cantidad];
                    archivo.Leer(cantidad, tipos);

                    for(int i = 0; i < cantidad; i++) {
                        cout << "\n--- Registro " << i+1 << " ---" << endl;
                        tipos[i].mostrar();
                    }
                    delete[] tipos;
                }
                break;
            }
            case 3: {
                int id;
                cout << "ID a buscar: ";
                cin >> id;

                int pos = archivo.Buscar(id);
                if(pos != -1) {
                    TipoProducto tipo = archivo.Leer(pos);
                    cout << "Encontrado en posicion " << pos << ":" << endl;
                    tipo.mostrar();
                } else {
                    cout << "No encontrado!" << endl;
                }
                break;
            }
            case 4: {
                cout << "Cantidad de registros: " << archivo.CantidadRegistros() << endl;
                break;
            }
        }
    } while(opcion != 0);
}

void testProveedor() {
    cout << "\n=== PRUEBA PROVEEDOR ===" << endl;

    ArchivoProveedor archivo("proveedores.dat");
    int opcion;

    do {
        cout << "\n1. Agregar proveedor" << endl;
        cout << "2. Listar todos" << endl;
        cout << "3. Buscar por DNI" << endl;
        cout << "4. Buscar por CUIT" << endl;
        cout << "5. Cantidad de registros" << endl;
        cout << "0. Volver" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1: {
                proveedor prov;
                prov.cargar();

                if(archivo.Guardar(prov)) {
                    cout << "Proveedor guardado correctamente!" << endl;
                } else {
                    cout << "Error al guardar!" << endl;
                }
                break;
            }
            case 2: {
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
                break;
            }
            case 3: {
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
                break;
            }
            case 4: {
                int cuit;
                cout << "CUIT a buscar: ";
                cin >> cuit;

                int pos = archivo.BuscarPorCuit(cuit);
                if(pos != -1) {
                    proveedor prov = archivo.Leer(pos);
                    cout << "Encontrado en posicion " << pos << ":" << endl;
                    prov.mostrar();
                } else {
                    cout << "No encontrado!" << endl;
                }
                break;
            }
            case 5: {
                cout << "Cantidad de registros: " << archivo.CantidadRegistros() << endl;
                break;
            }
        }
    } while(opcion != 0);
}

void testProductos() {
    cout << "\n=== PRUEBA PRODUCTOS ===" << endl;

    ArchivoProductos archivo("productos.dat");
    int opcion;

    do {
        cout << "\n1. Agregar producto" << endl;
        cout << "2. Listar todos" << endl;
        cout << "3. Buscar por numero" << endl;
        cout << "4. Cantidad de registros" << endl;
        cout << "0. Volver" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1: {
                Productos prod;
                prod.cargar();

                if(archivo.Guardar(prod)) {
                    cout << "Producto guardado correctamente!" << endl;
                } else {
                    cout << "Error al guardar!" << endl;
                }
                break;
            }
            case 2: {
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
                break;
            }
            case 3: {
                int nro;
                cout << "Numero de producto a buscar: ";
                cin >> nro;

                int pos = archivo.Buscar(nro);
                if(pos != -1) {
                    Productos prod = archivo.Leer(pos);
                    cout << "Encontrado en posicion " << pos << ":" << endl;
                    prod.mostrar();
                } else {
                    cout << "No encontrado!" << endl;
                }
                break;
            }
            case 4: {
                cout << "Cantidad de registros: " << archivo.CantidadRegistros() << endl;
                break;
            }
        }
    } while(opcion != 0);
}

void testCompras() {
    cout << "\n=== PRUEBA COMPRAS ===" << endl;

    ArchivoCompras archivo("compras.dat");
    int opcion;

    do {
        cout << "\n1. Agregar compra" << endl;
        cout << "2. Listar todas" << endl;
        cout << "3. Buscar por ID compra" << endl;
        cout << "4. Buscar por producto" << endl;
        cout << "5. Buscar por proveedor" << endl;
        cout << "6. Cantidad de registros" << endl;
        cout << "0. Volver" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1: {
                Compras compra;
                compra.cargar();

                if(archivo.Guardar(compra)) {
                    cout << "Compra guardada correctamente!" << endl;
                } else {
                    cout << "Error al guardar!" << endl;
                }
                break;
            }
            case 2: {
                int cantidad = archivo.CantidadRegistros();
                cout << "Cantidad de compras: " << cantidad << endl;

                if(cantidad > 0) {
                    Compras *compras = new Compras[cantidad];
                    archivo.Leer(cantidad, compras);

                    for(int i = 0; i < cantidad; i++) {
                        cout << "\n--- Registro " << i+1 << " ---" << endl;
                        compras[i].mostrar();
                    }
                    delete[] compras;
                }
                break;
            }
            case 3: {
                int id;
                cout << "ID de compra a buscar: ";
                cin >> id;

                int pos = archivo.Buscar(id);
                if(pos != -1) {
                    Compras compra = archivo.Leer(pos);
                    cout << "Encontrada en posicion " << pos << ":" << endl;
                    compra.mostrar();
                } else {
                    cout << "No encontrada!" << endl;
                }
                break;
            }
            case 4: {
                int nroProd;
                cout << "Numero de producto a buscar: ";
                cin >> nroProd;

                int pos = archivo.BuscarPorProducto(nroProd);
                if(pos != -1) {
                    Compras compra = archivo.Leer(pos);
                    cout << "Encontrada en posicion " << pos << ":" << endl;
                    compra.mostrar();
                } else {
                    cout << "No encontrada!" << endl;
                }
                break;
            }
            case 5: {
                int cuit;
                cout << "CUIT de proveedor a buscar: ";
                cin >> cuit;

                int pos = archivo.BuscarPorProveedor(cuit);
                if(pos != -1) {
                    Compras compra = archivo.Leer(pos);
                    cout << "Encontrada en posicion " << pos << ":" << endl;
                    compra.mostrar();
                } else {
                    cout << "No encontrada!" << endl;
                }
                break;
            }
            case 6: {
                cout << "Cantidad de registros: " << archivo.CantidadRegistros() << endl;
                break;
            }
        }
    } while(opcion != 0);
}

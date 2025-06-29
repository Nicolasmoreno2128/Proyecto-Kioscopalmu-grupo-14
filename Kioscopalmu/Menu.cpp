#include <iostream>
#include "Menu.h"
#include "ArchivoTipoProducto.h"
#include "TipoProducto.h"
#include "Productos.h"
#include "ArchivoProductos.h"
#include "proveedor.h"
#include "ArchivoProveedor.h"
#include "FuncionesGlobales.h"
#include "Compras.h"
#include "ArchivoCompras.h"
#include "exportarCSV.h"
#include "backup.h"

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
        cout << "5. Exportaciones a CSV" << endl;
        cout << "6. Backup y Restauracion" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1: menuTipoProducto(); break;
            case 2: menuProductos(); break;
            case 3: menuProveedor(); break;
            case 4: menuCompras(); break;
            case 5: menuExportaciones(); break;
            case 6: menuBackup(); break;
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
        cout << "2. Listar todos" << endl;
        cout << "3. Buscar por ID el Tipo de Producto" << endl;
        cout << "4. Cantidad de Registros" << endl;
        cout << "0. Volver" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1: agregarTipoProducto(); break; //Agregar tipo de producto
            case 2: listarTipoProductos(); break; // Listar todos los tipos de productos
            case 3: Buscarporidtp(); break;       // Buscar por tipo de producto
            case 4: Cantidadregistrostp(); break; // Cantidad de Tipos de productos registrados
            case 0: break;
            default: cout << "Opcion invalida.\n"; break;
        }
    } while(opcion != 0);
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

// FINALIZA MENU DE PROVEEDOR


///COMIENZA MENU COMPRAS

void menuCompras() {

cout << "\n=== MENU COMPRAS ===" << endl;

    int opcion;
    do {
        cout << "1. Agregar compra" << endl;
        cout << "2. Listar todas" << endl;
        cout << "3. Buscar por ID compra" << endl;
        cout << "4. Buscar por producto" << endl;
        cout << "5. Buscar por proveedor" << endl;
        cout << "6. Cantidad de registros" << endl;
        cout << "0. Volver" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1: registrarCompra(); break;
            case 2: listarCompras(); break;
            case 3: buscarxIDcompra(); break;
            case 4: buscarProducto(); break;
            case 5: buscarProveedorcomp(); break;
            case 6: Cantidadregistroscomp(); break;
            case 0: break;
            default: cout << "Opcion invalida.\n"; break;
        }
    } while(opcion != 0);

}

void registrarCompra() {
    ArchivoCompras archivo("compras.dat");
    Compras compra;
    compra.cargar();

    if(archivo.Guardar(compra)) {
        cout << "Compra guardada correctamente!" << endl;
                                }
    else {
        cout << "Error al guardar!" << endl;
        }
}
void listarCompras() {

    ArchivoCompras archivo("compras.dat");
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

}
void buscarxIDcompra(){

    ArchivoCompras archivo("compras.dat");
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
}
void buscarProducto(){
    ArchivoCompras archivo("compras.dat");
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
}
void buscarProveedorcomp(){
    ArchivoCompras archivo("compras.dat");
     char cuit[25];
        cout << "CUIT de proveedor a buscar: ";
        cargarCadena(cuit,25);

        int pos = archivo.BuscarPorProveedor(cuit);
            if(pos != -1) {
                Compras compra = archivo.Leer(pos);
                    cout << "Encontrada en posicion " << pos << ":" << endl;
                    compra.mostrar();
                    }
            else { cout << "No encontrada!" << endl;
                  }
}
void Cantidadregistroscomp(){
    ArchivoCompras archivo("compras.dat");
        cout << "Cantidad de registros: " << archivo.CantidadRegistros() << endl;
}

/// COMIENZA MENU EXPORTAR CSV

void menuExportaciones() {

    int opcion;
    do {
        cout << "\n=== MENU EXPORTACIONES ===" << endl;
        cout << "1. Exportar Compras a CSV" << endl;
        cout << "2. Exportar Proveedores a CSV" << endl;
        cout << "3. Exportar Productos a CSV" << endl;
        cout << "4. Exportar Tipos de Producto a CSV" << endl;
        cout << "5. Exportar TODO (todos los archivos)" << endl;
        cout << "0. Volver al menu principal" << endl;
        cout << "==================================" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                exportarExcelCompras();
                break;
            case 2:
                exportarExcelProveedores();
                break;
            case 3:
                exportarExcelProductos();
                break;
            case 4:
                exportarExcelTipoProductos();
                break;
            case 5:
                cout << "Exportando todos los archivos..." << endl;
                exportarExcelCompras();
                exportarExcelProveedores();
                exportarExcelProductos();
                exportarExcelTipoProductos();
                cout << "Exportacion completa finalizada!" << endl;
                break;
            case 0:
                cout << "Volviendo al menu principal..." << endl;
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
}

/// COMIENZA MENU BACKUP

void menuBackup(){
    int opcion;
    do {
        cout << "\n=== MENU BACKUP Y RESTAURACION ===" << endl;
        cout << "1. Backup de Compras" << endl;
        cout << "2. Backup de Productos" << endl;
        cout << "3. Backup de Proveedores" << endl;
        cout << "4. Backup de Tipos de Producto" << endl;
        cout << "5. Backup Completo (todos los archivos)" << endl;
        cout << "6. Restaurar Compras" << endl;
        cout << "7. Restaurar Productos" << endl;
        cout << "8. Restaurar Proveedores" << endl;
        cout << "9. Restaurar Tipos de Producto" << endl;
        cout << "10. Restauracion Completa" << endl;
        cout << "0. Volver al menu principal" << endl;
        cout << "======================================" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                realizarCopiaCompras();
                break;
            case 2:
                realizarCopiaProductos();
                break;
            case 3:
                realizarCopiaProveedores();
                break;
            case 4:
                realizarCopiaTipoProductos();
                break;
            case 5:
                realizarBackupCompleto();
                break;
            case 6:
                restaurarComprasDesdeBackup();
                break;
            case 7:
                restaurarProductosDesdeBackup();
                break;
            case 8:
                restaurarProveedoresDesdeBackup();
                break;
            case 9:
                restaurarTipoProductosDesdeBackup();
                break;
            case 10:
                restaurarBackupCompleto();
                break;
            case 0:
                cout << "Volviendo al menu principal..." << endl;
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
}


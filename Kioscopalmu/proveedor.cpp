#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
#include "FuncionesGlobales.h"
#include "proveedor.h"
#include "ArchivoProveedor.h"


// Constructor por defecto
proveedor::proveedor() {
    Dni = 0;
    telefono = 0;
    strcpy(Cuit, "");
    strcpy(nombre, "");
    strcpy(email, "");
    strcpy(direccion, "");
}

// Constructor con parámetros
proveedor::proveedor(int _Dni, int _telefono, const char* _Cuit, const char* _nombre, const char* _email, const char* _direccion) {
    Dni = _Dni;
    telefono = _telefono;
    strcpy(Cuit, _Cuit);
    strcpy(nombre, _nombre);
    strcpy(email, _email);
    strcpy(direccion, _direccion);
}

// Métodos getter
int proveedor::getDni() {
    return Dni;
}

int proveedor::gettelefono() {
    return telefono;
}

const char* proveedor::getCuit() {
    return Cuit;
}

const char* proveedor::getnombre() {
    return nombre;
}

const char* proveedor::getemail() {
    return email;
}

const char* proveedor::getdireccion() {
    return direccion;
}

// Métodos setter
void proveedor::setDni(int _dni) {
    Dni = _dni;

}
void proveedor::settelefono(int _telefono) {
    telefono = _telefono;
}

void proveedor::setCuit(const char* _Cuit) {
    strcpy(Cuit, _Cuit);
}

void proveedor::setnombre(const char* _nombre) {
    strcpy(nombre, _nombre);
}

void proveedor::setemail(const char* _email) {
    strcpy(email, _email);
}

void proveedor::setdireccion(const char* _direccion) {
    strcpy(direccion, _direccion);
}

// Método para cargar datos
void proveedor::cargar() {
    // DNI
    do {
    cout << "DNI (8 digitos numericos): ";
    cin >> Dni;
    if (cin.fail() || Dni < 10000000 || Dni > 99999999) {
        cout << "DNI invalido. Debe contener exactamente 8 digitos numericos.\n";
        cin.clear();
        cin.ignore(1000, '\n');
    } else break;
        } while (true);

    // CUIT (11 dígitos numéricos)
    /*do {
        cout << "CUIT (11 digitos): ";
        cargarCadena(Cuit, 49);
        int len = strlen(Cuit);
        bool valido = true;
        for (int i = 0; i < len; i++) {
            if (!isdigit(Cuit[i])) {
                valido = false;
                break;
            }
        }
        if (len != 11 || !valido) {
            cout << "CUIT invalido. Debe contener exactamente 11 digitos numericos.\n";
        } else break;
    } while (true);
*/
    // Teléfono
    do {
        cout << "TELEFONO (entero positivo): ";
        cin >> telefono;
        if (cin.fail() || telefono <= 0) {
            cout << "Telefono invalido.\n";
            cin.clear(); cin.ignore(1000, '\n');
        } else break;
    } while (true);

    // Nombre
    do {
        cout << "NOMBRE: ";
        cargarCadena(nombre, 49);
        if (strlen(nombre) == 0) {
            cout << "El nombre no puede estar vacio.\n";
        } else break;
    } while (true);

    // Email
    do {
        cout << "EMAIL: ";
        cargarCadena(email, 49);
        if (strlen(email) == 0) {
            cout << "El email no puede estar vacio.\n";
        } else break;
    } while (true);

    // Dirección
    do {
        cout << "DIRECCION: ";
        cargarCadena(direccion, 99);
        if (strlen(direccion) == 0) {
            cout << "La direccion no puede estar vacia.\n";
        } else break;
    } while (true);
}

// Método para mostrar datos
void proveedor::mostrar() {
    cout << "DNI: " << Dni << endl;
    cout << "CUIT: " << Cuit << endl;
    cout << "Telefono: " << telefono << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Email: " << email << endl;
    cout << "Direccion: " << direccion << endl;
}
// Metodos del menu
void altaProveedor() {

 ///Prueba inicio

 ArchivoProveedor archivo("proveedores.dat");

    proveedor prov;

    // VALIDACIÓN DE CUIT (exactamente 11 dígitos numéricos)
    char cuitTemp[50];
    do {
        cout << "CUIT (11 digitos): ";
        cargarCadena(cuitTemp, 49);

        int len = strlen(cuitTemp);
        bool valido = true;
        for (int i = 0; i < len; i++) {
            if (!isdigit(cuitTemp[i])) {
                valido = false;
                break;
            }
        }

        if (len != 11 || !valido) {
            cout << "CUIT invalido. Debe contener exactamente 11 digitos numericos.\n";
        } else break;
    } while (true);

    // VERIFICACIÓN DE CUIT DUPLICADO
    if (archivo.BuscarPorCuit(cuitTemp) != -1) {
        cout << "Error: ya existe un proveedor con ese CUIT registrado.\n";
        return;
    }

    // Guardamos el CUIT directamente al objeto antes de cargar
    prov.setCuit(cuitTemp);

    // LLAMAMOS A cargar() PARA COMPLETAR DATOS
    prov.cargar();

    // GUARDAMOS EN ARCHIVO
    if (archivo.Guardar(prov)) {
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

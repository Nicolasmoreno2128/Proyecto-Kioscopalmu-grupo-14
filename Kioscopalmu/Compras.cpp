#include <iostream>
#include <cstdlib>
#include "FuncionesGlobales.h"
#include "Compras.h"
#include <cstring>

using namespace std;
#include "Fecha.h"
#include "ArchivoCompras.h"

// Constructor por defecto
Compras::Compras() {
    idCompra = 0;
    nroProducto = 0;
    strcpy(CUITproveedor,"" );
    fecha = Fecha(1,1,2025); // Fecha por defecto
    cantidad = 0;
    importe = 0.0;
}

// Constructor con parámetros
Compras::Compras(int _idCompra, int _nroProducto, const char* _CUITproveedor, Fecha _fecha, int _cantidad, float _importe) {
    idCompra = _idCompra;
    nroProducto = _nroProducto;
    strcpy(CUITproveedor, _CUITproveedor);
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

const char* Compras::getCUITproveedor() {
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

void Compras::setCUITproveedor(const char* _CUITproveedor) {
   strcpy(CUITproveedor, _CUITproveedor);
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
    // ID de compra
    do {
        cout << "ID COMPRA (entero positivo): ";
        cin >> idCompra;
        if (cin.fail() || idCompra <= 0) {
            cout << "ID inválido. Intente nuevamente.\n";
            cin.clear();
            cin.ignore(1000, '\n');
        } else break;
    } while (true);

    // Número de producto
    do {
        cout << "NUMERO DE PRODUCTO (entero positivo): ";
        cin >> nroProducto;
        if (cin.fail() || nroProducto <= 0) {
            cout << "Número inválido. Intente nuevamente.\n";
            cin.clear();
            cin.ignore(1000, '\n');
        } else break;
    } while (true);

    // CUIT proveedor (11 dígitos numéricos)
    do {
        cout << "CUIT PROVEEDOR (11 dígitos numéricos): ";
        cargarCadena(CUITproveedor, 49);

        int longitud = strlen(CUITproveedor);
        bool esNumerico = true;

        for (int i = 0; i < longitud; i++) {
            if (!isdigit(CUITproveedor[i])) {
                esNumerico = false;
                break;
            }
        }

        if (longitud != 11 || !esNumerico) {
            cout << "CUIT inválido. Debe contener exactamente 11 dígitos numéricos.\n";
        } else break;
    } while (true);

    // Fecha de compra
    cout << "FECHA DE COMPRA:" << endl;
    fecha.Cargar();  // Se validará dentro de esa función

    // Cantidad
    do {
        cout << "CANTIDAD (entero positivo): ";
        cin >> cantidad;
        if (cin.fail() || cantidad <= 0) {
            cout << "Cantidad inválida. Ingrese un valor mayor a cero.\n";
            cin.clear();
            cin.ignore(1000, '\n');
        } else break;
    } while (true);

    // Importe
    do {
        cout << "IMPORTE ($ mayor a 0): ";
        cin >> importe;
        if (cin.fail() || importe <= 0) {
            cout << "Importe inválido. Ingrese un valor mayor a cero.\n";
            cin.clear();
            cin.ignore(1000, '\n');
        } else break;
    } while (true);
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
// Metodos del menu
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

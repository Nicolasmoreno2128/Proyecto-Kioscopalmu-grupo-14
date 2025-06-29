#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include "exportarCSV.h"

#include "ArchivoCompras.h"
#include "ArchivoProveedor.h"
#include "ArchivoProductos.h"
#include "ArchivoTipoProducto.h"
#include "Compras.h"
#include "proveedor.h"
#include "Productos.h"
#include "TipoProducto.h"
#include "Fecha.h"

using namespace std;

int exportarExcelCompras(){
///constructor ayuda a setear/asignar valores a las propiedades de mi objeto en este caso "archivo" esos valores pueden ser por parametros o sin ellos
    ArchivoCompras archivo("compras.dat");
    int total = archivo.CantidadRegistros();

    ofstream archivoCsv("compras.csv");
    if (!archivoCsv.is_open()) {
        cerr << "No se pudo crear el archivo CSV." << endl;
        return 1;
    }

    archivoCsv << "ID Compra,Nro Producto,CUIT Proveedor,Fecha,Cantidad,Importe\n";

    for (int i = 0; i < total; i++) {
        Compras c = archivo.Leer(i);
        Fecha f = c.getFecha();

        // Si Fecha tiene getDia(), getMes(), getAnio()
        string fechaTexto = to_string(f.getDia()) + "/" + to_string(f.getMes()) + "/" + to_string(f.getAnio());

        archivoCsv << c.getIdCompra() << ","
                   << c.getNroProducto() << ","
                   << c.getCUITproveedor() << ","
                   << fechaTexto << ","
                   << c.getCantidad() << ","
                   << c.getImporte() << "\n";
    }

    archivoCsv.close();
    cout << "Exportacion completada a compras.csv" << endl;
    return 0;
}

int exportarExcelProveedores(){
    // Constructor ayuda a setear/asignar valores a las propiedades de mi objeto en este caso "archivo"
    ArchivoProveedor archivo("proveedores.dat");
    int total = archivo.CantidadRegistros();

    ofstream archivoCsv("proveedores.csv");
    if (!archivoCsv.is_open()) {
        cerr << "No se pudo crear el archivo CSV." << endl;
        return 1;
    }

    // Header del CSV con las columnas de proveedor
    archivoCsv << "DNI,CUIT,Telefono,Nombre,Email,Direccion\n";

    for (int i = 0; i < total; i++) {
        proveedor p = archivo.Leer(i);

        archivoCsv << p.getDni() << ","
                   << p.getCuit() << ","
                   << p.gettelefono() << ","
                   << p.getnombre() << ","
                   << p.getemail() << ","
                   << p.getdireccion() << "\n";
    }

    archivoCsv.close();
    cout << "Exportacion completada a proveedores.csv" << endl;
    return 0;
}

int exportarExcelProductos(){
    // Constructor ayuda a setear/asignar valores a las propiedades de mi objeto en este caso "archivo"
    ArchivoProductos archivo("productos.dat");
    int total = archivo.CantidadRegistros();

    ofstream archivoCsv("productos.csv");
    if (!archivoCsv.is_open()) {
        cerr << "No se pudo crear el archivo CSV." << endl;
        return 1;
    }

    // Header del CSV con las columnas de productos
    archivoCsv << "Numero Producto,Nombre,ID Tipo Producto,Precio,Stock\n";

    for (int i = 0; i < total; i++) {
        Productos p = archivo.Leer(i);

        archivoCsv << p.getNroProducto() << ","
                   << p.getNombre() << ","
                   << p.getIdTipoProducto() << ","
                   << p.getPrecio() << ","
                   << p.getStock() << "\n";
    }

    archivoCsv.close();
    cout << "Exportacion completada a productos.csv" << endl;
    return 0;
}

int exportarExcelTipoProductos(){
    // Constructor ayuda a setear/asignar valores a las propiedades de mi objeto en este caso "archivo"
    ArchivoTipoProducto archivo("tipos.dat");
    int total = archivo.CantidadRegistros();

    ofstream archivoCsv("tipos_producto.csv");
    if (!archivoCsv.is_open()) {
        cerr << "No se pudo crear el archivo CSV." << endl;
        return 1;
    }

    // Header del CSV con las columnas de tipo producto
    archivoCsv << "ID Tipo Producto,Nombre\n";

    for (int i = 0; i < total; i++) {
        TipoProducto tp = archivo.Leer(i);

        archivoCsv << tp.getIdTipoProducto() << ","
                   << tp.getNombre() << "\n";
    }

    archivoCsv.close();
    cout << "Exportacion completada a tipos_producto.csv" << endl;
    return 0;
}

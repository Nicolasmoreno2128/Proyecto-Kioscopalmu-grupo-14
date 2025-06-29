#ifndef BACKUP_H_INCLUDED
#define BACKUP_H_INCLUDED

#include <iostream>
#include <cstdio>

// Includes de las clases archivo
#include "ArchivoCompras.h"
#include "ArchivoProductos.h"
#include "ArchivoProveedor.h"
#include "ArchivoTipoProducto.h"

// Includes de las clases modelo (necesarias para los objetos)
#include "Compras.h"
#include "Productos.h"
#include "proveedor.h"
#include "TipoProducto.h"

using namespace std;

// Declaraciones de funciones de backup para ArchivoCompras
bool realizarCopiaCompras(const char* nombreBackup = "compras.bkp");
bool restaurarComprasDesdeBackup(const char* nombreBackup = "compras.bkp");

// Declaraciones de funciones de backup para ArchivoProductos
bool realizarCopiaProductos(const char* nombreBackup = "productos.bkp");
bool restaurarProductosDesdeBackup(const char* nombreBackup = "productos.bkp");

// Declaraciones de funciones de backup para ArchivoProveedor
bool realizarCopiaProveedores(const char* nombreBackup = "proveedores.bkp");
bool restaurarProveedoresDesdeBackup(const char* nombreBackup = "proveedores.bkp");

// Declaraciones de funciones de backup para ArchivoTipoProducto
bool realizarCopiaTipoProductos(const char* nombreBackup = "tipos.bkp");
bool restaurarTipoProductosDesdeBackup(const char* nombreBackup = "tipos.bkp");

// Funciones adicionales de utilidad
bool realizarBackupCompleto();
bool restaurarBackupCompleto();

#endif // BACKUP_H_INCLUDED

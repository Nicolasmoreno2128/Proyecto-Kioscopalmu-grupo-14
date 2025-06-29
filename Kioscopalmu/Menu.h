#ifndef MENU_H
#define MENU_H

void mostrarMenuPrincipal();

void menuTipoProducto();
void agregarTipoProducto();
void listarTipoProductos();
void Buscarporidtp();
void Cantidadregistrostp();

void menuProductos();
void altaProducto();
void listarProductos();
void buscarProductos();
void cantidadProductos();

void menuProveedor();
void altaProveedor();
void listarProveedores();
void buscarProveedoresDNI();
void buscarProveedoresCUIT();
void CantidadProveedores();

void menuCompras();
void registrarCompra();
void listarCompras();
void buscarxIDcompra();
void buscarProducto();
void buscarProveedorcomp();
void Cantidadregistroscomp();
int exportarExcelCompras();
int exportarExcelProveedores();
int exportarExcelProductos();
int exportarExcelTipoProductos();
void menuExportaciones();
void menuBackup();
//bool realizarCopiaCompras();
//bool realizarCopiaProductos();
//bool realizarCopiaProveedores();
//bool realizarCopiaTipoProductos();
//bool realizarBackupCompleto();
//bool restaurarComprasDesdeBackup();
//bool restaurarProductosDesdeBackup();
//bool restaurarProveedoresDesdeBackup();
//bool restaurarTipoProductosDesdeBackup();
//bool restaurarBackupCompleto();
#endif // MENU_H

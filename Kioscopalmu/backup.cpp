#include "backup.h"

using namespace std;

// FUNCIONES DE BACKUP PARA COMPRAS
bool realizarCopiaCompras(const char* nombreBackup){
    ArchivoCompras archivo("compras.dat");
    FILE* pBackup;
    Compras obj;

    pBackup = fopen(nombreBackup, "wb");
    if(pBackup == NULL){
        cout << "ERROR AL CREAR ARCHIVO DE BACKUP DE COMPRAS" << endl;
        return false;
    }

    int cantReg = archivo.CantidadRegistros();
    for(int i = 0; i < cantReg; i++){
        obj = archivo.Leer(i);
        fwrite(&obj, sizeof(Compras), 1, pBackup);
    }
    fclose(pBackup);
    cout << "Backup de compras creado exitosamente: " << nombreBackup << endl;
    return true;
}

bool restaurarComprasDesdeBackup(const char* nombreBackup){
    ArchivoCompras archivo("compras.dat");
    FILE* p;
    Compras obj;
    ArchivoCompras archiBackup(nombreBackup);
    int cantReg = archiBackup.CantidadRegistros();

    p = fopen("compras.dat", "wb");
    if(p == NULL){
        cout << "ERROR AL RESTAURAR ARCHIVO DE COMPRAS" << endl;
        return false;
    }

    for(int i = 0; i < cantReg; i++){
        obj = archiBackup.Leer(i);
        fwrite(&obj, sizeof(Compras), 1, p);
    }
    fclose(p);
    cout << "Archivo de compras restaurado exitosamente desde: " << nombreBackup << endl;
    return true;
}

// FUNCIONES DE BACKUP PARA PRODUCTOS
bool realizarCopiaProductos(const char* nombreBackup){
    ArchivoProductos archivo("productos.dat");
    FILE* pBackup;
    Productos obj;

    pBackup = fopen(nombreBackup, "wb");
    if(pBackup == NULL){
        cout << "ERROR AL CREAR ARCHIVO DE BACKUP DE PRODUCTOS" << endl;
        return false;
    }

    int cantReg = archivo.CantidadRegistros();
    for(int i = 0; i < cantReg; i++){
        obj = archivo.Leer(i);
        fwrite(&obj, sizeof(Productos), 1, pBackup);
    }
    fclose(pBackup);
    cout << "Backup de productos creado exitosamente: " << nombreBackup << endl;
    return true;
}

bool restaurarProductosDesdeBackup(const char* nombreBackup){
    ArchivoProductos archivo("productos.dat");
    FILE* p;
    Productos obj;
    ArchivoProductos archiBackup(nombreBackup);
    int cantReg = archiBackup.CantidadRegistros();

    p = fopen("productos.dat", "wb");
    if(p == NULL){
        cout << "ERROR AL RESTAURAR ARCHIVO DE PRODUCTOS" << endl;
        return false;
    }

    for(int i = 0; i < cantReg; i++){
        obj = archiBackup.Leer(i);
        fwrite(&obj, sizeof(Productos), 1, p);
    }
    fclose(p);
    cout << "Archivo de productos restaurado exitosamente desde: " << nombreBackup << endl;
    return true;
}

// FUNCIONES DE BACKUP PARA PROVEEDORES
bool realizarCopiaProveedores(const char* nombreBackup){
    ArchivoProveedor archivo("proveedores.dat");
    FILE* pBackup;
    proveedor obj;

    pBackup = fopen(nombreBackup, "wb");
    if(pBackup == NULL){
        cout << "ERROR AL CREAR ARCHIVO DE BACKUP DE PROVEEDORES" << endl;
        return false;
    }

    int cantReg = archivo.CantidadRegistros();
    for(int i = 0; i < cantReg; i++){
        obj = archivo.Leer(i);
        fwrite(&obj, sizeof(proveedor), 1, pBackup);
    }
    fclose(pBackup);
    cout << "Backup de proveedores creado exitosamente: " << nombreBackup << endl;
    return true;
}

bool restaurarProveedoresDesdeBackup(const char* nombreBackup){
    ArchivoProveedor archivo("proveedores.dat");
    FILE* p;
    proveedor obj;
    ArchivoProveedor archiBackup(nombreBackup);
    int cantReg = archiBackup.CantidadRegistros();

    p = fopen("proveedores.dat", "wb");
    if(p == NULL){
        cout << "ERROR AL RESTAURAR ARCHIVO DE PROVEEDORES" << endl;
        return false;
    }

    for(int i = 0; i < cantReg; i++){
        obj = archiBackup.Leer(i);
        fwrite(&obj, sizeof(proveedor), 1, p);
    }
    fclose(p);
    cout << "Archivo de proveedores restaurado exitosamente desde: " << nombreBackup << endl;
    return true;
}

// FUNCIONES DE BACKUP PARA TIPO PRODUCTOS
bool realizarCopiaTipoProductos(const char* nombreBackup){
    ArchivoTipoProducto archivo("tipos.dat");
    FILE* pBackup;
    TipoProducto obj;

    pBackup = fopen(nombreBackup, "wb");
    if(pBackup == NULL){
        cout << "ERROR AL CREAR ARCHIVO DE BACKUP DE TIPOS DE PRODUCTO" << endl;
        return false;
    }

    int cantReg = archivo.CantidadRegistros();
    for(int i = 0; i < cantReg; i++){
        obj = archivo.Leer(i);
        fwrite(&obj, sizeof(TipoProducto), 1, pBackup);
    }
    fclose(pBackup);
    cout << "Backup de tipos de producto creado exitosamente: " << nombreBackup << endl;
    return true;
}

bool restaurarTipoProductosDesdeBackup(const char* nombreBackup){
    ArchivoTipoProducto archivo("tipos.dat");
    FILE* p;
    TipoProducto obj;
    ArchivoTipoProducto archiBackup(nombreBackup);
    int cantReg = archiBackup.CantidadRegistros();

    p = fopen("tipos.dat", "wb");
    if(p == NULL){
        cout << "ERROR AL RESTAURAR ARCHIVO DE TIPOS DE PRODUCTO" << endl;
        return false;
    }

    for(int i = 0; i < cantReg; i++){
        obj = archiBackup.Leer(i);
        fwrite(&obj, sizeof(TipoProducto), 1, p);
    }
    fclose(p);
    cout << "Archivo de tipos de producto restaurado exitosamente desde: " << nombreBackup << endl;
    return true;
}

// FUNCIONES ADICIONALES
bool realizarBackupCompleto(){
    cout << "=== REALIZANDO BACKUP COMPLETO ===" << endl;
    bool todosOk = true;

    if(!realizarCopiaCompras()) todosOk = false;
    if(!realizarCopiaProductos()) todosOk = false;
    if(!realizarCopiaProveedores()) todosOk = false;
    if(!realizarCopiaTipoProductos()) todosOk = false;

    if(todosOk){
        cout << "=== BACKUP COMPLETO REALIZADO EXITOSAMENTE ===" << endl;
    } else {
        cout << "=== HUBO ERRORES EN EL BACKUP COMPLETO ===" << endl;
    }

    return todosOk;
}

bool restaurarBackupCompleto(){
    cout << "=== RESTAURANDO BACKUP COMPLETO ===" << endl;
    bool todosOk = true;

    if(!restaurarComprasDesdeBackup()) todosOk = false;
    if(!restaurarProductosDesdeBackup()) todosOk = false;
    if(!restaurarProveedoresDesdeBackup()) todosOk = false;
    if(!restaurarTipoProductosDesdeBackup()) todosOk = false;

    if(todosOk){
        cout << "=== RESTAURACION COMPLETA REALIZADA EXITOSAMENTE ===" << endl;
    } else {
        cout << "=== HUBO ERRORES EN LA RESTAURACION COMPLETA ===" << endl;
    }

    return todosOk;
}

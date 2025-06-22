#include "ArchivoProveedor.h"
#include <cstring>

ArchivoProveedor::ArchivoProveedor(const char* nombreArchivo){
    strcpy(_nombreArchivo, nombreArchivo);
}

bool ArchivoProveedor::Guardar(proveedor prov){
    FILE *pArchivo = fopen(_nombreArchivo, "ab");
    if(pArchivo == NULL){
        return false;
    }
    bool ok = fwrite(&prov, sizeof(proveedor), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

bool ArchivoProveedor::Guardar(proveedor prov, int posicion){
    FILE *pArchivo = fopen(_nombreArchivo, "rb+");
    if(pArchivo == NULL){
        return false;
    }
    fseek(pArchivo, sizeof(proveedor) * posicion, SEEK_SET);
    bool ok = fwrite(&prov, sizeof(proveedor), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

int ArchivoProveedor::Buscar(int DNI){
    FILE *pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == NULL){
        return -1;
    }
    proveedor prov;
    int i = 0;
    while(fread(&prov, sizeof(proveedor), 1, pArchivo)){
        if(prov.getDni() == DNI){
            fclose(pArchivo);
            return i;
        }
        i++;
    }
    fclose(pArchivo);
    return -1;
}

int ArchivoProveedor::BuscarPorCuit( const char* CUIT){
    FILE *pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == NULL){
        return -1;
    }
    proveedor prov;
    int i = 0;
    while(fread(&prov, sizeof(proveedor), 1, pArchivo)){
        if(prov.getCuit() == CUIT){
            fclose(pArchivo);
            return i;
        }
        i++;
    }
    fclose(pArchivo);
    return -1;
}

proveedor ArchivoProveedor::Leer(int posicion){
    FILE *pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == NULL){
        return proveedor();
    }
    proveedor prov;
    fseek(pArchivo, sizeof(proveedor) * posicion, SEEK_SET);
    fread(&prov, sizeof(proveedor), 1, pArchivo);
    fclose(pArchivo);
    return prov;
}

int ArchivoProveedor::CantidadRegistros(){
    FILE *pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == NULL){
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(proveedor);
    fclose(pArchivo);
    return cantidadRegistros;
}

void ArchivoProveedor::Leer(int cantidadRegistros, proveedor *vector){
    FILE *pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == NULL){
        return;
    }
    for(int i = 0; i < cantidadRegistros; i++){
        fread(&vector[i], sizeof(proveedor), 1, pArchivo);
    }
    fclose(pArchivo);
}

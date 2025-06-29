#include "ArchivoCompras.h"
#include "Compras.h"
#include <cstring>

ArchivoCompras::ArchivoCompras(const char* nombreArchivo){
    strcpy(_nombreArchivo, nombreArchivo);
}

bool ArchivoCompras::Guardar(Compras compra){
    FILE *pArchivo = fopen(_nombreArchivo, "ab");
    if(pArchivo == NULL){
        return false;
    }
    bool ok = fwrite(&compra, sizeof(Compras), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

bool ArchivoCompras::Guardar(Compras compra, int posicion){
    FILE *pArchivo = fopen(_nombreArchivo, "rb+");
    if(pArchivo == NULL){
        return false;
    }
    fseek(pArchivo, sizeof(Compras) * posicion, SEEK_SET);
    bool ok = fwrite(&compra, sizeof(Compras), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

int ArchivoCompras::Buscar(int idCompra){
    FILE *pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == NULL){
        return -1;
    }
    Compras compra;
    int i = 0;
    while(fread(&compra, sizeof(Compras), 1, pArchivo)){
        if(compra.getIdCompra() == idCompra){
            fclose(pArchivo);
            return i;
        }
        i++;
    }
    fclose(pArchivo);
    return -1;
}

int ArchivoCompras::BuscarPorProducto(int nroProducto){
    FILE *pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == NULL){
        return -1;
    }
    Compras compra;
    int i = 0;
    while(fread(&compra, sizeof(Compras), 1, pArchivo)){
        if(compra.getNroProducto() == nroProducto){
            fclose(pArchivo);
            return i;
        }
        i++;
    }
    fclose(pArchivo);
    return -1;
}

int ArchivoCompras::BuscarPorProveedor(const char* CUITproveedor){
    FILE *pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == NULL){
        return -1;
    }
    Compras compra;
    int i = 0;
    while(fread(&compra, sizeof(Compras), 1, pArchivo)){
        if(strcmp(compra.getCUITproveedor(),CUITproveedor)==0){
            fclose(pArchivo);
            return i;
        }
        i++;
    }
    fclose(pArchivo);
    return -1;
}

Compras ArchivoCompras::Leer(int posicion){
    FILE *pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == NULL){
        return Compras();
    }
    Compras compra;
    fseek(pArchivo, sizeof(Compras) * posicion, SEEK_SET);
    fread(&compra, sizeof(Compras), 1, pArchivo);
    fclose(pArchivo);
    return compra;
}

int ArchivoCompras::CantidadRegistros(){
    FILE *pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == NULL){
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(Compras);
    fclose(pArchivo);
    return cantidadRegistros;
}

void ArchivoCompras::Leer(int cantidadRegistros, Compras *vector){
    FILE *pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == NULL){
        return;
    }
    for(int i = 0; i < cantidadRegistros; i++){
        fread(&vector[i], sizeof(Compras), 1, pArchivo);
    }
    fclose(pArchivo);
}

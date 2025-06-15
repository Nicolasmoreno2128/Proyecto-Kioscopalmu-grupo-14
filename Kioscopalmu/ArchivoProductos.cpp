#include "ArchivoProductos.h"
#include "Productos.cpp"
#include "Productos.h"
#include <cstring>

ArchivoProductos::ArchivoProductos(const char* nombreArchivo){
    strcpy(_nombreArchivo, nombreArchivo);
}

bool ArchivoProductos::Guardar(Productos producto){
    FILE *pArchivo = fopen(_nombreArchivo, "ab");
    if(pArchivo == NULL){
        return false;
    }
    bool ok = fwrite(&producto, sizeof(Productos), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

bool ArchivoProductos::Guardar(Productos producto, int posicion){
    FILE *pArchivo = fopen(_nombreArchivo, "rb+");
    if(pArchivo == NULL){
        return false;
    }
    fseek(pArchivo, sizeof(Productos) * posicion, SEEK_SET);
    bool ok = fwrite(&producto, sizeof(Productos), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

int ArchivoProductos::Buscar(int nroProducto){
    FILE *pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == NULL){
        return -1;
    }
    Productos producto;
    int i = 0;
    while(fread(&producto, sizeof(Productos), 1, pArchivo)){
        if(producto.getNroProducto() == nroProducto){
            fclose(pArchivo);
            return i;
        }
        i++;
    }
    fclose(pArchivo);
    return -1;
}

Productos ArchivoProductos::Leer(int posicion){
    FILE *pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == NULL){
        return Productos();
    }
    Productos producto;
    fseek(pArchivo, sizeof(Productos) * posicion, SEEK_SET);
    fread(&producto, sizeof(Productos), 1, pArchivo);
    fclose(pArchivo);
    return producto;
}

int ArchivoProductos::CantidadRegistros(){
    FILE *pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == NULL){
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(Productos);
    fclose(pArchivo);
    return cantidadRegistros;
}

void ArchivoProductos::Leer(int cantidadRegistros, Productos *vector){
    FILE *pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == NULL){
        return;
    }
    for(int i = 0; i < cantidadRegistros; i++){
        fread(&vector[i], sizeof(Productos), 1, pArchivo);
    }
    fclose(pArchivo);
}

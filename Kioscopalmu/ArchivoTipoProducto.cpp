#include "ArchivoTipoProducto.h"
#include "TipoProducto.h"
#include <cstring>

ArchivoTipoProducto::ArchivoTipoProducto(const char* nombreArchivo){
    strcpy(_nombreArchivo, nombreArchivo);
}

bool ArchivoTipoProducto::Guardar(TipoProducto tipo){
    FILE *pArchivo = fopen(_nombreArchivo, "ab");
    if(pArchivo == NULL){
        return false;
    }
    bool ok = fwrite(&tipo, sizeof(TipoProducto), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

bool ArchivoTipoProducto::Guardar(TipoProducto tipo, int posicion){
    FILE *pArchivo = fopen(_nombreArchivo, "rb+");
    if(pArchivo == NULL){
        return false;
    }
    fseek(pArchivo, sizeof(TipoProducto) * posicion, SEEK_SET);
    bool ok = fwrite(&tipo, sizeof(TipoProducto), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

int ArchivoTipoProducto::Buscar(int idTipoProducto){
    FILE *pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == NULL){
        return -1;
    }
    TipoProducto tipo;
    int i = 0;
    while(fread(&tipo, sizeof(TipoProducto), 1, pArchivo)){
        if(tipo.getIdTipoProducto() == idTipoProducto){
            fclose(pArchivo);
            return i;
        }
        i++;
    }
    fclose(pArchivo);
    return -1;
}

TipoProducto ArchivoTipoProducto::Leer(int posicion){
    FILE *pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == NULL){
        return TipoProducto();
    }
    TipoProducto tipo;
    fseek(pArchivo, sizeof(TipoProducto) * posicion, SEEK_SET);
    fread(&tipo, sizeof(TipoProducto), 1, pArchivo);
    fclose(pArchivo);
    return tipo;
}

int ArchivoTipoProducto::CantidadRegistros(){
    FILE *pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == NULL){
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(TipoProducto);
    fclose(pArchivo);
    return cantidadRegistros;
}

void ArchivoTipoProducto::Leer(int cantidadRegistros, TipoProducto *vector){
    FILE *pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == NULL){
        return;
    }
    for(int i = 0; i < cantidadRegistros; i++){
        fread(&vector[i], sizeof(TipoProducto), 1, pArchivo);
    }
    fclose(pArchivo);
}

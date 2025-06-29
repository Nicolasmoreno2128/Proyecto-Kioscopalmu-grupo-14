#ifndef ARCHIVOTIPOPRODUCTO_H_INCLUDED
#define ARCHIVOTIPOPRODUCTO_H_INCLUDED
#include <cstdio>
#include "TipoProducto.h"

class ArchivoTipoProducto{
    private:
        char _nombreArchivo[100];

    public:
        ArchivoTipoProducto(const char* nombreArchivo);
        bool Guardar(TipoProducto tipo);
        bool Guardar(TipoProducto tipo, int posicion);
        int Buscar(int idTipoProducto);
        TipoProducto Leer(int posicion);
        int CantidadRegistros();
        void Leer(int cantidadRegistros, TipoProducto *vector);
        bool RealizarCopiaSeguridad(const char* nombreBackup = "tipos.bkp");
        bool RestaurarDesdeBackup(const char* nombreBackup = "tipos.bkp");
};
#endif // ARCHIVOTIPOPRODUCTO_H_INCLUDED

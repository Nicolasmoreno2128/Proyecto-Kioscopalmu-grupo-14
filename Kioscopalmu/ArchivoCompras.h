#ifndef ARCHIVOCOMPRAS_H_INCLUDED
#define ARCHIVOCOMPRAS_H_INCLUDED
#include <cstdio>
#include "Compras.h"

class ArchivoCompras{
    private:
        char _nombreArchivo[100];

    public:
        ArchivoCompras(const char* nombreArchivo);
        bool Guardar(Compras compra);
        bool Guardar(Compras compra, int posicion);
        int Buscar(int idCompra);
        Compras Leer(int posicion);
        int CantidadRegistros();
        void Leer(int cantidadRegistros, Compras *vector);

        // metodos especificos para compras
        int BuscarPorProducto(int nroProducto);
        int BuscarPorProveedor(const char* CUITproveedor);
        bool RealizarCopiaSeguridad(const char* nombreBackup = "compras.bkp");
        bool RestaurarDesdeBackup(const char* nombreBackup = "compras.bkp");
};
#endif // ARCHIVOCOMPRAS_H_INCLUDED

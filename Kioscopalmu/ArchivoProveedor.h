#include <cstdio>
#include "proveedor.h"

class ArchivoProveedor{
    private:
        char _nombreArchivo[100];

    public:
        ArchivoProveedor(const char* nombreArchivo);
        bool Guardar(proveedor prov);
        bool Guardar(proveedor prov, int posicion);
        int Buscar(int DNI);
        int BuscarPorCuit(const char* CUIT);
        proveedor Leer(int posicion);
        int CantidadRegistros();
        void Leer(int cantidadRegistros, proveedor *vector);
};

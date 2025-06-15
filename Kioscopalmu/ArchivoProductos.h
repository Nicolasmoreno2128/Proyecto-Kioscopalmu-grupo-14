#include <cstdio>
#include "Productos.h"

class ArchivoProductos{
    private:
        char _nombreArchivo[100];

    public:
        ArchivoProductos(const char* nombreArchivo);
        bool Guardar(Productos producto);
        bool Guardar(Productos producto, int posicion);
        int Buscar(int nroProducto);
        Productos Leer(int posicion);
        int CantidadRegistros();
        void Leer(int cantidadRegistros, Productos *vector);
};

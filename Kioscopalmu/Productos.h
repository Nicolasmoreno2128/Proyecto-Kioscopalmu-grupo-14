#ifndef PRODUCTOS_H_INCLUDED
#define PRODUCTOS_H_INCLUDED
#include <cstring>
using namespace std;

class Productos {

private:
    int nroProducto;
    char nombre[50];
    int idTipoProducto;
    float precio;
    int stock;

public:
    // Constructores
    Productos();
    Productos(int _nroProducto, const char* _nombre, int _idTipoProducto, float _precio, int _stock);

    // Metodos getter
    int getNroProducto();
    char* getNombre();
    int getIdTipoProducto();
    float getPrecio();
    int getStock();

    // Metodos setter
    void setNroProducto(int _nroProducto);
    void setNombre(const char* _nombre);
    void setIdTipoProducto(int _idTipoProducto);
    void setPrecio(float _precio);
    void setStock(int _stock);

    // Metodos adicionales
    void cargar();
    void mostrar();
    void altaProducto();
    void listarProductos();
    void buscarProductos();
    void cantidadProductos();
};

#endif // PRODUCTOS_H_INCLUDED

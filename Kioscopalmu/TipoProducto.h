#ifndef TIPOPRODUCTO_H_INCLUDED
#define TIPOPRODUCTO_H_INCLUDED
#include <cstring>
using namespace std;

class TipoProducto {

private:
    int idTipoProducto;
    char nombre[50];

public:
    // Constructores
    TipoProducto();
    TipoProducto(int _idTipoProducto, const char* _nombre);

    // Métodos getter
    int getIdTipoProducto();
    char* getNombre();

    // Métodos setter
    void setIdTipoProducto(int _idTipoProducto);
    void setNombre(const char* _nombre);

    // Métodos adicionales
    void cargar();
    void mostrar();

    //Metodos del Menu
    void agregarTipoProducto();
    void listarTipoProductos();
    void Buscarporidtp();
    void Cantidadregistrostp();

    // Validaciones
    void cargarDatosComplementarios();


};

#endif // TIPOPRODUCTO_H_INCLUDED

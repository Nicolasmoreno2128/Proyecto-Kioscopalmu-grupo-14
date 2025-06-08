#ifndef COMPRAS_H_INCLUDED
#define COMPRAS_H_INCLUDED
#include <string>
#include "Fecha.h"
using namespace std;

class Compras {

private:
    int idCompra;
    int nroProducto;
    int CUITproveedor;
    Fecha fecha;
    int cantidad;
    float importe;

public:
    // Constructores
    Compras();
    Compras(int _idCompra, int _nroProducto, int _CUITproveedor, Fecha _fecha, int _cantidad, float _importe);

    // Métodos getter
    int getIdCompra();
    int getNroProducto();
    int getCUITproveedor();
    Fecha getFecha();
    int getCantidad();
    float getImporte();

    // Métodos setter
    void setIdCompra(int _idCompra);
    void setNroProducto(int _nroProducto);
    void setCUITproveedor(int _CUITproveedor);
    void setFecha(Fecha _fecha);
    void setCantidad(int _cantidad);
    void setImporte(float _importe);

    // Métodos adicionales
    void cargar();
    void mostrar();
};

#endif // COMPRAS_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include "proveedor.h"

proveedor :: proveedor()
{

    Dni=0;
    Cuit=0;
    telefono=0;
    nombre="";
    email="";
    direccion="";

}

proveedor :: proveedor(int _Dni, int _Cuit, int _telefono, string _nombre, string _email, string _direccion)
{

    Dni=_Dni;
    Cuit=_Cuit;
    telefono=_telefono;
    nombre=_nombre;
    email=_email;
    direccion=_direccion;

}

int proveedor :: getDni()
{
    return Dni;
}

int proveedor :: getCuit()
{
    return Cuit;
}

int proveedor :: gettelefono()
{
    return telefono;
}

string proveedor::getnombre()
{
    return nombre;
}
string proveedor::getemail()
{
    return email;
}

string proveedor::getdireccion()
{
    return direccion;
}


void  proveedor::setDni(int _Dni)
{
    Dni= _Dni;
}

void  proveedor::setCuit(int _Cuit)
{
    Cuit= _Cuit;
}

void  proveedor::settelefono(int _telefono)
{
    telefono= _telefono;
}

void proveedor::setnombre(string _nombre)
{
    nombre=_nombre;
}
void proveedor::setemail  (string _email)
{
    email=_email;
}
void proveedor::setdireccion(string _direccion)
{
    direccion=_direccion;
}


/*
void proveedor::mostrar() {
    cout << "DNI: " << Dni << endl;
    cout << "CUIT: " << Cuit << endl;
    cout << "Telefono: " << telefono << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Email: " << email << endl;
    cout << "Direccion: " << direccion << endl;
}
*/


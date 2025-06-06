#ifndef PROVEEDOR_H_INCLUDED
#define PROVEEDOR_H_INCLUDED
#include <string>
using namespace std;

class proveedor {

     private:
        int Dni, Cuit, telefono;
        char nombre[20], email[20], direccion[20];


    public:

        proveedor();
        proveedor (int _Dni,int _Cuit,int _telefono,const char* _nombre,const char*_email,const char*_direccion);
        //void mostrar();

        int getDni();
        int getCuit();
        int gettelefono();
        const char* getnombre();
        const char* getemail();
        const char* getdireccion();



        int setDni(int _dni);
        int setCuit(int _Cuit);
        int settelefono(int _telefono);
        const char* setnombre(const char* _nombre);
        const char* setemail(const char* _mail);
        const char* setdireccion(const char* _direccion);

};

#endif // PROVEEDOR_H_INCLUDED

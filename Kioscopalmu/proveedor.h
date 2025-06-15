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



        void setDni(int _dni);
        void setCuit(int _Cuit);
        void settelefono(int _telefono);
        void setnombre(const char* _nombre);
        void setemail(const char* _mail);
        void setdireccion(const char* _direccion);

        void cargar();
        void mostrar();

};

#endif // PROVEEDOR_H_INCLUDED

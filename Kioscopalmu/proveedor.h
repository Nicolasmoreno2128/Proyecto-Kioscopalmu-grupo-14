#ifndef PROVEEDOR_H_INCLUDED
#define PROVEEDOR_H_INCLUDED
#include <string>
using namespace std;

class proveedor {

     private:
        int Dni, telefono;
        char Cuit[20], nombre[20], email[20], direccion[20];


    public:

        proveedor();
        proveedor (int _Dni,int _telefono, const char* _Cuit,const char* _nombre,const char*_email,const char*_direccion);
        //void mostrar();

        int getDni();
        int gettelefono();
        const char* getCuit();
        const char* getnombre();
        const char* getemail();
        const char* getdireccion();



        void setDni(int _dni);
        void settelefono(int _telefono);
        void setCuit(const char* _Cuit);
        void setnombre(const char* _nombre);
        void setemail(const char* _mail);
        void setdireccion(const char* _direccion);

        void cargar();
        void mostrar();
        void altaProveedor();
        void listarProveedores();
        void buscarProveedoresDNI();
        void buscarProveedoresCUIT();
        void CantidadProveedores();

};

#endif // PROVEEDOR_H_INCLUDED

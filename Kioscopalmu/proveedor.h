#ifndef PROVEEDOR_H_INCLUDED
#define PROVEEDOR_H_INCLUDED
#include <string>
using namespace std;

class proveedor {

     private:
        int Dni, Cuit, telefono;
        string nombre, email, direccion;


    public:

        proveedor();
        proveedor (int _Dni,int _Cuit,int _telefono,string _nombre,string _email,string _direccion);
        //void mostrar();

        int getDni();
        int getCuit();
        int gettelefono();
        string getnombre();
        string getemail();
        string getdireccion();



        void setDni(int _dni);
        void setCuit(int _Cuit);
        void settelefono(int _telefono);
        void setnombre(string _nombre);
        void setemail(string _mail);
        void setdireccion(string _direccion);




};

#endif // PROVEEDOR_H_INCLUDED

#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

using namespace std;

class Fecha{
private:
    int dia,mes, anio;
public:
    Fecha(int d, int m, int a) {
    dia = d;
    mes = m;
    anio = a;
}
    //CONSTRUCTOR SIN PARAMETROS
    Fecha() : dia(1), mes(1), anio(2025) {}

    void Cargar(){
        cout<<"DIA ";cin>>dia;
        cout<<"MES ";cin>>mes;
        cout<<"ANIO ";cin>>anio;
    }
    void Mostrar(){
        cout<<dia<<"/";
        cout<<mes<<"/";
        cout<<anio<<endl;
    }
    int getDia(){return dia;}
    int getMes(){return mes;}
    int getAnio(){return anio;}

    void setDia(int d){dia=d;}
    void setMes(int m){mes=m;}
    void setAnio(int a){anio=a;}
    std::string toString();

};

#endif // FECHA_H_INCLUDED

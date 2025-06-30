#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
#include <iostream>
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
// D�a
    do {
        cout << "DIA (1-31): ";
        cin >> dia;
        if (cin.fail() || dia < 1 || dia > 31) {
            cout << "D�a inv�lido. Ingrese un n�mero entre 1 y 31.\n";
            cin.clear();
            cin.ignore(1000, '\n');
        } else break;
    } while (true);

    // Mes
    do {
        cout << "MES (1-12): ";
        cin >> mes;
        if (cin.fail() || mes < 1 || mes > 12) {
            cout << "Mes inv�lido. Ingrese un n�mero entre 1 y 12.\n";
            cin.clear();
            cin.ignore(1000, '\n');
        } else break;
    } while (true);

    // A�o
    do {
        cout << "A�O (2000-2100): ";
        cin >> anio;
        if (cin.fail() || anio < 2000 || anio > 2100) {
            cout << "A�o inv�lido. Ingrese un n�mero entre 2000 y 2100.\n";
            cin.clear();
            cin.ignore(1000, '\n');
        } else break;
    } while (true);
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

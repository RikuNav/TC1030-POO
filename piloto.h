

/*
*Ricardo Navarro Gómez A01708825
*TC1030 POO
*Profesor: Benjamín Valdés Aguirre
*Proyecto: Batallas de Evas
*Version: 2
*
*Este archivo define la clase Piloto, la cual tiene una relacion de
*agregacion con la clase Eva; dentro de la misma tiene parametros de identificacion
*como el nombre, pero a la par tendra la vida (la cual se vera afectada por las acciones
*del Eva), al igual que la estabilidad, la cual determinara el atributo de sincronizacion
*del Eva
*/

#ifndef PILOTO_H_INCLUDED
#define PILOTO_H_INCLUDED

#include <iostream>

using namespace std;

class Piloto{

//declaro los atributos privados
private:
    string nombre_piloto;
    int vida_piloto;
    int estabilidad_pil;

//declaro los constructores y metodos publicos
public:
    Piloto():nombre_piloto("---"),vida_piloto(0),estabilidad_pil(0){}; //constructor por default
    Piloto(string nom): nombre_piloto(nom), vida_piloto(500),estabilidad_pil(100){};

    int getEstab_pil(){return estabilidad_pil;}
    string getPiloto(){return nombre_piloto;}

    void imprimePiloto();
    void reduceVida(int life){vida_piloto = vida_piloto - life;} //metodo para el calculo de la vida del piloto luego de un ataque
    void reduceEstabilidad(int est) {estabilidad_pil = estabilidad_pil - est;}
    void aumentaEstabilidad(int);
};

/**
*imprimePiloto imprime la informacion del piloto
*
*@param
*@return
*/
void Piloto::imprimePiloto(){
    cout << "\nInformacion del piloto\n\n";
    cout << "El nombre del piloto encargado es: " << nombre_piloto << "\n";
    cout << nombre_piloto << " tiene " << vida_piloto << " puntos de vida\n";
    cout << "Su estabilidad mental es de " << estabilidad_pil << "%\n\n";
}

/**
*aumentaEstabilidad aumenta el atributo de estabilidad del piloto,
*en caso de ser este mayor a 100, se establece automaticamente como 100
*
*@param int con el valor de aumento de estabilidad
*@return
*/
void Piloto::aumentaEstabilidad(int est){
    estabilidad_pil = estabilidad_pil + est;
    if(estabilidad_pil >= 100){
        estabilidad_pil = 100;
    }
}


#endif // PILOTO_H_INCLUDED

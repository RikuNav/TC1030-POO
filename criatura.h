

/*
*Ricardo Navarro Gómez A01708825
*TC1030 POO
*Profesor: Benjamín Valdés Aguirre
*Proyecto: Batallas de Evas
*
*version: 5
*
*Este archivo define la clase Criatura, que contiene a las clases
*heredadas Eva y Angel
*/

#ifndef CRIATURA_H_INCLUDED
#define CRIATURA_H_INCLUDED

#include <iostream>
#include <time.h>
#include <stdlib.h>

#include "piloto.h" //archivo el cual contiene la clase piloto

using namespace std;

class Criatura{

//declaro los atributos protegidos
protected:
    string nombre;
    int vida;
    int id;
    int estatus;

//declaro constructores y metodos publicos
public:

    Criatura():nombre("---"), vida(0), id(00), estatus(1){}; //contructor por default
    Criatura(string nom, int vi, int i, int est): nombre(nom), vida(vi), id(i), estatus(est){}; //constructor 1
    Criatura(string nom, int vi): nombre(nom), vida(vi), id(00), estatus(1){}; //constructor 2

    string getNombre() {return nombre;}
    int getEstatus() {return estatus;}
    int getVida() {return vida;}

    void setEstatus(int estat) {estatus = estat;}
    void setVida(int life) {vida = life;}
    void defensa(){estatus = 0;}

    //Defino los metodos abstractos que seran sobreescritos
    virtual void imprimeInfo() = 0;

};

//Declaro la clase Angel, la cual hereda de Criatura
class Angel:public Criatura{

//declaro los atributos privados
private:
    string habilidades[4];
public:
    Angel():Criatura(),habilidades{"punos", "---", "---", "---"}{}; //constructor por default
    Angel(string nom):Criatura(nom,9000 + rand()%(10001 - 7000)),habilidades{"punios", "---", "---", "---"}{};

    void imprimeInfo(); //metodo sobreescrito
};

/**
*imprimeInfo imprime toda la información que tiene el angel,
*al estar sobreescrita, y heredar los atributos de Criatura, también
*imprimirá dicha información, ya que a fin de cuentas también pertenece a la información
*de el propio angel
*
*@param
*@return
*/
void Angel::imprimeInfo(){
    cout << "El angel es el numero " << nombre << endl;
    cout << "La vida que tiene actualmente es de: " << vida << endl;
    cout << "Su ID de reconocimiento es: " << id << endl;
    if (estatus == 0){
        cout << "Actualmente se encuentra en posicion de defensa, por lo que los ataques son menos efectivos" << endl;
    }
    else if (estatus == 1){
        cout << "Actualmente se encuentra en posicion de reposo, por lo que los ataques seran mediantemanete efectivos" << endl;
    }
    else{
        cout << "Actualmente esta en posicion de ataque, y es mas vulnerable a los ataques" << endl;
    }
    cout << "Sus habilidades son: " << endl;
    for (int i = 0; i < 4; i++){
        cout << i + 1 << ". " << habilidades[i] << endl;
    }
    cout << "\n-------------------------------------------" << endl;
}

//Declaro la clase Eva, la cual herada de Criatura
class Eva:public Criatura{

//Defino mis atributos privados
private:
    Piloto* pil; //Es el piloto que esta con agregacion, es un apuntador
    string armas[3];
    bool conector;
    int carga;
    int sincronizacion;

//declaro los constructores y metodos publicos
public:
    Eva(Piloto* pilot):Criatura(), pil(pilot), armas{"punios", "---", "---"},conector(false),carga(0),sincronizacion(0) {}; //constructor por default
    Eva(string nom, Piloto* pilot):Criatura(nom, 2000 + rand()%(4001 - 2000)),
    pil(pilot), armas{"punios", "---", "---"},conector(true),carga(100),sincronizacion(100) {};//constructor 1

    string getNomPiloto() {return pil->getPiloto();}
    int getSincro() {return sincronizacion;}

    void imprimeInfo(); //metodo sobreescrito
    void desincronizacion(int);
    void aumentaSincro(int);
};

/**
*imprimeInfo imprime la informacion de el
*eva, con los atributos originales de la clase, como aquellos que
*han sido heredados
*
*@param
*@return
*/
void Eva::imprimeInfo(){
    cout << "Informe del " << nombre << "\n\n" ;
    cout << "Numero de la unidad: " << nombre << endl;
    cout << "Tiene " << vida << " puntos de vida\n";
    cout << "Su ID es: " << id << endl;

    //imprime una condicion especifica en caso de que el conector este o no en el eva
    if (conector == true){
        cout << "El Eva esta conectado, por lo que no esta utilizando su bateria interna\n";
        cout << "Su bateria interna se encuentra al " << carga << "%\n";
    }
    else{
        cout << "El Eva no esta conectado, por lo que esta utilizando su bateria interna\n";
        cout << "Le queda " << carga << "% de la bateria interna\n";
    }

    //imprime una frase de acuerdo a que estatus de posicion tiene declarado
    if (estatus == 0){
        cout << "Actualmente se encuentra en posicion de defensa, por lo que los ataques son menos efectivos" << endl;
    }
    else if (estatus == 1){
        cout << "Actualmente se encuentra en posicion de reposo, por lo que los ataques seran mediantemanete efectivos" << endl;
    }
    else{
        cout << "Actualmente esta en posicion de ataque, y es mas vulnerable a los ataques" << endl;
    }

    cout << "Sus habilidades son: " << endl; //imprimo el arreglo de las habilidades
    for (int i = 0; i < 3; i++){
        cout << i + 1 << ". " << armas[i] << endl;
    }
    pil->imprimePiloto(); //instruccion a puntero para llevar a cabo la funcion correspondiente
    cout << "La sincronizacion entre el piloto y el Eva es del " << sincronizacion << "%";
    cout << "\n\n-------------------------------------------" << endl;

}

/**
*desincronizacion hace un calculo aleatorio de la sincronizacion entre
*el Eva y el piloto, por lo que dependerá el marco en el cual se generará
*el numero aleatorio de acuerdo al parametro de estabilidad mental del piloto del eva,
*el cual dentro del metodo va a disminuir
*
*@param int con la cantidad de daño que recibirá el piloto en su estabilidad
*@return
*/
void Eva::desincronizacion(int dano){
    pil->reduceEstabilidad(dano);
    srand(time(NULL));
    if (pil->getEstab_pil() >= 75){
        sincronizacion = 61 + rand()%(94 - 61);
    }
    else if (pil->getEstab_pil() <= 75 && pil->getEstab_pil() >= 25){
        sincronizacion = 31 + rand()%(61 - 31);
    }
    else{
        sincronizacion = 1 + rand()%(31 - 1);
    }
}

/**
*aumentaSincro aumenta la sincronizacion de manera aleatoria entre el Eva y su piloto, por
*lo que para definir sus paramentros del numero random, se debera de consultar el atributo
*de estabilidad mental del piloto, el cual dentro del metodo tambien aumentara
*
*@param int con el aumento que tendra el atributo de estabilidad mental del piloto
*@return
*/
void Eva::aumentaSincro(int aumento){
    pil->aumentaEstabilidad(aumento);
    srand(time(NULL));
    if (pil->getEstab_pil() >= 75){
        sincronizacion = 61 + rand()%(94 - 61);
    }
    else if (pil->getEstab_pil() <= 75 && pil->getEstab_pil() >= 25){
        sincronizacion = 31 + rand()%(61 - 31);
    }
    else{
        sincronizacion = 1 + rand()%(31 - 1);
    }
}

#endif // CRIATURA_H_INCLUDED

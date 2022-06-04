

/*
Ricardo Navarro Gómez A01708825
TC1030 POO
Profesor: Benjamín Valdés Aguirre
Proyecto: Batallas de Evas

version: 2

Este archivo define la clase Criatura, que contiene a las clases
heredadas Eva y Angel
*/

#ifndef CRIATURA_H_INCLUDED
#define CRIATURA_H_INCLUDED

#include <iostream>

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
    Criatura(string nom): nombre(nom), vida(4000), id(00), estatus(1){}; //constructor 2

    int getEstatus(){return estatus;}
    void setEstatus(int estat){estatus = estat;}
    void setVida(int life) {vida = life;}
    void defensa(){estatus = 0;}

    //Defino los metodos abstractos que seran sobreescritos
    virtual void imprimeInfo(){};
    virtual void atacar(){}; //aun no esta terminado el polimorfismo de este metodo

};

//Declaro la clase Angel, la cual hereda de Criatura
class Angel:public Criatura{

//declaro los atributos privados
private:
    string habilidades[4];
public:
    Angel():Criatura(),habilidades{"punos", "---", "---", "---"}{}; //constructor por default
    Angel(string nom):Criatura(nom),habilidades{"punios", "---", "---", "---"}{};

    void imprimeInfo(); //metodo sobreescrito
    //void atacar(eva&); Método dentro del codigo el cual aun no sirve
};

/*
imprimeInfo imprime toda la información que tiene el angel,
al estar sobreescrita, y heredar los atributos de Criatura, también
imprimirá dicha información, ya que a fin de cuentas también pertenece a la información
de el propio angel

No recibe ni regresa ningun tipo de dato
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
        cout << "Actualmente esta en posicion de ataque, y es mas vulnerable a los ataques ataques" << endl;
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
    int armadura;
    string armas[3];
    bool conector;
    int carga;
    int sincronizacion;

//declaro los constructores y metodos publicos
public:
    Eva(Piloto* pilot):Criatura(), pil(pilot), armadura(0), armas{"punios", "---", "---"},conector(false),carga(0),sincronizacion(0) {}; //constructor por default
    Eva(string nom, Piloto* pilot):Criatura(nom), pil(pilot), armadura(100), armas{"punios", "---", "---"},conector(true),carga(100),sincronizacion(100) {};

    void imprimeInfo(); //metodo sobreescrito
    //void atacar(Angel*); Un metodo el cual hasta el momento no sirve, por eso anulo el método por ahora
};

/*
imprimeInfo imprime la informacion de el
eva, con los atributos originales de la clase, como aquellos que
han sido heredados

No recibe ningun parametro, y no regresa ningun valor
*/
void Eva::imprimeInfo(){
    cout << "Informe del " << nombre << "\n\n" ;
    cout << "Numero de la unidad: " << nombre << endl;
    cout << "Tiene " << vida << " puntos de vida\n";
    cout << "Su ID es: " << id << endl;
    cout << "Su armadura tiene una integridad del: " << armadura << "%\n";

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
        cout << "Actualmente esta en posicion de ataque, y es mas vulnerable a los ataques ataques" << endl;
    }

    cout << "Sus habilidades son: " << endl; //imprimo el arreglo de las habilidades
    for (int i = 0; i < 3; i++){
        cout << i + 1 << ". " << armas[i] << endl;
    }
    pil->imprimePiloto(); //instruccion a puntero para llevar a cabo la funcion correspondiente
    cout << "La sincronizacion entre el piloto y el Eva es del " << sincronizacion << "%";
    cout << "\n\n-------------------------------------------" << endl;

}


/* Sección del código la cual no está terminada y aun no sirve
void Eva::atacar(Angel* ang){
    cout << "Hasta aqui jala tu código\n";
    cout << "Su vida es: " << ang->getEstatus() << "\n";
    cout << "Si te sirvio?\n";
}
*/
#endif // CRIATURA_H_INCLUDED

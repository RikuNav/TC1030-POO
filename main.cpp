

/*
*Ricardo Navarro Gómez A01708825
*TC1030 POO
*Profesor: Benjamín Valdés Aguirre
*Proyecto: Batallas de Evas
*Version: 4
*
*Este es el proyecto de la clase TC1030. Es un programa
*el cual simula un videojuego de peleas de el anime de Evangelion,
*donde habrá un Angel que derrotar y varios Evas a tu disposicion;
*deberas de tomar en cuenta el escenario, las armas y otros atributos si
*quieres derrotar al Angel
*/

#include <iostream> //para poder imprimir dentro de el codigo

#include <time.h>

#include <stdlib.h>

#include "criatura.h" //archivos con mis clases y objetos declarados

#include "piloto.h"

#include "combate.h"

using namespace std;

int menu();

int main(){

    Combate lista;

    const int n = 20;
    int uni;
    int eleccion = 0;
    int angel;

    Criatura* cria[n];


    Piloto* pi01 = new Piloto("Rei");
    Piloto* pi02 = new Piloto("Shinji");
    Piloto* pi03 = new Piloto("Akaza");

    int c = 0;
    cria[c] = new Angel("1");
    c++;
    cria[c] = new Eva("Eva 00", pi01);
    c++;
    cria[c] = new Eva("Eva 01", pi02);
    c++;
    cria[c] = new Eva("Eva 02", pi03);

    lista.agregaAngel(cria[0]);
    for (int i = 1; i < 4; i++){
        lista.agregaEva(cria[i]);
    }

    cout << "\nBienvenido al simulador de Batallas entre Evas y Angeles\n";
    cout << "Su mision es controlar los distintos Eva, con el fin de derrotar al objetivo\n";
    cout << "Esto evidentemente antes de que uno de los Evas sea destruido\n";
    cout << "A continuacion se despliegan los datos del campo de Batalla\n\n";

    lista.imprimeAngel();
    lista.imprimeEva();

    srand(time(NULL));

    do{
        eleccion = menu();
        if (eleccion == 1){
            cout << "\nIngrese la unidad que quiere que ataque\n";
            cout << "Eva 0";
            cin >> uni;

            lista.ataque(uni);

            angel = rand()%(3);
            if(angel == 0){
                cout << "\nEl angel permanece inmovil\n";
            }
            else if(angel == 1){
                cout << "\nEl angel se coloca en posicion de defensa\n";
                lista.defensa(0);
            }
            else if(angel == 2){
                lista.ataqueAngel();
            }
        }
        else if (eleccion == 2){
            cout << "\nIngrese la unidad que quiere que se ponga en posision de defensa\n";
            cout << "Eva 0";
            cin >> uni;
            uni++;

            lista.defensa(uni);

            angel = rand()%(3);
            if(angel == 0){
                cout << "\nEl angel permanece inmovil\n";
            }
            else if(angel == 1){
                cout << "\nEl angel se coloca en posicion de defensa\n";
                lista.defensa(0);
            }
            else if(angel == 2){
                lista.ataqueAngel();
            }
        }
        else if (eleccion == 3){
            lista.imprimeAngel();
            lista.imprimeEva();
        }

        if (cria[0]->getVida() <= 0){
            cout << "\nFelicidades soldado, has logrado terminar con la vida del Angel\n";
            eleccion = 4;
        }
        else if (cria[1]->getVida() <= 0 || cria[2]->getVida() <= 0 || cria[3]->getVida() <= 0){
            cout << "\nHas fracasado en tu mision de proteger a la humanidad\n";
            eleccion = 4;
        }


    }
    while(eleccion != 4);

    cout << "\nGracias por participar.\n";
    return 0;
}

/**
*menu es una funcion la cual despliega el menu al usuario para
*que elija que accion llevar dentro de el programa
*
*@param
*@return int con el valor de la eleccion del usuario
*/
int menu(){
    int eleccion = 5;
    while(eleccion >= 5){
        cout << "\nPor favor, elija una de las siguientes opciones:\n\n";
        cout << "1.- Atacar\n";
        cout << "2.- Posicion de defensa\n";
        cout << "3.- Desplegar informacion del campo de batallas\n";
        cout << "4.- Salir\n\n";
        cout << "No. de Eleccion: ";
        cin >> eleccion;
    }
    return eleccion;
}



/*
Ricardo Navarro Gómez A01708825
TC1030 POO
Profesor: Benjamín Valdés Aguirre
Proyecto: Batallas de Evas
Version: 2

Este es el proyecto de la clase TC1030. Es un programa
el cual simula un videojuego de peleas de el anime de Evangelion,
donde habrá un Angel que derrotar y varios Evas a tu disposicion;
deberas de tomar en cuenta el escenario, las armas y otros atributos si
quieres derrotar al Angel
*/

#include <iostream> //para poder imprimir dentro de el codigo

#include "criatura.h" //archivos con mis clases y objetos declarados

#include "piloto.h"

#include "combate.h"

using namespace std;

int main(){

    Combate lista;
    lista.generaLista();
    lista.imprime();

    Combate lista2;

    const int n = 20;

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

    lista2.agregaAngel(cria[0]);
    lista2.imprimeAngel();

    cout << pi01 << '\n';

    cout << "?" << cria[0] << '\n';

    /*
    for (int i = 0; i < 4; i++){
        cria[i]->imprimeInfo();
        cout << endl << endl;
    }


    cria[1]->atacar(cria[0]); Esta parte del codigo aun no sirve del todo
    cout << cria[0];
    */

    return 0;
}

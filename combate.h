
/*
Ricardo Navarro Gómez A01708825
TC1030 POO
Profesor: Benjamín Valdés Aguirre
Proyecto: Batallas de Evas

version: 2

Este archivo define la clase Combate que contienen a todos los evas y angeles, y será donde
se llevarán a cabo los ataques y reducciones de vida
*/

#ifndef COMBATE_H_INCLUDED
#define COMBATE_H_INCLUDED

#include <iostream>

#include<time.h> //incluyo las librerias que me ayudarán con los numeros aleatorios

#include <stdlib.h>

#include "piloto.h"

#include "criatura.h"

class Combate{
private:
    Criatura* cria[20];
    int c;
public:
    Combate(): c(0){};

    void agregaAngel(Criatura*);
    void agregaEva(Criatura*);
    void imprime();
    void imprimeAngel();
    void imprimeEva();


    void ataque(int);
    void ataqueAngel();

    void defensa(int);
};


void Combate::imprime(){
    for (int i = 0; i < 4; i++){
        cria[i]->imprimeInfo();
        cout << endl << endl;
    }
}

void Combate::agregaAngel(Criatura* ang){
    cria[0] = ang;
    c++;
}

void Combate::agregaEva(Criatura* ev){
    cria[c] = ev;
    c++;
}

void Combate::imprimeAngel(){
    cria[0]->imprimeInfo();
}

void Combate::imprimeEva(){
    for (int i = 1; i < 4; i++){
        cria[i]->imprimeInfo();
        cout << endl << endl;
    }
}

void Combate::ataque(int id){
    id++;
    int ata, dio;
    srand(time(NULL));
    dio = rand()%(2);
    cout << "El " << cria[id]->getNombre() << " ha recibido la instruccion de atacar\n";
    if (((Eva*)cria[id])->getSincro() >= 30){
        if (cria[id]->getEstatus() == 0){
            cout << "El Eva al recibir la instruccion de atacar, dejo de estar defendiendose y se puso en posicion de ataque\n";
        }
        else if (cria[id]->getEstatus() == 1) {
            cout << "El Eva al recibir la instruccion de atacar, dejo de estar en reposo y se puso en posicion de ataque\n";
        }
        else{
            cout << "El Eva se prepara para atacar";
        }
        if (dio == 0){
            cout << "\nEl Angel " << cria[0]->getNombre() << " esquivo el ataque y resulto ileso\n";
        }
        else{
            if (cria[0]->getEstatus() == 0){
                ata = 200 + rand()%(1201 - 200);
            }
            else if (cria[0]->getEstatus() == 1){
                ata = 400 + rand()%(1801 - 400);
            }
            else{
                ata = 700 + rand()%(2401 - 700);
            }
            cria[0]->setVida(cria[0]->getVida() - ata);
            cout << "\nEl ataque del Eva 0" << id - 1 << " fue exitoso, y le quito " << ata << " puntos de vida al Angel " << cria[0]->getNombre() << '\n';
            ((Eva*)cria[id])->aumentaSincro(10 + rand()%(21 - 10));
            cout << "Al acertar el ataque, la estabilidad mental del Piloto " << ((Eva *)cria[id])->getNomPiloto() << " aumento, y por ende tambien su sincronizacion con el Eva\n";
        }
        cria[id]->setEstatus(2);
    }
    else {
        cout << "El Eva es incapaz de moverse a causa de la baja sincronizacion con su piloto";
    }
    cout << "\nDespues del ultimo movimiento, los datos de Angel quedaron de la siguiente manera\n";
    cria[0]->imprimeInfo();


    cout << "\nPor otro lado, los datos del " << cria[id]->getNombre() << " quedaron de la siguiente manera\n\n";
    cria[id]->imprimeInfo();
}

void Combate::ataqueAngel(){
    int ata, ev, dio;
    srand(time(NULL));
    ev = 1 + rand()%(4 - 1);
    cout << "El angel ataco al Eva 0" << ev - 1 << "\n\n" ;
    dio = rand()%(2);
    if (((Eva*)cria[ev])->getSincro() >= 50){
        if (dio == 0){
            cout << "El Eva 0" << ev - 1 << " esquivo el ataque y resulto ileso\n\n";
        }
        else{
            cout << "El ataque fue exitoso e impacto al Eva 0" << ev - 1 << "\n\n";
            if (cria[ev]->getEstatus() == 0){
                ata = 200 + rand()%(401 - 200);
                cria[ev]->setVida(cria[ev]->getVida() - ata);
            }
            else if (cria[ev]->getEstatus() == 1){
                ata = 400 + rand()%(601 - 400);
                cria[ev]->setVida(cria[ev]->getVida() - ata);
            }
            else{
                ata = 700 + rand()%(1201 - 700);
                cria[ev]->setVida(cria[ev]->getVida() - ata);
            }
            cout << "El ataque le quito " << ata << " puntos de vida" << '\n';
        }
    }
    else{
        cria[ev]->setEstatus(2);
        cout << "Al ser tan baja la sincronizacion entre el piloto y el " << ((Eva*)cria[ev])->getNombre() << " el Eva no se pudo mover ni defender, por lo que el impacto dio de lleno\n";
        ata = 1200 + rand()%(1701 - 1200);
        cria[ev]->setVida(cria[ev]->getVida() - ata);
        cout << "El ataque le quito " << ata << " puntos de vida" << '\n';
    }

    cout << "\nDespues del ataque, el angel se quedo en posicion de ataque\n";
    cria[0]->setEstatus(2);
    cout << "\nEl piloto " << ((Eva *)cria[ev])->getNomPiloto() << " al haber sido objetivo de un ataque, se vio afectado en su estabilidad mental\n";
    cout << "Por ende, la sincronizacion entre Eva y el Piloto se redujo\n";
    ((Eva*)cria[ev])->desincronizacion(20);
    cout << "\nDespues del ataque, la informacion del Eva quedo de la siguiente manera\n\n";
    cria[ev]->imprimeInfo();
}

void Combate::defensa(int id){
    cria[id]->defensa();
    cout << "\nInformacion actualizada\n";
}

#endif // COMBATE_H_INCLUDED

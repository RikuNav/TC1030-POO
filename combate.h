
/*
Ricardo Navarro Gómez A01708825
TC1030 POO
Profesor: Benjamín Valdés Aguirre
Proyecto: Batallas de Evas

version: 1

Este archivo define la clase Combate que contienen a todos los evas y angeles, y será donde
se llevarán a cabo los ataques y reducciones de vida
*/

#ifndef COMBATE_H_INCLUDED
#define COMBATE_H_INCLUDED

#include <iostream>

#include "piloto.h"

#include "criatura.h"

class Combate{
private:
    Criatura* cria[20];
    int c;
public:
    Combate(): c(0){};

    void generaLista();

    void agregaAngel(Criatura*);
    void agregaEva(Criatura*);
    void imprime();
    void imprimeAngel();
    void imprimeEva();


    void ataque(int);
    void ataqueAngel();
};

void Combate::generaLista(){
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
}

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
/*
void Combate::ataque(int id){
    id++;



}

void Combate::ataqueEva(){

}

void Combate::ataque(int)

void Combate::agregaAngel(Angel& ang){
    cria[0] = &ang;
    c++;
}

void Combate::agregaEva(Eva& temp){
    cria[c] = &temp ;
    c++;
}
*/

#endif // COMBATE_H_INCLUDED

#ifndef CRIATURA_H_INCLUDED
#define CRIATURA_H_INCLUDED

/*Ricardo Navarro G�mez A01708825
TC1030 POO
Profesor: Benjam�n Vald�s Aguirre
Proyecto: Batallas de Evas
*/

#include <iostream>

using namespace std;

//defino la clase padre, la cual ser� la clase criatura
class criatura{
//defino los atributos que tendr� mi clase, para ello lo har� protegido
//son protegidos para que nadie fuera de las clases y subclases pueda acceder, pero que tambi�n tengan acceso
//las subclases
protected:
    string nombre;
    int vida;
    int id;
    int estatus;

    //defino el m�todo que me interesa que lo hereden las subclases hijo
    //se define sin ninguna instrucci�n dentro ya que me interesa que cada uno lo sobreescriba
    void imprimeInfo(){};
//ahora defino los m�todos que tendr� la clase
public:
    //primero defino los constructores
    //en origen ser� el constructor por default
    criatura():nombre("---"), vida(0), id(00), estatus(0);

    //ahora defino el constructor en caso de que se den par�metros completos
    criatura(string nom, int vid, int i, int est): nombre(nom), vida(vid), id(i), estatus(est);

    //defino ahora aquellos m�todos que no cambiar�n para cada uno de las subclases, pero que se que cada una
    //las necesita, por lo que se heredaran
    void defensa(){est = 0};
    void atacar(int){};

};


/*Aqu� empiezo a definir una de las subclases que saldr�n de la clase criatura. Para ello, heredo los atributos y m�todos
que defin� anteriormente*/
class angel:public criatura{

//defino los atributos que ser�n �nicos para esta clase, aparte de los que ya se hab�an heredado
//en este caso ser�n del tipo privado, ya que no quiero que nadie fuera de la clase lo pueda cambiar ni afectar
private:
    string habilidades[4];

//ahora debo de definir los nuevos m�todos que tendr� esta clase
//dichos m�todos ser�n p�blicos.
public:

    //primero definir� los nuevos constructores, empezando por el de default.
    //para ello utilizar� el constructor por default heredado
    angel(){criatura();habilidades[1] = "punos";}

    /*Ahora defino aquellos constructores los cuales recibir�n par�metros.
    Aqu� ahora utilizar� la sobrecarga, donde tendr� el caso donde el �ngel no tenga ninguna habilidad
    especial asignada, a la par que tengo el caso donde si se le asigna. Aqu� tendr�amos el ejemplo de la sobrecarga.*/
    angel(string nom, int vid, int i, int est){criatura(nom, vid, i, est); habilidades[1] = "punos";}
    angel(string nom, int vid, int i, int est, string hab){criatura(nom, vid, i, est);habilidades[1] = hab;}

    //finalmente sobreescribo mi nuevo m�todo de imprimeInfo, donde ahora imprimir� cierta
    //informaci�n espec�fica de su clase.
    void imprimeInfo(){
        cout << nombre << endl;
        cout << vida << endl;
        cout << id << endl;
        cout << estatus << endl;
        //establezco el for ya que el atributo habilidades es un arreglo, por lo que podr� tener m�s que una.
        for (int i = 1; i = sizeof(habilidades), i++){
            cout << habilidades[i] << endl;
        }
    };

    //finalmente establezco mi �ltimo m�todo, el cual es �nico para esta clase.
    void destruir(){vida = 0;}

};

#endif // CRIATURA_H_INCLUDED

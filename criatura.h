#ifndef CRIATURA_H_INCLUDED
#define CRIATURA_H_INCLUDED

/*Ricardo Navarro Gómez A01708825
TC1030 POO
Profesor: Benjamín Valdés Aguirre
Proyecto: Batallas de Evas
*/

#include <iostream>

using namespace std;

//defino la clase padre, la cual será la clase criatura
class criatura{
//defino los atributos que tendrá mi clase, para ello lo haré protegido
//son protegidos para que nadie fuera de las clases y subclases pueda acceder, pero que también tengan acceso
//las subclases
protected:
    string nombre;
    int vida;
    int id;
    int estatus;

    //defino el método que me interesa que lo hereden las subclases hijo
    //se define sin ninguna instrucción dentro ya que me interesa que cada uno lo sobreescriba
    void imprimeInfo(){};
//ahora defino los métodos que tendrá la clase
public:
    //primero defino los constructores
    //en origen será el constructor por default
    criatura():nombre("---"), vida(0), id(00), estatus(0);

    //ahora defino el constructor en caso de que se den parámetros completos
    criatura(string nom, int vid, int i, int est): nombre(nom), vida(vid), id(i), estatus(est);

    //defino ahora aquellos métodos que no cambiarán para cada uno de las subclases, pero que se que cada una
    //las necesita, por lo que se heredaran
    void defensa(){est = 0};
    void atacar(int){};

};


/*Aquí empiezo a definir una de las subclases que saldrán de la clase criatura. Para ello, heredo los atributos y métodos
que definí anteriormente*/
class angel:public criatura{

//defino los atributos que serán únicos para esta clase, aparte de los que ya se habían heredado
//en este caso serán del tipo privado, ya que no quiero que nadie fuera de la clase lo pueda cambiar ni afectar
private:
    string habilidades[4];

//ahora debo de definir los nuevos métodos que tendrá esta clase
//dichos métodos serán públicos.
public:

    //primero definiré los nuevos constructores, empezando por el de default.
    //para ello utilizaré el constructor por default heredado
    angel(){criatura();habilidades[1] = "punos";}

    /*Ahora defino aquellos constructores los cuales recibirán parámetros.
    Aquí ahora utilizaré la sobrecarga, donde tendré el caso donde el ángel no tenga ninguna habilidad
    especial asignada, a la par que tengo el caso donde si se le asigna. Aquí tendríamos el ejemplo de la sobrecarga.*/
    angel(string nom, int vid, int i, int est){criatura(nom, vid, i, est); habilidades[1] = "punos";}
    angel(string nom, int vid, int i, int est, string hab){criatura(nom, vid, i, est);habilidades[1] = hab;}

    //finalmente sobreescribo mi nuevo método de imprimeInfo, donde ahora imprimirá cierta
    //información específica de su clase.
    void imprimeInfo(){
        cout << nombre << endl;
        cout << vida << endl;
        cout << id << endl;
        cout << estatus << endl;
        //establezco el for ya que el atributo habilidades es un arreglo, por lo que podrá tener más que una.
        for (int i = 1; i = sizeof(habilidades), i++){
            cout << habilidades[i] << endl;
        }
    };

    //finalmente establezco mi último método, el cual es único para esta clase.
    void destruir(){vida = 0;}

};

#endif // CRIATURA_H_INCLUDED

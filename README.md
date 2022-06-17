## TC1030 - POO  

Ricardo Navarro Gómez A01708825  
Profesor: Benjamín Valdés Aguirre   
Proyecto: Batallas de Evas

## Explicación proyecto

El proyecto consiste en hacer un simulador de batalla entre Evas y Ángeles (los cuales salen del ánime Neon Genesis Evangelion); dichas batallas ocurrirán en un mapa que se elegirá al inicio, y dependiendo del mapa, tendrán condiciones de victoria distintas entre sí. Los Evas llevarán consigo un piloto, del cual, dependiendo de su estabilidad emocional será que tenga mayor o menos sincronización, y por ende el movimiento del Eva.

Por otro lado, los Ángeles para el caso serán controlado por la computadora, de manera que el objetivo del usuario es ganar la simulación, derrotando a tiempo al Ángel.

## Posibles casos para romper el código

Dentro del código, la única interacción que se tiene con el usuario, se encuentra en qué es lo que el usuario desea hacer del menú, y a la par de indicar que Eva quiere que se mueva. En estas ocasiones en las que se le pide ingrese un dato, únicamente acepta que sean valores del tipo enteros, por lo que al ingresar un dato de otro tipo (como del tipo string), se romperá el programa. Por otra parte, al momento de indicar que número de Eva quiere que ataque, si pides que ataque un numero de Eva fuera de los Evas establecidos, también se rompería el código.

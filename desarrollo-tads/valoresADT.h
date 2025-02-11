/* Utilizaremos este A.D.T.(Abstract Data Type) para almacenar datos, correspondientes 
   a los barrios y arboles de una determinada ciudad. */

#ifndef VALORES_H
#define VALORES_H

typedef struct valoresCDT * valoresADT;

// 10 ^ n donde n es la cantidad de sifras significativas deseadas para el orden de los datos.
#define SIG_FIGURES 100 

//Constante simbolica que representa que se acabo la memoria.
#define OOMEM -1  

/* Crea un CDT vacio. 
** Retorna un puntero al CDT creado.
** O retorna NULL de no tener suficiente memoria. 
*/
valoresADT newValores(void);

// Libera los recursos reservados por el TAD
void freeValores(valoresADT datos);

/*Agrega un barrio a datos, con su nombre, y cantidad de hab.
** Retorna 1 se se agrego correctamente.
** 0 si se trato de agregar un barrio repetido.
** OOMEM si la memoria no alcanzo.
*/
int addBarrio(valoresADT datos, char * nombre, size_t cant);

/*Agrega un arbol a datos, con su nombre y diametro AP.
** Retorna 1 se se agrego correctamente.
** OOMEM si la memoria no alcanzo.
*/
int addArbol(valoresADT datos, char * nombre, double diam);

/*Agrega un arbol al barrio "nombre" dentro de datos.
** Retorna 1 se se agrego correctamente.
** 0 si el barrio no pertenecia a datos.
*/
int addCant(valoresADT datos, char * nombre);

//Ordena los datos dadas las instrucciones del query 1;
void ordenBarrio(valoresADT datos);

//Ordena los datos dadas las instrucciones del query 2;
void ordenCant(valoresADT datos);

//Ordena los datos dadas las instrucciones del query 3;
void ordenArbol(valoresADT datos);

// Setea el current en el primer barrio
void toBegin(valoresADT datos);

// Indica si hay un siguiente barrio o no
int hasNext(valoresADT datos);

/* Devuelve los datos del barrio actual (nombre, cantidad de arboles, cantidad de habitantes).
** Retorna 1 si se pudieron devolver los datos.
** Al guardar una COPIA de "nombre", retorna OOMEM si la memoria no alcanzo.
** 0 si no hay mas datos. */
int nextCant(valoresADT datos, char ** nombre, size_t * cantArb, size_t * hab);

/* Devuelve los datos del barrio actual (nombre, cantidad de arboles).
** Retorna 1 si se pudieron devolver los datos.
** Al guardar una COPIA de "nombre", retorna OOMEM si la memoria no alcanzo.
** 0 si no hay mas datos. */
int nextBarrio(valoresADT datos, char ** nombre, size_t * cantArb);

/* Devuelve los datos del arbol actual (nombre, cantidad de arboles de esta especie).
** Retorna 1 si se pudieron devolver los datos.
** Al guardar una COPIA de "nombre", retorna OOMEM si la memoria no alcanzo.
** 0 si no hay mas datos. */
int nextArbol(valoresADT datos, char ** nombre, size_t * cantArb, double * diamAc);



#endif

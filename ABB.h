#ifndef ABB_LIBRARY_H
#define ABB_LIBRARY_H

#include <stdio.h>
#include <malloc.h>

//Tipos de datos

//Definir el tipo ArbolBinario
typedef struct ArbolBinario {
    struct NodoBinario *Raiz;
} ArbolBinario;

//Funciones

//Elimina el arbol binario
void EliminarArbolBinario(ArbolBinario *Arbol);


//Devuelve un 1 si el valor existe en la lista binaria y un 0 si no lo hace
int ExisteValorArbolBinario(ArbolBinario *Arbol, int valor);


//Añade el valor indicado
void AddValorArbolBinario(ArbolBinario *Arbol, int valor);


//Elimina un valor del arbol
void EliminarValorArbolBinario(ArbolBinario *Arbol, int valor);


//Inicializa el arbol binario
ArbolBinario * InicializarArbolBinario();

#endif //ABB_LIBRARY_H

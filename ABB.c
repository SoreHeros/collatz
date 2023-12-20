#include "ABB.h"


//Definir tipos
//Definir el tipo NodoBinario
typedef struct NodoBinario {
    int valor;
    struct NodoBinario *Padre;
    struct NodoBinario *Mayor;
    struct NodoBinario *Menor;
} NodoBinario;



//Funciones Auxiliares

//Crea el primer nodo del arbol
void CrearPrimerNodo(ArbolBinario *Arbol, int valor){
    //Asignar memoria
    Arbol->Raiz = malloc(sizeof(NodoBinario));

    //Asignar valores
    Arbol->Raiz->valor = valor;
    Arbol->Raiz->Padre = NULL;
    Arbol->Raiz->Mayor = NULL;
    Arbol->Raiz->Menor = NULL;
}


//*****IMPORTANTE***** ESTA IMPLEMENTACIÓN REQUIERE QUE EL PADRE TENGA UN VALOR, POR ESTE MOTIVO SE REQUIERE UNA INICIALIZACIÓN ESPECIAL PARA LA RAÍZ *****IMPORTANTE*****
//recive la dirección del nodo Padre
void CrearNodoHijo(NodoBinario *Padre, int valor){
    //inicialización del nodo hijo
    NodoBinario *Hijo;
    Hijo = malloc(sizeof(NodoBinario));


    //comprobar si el valor no está repetido
    if(Padre->valor != valor){



        //asignarle valores al hijo
        Hijo->valor = valor;
        Hijo->Padre = Padre;
        Hijo->Mayor = NULL;
        Hijo->Menor = NULL;

        //asignarle al Padre el valor correspondiente del hijo

        //TODO
        //EN ESTE EL SIGNO TAMBIÉN ESTABA AL REVÉS
        if(valor < Padre->valor) {
            Padre->Menor = Hijo;
        } else {
            Padre->Mayor = Hijo;
        }

    } else{
        //Como el valor está duplicado se debe liberar memoria
        free(Hijo);
    }
}


//Recibe la dirección de un nodo, busca si en su arbol existe un valor, devuelve la dirección del nodo con el valor o el que sería su padre, si el valor de entrada es nulo se devuelve NULL
NodoBinario * BuscarNodoBinario(NodoBinario *Nodo, int valor){

    //Excepción de entrada si es nulo
    if(Nodo == NULL)
        return NULL;


    while(1){
        if(Nodo->valor == valor){

            //Se ha encontrado el valor, devolver la localización
            return Nodo;

        }else if(valor < Nodo->valor){

            //Mirar si existe hijo menor buscar en el hijo menor
            if(Nodo->Menor == NULL){

                //No existe el valor en la lista, devolver la dirección del posible Padre
                return Nodo;

            } else{

                //Asignarle a nodo la dirección de nodo menor para buscar otra véz
                Nodo = Nodo->Menor;

            }

        } else{

            //hacer lo mismo que antes pero con el hijo menor
            if(Nodo->Mayor == NULL){

                //No existe el valor en la lista, devolver la dirección del posible Padre
                return Nodo;

            } else{

                //Asignarle a nodo la dirección de nodo menor para buscar otra véz
                Nodo = Nodo->Mayor;

            }
        }
    }
}


//Busca y devuelve la dirección del valor mínimo del nodo, si el nodo de entrada es nulo, devuelvo nulo
NodoBinario * MinimoNodoBinario(NodoBinario *Nodo){

    if(Nodo == NULL)
        return NULL;

    while(1){
        //Comprueba si el nodo es el mínimo, si no busca en el hijo menor
        if(Nodo->Menor==NULL)
            return Nodo;
        else
            Nodo=Nodo->Menor;
    }
}


//*****IMPORTANTE***** ESTE MÉTODO REQUIERE QUE EL NODO A ELIMINAR TENGA PADRE, POR ESO SE UTILIZA UN METODO DISTINTO AL ELIMINAR LA RAÍZ *****IMPORTANTE*****
//Elimina o substitulle el valor del nodo por el necesario
void EliminarNodo(NodoBinario *Nodo){
    NodoBinario *NodoAuxiliar;

    //Si el Nodo es NULL no se le hace nada
    if(Nodo != NULL){

        if(Nodo->Mayor != NULL && Nodo->Menor != NULL){
            //procedimiento en caso de que tenga hijo mayor e hijo menor

            //Buscar el menor valor del arbol mayor
            NodoAuxiliar = MinimoNodoBinario(Nodo->Mayor);
            //Substituir el valor del nodo por el nuevo
            Nodo->valor = NodoAuxiliar->valor;
            //Eliminar el nodo Auxiliar de forma recursiva
            EliminarNodo(NodoAuxiliar);
        } else if(Nodo->Mayor != NULL && Nodo->Menor == NULL){
            //procedimiento en caso de que tenga hijo mayor pero no hijo menor

            //Reasignar la dirección del hijo mayor
            Nodo->Mayor->Padre = Nodo->Padre;

            //Reasignar la dirección del padre dependiendo de la procedencia
            if(Nodo->valor < Nodo->Padre->valor){
                Nodo->Padre->Menor = Nodo->Mayor;
            } else{
                Nodo->Padre->Mayor = Nodo->Mayor;
            }

            //Liberar memoria
            free(Nodo);


        } else if(Nodo->Mayor == NULL && Nodo->Menor != NULL){
            //procedimiento en caso de que no tenga hijo mayor pero si hijo menor

            //Reasignar la dirección del hijo mayor
            Nodo->Menor->Padre = Nodo->Padre;

            //Reasignar la dirección del padre dependiendo de la procedencia
            if(Nodo->valor < Nodo->Padre->valor){
                Nodo->Padre->Menor = Nodo->Menor;
            } else{
                Nodo->Padre->Mayor = Nodo->Menor;
            }

            //Liberar memoria
            free(Nodo);


        } else{

            //El nodo no tiene hijos, por lo tanto se puede simplemente eliminar, actualizando el valor del padre

            //TODO
            //EN ESTE EL SIGNO ESTABA AL REVÉS
            if(Nodo->Padre->valor > Nodo->valor){
                Nodo->Padre->Menor = NULL;
            } else{
                Nodo->Padre->Mayor = NULL;
            }

            //Liberar memoria
            free(Nodo);
        }
    }

}


//Elimina el valor del arbol y devuelve la raíz por cuestiones de genericidad (en el caso de que se elimine la raíz se tiene que devolver la nueva dirección, o NULL, o también en caso de que la raíz sea NULL)
NodoBinario * EliminarValorNodo(NodoBinario *Raiz, int valor){

    //Excepción de raíz NULL
    if(Raiz == NULL)
        return NULL;

    //Buscar la locaclización del nodo que contenga el valor
    NodoBinario *Nodo = BuscarNodoBinario(Raiz, valor);

    //Comprobar que el valor de verdad existe
    if(Nodo->valor == valor){

        //Comprobar si el nodo a eliminar es la raíz y no tiene 2 hijos, en cullo caso, se utilizará un método distinto
        if(Nodo == Raiz && (Nodo->Mayor == NULL || Nodo->Menor == NULL)){
            //En este caso se eliminará el nodo de la raíz, por lo tanto es necesario actualizar la dirección de la raíz

            if(Raiz->Mayor != NULL){
                //Si tiene hijo mayor se le asigna a nodo esa dirección
                Nodo = Raiz->Mayor;
            } else{
                //En este caso no importa si existe o si no existe el hijo izquierdo
                Nodo = Raiz->Menor;
            }


            //Eliminar Raíz
            free(Raiz);
            //Devolver nueva dirección
            return Nodo;

        } else{
            //Caso genérico

            //Eliminar el nodo
            EliminarNodo(Nodo);
            //Devolver la dirección de la raíz
            return Raiz;
        }
    } else{

        //El valor no existe, simplemente devolver la dirección de la raíz
        return Raiz;
    }
}


//Devuelve un 1 si el valor existe en la lista binaria y un 0 si no lo hace, si es null devuelve 0
int ExisteValorNodoBinario(NodoBinario *Nodo, int valor){

    //Caso especial
    if(Nodo == NULL)
        return 0;

    //Busca el valor del nodo o posible Padre
    Nodo = BuscarNodoBinario(Nodo, valor);

    //Compara para ver si es un posible Padre o la dirección que contiene el valor
    return Nodo->valor == valor;

}


//*****IMPORTANTE***** ESTA IMPLEMENTACIÓN REQUIERE QUE EL PADRE TENGA UN VALOR, POR ESTE MOTIVO SE REQUIERE UNA INICIALIZACIÓN ESPECIAL PARA LA RAÍZ *****IMPORTANTE*****
//Recibe la raíz y añade el valor indicado
void AddValorNodoBinario(NodoBinario *Nodo, int valor){

    //busca la dirección del Padre
    Nodo = BuscarNodoBinario(Nodo, valor);

    //lo añade a la lista
    CrearNodoHijo(Nodo, valor);

}



//Funciones de la librería


//Elimina el arbol binario
void EliminarArbolBinario(ArbolBinario *Arbol){
    //No se utiliza el comando genérico porque al eliminar el arbol por completo se puede hacer un algoritmo que no requiera tantas comprobaciones
    //Crear variables
    NodoBinario *Nodo;
    int aux;

    //Comprobar si el arbol no existe
    if(Arbol->Raiz != NULL) {

        //Elimina el arbol mayor excepto si no existe
        if (Arbol->Raiz->Mayor != NULL) {
            Nodo = Arbol->Raiz->Mayor;

            //Se repite hasta que se llegue a la raíz
            while (Nodo->Padre != NULL) {

                //Si existe un hijo mayor, buscar más hondo
                if (Nodo->Mayor == NULL) {

                    //Si existe un hijo menor, buscar más hondo
                    if (Nodo->Menor == NULL) {

                        //Como no existen hijos, volver atrás y liberar la memoria dependiendo de su procedencia
                        aux = Nodo->valor;
                        Nodo = Nodo->Padre;

                        //TODO
                        //EL SIGNO DE COMPARACIÓN ESTABA AL REVÉS
                        if (aux > Nodo->valor) {
                            free(Nodo->Mayor);
                            Nodo->Mayor = NULL;
                        } else {
                            free(Nodo->Menor);
                            Nodo->Menor = NULL;
                        }

                    } else {
                        Nodo = Nodo->Menor;
                    }
                } else {
                    Nodo = Nodo->Mayor;
                }
            }
        }

        //Elimina el arbol menor excepto si no existe
        if (Arbol->Raiz->Menor != NULL) {
            Nodo = Arbol->Raiz->Menor;

            //Se repite hasta que se llegue a la raíz
            while (Nodo->Padre != NULL) {

                //Si existe un hijo mayor, buscar más hondo
                if (Nodo->Mayor == NULL) {

                    //Si existe un hijo menor, buscar más hondo
                    if (Nodo->Menor == NULL) {

                        //Como no existen hijos, volver atrás y liberar la memoria dependiendo de su procedencia
                        aux = Nodo->valor;
                        Nodo = Nodo->Padre;


                        //DE ALGUNA FORMA ME DÍ CUENTA DE ESTE, PERO NO DEL OTRO
                        if (aux < Nodo->valor) {
                            free(Nodo->Menor);
                            Nodo->Menor = NULL;
                        } else {
                            free(Nodo->Mayor);
                            Nodo->Mayor = NULL;
                        }

                    } else {
                        Nodo = Nodo->Menor;
                    }
                } else {
                    Nodo = Nodo->Mayor;
                }
            }
        }

        //liberar la memoria de la raíz
        free(Arbol->Raiz);
        //liberar memoria Arbol
        free(Arbol);
    }
}

//Devuelve un 1 si el valor existe en la lista binaria y un 0 si no lo hace
int ExisteValorArbolBinario(ArbolBinario *Arbol, int valor){

    //ejecuta el comando genérico
    return ExisteValorNodoBinario(Arbol->Raiz, valor);
}

//Añade el valor indicado
void AddValorArbolBinario(ArbolBinario *Arbol, int valor){

    //Comprueba si el ArbolBinario está vacío
    if(Arbol->Raiz == NULL){
        //Como está vacío ejecuta el procedimiento especiál
        CrearPrimerNodo(Arbol, valor);
    } else{
        //Como no está vacío ejecuta el procedimiento genérico
        AddValorNodoBinario(Arbol->Raiz, valor);

    }
}

//Elimina un valor del arbol
void EliminarValorArbolBinario(ArbolBinario *Arbol, int valor){

    Arbol->Raiz = EliminarValorNodo(Arbol->Raiz, valor);

}


ArbolBinario * InicializarArbolBinario(){
    ArbolBinario *Arbol;

    Arbol = malloc(sizeof(ArbolBinario));

    Arbol->Raiz = NULL;

    return Arbol;
}
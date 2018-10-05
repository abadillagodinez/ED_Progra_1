#include "mainwindow.h"


/* RADIX SORT */
template<class T>
void MainWindow::RadixSort(SimpleList<T> *arr) //radix de lista simple
{
    if(typeid(T) == typeid(string))
    {
        SimpleList<T> *baldes[26];
        for(int i = 0; i < 26; i++)
            baldes[i] = new SimpleList<T>();
        radixAux(arr, baldes, 12, 26);
    }
    else if(typeid(T) == typeid(char))
    {
        SimpleList<T> *baldes[26];
        for(int i = 0; i < 26; i++)
            baldes[i] = new SimpleList<T>();
        radixAux(arr, baldes, 1, 26);

    }
    else if(typeid(T) == typeid(int))
    {
        SimpleList<T> *baldes [10];
        for(int i = 0; i < 10; i++)
            baldes[i] = new SimpleList<T>();
        int digits = mayorCantidadDigitos(arr);
        radixAux(arr, baldes, digits, 10);
    }

    else
    {
        /*CODIGO PARA LA COMPARACION DE OBJETOS*/
    }
}

/*METODO AUXILIAR QUE DISTRIBUYE EN LAS LISTAS Y HACE CADA CICLO*/
template<class T>
void MainWindow::radixAux(SimpleList<T>* arr, SimpleList<T>* baldes[] ,int iterations, int tamArreglo)
{
    if(typeid(T) == typeid(string))
    {
        int i = 0, digit;
        SimpleNode<T> *aux;
        while(i < iterations)
        {
            aux = arr->getHead();
            while(aux)
            {
                digit = (aux->getDato() - 'a'); //calculo del indice segun letras
                baldes[digit]->insertAtTail(aux->getDato());
                aux = aux->getNext();
            }
            arr->~SimpleList();
            radixVaciarAux(arr, baldes, tamArreglo);
            i++;
        }
    }

    if(typeid(T) == typeid(int))
    {
        int i = 0, pot = 0, digit;
        SimpleNode<T> *aux;
        while(i < iterations)
        {
            aux = arr->getHead();
            while(aux)
            {
                digit = ((aux->getDato()/(int)pow(10,pot)) % 10); //calculo del indice segun numeros
                baldes[digit]->insertAtTail(aux->getDato());
                aux = aux->getNext();
            }
            arr->~SimpleList();
            radixVaciarAux(arr, baldes, tamArreglo);
            pot++;
            i++;
        }
    }

    if(typeid(T) == typeid(char))
    {
        int i = 0, digit;
        SimpleNode<T> *aux;
        while(i < iterations)
        {
            aux = arr->getHead();
            while(aux)
            {
                digit = (aux->getDato() - 'a'); //calculo del indice segun letras
                baldes[digit]->insertAtTail(aux->getDato());
                aux = aux->getNext();
            }
            arr->~SimpleList();
            radixVaciarAux(arr, baldes, tamArreglo);
            i++;
        }
    }
}


/*METODO AUXILIAR QUE VACIA LOS BALDES Y LE DEVUELVE LOS VALORES A LA LISTA ORIGINAL*/
template<class T>
void MainWindow::radixVaciarAux(SimpleList<T>* arr, SimpleList<T>* baldes[], int tamArreglo)
{
    for(int i = 0; i < tamArreglo; i++)
    {
        SimpleNode<T>* aux = baldes[i]->getHead();
        while(aux)
        {
            arr->insertAtTail(aux->getDato());
            aux = aux->getNext();
        }
    }
    for(int i = 0; i < tamArreglo; i++)
        baldes[i]->~SimpleList();
}


/*METODO AUXILIAR PARA CALCULAR LA CANTIDAD DE DIGITOS DE UN NUMERO (lista simple)*/
template<class T>
int MainWindow::mayorCantidadDigitos(SimpleList<T> *arr)
{
    SimpleNode<T>* aux = arr->getHead();
    int result = 0;
    while(aux)
    {
        int valorActual = 0;
        int copia = aux->getDato();
        while(copia > 0)
        {
            valorActual++;
            copia = copia/10;
        }
        if(valorActual > result)
            result = valorActual;
        aux = aux->getNext();

    }
    return result;
}

/*METODO AUXILIAR PARA CALCULAR LA CANTIDAD DE LETRAS DE UNA PALABRA (lista simple)*/

int MainWindow::mayorCantidadLetras(SimpleList<string> *arr)
{
    SimpleNode<string>* aux = arr->getHead();
    int result = 0;
    while(aux)
    {
        string word = aux->getDato();
        if(word.size() > result)
            result = word.size();
        aux = aux->getNext();

    }
    return result;
}

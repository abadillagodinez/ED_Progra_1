#ifndef Queue_H
#define Queue_H
#include "simplenode.h"
#include <iostream>

using namespace std;

template <typename tData>
class Queue
{
    SimpleNode<tData> *head;
    SimpleNode<tData> *actual;
    SimpleNode<tData> *tail;
    int lSize;
    public:
        Queue();
        ~Queue();
        bool isVoid();
        void enqueue(tData dato);
        tData dequeue();
        void print();
        int getSize();
        SimpleNode<tData>* getPos(int pos);
        void swap(int pos1, int pos2);


    protected:
};

/*CONSTRUCTOR DE LA CLASE*/
template <typename tData>
Queue<tData>::Queue()
{
    head = actual = tail = 0;
    lSize = 0;
}

/*DESTRUCTOR POR DEFECTO*/
template <typename tData>
Queue<tData>::~Queue()
{
}

/*METODO DE OBTENCION DEL TAMAÑO*/
template <typename tData>
int Queue<tData>::getSize()
{
    return lSize;
}

template <typename tData>
bool Queue<tData>::isVoid()
{
    return head == 0;
}

/*METODOS DE INSERCION AL FINAL DE LA COLA*/
template <typename tData>
void Queue<tData>::enqueue(tData dato)
{
    if(isVoid())
    {
        head = new SimpleNode<tData>(dato);
        tail = head;
        lSize++;
    }
    else
    {
        SimpleNode<tData>* nsNode = new SimpleNode<tData>(dato);
        tail->setNext(nsNode);
        tail = nsNode;
        lSize++;
    }
}

/*METODO DE DESENCOLADO
*RETORNA EL ELEMENTO AL INICIO DE LA COLA
*/

template <typename tData>
tData Queue<tData>::dequeue()
{
    if(isVoid())
         cout << "La lista se está vacía\n";
    else
    {
        if(!head->getNext())
        {
            head = 0;
            lSize--;
        }
        else
        {
            actual = head;
            head = head->getNext();
            lSize--;
            return actual->getDato();
        }
    }/*else*/
}

/*METODO DE IMPRESION*/

template <typename tData>
void Queue<tData>::print()
{
    if (isVoid())
        cout << "La lista se está vacía\n";
    else
    {
        actual = head;
        while (actual)
        {
            if (!actual->getNext())
            {
                cout << actual->getDato() << endl;
                actual = actual->getNext();
            }
            else
            {
                cout << actual->getDato() << " - ";
                actual = actual->getNext();
            }
        }
    }
}


template <class tData>
SimpleNode<tData>* Queue<tData>::getPos(int pos)
{
    if(isVoid())
        cout << "La lista se está vacía\n";
    else
    {
        if((pos >= lSize) || (pos < 0))
            cout << "El índice esta fuera del los límites de la lista\n";
        else
        {
            if(pos == 0)
                return head;
            else if(pos == lSize-1)
                return tail;
            else
            {
                int index = 1;
                actual = head;
                while (index <= pos) {
                    actual = actual->getNext();
                    index++;
                }
                return actual;
            }
        }
    }
}

template<class tData>
void Queue<tData>::swap(int pos1, int pos2)
{
    if((pos1 < lSize || pos1 >= 0) && (pos2 < lSize || pos2 >= 0))
    {
        SimpleNode<tData> *primero = getPos(pos1);
        SimpleNode<tData> *segundo = getPos(pos2);
        tData temp = primero->getDato();
        primero->setDato(segundo->getDato());
        segundo->setDato(temp);
    }
    else
        cout << "Indices fuera de rango\n";
}
#endif

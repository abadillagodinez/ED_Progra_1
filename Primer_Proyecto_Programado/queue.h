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

#endif

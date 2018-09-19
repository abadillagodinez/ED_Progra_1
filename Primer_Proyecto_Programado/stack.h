#ifndef Stack_H
#define Stack_H
#include "simplenode.h"
#include <iostream>

using namespace std;

template <typename tData>
class Stack
{
    SimpleNode<tData> *head;
    SimpleNode<tData> *actual;
    SimpleNode<tData> *tail;
    int lSize;
    public:
        Stack();
        ~Stack();
        bool isVoid();
        void push(tData dato);
        tData pop();
        void print();
        int getSize();


    protected:
};


template <typename tData>
Stack<tData>::Stack()
{
    head = actual = tail = 0;
    lSize = 0;
}

template <typename tData>
Stack<tData>::~Stack()
{
}

template <typename tData>
int Stack<tData>::getSize()
{
    return lSize;
}

template <typename tData>
bool Stack<tData>::isVoid()
{
    return head == 0;
}

/*METODOS DE INSERCION*/

template <typename tData>
void Stack<tData>::push(tData dato)
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
        nsNode->setNext(head);
        head = nsNode;
        lSize++;
    }
}

/*METODOS DE BORRADO*/

template <typename tData>
tData Stack<tData>::pop()
{
    if(isVoid())
         cout << "La lista se está vacía\n";
    else
    {
        if(!head->getNext())
        {
            actual = head;
            head = 0;
            lSize--;
            return actual->getDato();
        }
        else
        {
            actual = head;
            head = head->getNext();
            lSize--;
            return actual;
        }
    }/*else*/
}

/*METODO DE IMPRESION*/

template <typename tData>
void Stack<tData>::print()
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

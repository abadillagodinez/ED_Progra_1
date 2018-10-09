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
        SimpleNode<tData>* getPos(int pos);
        void swap(int pos1, int pos2);


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
            return actual->getDato();
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

template <class tData>
SimpleNode<tData>* Stack<tData>::getPos(int pos)
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
void Stack<tData>::swap(int pos1, int pos2)
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

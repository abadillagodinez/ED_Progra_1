#ifndef DobleList_H
#define DobleList_H
#include "doblenode.h"
#include <iostream>

using namespace std;

template <typename tData>
class DobleList
{
    DobleNode<tData> *head;
    DobleNode<tData> *actual;
    DobleNode<tData> *tail;
    int lSize;
    public:
        DobleList();
        ~DobleList();
        bool isVoid();
        void insertAtHead(tData dato);
        void insertAtTail(tData dato);
        void insertAtPos(int pos, tData dato);
        void deleteAtHead();
        void deleteAtPos(int pos);
        void deleteAtTail();
        void print();
        int getSize();
        DobleNode<tData>* getPos(int pos);
        void swap(int pos1, int pos2);



    protected:
};


template <typename tData>
DobleList<tData>::DobleList()
{
    head = actual = tail = 0;
    lSize = 0;
}

template <typename tData>
DobleList<tData>::~DobleList()
{
}

template <typename tData>
int DobleList<tData>::getSize()
{
    return lSize;
}

template <typename tData>
bool DobleList<tData>::isVoid()
{
    return head == 0;
}

/*METODOS DE INSERCION*/

template <typename tData>
void DobleList<tData>::insertAtHead(tData dato)
{
    if(isVoid())
    {
        head = new DobleNode<tData>(dato);
        tail = head;
        lSize++;
    }
    else
    {
        DobleNode<tData>* ndNode = new DobleNode<tData>(dato);
        ndNode->setNext(head);
        ndNode->setPrev(head->getPrev());
        ndNode->getNext()->setPrev(ndNode);
        head = ndNode;
        lSize++;
    }
}

template <typename tData>
void DobleList<tData>::insertAtTail(tData dato)
{
    if(isVoid())
    {
        head = new DobleNode<tData>(dato);
        tail = head;
        lSize++;
    }
    else
    {
        DobleNode<tData>* ndNode = new DobleNode<tData>(dato);
        tail->setNext(ndNode);
        ndNode->setPrev(tail);
        tail = ndNode;
        lSize++;
    }
}

template <typename tData>
void DobleList<tData>::insertAtPos(int pos, tData dato)
{
    if(isVoid() || pos <= 0)
       insertAtHead(dato);
    else if(pos >= lSize)
        insertAtTail(dato);
    else
    {
        actual = head;
        int index = 1;
        while ((index < pos) && (actual->getNext()))
        {
            index++;
            actual = actual->getNext();
        }
        DobleNode<tData>* ndNode = new DobleNode<tData>(dato);
        ndNode->setNext(actual->getNext());
        actual->setNext(ndNode);
        ndNode->setPrev(actual);
        ndNode->getNext()->setPrev(ndNode);
        lSize++;
    }/*else*/
}

/*METODOS DE BORRADO*/

template <typename tData>
void DobleList<tData>::deleteAtHead()
{
    if(isVoid())
         cout << "La lista se está vacía\n";
    else if(!head->getNext())
    {
        DobleNode<tData>* temp = head;
        head = 0;
        delete temp;
        lSize--;
    }
    else
    {
        DobleNode<tData>* temp = head;
        head = head->getNext();
        head->setPrev(0);
        temp->setNext(0); /*0 = NULL*/
        temp->setPrev(0);
        delete temp;
        lSize--;
    }/*else*/
}


template <typename tData>
void DobleList<tData>::deleteAtTail()
{
    if(isVoid())
         cout << "La lista se está vacía\n";
    else if(!head->getNext())
    {
        actual = head;
        head = 0;
        delete actual;
        lSize--;
    }/*else if*/
    else
    {
        actual = head;
        while (actual->getNext()->getNext())
            actual = actual->getNext();
        DobleNode<tData> *temp = actual->getNext();
        actual->setNext(0);
        delete temp;
        tail = actual;
        lSize--;
    }/*else*/
}

template <typename tData>
void DobleList<tData>::deleteAtPos(int pos)
{
    if(isVoid())
        cout << "La lista se está vacía\n";
    else if((pos >= lSize) || (pos < 0))
        cout << "El índice esta fuera del los límites de la lista\n";
    else if(pos == 0)
        deleteAtHead();
    else if(pos == lSize-1)
        deleteAtTail();
    else
    {
        int index = 1;
        actual = head;
        while (index < pos) {
            actual = actual->getNext();
            index++;
        }
        DobleNode<tData> *temp = actual->getNext();
        actual->setNext(actual->getNext()->getNext());
        actual->getNext()->setPrev(actual);
        delete temp;
        lSize--;
    }
}

/*METODO DE IMPRESION*/

template <typename tData>
void DobleList<tData>::print()
{
    if (isVoid())
        cout << "La lista se está vacía\n";
    else
    {
        actual = head;
        while(actual)
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
        }/*while*/
    }
}

template <class tData>
DobleNode<tData>* DobleList<tData>::getPos(int pos)
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
                if(pos <= lSize/2) //Si la distancia a la cabeza es menor
                {
                    int index = 1;
                    actual = head;
                    while (index <= pos) {
                        actual = actual->getNext();
                        index++;
                    }
                    return actual;
                }
                else //si la distancia a la cabeza es mayor
                {
                    int index = lSize-2;
                    actual = tail;
                    while (index >= pos) {
                        actual = actual->getPrev();
                        index--;
                    }
                    return actual;
                }
            }/*else si la posicion no es un extremo*/
        }/*else si la posicion es valida*/
    }/*else de vacio*/
}

template<class tData>
void DobleList<tData>::swap(int pos1, int pos2)
{
    if((pos1 < lSize || pos1 >= 0) && (pos2 < lSize || pos2 >= 0))
    {
        DobleNode<tData> *primero = getPos(pos1);
        DobleNode<tData> *segundo = getPos(pos2);
        tData temp = primero->getDato();
        primero->setDato(segundo->getDato());
        segundo->setDato(temp);
    }
    else
        cout << "Indices fuera de rango\n";
}

#endif

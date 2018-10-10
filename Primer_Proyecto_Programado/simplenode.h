#ifndef SimpleNode_H
#define SimpleNode_H
#include <string>
#include <tuple>

template <typename tData>
class SimpleNode
{

    public:
        tData dato;
        SimpleNode* next;
        SimpleNode(tData pDato);
        SimpleNode(tData pDato, SimpleNode<tData> *pNext);
        ~SimpleNode();
        tData getDato();
        void setDato(tData pDato);
        SimpleNode* getNext();
        void setNext(SimpleNode* pNext);
        bool operator< (SimpleNode<tData> newdato);
        bool operator> (SimpleNode<tData> newdato);
        bool operator == (SimpleNode<tData> newdato);
    protected:
};

template <typename tData>
SimpleNode<tData>::SimpleNode(tData pDato){
    dato = pDato;
    next = 0;
}

template <typename tData>
SimpleNode<tData>::SimpleNode(tData pDato, SimpleNode<tData> *pNext)
{
    dato = pDato;
    next = pNext;
}

template <typename tData>
SimpleNode<tData>::~SimpleNode()
{
}

template <typename tData>
tData SimpleNode<tData>::getDato()
{
    return dato;
}

template <typename tData>
void SimpleNode<tData>::setDato(tData pDato)
{
    dato = pDato;
}

template <typename tData>
SimpleNode<tData>* SimpleNode<tData>::getNext()
{
    return next;
}

template <typename tData>
void SimpleNode<tData>::setNext(SimpleNode* pNext)
{
    next = pNext;
}

template <typename tData>
bool SimpleNode<tData>::operator<(SimpleNode<tData> newdato)
{
    /* MODIFIBLE FUNCTION TO COMPARE OBJECTS USING TUPLES
     * YOU SHOULD DO STD::TIE(DATAMEMBERS) THEN STD::TIE(NEWDATAMEMEBERS)
     * AND FINALLY COMPARE THE TWO OBJECTS */
    return std::tie(dato) < std::tie(newdato.dato);
}

template <typename tData>
bool SimpleNode<tData>::operator>(SimpleNode<tData> newdato)
{
    /* MODIFIBLE FUNCTION TO COMPARE OBJECTS USING TUPLES
     * YOU SHOULD DO STD::TIE(DATAMEMBERS) THEN STD::TIE(NEWDATAMEMEBERS)
     * AND FINALLY COMPARE THE TWO OBJECTS */
    return std::tie(dato) > std::tie(newdato.dato);
}


template <typename tData>
bool SimpleNode<tData>::operator ==(SimpleNode<tData> newdato)
{
    /* MODIFIBLE FUNCTION TO COMPARE OBJECTS USING TUPLES
     * YOU SHOULD DO STD::TIE(DATAMEMBERS) THEN STD::TIE(NEWDATAMEMEBERS)
     * AND FINALLY COMPARE THE TWO OBJECTS */
    return std::tie(dato) == std::tie(newdato.dato);
}
#endif

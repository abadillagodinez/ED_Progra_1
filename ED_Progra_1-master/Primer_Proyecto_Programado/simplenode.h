#ifndef SimpleNode_H
#define SimpleNode_H
#include <typeinfo>
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
        bool operator< (tData newdato);
        bool operator> (tData newdato);
        bool operator == (tData newdato);
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
bool SimpleNode<tData>::operator<(tData newdato)
{
    if(typeid(tData) == typeid(int))
    {
        return dato < newdato;
    }
    if(typeid(tData) == typeid (char))
    {
        return dato < newdato;
    }
    if(typeid(tData) == typeid(std::string))
    {
        if(dato.compare(newdato) < 0)
            return 1;
        else
            return 0;
    }
    /* MODIFIBLE FUNCTION TO COMPARE OBJECTS USING TUPLES
     * YOU SHOULD DO STD::TIE(DATAMEMBERS) THEN STD::TIE(NEWDATAMEMEBERS)
     * AND FINALLY COMPARE THE TWO OBJECTS */
    return std::tie(dato) < std::tie(newdato);
}

template <typename tData>
bool SimpleNode<tData>::operator>(tData newdato)
{
    if(typeid(tData) == typeid(int))
    {
        return dato > newdato;
    }
    if(typeid(tData) == typeid (char))
    {
        return dato > newdato;
    }
    if(typeid(tData) == typeid(std::string))
    {
        if (dato.compare(newdato) > 0)
            return 1;
        else
            return 0;
    }
    /* MODIFIBLE FUNCTION TO COMPARE OBJECTS USING TUPLES
     * YOU SHOULD DO STD::TIE(DATAMEMBERS) THEN STD::TIE(NEWDATAMEMEBERS)
     * AND FINALLY COMPARE THE TWO OBJECTS */
    return std::tie(dato) > std::tie(newdato);
}


template <typename tData>
bool SimpleNode<tData>::operator ==(tData newdato)
{
    if(typeid(tData) == typeid(int))
    {
        return dato == newdato;
    }
    if(typeid(tData) == typeid (char))
    {
        return dato == newdato;
    }
    if(typeid(tData) == typeid(std::string))
    {
        if (dato.compare(newdato) == 0)
            return 1;
        else
            return 0;
    }
    /* MODIFIBLE FUNCTION TO COMPARE OBJECTS USING TUPLES
     * YOU SHOULD DO STD::TIE(DATAMEMBERS) THEN STD::TIE(NEWDATAMEMEBERS)
     * AND FINALLY COMPARE THE TWO OBJECTS */
    return std::tie(dato) == std::tie(newdato);
}
#endif

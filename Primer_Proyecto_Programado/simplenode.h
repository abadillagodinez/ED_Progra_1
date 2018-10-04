#ifndef SimpleNode_H
#define SimpleNode_H

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

#endif

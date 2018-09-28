#ifndef DobleNode_H
#define DobleNode_H

template <typename tData>
class DobleNode
{
    tData dato;
    DobleNode* next;
    DobleNode* prev;
    public:
        DobleNode(tData pDato);
        DobleNode(tData pDato, DobleNode<tData> *pNext, DobleNode<tData> *pPrev);
        ~DobleNode();
        tData getDato();
        void setDato(tData pDato);
        DobleNode* getNext();
        DobleNode* getPrev();
        void setNext(DobleNode* pNext);
        void setPrev(DobleNode* pPrev);
    protected:
};

template <typename tData>
DobleNode<tData>::DobleNode(tData pDato){
    dato = pDato;
    next = 0; /*0 siendo NULL*/
    prev = 0;
}

template <typename tData>
DobleNode<tData>::DobleNode(tData pDato, DobleNode<tData> *pNext, DobleNode<tData>* pPrev)
{
    dato = pDato;
    next = pNext;
    prev = pPrev;
}

template <typename tData>
DobleNode<tData>::~DobleNode()
{
}

template <typename tData>
tData DobleNode<tData>::getDato()
{
    return dato;
}

template <typename tData>
void DobleNode<tData>::setDato(tData pDato)
{
    dato = pDato;
}

template <typename tData>
DobleNode<tData>* DobleNode<tData>::getNext()
{
    return next;
}

template <typename tData>
void DobleNode<tData>::setNext(DobleNode* pNext)
{
    next = pNext;
}

template <typename tData>
DobleNode<tData>* DobleNode<tData>::getPrev()
{
    return prev;
}

template <typename tData>
void DobleNode<tData>::setPrev(DobleNode* pPrev)
{
    prev = pPrev;
}

#endif

#include "mainwindow.h"


/* MERGE SORT */
template <class T>
void MainWindow::MergeSort(SimpleList<T> *arr, int leftIndx, int rightIndx) /* INDICES IZQUIERDOS Y DERECHOS DE LA LISTA*/
{
    if (leftIndx < rightIndx)
    {
        int pivote = leftIndx+(rightIndx-leftIndx)/2;
        MergeSort(arr, leftIndx, pivote);
        MergeSort(arr, pivote+1, rightIndx);
        Merge(arr, leftIndx, pivote, rightIndx);
    }
}

/*METODO AUXILIAR DEL MERGE SORT*/
template <class T>
void MainWindow::Merge(SimpleList<T> *arr, int leftIndx, int pivote, int rigthIndx)
{
    int i, j, k; //INDICES DE LOS CICLOS
    int nuevList1 = pivote - leftIndx + 1; //TAMANO DE LA PRIMERA LISTA NUEVA
    int nuevList2 =  rigthIndx - pivote; //TAMANO DE LA SEGUNDA LISTA NUEVA
    SimpleList<T> *menores = new SimpleList<T>();
    SimpleList<T> *mayores = new SimpleList<T>();

    for (i = 0; i < nuevList1; i++)
        menores->insertAtTail(arr->getPos(leftIndx + i)->getDato());
    for (j = 0; j < nuevList2; j++)
         mayores->insertAtTail(arr->getPos(pivote + 1 + j)->getDato());
    i = 0;
    j = 0;
    k = leftIndx;
    while (i < nuevList1 && j < nuevList2)
    {
        if (menores->getPos(i)->getDato() <= mayores->getPos(j)->getDato())
        {
            arr->getPos(k)->setDato(menores->getPos(i)->getDato());
            i++;
        }
        else
        {
            arr->getPos(k)->setDato(mayores->getPos(j)->getDato());
            j++;
        }
        k++;
    }
    while (i < nuevList1)
    {
        arr->getPos(k)->setDato(menores->getPos(i)->getDato());
        i++;
        k++;
    }
    while (j < nuevList2)
    {
        arr->getPos(k)->setDato(mayores->getPos(j)->getDato());
        j++;
        k++;
    }
}

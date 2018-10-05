#include "mainwindow.h"

/* INSERTION SORT */
template <class T>
void MainWindow::InsertionSort(SimpleList<T>* arr)
{
    int i, j;
    T actual;
    for (i = 1; i < arr->getSize(); i++) {
        actual = arr->getPos(i)->getDato();
        for (j = i; j > 0 && arr->getPos(j-1)->getDato() > actual; j--) {
            SimpleNode<T> *actualNode = arr->getPos(j);
            SimpleNode<T> *prevNode = arr->getPos(j-1);
            actualNode->setDato(prevNode->getDato());
        }
        arr->getPos(j)->setDato(actual);
    }
}

#include "mainwindow.h"

/* QUICK SORT */
template<class T>
void MainWindow::QuickSort(SimpleList<T> *arr, int low, int high) //Metodo para la lista simple
{
    if (low < high){
        int pi = partition(arr, low, high);
        QuickSort(arr, low, pi - 1);//Makes a new group with the highers
        QuickSort(arr, pi + 1, high);//Makes a new group with the lowers

      }
}

/*METODO AUXILIAR QUE HACE LA PARTICION EN EL QUICK SORT*/
template<class T>
int MainWindow::partition(SimpleList<T> *arr, int low, int high)
{
    SimpleNode<T>* pivot = arr->getPos(high);
    int i = (low - 1);
    for (int j = low; j <= (high - 1); j++)
    {
        if (arr->getPos(j)->dato <= pivot->dato){ //changes acording to which one is higher
          i++;
          arr->swap(i,j);
          movements.push_back(movement(i,j));
        }
    }
    arr->swap((i+ 1),high);
    movements.push_back(movement(i,high));
    return( i + 1 );
}

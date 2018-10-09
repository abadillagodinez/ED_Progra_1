#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "simplelist.h"
#include "doblelist.h"
#include "dclist.h"
#include "stack.h"
#include "queue.h"
#include <QDialog>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsItemAnimation>
#include <QTimeLine>
#include <vector>
//#include "windows.h
#include "movement.h"
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include <typeinfo>
#include <QFile>
#include <QTextStream>
#include <fstream>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    template<class T>
    void GenerateBoxes(SimpleList<T>* list);
    void Swap(int pos1, int pos2);

    //firma de metodos de ordenamiento
    /*QUICK*/
    template<class T>
    void QuickSort(SimpleList<T>* arr, int low, int high); //de lista simple

    template<class T>
    int partition(SimpleList<T>* arr, int low, int high);

    template<class T>
    void QuickSort(DobleList<T>* arr, int low, int high); //de lista doble

    template<class T>
    int partition(DobleList<T>* arr, int low, int high);

    template<class T>
    void QuickSort(DCList<T>* arr, int low, int high); //de lista doble circular

    template<class T>
    int partition(DCList<T>* arr, int low, int high);

    template<class T>
    void QuickSort(Stack<T>* arr, int low, int high); //de pila

    template<class T>
    int partition(Stack<T>* arr, int low, int high);

    template<class T>
    void QuickSort(Queue<T>* arr, int low, int high); //de pila

    template<class T>
    int partition(Queue<T>* arr, int low, int high);

    /*RADIX*/
    template <class T>
    void RadixSort(SimpleList<T>* arr);

    template <class T>
    int mayorCantidadDigitos(SimpleList<T> *arr);

    int mayorCantidadLetras(SimpleList<string> *arr);

    template <class T>
    void radixAux(SimpleList<T>* arr, SimpleList<T>* baldes[] ,int iterations, int tamArreglo);

    template <class T>
    void radixVaciarAux(SimpleList<T>* arr, SimpleList<T>* baldes[], int tamArreglo);

    /*MERGE*/
    template <class T>
    void Merge(SimpleList<T> *arr, int leftIndx, int pivote, int rigthIndx);

    template <class T>
    void MergeSort(SimpleList<T> *arr, int leftIndx, int rightIndx);

    template <class T>
    void Merge(DobleList<T> *arr, int leftIndx, int pivote, int rigthIndx);

    template <class T>
    void MergeSort(DobleList<T> *arr, int leftIndx, int rightIndx);

    template <class T>
    void Merge(DCList<T> *arr, int leftIndx, int pivote, int rigthIndx);

    template <class T>
    void MergeSort(DCList<T> *arr, int leftIndx, int rightIndx);

    template <class T>
    void Merge(Stack<T> *arr, int leftIndx, int pivote, int rigthIndx);

    template <class T>
    void MergeSort(Stack<T> *arr, int leftIndx, int rightIndx);

    template <class T>
    void Merge(Queue<T> *arr, int leftIndx, int pivote, int rigthIndx);

    template <class T>
    void MergeSort(Queue<T> *arr, int leftIndx, int rightIndx);

    template <class T>
    Stack<T>* invertirPila(Stack<T> *arr);

    /*INSERTION*/
    template <class T>
    void InsertionSort(SimpleList<T> *arr);

    template <class T>
    void InsertionSort(DobleList<T> *arr);

    template <class T>
    void InsertionSort(DCList<T> *arr);

    template <class T>
    void InsertionSort(Stack<T> *arr);

    template <class T>
    void InsertionSort(Queue<T> *arr);

    /*SELECTION*/
    template <class T>
    void SelectionSort(SimpleList<T> *arr, int tamanio);

    template <class T>
    void SelectionSort(DobleList<T> *arr, int tamanio);

    template <class T>
    void SelectionSort(DCList<T> *arr, int tamanio);

    template <class T>
    void SelectionSort(Stack<T> *arr, int tamanio);

    template <class T>
    void SelectionSort(Queue<T> *arr, int tamanio);

    /*HEAPSORT*/
    template <class T>
    void HeapSort(SimpleList<T> *arr);

    template <class T>
    void HeapSortAux(SimpleList<T> *arr, int largo, int aTratar);

    template <class T>
    void HeapSort(DobleList<T> *arr);

    template <class T>
    void HeapSortAux(DobleList<T> *arr, int largo, int aTratar);

    template <class T>
    void HeapSort(DCList<T> *arr);

    template <class T>
    void HeapSortAux(DCList<T> *arr, int largo, int aTratar);

    template <class T>
    void HeapSort(Stack<T> *arr);

    template <class T>
    void HeapSortAux(Stack<T> *arr, int largo, int aTratar);

    template <class T>
    void HeapSort(Queue<T> *arr);

    template <class T>
    void HeapSortAux(Queue<T> *arr, int largo, int aTratar);

    /* SHELLSORT */
    template <class T>
    void ShellSort(SimpleList<T> *arr, int tamano);

    template <class T>
    void ShellSort(DobleList<T> *arr, int tamano);

    template <class T>
    void ShellSort(DCList<T> *arr, int tamano);

    template <class T>
    void ShellSort(Stack<T> *arr, int tamano);

    template <class T>
    void ShellSort(Queue<T> *arr, int tamano);


    void buildWords(SimpleList<string> *arr, int cantidad);
    string buildWordsAux(int indice);



private slots:

    void on_btnRandonInt_clicked();

    void on_btnQuick_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    vector<QGraphicsRectItem*> rectangles;
    QGraphicsRectItem *rectangle;
    QGraphicsRectItem *rectangle2;
    QGraphicsTextItem *text;
    QGraphicsTextItem *text2;
    vector<QGraphicsTextItem*> texts;
    QGraphicsItemAnimation *animation;
    SimpleList<int> *list = new SimpleList<int>();
    vector<movement> movements;
};

#endif // MAINWINDOW_H

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

    /*INSERTION*/
    template <class T>
    void InsertionSort(SimpleList<T> *arr);

    /*SELECTION*/
    template <class T>
    void SelectionSort(SimpleList<T> *arr);

    template <class T>
    void SelectionAux(SimpleList<T> *arr, int tamanio);

    /*HEAPSORT*/
    template <class T>
    void HeapSort(SimpleList<T> *arr);

    template <class T>
    void HeapSortAux(SimpleList<T> *arr, int largo, int aTratar);

    /* SHELLSORT */
    template <class T>
    void ShellSort(SimpleList<T> *arr, int tamano);


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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "simplelist.h"
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
    template<class T>
    void QuickSort(SimpleList<T>* arr, int low, int high); //de lista simple

    template<class T>
    int partition(SimpleList<T>* arr, int low, int high);

    template <class T>
    void RadixSort(SimpleList<T>* arr);

    template <class T>
    int mayorCantidadDigitos(SimpleList<T> *arr);

    template <class T>
    int mayorCantidadLetras(SimpleList<T> *arr);

    template <class T>
    void radixAux(SimpleList<T>* arr, SimpleList<T>* baldes[] ,int iterations, int tamArreglo);

    template <class T>
    void radixVaciarAux(SimpleList<T>* arr, SimpleList<T>* baldes[], int tamArreglo);


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

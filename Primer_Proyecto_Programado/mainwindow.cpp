#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);


}

template <typename T>
void MainWindow::GenerateBoxes(SimpleList<T>* list)
{
    QBrush redBrush(Qt::white);
    QPen outlinePen(Qt::black);
    outlinePen.setWidth(2);
    int size = list->getSize();
    for(int i = 0; i< size; i++)
    {
        std::string str = std::to_string(list->getPos(i)->getDato());
        QString qstr = QString::fromStdString(str);
        rectangle = scene->addRect(i*50, 0, 30, 90, outlinePen, redBrush);
        rectangles.push_back(rectangle);
        text = scene->addText(qstr, QFont("Arial",12));
        text->setPos(QPointF(i*50,-30));
        texts.push_back(text);
    }
}
void MainWindow::Swap(int pos1, int pos2)
{
    int dif = (max(pos1,pos2) - min(pos1,pos2))*50;
    QTimeLine *timer = new QTimeLine(1000);
    timer->setFrameRange(0,100);
    QGraphicsItemAnimation *animation = new QGraphicsItemAnimation;
    QGraphicsItemAnimation *animation2 = new QGraphicsItemAnimation;
    QGraphicsItemAnimation *animation3 = new QGraphicsItemAnimation;
    QGraphicsItemAnimation *animation4 = new QGraphicsItemAnimation;
    rectangle = rectangles[pos1];
    rectangle2 = rectangles[pos2];
    text = texts[pos1];
    text2 = texts[pos2];
    animation->setItem(rectangle);
    animation->setTimeLine(timer);
    animation2->setItem(rectangle2);
    animation2->setTimeLine(timer);
    animation3->setItem(text);
    animation3->setTimeLine(timer);
    animation4->setItem(text2);
    animation4->setTimeLine(timer);
    timer->start();
    for (int i = 0, j = 0; i <= dif; ++i, --j)
    {
        animation->setPosAt(i/500.0, QPointF(i,0));
        animation2->setPosAt(i/500.0, QPointF(j,0));
    }
    for (int i = 0; i<=50; ++i)
    {
        animation3->setPosAt(i/500.0, QPointF(i*pos2,-30));
        animation4->setPosAt(i/500.0, QPointF(i*pos1,-30));
    }
    QGraphicsRectItem *temp = rectangle;
    rectangle = rectangle2;
    rectangle2 = temp;
    QGraphicsTextItem *temp2 = text;
    text = text2;
    text2 = temp2;
}
MainWindow::~MainWindow()
{
    delete ui;
}



// SORTINGS ALGORITMS
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

template<class T>
void MainWindow::QuickSort(SimpleList<T> *arr, int low, int high) //Metodo para la lista simple
{
    if (low < high){
        int pi = partition(arr, low, high);
        QuickSort(arr, low, pi - 1);//Makes a new group with the highers
        QuickSort(arr, pi + 1, high);//Makes a new group with the lowers

      }
}

template<class T>
void MainWindow::RadixSort(SimpleList<T> *arr) //radix de lista simple
{
    if(typeid(T) == typeid(char))
    {
        SimpleList<T> *baldes[26];

    }
    else if(typeid(T) == typeid(int))
    {
        SimpleList<T> *baldes [10];
        for(int i = 0; i < 10; i++)
            baldes[i] = new SimpleList<T>();
        int digits = mayorCantidadDigitos(arr);
        radixAux(arr, baldes, digits, 10);
    }
    else if(typeid(T) == typeid(string))
    {
        SimpleList<T> *baldes[26];
        //int letras = mayorCantidadLetras(arr);

    }
    else
    {

    }
}

/*METODO AUXILIAR QUE DISTRIBUYE EN LAS LISTAS Y HACE CADA CICLO*/
template<class T>
void MainWindow::radixAux(SimpleList<T>* arr, SimpleList<T>* baldes[] ,int iterations, int tamArreglo)
{
    int i = 0, pot = 0, digit;
    SimpleNode<T> *aux;
    while(i < iterations)
    {
        aux = arr->getHead();
        while(aux)
        {
            digit = ((aux->getDato()/(int)pow(10,pot)) % 10);
            baldes[digit]->insertAtTail(aux->getDato());
            aux = aux->getNext();
        }
        arr->~SimpleList();
        radixVaciarAux(arr, baldes, tamArreglo);
        pot++;
        i++;
    }
}

/*METODO AUXILIAR QUE VACIA LOS BALDES Y LE DEVUELVE LOS VALORES A LA LISTA ORIGINAL*/
template<class T>
void MainWindow::radixVaciarAux(SimpleList<T>* arr, SimpleList<T>* baldes[], int tamArreglo)
{
    for(int i = 0; i < tamArreglo; i++)
    {
        SimpleNode<T>* aux = baldes[i]->getHead();
        while(aux)
        {
            arr->insertAtTail(aux->getDato());
            aux = aux->getNext();
        }
    }
    for(int i = 0; i < tamArreglo; i++)
        baldes[i]->~SimpleList();
}


/*METODO AUXILIAR PARA CALCULAR LA CANTIDAD DE DIGITOS DE UN NUMERO (lista simple)*/
template<class T>
int MainWindow::mayorCantidadDigitos(SimpleList<T> *arr)
{
    SimpleNode<T>* aux = arr->getHead();
    int result = 0;
    while(aux)
    {
        int valorActual = 0;
        int copia = aux->getDato();
        while(copia > 0)
        {
            valorActual++;
            copia = copia/10;
        }
        if(valorActual > result)
            result = valorActual;
        aux = aux->getNext();

    }
    return result;
}

/*METODO AUXILIAR PARA CALCULAR LA CANTIDAD DE LETRAS DE UNA PALABRA (lista simple)*/
template<class T>
int MainWindow::mayorCantidadLetras(SimpleList<T> *arr)
{
    SimpleNode<T>* aux = arr->getHead();
    int result = 0;
    while(aux)
    {
        if(typeid(aux->getDato()) == typeid(string))
        {
            string word = aux->getDato();
            const char *palabra = word.c_str();
            int valorActual = strlen(palabra);
            if(valorActual > result)
                result = valorActual;
            aux = aux->getNext();
        }

    }
    return result;
}

void MainWindow::on_btnRandonInt_clicked()
{
    srand(time(NULL)); //AGREGAR EL RANGO ALEATORIO
    int rango = 10;
    int valor;
    int sup = 10000; //limite sup que hay que ponerle un get de un spinbox
    int inf = 1; //limite inf que hay que ponerle un get de un spinbox
    for(int i = 0; i<rango;i++)
    {
        valor = rand() % sup + inf;
        list->insertAtHead(valor);
    }
    GenerateBoxes(list);
}

void MainWindow::on_btnQuick_clicked()
{
    list->print();
    //QuickSort(list,0,list->getSize()-1);
    RadixSort(list);
    list->print();
}

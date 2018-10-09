#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    Stack<int> *list = new Stack<int>();
    //buildWords(list,7);
    //for(int i = 10; i > 0; i--) list->enqueue(i);
    for(int i = 0; i < 10; i++) list->push(i);
    list->print();
    HeapSort(list/*, list->getSize()*/);
    list->print();
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
    //timer->stop();
}
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnRandonInt_clicked()
{
    srand(time(NULL)); //AGREGAR EL RANGO ALEATORIO
    int rango = 10;
    int valor;
    int sup = 1000; //limite sup que hay que ponerle un get de un spinbox
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
    //RadixSort(list);
    //MergeSort(list, 0, list->getSize()-1);
    ShellSort(list, list->getSize());
    list->print();
}


/* ALGORITMOS DE ORDENAMIENTO */


/* INSERTION SORT */
template <class T>
void MainWindow::InsertionSort(SimpleList<T>* arr) //Lista simple
{
    int i, j;
    T actual;
    for (i = 1; i < arr->getSize(); i++)
    {
        actual = arr->getPos(i)->getDato();
        for (j = i; j > 0 && arr->getPos(j-1)->getDato() > actual; j--)
        {
            SimpleNode<T> *actualNode = arr->getPos(j);
            SimpleNode<T> *prevNode = arr->getPos(j-1);
            actualNode->setDato(prevNode->getDato());
        }
        arr->getPos(j)->setDato(actual);
    }
}

template <class T>
void MainWindow::InsertionSort(DobleList<T> *arr) //sobrecarga para la lista doble
{
    int i, j;
    T actual;
    for (i = 1; i < arr->getSize(); i++)
    {
        actual = arr->getPos(i)->getDato();
        for (j = i; j > 0 && arr->getPos(j-1)->getDato() > actual; j--)
        {
            DobleNode<T> *actualNode = arr->getPos(j);
            DobleNode<T> *prevNode = arr->getPos(j-1);
            actualNode->setDato(prevNode->getDato());
        }
        arr->getPos(j)->setDato(actual);
    }
}

template <class T>
void MainWindow::InsertionSort(DCList<T> *arr) //sobrecarga para la lista circular
{
    int i, j;
    T actual;
    for (i = 1; i < arr->getSize(); i++)
    {
        actual = arr->getPos(i)->getDato();
        for (j = i; j > 0 && arr->getPos(j-1)->getDato() > actual; j--)
        {
            DobleNode<T> *actualNode = arr->getPos(j);
            DobleNode<T> *prevNode = arr->getPos(j-1);
            actualNode->setDato(prevNode->getDato());
        }
        arr->getPos(j)->setDato(actual);
    }
}

template <class T>
void MainWindow::InsertionSort(Stack<T> *arr) //sobrecarga para la pila
{
    int i, j;
    T actual;
    for (i = 1; i < arr->getSize(); i++)
    {
        actual = arr->getPos(i)->getDato();
        for (j = i; j > 0 && arr->getPos(j-1)->getDato() > actual; j--)
        {
            SimpleNode<T> *actualNode = arr->getPos(j);
            SimpleNode<T> *prevNode = arr->getPos(j-1);
            actualNode->setDato(prevNode->getDato());
        }
        arr->getPos(j)->setDato(actual);
    }
}

template <class T>
void MainWindow::InsertionSort(Queue<T> *arr) //sobrecarga para la cola
{
    int i, j;
    T actual;
    for (i = 1; i < arr->getSize(); i++)
    {
        actual = arr->getPos(i)->getDato();
        for (j = i; j > 0 && arr->getPos(j-1)->getDato() > actual; j--)
        {
            SimpleNode<T> *actualNode = arr->getPos(j);
            SimpleNode<T> *prevNode = arr->getPos(j-1);
            actualNode->setDato(prevNode->getDato());
        }
        arr->getPos(j)->setDato(actual);
    }
}


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
        menores->insertAtTail(arr->getPos(leftIndx + i)->getDato()); //crea la nueva lista con los menores
    for (j = 0; j < nuevList2; j++)
         mayores->insertAtTail(arr->getPos(pivote + 1 + j)->getDato()); //crea la nueva lista con los mayores
    i = 0;
    j = 0;
    k = leftIndx;
    while (i < nuevList1 && j < nuevList2)
    {
        if (menores->getPos(i)->getDato() <= mayores->getPos(j)->getDato()) // si menores[i] <= mayores[j]
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

/*(doble list)*/
template <class T>
void MainWindow::MergeSort(DobleList<T> *arr, int leftIndx, int rightIndx) //Sobrecarga para la lista doble
{
    if (leftIndx < rightIndx)
    {
        int pivote = leftIndx+(rightIndx-leftIndx)/2;
        MergeSort(arr, leftIndx, pivote);
        MergeSort(arr, pivote+1, rightIndx);
        Merge(arr, leftIndx, pivote, rightIndx);
    }
}

template <class T>
void MainWindow::Merge(DobleList<T> *arr, int leftIndx, int pivote, int rigthIndx)
{
    int i, j, k; //INDICES DE LOS CICLOS
    int nuevList1 = pivote - leftIndx + 1; //TAMANO DE LA PRIMERA LISTA NUEVA
    int nuevList2 =  rigthIndx - pivote; //TAMANO DE LA SEGUNDA LISTA NUEVA
    DobleList<T> *menores = new DobleList<T>();
    DobleList<T> *mayores = new DobleList<T>();

    for (i = 0; i < nuevList1; i++)
        menores->insertAtTail(arr->getPos(leftIndx + i)->getDato()); //crea la nueva lista con los menores
    for (j = 0; j < nuevList2; j++)
         mayores->insertAtTail(arr->getPos(pivote + 1 + j)->getDato()); //crea la nueva lista con los mayores
    i = 0;
    j = 0;
    k = leftIndx;
    while (i < nuevList1 && j < nuevList2)
    {
        if (menores->getPos(i)->getDato() <= mayores->getPos(j)->getDato()) // si menores[i] <= mayores[j]
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

/*(doble circular list)*/
template <class T>
void MainWindow::MergeSort(DCList<T> *arr, int leftIndx, int rightIndx) //Sobrecarga para la lista doble circular
{
    if (leftIndx < rightIndx)
    {
        int pivote = leftIndx+(rightIndx-leftIndx)/2;
        MergeSort(arr, leftIndx, pivote);
        MergeSort(arr, pivote+1, rightIndx);
        Merge(arr, leftIndx, pivote, rightIndx);
    }
}

template <class T>
void MainWindow::Merge(DCList<T> *arr, int leftIndx, int pivote, int rigthIndx)
{
    int i, j, k; //INDICES DE LOS CICLOS
    int nuevList1 = pivote - leftIndx + 1; //TAMANO DE LA PRIMERA LISTA NUEVA
    int nuevList2 =  rigthIndx - pivote; //TAMANO DE LA SEGUNDA LISTA NUEVA
    DCList<T> *menores = new DCList<T>();
    DCList<T> *mayores = new DCList<T>();

    for (i = 0; i < nuevList1; i++)
        menores->insertAtTail(arr->getPos(leftIndx + i)->getDato()); //crea la nueva lista con los menores
    for (j = 0; j < nuevList2; j++)
         mayores->insertAtTail(arr->getPos(pivote + 1 + j)->getDato()); //crea la nueva lista con los mayores
    i = 0;
    j = 0;
    k = leftIndx;
    while (i < nuevList1 && j < nuevList2)
    {
        if (menores->getPos(i)->getDato() <= mayores->getPos(j)->getDato()) // si menores[i] <= mayores[j]
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

/*(pila)*/
template <class T>
void MainWindow::MergeSort(Stack<T> *arr, int leftIndx, int rightIndx) /* INDICES IZQUIERDOS Y DERECHOS DE LA LISTA*/
{
    if (leftIndx < rightIndx)
    {
        int pivote = leftIndx+(rightIndx-leftIndx)/2;
        MergeSort(arr, leftIndx, pivote);
        MergeSort(arr, pivote+1, rightIndx);
        Merge(arr, leftIndx, pivote, rightIndx);
    }
}

template <class T>
void MainWindow::Merge(Stack<T> *arr, int leftIndx, int pivote, int rigthIndx)
{
    int i, j, k; //INDICES DE LOS CICLOS
    int nuevList1 = pivote - leftIndx + 1; //TAMANO DE LA PRIMERA LISTA NUEVA
    int nuevList2 =  rigthIndx - pivote; //TAMANO DE LA SEGUNDA LISTA NUEVA
    Stack<T> *menores = new Stack<T>();
    Stack<T> *mayores = new Stack<T>();

    for (i = 0; i < nuevList1; i++)
        menores->push(arr->getPos(leftIndx + i)->getDato()); //crea la nueva lista con los menores
    for (j = 0; j < nuevList2; j++)
         mayores->push(arr->getPos(pivote + 1 + j)->getDato()); //crea la nueva lista con los mayores
    mayores = invertirPila(mayores);
    menores = invertirPila(menores);
    i = 0;
    j = 0;
    k = leftIndx;
    while (i < nuevList1 && j < nuevList2)
    {
        if (menores->getPos(i)->getDato() <= mayores->getPos(j)->getDato()) // si menores[i] <= mayores[j]
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

template <class T>
Stack<T>* MainWindow::invertirPila(Stack<T> *arr) //metodo auxiliar para el merge con pila
{
    Stack<T> *temp = new Stack<T>();
    while(arr->getSize() > 0)
        temp->push(arr->pop());
    return temp;
}

/*Cola*/
template <class T>
void MainWindow::MergeSort(Queue<T> *arr, int leftIndx, int rightIndx) /* INDICES IZQUIERDOS Y DERECHOS DE LA LISTA*/
{
    if (leftIndx < rightIndx)
    {
        int pivote = leftIndx+(rightIndx-leftIndx)/2;
        MergeSort(arr, leftIndx, pivote);
        MergeSort(arr, pivote+1, rightIndx);
        Merge(arr, leftIndx, pivote, rightIndx);
    }
}

template <class T>
void MainWindow::Merge(Queue<T> *arr, int leftIndx, int pivote, int rigthIndx)
{
    int i, j, k; //INDICES DE LOS CICLOS
    int nuevList1 = pivote - leftIndx + 1; //TAMANO DE LA PRIMERA LISTA NUEVA
    int nuevList2 =  rigthIndx - pivote; //TAMANO DE LA SEGUNDA LISTA NUEVA
    Queue<T> *menores = new Queue<T>();
    Queue<T> *mayores = new Queue<T>();

    for (i = 0; i < nuevList1; i++)
        menores->enqueue(arr->getPos(leftIndx + i)->getDato()); //crea la nueva lista con los menores
    for (j = 0; j < nuevList2; j++)
         mayores->enqueue(arr->getPos(pivote + 1 + j)->getDato()); //crea la nueva lista con los mayores
    i = 0;
    j = 0;
    k = leftIndx;
    while (i < nuevList1 && j < nuevList2)
    {
        if (menores->getPos(i)->getDato() <= mayores->getPos(j)->getDato()) // si menores[i] <= mayores[j]
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
        if (arr->getPos(j)->dato <= pivot->dato)//changes acording to which one is higher
        {
          i++;
          arr->swap(i,j);
          movements.push_back(movement(i,j));
        }
    }
    arr->swap((i+ 1),high);
    movements.push_back(movement(i,high));
    return( i + 1 );
}

/*lista doble*/
template<class T>
void MainWindow::QuickSort(DobleList<T> *arr, int low, int high) //Metodo para la lista simple
{
    if (low < high){
        int pi = partition(arr, low, high);
        QuickSort(arr, low, pi - 1);//Makes a new group with the highers
        QuickSort(arr, pi + 1, high);//Makes a new group with the lowers
      }
}

template<class T>
int MainWindow::partition(DobleList<T> *arr, int low, int high)
{
    DobleNode<T>* pivot = arr->getPos(high);
    int i = (low - 1);
    for (int j = low; j <= (high - 1); j++)
    {
        if (arr->getPos(j)->getDato() <= pivot->getDato()) //changes acording to which one is higher
        {
          i++;
          arr->swap(i,j);
          movements.push_back(movement(i,j));
        }
    }
    arr->swap((i+ 1),high);
    movements.push_back(movement(i,high));
    return( i + 1 );
}

/*lista doble circular*/
template<class T>
void MainWindow::QuickSort(DCList<T> *arr, int low, int high) //Metodo para la lista simple
{
    if (low < high){
        int pi = partition(arr, low, high);
        QuickSort(arr, low, pi - 1);//Makes a new group with the highers
        QuickSort(arr, pi + 1, high);//Makes a new group with the lowers
      }
}

template<class T>
int MainWindow::partition(DCList<T> *arr, int low, int high)
{
    DobleNode<T>* pivot = arr->getPos(high);
    int i = (low - 1);
    for (int j = low; j <= (high - 1); j++)
    {
        if (arr->getPos(j)->getDato() <= pivot->getDato()) //changes acording to which one is higher
        {
          i++;
          arr->swap(i,j);
          movements.push_back(movement(i,j));
        }
    }
    arr->swap((i+ 1),high);
    movements.push_back(movement(i,high));
    return( i + 1 );
}

/*Pila*/
template<class T>
void MainWindow::QuickSort(Stack<T> *arr, int low, int high) //Metodo para la lista simple
{
    if (low < high){
        int pi = partition(arr, low, high);
        QuickSort(arr, low, pi - 1);//Makes a new group with the highers
        QuickSort(arr, pi + 1, high);//Makes a new group with the lowers
      }
}

template<class T>
int MainWindow::partition(Stack<T> *arr, int low, int high)
{
    SimpleNode<T>* pivot = arr->getPos(high);
    int i = (low - 1);
    for (int j = low; j <= (high - 1); j++)
    {
        if (arr->getPos(j)->dato <= pivot->dato)//changes acording to which one is higher
        {
          i++;
          arr->swap(i,j);
          movements.push_back(movement(i,j));
        }
    }
    arr->swap((i+ 1),high);
    movements.push_back(movement(i,high));
    return( i + 1 );
}

/*cola*/
template<class T>
void MainWindow::QuickSort(Queue<T> *arr, int low, int high) //Metodo para la lista simple
{
    if (low < high){
        int pi = partition(arr, low, high);
        QuickSort(arr, low, pi - 1);//Makes a new group with the highers
        QuickSort(arr, pi + 1, high);//Makes a new group with the lowers
      }
}

template<class T>
int MainWindow::partition(Queue<T> *arr, int low, int high)
{
    SimpleNode<T>* pivot = arr->getPos(high);
    int i = (low - 1);
    for (int j = low; j <= (high - 1); j++)
    {
        if (arr->getPos(j)->dato <= pivot->dato)//changes acording to which one is higher
        {
          i++;
          arr->swap(i,j);
          movements.push_back(movement(i,j));
        }
    }
    arr->swap((i+ 1),high);
    movements.push_back(movement(i,high));
    return( i + 1 );
}


/* SELECTION SORT */
template <class T>
void MainWindow::SelectionSort(SimpleList<T> *arr, int tamanio) //lista simple
{
    T atemp;
    int i, j, min_idx;  //indices de ciclos
    for(i = 0; i < tamanio-1; i++)
    {
        min_idx = i;
        for(j = i+1; j < tamanio; j++)
            if(arr->getPos(j)->getDato() < arr->getPos(min_idx)->getDato())
                min_idx = j;
        atemp = arr->getPos(i)->getDato();
        arr->getPos(i)->setDato(arr->getPos(min_idx)->getDato());
        arr->getPos(min_idx)->setDato(atemp);
    }
}

template <class T>
void MainWindow::SelectionSort(DobleList<T> *arr, int tamanio) //lista doble
{
    T atemp;
    int i, j, min_idx;  //indices de ciclos
    for(i = 0; i < tamanio-1; i++)
    {
        min_idx = i;
        for(j = i+1; j < tamanio; j++)
            if(arr->getPos(j)->getDato() < arr->getPos(min_idx)->getDato())
                min_idx = j;
        atemp = arr->getPos(i)->getDato();
        arr->getPos(i)->setDato(arr->getPos(min_idx)->getDato());
        arr->getPos(min_idx)->setDato(atemp);
    }
}

template <class T>
void MainWindow::SelectionSort(DCList<T> *arr, int tamanio) //lista doble circular
{
    T atemp;
    int i, j, min_idx;  //indices de ciclos
    for(i = 0; i < tamanio-1; i++)
    {
        min_idx = i;
        for(j = i+1; j < tamanio; j++)
            if(arr->getPos(j)->getDato() < arr->getPos(min_idx)->getDato())
                min_idx = j;
        atemp = arr->getPos(i)->getDato();
        arr->getPos(i)->setDato(arr->getPos(min_idx)->getDato());
        arr->getPos(min_idx)->setDato(atemp);
    }
}

template <class T>
void MainWindow::SelectionSort(Stack<T> *arr, int tamanio) //pila
{
    T atemp;
    int i, j, min_idx;  //indices de ciclos
    for(i = 0; i < tamanio-1; i++)
    {
        min_idx = i;
        for(j = i+1; j < tamanio; j++)
            if(arr->getPos(j)->getDato() < arr->getPos(min_idx)->getDato())
                min_idx = j;
        atemp = arr->getPos(i)->getDato();
        arr->getPos(i)->setDato(arr->getPos(min_idx)->getDato());
        arr->getPos(min_idx)->setDato(atemp);
    }
}

template <class T>
void MainWindow::SelectionSort(Queue<T> *arr, int tamanio) //cola
{
    T atemp;
    int i, j, min_idx;  //indices de ciclos
    for(i = 0; i < tamanio-1; i++)
    {
        min_idx = i;
        for(j = i+1; j < tamanio; j++)
            if(arr->getPos(j)->getDato() < arr->getPos(min_idx)->getDato())
                min_idx = j;
        atemp = arr->getPos(i)->getDato();
        arr->getPos(i)->setDato(arr->getPos(min_idx)->getDato());
        arr->getPos(min_idx)->setDato(atemp);
    }
}



/* RADIX SORT */
template<class T>
void MainWindow::RadixSort(SimpleList<T> *arr) //radix de lista simple
{
    if(typeid(T) == typeid(string))
    {
        SimpleList<T> *baldes[26];
        for(int i = 0; i < 26; i++)
            baldes[i] = new SimpleList<T>();
        radixAux(arr, baldes, 12, 26);
    }
    else if(typeid(T) == typeid(char))
    {
        SimpleList<T> *baldes[26];
        for(int i = 0; i < 26; i++)
            baldes[i] = new SimpleList<T>();
        radixAux(arr, baldes, 1, 26);

    }
    else if(typeid(T) == typeid(int))
    {
        SimpleList<T> *baldes [10];
        for(int i = 0; i < 10; i++)
            baldes[i] = new SimpleList<T>();
        int digits = mayorCantidadDigitos(arr);
        radixAux(arr, baldes, digits, 10);
    }

    else
    {
        /*CODIGO PARA LA COMPARACION DE OBJETOS*/
    }
}

/*METODO AUXILIAR QUE DISTRIBUYE EN LAS LISTAS Y HACE CADA CICLO*/
template<class T>
void MainWindow::radixAux(SimpleList<T>* arr, SimpleList<T>* baldes[] ,int iterations, int tamArreglo)
{
    if(typeid(T) == typeid(string))
    {
        int i = 0, digit;
        SimpleNode<T> *aux;
        while(i < iterations)
        {
            aux = arr->getHead();
            while(aux)
            {
                digit = (aux->getDato() - 'a'); //calculo del indice segun letras
                baldes[digit]->insertAtTail(aux->getDato());
                aux = aux->getNext();
            }
            arr->~SimpleList();
            radixVaciarAux(arr, baldes, tamArreglo);
            i++;
        }
    }

    if(typeid(T) == typeid(int))
    {
        int i = 0, pot = 0, digit;
        SimpleNode<T> *aux;
        while(i < iterations)
        {
            aux = arr->getHead();
            while(aux)
            {
                digit = ((aux->getDato()/(int)pow(10,pot)) % 10); //calculo del indice segun numeros
                baldes[digit]->insertAtTail(aux->getDato());
                aux = aux->getNext();
            }
            arr->~SimpleList();
            radixVaciarAux(arr, baldes, tamArreglo);
            pot++;
            i++;
        }
    }

    if(typeid(T) == typeid(char))
    {
        int i = 0, digit;
        SimpleNode<T> *aux;
        while(i < iterations)
        {
            aux = arr->getHead();
            while(aux)
            {
                digit = (aux->getDato() - 'a'); //calculo del indice segun letras
                baldes[digit]->insertAtTail(aux->getDato());
                aux = aux->getNext();
            }
            arr->~SimpleList();
            radixVaciarAux(arr, baldes, tamArreglo);
            i++;
        }
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
int MainWindow::mayorCantidadLetras(SimpleList<string> *arr)
{
    SimpleNode<string>* aux = arr->getHead();
    int result = 0;
    while(aux)
    {
        string word = aux->getDato();
        if(word.size() > result)
            result = word.size();
        aux = aux->getNext();

    }
    return result;
}



/* HEAP SORT */
template <class T>
void MainWindow::HeapSort(SimpleList<T> *arr) //lista simple
{
    int tamano = arr->getSize();

    for(int i = tamano / 2 - 1; i >= 0; i--)
        HeapSortAux(arr, tamano, i);

    for(int i = tamano - 1; i >= 0; i--)
    {
        //cambio de los valores
        T temp = arr->getPos(i)->getDato();
        arr->getPos(i)->setDato(arr->getPos(0)->getDato());
        arr->getPos(0)->setDato(temp);

        HeapSortAux(arr, i, 0);
    }

}

/*METODO AUXILIAR*/
template <class T>
void MainWindow::HeapSortAux(SimpleList<T> *arr, int largo, int aTratar)
{
    int mayor = aTratar;
    int izq = 2*aTratar + 1; //hijo izquierdo en la lista
    int der = 2*aTratar + 2; //hijo derecho en la lista

    //si el hijo izquierdo es mayor que el padre
    if(izq < largo && (arr->getPos(izq)->getDato() > arr->getPos(mayor)->getDato()))
        mayor = izq;

    //si el hijo derecho es mayor que el padre
    if(der < largo && (arr->getPos(der)->getDato() > arr->getPos(mayor)->getDato()))
        mayor = der;

    if(mayor != aTratar)
    {
        //Cambio del largo y el aTratar
        T temp = arr->getPos(mayor)->getDato();
        arr->getPos(mayor)->setDato(arr->getPos(aTratar)->getDato());
        arr->getPos(aTratar)->setDato(temp);

        HeapSortAux(arr, largo, mayor);
    }
}

template <class T>
void MainWindow::HeapSort(DobleList<T> *arr) //lista doble
{
    int tamano = arr->getSize();

    for(int i = tamano / 2 - 1; i >= 0; i--)
        HeapSortAux(arr, tamano, i);

    for(int i = tamano - 1; i >= 0; i--)
    {
        //cambio de los valores
        T temp = arr->getPos(i)->getDato();
        arr->getPos(i)->setDato(arr->getPos(0)->getDato());
        arr->getPos(0)->setDato(temp);

        HeapSortAux(arr, i, 0);
    }

}

template <class T>
void MainWindow::HeapSortAux(DobleList<T> *arr, int largo, int aTratar)
{
    int mayor = aTratar;
    int izq = 2*aTratar + 1; //hijo izquierdo en la lista
    int der = 2*aTratar + 2; //hijo derecho en la lista

    //si el hijo izquierdo es mayor que el padre
    if(izq < largo && (arr->getPos(izq)->getDato() > arr->getPos(mayor)->getDato()))
        mayor = izq;

    //si el hijo derecho es mayor que el padre
    if(der < largo && (arr->getPos(der)->getDato() > arr->getPos(mayor)->getDato()))
        mayor = der;

    if(mayor != aTratar)
    {
        //Cambio del largo y el aTratar
        T temp = arr->getPos(mayor)->getDato();
        arr->getPos(mayor)->setDato(arr->getPos(aTratar)->getDato());
        arr->getPos(aTratar)->setDato(temp);

        HeapSortAux(arr, largo, mayor);
    }
}

template <class T>
void MainWindow::HeapSort(DCList<T> *arr) //lista doble circular
{
    int tamano = arr->getSize();

    for(int i = tamano / 2 - 1; i >= 0; i--)
        HeapSortAux(arr, tamano, i);

    for(int i = tamano - 1; i >= 0; i--)
    {
        //cambio de los valores
        T temp = arr->getPos(i)->getDato();
        arr->getPos(i)->setDato(arr->getPos(0)->getDato());
        arr->getPos(0)->setDato(temp);

        HeapSortAux(arr, i, 0);
    }

}

template <class T>
void MainWindow::HeapSortAux(DCList<T> *arr, int largo, int aTratar)
{
    int mayor = aTratar;
    int izq = 2*aTratar + 1; //hijo izquierdo en la lista
    int der = 2*aTratar + 2; //hijo derecho en la lista

    //si el hijo izquierdo es mayor que el padre
    if(izq < largo && (arr->getPos(izq)->getDato() > arr->getPos(mayor)->getDato()))
        mayor = izq;

    //si el hijo derecho es mayor que el padre
    if(der < largo && (arr->getPos(der)->getDato() > arr->getPos(mayor)->getDato()))
        mayor = der;

    if(mayor != aTratar)
    {
        //Cambio del largo y el aTratar
        T temp = arr->getPos(mayor)->getDato();
        arr->getPos(mayor)->setDato(arr->getPos(aTratar)->getDato());
        arr->getPos(aTratar)->setDato(temp);

        HeapSortAux(arr, largo, mayor);
    }
}

template <class T>
void MainWindow::HeapSort(Stack<T> *arr) //pila
{
    int tamano = arr->getSize();

    for(int i = tamano / 2 - 1; i >= 0; i--)
        HeapSortAux(arr, tamano, i);

    for(int i = tamano - 1; i >= 0; i--)
    {
        //cambio de los valores
        T temp = arr->getPos(i)->getDato();
        arr->getPos(i)->setDato(arr->getPos(0)->getDato());
        arr->getPos(0)->setDato(temp);

        HeapSortAux(arr, i, 0);
    }

}

template <class T>
void MainWindow::HeapSortAux(Stack<T> *arr, int largo, int aTratar)
{
    int mayor = aTratar;
    int izq = 2*aTratar + 1; //hijo izquierdo en la lista
    int der = 2*aTratar + 2; //hijo derecho en la lista

    //si el hijo izquierdo es mayor que el padre
    if(izq < largo && (arr->getPos(izq)->getDato() > arr->getPos(mayor)->getDato()))
        mayor = izq;

    //si el hijo derecho es mayor que el padre
    if(der < largo && (arr->getPos(der)->getDato() > arr->getPos(mayor)->getDato()))
        mayor = der;

    if(mayor != aTratar)
    {
        //Cambio del largo y el aTratar
        T temp = arr->getPos(mayor)->getDato();
        arr->getPos(mayor)->setDato(arr->getPos(aTratar)->getDato());
        arr->getPos(aTratar)->setDato(temp);

        HeapSortAux(arr, largo, mayor);
    }
}

template <class T>
void MainWindow::HeapSort(Queue<T> *arr) //cola
{
    int tamano = arr->getSize();

    for(int i = tamano / 2 - 1; i >= 0; i--)
        HeapSortAux(arr, tamano, i);

    for(int i = tamano - 1; i >= 0; i--)
    {
        //cambio de los valores
        T temp = arr->getPos(i)->getDato();
        arr->getPos(i)->setDato(arr->getPos(0)->getDato());
        arr->getPos(0)->setDato(temp);

        HeapSortAux(arr, i, 0);
    }

}

template <class T>
void MainWindow::HeapSortAux(Queue<T> *arr, int largo, int aTratar)
{
    int mayor = aTratar;
    int izq = 2*aTratar + 1; //hijo izquierdo en la lista
    int der = 2*aTratar + 2; //hijo derecho en la lista

    //si el hijo izquierdo es mayor que el padre
    if(izq < largo && (arr->getPos(izq)->getDato() > arr->getPos(mayor)->getDato()))
        mayor = izq;

    //si el hijo derecho es mayor que el padre
    if(der < largo && (arr->getPos(der)->getDato() > arr->getPos(mayor)->getDato()))
        mayor = der;

    if(mayor != aTratar)
    {
        //Cambio del largo y el aTratar
        T temp = arr->getPos(mayor)->getDato();
        arr->getPos(mayor)->setDato(arr->getPos(aTratar)->getDato());
        arr->getPos(aTratar)->setDato(temp);

        HeapSortAux(arr, largo, mayor);
    }
}

/* SHELL SORT */
 template <class T>
void MainWindow::ShellSort(SimpleList<T> *arr, int tamano) //lista simple
{
    for (int gap = tamano/2; gap > 0; gap = gap/2)
        for(int i = gap; i < tamano; i += 1)
        {
            T temp =  arr->getPos(i)->getDato();
            int j;
            for(j = i; j >= gap && arr->getPos(j-gap)->getDato() > temp; j -= gap)
                arr->getPos(j)->setDato(arr->getPos(j-gap)->getDato());
             arr->getPos(j)->setDato(temp);
        }
}

template <class T>
void MainWindow::ShellSort(DobleList<T> *arr, int tamano) //lista doble
{
   for (int gap = tamano/2; gap > 0; gap = gap/2)
       for(int i = gap; i < tamano; i += 1)
       {
           T temp =  arr->getPos(i)->getDato();
           int j;
           for(j = i; j >= gap && arr->getPos(j-gap)->getDato() > temp; j -= gap)
               arr->getPos(j)->setDato(arr->getPos(j-gap)->getDato());
            arr->getPos(j)->setDato(temp);
       }
}

template <class T>
void MainWindow::ShellSort(DCList<T> *arr, int tamano) //lista doble circular
{
   for (int gap = tamano/2; gap > 0; gap = gap/2)
       for(int i = gap; i < tamano; i += 1)
       {
           T temp =  arr->getPos(i)->getDato();
           int j;
           for(j = i; j >= gap && arr->getPos(j-gap)->getDato() > temp; j -= gap)
               arr->getPos(j)->setDato(arr->getPos(j-gap)->getDato());
            arr->getPos(j)->setDato(temp);
       }
}

template <class T>
void MainWindow::ShellSort(Stack<T> *arr, int tamano) //pila
{
   for (int gap = tamano/2; gap > 0; gap = gap/2)
       for(int i = gap; i < tamano; i += 1)
       {
           T temp =  arr->getPos(i)->getDato();
           int j;
           for(j = i; j >= gap && arr->getPos(j-gap)->getDato() > temp; j -= gap)
               arr->getPos(j)->setDato(arr->getPos(j-gap)->getDato());
            arr->getPos(j)->setDato(temp);
       }
}

template <class T>
void MainWindow::ShellSort(Queue<T> *arr, int tamano) //cola
{
   for (int gap = tamano/2; gap > 0; gap = gap/2)
       for(int i = gap; i < tamano; i += 1)
       {
           T temp =  arr->getPos(i)->getDato();
           int j;
           for(j = i; j >= gap && arr->getPos(j-gap)->getDato() > temp; j -= gap)
               arr->getPos(j)->setDato(arr->getPos(j-gap)->getDato());
            arr->getPos(j)->setDato(temp);
       }
}

/*METODO PARA LA OBTENCION ALEATORIA DE N PALABRAS (N = CANTIDAD)*/
void MainWindow::buildWords(SimpleList<string> *arr, int cantidad)
{
    srand(time(NULL));

    int indice;
    for(int i = 0; i < cantidad; i++)
    {
        indice = rand() % 1000 + 1;
        string palabra (buildWordsAux(indice));
        arr->insertAtTail(palabra);
    }
}

string MainWindow::buildWordsAux(int indice)
{
    ifstream file("/home/retr0/Escritorio/Datos/ED_Progra_1/Primer_Proyecto_Programado/palabras.txt");
    string palabra;
    int j = 1;
    while(getline(file, palabra) && j <= indice)
    {
        if(j == indice)
            break;
        j++;
    }
    return palabra;
}

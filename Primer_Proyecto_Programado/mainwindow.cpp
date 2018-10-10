#include "mainwindow.h"
#include "ui_mainwindow.h"

/* FUNCTION FOR DELAYING SORTING GUI */
void delay(int n = 1000)
{
    QTime dieTime= QTime::currentTime().addMSecs(n);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->sbxRango2->setMinimum(ui->sbxRango1->value()+1);
    ui->rbtnAdelante->setChecked(true);
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
        text = scene->addText(qstr, QFont("Arial",12));
        text->setPos(QPointF(i*50,-30));
        texts.push_back(text);
        QGraphicsLineItem *line = scene->addLine(i*50,0,i*50 + 40,0,Qt::SolidLine);
        line->setPen(QPen(Qt::red));
    }

}

void MainWindow::Swap(int pos1, int pos2)
{
    text = texts[pos1];
    text2 = texts[pos2];
    QPropertyAnimation *animation4 = new QPropertyAnimation(text2, "x", this);
    QPropertyAnimation *animation3 = new QPropertyAnimation(text,"x",this);
    text->setDefaultTextColor(Qt::red);
    text2->setDefaultTextColor(Qt::red);
    animation3->setDuration(500);
    animation3->setStartValue(50*pos1);
    animation3->setEndValue(50*pos2);
    animation3->setEasingCurve(QEasingCurve::Linear);
    animation4->setDuration(500);
    animation4->setStartValue(50*pos2);
    animation4->setEndValue(50*pos1);
    animation4->setEasingCurve(QEasingCurve::Linear);
    animation3->start();
    animation4->start();
    iter_swap(texts.begin() + pos1, texts.begin() + pos2);
    delay();
    text->setDefaultTextColor(Qt::black);
    text2->setDefaultTextColor(Qt::black);

}
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnRandom_clicked()
{
    srand(time(NULL));
    if(ui->cbxEstructura->currentText() == "Lista Simple")
    {
        if(ui->cbxDato->currentText() == "Enteros")
        {
            delete intSimpList;
            intSimpList = new SimpleList<int>();
            int cantidad = ui->sbxCantidad->value();
            int valor;
            int sup = ui->sbxRango2->value();
            int inf = ui->sbxRango1->value();
            for(int i = 0; i<cantidad;i++)
            {
                valor = rand() % ((sup - inf) + 1) + inf;
                intSimpList->insertAtHead(valor);
            }
            scene->clear();;
            GenerateBoxes(intSimpList);
        }/*if de enteros*/
        else if(ui->cbxDato->currentText() == "Letras")
        {

        }
    }/*if de lista simple*/
}

void MainWindow::on_btnQuick_clicked()
{
    intSimpList->print();
    DobleBubble(*intSimpList, intSimpList->getSize()-1);
    //Swap(1,2);
    intSimpList->print();
}

void MainWindow::on_cbxDato_currentTextChanged(const QString &arg1)
{
    if(ui->cbxDato->currentText() == "Enteros")
    {
        ui->sbxRango1->setEnabled(true);
        ui->sbxRango2->setEnabled(true);
        ui->sbxCantidad->setMinimum(10);
        ui->sbxCantidad->setMaximum(100);
    }
    else if(ui->cbxDato->currentText() == "Palabras")
    {
        ui->sbxRango1->setEnabled(false);
        ui->sbxRango2->setEnabled(false);
        ui->sbxCantidad->setMinimum(10);
        ui->sbxCantidad->setMaximum(100);
    }

    else if(ui->cbxDato->currentText() == "Letras")
    {
        //ui->lblCantidadDatos->set
        ui->sbxRango1->setEnabled(false);
        ui->sbxRango2->setEnabled(false);
        ui->sbxCantidad->setMinimum(2);
        ui->sbxCantidad->setMaximum(27);
    }
}



/* ALGORITMOS DE ORDENAMIENTO */


/* INSERTION SORT */
template <class T>
void MainWindow::InsertionSort(SimpleList<T> *arr) //sobrecarga para la lista doble
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
            movements.push_back(movement(j+1,j));
        }
        arr->getPos(j)->setDato(actual);
        movements.push_back(movement(j+1,i));
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
            movements.push_back(movement(j+1,j));
        }
        arr->getPos(j)->setDato(actual);
        movements.push_back(movement(j+1,i));
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
            movements.push_back(movement(j+1,j));
        }
        arr->getPos(j)->setDato(actual);
        movements.push_back(movement(j+1,i));
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
            movements.push_back(movement(j+1,j));
        }
        arr->getPos(j)->setDato(actual);
        movements.push_back(movement(j+1,i));
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
            movements.push_back(movement(j+1,j));
        }
        arr->getPos(j)->setDato(actual);
        movements.push_back(movement(j+1,i));
    }
}


/* MERGE SORT */

void MainWindow::MergeAnimation(int i,int pos1, int pos2)
{
    return;
    QGraphicsLineItem *line = scene->addLine(pos1,i*20,pos2,i*20,Qt::DashLine);
    line->setPen(QPen(Qt::red));
    lines.push_back(line);
}

template <class T>
void MainWindow::MergeSort(SimpleList<T> *arr, int leftIndx, int rightIndx,int animationIndx) /* INDICES IZQUIERDOS Y DERECHOS DE LA LISTA*/
{
    if (leftIndx < rightIndx)
    {
        int pivote = leftIndx+(rightIndx-leftIndx)/2;
        MergeSort(arr, leftIndx, pivote,animationIndx + 1);
        MergeSort(arr, pivote+1, rightIndx,animationIndx + 1);
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
        movements.push_back(movement(min_idx,i));
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
        movements.push_back(movement(min_idx,i));
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
        movements.push_back(movement(min_idx,i));
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
        movements.push_back(movement(min_idx,i));
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
        movements.push_back(movement(min_idx,i));
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
            {
                arr->getPos(j)->setDato(arr->getPos(j-gap)->getDato());
                movements.push_back(movement(j,j - gap));
            }
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
           {
               arr->getPos(j)->setDato(arr->getPos(j-gap)->getDato());
               movements.push_back(movement(j,j - gap));
           }
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
           {
               arr->getPos(j)->setDato(arr->getPos(j-gap)->getDato());
               movements.push_back(movement(j,j - gap));
           }
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
           {
               arr->getPos(j)->setDato(arr->getPos(j-gap)->getDato());
               movements.push_back(movement(j,j - gap));
           }
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
           {
               arr->getPos(j)->setDato(arr->getPos(j-gap)->getDato());
               movements.push_back(movement(j,j - gap));
           }
            arr->getPos(j)->setDato(temp);
       }
}


/* BUBBLE SORT */
template<class T>
void MainWindow::BubbleSort(SimpleList<T> *arr)
{
    int i,j,n;
    n = arr->getSize();
    for (i = 0; i< n-1; i++)
    {
        for(j = 0; j<n-i-1; j++)
        {
            if(arr->getPos(j)->getDato() > arr->getPos(j+1)->getDato())
            {
                arr->swap(j,j+1);
                movements.push_back(movement(j,j+1));
            }
        }
    }
}

template<class T>
void MainWindow::BubbleSort(DobleList<T> *arr)
{
    int i,j,n;
    n = arr->gettSize();
    for (i = 0; i< n-1; i++)
    {
        for(j = 0; j<n-i-1; j++)
        {
            if(arr->getPos(j)->getDato() > arr->getPos(j+1)->getDato())
            {
                arr.swap(j,j+1);
                movements.push_back(movement(j,j+1));
            }
        }
    }
}
template<class T>
void MainWindow::BubbleSort(DCList<T> *arr)
{
    int i,j,n;
    n = arr->getSize();
    for (i = 0; i< n-1; i++)
    {
        for(j = 0; j<n-i-1; j++)
        {
            if(arr->getPos(j)->getDato() > arr->getPos(j+1)->getDato())
            {
                arr->swap(j,j+1);
                movements.push_back(movement(j,j+1));
            }
        }
    }
}
template<class T>
void MainWindow::BubbleSort(Stack<T> *arr)
{
    int i,j,n;
    n = arr->getSize();
    for (i = 0; i< n-1; i++)
    {
        for(j = 0; j<n-i-1; j++)
        {
            if(arr->getPos(j)->getDato() > arr->getPos(j+1)->getDato())
            {
                arr->swap(j,j+1);
                movements.push_back(movement(j,j+1));
            }
        }
    }
}
template<class T>
void MainWindow::BubbleSort(Queue<T> *arr)
{
    int i,j,n;
    n = arr->getSize();
    for (i = 0; i< n-1; i++)
    {
        for(j = 0; j<n-i-1; j++)
        {
            if(arr->getPos(j)->getDato() > arr->getPos(j+1)->getDato())
            {
                arr->swap(j,j+1);
                movements.push_back(movement(j,j+1));
            }
        }
    }
}

/* BUBBLEDOBLE */
template<class T>
void MainWindow::DobleBubble(SimpleList<T> &arr, int end)
{
    bool permutation;
    int en_cours = 0, sens = 1;
    int debut = 1;
    do
    {
        permutation = false;
        while (((sens == 1) && (en_cours < end)) || ((sens == -1) && (en_cours > debut)))
        {
            en_cours += sens;
            SimpleNode<T> a = *arr[en_cours];
            SimpleNode<T> b = *arr[en_cours-1];
            if (a < b)
            {
                arr.swap(en_cours,en_cours-1);
                movements.push_back(movement(en_cours,en_cours - 1));
                permutation = true;
            }
        }
        if (sens==1) end--; else debut++;
        sens = -sens;
    }
    while (permutation);
}

template<class T>
void MainWindow::DobleBubble(DobleList<T> *arr, int end) //lista doble
{
    bool permutation;
    int en_cours = 0, sens = 1;
    int debut = 1;
    do
    {
        permutation = false;
        while (((sens == 1) && (en_cours < end)) || ((sens == -1) && (en_cours > debut)))
        {
            en_cours += sens;
            if (arr->getPos(en_cours)->getDato() < arr->getPos(en_cours-1)->getDato())
            {
                arr->swap(en_cours,en_cours-1);
                movements.push_back(movement(en_cours,en_cours - 1));
                permutation = true;
            }
        }
        if (sens==1) end--; else debut++;
        sens = -sens;
    }
    while (permutation);
}

template<class T>
void MainWindow::DobleBubble(DCList<T> *arr, int end) //lista doble circular
{
    bool permutation;
    int en_cours = 0, sens = 1;
    int debut = 1;
    do
    {
        permutation = false;
        while (((sens == 1) && (en_cours < end)) || ((sens == -1) && (en_cours > debut)))
        {
            en_cours += sens;
            if (arr->getPos(en_cours)->getDato() < arr->getPos(en_cours-1)->getDato())
            {
                arr->swap(en_cours,en_cours-1);
                movements.push_back(movement(en_cours,en_cours - 1));
                permutation = true;
            }
        }
        if (sens==1) end--; else debut++;
        sens = -sens;
    }
    while (permutation);
}

template<class T>
void MainWindow::DobleBubble(Stack<T> *arr, int end) //pila
{
    bool permutation;
    int en_cours = 0, sens = 1;
    int debut = 1;
    do
    {
        permutation = false;
        while (((sens == 1) && (en_cours < end)) || ((sens == -1) && (en_cours > debut)))
        {
            en_cours += sens;
            if (arr->getPos(en_cours)->getDato() < arr->getPos(en_cours-1)->getDato())
            {
                arr->swap(en_cours,en_cours-1);
                movements.push_back(movement(en_cours,en_cours - 1));
                permutation = true;
            }
        }
        if (sens==1) end--; else debut++;
        sens = -sens;
    }
    while (permutation);
}

template<class T>
void MainWindow::DobleBubble(Queue<T> *arr, int end) //cola
{
    bool permutation;
    int en_cours = 0, sens = 1;
    int debut = 1;
    do
    {
        permutation = false;
        while (((sens == 1) && (en_cours < end)) || ((sens == -1) && (en_cours > debut)))
        {
            en_cours += sens;
            if (arr->getPos(en_cours)->getDato() < arr->getPos(en_cours-1)->getDato())
            {
                arr->swap(en_cours,en_cours-1);
                movements.push_back(movement(en_cours,en_cours - 1));
                permutation = true;
            }
        }
        if (sens==1) end--; else debut++;
        sens = -sens;
    }
    while (permutation);
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

/*Metodo que saca una palabra aleatoriamente*/
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

void MainWindow::on_sbxRango1_valueChanged(int arg1)
{
    ui->sbxRango2->setMinimum(arg1+1);
}

void MainWindow::on_sbxRango2_valueChanged(int arg1)
{
    ui->sbxRango1->setMaximum(arg1-1);
}

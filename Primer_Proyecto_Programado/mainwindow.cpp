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
        string str;
        AnimationString temp(list->getPos(i)->getDato());
        str = temp.getString();
        QString qstr = QString::fromStdString(str);
        text = scene->addText(qstr, QFont("Arial",12));
        text->setPos(QPointF(i*50,-30));
        texts.push_back(text);
        QGraphicsLineItem *line = scene->addLine(i*50,0,i*50 + 40,0,Qt::SolidLine);
        line->setPen(QPen(Qt::red));
    }
}

template <typename T>
void MainWindow::GenerateBoxes(DobleList<T>* list)
{
    QBrush redBrush(Qt::white);
    QPen outlinePen(Qt::black);
    outlinePen.setWidth(2);
    int size = list->getSize();
    for(int i = 0; i< size; i++)
    {
        string str;
        AnimationString temp(list->getPos(i)->getDato());
        str = temp.getString();
        QString qstr = QString::fromStdString(str);
        text = scene->addText(qstr, QFont("Arial",12));
        text->setPos(QPointF(i*50,-30));
        texts.push_back(text);
        QGraphicsLineItem *line = scene->addLine(i*50,0,i*50 + 40,0,Qt::SolidLine);
        line->setPen(QPen(Qt::red));
    }
}

template <typename T>
void MainWindow::GenerateBoxes(DCList<T>* list)
{
    QBrush redBrush(Qt::white);
    QPen outlinePen(Qt::black);
    outlinePen.setWidth(2);
    int size = list->getSize();
    for(int i = 0; i< size; i++)
    {
        string str;
        AnimationString temp(list->getPos(i)->getDato());
        str = temp.getString();
        QString qstr = QString::fromStdString(str);
        text = scene->addText(qstr, QFont("Arial",12));
        text->setPos(QPointF(i*50,-30));
        texts.push_back(text);
        QGraphicsLineItem *line = scene->addLine(i*50,0,i*50 + 40,0,Qt::SolidLine);
        line->setPen(QPen(Qt::red));
    }
}

template <typename T>
void MainWindow::GenerateBoxes(Stack<T>* list)
{
    QBrush redBrush(Qt::white);
    QPen outlinePen(Qt::black);
    outlinePen.setWidth(2);
    int size = list->getSize();
    for(int i = 0; i< size; i++)
    {
        string str;
        AnimationString temp(list->getPos(i)->getDato());
        str = temp.getString();
        QString qstr = QString::fromStdString(str);
        text = scene->addText(qstr, QFont("Arial",12));
        text->setPos(QPointF(i*50,-30));
        texts.push_back(text);
        QGraphicsLineItem *line = scene->addLine(i*50,0,i*50 + 40,0,Qt::SolidLine);
        line->setPen(QPen(Qt::red));
    }
}

template <typename T>
void MainWindow::GenerateBoxes(Queue<T>* list)
{
    QBrush redBrush(Qt::white);
    QPen outlinePen(Qt::black);
    outlinePen.setWidth(2);
    int size = list->getSize();
    for(int i = 0; i< size; i++)
    {
        string str;
        AnimationString temp(list->getPos(i)->getDato());
        str = temp.getString();
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
    texts.clear();
    lines.clear();
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
            scene->clear();
            GenerateBoxes(intSimpList);
        }/*if de enteros*/

        else if(ui->cbxDato->currentText() == "Letras")
        {
            delete charSimpList;
            charSimpList = new SimpleList<char>();
            int cantidad = ui->sbxCantidad->value();
            int valor;
            int sup = 122;
            int inf = 97;
            for(int i = 0; i<cantidad;i++)
            {
                valor = rand() % ((sup - inf) + 1) + inf;
                charSimpList->insertAtHead(valor);
            }
            scene->clear();
            charSimpList->print();
            GenerateBoxes(charSimpList);
        }/*else if de letras*/

        else if(ui->cbxDato->currentText() == "Palabras")
        {
            delete strSimpList;
            strSimpList = new SimpleList<string>();
            int cantidad = ui->sbxCantidad->value();
            for(int i = 0; i < cantidad; i++)
            {
                int indice = rand() % 1000 + 1;
                strSimpList->insertAtTail(buildWord(indice));
            }
            scene->clear();
            strSimpList->print();
            GenerateBoxes(strSimpList);
        }/*else if de palabras*/

        else if(ui->cbxDato->currentText() == "Otros")
        {
            //CODIGO DE SOBRECARGA DE METODOS
        }

    }/*if de lista simple*/

    else if(ui->cbxEstructura->currentText() == "Lista Doble")
    {
        if(ui->cbxDato->currentText() == "Enteros")
        {
            delete intDobList;
            intDobList = new DobleList<int>();
            int cantidad = ui->sbxCantidad->value();
            int valor;
            int sup = ui->sbxRango2->value();
            int inf = ui->sbxRango1->value();
            for(int i = 0; i<cantidad;i++)
            {
                valor = rand() % ((sup - inf) + 1) + inf;
                intDobList->insertAtHead(valor);
            }
            scene->clear();
            GenerateBoxes(intDobList);
        }/*if de enteros*/

        else if(ui->cbxDato->currentText() == "Letras")
        {
            delete charDobList;
            charDobList = new DobleList<char>();
            int cantidad = ui->sbxCantidad->value();
            int valor;
            int sup = 122;
            int inf = 97;
            for(int i = 0; i<cantidad;i++)
            {
                valor = rand() % ((sup - inf) + 1) + inf;
                charDobList->insertAtHead(valor);
            }
            scene->clear();
            charDobList->print();
            //GenerateBoxes(charDobList);
        }/*else if de letras*/

        else if(ui->cbxDato->currentText() == "Palabras")
        {
            delete strDoblList;
            strDoblList = new DobleList<string>();
            int cantidad = ui->sbxCantidad->value();
            for(int i = 0; i < cantidad; i++)
            {
                int indice = rand() % 1000 + 1;
                strDoblList->insertAtTail(buildWord(indice));
            }
            scene->clear();
            strDoblList->print();
            GenerateBoxes(strDoblList);
        }/*else if de palabras*/

        else if(ui->cbxDato->currentText() == "Otros")
        {
            //CODIGO DE SOBRECARGA DE METODOS
        }
    }/*if lista doble*/

    else if(ui->cbxEstructura->currentText() == "Lista Doble Circular")
    {
        if(ui->cbxDato->currentText() == "Enteros")
        {
            delete intDClist;
            intDClist = new DCList<int>();
            int cantidad = ui->sbxCantidad->value();
            int valor;
            int sup = ui->sbxRango2->value();
            int inf = ui->sbxRango1->value();
            for(int i = 0; i<cantidad;i++)
            {
                valor = rand() % ((sup - inf) + 1) + inf;
                intDClist->insertAtHead(valor);
            }
            scene->clear();
            intDClist->print();
            GenerateBoxes(intDClist);
        }/*if de enteros*/

        else if(ui->cbxDato->currentText() == "Letras")
        {
            delete charDCList;
            charDCList = new DCList<char>();
            int cantidad = ui->sbxCantidad->value();
            int valor;
            int sup = 122;
            int inf = 97;
            for(int i = 0; i<cantidad;i++)
            {
                valor = rand() % ((sup - inf) + 1) + inf;
                charDCList->insertAtHead(valor);
            }
            scene->clear();
            charDCList->print();
            GenerateBoxes(charDCList);
        }/*else if de letras*/

        else if(ui->cbxDato->currentText() == "Palabras")
        {
            delete strDCList;
            strDCList = new DCList<string>();
            int cantidad = ui->sbxCantidad->value();
            for(int i = 0; i < cantidad; i++)
            {
                int indice = rand() % 1000 + 1;
                strDCList->insertAtTail(buildWord(indice));
            }
            scene->clear();
            strDCList->print();
            GenerateBoxes(strDCList);
        }/*else if de palabras*/

        else if(ui->cbxDato->currentText() == "Otros")
        {
            //CODIGO DE SOBRECARGA DE METODOS
        }
    }/*else if de lista doble circular*/

    else if(ui->cbxEstructura->currentText() == "Pila")
    {
        if(ui->cbxDato->currentText() == "Enteros")
        {
            delete intStack;
            intStack = new Stack<int>();
            int cantidad = ui->sbxCantidad->value();
            int valor;
            int sup = ui->sbxRango2->value();
            int inf = ui->sbxRango1->value();
            for(int i = 0; i<cantidad;i++)
            {
                valor = rand() % ((sup - inf) + 1) + inf;
                intStack->push(valor);
            }
            scene->clear();
            intStack->print();
            GenerateBoxes(intStack);
        }/*if de enteros*/

        else if(ui->cbxDato->currentText() == "Letras")
        {
            delete charStack;
            charStack = new Stack<char>();
            int cantidad = ui->sbxCantidad->value();
            int valor;
            int sup = 122;
            int inf = 97;
            for(int i = 0; i<cantidad;i++)
            {
                valor = rand() % ((sup - inf) + 1) + inf;
                charStack->push(valor);
            }
            scene->clear();
            charStack->print();
            GenerateBoxes(charStack);
        }/*else if de letras*/

        else if(ui->cbxDato->currentText() == "Palabras")
        {
            delete strStack;
            strStack = new Stack<string>();
            int cantidad = ui->sbxCantidad->value();
            for(int i = 0; i < cantidad; i++)
            {
                int indice = rand() % 1000 + 1;
                strStack->push(buildWord(indice));
            }
            scene->clear();
            strStack->print();
            GenerateBoxes(strStack);
        }/*else if de palabras*/

        else if(ui->cbxDato->currentText() == "Otros")
        {
            //CODIGO DE SOBRECARGA DE METODOS
        }
    } /*else if de la pila*/

    else if(ui->cbxEstructura->currentText() == "Cola")
    {
        if(ui->cbxDato->currentText() == "Enteros")
        {
            delete intQueue;
            intQueue = new Queue<int>();
            int cantidad = ui->sbxCantidad->value();
            int valor;
            int sup = ui->sbxRango2->value();
            int inf = ui->sbxRango1->value();
            for(int i = 0; i<cantidad;i++)
            {
                valor = rand() % ((sup - inf) + 1) + inf;
                intQueue->enqueue(valor);
            }
            scene->clear();
            intQueue->print();
            GenerateBoxes(intQueue);
        }/*if de enteros*/

        else if(ui->cbxDato->currentText() == "Letras")
        {
            delete charQueue;
            charQueue = new Queue<char>();
            int cantidad = ui->sbxCantidad->value();
            int valor;
            int sup = 122;
            int inf = 97;
            for(int i = 0; i<cantidad;i++)
            {
                valor = rand() % ((sup - inf) + 1) + inf;
                charQueue->enqueue(valor);
            }
            scene->clear();
            charQueue->print();
            GenerateBoxes(charQueue);
        }/*else if de letras*/

        else if(ui->cbxDato->currentText() == "Palabras")
        {
            delete strQueue;
            strQueue = new Queue<string>();
            int cantidad = ui->sbxCantidad->value();
            for(int i = 0; i < cantidad; i++)
            {
                int indice = rand() % 1000 + 1;
                strQueue->enqueue(buildWord(indice));
            }
            scene->clear();
            strQueue->print();
            GenerateBoxes(strQueue);
        }/*else if de palabras*/

        else if(ui->cbxDato->currentText() == "Otros")
        {
            //CODIGO DE SOBRECARGA DE METODOS
        }
    } /*else if de la cola*/
}


void MainWindow::on_btnQuick_clicked()//QUICK SORT
{
    if(ui->cbxEstructura->currentText() == "Lista Simple")
    {
        if(ui->cbxDato->currentText() == "Enteros")
        {
            QuickSort(*intSimpList, 0,intSimpList->getSize()-1);
            move();
        }
        if(ui->cbxDato->currentText() == "Letras")
        {
            QuickSort(*charSimpList, 0, charSimpList->getSize()-1);
            move();
        }
        if(ui->cbxDato->currentText() == "Palabras")
        {
            QuickSort(*strSimpList, 0, strSimpList->getSize()-1);
            move();
        }
    }
    if(ui->cbxEstructura->currentText() == "Lista Doble")
    {
        if(ui->cbxDato->currentText() == "Enteros")
        {
            QuickSort(*intDobList, 0,intDobList->getSize()-1);
            move();
        }
        if(ui->cbxDato->currentText() == "Letras")
        {
            QuickSort(*charDobList, 0, charDobList->getSize()-1);
            move();
        }
        if(ui->cbxDato->currentText() == "Palabras")
        {
            QuickSort(*strDoblList, 0, strDoblList->getSize()-1);
            move();
        }
    }
    if(ui->cbxEstructura->currentText() == "Lista Doble Circular")
    {
        if(ui->cbxDato->currentText() == "Enteros")
        {
            QuickSort(*intDClist, 0,intDClist->getSize()-1);
            move();
        }
        if(ui->cbxDato->currentText() == "Letras")
        {
            QuickSort(*charDCList, 0, charDCList->getSize()-1);
            move();
        }
        if(ui->cbxDato->currentText() == "Palabras")
        {
            QuickSort(*strDCList, 0, strDCList->getSize()-1);
            move();
        }
    }
    if(ui->cbxEstructura->currentText() == "Pila")
    {
        if(ui->cbxDato->currentText() == "Enteros")
        {
            QuickSort(*intStack, 0,intStack->getSize()-1);
            move();
        }
        if(ui->cbxDato->currentText() == "Letras")
        {
            QuickSort(*charStack, 0, charStack->getSize()-1);
            move();
        }
        if(ui->cbxDato->currentText() == "Palabras")
        {
            QuickSort(*strStack, 0, strStack->getSize()-1);
            move();
        }
    }
    if(ui->cbxEstructura->currentText() == "Cola")
    {
        if(ui->cbxDato->currentText() == "Enteros")
        {
            QuickSort(*intQueue, 0,intQueue->getSize()-1);
            move();
        }
        if(ui->cbxDato->currentText() == "Letras")
        {
            QuickSort(*charQueue, 0, charQueue->getSize()-1);
            move();
        }
        if(ui->cbxDato->currentText() == "Palabras")
        {
            QuickSort(*strQueue, 0, strQueue->getSize()-1);
            move();
        }
    }
}

void MainWindow::on_btnShell_clicked()//SHELL SORT
{
    if(ui->cbxEstructura->currentText() == "Lista Simple")
    {
        if(ui->cbxDato->currentText() == "Enteros")
        {
            ShellSort(*intSimpList, intSimpList->getSize());
            move();
        }
        if(ui->cbxDato->currentText() == "Letras")
        {
            ShellSort(*charSimpList, charSimpList->getSize());
            move();
        }
        if(ui->cbxDato->currentText() == "Palabras")
        {
            ShellSort(*strSimpList, strSimpList->getSize());
            move();
        }
    }
    if(ui->cbxEstructura->currentText() == "Lista Doble")
    {
        if(ui->cbxDato->currentText() == "Enteros")
        {
            ShellSort(*intDobList, intDobList->getSize());
            move();
        }
        if(ui->cbxDato->currentText() == "Letras")
        {
            ShellSort(*charDobList, charDobList->getSize());
            move();
        }
        if(ui->cbxDato->currentText() == "Palabras")
        {
            ShellSort(*strDoblList, strDoblList->getSize());
            move();
        }
    }
    if(ui->cbxEstructura->currentText() == "Lista Doble Circular")
    {
        if(ui->cbxDato->currentText() == "Enteros")
        {
            ShellSort(*intDClist, intDClist->getSize());
            move();
        }
        if(ui->cbxDato->currentText() == "Letras")
        {
            ShellSort(*charDCList, charDCList->getSize());
            move();
        }
        if(ui->cbxDato->currentText() == "Palabras")
        {
            ShellSort(*strDCList, strDCList->getSize());
            move();
        }
    }
    if(ui->cbxEstructura->currentText() == "Pila")
    {
        if(ui->cbxDato->currentText() == "Enteros")
        {
            ShellSort(*intStack, intStack->getSize());
            move();
        }
        if(ui->cbxDato->currentText() == "Letras")
        {
            ShellSort(*charStack, charStack->getSize());
            move();
        }
        if(ui->cbxDato->currentText() == "Palabras")
        {
            ShellSort(*strStack, strStack->getSize());
            move();
        }
    }
    if(ui->cbxEstructura->currentText() == "Cola")
    {
        if(ui->cbxDato->currentText() == "Enteros")
        {
            ShellSort(*intQueue, intQueue->getSize());
            move();
        }
        if(ui->cbxDato->currentText() == "Letras")
        {
            ShellSort(*charQueue, charQueue->getSize());
            move();
        }
        if(ui->cbxDato->currentText() == "Palabras")
        {
            ShellSort(*strQueue, strQueue->getSize());
            move();
        }
    }
}

void MainWindow::on_btnInsertion_clicked()//INSERTION SORT
{
    if(ui->cbxEstructura->currentText() == "Lista Simple")
    {
        if(ui->cbxDato->currentText() == "Enteros")
        {
            InsertionSort(*intSimpList);
            move();
        }
        if(ui->cbxDato->currentText() == "Letras")
        {
            InsertionSort(*charSimpList);
            move();
        }
        if(ui->cbxDato->currentText() == "Palabras")
        {
            InsertionSort(*strSimpList);
            move();
        }
    }
    if(ui->cbxEstructura->currentText() == "Lista Doble")
    {
        if(ui->cbxDato->currentText() == "Enteros")
        {
            InsertionSort(*intDobList);
            move();
        }
        if(ui->cbxDato->currentText() == "Letras")
        {
            InsertionSort(*charDobList);
            move();
        }
        if(ui->cbxDato->currentText() == "Palabras")
        {
            InsertionSort(*strDoblList);
            move();
        }
    }
    if(ui->cbxEstructura->currentText() == "Lista Doble Circular")
    {
        if(ui->cbxDato->currentText() == "Enteros")
        {
            InsertionSort(*intDClist);
            move();
        }
        if(ui->cbxDato->currentText() == "Letras")
        {
            InsertionSort(*charDCList);
            move();
        }
        if(ui->cbxDato->currentText() == "Palabras")
        {
            InsertionSort(*strDCList);
            move();
        }
    }
    if(ui->cbxEstructura->currentText() == "Pila")
    {
        if(ui->cbxDato->currentText() == "Enteros")
        {
            InsertionSort(*intStack);
            move();
        }
        if(ui->cbxDato->currentText() == "Letras")
        {
            InsertionSort(*charStack);
            move();
        }
        if(ui->cbxDato->currentText() == "Palabras")
        {
            InsertionSort(*strStack);
            move();
        }
    }
    if(ui->cbxEstructura->currentText() == "Cola")
    {
        if(ui->cbxDato->currentText() == "Enteros")
        {
            InsertionSort(*intQueue);
            move();
        }
        if(ui->cbxDato->currentText() == "Letras")
        {
            InsertionSort(*charQueue);
            move();
        }
        if(ui->cbxDato->currentText() == "Palabras")
        {
            InsertionSort(*strQueue);
            move();
        }
    }
}

void MainWindow::on_btnMerge_clicked()//MERGE SORT
{
    if(ui->cbxEstructura->currentText() == "Lista Simple")
    {
        if(ui->cbxDato->currentText() == "Enteros")
        {
            MergeSort(*intSimpList, 0,intSimpList->getSize()-1);
            move();
        }
        if(ui->cbxDato->currentText() == "Letras")
        {
           MergeSort(*charSimpList, 0, charSimpList->getSize()-1);
            move();
        }
        if(ui->cbxDato->currentText() == "Palabras")
        {
           MergeSort(*strSimpList, 0, strSimpList->getSize()-1);
            move();
        }
    }
    if(ui->cbxEstructura->currentText() == "Lista Doble")
    {
        if(ui->cbxDato->currentText() == "Enteros")
        {
            MergeSort(*intDobList, 0,intDobList->getSize()-1);
            move();
        }
        if(ui->cbxDato->currentText() == "Letras")
        {
            MergeSort(*charDobList, 0, charDobList->getSize()-1);
            move();
        }
        if(ui->cbxDato->currentText() == "Palabras")
        {
            MergeSort(*strDoblList, 0, strDoblList->getSize()-1);
            move();
        }
    }
    if(ui->cbxEstructura->currentText() == "Lista Doble Circular")
    {
        if(ui->cbxDato->currentText() == "Enteros")
        {
            MergeSort(*intDClist, 0,intDClist->getSize()-1);
            move();
        }
        if(ui->cbxDato->currentText() == "Letras")
        {
            MergeSort(*charDCList, 0, charDCList->getSize()-1);
            move();
        }
        if(ui->cbxDato->currentText() == "Palabras")
        {
            MergeSort(*strDCList, 0, strDCList->getSize()-1);
            move();
        }
    }
    if(ui->cbxEstructura->currentText() == "Pila")
    {
        if(ui->cbxDato->currentText() == "Enteros")
        {
            MergeSort(*intStack, 0,intStack->getSize()-1);
            move();
        }
        if(ui->cbxDato->currentText() == "Letras")
        {
            MergeSort(*charStack, 0, charStack->getSize()-1);
            move();
        }
        if(ui->cbxDato->currentText() == "Palabras")
        {
            MergeSort(*strStack, 0, strStack->getSize()-1);
            move();
        }
    }
    if(ui->cbxEstructura->currentText() == "Cola")
    {
        if(ui->cbxDato->currentText() == "Enteros")
        {
            MergeSort(*intQueue, 0,intQueue->getSize()-1);
            move();
        }
        if(ui->cbxDato->currentText() == "Letras")
        {
            MergeSort(*charQueue, 0, charQueue->getSize()-1);
            move();
        }
        if(ui->cbxDato->currentText() == "Palabras")
        {
            MergeSort(*strQueue, 0, strQueue->getSize()-1);
            move();
        }
    }
}

void MainWindow::on_btnSeletion_clicked()//SELECTION SORT
{
    if(ui->cbxEstructura->currentText() == "Lista Simple")
    {
        if(ui->cbxDato->currentText() == "Enteros")
        {
            SelectionSort(*intSimpList, intSimpList->getSize());
            move();
        }
        if(ui->cbxDato->currentText() == "Letras")
        {
            SelectionSort(*charSimpList, charSimpList->getSize());
            move();
        }
        if(ui->cbxDato->currentText() == "Palabras")
        {
            SelectionSort(*strSimpList, strSimpList->getSize());
            move();
        }
    }
    if(ui->cbxEstructura->currentText() == "Lista Doble")
    {
        if(ui->cbxDato->currentText() == "Enteros")
        {
            SelectionSort(*intDobList, intDobList->getSize());
            move();
        }
        if(ui->cbxDato->currentText() == "Letras")
        {
            SelectionSort(*charDobList, charDobList->getSize());
            move();
        }
        if(ui->cbxDato->currentText() == "Palabras")
        {
            SelectionSort(*strDoblList, strDoblList->getSize());
            move();
        }
    }
    if(ui->cbxEstructura->currentText() == "Lista Doble Circular")
    {
        if(ui->cbxDato->currentText() == "Enteros")
        {
            SelectionSort(*intDClist, intDClist->getSize());
            move();
        }
        if(ui->cbxDato->currentText() == "Letras")
        {
            SelectionSort(*charDCList, charDCList->getSize());
            move();
        }
        if(ui->cbxDato->currentText() == "Palabras")
        {
            SelectionSort(*strDCList, strDCList->getSize());
            move();
        }
    }
    if(ui->cbxEstructura->currentText() == "Pila")
    {
        if(ui->cbxDato->currentText() == "Enteros")
        {
            SelectionSort(*intStack, intStack->getSize());
            move();
        }
        if(ui->cbxDato->currentText() == "Letras")
        {
            SelectionSort(*charStack, charStack->getSize());
            move();
        }
        if(ui->cbxDato->currentText() == "Palabras")
        {
            SelectionSort(*strStack, strStack->getSize());
            move();
        }
    }
    if(ui->cbxEstructura->currentText() == "Cola")
    {
        if(ui->cbxDato->currentText() == "Enteros")
        {
            SelectionSort(*intQueue, intQueue->getSize());
            move();
        }
        if(ui->cbxDato->currentText() == "Letras")
        {
            SelectionSort(*charQueue, charQueue->getSize());
            move();
        }
        if(ui->cbxDato->currentText() == "Palabras")
        {
            SelectionSort(*strQueue, strQueue->getSize());
            move();
        }
    }
}

void MainWindow::on_btnDobleBubble_clicked()//BUBBLE BIDIRECCIONAL
{
    if(ui->cbxEstructura->currentText() == "Lista Simple")
    {
        if(ui->cbxDato->currentText() == "Enteros")
        {
            DobleBubble(*intSimpList, intSimpList->getSize());
            move();
        }
        if(ui->cbxDato->currentText() == "Letras")
        {
            DobleBubble(*charSimpList, charSimpList->getSize());
            move();
        }
        if(ui->cbxDato->currentText() == "Palabras")
        {
            DobleBubble(*strSimpList, strSimpList->getSize());
            move();
        }
    }
    if(ui->cbxEstructura->currentText() == "Lista Doble")
    {
        if(ui->cbxDato->currentText() == "Enteros")
        {
            DobleBubble(*intDobList, intDobList->getSize()-1);
            move();
        }
        if(ui->cbxDato->currentText() == "Letras")
        {
            DobleBubble(*charDobList, charDobList->getSize()-1);
            move();
        }
        if(ui->cbxDato->currentText() == "Palabras")
        {
            DobleBubble(*strDoblList, strDoblList->getSize()-1);
            move();
        }
    }
    if(ui->cbxEstructura->currentText() == "Lista Doble Circular")
    {
        if(ui->cbxDato->currentText() == "Enteros")
        {
            DobleBubble(*intDClist, intDClist->getSize()-1);
            move();
        }
        if(ui->cbxDato->currentText() == "Letras")
        {
            DobleBubble(*charDCList, charDCList->getSize()-1);
            move();
        }
        if(ui->cbxDato->currentText() == "Palabras")
        {
            DobleBubble(*strDCList, strDCList->getSize()-1);
            move();
        }
    }
    if(ui->cbxEstructura->currentText() == "Pila")
    {
        if(ui->cbxDato->currentText() == "Enteros")
        {
            DobleBubble(*intStack, intStack->getSize()-1);
            move();
        }
        if(ui->cbxDato->currentText() == "Letras")
        {
            DobleBubble(*charStack, charStack->getSize()-1);
            move();
        }
        if(ui->cbxDato->currentText() == "Palabras")
        {
            DobleBubble(*strStack, strStack->getSize()-1);
            move();
        }
    }
    if(ui->cbxEstructura->currentText() == "Cola")
    {
        if(ui->cbxDato->currentText() == "Enteros")
        {
            DobleBubble(*intQueue, intQueue->getSize()-1);
            move();
        }
        if(ui->cbxDato->currentText() == "Letras")
        {
            DobleBubble(*charQueue, charQueue->getSize()-1);
            move();
        }
        if(ui->cbxDato->currentText() == "Palabras")
        {
            DobleBubble(*strQueue, strQueue->getSize()-1);
            move();
        }
    }
}

void MainWindow::on_btnHeap_clicked()//HEAPSORT BUTTON
{
    if(ui->cbxEstructura->currentText() == "Lista Simple")
    {
        if(ui->cbxDato->currentText() == "Enteros")
        {
            HeapSort(*intSimpList);
            move();
        }
        if(ui->cbxDato->currentText() == "Letras")
        {
            HeapSort(*charSimpList);
            move();
        }
        if(ui->cbxDato->currentText() == "Palabras")
        {
            HeapSort(*strSimpList);
            move();
        }
    }
    if(ui->cbxEstructura->currentText() == "Lista Doble")
    {
        if(ui->cbxDato->currentText() == "Enteros")
        {
            HeapSort(*intDobList);
            move();
        }
        if(ui->cbxDato->currentText() == "Letras")
        {
            HeapSort(*charDobList);
            move();
        }
        if(ui->cbxDato->currentText() == "Palabras")
        {
            HeapSort(*strDoblList);
            move();
        }
    }
    if(ui->cbxEstructura->currentText() == "Lista Doble Circular")
    {
        if(ui->cbxDato->currentText() == "Enteros")
        {
            HeapSort(*intDClist);
            move();
        }
        if(ui->cbxDato->currentText() == "Letras")
        {
            HeapSort(*charDCList);
            move();
        }
        if(ui->cbxDato->currentText() == "Palabras")
        {
            HeapSort(*strDCList);
            move();
        }
    }
    if(ui->cbxEstructura->currentText() == "Pila")
    {
        if(ui->cbxDato->currentText() == "Enteros")
        {
            HeapSort(*intStack);
            move();
        }
        if(ui->cbxDato->currentText() == "Letras")
        {
            HeapSort(*charStack);
            move();
        }
        if(ui->cbxDato->currentText() == "Palabras")
        {
            HeapSort(*strStack);
            move();
        }
    }
    if(ui->cbxEstructura->currentText() == "Cola")
    {
        if(ui->cbxDato->currentText() == "Enteros")
        {
            HeapSort(*intQueue);
            move();
        }
        if(ui->cbxDato->currentText() == "Letras")
        {
            HeapSort(*charQueue);
            move();
        }
        if(ui->cbxDato->currentText() == "Palabras")
        {
            HeapSort(*strQueue);
            move();
        }
    }
}

void MainWindow::on_btnBubble_clicked()
{
    if(ui->cbxEstructura->currentText() == "Lista Simple")
    {
        if(ui->cbxDato->currentText() == "Enteros")
        {
            BubbleSort(*intSimpList);
            move();
        }
        if(ui->cbxDato->currentText() == "Letras")
        {
            BubbleSort(*charSimpList);
            move();
        }
        if(ui->cbxDato->currentText() == "Palabras")
        {
            BubbleSort(*strSimpList);
            move();
        }
    }
    if(ui->cbxEstructura->currentText() == "Lista Doble")
    {
        if(ui->cbxDato->currentText() == "Enteros")
        {
            BubbleSort(*intDobList);
            move();
        }
        if(ui->cbxDato->currentText() == "Letras")
        {
            BubbleSort(*charDobList);
            move();
        }
        if(ui->cbxDato->currentText() == "Palabras")
        {
            BubbleSort(*strDoblList);
            move();
        }
    }
    if(ui->cbxEstructura->currentText() == "Lista Doble Circular")
    {
        if(ui->cbxDato->currentText() == "Enteros")
        {
            BubbleSort(*intDClist);
            move();
        }
        if(ui->cbxDato->currentText() == "Letras")
        {
            BubbleSort(*charDCList);
            move();
        }
        if(ui->cbxDato->currentText() == "Palabras")
        {
            BubbleSort(*strDCList);
            move();
        }
    }
    if(ui->cbxEstructura->currentText() == "Pila")
    {
        if(ui->cbxDato->currentText() == "Enteros")
        {
            BubbleSort(*intStack);
            move();
        }
        if(ui->cbxDato->currentText() == "Letras")
        {
            BubbleSort(*charStack);
            move();
        }
        if(ui->cbxDato->currentText() == "Palabras")
        {
            BubbleSort(*strStack);
            move();
        }
    }
    if(ui->cbxEstructura->currentText() == "Cola")
    {
        if(ui->cbxDato->currentText() == "Enteros")
        {
            BubbleSort(*intQueue);
            move();
        }
        if(ui->cbxDato->currentText() == "Letras")
        {
            BubbleSort(*charQueue);
            move();
        }
        if(ui->cbxDato->currentText() == "Palabras")
        {
            BubbleSort(*strQueue);
            move();
        }
    }
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

void MainWindow::move()
{
    std::size_t i = 0;
    vector<movement>::iterator it = movements.begin();
    if(ui->rbtnAdelante->isChecked())
        {
            if(!movements.empty())
            {
                movement n = movements[i];
                movementsDone.push_back(n);
                movements.erase(it);
                Swap(n.getX(),n.getY());
                move();
            }
        }
        if(ui->rbtnAtras->isChecked())
        {
            if(!movementsDone.empty())
            {
                i = movementsDone.size()-1;
                movement n = movementsDone[i];
                movements.insert(it,n);
                movementsDone.pop_back();
                Swap(n.getX(),n.getY());
                move();
            }
        }
}


/* ALGORITMOS DE ORDENAMIENTO */


/* INSERTION SORT */
template <class T>
void MainWindow::InsertionSort(SimpleList<T> &arr) //sobrecarga para la lista doble
{
    int i, j;
    SimpleNode<T> actual =*arr.getPos(1);
    for (i = 1; i < arr.getSize(); i++)
    {
        SimpleNode<T> temp = *arr.getPos(1);
        actual = *arr.getPos(i);
        for (j = i; j > 0 && (temp = *arr.getPos(j-1)) > actual; j--)
        {
            SimpleNode<T> *actualNode = arr.getPos(j);
            SimpleNode<T> *prevNode = arr.getPos(j-1);
            actualNode->setDato(prevNode->getDato());
            movements.push_back(movement(j-1,j));
        }
        arr.getPos(j)->setDato(actual.dato);
        movements.push_back(movement(j,i));
    }
}

template <class T>
void MainWindow::InsertionSort(DobleList<T> &arr) //sobrecarga para la lista doble
{
    int i, j;
    DobleNode<T> actual =*arr.getPos(0);
    for (i = 1; i < arr.getSize(); i++)
    {
        DobleNode<T> temp = *arr.getPos(0);
        actual = *arr.getPos(i);
        for (j = i; j > 0 && (temp = *arr.getPos(j-1)) > actual; j--)
        {
            DobleNode<T> *actualNode = arr.getPos(j);
            DobleNode<T> *prevNode = arr.getPos(j-1);
            actualNode->setDato(prevNode->getDato());
            movements.push_back(movement(j-1,j));
        }
        arr.getPos(j)->setDato(actual.getDato());
        movements.push_back(movement(j,i));
    }
}

template <class T>
void MainWindow::InsertionSort(DCList<T> &arr) //sobrecarga para la lista doble
{
    int i, j;
    DobleNode<T> actual =*arr.getPos(0);
    for (i = 1; i < arr.getSize(); i++)
    {
        DobleNode<T> temp = *arr.getPos(0);
        actual = *arr.getPos(i);
        for (j = i; j > 0 && (temp = *arr.getPos(j-1)) > actual; j--)
        {
            DobleNode<T> *actualNode = arr.getPos(j);
            DobleNode<T> *prevNode = arr.getPos(j-1);
            actualNode->setDato(prevNode->getDato());
            movements.push_back(movement(j-1,j));
        }
        arr.getPos(j)->setDato(actual.getDato());
        movements.push_back(movement(j,i));
    }
}

template <class T>
void MainWindow::InsertionSort(Stack<T> &arr) //sobrecarga para la lista doble
{
    int i, j;
    SimpleNode<T> actual =*arr.getPos(0);
    for (i = 1; i < arr.getSize(); i++)
    {
        SimpleNode<T> temp = *arr.getPos(0);
        actual = *arr.getPos(i);
        for (j = i; j > 0 && (temp = *arr.getPos(j-1)) > actual; j--)
        {
            SimpleNode<T> *actualNode = arr.getPos(j);
            SimpleNode<T> *prevNode = arr.getPos(j-1);
            actualNode->setDato(prevNode->getDato());
            movements.push_back(movement(j-1,j));
        }
        arr.getPos(j)->setDato(actual.dato);
        movements.push_back(movement(j,i));
    }
}

template <class T>
void MainWindow::InsertionSort(Queue<T> &arr) //sobrecarga para la lista doble
{
    int i, j;
    SimpleNode<T> actual =*arr.getPos(0);
    for (i = 1; i < arr.getSize(); i++)
    {
        SimpleNode<T> temp = *arr.getPos(0);
        actual = *arr.getPos(i);
        for (j = i; j > 0 && (temp = *arr.getPos(j-1)) > actual; j--)
        {
            SimpleNode<T> *actualNode = arr.getPos(j);
            SimpleNode<T> *prevNode = arr.getPos(j-1);
            actualNode->setDato(prevNode->getDato());
            movements.push_back(movement(j-1,j));
        }
        arr.getPos(j)->setDato(actual.dato);
        movements.push_back(movement(j,i));
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
void MainWindow::MergeSort(SimpleList<T> &arr, int leftIndx, int rightIndx) /* INDICES IZQUIERDOS Y DERECHOS DE LA LISTA*/
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
void MainWindow::Merge(SimpleList<T> &arr, int leftIndx, int pivote, int rigthIndx)
{
    int i, j, k; //INDICES DE LOS CICLOS
    int nuevList1 = pivote - leftIndx + 1; //TAMANO DE LA PRIMERA LISTA NUEVA
    int nuevList2 =  rigthIndx - pivote; //TAMANO DE LA SEGUNDA LISTA NUEVA
    SimpleList<T> *menores = new SimpleList<T>();
    SimpleList<T> *mayores = new SimpleList<T>();

    for (i = 0; i < nuevList1; i++)
        menores->insertAtTail(arr.getPos(leftIndx + i)->getDato()); //crea la nueva lista con los menores
    for (j = 0; j < nuevList2; j++)
         mayores->insertAtTail(arr.getPos(pivote + 1 + j)->getDato()); //crea la nueva lista con los mayores
    i = 0;
    j = 0;
    k = leftIndx;
    SimpleNode<T> temp1 = *arr.getPos(0);
    SimpleNode<T> temp2 = *arr.getPos(0);
    while (i < nuevList1 && j < nuevList2)
    {
        if ((temp1 = *menores->getPos(i)) < (temp2 = *mayores->getPos(j)) || (temp1 = *menores->getPos(i)) == (temp2 = *mayores->getPos(j))) // si menores[i] <= mayores[j]
        {
            arr.getPos(k)->setDato(menores->getPos(i)->getDato());
            movements.push_back(movement(k,i));
            i++;
        }
        else
        {
            arr.getPos(k)->setDato(mayores->getPos(j)->getDato());
            movements.push_back(movement(k,j));
            j++;
        }
        k++;
    }
    while (i < nuevList1)
    {
        arr.getPos(k)->setDato(menores->getPos(i)->getDato());
        movements.push_back(movement(k,i));
        i++;
        k++;
    }
    while (j < nuevList2)
    {
        arr.getPos(k)->setDato(mayores->getPos(j)->getDato());
        movements.push_back(movement(k,j));
        j++;
        k++;
    }
}

template <class T>
void MainWindow::MergeSort(DobleList<T> &arr, int leftIndx, int rightIndx) /* INDICES IZQUIERDOS Y DERECHOS DE LA LISTA*/
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
void MainWindow::Merge(DobleList<T> &arr, int leftIndx, int pivote, int rigthIndx)
{
    int i, j, k; //INDICES DE LOS CICLOS
    int nuevList1 = pivote - leftIndx + 1; //TAMANO DE LA PRIMERA LISTA NUEVA
    int nuevList2 =  rigthIndx - pivote; //TAMANO DE LA SEGUNDA LISTA NUEVA
    DobleList<T> *menores = new DobleList<T>();
    DobleList<T> *mayores = new DobleList<T>();

    for (i = 0; i < nuevList1; i++)
        menores->insertAtTail(arr.getPos(leftIndx + i)->getDato()); //crea la nueva lista con los menores
    for (j = 0; j < nuevList2; j++)
         mayores->insertAtTail(arr.getPos(pivote + 1 + j)->getDato()); //crea la nueva lista con los mayores
    i = 0;
    j = 0;
    k = leftIndx;
    DobleNode<T> temp1 = *arr.getPos(0);
    DobleNode<T> temp2 = *arr.getPos(0);
    while (i < nuevList1 && j < nuevList2)
    {
        if ((temp1 = *menores->getPos(i)) < (temp2 = *mayores->getPos(j)) || (temp1 = *menores->getPos(i)) == (temp2 = *mayores->getPos(j))) // si menores[i] <= mayores[j]
        {
            arr.getPos(k)->setDato(menores->getPos(i)->getDato());
            movements.push_back(movement(k,i));
            i++;
        }
        else
        {
            arr.getPos(k)->setDato(mayores->getPos(j)->getDato());
            movements.push_back(movement(k,j));
            j++;
        }
        k++;
    }
    while (i < nuevList1)
    {
        arr.getPos(k)->setDato(menores->getPos(i)->getDato());
        movements.push_back(movement(k,i));
        i++;
        k++;
    }
    while (j < nuevList2)
    {
        arr.getPos(k)->setDato(mayores->getPos(j)->getDato());
        movements.push_back(movement(k,j));
        j++;
        k++;
    }
}

template <class T>
void MainWindow::MergeSort(DCList<T> &arr, int leftIndx, int rightIndx) /* INDICES IZQUIERDOS Y DERECHOS DE LA LISTA*/
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
void MainWindow::Merge(DCList<T> &arr, int leftIndx, int pivote, int rigthIndx)
{
    int i, j, k; //INDICES DE LOS CICLOS
    int nuevList1 = pivote - leftIndx + 1; //TAMANO DE LA PRIMERA LISTA NUEVA
    int nuevList2 =  rigthIndx - pivote; //TAMANO DE LA SEGUNDA LISTA NUEVA
    DCList<T> *menores = new DCList<T>();
    DCList<T> *mayores = new DCList<T>();

    for (i = 0; i < nuevList1; i++)
        menores->insertAtTail(arr.getPos(leftIndx + i)->getDato()); //crea la nueva lista con los menores
    for (j = 0; j < nuevList2; j++)
         mayores->insertAtTail(arr.getPos(pivote + 1 + j)->getDato()); //crea la nueva lista con los mayores
    i = 0;
    j = 0;
    k = leftIndx;
    DobleNode<T> temp1 = *arr.getPos(0);
    DobleNode<T> temp2 = *arr.getPos(0);
    while (i < nuevList1 && j < nuevList2)
    {
        if ((temp1 = *menores->getPos(i)) < (temp2 = *mayores->getPos(j)) || (temp1 = *menores->getPos(i)) == (temp2 = *mayores->getPos(j))) // si menores[i] <= mayores[j]
        {
            arr.getPos(k)->setDato(menores->getPos(i)->getDato());
            movements.push_back(movement(k,i));
            i++;
        }
        else
        {
            arr.getPos(k)->setDato(mayores->getPos(j)->getDato());
            movements.push_back(movement(k,j));
            j++;
        }
        k++;
    }
    while (i < nuevList1)
    {
        arr.getPos(k)->setDato(menores->getPos(i)->getDato());
        movements.push_back(movement(k,i));
        i++;
        k++;
    }
    while (j < nuevList2)
    {
        arr.getPos(k)->setDato(mayores->getPos(j)->getDato());
        movements.push_back(movement(k,j));
        j++;
        k++;
    }
}

template <class T>
void MainWindow::MergeSort(Stack<T> &arr, int leftIndx, int rightIndx) /* INDICES IZQUIERDOS Y DERECHOS DE LA LISTA*/
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
void MainWindow::Merge(Stack<T> &arr, int leftIndx, int pivote, int rigthIndx)
{
    int i, j, k; //INDICES DE LOS CICLOS
    int nuevList1 = pivote - leftIndx + 1; //TAMANO DE LA PRIMERA LISTA NUEVA
    int nuevList2 =  rigthIndx - pivote; //TAMANO DE LA SEGUNDA LISTA NUEVA
    Stack<T> *menores = new Stack<T>();
    Stack<T> *mayores = new Stack<T>();

    for (i = 0; i < nuevList1; i++)
        menores->push(arr.getPos(leftIndx + i)->getDato()); //crea la nueva lista con los menores
    for (j = 0; j < nuevList2; j++)
         mayores->push(arr.getPos(pivote + 1 + j)->getDato()); //crea la nueva lista con los mayores
    mayores = invertirPila(mayores);
    menores = invertirPila(menores);
    i = 0;
    j = 0;
    k = leftIndx;
    SimpleNode<T> temp1 = *arr.getPos(0);
    SimpleNode<T> temp2 = *arr.getPos(0);
    while (i < nuevList1 && j < nuevList2)
    {
        if ((temp1 = *menores->getPos(i)) < (temp2 = *mayores->getPos(j)) || (temp1 = *menores->getPos(i)) == (temp2 = *mayores->getPos(j))) // si menores[i] <= mayores[j]
        {
            arr.getPos(k)->setDato(menores->getPos(i)->getDato());
            movements.push_back(movement(k,i));
            i++;
        }
        else
        {
            arr.getPos(k)->setDato(mayores->getPos(j)->getDato());
            movements.push_back(movement(k,j));
            j++;
        }
        k++;
    }
    while (i < nuevList1)
    {
        arr.getPos(k)->setDato(menores->getPos(i)->getDato());
        movements.push_back(movement(k,i));
        i++;
        k++;
    }
    while (j < nuevList2)
    {
        arr.getPos(k)->setDato(mayores->getPos(j)->getDato());
        movements.push_back(movement(k,j));
        j++;
        k++;
    }
}

template <class T>
void MainWindow::MergeSort(Queue<T> &arr, int leftIndx, int rightIndx) /* INDICES IZQUIERDOS Y DERECHOS DE LA LISTA*/
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
void MainWindow::Merge(Queue<T> &arr, int leftIndx, int pivote, int rigthIndx)
{
    int i, j, k; //INDICES DE LOS CICLOS
    int nuevList1 = pivote - leftIndx + 1; //TAMANO DE LA PRIMERA LISTA NUEVA
    int nuevList2 =  rigthIndx - pivote; //TAMANO DE LA SEGUNDA LISTA NUEVA
    Queue<T> *menores = new Queue<T>();
    Queue<T> *mayores = new Queue<T>();

    for (i = 0; i < nuevList1; i++)
        menores->enqueue(arr.getPos(leftIndx + i)->getDato()); //crea la nueva lista con los menores
    for (j = 0; j < nuevList2; j++)
         mayores->enqueue(arr.getPos(pivote + 1 + j)->getDato()); //crea la nueva lista con los mayores
    i = 0;
    j = 0;
    k = leftIndx;
    SimpleNode<T> temp1 = *arr.getPos(0);
    SimpleNode<T> temp2 = *arr.getPos(0);
    while (i < nuevList1 && j < nuevList2)
    {
        if ((temp1 = *menores->getPos(i)) < (temp2 = *mayores->getPos(j)) || (temp1 = *menores->getPos(i)) == (temp2 = *mayores->getPos(j))) // si menores[i] <= mayores[j]
        {
            arr.getPos(k)->setDato(menores->getPos(i)->getDato());
            movements.push_back(movement(k,i));
            i++;
        }
        else
        {
            arr.getPos(k)->setDato(mayores->getPos(j)->getDato());
            movements.push_back(movement(k,j));
            j++;
        }
        k++;
    }
    while (i < nuevList1)
    {
        arr.getPos(k)->setDato(menores->getPos(i)->getDato());
        movements.push_back(movement(k,i));
        i++;
        k++;
    }
    while (j < nuevList2)
    {
        arr.getPos(k)->setDato(mayores->getPos(j)->getDato());
        movements.push_back(movement(k,j));
        j++;
        k++;
    }
}

/* QUICK SORT */
template<class T>
void MainWindow::QuickSort(SimpleList<T> &arr, int low, int high) //Metodo para la lista simple
{
    if (low < high){
        int pi = partition(arr, low, high);
        QuickSort(arr, low, pi - 1);//Makes a new group with the highers
        QuickSort(arr, pi + 1, high);//Makes a new group with the lowers
      }
}

/*METODO AUXILIAR QUE HACE LA PARTICION EN EL QUICK SORT*/
template<class T>
int MainWindow::partition(SimpleList<T> &arr, int low, int high)
{
    SimpleNode<T> pivot = *arr.getPos(high);
    SimpleNode<T> temp = *arr.getPos(0);
    int i = (low - 1);
    for (int j = low; j <= (high - 1); j++)
    {
        if ((temp = *arr.getPos(j)) < pivot || (temp = *arr.getPos(j)) == pivot )//changes acording to which one is higher
        {
          i++;
          arr.swap(i,j);
          movements.push_back(movement(i,j));
        }
    }
    arr.swap((i+ 1),high);
    movements.push_back(movement(i+1,high));
    return( i + 1 );
}

template<class T>
void MainWindow::QuickSort(DobleList<T> &arr, int low, int high) //Metodo para la lista simple
{
    if (low < high){
        int pi = partition(arr, low, high);
        QuickSort(arr, low, pi - 1);//Makes a new group with the highers
        QuickSort(arr, pi + 1, high);//Makes a new group with the lowers
      }
}

/*METODO AUXILIAR QUE HACE LA PARTICION EN EL QUICK SORT*/
template<class T>
int MainWindow::partition(DobleList<T> &arr, int low, int high)
{
    DobleNode<T> pivot = *arr.getPos(high);
    DobleNode<T> temp = *arr.getPos(0);
    int i = (low - 1);
    for (int j = low; j <= (high - 1); j++)
    {
        if ((temp = *arr.getPos(j)) < pivot || (temp = *arr.getPos(j)) == pivot )//changes acording to which one is higher
        {
          i++;
          arr.swap(i,j);
          movements.push_back(movement(i,j));
        }
    }
    arr.swap((i+ 1),high);
    movements.push_back(movement(i+1,high));
    return( i + 1 );
}

template<class T>
void MainWindow::QuickSort(DCList<T> &arr, int low, int high) //Metodo para la lista simple
{
    if (low < high){
        int pi = partition(arr, low, high);
        QuickSort(arr, low, pi - 1);//Makes a new group with the highers
        QuickSort(arr, pi + 1, high);//Makes a new group with the lowers
      }
}

/*METODO AUXILIAR QUE HACE LA PARTICION EN EL QUICK SORT*/
template<class T>
int MainWindow::partition(DCList<T> &arr, int low, int high)
{
    DobleNode<T> pivot = *arr.getPos(high);
    DobleNode<T> temp = *arr.getPos(0);
    int i = (low - 1);
    for (int j = low; j <= (high - 1); j++)
    {
        if ((temp = *arr.getPos(j)) < pivot || (temp = *arr.getPos(j)) == pivot )//changes acording to which one is higher
        {
          i++;
          arr.swap(i,j);
          movements.push_back(movement(i,j));
        }
    }
    arr.swap((i+ 1),high);
    movements.push_back(movement(i+1,high));
    return( i + 1 );
}

template<class T>
void MainWindow::QuickSort(Stack<T> &arr, int low, int high) //Metodo para la lista simple
{
    if (low < high){
        int pi = partition(arr, low, high);
        QuickSort(arr, low, pi - 1);//Makes a new group with the highers
        QuickSort(arr, pi + 1, high);//Makes a new group with the lowers
      }
}

/*METODO AUXILIAR QUE HACE LA PARTICION EN EL QUICK SORT*/
template<class T>
int MainWindow::partition(Stack<T> &arr, int low, int high)
{
    SimpleNode<T> pivot = *arr.getPos(high);
    SimpleNode<T> temp = *arr.getPos(0);
    int i = (low - 1);
    for (int j = low; j <= (high - 1); j++)
    {
        if ((temp = *arr.getPos(j)) < pivot || (temp = *arr.getPos(j)) == pivot )//changes acording to which one is higher
        {
          i++;
          arr.swap(i,j);
          movements.push_back(movement(i,j));
        }
    }
    arr.swap((i+ 1),high);
    movements.push_back(movement(i+1,high));
    return( i + 1 );
}

template<class T>
void MainWindow::QuickSort(Queue<T> &arr, int low, int high) //Metodo para la lista simple
{
    if (low < high){
        int pi = partition(arr, low, high);
        QuickSort(arr, low, pi - 1);//Makes a new group with the highers
        QuickSort(arr, pi + 1, high);//Makes a new group with the lowers
      }
}

/*METODO AUXILIAR QUE HACE LA PARTICION EN EL QUICK SORT*/
template<class T>
int MainWindow::partition(Queue<T> &arr, int low, int high)
{
    SimpleNode<T> pivot = *arr.getPos(high);
    SimpleNode<T> temp = *arr.getPos(0);
    int i = (low - 1);
    for (int j = low; j <= (high - 1); j++)
    {
        if ((temp = *arr.getPos(j)) < pivot || (temp = *arr.getPos(j)) == pivot )//changes acording to which one is higher
        {
          i++;
          arr.swap(i,j);
          movements.push_back(movement(i,j));
        }
    }
    arr.swap((i+ 1),high);
    movements.push_back(movement(i+1,high));
    return( i + 1 );
}

/* SELECTION SORT */
template <class T>
void MainWindow::SelectionSort(SimpleList<T> &arr, int tamanio) //lista simple
{
    T atemp;
    int i, j, min_idx;  //indices de ciclos
    for(i = 0; i < tamanio-1; i++)
    {
        min_idx = i;
        SimpleNode<T> temp1 = *arr.getPos(0);
        SimpleNode<T> temp2 = *arr.getPos(0);
        for(j = i+1; j < tamanio; j++)
            if((temp1 = *arr.getPos(j)) < (temp2 = *arr.getPos(min_idx)))
                min_idx = j;
        atemp = arr.getPos(i)->getDato();
        arr.getPos(i)->setDato(arr.getPos(min_idx)->getDato());
        arr.getPos(min_idx)->setDato(atemp);
        movements.push_back(movement(min_idx,i));
    }
}

template <class T>
void MainWindow::SelectionSort(DobleList<T> &arr, int tamanio) //lista simple
{
    T atemp;
    int i, j, min_idx;  //indices de ciclos
    for(i = 0; i < tamanio-1; i++)
    {
        min_idx = i;
        DobleNode<T> temp1 = *arr.getPos(0);
        DobleNode<T> temp2 = *arr.getPos(0);
        for(j = i+1; j < tamanio; j++)
            if((temp1 = *arr.getPos(j)) < (temp2 = *arr.getPos(min_idx)))
                min_idx = j;
        atemp = arr.getPos(i)->getDato();
        arr.getPos(i)->setDato(arr.getPos(min_idx)->getDato());
        arr.getPos(min_idx)->setDato(atemp);
        movements.push_back(movement(min_idx,i));
    }
}

template <class T>
void MainWindow::SelectionSort(DCList<T> &arr, int tamanio) //lista simple
{
    T atemp;
    int i, j, min_idx;  //indices de ciclos
    for(i = 0; i < tamanio-1; i++)
    {
        min_idx = i;
        DobleNode<T> temp1 = *arr.getPos(0);
        DobleNode<T> temp2 = *arr.getPos(0);
        for(j = i+1; j < tamanio; j++)
            if((temp1 = *arr.getPos(j)) < (temp2 = *arr.getPos(min_idx)))
                min_idx = j;
        atemp = arr.getPos(i)->getDato();
        arr.getPos(i)->setDato(arr.getPos(min_idx)->getDato());
        arr.getPos(min_idx)->setDato(atemp);
        movements.push_back(movement(min_idx,i));
    }
}

template <class T>
void MainWindow::SelectionSort(Stack<T> &arr, int tamanio) //lista simple
{
    T atemp;
    int i, j, min_idx;  //indices de ciclos
    for(i = 0; i < tamanio-1; i++)
    {
        min_idx = i;
        SimpleNode<T> temp1 = *arr.getPos(0);
        SimpleNode<T> temp2 = *arr.getPos(0);
        for(j = i+1; j < tamanio; j++)
            if((temp1 = *arr.getPos(j)) < (temp2 = *arr.getPos(min_idx)))
                min_idx = j;
        atemp = arr.getPos(i)->getDato();
        arr.getPos(i)->setDato(arr.getPos(min_idx)->getDato());
        arr.getPos(min_idx)->setDato(atemp);
        movements.push_back(movement(min_idx,i));
    }
}

template <class T>
void MainWindow::SelectionSort(Queue<T> &arr, int tamanio) //lista simple
{
    T atemp;
    int i, j, min_idx;  //indices de ciclos
    for(i = 0; i < tamanio-1; i++)
    {
        min_idx = i;
        SimpleNode<T> temp1 = *arr.getPos(0);
        SimpleNode<T> temp2 = *arr.getPos(0);
        for(j = i+1; j < tamanio; j++)
            if((temp1 = *arr.getPos(j)) < (temp2 = *arr.getPos(min_idx)))
                min_idx = j;
        atemp = arr.getPos(i)->getDato();
        arr.getPos(i)->setDato(arr.getPos(min_idx)->getDato());
        arr.getPos(min_idx)->setDato(atemp);
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
void MainWindow::HeapSort(SimpleList<T> &arr) //lista simple
{
    int tamano = arr.getSize();

    for(int i = tamano / 2 - 1; i >= 0; i--)
        HeapSortAux(arr, tamano, i);

    for(int i = tamano - 1; i >= 0; i--)
    {
        //cambio de los valores
        T temp = arr.getPos(i)->getDato();
        arr.getPos(i)->setDato(arr.getPos(0)->getDato());
        arr.getPos(0)->setDato(temp);
        movements.push_back(movement(i,0));

        HeapSortAux(arr, i, 0);
    }

}

/*METODO AUXILIAR*/
template <class T>
void MainWindow::HeapSortAux(SimpleList<T> &arr, int largo, int aTratar)
{
    int mayor = aTratar;
    int izq = 2*aTratar + 1; //hijo izquierdo en la lista
    int der = 2*aTratar + 2; //hijo derecho en la lista
    SimpleNode<T> temp1 = *arr.getPos(0);
    SimpleNode<T> temp2 = *arr.getPos(0);
    //si el hijo izquierdo es mayor que el padre
    if(izq < largo && ((temp1 = *arr.getPos(izq)) > (temp2 = *arr.getPos(mayor))))
        mayor = izq;

    //si el hijo derecho es mayor que el padre
    if(der < largo && ((temp1 = *arr.getPos(der)) > (temp2 = *arr.getPos(mayor))))
        mayor = der;

    if(mayor != aTratar)
    {
        //Cambio del largo y el aTratar
        T temp = arr.getPos(mayor)->getDato();
        arr.getPos(mayor)->setDato(arr.getPos(aTratar)->getDato());
        arr.getPos(aTratar)->setDato(temp);
        movements.push_back(movement(mayor,aTratar));
        HeapSortAux(arr, largo, mayor);
    }
}

template <class T>
void MainWindow::HeapSort(DobleList<T> &arr) //lista simple
{
    int tamano = arr.getSize();

    for(int i = tamano / 2 - 1; i >= 0; i--)
        HeapSortAux(arr, tamano, i);

    for(int i = tamano - 1; i >= 0; i--)
    {
        //cambio de los valores
        T temp = arr.getPos(i)->getDato();
        arr.getPos(i)->setDato(arr.getPos(0)->getDato());
        arr.getPos(0)->setDato(temp);
        movements.push_back(movement(i,0));

        HeapSortAux(arr, i, 0);
    }

}

/*METODO AUXILIAR*/
template <class T>
void MainWindow::HeapSortAux(DobleList<T> &arr, int largo, int aTratar)
{
    int mayor = aTratar;
    int izq = 2*aTratar + 1; //hijo izquierdo en la lista
    int der = 2*aTratar + 2; //hijo derecho en la lista
    DobleNode<T> temp1 = *arr.getPos(0);
    DobleNode<T> temp2 = *arr.getPos(0);
    //si el hijo izquierdo es mayor que el padre
    if(izq < largo && ((temp1 = *arr.getPos(izq)) > (temp2 = *arr.getPos(mayor))))
        mayor = izq;

    //si el hijo derecho es mayor que el padre
    if(der < largo && ((temp1 = *arr.getPos(der)) > (temp2 = *arr.getPos(mayor))))
        mayor = der;

    if(mayor != aTratar)
    {
        //Cambio del largo y el aTratar
        T temp = arr.getPos(mayor)->getDato();
        arr.getPos(mayor)->setDato(arr.getPos(aTratar)->getDato());
        arr.getPos(aTratar)->setDato(temp);
        movements.push_back(movement(mayor,aTratar));
        HeapSortAux(arr, largo, mayor);
    }
}

template <class T>
void MainWindow::HeapSort(DCList<T> &arr) //lista simple
{
    int tamano = arr.getSize();

    for(int i = tamano / 2 - 1; i >= 0; i--)
        HeapSortAux(arr, tamano, i);

    for(int i = tamano - 1; i >= 0; i--)
    {
        //cambio de los valores
        T temp = arr.getPos(i)->getDato();
        arr.getPos(i)->setDato(arr.getPos(0)->getDato());
        arr.getPos(0)->setDato(temp);
        movements.push_back(movement(i,0));

        HeapSortAux(arr, i, 0);
    }

}

/*METODO AUXILIAR*/
template <class T>
void MainWindow::HeapSortAux(DCList<T> &arr, int largo, int aTratar)
{
    int mayor = aTratar;
    int izq = 2*aTratar + 1; //hijo izquierdo en la lista
    int der = 2*aTratar + 2; //hijo derecho en la lista
    DobleNode<T> temp1 = *arr.getPos(0);
    DobleNode<T> temp2 = *arr.getPos(0);
    //si el hijo izquierdo es mayor que el padre
    if(izq < largo && ((temp1 = *arr.getPos(izq)) > (temp2 = *arr.getPos(mayor))))
        mayor = izq;

    //si el hijo derecho es mayor que el padre
    if(der < largo && ((temp1 = *arr.getPos(der)) > (temp2 = *arr.getPos(mayor))))
        mayor = der;

    if(mayor != aTratar)
    {
        //Cambio del largo y el aTratar
        T temp = arr.getPos(mayor)->getDato();
        arr.getPos(mayor)->setDato(arr.getPos(aTratar)->getDato());
        arr.getPos(aTratar)->setDato(temp);
        movements.push_back(movement(mayor,aTratar));
        HeapSortAux(arr, largo, mayor);
    }
}

template <class T>
void MainWindow::HeapSort(Stack<T> &arr) //lista simple
{
    int tamano = arr.getSize();

    for(int i = tamano / 2 - 1; i >= 0; i--)
        HeapSortAux(arr, tamano, i);

    for(int i = tamano - 1; i >= 0; i--)
    {
        //cambio de los valores
        T temp = arr.getPos(i)->getDato();
        arr.getPos(i)->setDato(arr.getPos(0)->getDato());
        arr.getPos(0)->setDato(temp);
        movements.push_back(movement(i,0));

        HeapSortAux(arr, i, 0);
    }

}

/*METODO AUXILIAR*/
template <class T>
void MainWindow::HeapSortAux(Stack<T> &arr, int largo, int aTratar)
{
    int mayor = aTratar;
    int izq = 2*aTratar + 1; //hijo izquierdo en la lista
    int der = 2*aTratar + 2; //hijo derecho en la lista
    SimpleNode<T> temp1 = *arr.getPos(0);
    SimpleNode<T> temp2 = *arr.getPos(0);
    //si el hijo izquierdo es mayor que el padre
    if(izq < largo && ((temp1 = *arr.getPos(izq)) > (temp2 = *arr.getPos(mayor))))
        mayor = izq;

    //si el hijo derecho es mayor que el padre
    if(der < largo && ((temp1 = *arr.getPos(der)) > (temp2 = *arr.getPos(mayor))))
        mayor = der;

    if(mayor != aTratar)
    {
        //Cambio del largo y el aTratar
        T temp = arr.getPos(mayor)->getDato();
        arr.getPos(mayor)->setDato(arr.getPos(aTratar)->getDato());
        arr.getPos(aTratar)->setDato(temp);
        movements.push_back(movement(mayor,aTratar));
        HeapSortAux(arr, largo, mayor);
    }
}

template <class T>
void MainWindow::HeapSort(Queue<T> &arr) //lista simple
{
    int tamano = arr.getSize();

    for(int i = tamano / 2 - 1; i >= 0; i--)
        HeapSortAux(arr, tamano, i);

    for(int i = tamano - 1; i >= 0; i--)
    {
        //cambio de los valores
        T temp = arr.getPos(i)->getDato();
        arr.getPos(i)->setDato(arr.getPos(0)->getDato());
        arr.getPos(0)->setDato(temp);
        movements.push_back(movement(i,0));

        HeapSortAux(arr, i, 0);
    }

}

/*METODO AUXILIAR*/
template <class T>
void MainWindow::HeapSortAux(Queue<T> &arr, int largo, int aTratar)
{
    int mayor = aTratar;
    int izq = 2*aTratar + 1; //hijo izquierdo en la lista
    int der = 2*aTratar + 2; //hijo derecho en la lista
    SimpleNode<T> temp1 = *arr.getPos(0);
    SimpleNode<T> temp2 = *arr.getPos(0);
    //si el hijo izquierdo es mayor que el padre
    if(izq < largo && ((temp1 = *arr.getPos(izq)) > (temp2 = *arr.getPos(mayor))))
        mayor = izq;

    //si el hijo derecho es mayor que el padre
    if(der < largo && ((temp1 = *arr.getPos(der)) > (temp2 = *arr.getPos(mayor))))
        mayor = der;

    if(mayor != aTratar)
    {
        //Cambio del largo y el aTratar
        T temp = arr.getPos(mayor)->getDato();
        arr.getPos(mayor)->setDato(arr.getPos(aTratar)->getDato());
        arr.getPos(aTratar)->setDato(temp);
        movements.push_back(movement(mayor,aTratar));
        HeapSortAux(arr, largo, mayor);
    }
}
/* SHELL SORT */
template <class T>
void MainWindow::ShellSort(SimpleList<T>& arr, int tamano) //lista simple
{
    for (int gap = tamano/2; gap > 0; gap = gap/2)
        for(int i = gap; i < tamano; i += 1)
        {
            SimpleNode<T> temp =  *arr.getPos(i);
            SimpleNode<T> temp2 = *arr.getPos(0);
            int j;
            for(j = i; j >= gap && (temp2 = *arr.getPos(j-gap)) > temp; j -= gap)
            {
                arr.getPos(j)->setDato(arr.getPos(j-gap)->getDato());
                movements.push_back(movement(j,j - gap));
            }
             arr.getPos(j)->setDato(temp.dato);
        }
}
template <class T>
void MainWindow::ShellSort(DobleList<T>& arr, int tamano) //lista simple
{
    for (int gap = tamano/2; gap > 0; gap = gap/2)
        for(int i = gap; i < tamano; i += 1)
        {
            DobleNode<T> temp =  *arr.getPos(i);
            DobleNode<T> temp2 = *arr.getPos(0);
            int j;
            for(j = i; j >= gap && (temp2 = *arr.getPos(j-gap)) > temp; j -= gap)
            {
                arr.getPos(j)->setDato(arr.getPos(j-gap)->getDato());
                movements.push_back(movement(j,j - gap));
            }
             arr.getPos(j)->setDato(temp.getDato());
        }
}
template <class T>
void MainWindow::ShellSort(DCList<T>& arr, int tamano) //lista simple
{
    for (int gap = tamano/2; gap > 0; gap = gap/2)
        for(int i = gap; i < tamano; i += 1)
        {
            DobleNode<T> temp =  *arr.getPos(i);
            DobleNode<T> temp2 = *arr.getPos(0);
            int j;
            for(j = i; j >= gap && (temp2 = *arr.getPos(j-gap)) > temp; j -= gap)
            {
                arr.getPos(j)->setDato(arr.getPos(j-gap)->getDato());
                movements.push_back(movement(j,j - gap));
            }
             arr.getPos(j)->setDato(temp.getDato());
        }
}
template <class T>
void MainWindow::ShellSort(Stack<T>& arr, int tamano) //lista simple
{
    for (int gap = tamano/2; gap > 0; gap = gap/2)
        for(int i = gap; i < tamano; i += 1)
        {
            SimpleNode<T> temp =  *arr.getPos(i);
            SimpleNode<T> temp2 = *arr.getPos(0);
            int j;
            for(j = i; j >= gap && (temp2 = *arr.getPos(j-gap)) > temp; j -= gap)
            {
                arr.getPos(j)->setDato(arr.getPos(j-gap)->getDato());
                movements.push_back(movement(j,j - gap));
            }
             arr.getPos(j)->setDato(temp.dato);
        }
}
template <class T>
void MainWindow::ShellSort(Queue<T>& arr, int tamano) //lista simple
{
    for (int gap = tamano/2; gap > 0; gap = gap/2)
        for(int i = gap; i < tamano; i += 1)
        {
            SimpleNode<T> temp =  *arr.getPos(i);
            SimpleNode<T> temp2 = *arr.getPos(0);
            int j;
            for(j = i; j >= gap && (temp2 = *arr.getPos(j-gap)) > temp; j -= gap)
            {
                arr.getPos(j)->setDato(arr.getPos(j-gap)->getDato());
                movements.push_back(movement(j,j - gap));
            }
             arr.getPos(j)->setDato(temp.dato);
        }
}


/* BUBBLE SORT */
template<class T>
void MainWindow::BubbleSort(SimpleList<T> &arr)
{
    int i,j,n;
    n = arr.getSize();\
    SimpleNode<T> temp1 = *arr.getPos(0);
    SimpleNode<T> temp2 = *arr.getPos(0);
    for (i = 0; i< n-1; i++)
    {
        for(j = 0; j<n-i-1; j++)
        {
            if((temp1 = *arr.getPos(j)) > (temp2 = *arr.getPos(j+1)))
            {
                arr.swap(j,j+1);
                movements.push_back(movement(j,j+1));
            }
        }
    }
}

template<class T>
void MainWindow::BubbleSort(DobleList<T> &arr)
{
    int i,j,n;
    n = arr.getSize();\
    DobleNode<T> temp1 = *arr.getPos(0);
    DobleNode<T> temp2 = *arr.getPos(0);
    for (i = 0; i< n-1; i++)
    {
        for(j = 0; j<n-i-1; j++)
        {
            if((temp1 = *arr.getPos(j)) > (temp2 = *arr.getPos(j+1)))
            {
                arr.swap(j,j+1);
                movements.push_back(movement(j,j+1));
            }
        }
    }
}
template<class T>
void MainWindow::BubbleSort(DCList<T> &arr)
{
    int i,j,n;
    n = arr.getSize();\
    DobleNode<T> temp1 = *arr.getPos(0);
    DobleNode<T> temp2 = *arr.getPos(0);
    for (i = 0; i< n-1; i++)
    {
        for(j = 0; j<n-i-1; j++)
        {
            if((temp1 = *arr.getPos(j)) > (temp2 = *arr.getPos(j+1)))
            {
                arr.swap(j,j+1);
                movements.push_back(movement(j,j+1));
            }
        }
    }
}
template<class T>
void MainWindow::BubbleSort(Stack<T> &arr)
{
    int i,j,n;
    n = arr.getSize();\
    SimpleNode<T> temp1 = *arr.getPos(0);
    SimpleNode<T> temp2 = *arr.getPos(0);
    for (i = 0; i< n-1; i++)
    {
        for(j = 0; j<n-i-1; j++)
        {
            if((temp1 = *arr.getPos(j)) > (temp2 = *arr.getPos(j+1)))
            {
                arr.swap(j,j+1);
                movements.push_back(movement(j,j+1));
            }
        }
    }
}
template<class T>
void MainWindow::BubbleSort(Queue<T> &arr)
{
    int i,j,n;
    n = arr.getSize();\
    SimpleNode<T> temp1 = *arr.getPos(0);
    SimpleNode<T> temp2 = *arr.getPos(0);
    for (i = 0; i< n-1; i++)
    {
        for(j = 0; j<n-i-1; j++)
        {
            if((temp1 = *arr.getPos(j)) > (temp2 = *arr.getPos(j+1)))
            {
                arr.swap(j,j+1);
                movements.push_back(movement(j,j+1));
            }
        }
    }
}

/* BUBBLEDOBLE */
template <class T>
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
            if (arr[en_cours] < arr[en_cours-1])
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
void MainWindow::DobleBubble(DobleList<T> &arr, int end)
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
            if (arr.getPos(en_cours) < arr.getPos(en_cours-1))
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
void MainWindow::DobleBubble(DCList<T> &arr, int end)
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
            if (arr.getPos(en_cours) < arr.getPos(en_cours-1))
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
void MainWindow::DobleBubble(Stack<T> &arr, int end)
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
            if (arr.getPos(en_cours) < arr.getPos(en_cours-1))
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
void MainWindow::DobleBubble(Queue<T> &arr, int end)
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
            if (arr.getPos(en_cours) < arr.getPos(en_cours-1))
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
string MainWindow::buildWord(int indice)
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

/*METODOS DE VALIDACION EN INTERFAZ*/
void MainWindow::on_sbxRango1_valueChanged(int arg1)
{
    ui->sbxRango2->setMinimum(arg1+1);
}

void MainWindow::on_sbxRango2_valueChanged(int arg1)
{
    ui->sbxRango1->setMaximum(arg1-1);
}

template <class T>
Stack<T>* MainWindow::invertirPila(Stack<T> *arr) //metodo auxiliar para el merge con pila
{
    Stack<T> *temp = new Stack<T>();
    while(arr->getSize() > 0)
        temp->push(arr->pop());
    return temp;
}

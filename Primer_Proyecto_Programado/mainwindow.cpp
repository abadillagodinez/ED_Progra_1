#include "mainwindow.h"
#include "ui_mainwindow.h"

void delay(int n)
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

}

template <typename T>
void MainWindow::GenerateBoxes(SimpleList<T> list)
{
    QBrush redBrush(Qt::red);
    QPen outlinePen(Qt::black);
    outlinePen.setWidth(2);
    int size = list.getSize();
    for(int i = 0; i< size; i++)
    {
        std::string str = std::to_string(list[i]->dato);
        QString qstr = QString::fromStdString(str);
        text = scene->addText(qstr, QFont("Arial",12));
        text->setPos(QPointF(i*50,-30));
        texts.push_back(text);
    }
}
void MainWindow::Swap(int pos1, int pos2)
{
    text = texts[pos1];
    text2 = texts[pos2];
    QPropertyAnimation *animation4 = new QPropertyAnimation(text2, "x", this);
    QPropertyAnimation *animation3 = new QPropertyAnimation(text,"x",this);
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

}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    for(int i = 0; i<=10;i++) list.insertAtHead(i);
    GenerateBoxes(list);
    //QuickSort(list,0,list.getSize()-1);
}


// SORTINGS ALGORITMS
template<class T>
int MainWindow::partition(SimpleList<T> arr, int low, int high)
{
    SimpleNode<T>* pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= (high - 1); j++)
    {
        if (arr[j]->dato <= pivot->dato){ //changes acording to which one is higher
          i++;
          //cout << "Moving" << arr[j]->dato << "," << arr[i]->dato;
          arr.swap(i,j);
          //movements.push_back(movement(i,j));
          //cout << "Inserted " <<movements[i].getX() << "," << movements[i].getY();
        }
    }
    arr.swap((i+ 1),high);
    movements.push_back(movement(i+1,high));
    //cout << "Inserted " <<movements[i+1].getX() << "," << movements[i+1].getY();
    return( i + 1 );
}

template<class T>
void MainWindow::QuickSort(SimpleList<T> arr, int low, int high)
{
    if (low < high){
        int pi = partition(arr, low, high);
        QuickSort(arr, low, pi - 1);//Makes a new group with the highers
        QuickSort(arr, pi + 1, high);//Makes a new group with the lowers

      }

}
void MainWindow::printmoves()
{
    cout << "Movements : [";
    for(std::size_t i = 0; i< (movementsDone.size()-1); i++)
    {
        movement n = movementsDone[i];
        cout << "(" << n.getX() << ","<< n.getY() << "),";
    }
    cout << "]";

}
void MainWindow::move()
{
    int m = 0;

    std::size_t i = 0;
    vector<movement>::iterator it = movements.begin();
    if(ui->radioButton_2->isChecked())
    {
        if(!movements.empty())
        {
            if(ui->checkBox->isChecked())
                m = 1000;
            else m = 500;
            movement n = movements[i];
            movementsDone.push_back(n);
            movements.erase(it);
            Swap(n.getX(),n.getY());
            delay(m);
            move();
        }
    }
    if(ui->radioButton_3->isChecked())
    {
        if(!movementsDone.empty())
        {
            i = movementsDone.size()-1;
            if(ui->checkBox->isChecked())
                m = 1000;
            else m = 500;
            movement n = movementsDone[i];
            movements.insert(it,n);
            movementsDone.pop_back();
            Swap(n.getX(),n.getY());
            delay(m);
            move();
        }
    }

}
template<class T>
void MainWindow::BubbleSort(SimpleList<T> arr)
{
    int i,j,n;
    n = arr.getSize();
    for (i = 0; i< n-1; i++)
    {
        for(j = 0; j<n-i-1; j++)
        {
            if(arr[j]->getDato() > arr[j+1]->getDato())
            {
                arr.swap(j,j+1);
                movements.push_back(movement(j,j+1));
            }
        }
    }
}
void MainWindow::on_pushButton_2_clicked()
{
    list.print();
    QuickSort(list,0,list.getSize()-1);
    move();
    list.print();
}

void MainWindow::on_pushButton_3_clicked()
{
    list.print();
    BubbleSort(list);
    move();
    //printmoves();
    list.print();
}


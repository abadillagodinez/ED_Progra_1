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
void MainWindow::GenerateBoxes(SimpleList<T> list)
{
    QBrush redBrush(Qt::white);
    QPen outlinePen(Qt::black);
    outlinePen.setWidth(2);
    int size = list.getSize();
    for(int i = 0; i< size; i++)
    {
        std::string str = std::to_string(list[i]->dato);
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
void MainWindow::move()
{
    cout << "Movements : [";
    int z = 0;
    for(std::size_t i = 0; i< (movements.size()-1); i++)
    {
        movement n = movements[i];
        cout << "(" << n.getX() << ","<< n.getY() << "),";
        //Swap(n.getX(),n.getY());
        movementsDone.push_back(n);
        if (z < 1)
        {
            Swap(n.getX(),n.getY());
            z++;
        }

    }
    cout << "]";

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
    //QuickSort(list,0,list.getSize()-1);
    BubbleSort(list);
    move();
    list.print();
}

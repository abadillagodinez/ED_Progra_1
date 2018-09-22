#include "mainwindow.h"
#include <QApplication>
#include "doblelist.h"
#include "dclist.h"
#include "simplelist.h"
#include "stack.h"
#include "queue.h"

int main(int argc, char *argv[])
{
    SimpleList<int> nepe;
    for(int i = 0; i<52;i++) nepe.insertAtHead(i);

    nepe.print();
    std::cout<< nepe[4]->dato<< endl;
    nepe.swap(1,2);
    nepe.print();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}

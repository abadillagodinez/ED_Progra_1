#include "mainwindow.h"
#include <QApplication>
#include "doblelist.h"
#include "dclist.h"
#include "simplelist.h"
#include "stack.h"
#include "queue.h"

int main(int argc, char *argv[])
{
    SimpleList<int> list;
    for(int i = 0; i<52;i++) list.insertAtHead(i);

    list.print();
    std::cout<< list[4]->dato<< endl;
    list.swap(1,2);
    list.print();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}

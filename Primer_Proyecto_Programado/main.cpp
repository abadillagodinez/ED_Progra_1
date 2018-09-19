#include "mainwindow.h"
#include <QApplication>
#include "doblelist.h"
#include "dclist.h"
#include "simplelist.h"
#include "stack.h"
#include "queue.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}

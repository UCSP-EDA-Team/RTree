#include <QCoreApplication>
#include <Tree.h>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Tree<Hyperrectangle> x(2);
    return a.exec();
}

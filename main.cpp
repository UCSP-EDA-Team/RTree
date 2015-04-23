#include <QCoreApplication>
#include <Tree.h>
#include <Hyperrectangle.h>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
<<<<<<< Updated upstream
=======
    
    double e1, e2;
    std::cin >> e1 >> e2;

    point p1 = make_pair(e1,e2);
    point p2 = make_pair(e1,e2);
    points vertices;
    vertices.push_back(p1);
    vertices.push_back(p2);
    Hyperrectangle p(vertices);

    Tree<int> t(2);

    t.insert(p,1);
    cout << "listo" << endl;
>>>>>>> Stashed changes

    return a.exec();
}

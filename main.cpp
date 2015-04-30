#include <QCoreApplication>
#include <Connector.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    
    Connector connector;
    connector.listen();

    return a.exec();
}

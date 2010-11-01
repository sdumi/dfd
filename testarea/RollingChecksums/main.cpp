#include <QtCore>
#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
	
    qDebug() << "rolling checksums...";

    exit (0);

    return a.exec();
}

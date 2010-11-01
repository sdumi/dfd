#include <QtCore>
#include <QCoreApplication>
#include "Compressor.h"

void usage()
{
	qDebug() << "Usage:";
	qDebug() << "\t Compression <option> <input_file> <output_file>";
	qDebug() << "\t\t<option>:";
	qDebug() << "\t\t\t--help || /? - to show this message";
	qDebug() << "\t\t\t-c - to compress";
	qDebug() << "\t\t\t-d - to decompress";
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    if (argc < 2)
    {
    	qDebug("insufficient arguments...");
    	usage();
    	exit (0);
    }

    QString option = argv[1];
    Compressor *c = new Compressor ();

    if (option == "--help" || option == "/?")
    {
    	usage();
    	exit(0);
    }
    else if (argc < 4)
    {
    	qDebug() << "insufficient arguments...";
    	usage();
    	exit(0);
    }

    if (option == "-c")
    {
    	c->compress(argv[2], argv[3]);

    }
    else if (option == "-d")
    {
    	c->decompress(argv[2], argv[3]);
    }
    else
    {
    	qDebug("unknown option!");
    	usage();
    	exit (0);
    }

    delete c;

    qDebug("Done!");

    exit (1);
	
    return a.exec();
}

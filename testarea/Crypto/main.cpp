#include <QtCore>
#include <QCoreApplication>

#include "Crypto.h"
#include <iostream>

using namespace std;

void usage ()
{
	qDebug() << "Usage: Crypto <option> <filename>";
	qDebug() << "\t <option>:";
	qDebug() << "\t\t--help || /? - displays this message :)";
	qDebug() << "\t\tmd4 - for md4 checksum";
	qDebug() << "\t\tmd5 - for md5 checksum";
	qDebug() << "\t\tsha1 - for sha1 checksum";
	qDebug() << "\t <filename>:";
	qDebug() << "\t\tany filename :)";
}

int main(int argc, char *argv[])
{

	if (argc < 2)
	{
		cout << "insufficient arguments\n";
		usage();
		exit (0);
	}
	else
	{
		QString option (argv[1]);
		if (option == "--help" || option == "/?")
		{
			usage();
			exit (0);
		}

		if (argc < 3)
		{
			qDebug() << "Insufficient arguments!";
			usage();
			exit (0);
		}
		if (option != "md4" && option != "md5" && option != "sha1")
		{
			cout << "hash algorithms supported are: md4 and md5" << endl;
			usage();
			exit (0);
		}
	}

    QCoreApplication a(argc, argv);

    Crypto *c = new Crypto ();
    c->generateHash(argv[2], argv[1]);
    delete c;
    exit (0);
	
    return a.exec();
}

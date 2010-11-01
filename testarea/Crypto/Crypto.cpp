/*
 * Crypto.cpp
 *
 *  Created on: Oct 27, 2010
 *      Author: dpomian
 */

#include <QDebug>
#include <QCryptographicHash>
#include <iostream>
#include "Crypto.h"

using namespace std;

Crypto::Crypto()
{
}

Crypto::~Crypto()
{
}

void Crypto::generateHash(QString fileName, QString method)
{
	QCryptographicHash::Algorithm hash_algorithm;
	if (method == "md5")
		hash_algorithm = static_cast<QCryptographicHash::Algorithm> (QCryptographicHash::Md5);
	else if (method == "md4")
		hash_algorithm = static_cast<QCryptographicHash::Algorithm> (QCryptographicHash::Md4);
	else if (method == "sha1")
		hash_algorithm = static_cast<QCryptographicHash::Algorithm> (QCryptographicHash::Sha1);

	QCryptographicHash cryptoHash (hash_algorithm);
	QFile file (fileName);

	if (!file.exists(fileName))
	{
		cout << "file '" << fileName.toStdString() << "' does not exist..." << endl;
		return;
	}

	file.open (QIODevice::ReadOnly);
	const int blockSize = 500;
	char buffer[blockSize];
	int bytesRead;

	while ((bytesRead = file.read (buffer, blockSize)) > 0)
	{
		cryptoHash.addData(buffer, bytesRead);
	}

	qDebug() << fileName << "<- " << method << " -> " << cryptoHash.result().toHex();

	file.close();
}

/*
 * Roller.h
 *
 *  Created on: Nov 2, 2010
 *      Author: dpomian
 */

#ifndef ROLLER_H_
#define ROLLER_H_

#include <QString>
#include <QFile>
#include <QList>

#define _CHUNK_SIZE_ 4096
#define _WINDOW_SIZE_ 700
#define _MODULO_ 65536

class Roller
{
	QString _inputFileName;
	QString _wrOutFileName;
	QString _winWrOutFileName;
	QList<QString> nonOverlapingWeakChecksums;

private:
	quint64 checksum (QByteArray buffer);

public:
	Roller(const char* inputFileName);
	virtual ~Roller();

	bool doWeakRollChecksum();
	bool writeNonOverlapingWeakChecksumsToFile();
};

#endif /* ROLLER_H_ */

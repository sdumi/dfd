/*
 * Roller.cpp
 *
 *  Created on: Nov 2, 2010
 *      Author: dpomian
 */

#include <QDebug>
#include "Roller.h"

Roller::Roller(const char* inputFileName)
{
	_inputFileName = inputFileName;
	_wrOutFileName = "checksums.txt";
	_winWrOutFileName = "windowed_checksums.txt";
}

Roller::~Roller()
{
}

bool Roller::doWeakRollChecksum()
{
	QFile inFile (_inputFileName);
	if (!inFile.open(QIODevice::ReadOnly))
	{
		qDebug() << "cannot open input file...";
		return false;
	}

	int bytesRead;
	char readBuffer[_CHUNK_SIZE_];
	QByteArray bytesBuffer("");
	QString strChecksum;

	while ((bytesRead = inFile.read(readBuffer, _CHUNK_SIZE_)) > 0)
	{
		bytesBuffer.append(readBuffer, bytesRead);
		if (bytesBuffer.size() <= _WINDOW_SIZE_)
		{
			strChecksum.setNum(checksum(bytesBuffer), 16);
			nonOverlapingWeakChecksums.push_back(strChecksum);
			strChecksum.clear();
			bytesBuffer.clear();
		}
		else
		{
			int iterations = bytesBuffer.size()/_WINDOW_SIZE_;
			for (int i=0; i<iterations; i++)
			{
				int startIndex = i*_WINDOW_SIZE_;
				strChecksum.setNum(checksum(bytesBuffer.mid(startIndex, _WINDOW_SIZE_)), 16);
				nonOverlapingWeakChecksums.push_back(strChecksum);
				strChecksum.clear();
			}
			bytesBuffer.remove(0,iterations*_WINDOW_SIZE_);
		}
	}

	if (bytesBuffer.size() > 0)
	{
		strChecksum.setNum(checksum(bytesBuffer), 16);
		nonOverlapingWeakChecksums.push_back(strChecksum);
		strChecksum.clear();
	}

	inFile.close();

	return true;
}

quint64 Roller::checksum(QByteArray buffer)
{
	qint64 wra = 0;
	qint64 wrb = 0;
	quint64 result;

	for (int i=0; i<buffer.size(); i++)
	{
		wra += buffer.at(i);
		wrb += buffer.at(i)*(buffer.size()-1-i+1);
	}

	wra = wra % _MODULO_;
	if (wra < 0)
		wra += _MODULO_;
	wrb = wrb % _MODULO_;
	if (wrb < 0)
		wrb += _MODULO_;

	result = wra + wrb*_MODULO_;

	return result;
}

bool Roller::writeNonOverlapingWeakChecksumsToFile()
{
	QFile outFile (_wrOutFileName);
	if (!outFile.open (QIODevice::WriteOnly))
	{
		qDebug() << "cannot open " << _wrOutFileName;
		return false;
	}

	for (int i=0; i<nonOverlapingWeakChecksums.length(); i++)
	{
		outFile.write(nonOverlapingWeakChecksums.at(i).toStdString().c_str());
		outFile.write ("\n");
	}

	outFile.close();

	return true;
}

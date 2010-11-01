/*
 * Compressor.cpp
 *
 *  Created on: Oct 25, 2010
 *      Author: dpomian
 */

#include <QByteArray>
#include <QFile>
#include "Compressor.h"

Compressor::Compressor() {
	// TODO Auto-generated constructor stub

}

Compressor::~Compressor() {
	// TODO Auto-generated destructor stub
}

void Compressor::compress(QString inputFile, QString outputFile)
{
	QString outputFileName;

	if (outputFile == "")
	{
		QString inputFileName;
		QString inputFileExtension;

		int sepPos = inputFile.lastIndexOf('.');

		if (sepPos != -1)
		{
			inputFileName = inputFile.left(sepPos);
			inputFileExtension = inputFile.right(sepPos);
			outputFileName = inputFileName + "_out." + inputFileExtension;
		}
		else
			outputFile = inputFile + "_out";
	}
	else
		outputFileName = outputFile;

	// open files
	qDebug("open files...");
	QFile infile (inputFile);
	QFile outfile (outputFileName);

	infile.open(QIODevice::ReadOnly);
	outfile.open(QIODevice::WriteOnly);

	qDebug("reading input file...");
	QByteArray uncompressedData = infile.readAll();

	qDebug("compressing data...");
	QByteArray compressedData = qCompress (uncompressedData);

	// write compressed data to file
	qDebug("write data to file...");
	outfile.write(compressedData);

	// close files
	infile.close();
	outfile.close();
}

void Compressor::decompress(QString inputFile, QString outputFile)
{
	// open files
	QFile infile (inputFile);
	QFile outfile (outputFile);

	infile.open(QIODevice::ReadOnly);
	outfile.open (QIODevice::WriteOnly);

	qDebug("reading input file...");
	QByteArray compressedData = infile.readAll();

	qDebug("uncompressing data...");
	QByteArray uncompressedData = qUncompress (compressedData);

	// write uncompressed data to output file
	qDebug("writing data to file...");
	outfile.write (uncompressedData);

	// close files
	infile.close();
	outfile.close();
}

/*
 * Compressor.h
 *
 *  Created on: Oct 25, 2010
 *      Author: dpomian
 */

#ifndef COMPRESSOR_H_
#define COMPRESSOR_H_

#include <qstring.h>

class Compressor {
public:
	Compressor();
	void compress (QString inputFile, QString outputFile);
	void decompress (QString inputFile, QString outputFile);
	virtual ~Compressor();
};

#endif /* COMPRESSOR_H_ */

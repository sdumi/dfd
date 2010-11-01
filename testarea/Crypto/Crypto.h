/*
 * Crypto.h
 *
 *  Created on: Oct 27, 2010
 *      Author: dpomian
 */

#ifndef CRYPTO_H_
#define CRYPTO_H_

#include <QString>
#include <QFile>

class Crypto {
public:
	Crypto();
	virtual ~Crypto();
	void generateHash (QString infile, QString method);
};

#endif /* CRYPTO_H_ */

/*
 * ChecksumInfo.h
 *
 *  Created on: Nov 2, 2010
 *      Author: dpomian
 */

#ifndef CHECKSUMINFO_H_
#define CHECKSUMINFO_H_

#include <QString>

enum TO_STRING_DETAIL_LEVEL {LEVEL0 = 0, LEVEL1 = 1};

class ChecksumInfo {
private:
	quint32 _startIndex;
	quint32 _endIndex;
	QString	_strChecksum;
	QByteArray _buffer;
	TO_STRING_DETAIL_LEVEL _detailLevel;
public:
	ChecksumInfo(quint32 startIndex_, quint32 endIndex_, QString strChecksum_);
	ChecksumInfo(QByteArray byteArray, QString strChecksum);
	ChecksumInfo(QString strChecksum);
	virtual ~ChecksumInfo();

	quint32 getStartIndex () const;
	quint32 getEndIndex () const;
	QString getStringChecksum() const;
	QString toQString() const;
};

#endif /* CHECKSUMINFO_H_ */

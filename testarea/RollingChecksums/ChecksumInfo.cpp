/*
 * ChecksumInfo.cpp
 *
 *  Created on: Nov 2, 2010
 *      Author: dpomian
 */

#include "ChecksumInfo.h"

ChecksumInfo::ChecksumInfo(quint32 startIndex_, quint32 endIndex_, QString strChecksum_)
{
	_startIndex = startIndex_;
	_endIndex = endIndex_;
	_strChecksum = strChecksum_;
}

ChecksumInfo::ChecksumInfo(QByteArray byteArray, QString checksum)
{
	_strChecksum = checksum;
	_buffer = byteArray;
	_detailLevel = LEVEL1;
}

ChecksumInfo::ChecksumInfo(QString strChecksum)
{
	_strChecksum = strChecksum;
	_detailLevel = LEVEL0;
}

ChecksumInfo::~ChecksumInfo()
{

}

quint32 ChecksumInfo::getStartIndex() const
{
	return _startIndex;
}

quint32 ChecksumInfo::getEndIndex() const
{
	return _endIndex;
}

QString ChecksumInfo::getStringChecksum() const
{
	return _strChecksum;
}

QString ChecksumInfo::toQString() const
{
	QString result("");

	switch (_detailLevel)
	{
	case LEVEL0:
		result.append(_strChecksum);
		break;
	case LEVEL1:
		result.append(_strChecksum);
		result.append ("-> ");
		result.append (_buffer.data());
		break;
	}

	return result;
}

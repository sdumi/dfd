/*
 * QtClient.h
 *
 *  Created on: Oct 22, 2010
 *      Author: dpomian
 */

#ifndef QTCLIENT_H_
#define QTCLIENT_H_

#include <QtNetwork>

class QtClient : public QObject
{
	Q_OBJECT

private:
	int port;
	QTcpSocket *client;

public:
	QtClient ();
	~QtClient();

	bool start (QString address, quint16 port);

protected slots:
	void clientConnected ();
	void read ();
	void showError ();
};

#endif /* QTCLIENT_H_ */

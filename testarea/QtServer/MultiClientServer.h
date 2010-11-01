/*
 * MultiClientServer.h
 *
 *  Created on: Oct 22, 2010
 *      Author: dpomian
 */

#ifndef MULTICLIENTSERVER_H_
#define MULTICLIENTSERVER_H_

#include <QtNetwork>

class MultiClientServer : public QTcpServer
{
	Q_OBJECT

protected:
	void sendHello (QTcpSocket *client);

protected slots:
	void handleNewConnection ();
	void clientDisconnected ();
	void sendMessageToAllClients();

private:
	int _PORT_;
	QList <QTcpSocket *> clientConnections;
	QTimer messageTimer;

public:
	MultiClientServer(int port_);
	~MultiClientServer();

	void start();
	void stop();
};

#endif /* MULTICLIENTSERVER_H_ */

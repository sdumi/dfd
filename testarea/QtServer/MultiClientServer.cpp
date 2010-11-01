/*
 * MultiClientServer.cpp
 *
 *  Created on: Oct 22, 2010
 *      Author: dpomian
 */

#include "MultiClientServer.h"
#include <iostream>

using namespace std;

MultiClientServer::MultiClientServer(int port_)
{
	this->_PORT_ = port_;

	connect (&messageTimer, SIGNAL(timeout()), this, SLOT (sendMessageToAllClients()));
	connect (this, SIGNAL(newConnection()), this, SLOT (handleNewConnection()));
}

MultiClientServer::~MultiClientServer()
{
	stop();
}

void MultiClientServer::stop()
{
	messageTimer.stop();
	close();
	qDeleteAll (clientConnections);
}

void MultiClientServer::start()
{
	qDebug() << "Server started on port: " << this->_PORT_;
	qDebug() << "Listening for incoming connections\n";

	messageTimer.start(1000);
	listen (QHostAddress::LocalHost, this->_PORT_);
}

void MultiClientServer::handleNewConnection()
{
	while (hasPendingConnections())
	{
		QTcpSocket *client = nextPendingConnection();
		connect (client, SIGNAL (disconnected()), this, SLOT(clientDisconnected()));
		this->clientConnections.append(client);

		qDebug() << "new client connected";
		qDebug() << "clients logged in: " << clientConnections.length();

		this->sendHello(client);
	}
}

void MultiClientServer::clientDisconnected()
{
	QTcpSocket *client = qobject_cast<QTcpSocket *> (sender());
	if (!client)
		return;

	clientConnections.removeAll(client);

	qDebug() << "client disconnected";
	qDebug() << "number of clients: " << clientConnections.length() << endl;

	client->deleteLater();
}

void MultiClientServer::sendHello(QTcpSocket *client_)
{
	if (!client_)
		return;

	client_->write("Hello \n");
}

void MultiClientServer::sendMessageToAllClients()
{
	QString message = QString ("The current time is: %1\n").arg(QTime::currentTime().toString ("hh:mm:ss"));

	foreach (QTcpSocket *client, clientConnections)
	{
		client->write (message.toLatin1());
	}
}

/*
 * QtClient.cpp
 *
 *  Created on: Oct 22, 2010
 *      Author: dpomian
 */

#include "QtClient.h"
#include <iostream>

using namespace std;

QtClient::QtClient()
{
	client = new QTcpSocket (this);

	connect (client, SIGNAL (connected ()), this, SLOT (clientConnected()));
	connect (client, SIGNAL (readyRead ()), this, SLOT (read()));
	connect (client, SIGNAL (error (QAbstractSocket::SocketError)), this, SLOT (showError()));
}

QtClient::~QtClient()
{
	client->close();
}

bool QtClient::start(QString address, quint16 port)
{
	QHostAddress addr (address);

	cout << "connecting to: " << address.toStdString() << " port: " << port << endl;

	client->connectToHost(addr, port);

	if (!client)
	{
		cout << "connection failed!" << endl;
		return false;
	}

	return true;
}

void QtClient::clientConnected()
{
	cout << "Client connected!"<< endl;
}

void QtClient::read()
{
	QString data (client->readAll());

	cout << data.toStdString() << endl;
}

void QtClient::showError()
{
	cout << "Error: " << client->errorString().toStdString() << endl;
}

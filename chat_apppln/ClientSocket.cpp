#include "ClientSocket.h"
#include "SocketException.h"
#include <errno.h>

// constructor to initialize the client
ClientSocket::ClientSocket( string ip, int port )
{
	if( Socket::create() == 0 )
	{
		throw SocketException(errno);
	}

	if( Socket::connect(ip, port) < 0 )
	{
		throw SocketException(errno);
	}
}

// sending the data 
ClientSocket& ClientSocket::operator << ( const string& s )
{
	if( Socket::send(s) < 0)
	{
		throw SocketException(errno);
	}

	return *this;
}

// recieving the data
ClientSocket& ClientSocket::operator >> ( string& s )
{
	if( Socket::recv(s) < 0)
	{
		throw SocketException(errno);
	}

	return *this;
}

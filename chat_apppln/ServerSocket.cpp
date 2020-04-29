#include "ServerSocket.h"
#include "SocketException.h"
#include <errno.h>

// constructor to initialize the server
ServerSocket::ServerSocket(int port)
{
	if( Socket::create() == 0 )
	{
		throw SocketException(errno);
	}

	if( Socket::bind( port ) < 0 )
	{
		throw SocketException(errno);
	}

	if( Socket::listen() < 0 )
	{
		throw SocketException(errno);
	}
}

// destructor
ServerSocket::~ServerSocket()
{

}

//  operator overload << : to send data
ServerSocket& ServerSocket::operator << ( const string& s )
{
	if( Socket::send( s ) < 0 )
	{
		throw SocketException(errno);
	}

	return *this;
}

// operator overload >> : to recieve data
ServerSocket& ServerSocket::operator >> ( string& s )
{
	if( Socket::recv( s ) < 0)
	{
		throw SocketException(errno);
	}

	return *this;
}

// accepting the connection on new socket
void ServerSocket::accept( ServerSocket& sock)
{
	if( Socket::accept( sock ) <= 0)
	{
		throw SocketException(errno);
	}
}

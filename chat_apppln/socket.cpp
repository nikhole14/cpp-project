#include "socket.h"
#include <string.h>

Socket::Socket()
{
	sockfd = -1;
	memset(&address, 0, sizeof(address));
}

Socket::~Socket()
{
	close(sockfd);
}

/*
func: create
desc: creating socket connection 
return: on success = 0, on failed = -1
*/
int Socket::create()
{
	// creating file descriptor for end point communication
	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	int opt = 1;
	if(setsockopt( sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)) < 0)
		return -1;

	return sockfd;
}

/*
func: bind
desc: binding address to the socket
return: on success = 0, on failed = -1
*/
int Socket::bind(const int port)
{
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(port);

	int bind_ret = ::bind(sockfd, (struct sockaddr*)&address, sizeof(address));

	return bind_ret;
}

/*
func: listen
desc: listening on connection for socket
return: on success = 0, on failed = -1
*/
int Socket::listen()
{
	int listen_ret = ::listen(sockfd, 5);
	return listen_ret;
}


/*
func: accept
desc: accept the connection on socket
return: on success = non negative value, on failed = -1
*/
int Socket::accept( Socket& new_sock)
{
	int addrlen = sizeof(address);
	new_sock.sockfd = ::accept( sockfd, (struct sockaddr*)&address, (socklen_t*)&addrlen );
	
	return new_sock.sockfd;
}

/*
func: connect
desc: initiate a connection on socket
return: on success = 0, on failed = -1
*/
int Socket::connect(const string ip, const int port)
{
	address.sin_family = AF_INET;
	address.sin_port = htons(port);

	// converting IPv4 address text to binary form
	int status = inet_pton( AF_INET, ip.c_str(), &address.sin_addr );
	if(status <= 0)
	{
		return status;
	}

	status = ::connect( sockfd, (sockaddr *)&address, sizeof(address) );
}

/*
func: send
desc: send messagen on socket
return: on success = no of bytes sent, on failed = -1
*/
int Socket::send( const string s )
{
//	cout <<"sending string" << s <<endl;
	int send_ret = ::send( sockfd, s.c_str(), s.size(), 0);

	return send_ret;
}


/*
func: recv
desc: recieve messagen from socket
return: on success = no of bytes recieved, on failed = -1
*/
int Socket::recv( string& s )
{
	s = "";
	char buffer[1024 + 1];
	memset(buffer, 0, sizeof(buffer));
	int recv_ret = ::recv( sockfd, buffer, 1024, 0);
	if(recv_ret != -1)
		s = buffer;

	return recv_ret;
}

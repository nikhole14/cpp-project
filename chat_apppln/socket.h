#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<unistd.h>
#include<string>
#include<arpa/inet.h>
#include<sys/types.h>
#include<iostream>

using namespace std;

class Socket
{
	public:
		Socket();
		virtual ~Socket();

		// Server initialization
		int create();
		int bind(const int port);
		int listen();
		int accept( Socket& );

		// Client initialization
		int connect(const string ip, const int port);

		// Data transmission
		int send( const string );
		int recv( string& );

	private:
		int sockfd;
		struct sockaddr_in address;
};

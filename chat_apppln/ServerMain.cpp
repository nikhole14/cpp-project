#include "ServerSocket.h"
#include "SocketException.h"
#include <iostream>

int main(int argc, char* argv[])
{
	try
	{
		// initialize server on port 8080
		ServerSocket server(8080);

		while(1)
		{
			ServerSocket n_sock;

			// accepting the connection on new socket
			server.accept(n_sock);

			while(1)
			{
				string data;

				// recieving the message from client
				n_sock >> data;
				cout <<"From Client: " <<data <<endl;

				string reply;

				// sending the message to client
				cout <<"You: ";
				getline(cin, reply);
				n_sock <<  reply;
			}
		}
	}
	catch( SocketException& se)
	{
		// printing if any exception
		std::cout <<"Error : " <<se.desc() <<endl;
	}

	return 0;
}

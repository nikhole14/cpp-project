#include "ClientSocket.h"
#include "SocketException.h"
#include <iostream>

int main(int argc, char* argv[])
{
	try
	{
		// initialize the client using ip and port 8080
		ClientSocket client( "127.0.0.1", 8080 );
		

		while(1)
		{
			// sending the message to server
			string data;
			cout <<"You: ";
			getline(cin, data);
			client << data;

			// recieving the message from server
			string reply;
			client >> reply;

			cout <<"From Server: " << reply <<endl;
		}	
	}
	catch( SocketException& se)
	{
		// printing if any exception
		std::cout <<"Error: " <<se.desc() <<endl;
	}

	return 0;
}

#include "socket.h"

class ServerSocket: private Socket
{
	public:

		// server initialization
		ServerSocket(int port);
		ServerSocket(){};
		virtual ~ServerSocket();

		// data send & recieve
		ServerSocket& operator << ( const string& s );
		ServerSocket& operator >> ( string& s );

		// accept the connection on new socket
		void accept( ServerSocket& );

};

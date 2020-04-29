#include "socket.h"

class ClientSocket : private Socket
{
	public:
		// initialize the client
		ClientSocket( string ip, int port ) ;
		virtual ~ClientSocket(){};

		// sending and recieving the data
		ClientSocket& operator << ( const string& s );
		ClientSocket& operator >> ( string& s );
};

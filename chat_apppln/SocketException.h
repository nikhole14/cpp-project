#include <string>
#include <exception>
#include <string.h>

class SocketException : public exception
{
	public:
		// constructor to initialize msg of thrown exception
		SocketException( int erno)
		{
			this->erno = erno;
		}

		// destructor
		~SocketException()
		{

		}

		// returning the thrown msg
		string desc()
		{
			msg = strerror(erno);
			return msg;
		}

	private:
		int erno;
		string msg;
};

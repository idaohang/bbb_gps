#ifndef CSERVER_H
#define CSERVER_H

#include "winsock2.h"

#define DEFAULT_IP ("127.0.0.1")
#define DEFAULT_PORT 8181
#define MAX_CONNECTIONS (10)

namespace GPS_Server
{

class cServer
{
	public:
		/** Default constructor */
		cServer();
		/** Default destructor */
		virtual ~cServer();

		bool Ready();
		int Start();
		int ClientCount();
		SOCKET * GetSocket();
		sockaddr_in * GetEndPoint();
		void IncClients();
		void DecClients();

	protected:

	private:

	SOCKET * m_Socket;
	sockaddr_in* m_EP;
	UINT32 m_Clients;

	bool m_Ready;

};

}

#endif // CSERVER_H

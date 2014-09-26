#include "cServer.h"
#include "winsock2.h"
#include <string>

#include "cServerFunctions.h"

using namespace GPS_Server;

inline int CreateMySocket(SOCKET & sckt)
{

	sckt = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if(sckt == INVALID_SOCKET)
	{
		WSACleanup();
		return -1;
	}

	return 0;
}

inline int CreateMyEndpoint(sockaddr_in * ep, std::string ipAddr, USHORT port)
{

    ep->sin_family = AF_INET;
    ep->sin_addr.s_addr = inet_addr(ipAddr.c_str());
    ep->sin_port = htons(port);

    return 0;
}

inline int MyListen(cServer * srv)
{
	SOCKET * sckt = srv->GetSocket();
	listen(*sckt, MAX_CONNECTIONS);

	SOCKET client;

    while(1)
	{
		client = SOCKET_ERROR;
		while(client == SOCKET_ERROR)
		{
			client = accept(*sckt, NULL, NULL);
		}
		sckt = &client;
		srv->IncClients();
		break;
	}

	WSACleanup();
	return 0;
}


int ServiceStart(cServer * srv)
{

	if(bind(*srv->GetSocket(), (SOCKADDR *)srv->GetEndPoint(), sizeof(*srv->GetEndPoint())) == SOCKET_ERROR)
	{
		closesocket(*srv->GetSocket());
        return -1;
	}

	return MyListen(srv);
}

int ServiceStart(cServer * srv, std::string ipAddr, USHORT port)
{
	if(srv->GetSocket() == nullptr)
	{
		if(CreateMySocket(*srv->GetSocket()) != 0)
		{
			return -1;
		}
	}

	if(srv->GetEndPoint() == nullptr)
	{
		if(CreateMyEndpoint(srv->GetEndPoint(), ipAddr, port) != 0)
		{
			return -1;
		}
	}

	return ServiceStart(srv);
}

cServer::cServer()
{
	m_Clients = 0;
	if(CreateMySocket(*m_Socket) != 0)
	{
		m_Ready = (CreateMyEndpoint(m_EP, DEFAULT_IP, DEFAULT_PORT) == 0);
	}
	else
	{
		m_Ready = false;
	}
}

cServer::~cServer()
{
}

int cServer::Start()
{
	if(!m_Ready)
	{
		return 1;
	}

	return ServiceStart(this);
}

int cServer::ClientCount()
{
	return m_Clients;
}

SOCKET * cServer::GetSocket()
{
	return m_Socket;
}

sockaddr_in * cServer::GetEndPoint()
{
	return m_EP;
}

inline void cServer::IncClients()
{
	m_Clients++;
}

inline void cServer::DecClients()
{
	m_Clients--;
}

bool cServer::Ready()
{
	return m_Ready;
}

//END FILE

#include "cClient.h"

using namespace GPS_Server;

cClient::cClient()
{
	m_Type = ClientType::UNKNOWN;
}

cClient::cClient(ClientType type)
{
    m_Type = type;
}

cClient::~cClient()
{
	//dtor
}

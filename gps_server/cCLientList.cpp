#include "cCLientList.h"
#include "cClient.h"
#include <deque>

using namespace GPS_Server;

int FindElementInt(std::deque<cClient *> d, cClient * val)
{
	int i = 0;
	int iLength = d.size();

	for(; i < iLength; i++)
	{
		if(d[i] == val)
		{
			break;
		}
	}

	return i;
}

std::deque<cClient *>::iterator FindElementIter(std::deque<cClient *> d, cClient * val)
{

    std::deque<cClient *>::iterator it = d.begin();
    for(;it != d.end(); it++)
	{
		if(*it == val)
			break;
	}

	return it;
}

cCLientList::cCLientList()
{
	//ctor
}

cCLientList::~cCLientList()
{
	//dtor
}

int cCLientList::AddClient(cClient * val)
{

	if(!m_Lock)
	{
		m_Lock = !m_Lock;
		m_Clients.push_back(val);
		m_Lock = !m_Lock;
	}

	return 0;
}

int cCLientList::DelClient(cClient * val)
{

	if(!m_Lock)
	{
		m_Lock = !m_Lock;
		std::deque<cClient *>::iterator del = FindElementIter(m_Clients, val);
		m_Clients.erase(del);
		m_Lock = !m_Lock;
	}

	return 0;
}

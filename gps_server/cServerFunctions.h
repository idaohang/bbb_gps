#ifndef CSERVERFUNCTIONS_H
#define CSERVERFUNCTIONS_H

#include "cServer.h"
#include "winsock2.h"


int CreateMySocket(SOCKET &);

int CreateMyEndpoint(sockaddr_in * ep, std::string ipAddr, USHORT port);

int ServiceStart(GPS_Server::cServer *);

int ServiceStart(GPS_Server::cServer *, std::string , USHORT );

#endif

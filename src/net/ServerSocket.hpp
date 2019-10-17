#pragma once

#include "Socket.hpp"
#include <netinet/in.h>

class ServerSocket : public Socket
{
  private:
	int port;
	struct sockaddr_in servaddr;
	int max_connections;
  public:
	ServerSocket(int port);
	void Listen();
	void Accept();

	inline void SetMaxConnections(int n) { max_connections = n; }
};


#pragma once

#include "Socket.hpp"
#include <netinet/in.h>
#include <memory>

class ServerSocket : public Socket
{
  private:
	int port;
	struct sockaddr_in servaddr;
	int max_connections;
	fd_set read_set;
	struct timeval timeout;
  public:
	ServerSocket(int port);
	void Listen();
	std::unique_ptr<Socket> Accept();

	inline void SetMaxConnections(int n) { max_connections = n; }
};


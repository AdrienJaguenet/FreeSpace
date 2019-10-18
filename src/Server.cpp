#include "Server.hpp"

#include "net/ServerSocket.hpp"

#include <iostream>
#include "signal.h"

bool closeServer(false);

void CloseServer(int signal)
{
	std::cerr << "Received ^C" << std::endl;
	closeServer = true;
}

Server::Server(int port) :
	socket(port),
	acceptThread(&Server::AcceptLoop, this)
{
	std::cerr << "Socket listening..." << std::endl;
	socket.Listen();
	std::cerr << "Joining accept thread" << std::endl;
	acceptThread.join();
}

void Server::AcceptLoop()
{
	std::cerr << "AcceptLoop launched..." << std::endl;
	while (not closeServer) {
		std::unique_ptr<Socket> client = socket.Accept();
		if (client) {
		}
	}
}

int main()
{
	signal(SIGINT, CloseServer);
	Server server(10000);
	return 0;
}


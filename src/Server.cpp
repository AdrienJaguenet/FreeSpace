#include "net/ServerSocket.hpp"

#include <iostream>
#include "signal.h"

bool closeServer(false);

void CloseServer(int signal)
{
  std::cerr << "Received ^C" << std::endl;
  closeServer = true;
}

int main()
{
  signal(SIGINT, CloseServer);
  int port(10000);
  std::cerr << "Starting server on port " << port << std::endl;
  ServerSocket s(10000);
  s.Listen();
  while (not closeServer) {
	std::cerr << "Accepting connections..." << std::endl;
	std::unique_ptr<Socket> client = s.Accept();
	if (client) {
	  *client << "Hello";
	}
  }
  return 0;
}


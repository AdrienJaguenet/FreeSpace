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

void Server::Init() 
{
  std::cerr << "Init()" << std::endl;
  std::lock_guard<std::mutex> initGuard(initMutex);
  socket.Listen();
  std::cerr << "Listening..." << std::endl;
  socketListening = true;
  socketReady.notify_one();
}

Server::Server(int port) :
  socketListening(false),
  socket(port),
  acceptThread(&Server::AcceptLoop, this)
{
  {
	std::lock_guard<std::mutex> socketLock(initMutex);
	std::cerr << "Socket listening..." << std::endl;
	socket.Listen();
  }
  std::cerr << "Joining accept thread" << std::endl;
  acceptThread.join();
}

void Server::AcceptLoop()
{
  std::cerr << "AcceptLoop launched..." << std::endl;
  std::unique_lock<std::mutex> initLock(initMutex);
  socketReady.wait(initLock, [this] { return socketListening; });
  std::cerr << "Accepting..." << std::endl;
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


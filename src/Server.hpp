#pragma once

#include <thread>
#include <mutex>
#include <condition_variable>

#include "net/Socket.hpp"
#include "net/ServerSocket.hpp"

class Server
{
  private:
	int port;
	ServerSocket socket;
	std::thread acceptThread;
  public:
	Server(int port);

	void AcceptLoop();
	void CloseServer(int signal);
};


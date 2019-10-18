#pragma once

#include "Socket.hpp"

class ClientSocket : public Socket
{
private:
public:
	ClientSocket(const std::string& address, int port);
};


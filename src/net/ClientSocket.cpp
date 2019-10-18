#include "ClientSocket.hpp"

#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <cstring>
#include <cerrno>

#include <stdexcept>

ClientSocket::ClientSocket(const std::string& address, int port) :
	Socket()
{
	struct sockaddr_in servaddr, client;
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = inet_addr(address.c_str());
	servaddr.sin_port = htons(port);

	if (connect(GetSocketDescriptor(), (struct sockaddr*)&servaddr, sizeof(servaddr)) != 0) {
		throw std::runtime_error("Could not connect to " + address + ": " + std::string(strerror(errno)));
	}
}


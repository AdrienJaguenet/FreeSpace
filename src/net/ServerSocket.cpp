#include "ServerSocket.hpp"

#include <fcntl.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdexcept>
#include <cerrno>
#include <cstdlib>
#include <cstring>
#include <iostream>

ServerSocket::ServerSocket(int port) :
  Socket(),
  port(port)
{
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  servaddr.sin_port = htons(port);
  if (bind(GetSocketDescriptor(), (struct sockaddr*) &servaddr, sizeof(servaddr)) != 0) {
	throw std::runtime_error("Could not bind server socket: " + std::to_string(errno));
  }
  int flags = fcntl(GetSocketDescriptor(), F_GETFL);
  fcntl(GetSocketDescriptor(), F_SETFL, flags | O_NONBLOCK);
}

void ServerSocket::Listen()
{
  if (listen(GetSocketDescriptor(), max_connections) != 0) {
	throw std::runtime_error("Could not listen: " + std::to_string(errno));
  }
  FD_ZERO(&read_set);
}

std::unique_ptr<Socket> ServerSocket::Accept()
{
  struct sockaddr_in client;
  unsigned int length;
  int client_fd;

  timeout.tv_sec = 1;

  FD_SET(GetSocketDescriptor(), &read_set);
  select(GetSocketDescriptor() + 1, &read_set, NULL, NULL, &timeout);
  if (FD_ISSET(GetSocketDescriptor(), &read_set)) {
	length = sizeof(client);
	client_fd = accept(GetSocketDescriptor(), (struct sockaddr*) &client, &length);
	if (client_fd < 0) {
	  if (errno != EWOULDBLOCK) {
		throw std::runtime_error("Error accepting: " + std::string(strerror(errno)));
		sleep(1);
	  }
	} else {
	  std::cerr << "Accepted connection from " << inet_ntoa(client.sin_addr) << std::endl;
	  return std::make_unique<Socket>(client_fd);
	}
  }
  return nullptr;
}


#include "ServerSocket.hpp"

#include <arpa/inet.h>
#include <stdexcept>
#include <cerrno>
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
}

void ServerSocket::Listen()
{
  if (listen(GetSocketDescriptor(), max_connections) != 0) {
	throw std::runtime_error("Could not listen: " + std::to_string(errno));
  }
}

void ServerSocket::Accept()
{
  struct sockaddr_in client;
  unsigned int len = sizeof(client);
  int sd = accept(GetSocketDescriptor(), (struct sockaddr*) &client, &len);
  if (sd < 0) {
	throw std::runtime_error("Could not accept: " + std::to_string(errno));
  }
  std::string client_ip(inet_ntoa(client.sin_addr));
  std::cerr << "Accepted connection from " << client_ip << std::endl;
}

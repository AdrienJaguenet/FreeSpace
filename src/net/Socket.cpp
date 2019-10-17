#include "Socket.hpp"

#include <unistd.h>
#include <sys/socket.h>
#include <cerrno>
#include <stdexcept>

Socket::Socket()
{
  socket_d = socket(AF_INET, SOCK_STREAM, 0);
  if (socket_d < 0) {
	throw std::runtime_error("Could not create socket: " + std::to_string(errno));
  }
}

Socket::~Socket()
{
  if (socket_d > 0) {
	close(socket_d);
  }
}

Socket& Socket::operator>>(std::string& s)
{
  int written = write(socket_d, s.c_str(), s.size());
  if (written < s.size()) {
	throw std::runtime_error("Could only write " + std::to_string(written) + " bytes to socket");
  }
  return *this;
}

Socket& Socket::operator<<(std::string& s)
{
  char buffer[4096];
  int bytes_read = read(socket_d, buffer, 4096);
  if (bytes_read < 0) {
	throw std::runtime_error("Could not read any byte");
  }
  s.assign(std::string(buffer, bytes_read));
  return *this;
}


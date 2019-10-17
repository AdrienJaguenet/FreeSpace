#pragma once

#include <string>

class Socket
{
  private:
	int socket_d;
  public:
	Socket();
	Socket(int fd) : socket_d(fd) {}
	~Socket();

	/* read */
	Socket& operator<<(const std::string& s);

	/* write */
	Socket& operator>>(std::string& s);

	inline const int& GetSocketDescriptor() { return socket_d; }
};


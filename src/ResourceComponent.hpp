#pragma once

#include <map>

struct ResourceComponent {
	int factor;
	std::map<std::string, int> resources {};
	std::map<std::string, bool> infinite {};
};


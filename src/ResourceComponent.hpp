#pragma once

#include <map>

struct ResourceComponent {
	std::map<std::string, int> resources {};
	std::map<std::string, bool> infinite {};
};


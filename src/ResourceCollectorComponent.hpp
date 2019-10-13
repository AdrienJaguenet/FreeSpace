#pragma once

#include <map>

struct ResourceCollectorComponent {
	bool active;
	int factor;
	std::map<std::string, int> reserves;
};


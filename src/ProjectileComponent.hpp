#pragma once

#include "Entity.hpp"

struct ProjectileComponent {
	int damage;
	const Entity *origin;
};


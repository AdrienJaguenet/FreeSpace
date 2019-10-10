#pragma once

#include "Entity.hpp"

class DamageComponent
{
public:
	virtual void OnDamage(Entity& e, int d) {}
};


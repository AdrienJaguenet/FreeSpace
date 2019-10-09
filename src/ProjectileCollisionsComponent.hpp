
#pragma once

#include "CollisionsComponent.hpp"

class ProjectileCollisionsComponent : public CollisionsComponent
{
	int damage;
public:
	ProjectileCollisionsComponent(int damage) : damage(damage) {}
	void OnCollision(Entity& e, Entity& f);
};

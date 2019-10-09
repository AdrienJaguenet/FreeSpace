
#pragma once

#include "CollisionsComponent.hpp"

class ProjectileCollisionsComponent : public CollisionsComponent
{
	int damage;
	Entity* source; /* should not collide with source */
public:
	ProjectileCollisionsComponent(Entity* source, int damage) : source(source), damage(damage) {}
	void OnCollision(Entity& e, Entity& f);
};

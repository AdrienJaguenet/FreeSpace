
#pragma once

#include "CollisionsComponent.hpp"

class ProjectileCollisionsComponent : public CollisionsComponent
{
	Entity* source; /* should not collide with source */
	int damage;
public:
	ProjectileCollisionsComponent(Entity* source, int damage) : source(source), damage(damage) {}
	void OnCollision(Entity& e, Entity& f);
};

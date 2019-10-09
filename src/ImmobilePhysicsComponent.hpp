#pragma once

#include "PhysicsComponent.hpp"

class ImmobilePhysicsComponent : public PhysicsComponent
{
private:
public:
	/* do nothing, literally the trivial component */
	void OnCollision(Entity& a, Entity& b) { };
};


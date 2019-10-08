#pragma once

#include "PhysicsComponent.hpp"

class ImmobilePhysicsComponent : public PhysicsComponent
{
private:
public:
	/* do nothing, literally the trivial component */
	void Update(int dt, Scene& scene, Entity& entity) { }
};


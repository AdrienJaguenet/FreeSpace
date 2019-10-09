#pragma once

#include "Entity.hpp"

class Entity;

class CollisionsComponent
{
public:
	virtual void OnCollision(Entity& e, Entity& f);
};


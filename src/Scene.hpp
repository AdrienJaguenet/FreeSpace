#pragma once

#include <vector>

#include "Entity.hpp"

class Entity;

class Scene
{
private:
	std::vector<Entity> ents;
public:
	/* returns the player's ID (position in the ents list) */
	int SpawnPlayer();
	Entity& GetEntity(int id);
	void Update(int dt);
};


#pragma once

#include <vector>

#include <SFML/Graphics.hpp>

#include "Entity.hpp"

class Entity;

class Scene
{
private:
	std::vector<Entity> ents;
	sf::RenderTarget& window;
public:
	Scene(sf::RenderTarget& window);
	/* returns the player's ID (position in the ents list) */
	int SpawnPlayer();
	Entity& GetEntity(int id)
	{
		return ents[id];
	}
	void Update(int dt);
	void Render();
};


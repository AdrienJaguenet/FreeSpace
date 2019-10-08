#pragma once

#include <vector>

#include <SFML/Graphics.hpp>

#include "Entity.hpp"

class Entity;

class Scene
{
private:
	std::vector<Entity> ents;
	sf::RenderWindow& window;
public:
	Scene(sf::RenderWindow& window);
	/* returns the player's ID (position in the ents list) */
	int SpawnPlayer();
	Entity& GetEntity(int id);
	void Update(int dt);
	void Render();
};


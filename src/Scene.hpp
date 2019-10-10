#pragma once

#include <vector>

#include <SFML/Graphics.hpp>

#include "Camera.hpp"
#include "Entity.hpp"

class Entity;

class Scene
{
private:
	int ent_cnt;
	std::map<std::string, Entity> ents;
	sf::RenderTarget& window;
	std::map<std::string, sf::Texture> textures;
	std::map<std::string, sf::Sprite> sprites;

	sf::Texture LoadTexture(const std::string& path);
public:
	Scene(sf::RenderTarget& window);
	/* returns the player's ID (position in the ents list) */
	Entity* SpawnPlayer();
	void SpawnRock(float x, float y);
	/* spawns a projectile */
	void ShootProjectile(Entity& from);
	/* spawns weedium */
	void SpawnOrangium(float x, float y);
	void Update(int dt);
	void Render(Camera& camera);
	sf::RenderTarget& GetRenderTarget()
	{
		return window;
	}
};


#pragma once

#include <vector>

#include <SFML/Graphics.hpp>

#include "Camera.hpp"
#include "Entity.hpp"

#include "BodyComponent.hpp"
#include "HealthComponent.hpp"
#include "InputComponent.hpp"
#include "GraphicComponent.hpp"

class Entity;

class Scene
{
private:
	int ent_cnt;
	std::map<std::string, Entity> ents;
	sf::RenderTarget& window;
	std::map<std::string, sf::Texture> textures;
	std::map<std::string, sf::Sprite> sprites;

	std::vector<Entity> ents;
	std::vector<std::unique_ptr<BodyComponent>> bodies;
	std::vector<std::unique_ptr<HealthComponent>> healths;
	std::vector<std::unique_ptr<InputComponent>> inputs;
	std::vector<std::unique_ptr<GraphicComponent>> graphics;

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


#include "Scene.hpp"

#include <iostream>

sf::Texture Scene::LoadTexture(const std::string& path)
{
	std::cerr << "Loading '"+path+"'" << std::endl;
	sf::Texture tex;
	if (! tex.loadFromFile(path)) {
		throw std::runtime_error("Could not load texture '"+path+"'");
	}
	return tex;
}

Scene::Scene(sf::RenderTarget& window) :
	ent_id(0),
	ent_count(0),
	max_ents(1000),
	window(window),
	physics(max_ents),
	healths(max_ents),
	inputs(max_ents),
	graphics(max_ents),
	physicsSystem(*this),
	inputSystem(*this)
{
	textures["background1"] = LoadTexture("res/bg1.jpg");
	textures["background1"].setRepeated(true);
	textures["ship_player"] = LoadTexture("res/ship_player.png");
	textures["ship_player_running"] = LoadTexture("res/ship_player_running.png");
	textures["projectile1"] = LoadTexture("res/projectile1.png");
	textures["rock"] = LoadTexture("res/rock.png");
	textures["orangium"] = LoadTexture("res/orangium.png");
	sprites["background1"] = sf::Sprite(textures["background1"]);
	sprites["ship_player"] = sf::Sprite(textures["ship_player"]);
	sprites["ship_player_running"] = sf::Sprite(textures["ship_player_running"]);
	sprites["rock"] = sf::Sprite(textures["rock"]);
	sprites["projectile1"] = sf::Sprite(textures["projectile1"]);
	sprites["orangium"] = sf::Sprite(textures["orangium"]);
}

Entity Scene::NewEntity()
{
  if (ent_count > max_ents) {
	throw std::runtime_error("Trying to instantiate too many entities");
  }
  while (ents.find(ent_id) != ents.end()) {
	++ent_id;
	if (ent_id > max_ents - 1) {
	  ent_id = 0;
	}
  }
  ++ent_count;
  return ents.insert(ent_id).second;
}

Entity Scene::SpawnPlayer()
{
	Entity e = NewEntity();
	physics[e] = std::make_unique<PhysicComponent>();
	return e;
}

void Scene::SpawnRock(float x, float y)
{
}

void Scene::ShootProjectile(Entity& from)
{
}

void Scene::SpawnOrangium(float x, float y)
{
}

void Scene::Render(Camera& camera)
{
	sprites["background1"].setTextureRect(sf::IntRect(camera.x / 5.f, camera.y / 5.f, 1000, 1000));
	window.draw(sprites["background1"]);
}
void Scene::Update(int dt)
{
}


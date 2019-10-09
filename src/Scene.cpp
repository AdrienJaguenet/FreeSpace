#include "Scene.hpp"

#include <iostream>

#include "ImmobilePhysicsComponent.hpp"
#include "LinearPhysicsComponent.hpp"
#include "ShipSpriteGraphicsComponent.hpp"
#include "StaticSpriteGraphicsComponent.hpp"

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
	window(window)
{
	textures["background1"] = LoadTexture("res/bg1.jpg");
	textures["background1"].setRepeated(true);
	textures["ship_player"] = LoadTexture("res/ship_player.png");
	textures["ship_player_running"] = LoadTexture("res/ship_player_running.png");
	textures["rock"] = LoadTexture("res/rock.png");
	sprites["background1"] = sf::Sprite(textures["background1"]);
	sprites["ship_player"] = sf::Sprite(textures["ship_player"]);
	sprites["ship_player_running"] = sf::Sprite(textures["ship_player_running"]);
	sprites["rock"] = sf::Sprite(textures["rock"]);
}

int Scene::SpawnPlayer()
{
	ents.push_back(Entity());
	int ent_id = ents.size() - 1;
	ents[ent_id].SetName("player");
	ents[ent_id].SetPhysicsComponent(std::make_unique<LinearPhysicsComponent>());
	ents[ent_id].SetGraphicsComponent(std::make_unique<ShipSpriteGraphicsComponent>(sprites["ship_player"], sprites["ship_player_running"]));
	return ent_id;
}

void Scene::SpawnRock(float x, float y)
{
	ents.push_back(Entity());
	int ent_id = ents.size() - 1;
	ents[ent_id].SetName("rock");
	ents[ent_id].SetPhysicsComponent(std::make_unique<ImmobilePhysicsComponent>());
	ents[ent_id].SetGraphicsComponent(std::make_unique<StaticSpriteGraphicsComponent>( sprites["rock"]));
	ents[ent_id].GetPhysicsComponent().pos = sf::Vector2f(x, y);
}

void Scene::Render(Camera& camera)
{
	sprites["background1"].setTextureRect(sf::IntRect(0, 0, 1000, 1000));
	sprites["background1"].setPosition(sf::Vector2f(-camera.x / 5.f, -camera.y / 5.f));
	window.draw(sprites["background1"]);
	for (auto & e : ents) {
		e.Render(*this, camera);
	}
}
void Scene::Update(int dt)
{
	for (auto & e : ents) {
		e.Update(*this, dt);
	}
}


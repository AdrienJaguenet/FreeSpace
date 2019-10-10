#include "Scene.hpp"

#include <iostream>

#include "ImmobilePhysicsComponent.hpp"
#include "ProjectilePhysicsComponent.hpp"
#include "LinearPhysicsComponent.hpp"
#include "ShipSpriteGraphicsComponent.hpp"
#include "StaticSpriteGraphicsComponent.hpp"
#include "ProjectileCollisionsComponent.hpp"
#include "DestructibleDamageComponent.hpp"

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
	window(window),
	ent_cnt(0)
{
	textures["background1"] = LoadTexture("res/bg1.jpg");
	textures["background1"].setRepeated(true);
	textures["ship_player"] = LoadTexture("res/ship_player.png");
	textures["ship_player_running"] = LoadTexture("res/ship_player_running.png");
	textures["projectile1"] = LoadTexture("res/projectile1.png");
	textures["rock"] = LoadTexture("res/rock.png");
	sprites["background1"] = sf::Sprite(textures["background1"]);
	sprites["ship_player"] = sf::Sprite(textures["ship_player"]);
	sprites["ship_player_running"] = sf::Sprite(textures["ship_player_running"]);
	sprites["rock"] = sf::Sprite(textures["rock"]);
	sprites["projectile1"] = sf::Sprite(textures["projectile1"]);
}

Entity* Scene::SpawnPlayer()
{
	std::string entName = "player" + std::to_string(ent_cnt);
	ents.insert(std::make_pair(entName, Entity()));
	Entity& e = ents[entName];
	e.SetName(entName);
	e.SetPhysicsComponent(std::make_unique<LinearPhysicsComponent>());
	e.SetGraphicsComponent(std::make_unique<ShipSpriteGraphicsComponent>(sprites["ship_player"], sprites["ship_player_running"]));
	e.SetCollisionsComponent(std::make_unique<CollisionsComponent>());
	e.SetDamageComponent(std::make_unique<DamageComponent>());
	e.GetPhysicsComponent().body.width = 32.f;
	e.GetPhysicsComponent().body.height = 32.f;
	++ ent_cnt;
	return &(ents[entName]);
}

void Scene::SpawnRock(float x, float y)
{
	std::string entName = "rock" + std::to_string(ent_cnt);
	ents.insert(std::make_pair(entName, Entity()));
	Entity& e = ents[entName];
	e.SetName(entName);
	e.SetPhysicsComponent(std::make_unique<ImmobilePhysicsComponent>());
	e.SetGraphicsComponent(std::make_unique<StaticSpriteGraphicsComponent>( sprites["rock"]));
	e.GetPhysicsComponent().pos = sf::Vector2f(x, y);
	e.SetCollisionsComponent(std::make_unique<CollisionsComponent>());
	e.SetDamageComponent(std::make_unique<DestructibleDamageComponent>(1));
	e.GetPhysicsComponent().body.width = 32.f;
	e.GetPhysicsComponent().body.height = 32.f;
	++ ent_cnt;
}

void Scene::ShootProjectile(Entity& from)
{
	std::string entName = "projectile" + std::to_string(ent_cnt);
	ents.insert(std::make_pair(entName, Entity()));
	Entity& e = ents[entName];
	e.SetName(entName);
	e.SetPhysicsComponent(std::make_unique<ProjectilePhysicsComponent>(800));
	e.SetGraphicsComponent(std::make_unique<StaticSpriteGraphicsComponent>( sprites["projectile1"]));
	e.SetCollisionsComponent(std::make_unique<ProjectileCollisionsComponent>(&from, 10));
	e.SetDamageComponent(std::make_unique<DamageComponent>());
	e.GetPhysicsComponent().pos = from.GetPhysicsComponent().pos;
	e.GetPhysicsComponent().yaw = from.GetPhysicsComponent().yaw;
	e.GetPhysicsComponent().frontThrust = 1000.f;
	e.GetPhysicsComponent().body.width = 16.f;
	e.GetPhysicsComponent().body.height = 16.f;
	++ ent_cnt;
}

void Scene::Render(Camera& camera)
{
	sprites["background1"].setTextureRect(sf::IntRect(camera.x / 5.f, camera.y / 5.f, 1000, 1000));
	window.draw(sprites["background1"]);
	for (auto & e : ents) {
		e.second.Render(*this, camera);
	}
}
void Scene::Update(int dt)
{
	for (auto & e : ents) {
		e.second.Update(*this, dt);
	}
	for (auto & e : ents) {
		for (auto & f : ents) {
			if (&e != &f) {
				if (e.second.CollidesWith(f.second)) {
					e.second.OnCollision(f.second);
				}
			}
		}
	}
	auto itr(ents.begin());
	while (itr != ents.end()) {
		Entity& e = itr->second;
		if (e.IsStagedForDestruction()) {
			itr = ents.erase(itr);
		} else {
			++itr;
		}
	}
}


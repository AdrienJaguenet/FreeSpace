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
	resources(max_ents),
	physicsSystem(*this),
	inputSystem(*this)
{
	graphicsSystem.ToggleDebug(true);
	textures["background1"] = LoadTexture("res/bg1.jpg");
	textures["background1"].setRepeated(true);
	textures["ship_player"] = LoadTexture("res/ship_player.png");
	textures["ship_player_running"] = LoadTexture("res/ship_player_running.png");
	textures["projectile1"] = LoadTexture("res/projectile1.png");
	textures["rock"] = LoadTexture("res/rock.png");
	textures["orangium"] = LoadTexture("res/orangium.png");
	textures["greenine"] = LoadTexture("res/greenine.png");
	sprites["background1"] = sf::Sprite(textures["background1"]);
	sprites["ship_player"] = sf::Sprite(textures["ship_player"]);
	sprites["ship_player_running"] = sf::Sprite(textures["ship_player_running"]);
	sprites["rock"] = sf::Sprite(textures["rock"]);
	sprites["projectile1"] = sf::Sprite(textures["projectile1"]);
	sprites["orangium"] = sf::Sprite(textures["orangium"]);
	sprites["greenine"] = sf::Sprite(textures["greenine"]);
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
	return *ents.insert(ent_id).first;
}

Entity Scene::SpawnPlayer()
{
	Entity e = NewEntity();
	physics[e] = std::make_unique<PhysicComponent>();
	graphics[e] = std::make_unique<GraphicComponent>();
	graphics[e]->renderingType = GraphicComponent::RenderingType::RENDERING_SHIP;
	graphics[e]->sprites.push_back(&sprites["ship_player"]);
	graphics[e]->sprites.push_back(&sprites["ship_player_running"]);
	physics[e]->radius = 32.f;
	inputs[e] = std::make_unique<InputComponent>();
	std::cerr << "Created entity " << e << std::endl;
	return e;
}

void Scene::SpawnRock(float x, float y)
{
}

void Scene::SpawnGreenine(float x, float y)
{
	Entity e = NewEntity();
	physics[e] = std::make_unique<PhysicComponent>();
	graphics[e] = std::make_unique<GraphicComponent>();
	resources[e] = std::make_unique<ResourceComponent>();
	graphics[e]->renderingType = GraphicComponent::RenderingType::RENDERING_STATIC;
	graphics[e]->sprites.push_back(&sprites["greenine"]);
	physics[e]->pos.x = x;
	physics[e]->pos.y = y;
	physics[e]->radius = 64.f;
	resources[e]->resources["greenine"] = 9999;
	resources[e]->infinite["greenine"] = true;
}

void Scene::SpawnOrangium(float x, float y)
{
	Entity e = NewEntity();
	physics[e] = std::make_unique<PhysicComponent>();
	graphics[e] = std::make_unique<GraphicComponent>();
	resources[e] = std::make_unique<ResourceComponent>();
	graphics[e]->renderingType = GraphicComponent::RenderingType::RENDERING_STATIC;
	graphics[e]->sprites.push_back(&sprites["orangium"]);
	physics[e]->pos.x = x;
	physics[e]->pos.y = y;
	physics[e]->radius = 64.f;
	resources[e]->resources["orangium"] = 9999;
	resources[e]->infinite["orangium"] = true;
}


void Scene::ShootProjectile(Entity& from)
{
}

void Scene::Render(Camera& camera)
{
	sprites["background1"].setTextureRect(sf::IntRect(camera.x / 5.f, camera.y / 5.f, 1000, 1000));
	window.draw(sprites["background1"]);
	graphicsSystem.Render(camera, *this);
}
void Scene::Update(int dt)
{
	physicsSystem.Update(dt);
	for (auto& e : ents) {
		bool collides(false);
		for (auto& f : ents) {
			if (&e != &f) {
				if (physics[e] && physics[f]) {
					auto distvec = physics[e]->pos - physics[f]->pos;
					float sqdist = (distvec.x * distvec.x) + (distvec.y * distvec.y);
					float radiusSum = physics[e]->radius + physics[f]->radius;
					if (sqdist <= (radiusSum) * (radiusSum)) {
						/* trigger collision */
						/* for debug purposes */
						collides = true;
					}
				}
			}
		}
		physics[e]->isColliding = collides;
	}
}


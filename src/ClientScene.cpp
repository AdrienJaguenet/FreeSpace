#include "ClientScene.hpp"

#include <iostream>

sf::Texture ClientScene::LoadTexture(const std::string& path)
{
	std::cerr << "Loading '"+path+"'" << std::endl;
	sf::Texture tex;
	if (! tex.loadFromFile(path)) {
		throw std::runtime_error("Could not load texture '"+path+"'");
	}
	return tex;
}

ClientScene::ClientScene(sf::RenderTarget& window) :
	window(window),
	inputs(max_ents),
	graphics(max_ents),
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
	textures["monster_pirate"] = LoadTexture("res/monster_pirate.png");
	textures["monster_pirate_thrusting"] = LoadTexture("res/monster_pirate_thrusting.png");
	textures["laser_red"] = LoadTexture("res/laser_red.png");
	sprites["background1"] = sf::Sprite(textures["background1"]);
	sprites["ship_player"] = sf::Sprite(textures["ship_player"]);
	sprites["ship_player_running"] = sf::Sprite(textures["ship_player_running"]);
	sprites["rock"] = sf::Sprite(textures["rock"]);
	sprites["projectile1"] = sf::Sprite(textures["projectile1"]);
	sprites["orangium"] = sf::Sprite(textures["orangium"]);
	sprites["greenine"] = sf::Sprite(textures["greenine"]);
	sprites["monster_pirate"] = sf::Sprite(textures["monster_pirate"]);
	sprites["monster_pirate_thrusting"] = sf::Sprite(textures["monster_pirate_thrusting"]);
	sprites["laser_red"] = sf::Sprite(textures["laser_red"]);
}

Entity ClientScene::SpawnPlayer()
{
	Entity e = NewEntity();
	graphics[e] = std::make_unique<GraphicComponent>();
	teams[e] = std::make_unique<TeamComponent>();
	healths[e] = std::make_unique<HealthComponent>();
	weapons[e] = std::make_unique<WeaponComponent>();
	inputs[e] = std::make_unique<InputComponent>();
	graphics[e]->renderingType = GraphicComponent::RenderingType::RENDERING_SHIP;
	graphics[e]->sprites.push_back(&sprites["ship_player"]);
	graphics[e]->sprites.push_back(&sprites["ship_player_running"]);
	physics[e]->radius = 32.f;
	teams[e]->id = 0;
	healths[e]->hp = 50;
	healths[e]->maxHp = 50;
	inputs[e] = std::make_unique<InputComponent>();
	weapons[e] = std::make_unique<WeaponComponent>();
	std::cerr << "Created entity " << e << std::endl;
	return e;
}

void ClientScene::SpawnGreenine(float x, float y)
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
	resources[e]->factor = 1;
}

void ClientScene::SpawnOrangium(float x, float y)
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
	resources[e]->factor = 1;
}

void ClientScene::SpawnPirate(float x, float y)
{
	Entity e = NewEntity();
	physics[e] = std::make_unique<PhysicComponent>();
	graphics[e] = std::make_unique<GraphicComponent>();
	teams[e] = std::make_unique<TeamComponent>();
	healths[e] = std::make_unique<HealthComponent>();
	weapons[e] = std::make_unique<WeaponComponent>();
	graphics[e]->renderingType = GraphicComponent::RenderingType::RENDERING_SHIP;
	graphics[e]->sprites.push_back(&sprites["monster_pirate"]);
	graphics[e]->sprites.push_back(&sprites["monster_pirate_thrusting"]);
	physics[e]->pos.x = x;
	physics[e]->pos.y = y;
	physics[e]->radius = 32.f;
	teams[e]->id = 1;
	healths[e]->hp = 25;
	healths[e]->maxHp = 25;
	weapons[e]->cooldown = 1.f;
	weapons[e]->current_cooldown = 0.f;
}

void ClientScene::FireWeapon(const Entity& e)
{
	/* send message to server */
}

void ClientScene::SpawnProjectile(float x, float y, float yaw, float speed)
{
	Entity e = NewEntity();
	physics[e] = std::make_unique<PhysicComponent>();
	graphics[e] = std::make_unique<GraphicComponent>();
	graphics[e]->renderingType = GraphicComponent::RenderingType::RENDERING_STATIC;
	graphics[e]->sprites.push_back(&sprites["laser_red"]);
	physics[e]->pos.x = x;
	physics[e]->pos.y = y;
	physics[e]->yaw = yaw;
	physics[e]->speed = speed;
}

void ClientScene::Render(Camera& camera)
{
	sprites["background1"].setTextureRect(sf::IntRect(camera.x / 5.f, camera.y / 5.f, 1000, 1000));
	window.draw(sprites["background1"]);
	graphicsSystem.Render(camera, *this);
}
void ClientScene::Update(int dt)
{
	physicsSystem.Update(dt);
	for (auto& e : toDelete) {
		ents.erase(e);
		physics[e] = nullptr;
		graphics[e] = nullptr;
		healths[e] = nullptr;
		resources[e] = nullptr;
		weapons[e] = nullptr;
	}
	toDelete.clear();
}


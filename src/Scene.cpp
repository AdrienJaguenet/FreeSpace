#include "Scene.hpp"

#include "LinearPhysicsComponent.hpp"
#include "StaticSpriteGraphicsComponent.hpp"

sf::Texture Scene::LoadTexture(const std::string& path)
{
	sf::Texture tex;
	if (! tex.loadFromFile(path)) {
		throw std::runtime_error("Could not load texture '"+path+"'");
	}
	return tex;
}

Scene::Scene(sf::RenderTarget& window) :
	window(window)
{
	textures["ship_player"] = LoadTexture("res/ship_player.png");
	sprites["ship_player"] = sf::Sprite(textures["ship_player"]);
}

int Scene::SpawnPlayer()
{
	ents.push_back(Entity());
	int ent_id = ents.size() - 1;
	ents[ent_id].SetName("player");
	ents[ent_id].SetPhysicsComponent(std::make_unique<LinearPhysicsComponent>());
	ents[ent_id].SetGraphicsComponent(std::make_unique<StaticSpriteGraphicsComponent>(sprites["ship_player"]));
	return ent_id;
}

void Scene::Render(Camera& camera)
{
	for (auto & e : ents) {
		e.Render(*this, camera);
	}
}

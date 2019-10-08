#include "Scene.hpp"

#include "LinearPhysicsComponent.hpp"
#include "InvisibleGraphicsComponent.hpp"

Scene::Scene(sf::RenderWindow& window) :
	window(window)
{

}

int Scene::SpawnPlayer()
{
	ents.push_back(Entity());
	int ent_id = ents.size() - 1;
	ents[ent_id].SetName("player");
	ents[ent_id].SetPhysicsComponent(std::make_unique<LinearPhysicsComponent>());
	ents[ent_id].SetGraphicsComponent(std::make_unique<InvisibleGraphicsComponent>());
	return ent_id;
}

void Scene::Render()
{
	for (auto & e : ents) {
		e.Render(*this);
	}
}

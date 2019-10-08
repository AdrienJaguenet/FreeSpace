#include "Scene.hpp"

#include "LinearPhysicsComponent.hpp"

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
	return ent_id;
}

void Scene::Render()
{
	for (auto & e : ents) {
		e.Render(*this);
	}
}

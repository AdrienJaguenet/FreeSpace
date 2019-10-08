#include "Scene.hpp"

#include "LinearPhysicsComponent.hpp"

int Scene::SpawnPlayer()
{
	ents.push_back(Entity());
	int ent_id = ents.size() - 1;
	ents[ent_id].SetName("player");
	ents[ent_id].SetPhysicsComponent(std::make_unique<LinearPhysicsComponent>());
	return ent_id;
}


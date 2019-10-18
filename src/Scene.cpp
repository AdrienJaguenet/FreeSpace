#include "Scene.hpp"

Scene::Scene() :
	ent_id(0),
	ent_count(0),
	max_ents(1000),
	physics(max_ents),
	healths(max_ents),
	resources(max_ents),
	teams(max_ents),
	weapons(max_ents),
	collectors(max_ents),
	physicsSystem(*this)
{

}

Entity Scene::NewEntity()
{
	if (ent_count > max_ents) {
		throw std::runtime_error("Trying to instantiate too many entities");
	}
	while (entities.find(ent_id) != entities.end()) {
		++ent_id;
		if (ent_id > max_ents - 1) {
			ent_id = 0;
		}
	}
	++ent_count;
	return *entities.insert(ent_id).first;
}

void Scene::KillEntity(const Entity& e)
{
	toDelete.push_back(e);
}


#include "ResourceCollectSystem.hpp"
#include "Entity.hpp"
#include "Scene.hpp"

void ResourceCollectSystem::OnCollide(Entity& e, Entity& f)
{
	if (sc.GetResourceCollectorComponent(e) and sc.GetResourceComponent(f)) {
		auto& collector = *sc.GetResourceCollectorComponent(e);
		auto& source = *sc.GetResourceComponent(f);
		for (auto& resource : source.resources) {
			if (collector.reserves.find(resource.first) != std::end(collector.reserves)) {
				collector.reserves[resource.first] += collector.factor * source.factor;
			}
		}
	}
}

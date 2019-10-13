#pragma once

#include "Entity.hpp"

class Scene;

class ResourceCollectSystem
{
private:
	Scene& sc;
public:
	ResourceCollectSystem(Scene& sc) : sc(sc) {}
	/* entity e collects from f */
	void OnCollide(Entity& e, Entity& f);
};


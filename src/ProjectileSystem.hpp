#pragma once

#include "Entity.hpp"

class Scene;

class ProjectileSystem
{
private:
	Scene& sc;
public:
	ProjectileSystem(Scene& sc) : sc(sc) {}
	void OnCollide(Entity& e, Entity&f);
};


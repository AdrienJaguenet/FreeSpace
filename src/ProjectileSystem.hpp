#pragma once

#include "Entity.hpp"

class ServerScene;

class ProjectileSystem
{
private:
	ServerScene& sc;
public:
	ProjectileSystem(ServerScene& sc) : sc(sc) {}
	void OnCollide(Entity& e, Entity&f);
};


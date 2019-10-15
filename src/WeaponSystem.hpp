#pragma once

#include "Entity.hpp"

class Scene;

class WeaponSystem
{
	Scene& sc;
public:
	WeaponSystem(Scene& sc) : sc(sc) {}
	void Update(int dt);
	void FireWeapon(const Entity& e);
};


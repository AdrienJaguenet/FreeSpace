#pragma once

#include "Entity.hpp"

class ServerScene;

class WeaponSystem
{
	ServerScene& sc;
public:
	WeaponSystem(ServerScene& sc) : sc(sc) {}
	void Update(int dt);
	void FireWeapon(const Entity& e);
};


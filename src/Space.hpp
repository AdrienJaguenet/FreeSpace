#pragma once

#include "Scene.hpp"

class Scene;

class Space
{
private:
	Scene scene;
	int refreshPeriod = 25;
	int player_id;
public:
	int GetRefreshPeriod()
	{
		return refreshPeriod;
	}
	void Update();
	void Render(int offx, int offy);
	void Load();
};


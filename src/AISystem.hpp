#pragma once

class Scene;

class AISystem
{
private:
	Scene& sc;
public:
	AISystem(Scene& sc) : sc(sc) {}
	void Update(int dt);
};


#pragma once

class Scene;

class PhysicsSystem
{
	Scene& scene;
public:
	PhysicsSystem(Scene& sc) : scene(sc) {}
	void Update(int dt);
};


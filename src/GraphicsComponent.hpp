#pragma once

#include "Scene.hpp"

class Entity;
class Scene;

class GraphicsComponent
{
private:
public:
	virtual void Render(Entity& e, Scene& sc, Camera& c) = 0;
};


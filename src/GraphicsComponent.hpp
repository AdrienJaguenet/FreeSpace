#pragma once

#include "Scene.hpp"

class GraphicsComponent
{
  private:
  public:
	virtual void Render(Entity& e, Scene& sc) = 0;
};


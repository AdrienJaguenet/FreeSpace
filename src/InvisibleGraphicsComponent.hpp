#pragma once

#include "GraphicsComponent.hpp"

class InvisibleGraphicsComponent : public GraphicsComponent
{
  private:
  public:
	/* Do nothing, the trivial graphics component */
	void Render(Entity& e, Scene& sc) { }
};


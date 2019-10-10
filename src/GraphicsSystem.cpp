#include "GraphicsSystem.hpp"

#include <cmath>

#include "Camera.hpp"
#include "Scene.hpp"

void Render(Camera& c, Scene& sc)
{
  for (auto& e : sc.GetEntities()) {
	if (sc.GetGraphicsComponent(e) && sc.GetPhysicsComponent(e)) {
	  auto& gc = *sc.GetGraphicsComponent(e);
	  auto& pc = *sc.GetPhysicsComponent(e);
	  sf::Sprite& sprite = *(gc.sprites[0]);
	  sprite.setOrigin(sprite.getLocalBounds().width / 2.f, sprite.getLocalBounds().height / 2.f);
	  sprite.setRotation(pc.yaw * 180.f / M_PI);
	  sprite.setPosition(pc.pos.x - c.x, pc.pos.y - c.y);
	  sprite.setScale(sf::Vector2f(c.scale, c.scale));
	  sc.GetRenderTarget().draw(sprite);
	}
  }
}

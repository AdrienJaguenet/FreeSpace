#include "StaticSpriteGraphicsComponent.hpp"

StaticSpriteGraphicsComponent::StaticSpriteGraphicsComponent(sf::Sprite& sprite) :
	sprite(&sprite)
{

}

void StaticSpriteGraphicsComponent::Render(Entity& e, Scene& sc, Camera& c)
{
	sprite->setPosition(e.GetPhysicsComponent().pos.x + c.x, e.GetPhysicsComponent().pos.y + c.y);
	sprite->setScale(sf::Vector2f(c.scale, c.scale));
	sc.GetRenderTarget().draw(*sprite);
}

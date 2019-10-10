#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

struct GraphicComponent {
	enum RenderingType {
		RENDERING_STATIC, RENDERING_SHIP
	} renderingType {};
	std::vector<sf::Sprite*> sprites {};
};


#pragma once

#include <SFML/Graphics.hpp>
#include "SimplePendulum.h"

struct GraphicalPendulum {
	sf::Vector2f position;
	SimplePendulum* pendulum;

	float radius{ 75 };
	float rodThickness{ 10 };
	float ppm{};

	const sf::Color bobColor{ 31, 64, 69 };
	const sf::Color rodColor{ 127, 149, 147 };

	sf::CircleShape bob;
	sf::RectangleShape rod;

	GraphicalPendulum(sf::Vector2f position, float ppm, SimplePendulum* pendulum);
	void draw(sf::RenderWindow& window);
};
#pragma once

#include <SFML/Graphics.hpp>
#include "DoublePendulum.h"
#include <vector>

struct GraphicalDoublePendulum {
	static constexpr int trail_count{ 10000 };

	sf::Vector2f position;
	DoublePendulum* pendulum;

	float radius{ 40 };
	float rodThickness{ 10 };
	float ppm{};

	const sf::Color bobColor{ 31, 64, 69 };
	const sf::Color rodColor{ 127, 149, 147 };
	const sf::Color trailColor{ 31, 47, 49 };

	sf::CircleShape bob1;
	sf::CircleShape bob2;
	sf::RectangleShape rod1;
	sf::RectangleShape rod2;

	std::vector<sf::Vertex> trailPoints1;
	std::vector<sf::Vertex> trailPoints2;

	GraphicalDoublePendulum(sf::Vector2f position, float ppm, DoublePendulum* pendulum);
	void draw(sf::RenderWindow& window);
	void drawTrail(sf::RenderWindow& window);
};
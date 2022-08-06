#include "GraphicalDoublePendulum.h"
#include "DoublePendulum.h"

const float PI{ static_cast<float>(std::atan(1)) * 4 };

GraphicalDoublePendulum::GraphicalDoublePendulum(sf::Vector2f position, float ppm, DoublePendulum* pendulum) : position(position), ppm(ppm), pendulum(pendulum), bob1(radius), bob2(radius), rod1(sf::Vector2f(pendulum->length_1* ppm, rodThickness)), rod2(sf::Vector2f(pendulum->length_2* ppm, rodThickness))
{
	bob1.setFillColor(bobColor);
	bob2.setFillColor(bobColor);
	rod1.setFillColor(rodColor);
	rod2.setFillColor(rodColor);

	bob1.setOrigin(radius, radius);
	bob2.setOrigin(radius, radius);
	rod1.setOrigin(0, rodThickness / 2);
	rod1.setPosition(position);
	
	rod2.setOrigin(0, rodThickness / 2);
	rod2.setPosition(pendulum->getRelativeCoordinatesM1(position / ppm)* ppm);
}

void GraphicalDoublePendulum::draw(sf::RenderWindow& window) {
	sf::Vector2f bob1pos{ pendulum->getRelativeCoordinatesM1(position / ppm) * ppm };
	sf::Vector2f bob2pos{ pendulum->getRelativeCoordinatesM2(position / ppm) * ppm };
	bob1.setPosition(bob1pos);
	bob2.setPosition(bob2pos);

	rod1.setRotation(-(pendulum->theta_1 / PI) * 180 + 90);
	rod2.setPosition(bob1pos);
	rod2.setRotation(-(pendulum->theta_2 / PI) * 180 + 90);

	trailPoints1.push_back(sf::Vertex(bob1pos, trailColor));
	trailPoints2.push_back(sf::Vertex(bob2pos, trailColor));

	if (trailPoints1.size() > trail_count) {
		trailPoints1.erase(trailPoints1.begin());
	}

	if (trailPoints2.size() > trail_count) {
		trailPoints2.erase(trailPoints2.begin());
	}

	drawTrail(window);

	window.draw(rod1);
	window.draw(rod2);

	window.draw(bob1);
	window.draw(bob2);
}

void GraphicalDoublePendulum::drawTrail(sf::RenderWindow & window) {
	window.draw(&trailPoints1[0], trailPoints1.size(), sf::LineStrip);
	window.draw(&trailPoints2[0], trailPoints2.size(), sf::LineStrip);
}
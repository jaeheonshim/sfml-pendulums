#include "GraphicalPendulum.h"
#include "SimplePendulum.h"

const float PI{ static_cast<float>(std::atan(1)) * 4 };

GraphicalPendulum::GraphicalPendulum(sf::Vector2f position, float ppm, SimplePendulum* pendulum) : position(position), ppm(ppm), pendulum(pendulum), bob(radius), rod(sf::Vector2f(pendulum->length * ppm, rodThickness))
{
	bob.setFillColor(bobColor);
	rod.setFillColor(rodColor);

	bob.setOrigin(radius, radius);
	rod.setOrigin(0, rodThickness / 2);
	rod.setPosition(position);
}

void GraphicalPendulum::draw(sf::RenderWindow& window) {
	bob.setPosition(pendulum->getRelativeCoordinates(position / ppm) * ppm);
	rod.setRotation(-(pendulum->theta / PI) * 180 + 90);
	window.draw(rod);
	window.draw(bob);
}

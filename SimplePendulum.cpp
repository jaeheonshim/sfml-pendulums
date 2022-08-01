#include "SimplePendulum.h"
#include <cmath>
#include "SFML/Graphics.hpp"

float SimplePendulum::getTorque() {
    float sine{ static_cast<float>(std::sin(theta)) };
    return -gravity * sine / length;
}

void SimplePendulum::step(float dt) {
    omega += getTorque() * dt;
    theta += omega * dt;
}

sf::Vector2f SimplePendulum::getRelativeCoordinates(sf::Vector2f origin) {
    return sf::Vector2f(origin.x + static_cast<float>(std::sin(theta)) * length, origin.y + static_cast<float>(std::cos(theta)) * length);
}
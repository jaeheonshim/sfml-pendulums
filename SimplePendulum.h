#pragma once

#include "SFML/Graphics.hpp"

struct SimplePendulum {
    float theta{ 0 };
    float mass{ 1 };
    float length{ 2 };
    float gravity{ 9.8 };

    float omega{ 0 };

    void step(float dt);
    float getTorque();
    sf::Vector2f getRelativeCoordinates(sf::Vector2f origin);
};
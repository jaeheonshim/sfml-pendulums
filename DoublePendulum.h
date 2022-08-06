#pragma once

#include <SFML/Graphics.hpp>

struct DoublePendulum {
    float theta_1{ 0 };
    float theta_2{ 0 };

    float mass_1{ 1 };
    float mass_2{ 1 };

    float length_1{ 1 };
    float length_2{ 1 };

    float gravity{ 9.8 };

    float omega_1{ 0 };
    float omega_2{ 0 };

    void step(float dt);
    sf::Vector2f getRelativeCoordinatesM1(sf::Vector2f origin);
    sf::Vector2f getRelativeCoordinatesM2(sf::Vector2f origin);
};
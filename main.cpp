#include <iostream>
#include <algorithm>
#include <cmath>
#include <SFML/Graphics.hpp>
#include "SimplePendulum.h"
#include "GraphicalPendulum.h"

const sf::Color backgroundColor(234, 230, 227);
const sf::Color massColor(31, 64, 69);
const sf::Color rodColor(127, 149, 147);

const float PI{ static_cast<float>(std::atan(1)) * 4 };

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!");

    float ppm{ 400 };
    sf::Vector2f origin(960, 100);

    SimplePendulum pendulum{ 3.14 / 2 };
    GraphicalPendulum graphicalPendulum(origin, ppm, &pendulum);

    sf::Clock deltaClock;

    while (window.isOpen())
    {
        float dt{ std::min(deltaClock.restart().asSeconds(), 1/15.f) };

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        pendulum.step(dt);

        window.clear(backgroundColor);
        graphicalPendulum.draw(window);
        window.display();
    }

    return 0;
}
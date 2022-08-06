#include <iostream>
#include <algorithm>
#include <cmath>
#include <SFML/Graphics.hpp>
#include "SimplePendulum.h"
#include "DoublePendulum.h"
#include "GraphicalPendulum.h"
#include "GraphicalDoublePendulum.h"

const sf::Color backgroundColor(234, 230, 227);

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Pendulums");

    float ppm{ 400 };
    sf::Vector2f origin(960, 200);

    DoublePendulum pendulum{ -3.14 / 4, 3.14 };
    GraphicalDoublePendulum graphicalPendulum(origin, ppm, &pendulum);

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
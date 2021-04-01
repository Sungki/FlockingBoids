#pragma once
#include <iostream>
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "Boid.h"

class Game
{
private:
    sf::RenderWindow window;
    int window_width;
    int window_height;

    std::vector<sf::CircleShape> shapes;
    std::vector<Boid> flock;

    void Render();
    void HandleInput();

public:
    Game();
    void Run();
};


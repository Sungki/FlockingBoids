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
    void Edges(Boid& b);

    void Align(std::vector<Boid> boids, Boid& b);
    void Cohesion(std::vector<Boid> boids, Boid& b);

public:
    Game();
    void Run();
};


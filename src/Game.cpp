#include "Game.h"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

Game::Game()
{
    window_height = 768;
    window_width = 1024;
    window.create(sf::VideoMode(window_width, window_height, 32), "FlockingSimulation");
}

void Game::Run()
{
    for (int i = 0; i < 250; i++) {
        Boid b(rand()% window_width, rand() % window_height);
        sf::CircleShape shape(8, 3);

        shape.setPosition(window_width/2, window_height/2);
        shape.setOutlineColor(sf::Color(0, 255, 0));
        shape.setFillColor(sf::Color::Green);
        shape.setOutlineColor(sf::Color::White);
        shape.setOutlineThickness(1);
        shape.setRadius(3);

        flock.push_back(b);
        shapes.push_back(shape);
    }

    while (window.isOpen()) {
        HandleInput();
        Render();
    }
}

void Game::HandleInput()
{
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) window.close();
    }
}

void Game::Render()
{
    window.clear();

    for (int i = 0; i < shapes.size(); i++) 
    {
        Separation(flock, flock[i]);
        Align(flock, flock[i]);
        Cohesion(flock, flock[i]);

        flock[i].Update();

        Edges(flock[i]);
        shapes[i].setPosition(flock[i].position.x, flock[i].position.y);
        window.draw(shapes[i]);
    }

    window.display();
}

void Game::Edges(Boid& b)
{
    if (b.position.x > window_width) b.position.x = 0;
    else if (b.position.x < 0) b.position.x = window_width;
    if (b.position.y > window_height) b.position.y = 0;
    else if (b.position.y < 0) b.position.y = window_height;
}

void Game::Align(std::vector<Boid> boids, Boid& b)
{
    Vector steering;
    int total = 0;

    for (auto s : boids)
    {
        if (&s != &b && b.position.distance(s.position) < 50)
        {
            steering.addVector(s.velocity);
            total++;
        }
    }
    if (total > 0)
    {
        steering.divScalar((float)total);
        steering.subVector(b.velocity);
        steering.limit(0.3);
    }

    b.acceleration.addVector(steering);
}

void Game::Cohesion(std::vector<Boid> boids, Boid& b)
{
    Vector steering;
    int total = 0;

    for (auto s : boids)
    {
        if (&s != &b && b.position.distance(s.position) < 100)
        {
            steering.addVector(s.position);
            total++;
        }
    }
    if (total > 0)
    {
        steering.divScalar((float)total);
        steering.subVector(b.position);
        steering.subVector(b.velocity);
        steering.limit(0.1);
    }

    b.acceleration.addVector(steering);
}

void Game::Separation(std::vector<Boid> boids, Boid& b)
{
    Vector steering;
    int total = 0;

    for (auto s : boids)
    {
        float d = b.position.distance(s.position);
        if (&s != &b && d < 30)
        {
            Vector diff;
            diff = diff.subTwoVector(b.position, s.position);
            diff.divScalar(d);
            steering.addVector(diff);
            total++;
        }
    }
    if (total > 0)
    {
        steering.divScalar((float)total);
//        steering.subVector(b.velocity);
//        steering.limit(0.1);

        steering.mulScalar(3);
    }

    b.acceleration.addVector(steering);
}
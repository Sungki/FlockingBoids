#include "Game.h"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

Game::Game()
{
    this->window_height = 768;
    this->window_width = 1024;
    this->window.create(sf::VideoMode(window_width, window_height, 32), "FlockingSimulation");
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
        flock[i].Flock(flock);
        flock[i].Update();

        shapes[i].setPosition(flock[i].position.x, flock[i].position.y);

        window.draw(shapes[i]);
    }


    window.display();
}
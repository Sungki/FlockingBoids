#include <iostream>
#include "Boid.h"

Boid::Boid(float x, float y)
{
    acceleration = Vector(0, 0);
    velocity = Vector(rand() % 10 - 5, rand() % 10 - 5);
    velocity.setMagnitude(((rand() % 5)/10) - 0.9);
    position = Vector(x,y);
}

void Boid::Update()
{
//    acceleration.mulScalar(.4);
    velocity.addVector(acceleration);
    velocity.limit(3.5);
    position.addVector(velocity);
//    acceleration.mulScalar(0);
}

Vector Boid::Align(std::vector<Boid> boids)
{
    Vector steering;
    int total = 0;

    for (auto other : boids)
    {
        if (&other != this && position.distance(other.position) < 50)
        {
            steering.addVector(other.velocity);
            total++;
        }
    }
    if (total > 0)
    {
        steering.divScalar((float)total);
        steering.subVector(velocity);
        steering.limit(0.5);
    }

    return steering;
}

void Boid::Flock(std::vector<Boid> boids)
{
    Vector alignment = Align(boids);
    acceleration = alignment;
}

void Boid::Edges(int w, int h)
{
    if (position.x > w) position.x = 0;
    else if (position.x < 0) position.x = w;
    if (position.y > h) position.y = 0;
    else if (position.y < 0) position.y = h;
}
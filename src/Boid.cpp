#include <iostream>
#include "Boid.h"

Boid::Boid(float x, float y)
{
    acceleration = Vector(1, 1);
    velocity = Vector(rand() % 3 - 2, rand() % 3 - 2);
    position = Vector(x,y);
}

void Boid::Update()
{
    velocity.addVector(acceleration);
    velocity.limit(6);
    position.addVector(velocity);
    acceleration.mulScalar(0);
}
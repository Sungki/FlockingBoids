#include <iostream>
#include "Boid.h"

Boid::Boid(float x, float y)
{
    acceleration = Vector(0, 0);
    velocity = Vector(rand() % 10 - 5, rand() % 10 - 5);
    velocity.setMagnitude(((rand() % 5)/10) - 0.05);
    position = Vector(x,y);
}

void Boid::Update()
{
//    acceleration.mulScalar(.4);
//    velocity.addVector(acceleration);
//    velocity.limit(3.5);
    position.addVector(velocity);
//    acceleration.mulScalar(0);
}

void Boid::Align()
{

}
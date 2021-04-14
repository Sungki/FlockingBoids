#include "Flock.h"
#include "Boid.h"

int Flock::getSize()
{
    return flock.size();
}

Boid Flock::getBoid(int i)
{
    return flock[i];
}

void Flock::addBoid(Boid b)
{
    flock.push_back(b);
}

void Flock::flocking()
{
//    for (int i = 0; i < flock.size(); i++)
//        flock[i].run(flock);
}
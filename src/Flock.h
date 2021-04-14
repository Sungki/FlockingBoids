#pragma once

#include <iostream>
#include <vector>
#include "Boid.h"

class Flock
{
public:
    std::vector<Boid> flock;
    Flock() {}
    int getSize();
    Boid getBoid(int i);
    void addBoid(Boid b);
    void flocking();
};


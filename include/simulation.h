#pragma once

#include "world.h"
#include "agent.h"
struct Simulation
{
    Agent agent;
    int target_index;
    int speed;
    Location location;
};

void init_simulation(Simulation& sim);
void update_simulation(Simulation& sim, World& world);
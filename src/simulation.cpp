#include "../include/simulation.h"
#include <cmath>

void init_simulation(Simulation& sim)
{
    sim.target_index = 0;
    sim.speed = 4;
}

void update_simulation(Simulation& sim, World& world)
{
    Location target = world.locations[sim.target_index];

    if (sim.location.x    < target.x) sim.location.x += sim.speed;
    if (sim.location.x > target.x) sim.location.x -= sim.speed;

    if (sim.location.y < target.y) sim.location.y += sim.speed;
    if (sim.location.y > target.y) sim.location.y -= sim.speed;

    if (abs(sim.location.x - target.x) < 4 &&
        abs(sim.location.y - target.y) < 4)
    {
        sim.location.location_name = target.location_name;

        sim.target_index++;

        if (sim.target_index >= world.locations.size())
            sim.target_index = 0;
    }
}
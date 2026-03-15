#include "../include/world.h"

World create_world()
{
    World world;

    world.width = 800;
    world.height = 600;

    world.locations.push_back({"home",300,300});
    world.locations.push_back({"coffee",600,350});
    world.locations.push_back({"shopmark",800,600});
    world.locations.push_back({"park",400,600});

    return world;
}
#pragma once

#include <vector>
#include "location.h"

struct World
{
    int width;
    int height;

    std::vector<Location> locations;
};

World create_world();
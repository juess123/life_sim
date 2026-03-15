#pragma once
#include <string>

struct Location
{
    std::string location_name;
    int x;
    int y;
};
Location init_location(void);
#include "../include/world_time.h"
#include <iostream>

SimTime init_time()
{
    SimTime t;
    t.month = 1;
    t.day = 1;
    t.hour = 1;

    return t;
}

void advance_time(SimTime& t)
{
    t.hour++;

    if (t.hour >= 24)
    {
        t.hour = 0;
        t.day++;
        if (t.day > 28)
        {
            t.month++;
        }
    }
}



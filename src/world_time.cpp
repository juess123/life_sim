#include "../include/world_time.h"
void advance_time(SimTime& t)
{
    t.hour++;

    if (t.hour >= 24)
    {
        t.hour = 0;
        t.day++;
        t.week_day++;

        if (t.week_day > 7)
            t.week_day = 1;

        if (t.day > 28)
        {
            t.day = 1;
            t.month++;
        }
    }
}

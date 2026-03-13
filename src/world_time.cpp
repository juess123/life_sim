#include "../include/world_time.h"
#include <iostream>

SimTime init_time()
{
    SimTime t;

    t.month = 1;
    t.day = 1;
    t.week_day = 1;
    t.hour = 8;

    return t;
}

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

bool is_weekend(const SimTime& t)
{
    return (t.week_day == 6 || t.week_day == 7);
}

void print_time(const SimTime& t)
{
    std::cout << "Month: " << t.month
              << " Day: " << t.day
              << " WeekDay: " << t.week_day
              << " Hour: " << t.hour
              << std::endl;
}
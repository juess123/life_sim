#include <iostream>
#include "../include/world_time.h"
#include "../include/agent.h"
int main()
{
    Agent agent = init_agent();

    SimTime time;

    time.month = 1;
    time.day = 1;
    time.week_day = 1;
    time.hour = 8;

    for(int i = 0; i < 100; i++)
    {
        std::cout << "Month: " << time.month
                  << " Day: " << time.day
                  << " WeekDay: " << time.week_day
                  << " Hour: " << time.hour
                  << std::endl;

        advance_time(time);
    }

    return 0;
}
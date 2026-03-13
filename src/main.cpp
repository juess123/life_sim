#include <iostream>
#include "../include/world_time.h"
#include "../include/agent.h"
#include "../include/actions.h"
#include "../include/simulation.h"
int main()
{
    Agent agent = init_agent();

    SimTime time = init_time();

    for(int step = 0; step < 10; step++)
    {
        Action act = decide_action(agent,time);

        save_dataset(agent,time,act);

        perform_action(agent,act);

        advance_time(time);
    }

    std::cout<<"dataset generated"<<std::endl;

    return 0;
}
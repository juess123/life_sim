#ifndef SIMULATION_H
#define SIMULATION_H

#include "agent.h"
#include "world_time.h"
#include "actions.h"

Action decide_action(const Agent& a,const SimTime& t);

void save_dataset(const Agent& a,const SimTime& t,Action act);

void run_simulation(Agent& agent,SimTime& time,int steps);

#endif
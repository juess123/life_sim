#ifndef ACTIVATE_H
#define ACTIVATE_H
#include "../include/agent.h"
#include "../include/world_time.h"
enum class Action
{
    Eat,
    Sleep,
    Social,
    Work,
    Func,
    No
};
std::string action_to_string(Action a);

void perform_action(Agent& a, Action act);

Action decide_action(const Agent& a, const SimTime& t);

#endif
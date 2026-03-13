#ifndef ACTIVATE_H
#define ACTIVATE_H
#include "../include/agent.h"
enum class Action
{
    Eat,
    Work,
    Sleep,
    Social,
    Relax
};
void do_daily_life(Agent& a);
#endif
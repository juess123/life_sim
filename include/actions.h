#ifndef ACTIVATE_H
#define ACTIVATE_H
#include "../include/agent.h"
enum class Action
{
    Eat,
    Sleep,
    Work,
    StayHome,
    Travel
};
std::string action_to_string(Action a)
{
    switch(a)
    {
        case Action::Eat: return "Eat";
        case Action::Sleep: return "Sleep";
        case Action::Work: return "Work";
        case Action::StayHome: return "StayHome";
        case Action::Travel: return "Travel";
    }
    return "Unknown";
}
Action decide_action(const Agent& a,const SimTime& t)
{
    if(a.needs.basic.hunger > 70)
        return Action::Eat;

    if(a.needs.basic.rest > 80)
        return Action::Sleep;

    if(a.emotion.stress > 80 && a.resources.money > 500)
        return Action::Travel;

    if(!is_weekend(t) && t.hour >= 9 && t.hour <= 18)
        return Action::Work;

    return Action::StayHome;
}

#endif
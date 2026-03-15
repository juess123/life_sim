#include "../include/actions.h"
#include "../include/utils.h"
#include "../include/status.h"

std::string action_to_string(Action a)
{
    switch(a)
    {
        case Action::Eat: return "Eat";
        case Action::Sleep: return "Sleep";
        case Action::Social: return "Social";
        case Action::Work: return "Work";
        case Action::Func: return "Func";
        case Action::No: return "No";
    }
    return "Unknown";
}
Action decide_action(const Agent& a, const SimTime& t)
{
    // ===== 极端状态优先 =====
    Action critical = check_critical_state(a);

    if(critical != Action::No)
        return critical;


    // ===== 时间驱动行为 =====

    if(t.hour == 8)
        return Action::Eat;

    if(t.hour >= 9 && t.hour <= 11 )
        return Action::Work;

    if(t.hour == 12)
        return Action::Eat;

    if(t.hour >= 13 && t.hour <= 17 )
        return Action::Work;

    if(t.hour == 18)
        return Action::Eat;

    if(t.hour >= 19 && t.hour <= 23)
        return Action::Func;

    if(t.hour == 0)
        return Action::Sleep;

    return Action::No;
}
void perform_action(Agent& a, Action act)
{
    switch(act)
    {
        case Action::Eat:
            a.needs.basic.hunger -= random_range(30, 40);
            a.emotion.mood += random_range(0, 4);
            a.needs.basic.rest -= random_range(2, 4);
            break;

        case Action::Sleep:
            a.needs.basic.rest -= random_range(10, 25);
            a.emotion.stress -= random_range(5, 15);
            break;

        case Action::Work:
            a.resources.money += random_range(15, 30);
            a.needs.basic.rest += random_range(6, 12);
            a.needs.basic.hunger += random_range(8, 12);
            a.emotion.stress += random_range(0, 5);
            a.emotion.mood -= random_range(3, 7);

            break;

        case Action::Func:
            a.resources.money -= random_range(30, 70);
            a.needs.basic.hunger += random_range(8, 12);
            a.needs.basic.rest -= random_range(0, 5);
            a.emotion.stress -= random_range(0, 5);
            a.emotion.mood += random_range(4, 6);
            break;
        default:
            break;
    }
}
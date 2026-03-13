#include "../include/simulation.h"
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

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

void save_dataset(const Agent& a,const SimTime& t,Action act)
{
    json data;

    data["time"] = {
        {"hour",t.hour},
        {"weekday",t.week_day},
        {"day",t.day}
    };

    data["state"] = {
        {"hunger",a.needs.basic.hunger},
        {"rest",a.needs.basic.rest},
        {"stress",a.emotion.stress},
        {"money",a.resources.money}
    };

    data["action"] = action_to_string(act);

    std::ofstream file("datasets/dataset.jsonl",std::ios::app);
    file << data.dump() << std::endl;
}

void run_simulation(Agent& agent,SimTime& time,int steps)
{
    for(int i=0;i<steps;i++)
    {
        Action act = decide_action(agent,time);

        save_dataset(agent,time,act);

        perform_action(agent,act);

        advance_time(time);
    }
}
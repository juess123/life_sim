#include "../include/agent.h"
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
using json = nlohmann::ordered_json;
Needs init_needs()
{
    Needs n;
    n.basic.hunger = 50.0f;
    n.basic.rest = 50.0f;
    n.basic.social = 50.0f;

    n.higher.fun = 50.0f;
    n.higher.romance = 50.0f;
    n.higher.curiosity = 50.0f;
    return n;
}

Emotion init_emotion()
{
    Emotion e;

    e.mood = 65.0f;
    e.stress = 35.0f;
    e.loneliness = 40.0f;
    e.anger = 25.0f;

    return e;
}

Resources init_resources()
{
    Resources r;
    r.money = 1500;
    return r;
}

Personality init_personality()
{
    Personality p;
    p.openness = 75.0f;           // 开放性 高
    p.conscientiousness = 40.0f;  // 尽责性 低
    p.extraversion = 55.0f;       // 外向性 中等
    p.agreeableness = 35.0f;      // 宜人性 偏低
    p.neuroticism = 30.0f;        // 神经质 低
    return p;
}

Appearance init_appearance()
{
    Appearance a;
    a.age = 25;
    a.gender = Gender::Male;
    a.height = 173.0f;
    a.weight = 65.0f;
    a.attractiveness = 50.0f;
    return a;
}

Agent init_agent()
{
    Agent a;
    a.identity.id = 1;
    a.identity.name = "ZhangSan";
    a.needs = init_needs();
    a.emotion = init_emotion();
    a.resources = init_resources();
    a.personality = init_personality();
    a.appearance = init_appearance();
    return a;
}
void printf_agent(Agent agent)
{
    std::cout << "===== Identity =====" << std::endl;
    std::cout << "ID: " << agent.identity.id << std::endl;
    std::cout << "Name: " << agent.identity.name << std::endl;

    std::cout << "\n===== Needs =====" << std::endl;
    std::cout << "Hunger: " << agent.needs.basic.hunger << std::endl;
    std::cout << "Rest: " << agent.needs.basic.rest << std::endl;
    std::cout << "Social: " << agent.needs.basic.social << std::endl;

    std::cout << "Fun: " << agent.needs.higher.fun << std::endl;
    std::cout << "Romance: " << agent.needs.higher.romance << std::endl;
    std::cout << "Curiosity: " << agent.needs.higher.curiosity << std::endl;

    std::cout << "\n===== Emotion =====" << std::endl;
    std::cout << "Mood: " << agent.emotion.mood << std::endl;
    std::cout << "Stress: " << agent.emotion.stress << std::endl;
    std::cout << "Loneliness: " << agent.emotion.loneliness << std::endl;
    std::cout << "Anger: " << agent.emotion.anger << std::endl;

    std::cout << "\n===== Resources =====" << std::endl;
    std::cout << "Money: " << agent.resources.money << std::endl;

    std::cout << "\n===== Personality =====" << std::endl;
    std::cout << "Openness: " << agent.personality.openness << std::endl;
    std::cout << "Conscientiousness: " << agent.personality.conscientiousness << std::endl;
    std::cout << "Extraversion: " << agent.personality.extraversion << std::endl;
    std::cout << "Agreeableness: " << agent.personality.agreeableness << std::endl;
    std::cout << "Neuroticism: " << agent.personality.neuroticism << std::endl;

    std::cout << "\n===== Appearance =====" << std::endl;
    std::cout << "Age: " << agent.appearance.age << std::endl;
    std::cout << "Height: " << agent.appearance.height << std::endl;
    std::cout << "Weight: " << agent.appearance.weight << std::endl;
    std::cout << "Attractiveness: " << agent.appearance.attractiveness << std::endl;
}
void json_agent(const Agent& A)
{
    json data;

    data["identity"] = {
        {"id", A.identity.id},
        {"name", A.identity.name}
    };

    data["appearance"] = {
        {"age", A.appearance.age},
        {"height", A.appearance.height},
        {"weight", A.appearance.weight},
        {"attractiveness", A.appearance.attractiveness}
    };

    data["needs"]["basic"] = {
        {"hunger", A.needs.basic.hunger},
        {"rest", A.needs.basic.rest},
        {"social", A.needs.basic.social}
    };

    data["needs"]["higher"] = {
        {"fun", A.needs.higher.fun},
        {"romance", A.needs.higher.romance},
        {"curiosity", A.needs.higher.curiosity}
    };

    data["emotion"] = {
        {"mood", A.emotion.mood},
        {"stress", A.emotion.stress},
        {"loneliness", A.emotion.loneliness},
        {"anger", A.emotion.anger}
    };

    data["resources"] = {
        {"money", A.resources.money}
    };

    data["personality"] = {
        {"openness", A.personality.openness},
        {"conscientiousness", A.personality.conscientiousness},
        {"extraversion", A.personality.extraversion},
        {"agreeableness", A.personality.agreeableness},
        {"neuroticism", A.personality.neuroticism}
    };

    std::ofstream file("./datasets/agent.json");

    if (!file.is_open())
    {
        std::cout << "Failed to open file\n";
        return;
    }

    file << data.dump(4);   // pretty print
    file.close();

    std::cout << "Saved to ./datasets/agent.json\n";
}
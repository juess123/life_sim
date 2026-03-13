#include <iostream>
#include <random>
#include <fstream>
#include <map>
#include <nlohmann/json.hpp>
using json = nlohmann::ordered_json;
enum class Gender
{
    Male,
    Female
};
struct Identity
{
    int id;
    std::string name;
};
struct BasicNeeds
{
    float hunger;
    float rest;
    float social;
    
};
struct HigherNeeds
{
    float fun;
    float romance;
    float curiosity;
};
struct Needs
{
    BasicNeeds basic;
    HigherNeeds higher;
};
struct Emotion
{
    float mood;
    float stress;
    float loneliness;
    float anger;
};
struct Resources
{
    int money;
};
struct Personality
{
    float openness;          // 开放性
    float conscientiousness; // 尽责性
    float extraversion;      // 外向性
    float agreeableness;     // 宜人性
    float neuroticism;       // 神经质
};
struct Appearance
{
    int age;
    Gender gender;
    float height;
    float weight;
    float attractiveness;
};


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

int main()
{
    Identity ID ={1,"A"};
    Needs needs = init_needs();
    Emotion emotion = init_emotion();
    Resources resources = init_resources();
    Personality personality = init_personality();
    Appearance appearance = init_appearance();

    json data;

    data["identity"] = {
        {"id", ID.id},
        {"name", ID.name}
    };
    data["appearance"] = {
        {"age", appearance.age},
        {"height", appearance.height},
        {"weight", appearance.weight},
        {"attractiveness", appearance.attractiveness}
    };

    data["needs"]["basic"] = {
        {"hunger", needs.basic.hunger},
        {"rest", needs.basic.rest},
        {"social", needs.basic.social}
    };

    data["needs"]["higher"] = {
        {"fun", needs.higher.fun},
        {"romance", needs.higher.romance},
        {"curiosity", needs.higher.curiosity}
    };

    data["emotion"] = {
        {"mood", emotion.mood},
        {"stress", emotion.stress},
        {"loneliness", emotion.loneliness},
        {"anger", emotion.anger}
    };
    data["resources"] = {
        {"money", resources.money}
    };
    data["personality"] = {
        {"openness", personality.openness},
        {"conscientiousness", personality.conscientiousness},
        {"extraversion", personality.extraversion},
        {"agreeableness", personality.agreeableness},
        {"neuroticism", personality.neuroticism}
    };
    std::ofstream file("./datasets/agent.json");
    file << data.dump(4);   // 4 = pretty print
    std::cout << "Saved to agent.json\n";
}
#include "../include/dataset.h"
#include "../include/utils.h"

using json = nlohmann::ordered_json;

void save_dataset(const Agent& a, const SimTime& t, Action act)
{
    json data;

    // ===== 时间 =====
    data["time"] = {
        {"hour", t.hour},
        {"day", t.day}
    };

    // ===== Action =====
    data["action"] = action_to_string(act);

    // ===== Basic Needs =====
    data["needs_basic"] = {
        {"hunger", round1(a.needs.basic.hunger)},
        {"rest", round1(a.needs.basic.rest)},
        {"social", round1(a.needs.basic.social)}
    };

    // ===== Higher Needs =====
    data["needs_higher"] = {
        {"fun", round1(a.needs.higher.fun)},
        {"romance", round1(a.needs.higher.romance)},
        {"curiosity", round1(a.needs.higher.curiosity)}
    };

    // ===== Emotion =====
    data["emotion"] = {
        {"mood", round1(a.emotion.mood)},
        {"stress", round1(a.emotion.stress)},
        {"loneliness", round1(a.emotion.loneliness)},
        {"anger", round1(a.emotion.anger)}
    };

    // ===== Resources =====
    data["resources"] = {
        {"money", a.resources.money}
    };

    // ===== Personality =====
    data["personality"] = {
        {"openness", round1(a.personality.openness)},
        {"conscientiousness", round1(a.personality.conscientiousness)},
        {"extraversion", round1(a.personality.extraversion)},
        {"agreeableness", round1(a.personality.agreeableness)},
        {"neuroticism", round1(a.personality.neuroticism)}
    };

    // ===== Appearance =====
    data["appearance"] = {
        {"age", a.appearance.age},
        {"gender", a.appearance.gender == Gender::Male ? "male" : "female"},
        {"height", round1(a.appearance.height)},
        {"weight", round1(a.appearance.weight)},
        {"attractiveness", round1(a.appearance.attractiveness)}
    };

    std::ofstream file("datasets/dataset.jsonl", std::ios::app);
    file << data.dump() << std::endl;
}
#ifndef STATUS_H
#define STATUS_H
#include "../include/actions.h"
enum class HungerLevel
{
    Full,        // 0-20
    Satisfied,   // 20-50
    Hungry,      // 50-80
    Starving     // 80-100 (极端状态)
};

enum class RestLevel
{
    Energetic,   // 0-20
    Normal,      // 20-50
    Tired,       // 50-80
    Exhausted    // 80-100
};

enum class SocialLevel
{
    Socialized,  // 0-20
    Normal,      // 20-50
    Lonely,      // 50-80
    Isolated     // 80-100
};
HungerLevel get_hunger_level(float hunger);

RestLevel get_rest_level(float rest);

SocialLevel get_social_level(float social);

Action check_critical_state(const Agent& a);
#endif
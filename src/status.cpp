#include "../include/status.h"

// ===== Hunger 状态判断 =====
HungerLevel get_hunger_level(float hunger)
{
    if(hunger < 20)
        return HungerLevel::Full;

    if(hunger < 50)
        return HungerLevel::Satisfied;

    if(hunger < 80)
        return HungerLevel::Hungry;

    return HungerLevel::Starving;
}

// ===== Rest 状态判断 =====
RestLevel get_rest_level(float rest)
{
    if(rest < 20)
        return RestLevel::Energetic;

    if(rest < 50)
        return RestLevel::Normal;

    if(rest < 80)
        return RestLevel::Tired;

    return RestLevel::Exhausted;
}
SocialLevel get_social_level(float social)
{
    if(social < 20)
        return SocialLevel::Socialized;

    if(social < 50)
        return SocialLevel::Normal;

    if(social < 80)
        return SocialLevel::Lonely;

    return SocialLevel::Isolated;
}
// ===== 紧急状态检测 =====
Action check_critical_state(const Agent& a)
{
    HungerLevel hunger = get_hunger_level(a.needs.basic.hunger);
    RestLevel rest = get_rest_level(a.needs.basic.rest);
    SocialLevel social = get_social_level(a.needs.basic.social);

    if(hunger == HungerLevel::Starving)
        return Action::Eat;

    if(rest == RestLevel::Exhausted)
        return Action::Sleep;

    if(social == SocialLevel::Isolated)
        return Action::Social;

    return Action::No;
}
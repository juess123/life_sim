#ifndef AGENT_H
#define AGENT_H
#include <string>
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
struct Agent
{
    Identity identity;
    Needs needs;
    Emotion emotion;
    Resources resources;
    Personality personality;
    Appearance appearance;
};
Agent init_agent();
void printf_agent(Agent agent);
void json_agent(const Agent& A);
#endif
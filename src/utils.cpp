#include "utils.h"
#include <random>
#include <cmath>

float random_range(float min, float max)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dist(min, max);

    return dist(gen);
}

float clamp(float v, float min, float max)
{
    if(v < min) return min;
    if(v > max) return max;
    return v;
}

double round1(double v)
{
    return std::round(v * 10.0) / 10.0;
}
#pragma once

#include <SDL.h>
#include <SDL_ttf.h>
#include "world.h"
#include "agent.h"
struct AgentInfo
{
    Agent agent;
    Location location;
};

void render_ui(SDL_Renderer* renderer,TTF_Font* font,const AgentInfo& agent);
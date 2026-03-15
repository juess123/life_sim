#pragma once

#include <SDL.h>
#include "simulation.h"
#include "world.h"

void render_world(SDL_Renderer* renderer, World& world);
void render_agent(SDL_Renderer* renderer, Simulation& sim);
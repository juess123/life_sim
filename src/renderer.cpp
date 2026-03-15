#include "../include/renderer.h"

void render_world(SDL_Renderer* renderer, World& world)
{
    for (auto &loc : world.locations)
    {
        SDL_Rect rect = {loc.x, loc.y, 20, 20};

        SDL_SetRenderDrawColor(renderer, 0, 200, 255, 255);
        SDL_RenderFillRect(renderer, &rect);
    }
}

void render_agent(SDL_Renderer* renderer, Simulation& sim)
{
    SDL_Rect agent = {sim.location.x, sim.location.y, 4, 4};

    SDL_SetRenderDrawColor(renderer, 255, 80, 80, 255);
    SDL_RenderFillRect(renderer, &agent);
}
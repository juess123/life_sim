#include "../include/simulation.h"
#include "../include/renderer.h"
#include "../include/text.h"
#include "../include/world.h"
#include "../include/ui.h"
#include "../include/location.h"
#include "../include/world_time.h"
#include "../include/agent.h"
#include "../include/actions.h"
#include <SDL.h>
#include <SDL_ttf.h>

int main()
{
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    SDL_Window* window = SDL_CreateWindow("Life Simulation",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1000,800,0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    TTF_Font* font =load_font("/System/Library/Fonts/Supplemental/Arial.ttf",16);
    World world = create_world();
    AgentInfo agent_info;
    agent_info.agent=init_agent();
    agent_info.location=init_location();
    Simulation sim;
    init_simulation(sim);
    SimTime time = init_time();
    bool running = true;
    int step=0;
    while (running)
    {
        step++;
        SDL_Event event;

        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                running = false;
        }

        update_simulation(sim, world);

        // 同步 simulation -> UI
        agent_info.location = sim.location;

        SDL_SetRenderDrawColor(renderer,30,30,30,255);
        SDL_RenderClear(renderer);

        render_world(renderer, world);
        render_agent(renderer, sim);
        if(step>=100)
        {
            Action act = decide_action(agent_info.agent,time);
            if(act!=Action::No)
            {
                perform_action(agent_info.agent,act);
            }
            step=0;
            advance_time(time);
        }
        
        
        // 渲染 UI 面板
        render_ui(renderer, font, agent_info);

        if(!sim.location.location_name.empty())
        {
            render_text(renderer,font,sim.location.location_name,sim.location.x+ 10,sim.location.y - 10);
        }
        SDL_RenderPresent(renderer);
        SDL_Delay(16);
    }

    SDL_Quit();
}
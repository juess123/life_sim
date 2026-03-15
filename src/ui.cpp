#include "../include/ui.h"

static void render_text(SDL_Renderer* renderer,TTF_Font* font,const std::string& text,int x,int y)
{
    SDL_Color white = {255,255,255};

    SDL_Surface* surface =
        TTF_RenderText_Solid(font, text.c_str(), white);

    SDL_Texture* texture =
        SDL_CreateTextureFromSurface(renderer, surface);

    SDL_Rect rect = {x, y, surface->w, surface->h};

    SDL_RenderCopy(renderer, texture, NULL, &rect);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}

static void draw_bar(SDL_Renderer* renderer,int x,int y,int value)
{
    SDL_Rect bg = {x, y, 100, 10};

    SDL_SetRenderDrawColor(renderer, 80,80,80,255);
    SDL_RenderFillRect(renderer, &bg);

    SDL_Rect bar = {x, y, value, 10};

    SDL_SetRenderDrawColor(renderer, 200,100,100,255);
    SDL_RenderFillRect(renderer, &bar);
}

void render_ui(SDL_Renderer* renderer,TTF_Font* font,const AgentInfo& info)
{
    SDL_Rect panel = {10,10,220,320};

    SDL_SetRenderDrawColor(renderer,50,50,50,255);
    SDL_RenderFillRect(renderer,&panel);

    render_text(renderer,font,"Agent Info",20,20);

    render_text(renderer,font,"Name: " + info.agent.identity.name,20,50);

    render_text(renderer,font,"Location: " + info.location.location_name,20,70);

    render_text(renderer,font,"Money: " + std::to_string(info.agent.resources.money),20,90);

    int start_y = 120;
    int start_x = 120;
    int line = 0;
    int gap = 20;

    render_text(renderer,font,"Hunger:" + std::to_string(int(info.agent.needs.basic.hunger)),20,start_y + gap*line);
    draw_bar(renderer,start_x,start_y + gap*line + 5,info.agent.needs.basic.hunger);
    line++;

    render_text(renderer,font,"Rest" + std::to_string((int)info.agent.needs.basic.rest),20,start_y + gap*line);
    draw_bar(renderer,start_x,start_y + gap*line + 5,info.agent.needs.basic.rest);
    line++;

    render_text(renderer,font,"Social" + std::to_string((int)info.agent.needs.basic.social),20,start_y + gap*line);
    draw_bar(renderer,start_x,start_y + gap*line + 5,info.agent.needs.basic.social);
    line++;

    render_text(renderer,font,"Mood" + std::to_string((int)info.agent.emotion.mood),20,start_y + gap*line);
    draw_bar(renderer,start_x,start_y + gap*line + 5,info.agent.emotion.mood);
    line++;

    render_text(renderer,font,"Stress" + std::to_string((int)info.agent.emotion.stress),20,start_y + gap*line);
    draw_bar(renderer,start_x,start_y + gap*line + 5,info.agent.emotion.stress);
    line++;

    render_text(renderer,font,"Loneliness" + std::to_string((int)info.agent.emotion.loneliness),20,start_y + gap*line);
    draw_bar(renderer,start_x,start_y + gap*line + 5,info.agent.emotion.loneliness);
}
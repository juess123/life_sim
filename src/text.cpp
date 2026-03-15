#include "../include/text.h"

TTF_Font* load_font(const char* path, int size)
{
    return TTF_OpenFont(path, size);
}

void render_text(SDL_Renderer* renderer,
                 TTF_Font* font,
                 const std::string& text,
                 int x,
                 int y)
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
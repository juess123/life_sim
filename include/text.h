#pragma once

#include <SDL.h>
#include <SDL_ttf.h>
#include <string>

TTF_Font* load_font(const char* path, int size);

void render_text(SDL_Renderer* renderer,
                 TTF_Font* font,
                 const std::string& text,
                 int x,
                 int y);
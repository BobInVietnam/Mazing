#pragma once

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "entity.hpp"
#include "text.hpp"

class renderWindow {
public:
    renderWindow(const char* p_title, int p_w, int p_h);
    SDL_Texture* loadTexture(const char* p_filePath);
    void renderBackground(SDL_Texture* p_tex);
    void renderEntity(Entity p_entity);

    SDL_Texture* loadText(Text p_text, TTF_Font* p_font);
    void renderText(SDL_Texture* p_tex, Text p_txt);
    SDL_Renderer* getRenderer();
    void display();
    void cleanUp();
    void clear();
    
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
};
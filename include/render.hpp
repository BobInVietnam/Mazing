#pragma once

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

class renderWindow {
public:
    renderWindow(const char* p_title, int p_w, int p_h);
    SDL_Texture* loadTexture(const char* p_filePath);
    SDL_Renderer* getRenderer();
    void display();
    void cleanUp();
    void clear();
    
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
};
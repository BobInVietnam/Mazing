#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "maths.hpp"

struct Texture {
    Texture(SDL_Texture * p_tex, Vector2f p_size)
    :texture(p_tex), size(p_size)
    {
        frameNum = 1;
    };
    
    Texture(SDL_Texture * p_tex, Vector2f p_size, int p_fnum)
    :texture(p_tex), size(p_size), frameNum(p_fnum)
    {};

    SDL_Texture * texture;
    Vector2f size;
    int frameNum;
};
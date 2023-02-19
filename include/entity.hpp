#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "maths.hpp"

class Entity
{
protected:
    SDL_Texture* texture;
    Vector2f position;
    Vector2f size;
public:
    Entity(SDL_Texture* p_tex, Vector2f p_pos, Vector2f p_size);
    void move(Vector2f p_velocity);
    Vector2f getSize() { return size; }
    Vector2f getPos() { return position; }
    SDL_Texture* getTex() { return texture; }
};

class Player : public Entity
{
protected: 
    
};
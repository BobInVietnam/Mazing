#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "maths.hpp"
#include "texture.hpp"

class Entity
{
protected:
    Texture texture;
    Vector2f position;
    Vector2f size;
public:
    Entity();
    Entity(Texture p_tex);
    Entity(Texture p_tex, Vector2f p_pos, Vector2f p_size);
    void move(Vector2f p_velocity);
    Vector2f getSize() { return size; }
    Vector2f getPos() { return position; }
    Texture getTex() { return texture; }
    void setPos(Vector2f p_pos) { position = p_pos; }
    void setSize(Vector2f p_size) { size = p_size; }
};
class Obstacle : public Entity 
{
public:
    Obstacle(Texture p_tex, Vector2f p_pos, Vector2f p_size) : Entity(p_tex, p_pos, p_size) 
    {};
    Obstacle(Texture p_tex, Vector2f p_size, float p_speed, Vector2f p_A, Vector2f p_B);
    Vector2f ObsVelocity = Vector2f();
    bool moving = false;
    Vector2f getStartingPos() { return posA;}
    bool reachedEnd();
private:
    float ObsSpeed = 0;
    Vector2f posA = Vector2f();
    Vector2f posB = Vector2f();
};
class Player : public Entity
{
public:
    Player(Texture p_tex) : Entity(p_tex)
    {};
    void changeTex(Texture p_tex);
    bool Collided(Entity p_entity);
};
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
    Obstacle(Texture p_tex, Vector2f p_size, Vector2f p_iniVelo, float p_acc, Vector2f p_origin, Vector2f p_gravOrigin);
    Vector2f ObsVelocity = Vector2f();
    float ObsGravity = 0;
    bool moving = false;
    bool oscillating = false;
    bool circling = false;
    Vector2f getStartingPos() { return posA;}
    Vector2f getStartingVelo() { return iniVelocity;}
    Vector2f getGravityOrigin() {return posB;}
    bool reachedEnd();
private:
    float ObsSpeed = 0;
    Vector2f iniVelocity = Vector2f();
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
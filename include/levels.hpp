#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include "render.hpp"

//Window & entities initialization 
renderWindow window("Hello!", SCREEN_WIDTH, SCREEN_HEIGHT);
SDL_Texture* bg = window.loadTexture("res/bg.png");

//Player-related variables
std::vector<Obstacle> ObsList = {   Obstacle(window.loadTexture("res/blockade.png"), Vector2f(100, 100), Vector2f(400, 80))
                                ,   Obstacle(window.loadTexture("res/blockade.png"), Vector2f(700, 100), Vector2f(80, 200))};
Player Bob(window.loadTexture("res/thing.png"), Vector2f(400, 300), Vector2f(40, 40));
Entity Goal(window.loadTexture("res/goal.png"), Vector2f(400, 500), Vector2f(30, 30));
Vector2f MousePos;
Vector2f PlayerVelocity;
int PlayerSpeed = 10;
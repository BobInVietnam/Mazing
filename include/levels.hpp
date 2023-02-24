#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include "render.hpp"

//Window & entities initialization 
renderWindow window("Hello!", SCREEN_WIDTH, SCREEN_HEIGHT);
SDL_Texture* bg = window.loadTexture("res/bg.png");
SDL_Texture* menu = window.loadTexture("res/intro.png");

//Player-related variables
Player Bob(window.loadTexture("res/thing.png"));
Entity Goal(window.loadTexture("res/goal.png"), Vector2f(), Vector2f(40, 40));
Vector2f MousePos;
Vector2f PlayerVelocity;

struct Level {
    Level(std::vector<Obstacle> p_obslist, Vector2f p_spos, Vector2f p_ssize, Vector2f p_gpos, int p_speed) 
    :ObstacleList(p_obslist), StartingPos(p_spos), StartingSize(p_ssize), GoalPos(p_gpos), PlayerLevelSpeed(p_speed)
    {};
    std::vector<Obstacle> ObstacleList;
    Vector2f StartingPos;
    Vector2f StartingSize;
    Vector2f GoalPos;
    int PlayerLevelSpeed;
};

const int LEVEL_NUM = 3;

//Level 1
std::vector<Obstacle> ObsList1 = {  Obstacle(window.loadTexture("res/blockade.png"), Vector2f(100, 100), Vector2f(400, 80))
                                ,   Obstacle(window.loadTexture("res/blockade.png"), Vector2f(700, 100), Vector2f(80, 200))};
const Vector2f PLAYER_POS_L1 = Vector2f(300, 300);
const Vector2f PLAYER_SIZE_L1 = Vector2f(30, 30);
const int PLAYER_SPEED_L1 = 10;
const Vector2f GOAL_POS_L1 = Vector2f(600, 400);

//Level 2
std::vector<Obstacle> ObsList2 = {  Obstacle(window.loadTexture("res/blockade.png"), Vector2f(100, 100), Vector2f(400, 80))
                                ,   Obstacle(window.loadTexture("res/blockade.png"), Vector2f(700, 100), Vector2f(80, 200))
                                ,   Obstacle(window.loadTexture("res/blockade.png"), Vector2f(100, 300), Vector2f(100, 100))
                                ,   Obstacle(window.loadTexture("res/blockade.png"), Vector2f(500, 500), Vector2f(80, 800))};
const Vector2f PLAYER_POS_L2 = Vector2f(300, 500);
const Vector2f PLAYER_SIZE_L2 = Vector2f(20, 20);
const int PLAYER_SPEED_L2 = 15;
const Vector2f GOAL_POS_L2 = Vector2f(700, 20);

//Level 3
std::vector<Obstacle> ObsList3 = {  Obstacle(window.loadTexture("res/blockade.png"), Vector2f(80, 80), Vector2f(40, 280))
                                ,   Obstacle(window.loadTexture("res/blockade.png"), Vector2f(80, 440), Vector2f(40, 280))
                                ,   Obstacle(window.loadTexture("res/blockade.png"), Vector2f(120, 80), Vector2f(760, 40))
                                ,   Obstacle(window.loadTexture("res/blockade.png"), Vector2f(120, 680), Vector2f(760, 40))
                                ,   Obstacle(window.loadTexture("res/blockade.png"), Vector2f(840, 120), Vector2f(40, 240))
                                ,   Obstacle(window.loadTexture("res/blockade.png"), Vector2f(840, 440), Vector2f(40, 240))
                                ,   Obstacle(window.loadTexture("res/blockade.png"), Vector2f(240, 240), Vector2f(40, 320))
                                ,   Obstacle(window.loadTexture("res/blockade.png"), Vector2f(400, 120), Vector2f(40, 200))
                                ,   Obstacle(window.loadTexture("res/blockade.png"), Vector2f(400, 480), Vector2f(40, 120))
                                ,   Obstacle(window.loadTexture("res/blockade.png"), Vector2f(560, 240), Vector2f(40, 440))
                                ,   Obstacle(window.loadTexture("res/blockade.png"), Vector2f(720, 120), Vector2f(40, 480))};
const Vector2f PLAYER_POS_L3 = Vector2f(20, 380);
const Vector2f PLAYER_SIZE_L3 = Vector2f(40, 40);
const int PLAYER_SPEED_L3 = 12;
const Vector2f GOAL_POS_L3 = Vector2f(900, 380);

int ID = 0;
Level lv[LEVEL_NUM] = { Level(ObsList1, PLAYER_POS_L1, PLAYER_SIZE_L1, GOAL_POS_L1, PLAYER_SPEED_L1)
                    ,   Level(ObsList2, PLAYER_POS_L2, PLAYER_SIZE_L2, GOAL_POS_L2, PLAYER_SPEED_L2)
                    ,   Level(ObsList3, PLAYER_POS_L3, PLAYER_SIZE_L3, GOAL_POS_L3, PLAYER_SPEED_L3)};


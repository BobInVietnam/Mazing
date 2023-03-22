#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <vector>
#include "render.hpp"

//Window & textures initialization 
renderWindow window("Hello!", SCREEN_WIDTH, SCREEN_HEIGHT);
SDL_Texture* bg = window.loadTexture("res/bg.png");
SDL_Texture* menu = window.loadTexture("res/intro.png");
SDL_Texture* win = window.loadTexture("res/win.png");
SDL_Texture* lost = window.loadTexture("res/lost.png");

Texture player(window.loadTexture("res/thing.png"), Vector2f(40, 40));
// Texture player_hit(window.loadTexture("res/thing_oof.png"), Vector2f(40, 40));
Texture goal(window.loadTexture("res/goal.png"), Vector2f(30, 30));
Texture obstacle(window.loadTexture("res/blockade.png"), Vector2f(200, 50));
Texture movingObstacle(window.loadTexture("res/moving_blockade.png"), Vector2f(40, 40));
Texture lock(window.loadTexture("res/lock.png"), Vector2f(100, 100));
Texture key(window.loadTexture("res/key.png"), Vector2f(100, 100));

//Player-related variables
Player Bob(player);
Entity Goal(goal, Vector2f(), Vector2f(40, 40));
Vector2f MousePos;
Vector2f PlayerVelocity;

TTF_Font* font = NULL;
int DeathCountI = 0;
Text DeathCountT = Text("Death Count: 0", 0.5f, Vector2f());
SDL_Texture* DeathCounter = NULL;

struct Level {
    Level(std::vector<Obstacle> p_obslist, Vector2f p_spos, Vector2f p_ssize, Vector2f p_gpos, float p_speed) 
    :ObstacleList(p_obslist), StartingPos(p_spos), StartingSize(p_ssize), GoalPos(p_gpos), PlayerLevelSpeed(p_speed)
    {
        KeyList = {};
    };
    Level(std::vector<Obstacle> p_obslist, std::vector<Key> p_picklist, Vector2f p_spos, Vector2f p_ssize, Vector2f p_gpos, float p_speed) 
    :ObstacleList(p_obslist), KeyList(p_picklist), StartingPos(p_spos), StartingSize(p_ssize), GoalPos(p_gpos), PlayerLevelSpeed(p_speed)
    {};
    std::vector<Obstacle> ObstacleList;
    std::vector<Key> KeyList;
    Vector2f StartingPos;
    Vector2f StartingSize;
    Vector2f GoalPos;
    float PlayerLevelSpeed;
};

const int LEVEL_NUM = 7;

//Level 1
std::vector<Obstacle> ObsList1 = {  Obstacle(obstacle, Vector2f(400, 280), Vector2f(400, 240))};
const Vector2f PLAYER_POS_L1 = Vector2f(240, 160);
const Vector2f PLAYER_SIZE_L1 = Vector2f(80, 80);
const float PLAYER_SPEED_L1 = 15;
const Vector2f GOAL_POS_L1 = Vector2f(880, 560);

//Level 2
std::vector<Obstacle> ObsList2 = {  Obstacle(obstacle, Vector2f(320, 360), Vector2f(120, 360))
                                ,   Obstacle(obstacle, Vector2f(760, 80), Vector2f(120, 360))};
const Vector2f PLAYER_POS_L2 = Vector2f(120, 360);
const Vector2f PLAYER_SIZE_L2 = Vector2f(80, 80);
const float PLAYER_SPEED_L2 = 15;
const Vector2f GOAL_POS_L2 = Vector2f(1000, 360);

//Level 3
std::vector<Obstacle> ObsList3 = {  Obstacle(obstacle, Vector2f(), Vector2f(1200, 40))
                                ,   Obstacle(obstacle, Vector2f(0, 40), Vector2f(40, 720))
                                ,   Obstacle(obstacle, Vector2f(0, 760), Vector2f(1200, 40))
                                ,   Obstacle(obstacle, Vector2f(1160, 40), Vector2f(40, 720))
                                ,   Obstacle(obstacle, Vector2f(40, 200), Vector2f(880, 80))
                                ,   Obstacle(obstacle, Vector2f(280, 480), Vector2f(880, 80))};
const Vector2f PLAYER_POS_L3 = Vector2f(100, 80);
const Vector2f PLAYER_SIZE_L3 = Vector2f(80, 80);
const float PLAYER_SPEED_L3 = 16;
const Vector2f GOAL_POS_L3 = Vector2f(1000, 640);

//Level 4
std::vector<Obstacle> ObsList4 = {  Obstacle(movingObstacle, Vector2f(200, 80), 10, Vector2f(280, 40), Vector2f(280, 680))
                                ,   Obstacle(movingObstacle, Vector2f(200, 80), 10, Vector2f(520, 680), Vector2f(520, 40))
                                ,   Obstacle(movingObstacle, Vector2f(200, 80), 10, Vector2f(760, 40), Vector2f(760, 680))};
const Vector2f PLAYER_POS_L4 = Vector2f(80, 360);
const Vector2f PLAYER_SIZE_L4 = Vector2f(80, 80);
const float PLAYER_SPEED_L4 = 12.5;
const Vector2f GOAL_POS_L4 = Vector2f(1060, 385);

//Level 5
std::vector<Obstacle> ObsList5 = {  Obstacle(obstacle, Vector2f(560, 360), Vector2f(80, 80))
                                ,   Obstacle(movingObstacle, Vector2f(80, 80), Vector2f(0, 24), 0.0036f, Vector2f(160, 360), Vector2f(560, 360))
                                ,   Obstacle(movingObstacle, Vector2f(80, 80), Vector2f(0, -24), 0.0036f, Vector2f(960, 360), Vector2f(560, 360))
                                ,   Obstacle(movingObstacle, Vector2f(80, 80), Vector2f(0, -12), 0.0036f, Vector2f(360, 360), Vector2f(560, 360))
                                ,   Obstacle(movingObstacle, Vector2f(80, 80), Vector2f(12, 0), 0.0036f, Vector2f(560, 160), Vector2f(560, 360))
                                ,   Obstacle(movingObstacle, Vector2f(80, 80), Vector2f(0, 12), 0.0036f, Vector2f(760, 360), Vector2f(560, 360))
                                ,   Obstacle(movingObstacle, Vector2f(80, 80), Vector2f(-12, 0), 0.0036f, Vector2f(560, 560), Vector2f(560, 360))};
const Vector2f PLAYER_POS_L5 = Vector2f(160, 120);
const Vector2f PLAYER_SIZE_L5 = Vector2f(40, 40);
const float PLAYER_SPEED_L5 = 12;
const Vector2f GOAL_POS_L5 = Vector2f(980, 620);

//Level 6
std::vector<Obstacle> ObsList6 = {  Obstacle(obstacle, Vector2f(520, 360), Vector2f(80, 80))
                                ,   Obstacle(obstacle, Vector2f(920, 0), Vector2f(40, 280))
                                ,   Obstacle(obstacle, Vector2f(960, 0), Vector2f(40, 320))
                                ,   Obstacle(obstacle, Vector2f(1000, 0), Vector2f(40, 360))
                                ,   Obstacle(obstacle, Vector2f(920, 520), Vector2f(40, 280))
                                ,   Obstacle(obstacle, Vector2f(960, 480), Vector2f(40, 320))
                                ,   Obstacle(obstacle, Vector2f(1000, 440), Vector2f(40, 360))
                                ,   Obstacle(movingObstacle, Vector2f(1200, 20), 3.5, Vector2f(0, 0), Vector2f(0, 800))
                                ,   Obstacle(movingObstacle, Vector2f(1200, 20), 3.5, Vector2f(0, 780), Vector2f(0, 0))};
const Vector2f PLAYER_POS_L6 = Vector2f(40, 370);
const Vector2f PLAYER_SIZE_L6 = Vector2f(60, 60);
const float PLAYER_SPEED_L6 = 12;
const Vector2f GOAL_POS_L6 = Vector2f(1120, 385);

//Level 7
std::vector<Obstacle> ObsList7 = {  Obstacle(obstacle, Vector2f(200, 0), Vector2f(40, 600))
                                ,   Obstacle(obstacle, Vector2f(400, 200), Vector2f(40, 600))
                                ,   Obstacle(obstacle, Vector2f(600, 0), Vector2f(40, 600))
                                ,   Obstacle(obstacle, Vector2f(800, 200), Vector2f(40, 600))
                                ,   Obstacle(obstacle, Vector2f(840, 200), Vector2f(200, 40))
                                ,   Obstacle(obstacle, Vector2f(1000, 400), Vector2f(200, 40))
                                ,   Obstacle(obstacle, Vector2f(840, 600), Vector2f(200, 40))
                                ,   Obstacle(movingObstacle, Vector2f(20, 400), 10, Vector2f(1180, 0), Vector2f(0, 0))
                                ,   Obstacle(movingObstacle, Vector2f(20, 400), 10, Vector2f(0, 400), Vector2f(1180, 400))};
const Vector2f PLAYER_POS_L7 = Vector2f(60, 60);
const Vector2f PLAYER_SIZE_L7 = Vector2f(60, 60);
const float PLAYER_SPEED_L7 = 12;
const Vector2f GOAL_POS_L7 = Vector2f(1080, 680);

//


int ID = 0;
Level lv[LEVEL_NUM] = { Level(ObsList1, PLAYER_POS_L1, PLAYER_SIZE_L1, GOAL_POS_L1, PLAYER_SPEED_L1)
                    ,   Level(ObsList2, PLAYER_POS_L2, PLAYER_SIZE_L2, GOAL_POS_L2, PLAYER_SPEED_L2)
                    ,   Level(ObsList3, PLAYER_POS_L3, PLAYER_SIZE_L3, GOAL_POS_L3, PLAYER_SPEED_L3)
                    ,   Level(ObsList4, PLAYER_POS_L4, PLAYER_SIZE_L4, GOAL_POS_L4, PLAYER_SPEED_L4)
                    ,   Level(ObsList5, PLAYER_POS_L5, PLAYER_SIZE_L5, GOAL_POS_L5, PLAYER_SPEED_L5)
                    ,   Level(ObsList6, PLAYER_POS_L6, PLAYER_SIZE_L6, GOAL_POS_L6, PLAYER_SPEED_L6)
                    ,   Level(ObsList7, PLAYER_POS_L7, PLAYER_SIZE_L7, GOAL_POS_L7, PLAYER_SPEED_L7)
                    };

// std::vector<Obstacle> ObsList3 = {  Obstacle(obstacle, Vector2f(80, 80), Vector2f(40, 280))
//                                 ,   Obstacle(obstacle, Vector2f(80, 440), Vector2f(40, 280))
//                                 ,   Obstacle(obstacle, Vector2f(120, 80), Vector2f(760, 40))
//                                 ,   Obstacle(obstacle, Vector2f(120, 680), Vector2f(760, 40))
//                                 ,   Obstacle(obstacle, Vector2f(840, 120), Vector2f(40, 240))
//                                 ,   Obstacle(obstacle, Vector2f(840, 440), Vector2f(40, 240))
//                                 ,   Obstacle(obstacle, Vector2f(240, 240), Vector2f(40, 320))
//                                 ,   Obstacle(obstacle, Vector2f(400, 120), Vector2f(40, 200))
//                                 ,   Obstacle(obstacle, Vector2f(400, 480), Vector2f(40, 120))
//                                 ,   Obstacle(obstacle, Vector2f(560, 240), Vector2f(40, 440))
//                                 ,   Obstacle(obstacle, Vector2f(720, 120), Vector2f(40, 480))};

// std::vector<Obstacle> ObsList5 = {  Obstacle(obstacle, Vector2f(/*pos*/), Vector2f(/*size*/))
//                                 ,   Obstacle(movingObstacle, Vector2f(/*size*/), Vector2f(/*ini_velocity*/), /*gravity_value*/, Vector2f(/*origin*/), Vector2f(/*grav_center*/))
//                                 ,   Obstacle(movingObstacle, Vector2f(/*size*/), /*speed*/, Vector2f(/*A*/), Vector2f(/*B*/))
// };
// const Vector2f PLAYER_POS_L = Vector2f();
// const Vector2f PLAYER_SIZE_L = Vector2f(40, 40);
// const float PLAYER_SPEED_L = 0;
// const Vector2f GOAL_POS_L = Vector2f();
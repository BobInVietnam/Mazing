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
Texture pause(window.loadTexture("res/pause.png"), Vector2f());

//Player-related variables
Player Bob(player);
Entity Goal(goal, Vector2f(), Vector2f(40, 40));
Vector2f MousePos;
Vector2f PlayerVelocity;

//Text-based
TTF_Font* font = NULL;
int DeathCountI = 0;
Text DeathCountT = Text("Death Count: 0", 0.5f, Vector2f());
SDL_Texture* DeathCounter = NULL;

int GameTimerI = 0;
int startingTime = 0;
Text GameTimerT = Text("Time : 000ms", 0.5f, Vector2f(0, 20));
SDL_Texture* GameTimer = NULL;

//Level objectives
std::vector<Key> LevelKeys = {};
std::vector<Entity> Locks = {};

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

const int LEVEL_NUM = 12;

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
std::vector<Obstacle> ObsList7 = {     Obstacle(obstacle, Vector2f(200, 0), Vector2f(1000, 30))
                                    ,   Obstacle(obstacle, Vector2f(200, 170), Vector2f(880, 30))
                                    ,   Obstacle(obstacle, Vector2f(1170, 30), Vector2f(30, 770))
                                    ,   Obstacle(obstacle, Vector2f(200, 200), Vector2f(30, 430))
                                    ,   Obstacle(obstacle, Vector2f(230, 600), Vector2f(520, 30))
                                    ,   Obstacle(obstacle, Vector2f(950, 330), Vector2f(30, 440))
                                    ,   Obstacle(obstacle, Vector2f(570, 330), Vector2f(380, 30))
                                    ,   Obstacle(obstacle, Vector2f(720, 450), Vector2f(30, 150))
                                    ,   Obstacle(obstacle, Vector2f(370, 200), Vector2f(30, 270))
                                    ,   Obstacle(obstacle, Vector2f(570, 360), Vector2f(30, 160))
                                    ,   Obstacle(obstacle, Vector2f(200, 170), Vector2f(780, 30))
                                    ,   Obstacle(obstacle, Vector2f(1070, 330), Vector2f(100, 30))
                                    ,   Obstacle(obstacle, Vector2f(980, 460), Vector2f(100, 30))
                                    ,   Obstacle(obstacle, Vector2f(1070, 590), Vector2f(100, 30))
};
std::vector<Key> KeyList7 = {  Key(key, Vector2f(280, 230), lock, Vector2f(60, 570), Vector2f(100, 100))
                            ,   Key(key, Vector2f(1060, 690), lock, Vector2f(70, 580), Vector2f(80, 80))
};
const Vector2f PLAYER_POS_L7 = Vector2f(80, 80);
const Vector2f PLAYER_SIZE_L7 = Vector2f(40, 40);
const float PLAYER_SPEED_L7 = 8;
const Vector2f GOAL_POS_L7 = Vector2f(90, 600);


//Level 8
std::vector<Obstacle> ObsList8 = {  Obstacle(obstacle, Vector2f(80, 80), Vector2f(40, 280))
                                ,   Obstacle(obstacle, Vector2f(80, 440), Vector2f(40, 280))
                                ,   Obstacle(obstacle, Vector2f(120, 80), Vector2f(760, 40))
                                ,   Obstacle(obstacle, Vector2f(120, 680), Vector2f(760, 40))
                                ,   Obstacle(obstacle, Vector2f(840, 120), Vector2f(40, 240))
                                ,   Obstacle(obstacle, Vector2f(840, 440), Vector2f(40, 240))
                                ,   Obstacle(obstacle, Vector2f(240, 240), Vector2f(40, 320))
                                ,   Obstacle(obstacle, Vector2f(400, 120), Vector2f(40, 200))
                                ,   Obstacle(obstacle, Vector2f(400, 480), Vector2f(40, 120))
                                ,   Obstacle(obstacle, Vector2f(560, 240), Vector2f(40, 440))
                                ,   Obstacle(obstacle, Vector2f(720, 120), Vector2f(40, 480))
                                ,   Obstacle(obstacle, Vector2f(880, 80), Vector2f(240, 40))
                                ,   Obstacle(obstacle, Vector2f(880, 680), Vector2f(240, 40))
                                ,   Obstacle(obstacle, Vector2f(1080, 120), Vector2f(40, 560))
                                ,   Obstacle(movingObstacle, Vector2f(200, 80), 10, Vector2f(880, 120), Vector2f(880, 600))
                                };
const Vector2f PLAYER_POS_L8 = Vector2f(40, 380);
const Vector2f PLAYER_SIZE_L8 = Vector2f(40, 40);
const float PLAYER_SPEED_L8 = 12;
const Vector2f GOAL_POS_L8 = Vector2f(970, 620);

//level9
std::vector<Obstacle> ObsList9 = {  Obstacle(obstacle, Vector2f(320, 40), Vector2f(120, 120))
                                ,   Obstacle(obstacle, Vector2f(400, 240), Vector2f(40, 40))
                                ,   Obstacle(obstacle, Vector2f(240, 320), Vector2f(80, 80))
                                ,   Obstacle(obstacle, Vector2f(120, 520), Vector2f(80, 80))
                                ,   Obstacle(obstacle, Vector2f(440, 440), Vector2f(80, 80))
                                ,   Obstacle(obstacle, Vector2f(560, 240), Vector2f(80, 80))
                                ,   Obstacle(obstacle, Vector2f(640, 400), Vector2f(80, 80))
                                ,   Obstacle(obstacle, Vector2f(640, 560), Vector2f(80, 80))
                                ,   Obstacle(obstacle, Vector2f(840, 520), Vector2f(80, 80))
                                ,   Obstacle(obstacle, Vector2f(760, 280), Vector2f(40, 40))
                                ,   Obstacle(obstacle, Vector2f(1040, 500), Vector2f(40, 40))
                                ,   Obstacle(obstacle, Vector2f(1100, 240), Vector2f(40, 40))
                                ,   Obstacle(obstacle, Vector2f(280, 640), Vector2f(120, 120))
                                ,   Obstacle(obstacle, Vector2f(760, 80), Vector2f(120, 120))
                                ,   Obstacle(obstacle, Vector2f(920, 320), Vector2f(120, 120))
                                ,   Obstacle(movingObstacle, Vector2f(20, 800), 5.3, Vector2f(0, 0), Vector2f(1180, 0))};
const Vector2f PLAYER_POS_L9 = Vector2f(120, 380);
const Vector2f PLAYER_SIZE_L9 = Vector2f(40, 40);
const float PLAYER_SPEED_L9 = 5.5;
const Vector2f GOAL_POS_L9 = Vector2f(1150, 380);

//level10
std::vector<Obstacle> ObsList10 = {  Obstacle(obstacle, Vector2f(580, 380), Vector2f(40, 40))
                                ,   Obstacle(movingObstacle, Vector2f(40, 160), Vector2f(0, 0), 0.001755f, Vector2f(0, 320), Vector2f(580, 320))
                                ,   Obstacle(movingObstacle, Vector2f(40, 160), Vector2f(0, 0), 0.001755f, Vector2f(1180, 320), Vector2f(580, 320))
                                ,   Obstacle(movingObstacle, Vector2f(160, 40), Vector2f(0, 0), 0.001755f, Vector2f(520, 0), Vector2f(520, 380))
                                ,   Obstacle(movingObstacle, Vector2f(160, 40), Vector2f(0, 0), 0.001755f, Vector2f(520, 760), Vector2f(520, 380))
                                ,   Obstacle(movingObstacle, Vector2f(40, 40), Vector2f(0, -12), 0.00213f, Vector2f(320, 380), Vector2f(580, 380))
                                ,   Obstacle(movingObstacle, Vector2f(40, 40), Vector2f(0, 12), 0.00213f, Vector2f(840, 380), Vector2f(580, 380))};
std::vector<Key> KeyList10 = {  Key(key, Vector2f(200, 80), lock, Vector2f(1000, 40), Vector2f(120, 120))
                            ,   Key(key, Vector2f(1040, 80), lock, Vector2f(80, 640), Vector2f(120, 120))
                            ,   Key(key, Vector2f(120, 680), lock, Vector2f(1000, 640), Vector2f(120, 120))};
const Vector2f PLAYER_POS_L10 = Vector2f(120, 80);
const Vector2f PLAYER_SIZE_L10 = Vector2f(40, 40);
const float PLAYER_SPEED_L10 = 12;
const Vector2f GOAL_POS_L10 = Vector2f(1040, 680);

//Level 11
std::vector<Obstacle> ObsList11 = {  Obstacle(obstacle, Vector2f(200, 0), Vector2f(40, 600))
                                ,   Obstacle(obstacle, Vector2f(400, 200), Vector2f(40, 600))
                                ,   Obstacle(obstacle, Vector2f(600, 0), Vector2f(40, 600))
                                ,   Obstacle(obstacle, Vector2f(800, 200), Vector2f(40, 600))
                                ,   Obstacle(obstacle, Vector2f(840, 200), Vector2f(200, 40))
                                ,   Obstacle(obstacle, Vector2f(1000, 400), Vector2f(200, 40))
                                ,   Obstacle(obstacle, Vector2f(840, 600), Vector2f(200, 40))
                                ,   Obstacle(movingObstacle, Vector2f(20, 400), 10, Vector2f(1180, 0), Vector2f(0, 0))
                                ,   Obstacle(movingObstacle, Vector2f(20, 400), 10, Vector2f(0, 400), Vector2f(1180, 400))};
const Vector2f PLAYER_POS_L11 = Vector2f(60, 60);
const Vector2f PLAYER_SIZE_L11 = Vector2f(60, 60);
const float PLAYER_SPEED_L11 = 12;
const Vector2f GOAL_POS_L11 = Vector2f(1080, 680);

// Level 12
std::vector<Obstacle> ObsList12 = {  Obstacle(obstacle, Vector2f(90, 90), Vector2f(420, 20))
                                ,   Obstacle(obstacle, Vector2f(590, 90), Vector2f(520, 20))
                                ,   Obstacle(obstacle, Vector2f(90, 110), Vector2f(20, 580))
                                ,   Obstacle(obstacle, Vector2f(90, 690), Vector2f(1020, 20))
                                ,   Obstacle(obstacle, Vector2f(1090, 110), Vector2f(20, 580))
                                ,   Obstacle(obstacle, Vector2f(590, 110), Vector2f(20, 100))
                                ,   Obstacle(obstacle, Vector2f(190, 190), Vector2f(400, 20))
                                ,   Obstacle(obstacle, Vector2f(110, 290), Vector2f(200, 20))
                                ,   Obstacle(obstacle, Vector2f(390, 210), Vector2f(20, 100))
                                ,   Obstacle(obstacle, Vector2f(410, 290), Vector2f(280, 20))
                                ,   Obstacle(obstacle, Vector2f(690, 190), Vector2f(20, 320))
                                ,   Obstacle(obstacle, Vector2f(890, 110), Vector2f(20, 100))
                                ,   Obstacle(obstacle, Vector2f(990, 190), Vector2f(20, 200))
                                ,   Obstacle(obstacle, Vector2f(790, 190), Vector2f(20, 200))
                                ,   Obstacle(obstacle, Vector2f(790, 390), Vector2f(220, 20))
                                ,   Obstacle(obstacle, Vector2f(810, 290), Vector2f(100, 20))
                                ,   Obstacle(obstacle, Vector2f(710, 490), Vector2f(100, 20))
                                ,   Obstacle(obstacle, Vector2f(810, 290), Vector2f(100, 20))
                                ,   Obstacle(obstacle, Vector2f(890, 410), Vector2f(20, 280))
                                ,   Obstacle(obstacle, Vector2f(990, 490), Vector2f(100, 20))
                                ,   Obstacle(obstacle, Vector2f(990, 510), Vector2f(20, 100))
                                ,   Obstacle(obstacle, Vector2f(290, 310), Vector2f(20, 100))
                                ,   Obstacle(obstacle, Vector2f(310, 390), Vector2f(300, 20))
                                ,   Obstacle(obstacle, Vector2f(590, 410), Vector2f(20, 200))
                                ,   Obstacle(obstacle, Vector2f(190, 390), Vector2f(20, 100))
                                ,   Obstacle(obstacle, Vector2f(190, 490), Vector2f(320, 20))
                                ,   Obstacle(obstacle, Vector2f(590, 410), Vector2f(20, 200))
                                ,   Obstacle(obstacle, Vector2f(490, 510), Vector2f(20, 180))
                                ,   Obstacle(obstacle, Vector2f(610, 590), Vector2f(200, 20))
                                ,   Obstacle(obstacle, Vector2f(390, 510), Vector2f(20, 100))
                                ,   Obstacle(obstacle, Vector2f(290, 590), Vector2f(20, 100))
                                ,   Obstacle(obstacle, Vector2f(190, 590), Vector2f(100, 20))
};
std::vector<Key> KeyList12 = {  Key(key, Vector2f(1030, 530), lock, Vector2f(210, 610), Vector2f(80, 80))
};
const Vector2f PLAYER_POS_L12 = Vector2f(530, 60);
const Vector2f PLAYER_SIZE_L12 = Vector2f(40, 40);
const float PLAYER_SPEED_L12 = 8;
const Vector2f GOAL_POS_L12 = Vector2f(230, 630);


int ID = 0;
Level lv[LEVEL_NUM] = { 
                        Level(ObsList1, PLAYER_POS_L1, PLAYER_SIZE_L1, GOAL_POS_L1, PLAYER_SPEED_L1)
                    ,   Level(ObsList2, PLAYER_POS_L2, PLAYER_SIZE_L2, GOAL_POS_L2, PLAYER_SPEED_L2)
                    ,   Level(ObsList3, PLAYER_POS_L3, PLAYER_SIZE_L3, GOAL_POS_L3, PLAYER_SPEED_L3)
                    ,   Level(ObsList4, PLAYER_POS_L4, PLAYER_SIZE_L4, GOAL_POS_L4, PLAYER_SPEED_L4)
                    ,   Level(ObsList5, PLAYER_POS_L5, PLAYER_SIZE_L5, GOAL_POS_L5, PLAYER_SPEED_L5)
                    ,   Level(ObsList6, PLAYER_POS_L6, PLAYER_SIZE_L6, GOAL_POS_L6, PLAYER_SPEED_L6)
                    ,   Level(ObsList7, KeyList7, PLAYER_POS_L7, PLAYER_SIZE_L7, GOAL_POS_L7, PLAYER_SPEED_L7)
                    ,   Level(ObsList8, PLAYER_POS_L8, PLAYER_SIZE_L8, GOAL_POS_L8, PLAYER_SPEED_L8)
                    ,   Level(ObsList9, PLAYER_POS_L9, PLAYER_SIZE_L9, GOAL_POS_L9, PLAYER_SPEED_L9)
                    ,   Level(ObsList10, KeyList10, PLAYER_POS_L10, PLAYER_SIZE_L10, GOAL_POS_L10, PLAYER_SPEED_L10)
                    ,   Level(ObsList11, PLAYER_POS_L11, PLAYER_SIZE_L11, GOAL_POS_L11, PLAYER_SPEED_L11)
                    ,   Level(ObsList12, KeyList12, PLAYER_POS_L12, PLAYER_SIZE_L12, GOAL_POS_L12, PLAYER_SPEED_L12)
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
#pragma once

#include <cmath>
#include "data.hpp" 

SDL_Event gameEvent;

bool gameRunning = true;

//New game menu
bool gameMenuRunning = true;
void RenderMenu();
void ProcessMenuEvent();
void InitiateLevel();

//Gameplay
bool gameStart = false;
bool gameplayRunning = false;
bool gameplayPausing = false;
void PauseGame();
void QuitGame();
void RegisterMousePos();
void ProcessGameEvent();
void RenderMainGame();
void CollisionCheck();
void ProcessObstacles();
void CheckGameWon();

//Lost menu
bool gameLostRunning = false;
void RenderGameLostMenu();
void ProcessGLMenuEvent();

//Won menu
bool gameWinRunning = false;
void RenderGameWonMenu();
void ProcessGWMenuEvent();

//-------------------------------------------------------------------------------------------------
//Menu
void ProcessMenuEvent() {
    while (SDL_PollEvent(&gameEvent)) {
        switch (gameEvent.type) {
            case SDL_QUIT:
                QuitGame();
                break;
            case SDL_KEYDOWN: 
                switch (gameEvent.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        QuitGame();
                        break;
                    case SDLK_RETURN:
                        gameMenuRunning = false;
                        gameplayRunning = true;
                        break;
                    default:
                        break;
                SDL_ResetKeyboard();
                }
            default:
                break;
        }
    }
}
void RenderMenu() {
    window.clear();
    window.renderBackground(menu);
    window.display();
}
//Gameplay
void InitiateLevel() {
    GameTimerT.changePos(Vector2f(0, 20));
    DeathCountT.changePos(Vector2f());
    GameTimer = window.loadText(GameTimerT, font);
    DeathCounter = window.loadText(DeathCountT, font);
    Bob.setPos(lv[ID].StartingPos);
    Bob.setSize(lv[ID].StartingSize);
    Goal.setPos(lv[ID].GoalPos);
    PlayerVelocity = Vector2f();
    for (Obstacle& i : lv[ID].ObstacleList) {
        if (i.moving) i.setPos(i.getStartingPos());
        if (i.oscillating) {
            i.setPos(i.getStartingPos());
            i.ObsVelocity = i.getStartingVelo();
        }
    }
    Locks = {};
    LevelKeys = lv[ID].KeyList;
    for (Key& i : LevelKeys) {
        Entity locky(lock, Vector2f(i.getLockPos()), Vector2f(i.getLockSize()));
        Locks.push_back(locky);
    }
    gameStart = false;
    startingTime = SDL_GetTicks();
}

void ProcessGameEvent() {
    while (SDL_PollEvent(&gameEvent)) {
        switch (gameEvent.type) {
            case SDL_QUIT:
                QuitGame();
                break;
            case SDL_MOUSEBUTTONDOWN:
                RegisterMousePos();
                PlayerVelocity = velocityAB(Bob.getPos(), MousePos, lv[ID].PlayerLevelSpeed);
                gameStart = true;
                break;
            case SDL_KEYDOWN: 
                switch (gameEvent.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        PauseGame();
                        break;
                    default:
                        break;
                SDL_ResetKeyboard();
                }
            default:
                break;
        }
    }
    //update game
    Bob.move(PlayerVelocity);
    if (gameStart) {
        ProcessObstacles();
    }
    GameTimerI = SDL_GetTicks() - startingTime;
    GameTimerT.changeText("Time : " + std::to_string(GameTimerI) + "ms");
    SDL_DestroyTexture(GameTimer);
    GameTimer = window.loadText(GameTimerT, font);
}

void ProcessObstacles() {
    for (Obstacle& i : lv[ID].ObstacleList) {
        if (i.moving == true) {
            i.move(i.ObsVelocity);
            if (i.reachedEnd()) i.ObsVelocity.invert();
        }
        if (i.oscillating == true) {
            i.move(i.ObsVelocity);
            Vector2f ObsAcceleration = velocityAB(i.getPos(), i.getGravityOrigin(), i.ObsGravity * distanceAB(i.getPos(), i.getGravityOrigin()));
            i.ObsVelocity = i.ObsVelocity + ObsAcceleration;
            }
        }
}

void CollisionCheck() {
    bool Collided = false;
    for (Obstacle& i : lv[ID].ObstacleList) {
        if (Bob.Collided(i)) {
            Collided = true;
            break;
        }
    } 
    for (int i = 0; i < LevelKeys.size(); ++i) {
        if (Bob.Collided(Locks[i])) {
            Collided = true;
            break;
        }
        if (Bob.Collided(LevelKeys[i])) {
            LevelKeys.erase(LevelKeys.begin()+i);
            Locks.erase(Locks.begin()+i);
        }
    }

    //Going out of bound counts as losing
    if (Collided
    ||  Bob.getPos().x + lv[ID].StartingSize.x > SCREEN_WIDTH || Bob.getPos().x < 0
    ||  Bob.getPos().y + lv[ID].StartingSize.y > SCREEN_HEIGHT || Bob.getPos().y < 0) {
        gameLostRunning = true;
        gameplayRunning = false;
        DeathCountI++;
        DeathCountT.changeText("Death Count: " + std::to_string(DeathCountI));

    }
}

void RenderMainGame() {
    window.clear();
    window.renderBackground(bg);
    for (Obstacle& i : lv[ID].ObstacleList) window.renderEntity(i);
    for (Entity& i : LevelKeys) window.renderEntity(i);
    for (Entity& i : Locks) window.renderEntity(i);
    window.renderEntity(Goal);
    window.renderEntity(Bob);
    window.renderText(DeathCounter, DeathCountT);
    window.renderText(GameTimer, GameTimerT);
    window.display();
}

void CheckGameWon() {
    if (Bob.Collided(Goal)) {
        gameplayRunning = false;
        gameWinRunning = true;
        ++ID;
        DeathCountI = 0;
        DeathCountT.changeText("Death Count: " + std::to_string(DeathCountI));
    }
}

void PauseGame() {
    gameplayPausing = true;
    int pauseTotalTimer;
    int pauseInitTimer = SDL_GetTicks();
    while (gameplayPausing) {
        SDL_Delay(50);
        SDL_Rect src = {0, 0, 80, 80};
        SDL_Rect des = {0, 720, 80, 80};
        SDL_RenderCopy(window.getRenderer(), pause.texture, &src, &des);
        window.display();
        SDL_PollEvent(&gameEvent);
        switch (gameEvent.type) {
            case SDL_QUIT:
                QuitGame();
                break;
            case SDL_KEYDOWN:
                if (gameEvent.key.keysym.sym == SDLK_ESCAPE) {
                    gameplayPausing = false;
                    window.clear();
                }
                break;
            default:
                break;
        }
        pauseTotalTimer = SDL_GetTicks() - pauseInitTimer;
    }
    startingTime += pauseTotalTimer;
}

void QuitGame() {
    gameMenuRunning = false;
    gameplayPausing = false;
    gameplayRunning = false;
    gameLostRunning = false;
    gameWinRunning = false;
    gameRunning = false;
}

void RegisterMousePos() {
    MousePos.x = gameEvent.button.x - Bob.getSize().x/2;
    MousePos.y = gameEvent.button.y - Bob.getSize().y/2;
}

//Lose
void RenderGameLostMenu() {
    window.clear();
    window.renderBackground(lost);
    window.display();
}

void ProcessGLMenuEvent() {
    while (SDL_PollEvent(&gameEvent)) {
        switch (gameEvent.type) {
            case SDL_QUIT:
                QuitGame();
                break;
            case SDL_KEYDOWN: 
                switch (gameEvent.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        QuitGame();
                        break;
                    case SDLK_m:
                        gameLostRunning = false;
                        gameMenuRunning = true;
                        ID = 0;
                        DeathCountI = 0;
                        DeathCountT.changeText("Death Count: " + std::to_string(DeathCountI));
                        break;
                    case SDLK_r:
                        gameLostRunning = false;
                        gameplayRunning = true;
                        break;   
                    default:
                        break;
                SDL_ResetKeyboard();
                }
            default:
                break;
        }
    }
}
//Win
void RenderGameWonMenu() {
    window.clear();
    if (ID == LEVEL_NUM) window.renderBackground(victory); else window.renderBackground(win);
    GameTimerT.changePos(Vector2f(400, 270));
    DeathCountT.changePos(Vector2f(400, 300));
    window.renderText(GameTimer, GameTimerT);
    window.renderText(DeathCounter, DeathCountT);
    window.display();
}

void ProcessGWMenuEvent() {
    while (SDL_PollEvent(&gameEvent)) {
        switch (gameEvent.type) {
            case SDL_QUIT:
                QuitGame();
                break;
            case SDL_KEYDOWN: 
                switch (gameEvent.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        QuitGame();
                        break;
                    case SDLK_c:
                        gameWinRunning = false;
                        gameplayRunning = true;
                        break;
                    case SDLK_r:
                        gameWinRunning = false;
                        gameplayRunning = true;
                        --ID;
                        break;   
                    case SDLK_m:
                        gameLostRunning = false;
                        gameMenuRunning = true;
                        ID = 0;
                        DeathCountI = 0;
                        DeathCountT.changeText("Death Count: " + std::to_string(DeathCountI));
                        break;
                    default:
                        break;
                SDL_ResetKeyboard();
                }
            default:
                break;
        }
    }
}
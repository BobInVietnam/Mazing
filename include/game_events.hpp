#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "data.hpp" 

SDL_Event gameEvent;

bool gameRunning = true;

bool gameMenuRunning = true;
void RenderMenu();
void ProcessMenuEvent();

bool gameplayRunning = false;
bool gameplayPausing = false;
void PauseGame();
void QuitGame();
void RegisterMousePos();
void ProcessGameEvent();
void RenderMainGame();
bool AlreadyCollided = false;
void CollisionCheck();
void CheckGameWon();
void InitiateLevel();

bool gameLostRunning = false;
void RenderGameLostMenu();
void ProcessGLMenuEvent();

bool gameWinRunning = false;
void RenderGameWonMenu();
void ProcessGWMenuEvent();

//-------------------------------------------------------------------------------------------------
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
void ProcessGameEvent() {
    while (SDL_PollEvent(&gameEvent)) {
        switch (gameEvent.type) {
            case SDL_QUIT:
                QuitGame();
                break;
            case SDL_MOUSEBUTTONDOWN:
                RegisterMousePos();
                PlayerVelocity = velocityAB(Bob.getPos(), MousePos, lv[ID].PlayerLevelSpeed);
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
    Bob.move(PlayerVelocity);
}


void CollisionCheck() {
    bool Collided = false;
    for (Obstacle i : lv[ID].ObstacleList) {
        if (Bob.Collided(i)) {
            Collided = true;
            break;
        }
    }
    // if (Collided && !AlreadyCollided) {
    //     AlreadyCollided = true;
    //     Bob.changeTex(player_hit);
    // }
    // if (!Collided && AlreadyCollided) {
    //     AlreadyCollided = false;
    //     Bob.changeTex(player);
    // }

    if (Collided) {
        gameLostRunning = true;
        gameplayRunning = false;
    }

    if (Bob.getPos().x + lv[ID].StartingSize.x > SCREEN_WIDTH || Bob.getPos().x < 0
    ||  Bob.getPos().y + lv[ID].StartingSize.y > SCREEN_HEIGHT || Bob.getPos().y < 0) {
        gameLostRunning = true;
        gameplayRunning = false;
    }
}

void RenderMainGame() {
    window.clear();
    window.renderBackground(bg);
    for (Obstacle i : lv[ID].ObstacleList) window.renderEntity(i);
    window.renderEntity(Goal);
    window.renderEntity(Bob);
    window.display();
}

void CheckGameWon() {
    if (Bob.Collided(Goal)) {
        gameplayRunning = false;
        gameWinRunning = true;
        ++ID;
    }
}

void PauseGame() {
    gameplayPausing = true;
    while (gameplayPausing) {
        SDL_Delay(50);
        SDL_PollEvent(&gameEvent);
        switch (gameEvent.type) {
            case SDL_QUIT:
                QuitGame();
                break;
            case SDL_KEYDOWN:
                if (gameEvent.key.keysym.sym == SDLK_ESCAPE) gameplayPausing = false;
                break;
            default:
                break;
        }
    }
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

void InitiateLevel() {
    Bob.setPos(lv[ID].StartingPos);
    Bob.setSize(lv[ID].StartingSize);
    Goal.setPos(lv[ID].GoalPos);
    PlayerVelocity = Vector2f();
}

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

void RenderGameWonMenu() {
    window.clear();
    window.renderBackground(win);
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
                    default:
                        break;
                SDL_ResetKeyboard();
                }
            default:
                break;
        }
    }
}
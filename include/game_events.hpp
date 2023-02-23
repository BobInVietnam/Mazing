#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "levels.hpp" 

SDL_Event gameEvent;

bool gameRunning = true;
bool gamePausing = false;

void PauseGame();
void QuitGame();
void RegisterMousePos();
void ProcessGameEvent();
void RenderMainGame();

bool AlreadyCollided = false;
void CollisionCheck();

bool gameWon = true;
void GameWon();
//-------------------------------------------------------------------------------------------------
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
    if (Collided && !AlreadyCollided) {
        AlreadyCollided = true;
        Bob.changeTex(window.loadTexture("res/thing_oof.png"));
    }
    if (!Collided && AlreadyCollided) {
        AlreadyCollided = false;
        Bob.changeTex(window.loadTexture("res/thing.png"));
    }

    if (Bob.getPos().x + lv[ID].StartingSize.x > SCREEN_WIDTH || Bob.getPos().x < 0
    ||  Bob.getPos().y + lv[ID].StartingSize.y > SCREEN_HEIGHT || Bob.getPos().y < 0) PlayerVelocity = Vector2f(0.0f, 0.0f);
}

void RenderMainGame() {
    window.clear();
    window.renderBackground(bg);
    for (Obstacle i : lv[ID].ObstacleList) window.renderEntity(i);
    window.renderEntity(Goal);
    window.renderEntity(Bob);
    window.display();
}

void GameWon() {
    if (Bob.Collided(Goal)) {
        gameWon = true;
        ++ID;
    }
}

void PauseGame() {
    gamePausing = true;
    while (gamePausing) {
        SDL_Delay(50);
        SDL_PollEvent(&gameEvent);
        switch (gameEvent.type) {
            case SDL_QUIT:
                QuitGame();
                break;
            case SDL_KEYDOWN:
                if (gameEvent.key.keysym.sym == SDLK_ESCAPE) gamePausing = false;
                break;
            default:
                break;
        }
    }
}

void QuitGame() {
    gamePausing = false;
    gameRunning = false;
}

void RegisterMousePos() {
    MousePos.x = gameEvent.button.x - Bob.getSize().x/2;
    MousePos.y = gameEvent.button.y - Bob.getSize().y/2;
}

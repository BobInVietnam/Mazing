#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "render.hpp" 
#include "maths.hpp"
#include "entity.hpp"

SDL_Event gameEvent;


//Window & entities initialization 
renderWindow window("Hello!", SCREEN_WIDTH, SCREEN_HEIGHT);
SDL_Texture* bg = window.loadTexture("res/bg.png");

//Player-related variables
Player Bob(window.loadTexture("res/thing.png"), Vector2f(400, 300), Vector2f(40, 40));
Vector2f MousePos;
Vector2f PlayerVelocity;
int PlayerSpeed = 20;

bool gameRunning = true;
bool gamePausing = false;

void PauseGame();
void QuitGame();
void RegisterMousePos();

void ProcessGameEvent() {
    while (SDL_PollEvent(&gameEvent)) {
        switch (gameEvent.type) {
            case SDL_QUIT:
                QuitGame();
                break;
            case SDL_MOUSEBUTTONDOWN:
                RegisterMousePos();
                PlayerVelocity = velocityAB(Bob.getPos(), MousePos, PlayerSpeed);
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

void PauseGame() {
    gamePausing = true;
    while (gamePausing) {
        SDL_Delay(50);
        SDL_PollEvent(&gameEvent);
        if (gameEvent.type == SDL_KEYDOWN) {
            if (gameEvent.key.keysym.sym == SDLK_ESCAPE) gamePausing = false;
        }
    }
}

void QuitGame() {
    gameRunning = false;
}

void RegisterMousePos() {
    MousePos.x = gameEvent.button.x - PLAYER_SIZE / 2;
    MousePos.y = gameEvent.button.y - PLAYER_SIZE / 2;
}
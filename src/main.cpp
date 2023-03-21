#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <vector>

#include "game_events.hpp"

void AdjustFrameTime(int p_tick);
const int frameRate = 30;
int frameDelay = 1000 / frameRate;

int main(int argc, char* argv[]) {
    //SDL initialization
    if (SDL_Init(SDL_INIT_VIDEO) != 0) 
        std::cout << "SDL_Init HAS FAILED. SDL_ERROR: " << SDL_GetError() << std::endl;
    if (!(IMG_Init(IMG_INIT_PNG))) 
        std::cout << "IMG_Init HAS FAILED. ERROR: " << SDL_GetError() << std::endl;
    if (TTF_Init() != 0) 
        std::cout << "TTF_Init HAS FAILED. ERROR: " << TTF_GetError() << std::endl;
    std::cout << "End of warning..." << std::endl;
    int startTick = 0;
    font = TTF_OpenFont("res/arial.ttf", 48); //I have to load the font here for some reasons. Other places won't work...
//-------------------------------------------------------------------------------------------------
    //Main game loop
    while (gameRunning) {

        while (gameMenuRunning) {
            startTick = SDL_GetTicks();
            ProcessMenuEvent();
            RenderMenu();
            AdjustFrameTime(startTick);
        }

        InitiateLevel();

        while (gameplayRunning) {
            startTick = SDL_GetTicks();
            ProcessGameEvent();
            CollisionCheck();
            RenderMainGame();
            CheckGameWon();
            
            // //debugger
            // std::cout << SDL_GetTicks() << std::endl;
            // std::cout << "MousePos: "; MousePos.print();
            // std::cout << "Bob's Velocity: "; PlayerVelocity.print(); std::cout << std::endl;

            AdjustFrameTime(startTick);
        }

        while (gameLostRunning) {
            startTick = SDL_GetTicks();
            RenderGameLostMenu();
            ProcessGLMenuEvent();
            AdjustFrameTime(startTick);
        }

        while (gameWinRunning) {
            startTick = SDL_GetTicks();
            RenderGameWonMenu();
            ProcessGWMenuEvent();
            AdjustFrameTime(startTick);
        }

        if (ID > LEVEL_NUM)
            QuitGame();
    }
//-------------------------------------------------------------------------------------------------

    window.cleanUp();
    SDL_Quit();
    IMG_Quit();
    TTF_Quit();
    
    return EXIT_SUCCESS;
}  

void AdjustFrameTime(int p_tick) {
    int frameTick = SDL_GetTicks() - p_tick;
    if (frameDelay > frameTick) SDL_Delay(frameDelay - frameTick);
}

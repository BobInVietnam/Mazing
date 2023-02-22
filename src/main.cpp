#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>

#include "game_events.hpp"

void AdjustFrameTime(int p_tick);
const int frameRate = 30;
int frameDelay = 1000 / frameRate;

int main(int argc, char* argv[]) {
    //SDL initialization
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cout << "SDL_Init HAS FAILED. SDL_ERROR: " << SDL_GetError() << std::endl;
    }
    if (!(IMG_Init(IMG_INIT_PNG))) {
        std::cout << "IMG_Init HAS FAILED. ERROR: " << SDL_GetError() << std::endl;
    }
    std::cout << "End of warning..." << std::endl;
//-------------------------------------------------------------------------------------------------
    //Main game loop
    while (gameRunning) {

        int startTick = SDL_GetTicks();
        
        ProcessGameEvent();
        CollisionCheck();

        window.clear();
        window.renderBackground(bg);
        for (Obstacle i : ObsList) window.renderEntity(i);
        window.renderEntity(Goal);
        window.renderEntity(Bob);
        window.display();

        std::cout << SDL_GetTicks() << std::endl;
        std::cout << "MousePos: "; MousePos.print();
        std::cout << "Bob's Velocity: "; PlayerVelocity.print(); std::cout << std::endl;

        AdjustFrameTime(startTick);
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

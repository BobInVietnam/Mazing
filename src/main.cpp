#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>

#include "render.hpp"
#include "game_events.hpp"

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
    const int frameRate = 30;
    int frameDelay = 1000 / frameRate;

    //Main game loop
    while (gameRunning) {

        int startTick = SDL_GetTicks();
        
        ProcessGameEvent();

        window.clear();
        window.renderBackground(bg);
        window.renderEntity(Bob);
        window.display();

        std::cout << SDL_GetTicks() << std::endl;
        std::cout << "MousePos: "; MousePos.print();
        std::cout << "Bob's Velocity: "; PlayerVelocity.print(); std::cout << std::endl;

        int frameTick = SDL_GetTicks() - startTick;
        if (frameDelay > frameTick) SDL_Delay(frameDelay - frameTick);
    }
//-------------------------------------------------------------------------------------------------

    window.cleanUp();
    SDL_Quit();
    
    return EXIT_SUCCESS;
}  
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
    
//--------------------------------------------------------------------------------------------------------
    //Window & entities initialization 
    renderWindow window("Hello!", SCREEN_WIDTH, SCREEN_HEIGHT);

    const int frameRate = 30;
    int frameDelay = 1000 / frameRate;
//--------------------------------------------------------------------------------------------------------
    //Main game loop
    bool gameRunning = true;
    bool gamePausing = false;
    while (gameRunning) {

        window.clear();
        int startTick = SDL_GetTicks();
        while (SDL_PollEvent(&gameEvent)) {
            if (gameEvent.type == SDL_QUIT) {
                gameRunning = false;
                break;
            }
            if (gameEvent.type == SDL_KEYDOWN) {
                switch (gameEvent.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        gamePausing = true;
                        while (gamePausing) {
                            SDL_Delay(50);
                            window.clear();
                            SDL_PollEvent(&gameEvent);
                            if (gameEvent.type == SDL_KEYDOWN) {
                                if (gameEvent.key.keysym.sym == SDLK_ESCAPE) gamePausing = false;
                            }
                            window.display();
                        }
                        break;
                    default:
                        break;
                }
            }
        }
        
        window.renderBackground(window.loadTexture("res/bg.png"));
        window.display();

        std::cout << SDL_GetTicks() << std::endl;

        int frameTick = SDL_GetTicks() - startTick;
        if (frameDelay > frameTick) SDL_Delay(frameDelay - frameTick);
    }

    window.cleanUp();
    SDL_Quit();
    
    return EXIT_SUCCESS;
}  
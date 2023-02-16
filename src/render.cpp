#include "render.hpp"

renderWindow::renderWindow(const char* p_title, int p_w, int p_h) 
    :window(NULL), renderer(NULL)
{
    window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED
                                        , SDL_WINDOWPOS_UNDEFINED, p_w , p_h
                                        , SDL_WINDOW_SHOWN);
    if (NULL == window) {
        std::cout << "Could not create window :(" << SDL_GetError() << std::endl;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_RenderSetLogicalSize(renderer, 800, 800);
}

SDL_Texture* renderWindow::loadTexture(const char* p_filePath) {
    SDL_Texture* texture = NULL;
    texture = IMG_LoadTexture(renderer, p_filePath);

    if (texture == NULL) std::cout << "Failed to load texture. Error: " << SDL_GetError() << std::endl;
    return texture;
}



SDL_Renderer* renderWindow::getRenderer() {
    return renderer;
}

void renderWindow::display() {
    SDL_RenderPresent(renderer);
}
void renderWindow::cleanUp() {
    SDL_DestroyWindow(window);
}
void renderWindow::clear() {
    SDL_RenderClear(renderer);
}


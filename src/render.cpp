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
    //SDL_RenderSetLogicalSize(renderer, 800, 800);
}

SDL_Texture* renderWindow::loadTexture(const char* p_filePath) {
    SDL_Texture* texture = NULL;
    texture = IMG_LoadTexture(renderer, p_filePath);

    if (texture == NULL) std::cout << "Failed to load texture. Error: " << SDL_GetError() << std::endl;
    return texture;
}

void renderWindow::renderBackground(SDL_Texture* p_tex) {
    SDL_Rect src;
    src.x = 0;
    src.y = 0;
    src.w = SCREEN_WIDTH;
    src.h = SCREEN_HEIGHT;
    SDL_Rect des;
    des.x = 0;
    des.y = 0;
    des.w = SCREEN_WIDTH;
    des.h = SCREEN_HEIGHT;
    SDL_RenderCopy(renderer, p_tex, &src, &des);
}
void renderWindow::renderEntity(Entity p_entity) {
    SDL_Rect src;
    src.x = 0;
    src.y = 0;
    src.w = p_entity.getSize().x;
    src.h = p_entity.getSize().y;
    SDL_Rect des;
    des.x = p_entity.getPos().x;
    des.y = p_entity.getPos().y;
    des.w = src.w;
    des.h = src.h;
    SDL_RenderCopy(renderer, p_entity.getTex(), &src, &des);
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


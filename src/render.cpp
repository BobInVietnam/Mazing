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
    //SDL_RenderSetLogicalSize(renderer, 1200, 800);
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
    src.w = p_entity.getTex().size.x;
    src.h = p_entity.getTex().size.y;
    SDL_Rect des;
    des.x = p_entity.getPos().x;
    des.y = p_entity.getPos().y;
    des.w = p_entity.getSize().x;
    des.h = p_entity.getSize().y;
    SDL_RenderCopy(renderer, p_entity.getTex().texture, &src, &des);
}

SDL_Texture* renderWindow::loadText(Text p_text, TTF_Font* p_font) {
    //if (p_font == NULL) std::cout << "FAILED TO LOAD FONT!" << std::endl;
    SDL_Surface* foo = TTF_RenderText_Solid(p_font, p_text.getText(), {0, 0 ,0});
    //if (foo == NULL) std::cout << "FAILED TO LOAD TEXT! ERROR " << SDL_GetError() << std::endl;
    SDL_Texture* tempTexture = SDL_CreateTextureFromSurface(renderer, foo);
    SDL_FreeSurface(foo);
    return tempTexture;
}

void renderWindow::renderText(SDL_Texture* p_tex, Text p_txt) {
    int texW = 0;
    int texH = 0;
    SDL_QueryTexture(p_tex, NULL, NULL, &texW, &texH);
    SDL_Rect des = {(int) p_txt.getPos().x, (int) p_txt.getPos().y, (int) (texW * p_txt.getSize()), (int) (texH * p_txt.getSize())};
    SDL_RenderCopy(renderer, p_tex, NULL, &des);
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

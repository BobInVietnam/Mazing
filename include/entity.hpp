#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "maths.hpp"

class Player
{
private:
    SDL_Texture* texture;
    Vector2f position;
    Vector2f size;
public:
    Player(SDL_Texture* p_tex, Vector2f p_pos, Vector2f p_size);
    
};
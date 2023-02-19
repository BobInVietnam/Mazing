#include "entity.hpp"

Entity::Entity(SDL_Texture* p_tex, Vector2f p_pos, Vector2f p_size)
:texture(p_tex), position(p_pos), size(p_size)
{}

void Entity::move(Vector2f p_velocity) {
    position.x += p_velocity.x;
    position.y += p_velocity.y;
}
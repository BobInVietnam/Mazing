#include "entity.hpp"

Entity::Entity(SDL_Texture* p_tex, Vector2f p_pos, Vector2f p_size)
:texture(p_tex), position(p_pos), size(p_size)
{}

void Entity::move(Vector2f p_velocity) {
    position.x += p_velocity.x;
    position.y += p_velocity.y;
}

void Player::changeTex(SDL_Texture* p_tex) 
{
    texture = NULL;
    texture = p_tex;
}

bool Player::Collided(Obstacle p_obs) {
    if (position.x < p_obs.getPos().x + p_obs.getSize().x
    &&  position.x + size.x > p_obs.getPos().x
    &&  position.y < p_obs.getPos().y + p_obs.getSize().y
    &&  position.y + size.y > p_obs.getPos().y) return true;
    else return false;
}
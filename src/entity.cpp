#include "entity.hpp"

Entity::Entity(Texture p_tex, Vector2f p_pos, Vector2f p_size)
:texture(p_tex), position(p_pos), size(p_size)
{}

Entity::Entity(Texture p_tex)
:texture(p_tex)
{
    position = Vector2f(0,0);
    size = Vector2f(0,0);
}

void Entity::move(Vector2f p_velocity) {
    position.x += p_velocity.x;
    position.y += p_velocity.y;
}

void Player::changeTex(Texture p_tex) 
{
    texture = p_tex;
}

bool Player::Collided(Entity p_entity) {
    if (position.x < p_entity.getPos().x + p_entity.getSize().x
    &&  position.x + size.x > p_entity.getPos().x
    &&  position.y < p_entity.getPos().y + p_entity.getSize().y
    &&  position.y + size.y > p_entity.getPos().y) return true;
    else return false;
}
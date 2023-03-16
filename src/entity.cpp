#include "entity.hpp"

Entity::Entity()
{}

Entity::Entity(Texture p_tex, Vector2f p_pos, Vector2f p_size)
:texture(p_tex), position(p_pos), size(p_size)
{}

Entity::Entity(Texture p_tex)
:texture(p_tex)
{
    position = Vector2f(0,0);
    size = Vector2f(0,0);
}

Obstacle::Obstacle(Texture p_tex, Vector2f p_size, float p_speed, Vector2f p_A, Vector2f p_B)
:ObsSpeed(p_speed), posA(p_A), posB(p_B)
{
    texture = p_tex;
    size = p_size;
    position = p_A;
    ObsVelocity = velocityAB(posA, posB, p_speed);
    moving = true;
}
Obstacle::Obstacle(Texture p_tex, Vector2f p_size, Vector2f p_iniVelo, float p_acc, Vector2f p_origin, Vector2f p_gravOrigin)
:ObsGravity(p_acc), iniVelocity(p_iniVelo), posA(p_origin), posB(p_gravOrigin)
{
    texture = p_tex;
    size = p_size;
    position = p_origin;
    ObsVelocity = iniVelocity;
    oscillating = true;
}

void Entity::move(Vector2f p_velocity) {
    position.x += p_velocity.x;
    position.y += p_velocity.y;
}

bool Obstacle::reachedEnd() {
    if (position.x > (posA.x > posB.x ? posA.x : posB.x) ||
        position.x < (posA.x < posB.x ? posA.x : posB.x) ||
        position.y > (posA.y > posB.y ? posA.y : posB.y) ||
        position.y < (posA.y < posB.y ? posA.y : posB.y)) return true;
    else return false;
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
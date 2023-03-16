#include "maths.hpp"

void Vector2f::print() {
    std::cout << '(' << x << ", " << y << ')' << std::endl;
}
void Vector2f::invert() {
    x = -x;
    y = -y;
}

bool Vector2f::operator== (Vector2f p_vct) {
    return (x == p_vct.x && y == p_vct.y);
}
bool Vector2f::operator!= (Vector2f p_vct) {
    return (!(x == p_vct.x && y == p_vct.y));
}

Vector2f velocityAB(Vector2f p_A, Vector2f p_B, float p_speed) {
    Vector2f velocity;

    float veloX = p_B.x - p_A.x;
    float veloY = p_B.y - p_A.y;
    float veloXY = SDL_sqrt(veloX * veloX + veloY * veloY);

    velocity.x = p_speed * (veloX / veloXY);
    velocity.y = p_speed * (veloY / veloXY);
    return velocity;
}
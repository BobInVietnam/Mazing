#pragma once
#include <SDL2/SDL.h>
#include <iostream>

const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 800;

struct Vector2f
{
    float x, y;
    Vector2f() : x(0.0f), y(0.0f)
    {};
    Vector2f(float p_x, float p_y)
    : x(p_x), y(p_y)
    {};

    void print();
    bool operator == (Vector2f);
};

Vector2f velocityAB(Vector2f p_A, Vector2f p_B, int p_speed);
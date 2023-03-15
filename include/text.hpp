#pragma once
#include "maths.hpp"

class Text {
public:
    Text(const char* p_text, float p_size, Vector2f p_pos);
    void changeText(const char* p_text);
    const char* getText() {return text;}
    float getSize() {return size;}
    Vector2f getPos() {return position;}
private:
    const char* text;
    float size;
    Vector2f position;
};
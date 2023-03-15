#pragma once
#include "maths.hpp"
#include <string>

class Text {
public:
    Text(std::string p_text, float p_size, Vector2f p_pos);
    void changeText(std::string p_text);
    const char* getText() {return text.c_str();}
    float getSize() {return size;}
    Vector2f getPos() {return position;}
private:
    std::string text;
    float size;
    Vector2f position;
};
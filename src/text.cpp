#include "text.hpp"

Text::Text(const char* p_text, float p_size, Vector2f p_pos)
:text(p_text), size(p_size), position(p_pos)
{}

void Text::changeText(const char* p_text) {
    text = p_text;
}
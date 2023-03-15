#include "text.hpp"

Text::Text(std::string p_text, float p_size, Vector2f p_pos)
:text(p_text), size(p_size), position(p_pos)
{}

void Text::changeText(std::string p_text) {
    text = p_text;
}
#include "button.h"

Button::Button(const Rectangle &bounds, const char *text){
    bounds_ = bounds;
    text_ = text;
    enabled_ = false;
    clicked_ = false;
}
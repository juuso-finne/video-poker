#pragma once
#include<raylib.h>
#include <string>

class Button{
    public:
        Button(const Rectangle &bounds, const char *text);
        bool enabled_;
        bool clicked_;
        Rectangle bounds_;
        const char *text_;
    private:
};
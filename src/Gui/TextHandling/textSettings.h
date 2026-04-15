#pragma once
#include <raylib.h>

struct TextSettings{

    TextSettings();
    TextSettings(
        int column_gap,
        int font_size,
        int margin_x,
        int margin_y,
        int padding,
        float text_spacing,
        int row_spacing
    );

    int MeasureWidth(const char* text) const;

    int column_gap_;
    int font_size_;
    int margin_x_;
    int margin_y_;
    int padding_;
    float text_spacing_;
    int row_spacing_;
    Font font_;
};
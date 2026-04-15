#include "textSettings.h"

TextSettings::TextSettings(){
    column_gap_ = 30;
    font_size_ = 30;
    margin_x_ = 10;
    margin_y_ = 10;
    padding_ = 10;
    text_spacing_ = 3;
    row_spacing_ = 5;
    font_ = GetFontDefault();
}

TextSettings::TextSettings(
    int column_gap,
    int font_size,
    int margin_x,
    int margin_y,
    int padding,
    float text_spacing,
    int row_spacing
): TextSettings(){
    column_gap_ = column_gap;
    font_size_ = font_size;
    margin_x_ = margin_x;
    margin_y_ = margin_y;
    padding_ = padding;
    text_spacing_ = text_spacing;
    row_spacing_ = row_spacing;
}

int TextSettings::MeasureWidth(const char *text)
{
    return MeasureTextEx(font_, text, font_size_, text_spacing_).x;
}
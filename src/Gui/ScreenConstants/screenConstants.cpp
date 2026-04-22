#include "ScreenConstants.h"

float ScreenConstants::screen_height_ = 768;
float ScreenConstants::screen_width_ = 1024;

float ScreenConstants::card_sprite_width_ = 75;
float ScreenConstants::card_sprite_height_ = 112;

float ScreenConstants::deal_speed_ = 1000;

float ScreenConstants::card_scaling_ = 1.5;

float ScreenConstants::card_width_ = card_sprite_width_ * card_scaling_;
float ScreenConstants::card_height_ = card_sprite_height_ * card_scaling_;

float ScreenConstants::button_width_ = 128;
float ScreenConstants::button_height_ = 64;
float ScreenConstants::button_gap_ = 20;

Vector2 ScreenConstants::deck_position_ = {25, 125};

std::vector<Vector2> ScreenConstants::GetCardSlots(){

    std::vector<Vector2> output;
    float x_offset = button_gap_ + (button_width_ - card_width_) / 2;
    float y = screen_height_ - 2 * button_height_ - 3 * button_gap_ - card_height_;

    for (int i = 0; i < 5; i++){
        float x = x_offset + i * (button_gap_ + button_width_);
        output.push_back(Vector2{x, y});
    }

    return output;
}

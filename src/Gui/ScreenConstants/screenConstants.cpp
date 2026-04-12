#include "ScreenConstants.h"

float ScreenConstants::screen_height_ = 600;
float ScreenConstants::screen_width_ = 800;

float ScreenConstants::card_width_ = 75;
float ScreenConstants::card_height_ = 112;

Vector2 ScreenConstants::deck_position_ = {25, 25};
Vector2 ScreenConstants::hand_position_ = {25, 300};

std::vector<Vector2> ScreenConstants::GetCardSlots(){

    std::vector<Vector2> output;
    float margin = 45;

    for (int i = 0; i < 5; i++){
        float x = hand_position_.x + i * (margin + card_width_);
        output.push_back(Vector2{x, hand_position_.y});
    }

    return output;
}

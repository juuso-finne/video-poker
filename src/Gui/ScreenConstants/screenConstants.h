#pragma once
#include <raylib.h>
#include<vector>

class ScreenConstants{
    public:
        static float screen_width_;
        static float screen_height_;

        static float deal_speed_;

        static float card_sprite_width_;
        static float card_sprite_height_;

        static float card_scaling_;

        static float card_width_;
        static float card_height_;

        static float button_height_;
        static float button_width_;
        static float button_gap_;

        static Color background_color_;

        static Vector2 deck_position_;
        static Vector2 hand_position_;

        static std::vector<Vector2> GetCardSlots();
};
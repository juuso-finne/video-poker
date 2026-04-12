#pragma once
#include <raylib.h>
#include<vector>

class ScreenConstants{
    public:
        static float screen_width_;
        static float screen_height_;

        static float card_width_;
        static float card_height_;

        static Vector2 deck_position_;
        static Vector2 hand_position_;

        static std::vector<Vector2> GetCardSlots();
};
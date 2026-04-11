#pragma once
#include <memory>

class GameState;


class GameData{
    public:
        static GameState *state_;
        static int bet_;
        static float screenWidth_;
        static float screenHeight_;
};
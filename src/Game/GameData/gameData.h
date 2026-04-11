#pragma once
#include <memory>

class GameState;


class GameData{
    public:
        static GameState *state_;
        static int bet_;
};
#pragma once
#include "../../Card/card.h"
#include<vector>

class GameState;


class GameData{
    public:
        static GameState *state_;

        static int bet_;
        static int current_winnings_;
        static int total_winnings_;
        static int total_bets_;

        static std::vector<Card> player_hand_;
        static bool held_cards_[5];
};
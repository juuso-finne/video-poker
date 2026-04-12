#pragma once
#include <raylib.h>
#include <vector>
#include "card.h"

class Deck{
    public:
        Deck(Vector2 position, int jokers = 0);
        void Shuffle();
        bool IsEmpty();
        void Reset();
        Card DealOne();
        std::vector<Card> DealN(int n);
    private:
        std::vector<Card> cards_;
        Vector2 position_;
        void Generate();
        int jokers_;
};
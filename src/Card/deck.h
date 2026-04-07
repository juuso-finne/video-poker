#pragma once
#include <raylib.h>
#include <vector>
#include "card.h"

class Deck{
    public:
        Deck(Vector2 position, int jokers = 0);
        ~Deck();
        void Shuffle();
        bool isEmpty();
        void Generate(int jokers);
        Card DealOne();
        std::vector<Card> DealN(int n);
    private:
        std::vector<Card> cards_;
        Texture2D spritesheet_;
        Vector2 position_;
};
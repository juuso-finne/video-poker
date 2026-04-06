#pragma once
#include<raylib.h>

enum class Suit{
    kClubs,
    kDiamonds,
    kHearts,
    kSpades,
    kJoker
};

class Card{
    public:
        Card();
        Card(Vector2 position, int rank, Suit suit, const Texture2D &spritesheet, bool is_visible = false);
        void Draw();
        void FaceUp();
        void FaceDown();
    protected:
        bool is_visible_;
        int rank_;
        int suit_index_;
        Suit suit_;
        Vector2 position_;
        Texture2D spritesheet_;
};

class Joker: public Card{
    public:
        Joker(Vector2 position, const Texture2D &spritesheet, bool is_visible = false);
};
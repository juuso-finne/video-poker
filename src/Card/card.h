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
        void Move(const Vector2 &destination, float speed);
        bool IsMoving();
        void Update();
        void UpdateAndDraw();
    protected:
        bool is_visible_;
        bool is_moving_;
        float speed_;
        int rank_;
        int suit_index_;
        Suit suit_;
        Vector2 position_;
        Vector2 destination_;
        Texture2D spritesheet_;
};

class Joker: public Card{
    public:
        Joker(Vector2 position, const Texture2D &spritesheet, bool is_visible = false);
};
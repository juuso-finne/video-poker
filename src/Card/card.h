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
        Card(Vector2 position, int rank, Suit suit, bool is_face_up = false);
        void FaceUp();
        void FaceDown();
        void Move(const Vector2 &destination, float speed);
        bool IsMoving();
        void Update();
        Suit GetSuit();
        int GetRank();
        bool is_face_up_;
        Vector2 GetPosition();
        int GetSuitIndex();
    protected:
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
        Joker(Vector2 position, bool is_face_up = false);
};
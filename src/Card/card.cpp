#include "card.h"
#include "../Gui/gui.h"
#include <stdexcept>
#include <raymath.h>

Card::Card(Vector2 position, int rank, Suit suit, bool is_visible)
{
    bool rank_out_of_bounds = rank < 1 || rank > 13;
    bool is_joker = rank == 14 && suit == Suit::kJoker;

    if(rank_out_of_bounds && !is_joker){
        throw std::invalid_argument("Card.cpp: Card rank must be between 1 and 13 (incl.) for regular cards. 14 for joker");
    }

    position_ = position;
    destination_ = {0,0};
    speed_ = 0;
    is_moving_ = false;
    rank_ = rank;
    suit_ = suit;
    suit_index_ = static_cast<int>(suit);
    is_face_up_ = is_visible;
}

void Card::FaceUp(){
    is_face_up_ = true;
}

void Card::FaceDown(){
    is_face_up_ = false;
}

void Card::Move(const Vector2 &destination, float speed){
    is_moving_ = true;
    destination_ = destination;
    speed_ = speed;
}

bool Card::IsMoving(){
    return is_moving_;
}

void Card::Update(){
    if(is_moving_){
        position_ = Vector2MoveTowards(position_, destination_, GetFrameTime() * speed_);
        is_moving_ = Vector2Equals(position_, destination_) == 0;
    }
}

Suit Card::GetSuit(){
    return suit_;
}

int Card::GetRank(){
    return rank_;
}

Vector2 Card::GetPosition(){
    return position_;
}

int Card::GetSuitIndex(){
    return suit_index_;
}

Joker::Joker(Vector2 position, bool is_visible):
    Card(position, 14, Suit::kJoker, is_visible){}

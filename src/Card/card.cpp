#include "card.h"
#include <stdexcept>
#include <raymath.h>

Card::Card(){
}

Card::Card(Vector2 position, int rank, Suit suit, const Texture2D &spritesheet, bool is_visible)
{

    if(rank < 1 || rank > 13){
        throw std::invalid_argument("Card rank must be between 1 and 13 (incl.)");
    }

    position_ = position;
    destination_ = {0,0};
    speed_ = 0;
    is_moving_ = false;
    rank_ = rank;
    suit_ = suit;
    suit_index_ = static_cast<int>(suit);
    is_visible_ = is_visible;
    spritesheet_ = spritesheet;
}

void Card::Draw(){

    constexpr int kCardWidth = 75;
    constexpr int kCardHeight = 112;

    float x_offset = (is_visible_ ? (float)(rank_ - 1) : 13.0) * kCardWidth;
    float y_offset = (is_visible_ ? (float)suit_index_ : 3.0) * kCardHeight;

    Rectangle source = {x_offset, y_offset, kCardWidth, kCardHeight};

    DrawTextureRec(spritesheet_, source, position_, WHITE);

}

void Card::FaceUp(){
    is_visible_ = true;
}

void Card::FaceDown(){
    is_visible_ = false;
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
        position_ = Vector2MoveTowards(position_, destination_, speed_);
        is_moving_ = Vector2Equals(position_, destination_) == 0;
    }
}

void Card::UpdateAndDraw(){
    Update();
    Draw();
}

Joker::Joker(Vector2 position, const Texture2D &spritesheet, bool is_visible){
    position_ = position;
    rank_ = 14;
    suit_index_ = 0;
    is_visible_ = is_visible;
    spritesheet_ = spritesheet;
}

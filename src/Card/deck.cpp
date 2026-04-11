#include <algorithm>
#include <random>
#include <stdexcept>
#include "deck.h"

Deck::Deck(Vector2 position, int jokers){
    cards_ = std::vector<Card>{};
    spritesheet_ = LoadTexture("assets/graphics/card_spritesheet.png");
    position_ = position;
    jokers_ = jokers;
    Reset();
}

Deck::~Deck(){
    UnloadTexture(spritesheet_);
}

void Deck::Shuffle(){
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(cards_.begin(), cards_.end(), g);
}

bool Deck::IsEmpty(){
    return cards_.empty();
}

void Deck::Reset(){
    Generate();
    Shuffle();
}

void Deck::Generate(){

    cards_.clear();

    std::vector<Suit> suits = {Suit::kClubs, Suit::kDiamonds, Suit::kHearts, Suit::kSpades};

    for (Suit suit : suits){
        for(int rank = 1; rank < 14; rank++){
            cards_.push_back(Card(position_, rank, suit, spritesheet_));
        }
    }

    for (int i = 0; i < jokers_; i++){
        cards_.push_back(Joker(position_, spritesheet_));
    }
}

Card Deck::DealOne(){
    if (cards_.empty()){
        throw std::out_of_range("Attempting to deal a card from empty deck");
    }

    Card output = cards_.back();
    cards_.pop_back();
    return output;
}

std::vector<Card> Deck::DealN(int n){
    std::vector<Card> output{};
    for (int i = 0; i < n; i++){
        if (!cards_.empty()){
            output.push_back(DealOne());
        } else{
            break;
        }
    }
    return output;
}

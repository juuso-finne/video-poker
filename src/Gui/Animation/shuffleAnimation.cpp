#include "animation.h"
#include <random>
#include <raymath.h>
#include "../ScreenConstants/screenConstants.h"

ShuffleAnimation::ShuffleAnimation(){
    timer_ = Timer(1);
}

void ShuffleAnimation::Init(){
    for (int i = 0; i < 10; i++){
        Card c{ScreenConstants::deck_position_, 1, Suit::kClubs};
        animation_cards_.push_back(c);
    }
}

bool ShuffleAnimation::IsPlaying(){

    if (timer_.current_seconds_ > 0){
        return true;
    }

    for (Card c: animation_cards_){
        if (c.IsMoving()){
            return true;
        }
    }
    return false;
}


Vector2 ShuffleAnimation::RandomVector(float max){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, max);

    float x = dis(gen) - max/2;
    float y = dis(gen) - max/2;

    return Vector2{x, y};
}

void ShuffleAnimation::Update(){
    timer_.Tick();

    if(timer_.current_seconds_ <= 0){
        for (Card &c: animation_cards_){
            if(!Vector2Equals(c.GetPosition(), ScreenConstants::deck_position_)){
                c.Move(ScreenConstants::deck_position_, 500);
            }
        }
        return;
    }

    for (Card &c: animation_cards_){
        if(!c.IsMoving()){
            Vector2 target_position = Vector2Add(RandomVector(50), ScreenConstants::deck_position_);
            c.Move(target_position, 500);
        }
    }
}
#include "animation.h"
#include "../../Game/GameData/gameData.h"
#include "../ScreenConstants/screenConstants.h"

DropAnimation::DropAnimation(){
    stagger_timer_ = Timer(0.1);
    std::fill(dropped_cards_, dropped_cards_ + 5, false);
    new_hand_ = {};

    for (int i = 0; i < 5; i++){
        if(GameData::held_cards_[i]){
            new_hand_.push_back(GameData::player_hand_[i]);
        }
    }
}

bool DropAnimation::IsPlaying()
{
    if (!is_initialized_){
        return true;
    }

    for (int i = 0; i < 5; i++){
        if(GameData::player_hand_[i].IsMoving()){
            return true;
        }

        if(GameData::held_cards_[i] == dropped_cards_[i]){
            return true;
        }
    }

    std::fill(GameData::held_cards_, GameData::held_cards_ + 5, false);

    for (int i = 0; i < 5; i++){
        GameData::held_cards_[i] = false;
    }

    GameData::player_hand_ = new_hand_;

    return false;
}

void DropAnimation::Update(){
    stagger_timer_.Tick();

    if(stagger_timer_.current_seconds_ > 0){
        return;
    }


    for (int i = 0; i < 5; i++){

        if(!GameData::held_cards_[i] && !dropped_cards_[i]){
            float x = GameData::player_hand_[i].GetPosition().x;
            float y = ScreenConstants::screen_height_ + ScreenConstants::card_height_;
            GameData::player_hand_[i].Move({x, y}, 1000);
            dropped_cards_[i] = true;
            stagger_timer_.Reset();
            return;
        }
    }
}

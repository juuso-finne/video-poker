#include "animation.h"
#include "../../Game/GameData/gameData.h"
#include "../ScreenConstants/screenConstants.h"

CollectionAnimation::CollectionAnimation(){}

bool CollectionAnimation::IsPlaying()
{
    if (!is_initialized_){
        return true;
    }

    for (Card c: GameData::player_hand_){
        if(c.IsMoving()){
            return true;
        }
    }

    GameData::player_hand_.clear();
    return false;
}

void CollectionAnimation::Init(){
    for (Card &c: GameData::player_hand_){
        c.FaceDown();
        c.Move(ScreenConstants::deck_position_, 500);
    }
}

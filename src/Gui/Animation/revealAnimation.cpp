#include "animation.h"
#include "../../Game/GameData/gameData.h"

RevealAnimation::RevealAnimation(){
    stagger_timer_ = Timer(0.1);
}

bool RevealAnimation::IsPlaying()
{
    if (!is_initialized_){
        return true;
    }

    for (Card c: GameData::player_hand_){
        if(!c.is_face_up_){
            return true;
        }
    }

    return false;
}

void RevealAnimation::Update(){
    stagger_timer_.Tick();

    if(stagger_timer_.current_seconds_ > 0){
        return;
    }

    for (Card &c: GameData::player_hand_){
        if(!c.is_face_up_){
            c.FaceUp();
            stagger_timer_.Reset();
            return;
        }
    }
}

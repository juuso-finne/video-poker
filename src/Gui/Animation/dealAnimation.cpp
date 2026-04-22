#include "animation.h"
#include "../../Game/GameData/gameData.h"
#include "../ScreenConstants/screenConstants.h"

DealAnimation::DealAnimation(){
    positions_ = ScreenConstants::GetCardSlots();
}

DealAnimation::DealAnimation(const std::vector<Vector2> &positions)
{
    positions_ = positions;
}

bool DealAnimation::IsPlaying()
{
    if (!is_initialized_){
        return true;
    }

    for (Card c: GameData::player_hand_){
        if(c.IsMoving()){
            return true;
        }
    }

    return false;
}

void DealAnimation::Init(){
    for(Vector2 position: positions_){
        Card card = GameData::deck_.DealOne();
        card.Move(position, ScreenConstants::deal_speed_);
        GameData::player_hand_.push_back(card);
    }
}

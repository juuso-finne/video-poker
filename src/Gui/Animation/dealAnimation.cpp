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
    if (!is_initialized_ || current_position_ < positions_.size()){
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
    stagger_timer_ = Timer(0.1);
    current_position_ = 0;
}

void DealAnimation::Update(){
    stagger_timer_.Tick();

    if (stagger_timer_.current_seconds_ > 0 || current_position_ >= positions_.size()){
        return;
    }

    stagger_timer_.Reset();
    Card card = GameData::deck_.DealOne();
    card.Move(positions_[current_position_], ScreenConstants::deal_speed_);
    GameData::player_hand_.push_back(card);

    current_position_++;
}

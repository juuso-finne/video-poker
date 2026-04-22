#include "../gameState.h"
#include "../../GameData/gameData.h"
#include "../../GameRules/gameRules.h"

DrawState DrawState::draw_state_;
DrawState::DrawState(){}
DrawState *DrawState::Instance(){ return &draw_state_; }

void DrawState::Init(){
    for (HoldButton &b: ButtonManager::hold_buttons_){
        b.enabled_ = true;
    }
    ButtonManager::deal_button_.enabled_ = true;
}

void DrawState::Deal(){
    std::vector<Vector2> positions;

    for (int i = 0; i < 5; i++){
        if(!GameData::held_cards_[i]){
            positions.push_back(GameData::player_hand_[i].GetPosition());
        }
    }

    Gui::animations_.push(std::make_shared<DropAnimation>());
    Gui::animations_.push(std::make_shared<DealAnimation>(positions));
    Gui::animations_.push(std::make_shared<RevealAnimation>());

    ChangeState(EvaluationState::Instance());
}

void DrawState::Hold(int index){
    GameData::held_cards_[index] = !GameData::held_cards_[index];
}



#include "../gameState.h"
#include <iostream>
#include "../../GameData/gameData.h"
#include "../../../Gui/gui.h"

InitialState InitialState::initial_state_;
InitialState::InitialState(){}
InitialState *InitialState::Instance() { return &initial_state_; }

void InitialState::Init(){
    ButtonManager::deal_button_.enabled_ = true;
    ButtonManager::bet_button_.enabled_ = true;
}

void InitialState::Deal(){
    std::vector<Vector2> card_slots = ScreenConstants::GetCardSlots();
    GameData::player_hand_ = GameData::deck_.DealN(5);
    for(int i = 0; i < 5; i++){
        GameData::player_hand_[i].FaceUp();
        GameData::player_hand_[i].Move(card_slots[i], 500);
    }
    ChangeState(DrawState::Instance());
}

void InitialState::Bet(){
    std::cout << "Bet Increase" << std::endl;
}



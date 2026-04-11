#include "../gameState.h"
#include <iostream>
#include "../../GameData/gameData.h"

DoubleState DoubleState::double_state_;
DoubleState::DoubleState(){}
DoubleState *DoubleState::Instance(){ return &double_state_; }

void DoubleState::Init(){
    Gui::DisableButtons;
    Gui::small_button_.enabled_ = true;
    Gui::big_button_.enabled_ = true;
}

void DoubleState::Big(){
    std::cout << "Big" << std::endl;
    GameData::state_ = InitialState::Instance();
}

void DoubleState::Small(){
    std::cout << "Small" << std::endl;
    GameData::state_ = InitialState::Instance();
}
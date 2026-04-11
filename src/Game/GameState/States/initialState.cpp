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
    std::cout << "DEAL (initial state)" << std::endl;
    ChangeState(DrawState::Instance());
}

void InitialState::Bet(){
    std::cout << "Bet Increase" << std::endl;
}



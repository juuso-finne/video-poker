#include "../gameState.h"
#include <iostream>
#include "../../GameData/gameData.h"
# include "../../../Gui/gui.h"

InitialState InitialState::initial_state_;
InitialState::InitialState(){}

void InitialState::Init(){
    Gui::DisableButtons();
    Gui::deal_button_.enabled_ = true;
    Gui::bet_button_.enabled_ = true;
}

void InitialState::Deal(){
    std::cout << "DEAL (initial state)" << std::endl;
    GameData::state_ = DrawState::Instance();
}

void InitialState::Bet(){
    std::cout << "Bet Increase" << std::endl;
}

InitialState *InitialState::Instance()
{
    return &initial_state_;
}

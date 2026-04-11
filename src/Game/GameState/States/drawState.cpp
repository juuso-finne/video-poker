#include "../gameState.h"
#include <iostream>
#include "../../GameData/gameData.h"

DrawState DrawState::draw_state_;
DrawState::DrawState(){}
DrawState *DrawState::Instance(){ return &draw_state_; }

void DrawState::Init(){
    Gui::DisableButtons();
    for (HoldButton &b: Gui::hold_buttons_){
        b.enabled_ = true;
    }
    Gui::deal_button_.enabled_ = true;
}

void DrawState::Deal(){
    std::cout << "DEAL (draw state)" << std::endl;
    GameData::state_ = WinState::Instance();
}

void DrawState::Hold(int index){
    std::cout << "HOLD " << index << std::endl;
}



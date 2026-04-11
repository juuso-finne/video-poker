#include "../gameState.h"
#include <iostream>
#include "../../GameData/gameData.h"


WinState::WinState(){}
WinState WinState::win_state_;
WinState *WinState::Instance(){ return &win_state_;}

void WinState::Init(){
    Gui::cash_out_button_.enabled_ = true;
    Gui::double_button_.enabled_ = true;
}

void WinState::Double(){
    std::cout << "Double" << std::endl;
    ChangeState(DoubleState::Instance());
}

void WinState::CashOut(){
    std::cout << "Cash out" << std::endl;
    ChangeState(InitialState::Instance());
}
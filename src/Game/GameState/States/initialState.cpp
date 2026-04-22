#include "../gameState.h"
#include <iostream>
#include "../../GameData/gameData.h"
#include "../../../Gui/gui.h"

InitialState InitialState::initial_state_;
InitialState::InitialState(){}
InitialState *InitialState::Instance() { return &initial_state_; }

void InitialState::Init(){
    GameData::current_winnings_ = 0;
    ButtonManager::deal_button_.enabled_ = true;
    ButtonManager::bet_button_.enabled_ = true;
}

void InitialState::Deal(){
    Reset();
    Gui::animations_.push(std::make_shared<ShuffleAnimation>());
    Gui::animations_.push(std::make_shared<DealAnimation>());
    Gui::animations_.push(std::make_shared<RevealAnimation>());
    GameData::total_bets_ += GameData::bet_;
    ChangeState(DrawState::Instance());
}

void InitialState::Bet(){
    GameData::bet_ += 20;
    if(GameData::bet_ > 100){
        GameData::bet_ = 20;
    }
    std::cout << "Current bet: " << GameData::bet_ << std::endl;
}



#include "../gameState.h"
#include <iostream>
#include "../../GameData/gameData.h"


WinState::WinState(){}
WinState WinState::win_state_;
WinState *WinState::Instance(){ return &win_state_;}

void WinState::Init(){
    ButtonManager::cash_out_button_.enabled_ = true;
    ButtonManager::double_button_.enabled_ = true;
}

void WinState::Double(){

    GameData::player_hand_.clear();
    GameData::deck_.Reset();

    Card card = GameData::deck_.DealOne();
    float y = ScreenConstants::hand_position_.y;
    float x = (ScreenConstants::screen_width_ - ScreenConstants::card_width_) / 2;
    std::cout << "Cheat: " << card.GetRank() << std::endl;
    card.Move({x, y}, 500);
    GameData::player_hand_.push_back(card);

    ChangeState(DoubleState::Instance());
}

void WinState::CashOut(){
    GameData::total_winnings_ += GameData::current_winnings_;
    std::cout
        << "Collected: " << GameData::current_winnings_ << std::endl
        << "Total winnings: " << GameData::total_winnings_ << std::endl
        << "Total bets: " << GameData::total_bets_ << std::endl
        << "Net profit: " << GameData::total_winnings_ - GameData::total_bets_ << std::endl;
    ChangeState(InitialState::Instance());
}
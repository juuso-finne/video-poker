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

    GameData::deck_.Reset();

    float y = ScreenConstants::GetCardSlots()[0].y;
    float x = (ScreenConstants::screen_width_ - ScreenConstants::card_width_) / 2;

    Gui::animations_.push(std::make_shared<TransferToCurrentWinningsAnimation>(GameData::current_winnings_));
    Gui::animations_.push(std::make_shared<CollectionAnimation>());
    Gui::animations_.push(std::make_shared<ShuffleAnimation>());
    Gui::animations_.push(std::make_shared<DealAnimation>(std::vector<Vector2>{{x, y}}));

    ChangeState(DoubleState::Instance());
}

void WinState::CashOut(){
    Gui::animations_.push(std::make_shared<TransferToTotalWinnings>(GameData::current_winnings_));

    std::cout
        << "Collected: " << GameData::current_winnings_ << std::endl
        << "Total winnings: " << GameData::total_winnings_ << std::endl
        << "Total bets: " << GameData::total_bets_ << std::endl
        << "Net profit: " << GameData::total_winnings_ - GameData::total_bets_ << std::endl;
    ChangeState(InitialState::Instance());
}
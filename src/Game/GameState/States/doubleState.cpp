#include "../gameState.h"
#include <iostream>
#include "../../GameData/gameData.h"

DoubleState DoubleState::double_state_;
DoubleState::DoubleState(){}
DoubleState *DoubleState::Instance(){ return &double_state_; }

void DoubleState::Init(){
    ButtonManager::small_button_.enabled_ = true;
    ButtonManager::big_button_.enabled_ = true;
}

void DoubleState::Resolve(bool success){
    Gui::animations_.push(std::make_shared<RevealAnimation>());
    GameData::player_hand_[0].FaceUp();
    int rank = GameData::player_hand_[0].GetRank();

    if (rank == 14){ //joker
        Win();
        return;
    }

    if(rank == 7){
        ResolveSeven();
        return;
    }

    if (success){
        Win();
        return;
    }

    Lose();
}

void DoubleState::Big(){
    Resolve(GameData::player_hand_[0].GetRank() > 7);
}

void DoubleState::Small(){
    Resolve(GameData::player_hand_[0].GetRank() < 7);
}

void DoubleState::Win(){
    GameData::current_winnings_ *= 2;
    std::cout << "You won " << GameData::current_winnings_ << "!" << std::endl;

    if(GameData::current_winnings_ >= 10000){
        std::cout << "Maximum doubling reached." << std::endl;
        GameData::total_winnings_ += GameData::current_winnings_;
        std::cout << "Total winnings: " << GameData::total_winnings_ << std::endl
        << "Total bets: " << GameData::total_bets_ << std::endl
        << "Net profit: " << GameData::total_winnings_ - GameData::total_bets_ << std::endl;
        ChangeState(InitialState::Instance());
        return;
    }

    std::cout << "Do you want to double?" << std::endl;
    ChangeState(WinState::Instance());
}

void DoubleState::Lose(){
    std::cout
        << "No win! Total winnings: " << GameData::total_winnings_ << std::endl
        << "Total bets: " << GameData::total_bets_ << std::endl
        << "Net profit: " << GameData::total_winnings_ - GameData::total_bets_ << std::endl;

    ChangeState(InitialState::Instance());
}

void DoubleState::ResolveSeven(){
    Suit suit = GameData::player_hand_[0].GetSuit();

    if( suit == Suit::kDiamonds || suit == Suit::kHearts){
        GameData::total_winnings_ += GameData::current_winnings_;
    }

    Lose();
}
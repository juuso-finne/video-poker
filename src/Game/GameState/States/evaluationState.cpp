#include "../gameState.h"
#include <iostream>
#include "../../GameData/gameData.h"
#include "../../GameRules/gameRules.h"

EvaluationState::EvaluationState(){}
EvaluationState EvaluationState::evaluation_state_;

EvaluationState *EvaluationState::Instance()
{
    return &evaluation_state_;
}

void EvaluationState::Init(){

    HandValue value = EvaluateHand(GameData::player_hand_);
    int coefficient = payout_table[value];

    if(coefficient == 0){
        std::cout
            << "No win! Total winnings: " << GameData::total_winnings_ << std::endl
            << "Total bets: " << GameData::total_bets_ << std::endl
            << "Net profit: " << GameData::total_winnings_ - GameData::total_bets_ << std::endl;
        ChangeState(InitialState::Instance());
    } else{
        GameData::current_winnings_ = coefficient * GameData::bet_;
        std::cout << "You won " << GameData::current_winnings_ << "! Do you want to double?" << std::endl;
        ChangeState(WinState::Instance());
    }
}
#include "../gameState.h"
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
        ChangeState(InitialState::Instance());
    } else{

        int winning_sum = coefficient * GameData::bet_;
        Gui::animations_.push(std::make_shared<TransferToCurrentWinningsAnimation>(winning_sum));

        ChangeState(WinState::Instance());
    }
}
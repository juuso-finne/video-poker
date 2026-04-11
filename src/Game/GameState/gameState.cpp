#include "gameState.h"
#include "../GameData/gameData.h"

void GameState::Deal(){}
void GameState::Bet(){}
void GameState::Hold(int index){}
void GameState::CashOut(){}
void GameState::Double(){}
void GameState::Small(){}
void GameState::Big(){}

GameState::GameState(){}

void GameState::ChangeState(GameState *new_state){
    ButtonManager::DisableButtons();
    GameData::state_ = new_state;
}

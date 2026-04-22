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
    state_changed_ = true;
    ButtonManager::DisableButtons();
    GameData::state_ = new_state;
}

void GameState::Reset(){
    GameData::deck_.Reset();
    Gui::animations_.push(std::make_shared<CollectionAnimation>());
}

bool GameState::state_changed_ = true;

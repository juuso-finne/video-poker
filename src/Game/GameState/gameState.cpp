#include "gameState.h"

GameState::GameState(){}

void GameState::DealButtonClick() {}
bool GameState::DealButtonEnabled(){ return false; }

bool GameState::BetButtonEnabled(){ return false; }
void GameState::BetButtonClick(){}

bool GameState::HoldButtonEnabled(){ return false; }
void GameState::HoldButtonClick(int index) {}

bool GameState::CashOutButtonEnabled(){ return false; }
void GameState::CashOutButtonClick(){}

bool GameState::DoubleButtonEnabled(){ return false; }
void GameState::DoubleButtonClick(){}

bool GameState::SmallButtonEnabled(){ return false; }
void GameState::SmallButtonClick(){}

bool GameState::BigButtonEnabled(){ return false; }
void GameState::BigButtonClick(){}

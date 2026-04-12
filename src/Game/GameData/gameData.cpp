#include "gameData.h"
#include "../GameState/gameState.h"

int GameData::bet_ = 20;
int GameData::current_winnings_ = 0;
int GameData::total_winnings_ = 0;
int GameData::total_bets_ = 0;

bool GameData::held_cards_[5];

Deck GameData::deck_{ScreenConstants::deck_position_, 1};
std::vector<Card> GameData::player_hand_;
GameState* GameData::state_ = InitialState::Instance();
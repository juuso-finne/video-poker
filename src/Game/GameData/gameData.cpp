#include "gameData.h"
#include "../GameState/gameState.h"

int GameData::bet_ = 1;
GameState* GameData::state_ = InitialState::Instance();
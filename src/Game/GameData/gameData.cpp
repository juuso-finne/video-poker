#include "gameData.h"
#include "../GameState/gameState.h"

int GameData::bet_ = 1;
GameState* GameData::state_ = InitialState::Instance();
float GameData::screenHeight_ = 600;
float GameData::screenWidth_ = 800;
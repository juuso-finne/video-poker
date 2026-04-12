#include "gui.h"
#include "../Game/GameData/gameData.h"

void Gui::Update(){
    ButtonManager::DrawButtons();
    for (Card card: GameData::player_hand_){
        card.UpdateAndDraw();
    }
}

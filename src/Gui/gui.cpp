#include "gui.h"
#include "../Game/GameData/gameData.h"

void Gui::Update(const Texture2D &spritesheet){
    ButtonManager::DrawButtons();
    for (Card &card: GameData::player_hand_){
        UpdateAndDrawCard(spritesheet, card);
    }
}

void Gui::UpdateAndDrawCard(const Texture2D &spritesheet, Card &card){
    card.Update();

    float card_width = ScreenConstants::card_width_;
    float card_height = ScreenConstants::card_height_;

    float x_offset = (card.is_face_up_ ? (float)(card.GetRank() - 1) : 13.0) * card_width;
    float y_offset = (card.is_face_up_ ? (float)card.GetSuitIndex() : 3.0) * card_height;

    Rectangle source = {x_offset, y_offset, card_width, card_height};

    DrawTextureRec(spritesheet, source, card.GetPosition(), WHITE);
}

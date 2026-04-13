#include "gui.h"
#include "../Game/GameData/gameData.h"
#include <raymath.h>
#include <iostream>
#include <raygui.h>

std::queue<std::shared_ptr<Animation>> Gui::animations_;
bool Gui::animation_playing_ = false;

void Gui::Update(const Texture2D &spritesheet){

    PlayAnimations();
    DrawDeck(spritesheet);

    PrintPayouts(30);

    for(Card &card: Animation::animation_cards_){
        UpdateAndDrawCard(spritesheet, card);
    }

    for (Card &card: GameData::player_hand_){
        UpdateAndDrawCard(spritesheet, card);
    }

    ButtonManager::DrawButtons();
}

void Gui::PlayAnimations(){

    animation_playing_ = false;

    while(!animations_.empty()){

        std::shared_ptr<Animation> animation = animations_.front();
        animation_playing_ = animation -> IsPlaying();

        if (animation_playing_){
            animation -> Play();
            return;
        } else{
            animations_.pop();
        }
    }

    Animation::animation_cards_.clear();
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

void Gui::DrawDeck(const Texture2D &spritesheet){
    float margin = 2;
    Vector2 position = GameData::deck_.GetPosition();
    for(int i = 10; i >= 0; i--){
        Vector2 offset = {i * margin, i * margin};
        Card c = {Vector2Add(position, offset), 1, Suit::kClubs};
        UpdateAndDrawCard(spritesheet, c);
    }
}

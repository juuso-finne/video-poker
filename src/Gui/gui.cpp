#include "gui.h"
#include "../Game/GameData/gameData.h"
#include <raymath.h>
#include <raygui.h>

std::queue<std::shared_ptr<Animation>> Gui::animations_;
bool Gui::animation_playing_ = false;

void Gui::Update(const Texture2D &spritesheet){

    PlayAnimations();
    DrawDeck(spritesheet);

    PrintTexts();

    for(Card &card: Animation::animation_cards_){
        UpdateAndDrawCard(spritesheet, card);
    }

    for (Card &card: GameData::player_hand_){
        UpdateAndDrawCard(spritesheet, card);
    }

    DrawHoldIndicators();

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

void UpdateAndDrawCard(const Texture2D &spritesheet, Card &card){
    card.Update();

    float sprite_width = ScreenConstants::card_sprite_width_;
    float sprite_height = ScreenConstants::card_sprite_height_;

    float x_offset = (card.is_face_up_ ? (float)(card.GetRank() - 1) : 13.0) * sprite_width;
    float y_offset = (card.is_face_up_ ? (float)card.GetSuitIndex() : 3.0) * sprite_height;

    Rectangle source = {x_offset, y_offset, sprite_width, sprite_height};

    float card_width = ScreenConstants::card_width_;
    float card_height = ScreenConstants::card_height_;

    float x = card.GetPosition().x;
    float y = card.GetPosition().y;

    Rectangle dest = {x, y, card_width, card_height};

    DrawTexturePro(spritesheet, source, dest, {0,0}, 0, WHITE);
}

void DrawDeck(const Texture2D &spritesheet){
    float margin = 2;
    Vector2 position = GameData::deck_.GetPosition();
    for(int i = 10; i >= 0; i--){
        Vector2 offset = {i * margin, i * margin};
        Card c = {Vector2Add(position, offset), 1, Suit::kClubs};
        UpdateAndDrawCard(spritesheet, c);
    }
}

void DrawHoldIndicators(int font_size){

    int height = 30;
    int width = ScreenConstants::card_width_;
    std::vector<Vector2> positions = ScreenConstants::GetCardSlots();

    float text_width = MeasureText("HOLD", font_size);

    Vector2 origin = {text_width/2, (float)font_size/2};


    for(int i = 0; i < 5; i++){
        if(!GameData::held_cards_[i]){
            continue;
        }

        Vector2 position = positions[i];

        int x = position.x;
        int y = position.y + (ScreenConstants::card_height_ - height) / 2;

        DrawRectangle(x, y, width, height, Color{0, 0, 0, 192});
        DrawTextPro(GetFontDefault(), "HOLD", {(float)x + width/2, y + (float)height/2}, origin, 0, font_size, 1, RED);
    }
}

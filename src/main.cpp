#include <raylib.h>
#include "Gui/gui.h"
#include "Game/GameData/gameData.h"
#include "Game/GameState/gameState.h"
#include "Audio/audioManager.h"

int main()
{

    InitWindow(ScreenConstants::screen_width_, ScreenConstants::screen_height_, "Video poker");
    Texture2D card_sprite_sheet = LoadTexture("assets/graphics/card_spritesheet.png");

    LoadSounds();
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        UpdateMusic();

        BeginDrawing();
        ClearBackground(ScreenConstants::background_color_);

        Gui::Update(card_sprite_sheet);

        if(Gui::animations_.empty() && GameState::state_changed_){
            GameState::state_changed_ = false;
            GameData::state_ -> Init();
        }

        EndDrawing();
    }

    UnloadTexture(card_sprite_sheet);
    UnloadSounds();

    CloseWindow();
}
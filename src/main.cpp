#include <raylib.h>
#include "Card/deck.h"
#include "Gui/gui.h"
#include "Game/GameData/gameData.h"
#include "Game/GameState/gameState.h"
#include "Game/GameRules/gameRules.h"
#include <memory>


int main()
{

/*     float delay = 0.25;
    std::vector<Card> cards{}; */

    InitWindow(ScreenConstants::screen_width_, ScreenConstants::screen_height_, "Video poker");
    Texture2D card_sprite_sheet = LoadTexture("assets/graphics/card_spritesheet.png");





    SetTargetFPS(60);


    while (!WindowShouldClose())
    {

/*         delay -= GetFrameTime();
        if(delay < 0 ){
            delay = 0.5;
            if(deck.IsEmpty()){
                delay = 1;
                deck.Reset();
            }
            Card c = deck.DealOne();
            c.FaceUp();
            c.Move({775, 300}, GetFrameTime() * 250);
            cards.push_back(c);
        } */


        BeginDrawing();
        ClearBackground(BLACK);
        GameData::state_ -> Init();
        Gui::Update(card_sprite_sheet);


/*         for (std::vector<Card>::iterator it = cards.begin(); it != cards.end();)
        {
            if (!(*it).IsMoving()){
                it = cards.erase(it);
            }
            else{
                (*it).UpdateAndDraw();
                ++it;
            }
        }

 */
        EndDrawing();
    }

    UnloadTexture(card_sprite_sheet);

    CloseWindow();
}
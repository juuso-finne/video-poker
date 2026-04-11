#include <raylib.h>
#include "Card/deck.h"
#include "Game/GameData/gameData.h"
#include "Game/GameState/gameState.h"
#include <memory>


int main()
{

    //float delay = 0.25;
    std::vector<Card> cards{};

    InitWindow(GameData::screenWidth_, GameData::screenHeight_, "Video poker");
    //Deck deck = {{-75, 300}, 1};
     /*
    DealButton deal{&state};
    BetButton bet{&state}; */

    SetTargetFPS(60);


    while (!WindowShouldClose())
    {
        /*
        delay -= GetFrameTime();
        if(delay < 0 && !deck.isEmpty()){
            delay = 0.25;
            Card c = deck.DealOne();
            c.FaceUp();
            c.Move({775, 300}, 5);
            cards.push_back(c);
        }

        */
        BeginDrawing();
        ClearBackground(BLACK);
        GameData::state_->Init();
        Gui::DrawButtons();

        /*
        for (std::vector<Card>::iterator it = cards.begin(); it != cards.end();)
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

    CloseWindow();
}
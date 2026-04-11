#include <raylib.h>
#include "Card/deck.h"
#include "Gui/gui.h"
#include "Game/GameData/gameData.h"
#include "Game/GameState/gameState.h"
#include <memory>


int main()
{

    float delay = 0.25;
    std::vector<Card> cards{};

    InitWindow(Gui::screenWidth_, Gui::screenHeight_, "Video poker");
    Deck deck = {{-75, 300}, 1};

    SetTargetFPS(60);


    while (!WindowShouldClose())
    {

        delay -= GetFrameTime();
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
        }


        BeginDrawing();
        ClearBackground(BLACK);
        GameData::state_ -> Init();
        ButtonManager::DrawButtons();


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

        EndDrawing();
    }

    CloseWindow();
}
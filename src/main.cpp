#include <raylib.h>
#include"Card/deck.h"

int main()
{
    constexpr int screenWidth = 800;
    constexpr int screenHeight = 600;

    float delay = 0.25;
    std::vector<Card> cards{};

    InitWindow(screenWidth, screenHeight, "Video poker");
    Deck deck = {{-75, 300}, 1};
    SetTargetFPS(60);



    while (!WindowShouldClose())
    {
        delay -= GetFrameTime();
        if(delay < 0 && !deck.isEmpty()){
            delay = 0.25;
            Card c = deck.DealOne();
            c.FaceUp();
            c.Move({775, 300}, 5);
            cards.push_back(c);
        }

        BeginDrawing();
        ClearBackground(BLACK);
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
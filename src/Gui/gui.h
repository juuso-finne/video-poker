#pragma once
#include <vector>
#include "ButtonManager/buttonManager.h"
#include "ScreenConstants/screenConstants.h"
#include "../Card/card.h"


class Gui{
    public:
        static void Update(const Texture2D &spritesheet);
    private:
        static void UpdateAndDrawCard(const Texture2D &spritesheet, Card &card);
        static void DrawDeck(const Texture2D &spritesheet);
};
#pragma once
#include <queue>
#include "ButtonManager/buttonManager.h"
#include "ScreenConstants/screenConstants.h"
#include "Animation/animation.h"
#include "TextHandling/textHandling.h"
#include "../Card/card.h"
#include "../Game/GameRules/gameRules.h"
#include <memory>


class Gui{
    public:
        static bool animation_playing_;
        static std::queue<std::shared_ptr<Animation>> animations_;
        static void Update(const Texture2D &spritesheet);

    private:
        static void PlayAnimations();
};

const char *ConvertToDecimal(int value);

void UpdateAndDrawCard(const Texture2D &spritesheet, Card &card);
void DrawDeck(const Texture2D &spritesheet);
void DrawHoldIndicators(int font_size = 12);

std::vector<std::pair<const char*, HandValue>> GetNameValuePairs();
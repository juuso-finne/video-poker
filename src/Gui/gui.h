#pragma once
#include <queue>
#include "ButtonManager/buttonManager.h"
#include "ScreenConstants/screenConstants.h"
#include "Animation/animation.h"
#include "../Card/card.h"
#include <memory>
#include "../Game/GameRules/gameRules.h"


class Gui{
    public:
        static bool animation_playing_;
        static std::queue<std::shared_ptr<Animation>> animations_;
        static void Update(const Texture2D &spritesheet);

    private:
        static void UpdateAndDrawCard(const Texture2D &spritesheet, Card &card);
        static void DrawDeck(const Texture2D &spritesheet);
        static void PlayAnimations();
};

const char *ConvertToDecimal(int value);

void PrintPayouts(int margin = 10, int font_size = 24);
std::vector<std::pair<const char*, HandValue>> GetNameValuePairs();
void ConstructColums(std::string &name_column, std::string &value_column);
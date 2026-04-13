#pragma once
#include <queue>
#include "ButtonManager/buttonManager.h"
#include "ScreenConstants/screenConstants.h"
#include "Animation/animation.h"
#include "../Card/card.h"
#include <memory>


class Gui{
    public:
        static bool animation_playing_;
        static std::queue<std::shared_ptr<Animation>> animations_;

        static void Update(const Texture2D &spritesheet);
        static void PlayAnimations();
    private:
        static void UpdateAndDrawCard(const Texture2D &spritesheet, Card &card);
        static void DrawDeck(const Texture2D &spritesheet);
};
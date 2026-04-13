#pragma once
#include "../../Timer/timer.h"
#include <vector>
#include "../../Card/card.h"

class Animation{
    public:
        static std::vector<Card> animation_cards_;
        Animation();

        virtual bool IsPlaying() = 0;
        virtual void Play();
        virtual void Init();
        virtual void Update();

        bool is_initialized_;
};

class ShuffleAnimation: public Animation{
    public:
        ShuffleAnimation();
        void Init() override;
        bool IsPlaying() override;
        void Update() override;
        Vector2 RandomVector(float max = 10);
    private:
        Timer timer_;
};

class DealAnimation: public Animation{
    public:
        DealAnimation();
        DealAnimation(const std::vector<Vector2> &positions);
        bool IsPlaying() override;
        void Init() override;
    private:
        std::vector<Vector2> positions_;
};

class RevealAnimation: public Animation{
    public:
        RevealAnimation();
        bool IsPlaying() override;
        void Update() override;

    private:
        Timer stagger_timer_;
};
#pragma once
#include<raylib.h>
#include <string>
#include <map>
#include <vector>
#include "../Game/GameState/gameState.h"
#include <memory>

enum class ButtonType{
    kDeal,
    kBet,
    kHold,
    kCashOut,
    kDouble,
    kSmall,
    kBig
};

class Button{
    public:
        Button(std::shared_ptr<GameState> game_state);
        virtual void OnClick();
        std::shared_ptr<GameState> game_state_;
        Rectangle bounds_;
        const char *text_;
        bool enabled_;
    protected:
        float width_;
        float height_;
        int padding_;
};

class DealButton: public Button{
    public:
        DealButton(std::shared_ptr<GameState> game_state);
        void OnClick() override;
};

class BetButton: public Button{
    public:
        BetButton(std::shared_ptr<GameState> game_state);
        void OnClick() override;
};

class HoldButton: public Button{
    public:
        HoldButton(int index, std::shared_ptr<GameState> game_state);
        int GetIndex();
    private:
        int index_;
};

class CashOutButton: public Button{
    public:
        CashOutButton(std::shared_ptr<GameState> game_state);
};

class DoubleButton: public Button{
    public:
        DoubleButton(std::shared_ptr<GameState> game_state);
};

class SmallButton: public Button{
    public:
        SmallButton(std::shared_ptr<GameState> game_state);
};

class BigButton: public Button{
    public:
        BigButton(std::shared_ptr<GameState> game_state);
};
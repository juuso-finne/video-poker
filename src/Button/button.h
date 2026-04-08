#pragma once
#include<raylib.h>
#include <string>
#include <map>
#include <vector>
#include "../Game/GameState/gameState.h"


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
        Button(GameState *game_state);
        virtual void OnClick();

        GameState *game_state_;
        ButtonType type_;
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
        DealButton(GameState *game_state);
        void OnClick() override;
};

class BetButton: public Button{
    public:
        BetButton(GameState *game_state);
        void OnClick() override;
};

class HoldButton: public Button{
    public:
        HoldButton(int index, GameState *game_state);
        int GetIndex();
    private:
        int index_;
};

class CashOutButton: public Button{
    public:
        CashOutButton(GameState *game_state);
};

class DoubleButton: public Button{
    public:
        DoubleButton(GameState *game_state);
};

class SmallButton: public Button{
    public:
        SmallButton(GameState *game_state);
};

class BigButton: public Button{
    public:
        BigButton(GameState *game_state);
};
#pragma once
#include<raylib.h>
#include <string>

constexpr int kButtonWidth = 100;
constexpr int kButtonHeight = 50;

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
        Button(const Vector2 &position);
        ButtonType type_;
        Rectangle bounds_;
        const char *text_;
    private:
};

class DealButton: public Button{
    public:
        DealButton(const Vector2 &position);
};

class BetButton: public Button{
    public:
        BetButton(const Vector2 &position);
};

class HoldButton: public Button{
    public:
        HoldButton(const Vector2 &position);
};

class CashOutButton: public Button{
    public:
        CashOutButton(const Vector2 &position);
};

class DoubleButton: public Button{
    public:
        DoubleButton(const Vector2 &position);
};

class SmallButton: public Button{
    public:
        SmallButton(const Vector2 &position);
};

class BigButton: public Button{
    public:
        BigButton(const Vector2 &position);
};
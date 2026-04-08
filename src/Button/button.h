#pragma once
#include<raylib.h>
#include <string>
#include <map>
#include <vector>


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
        Button();
        ButtonType type_;
        Rectangle bounds_;
        const char *text_;
    protected:
        float width_;
        float height_;
        int padding_;
};

class DealButton: public Button{
    public:
        DealButton();
        int GetIndex();
    private:
        int index_;
};

class BetButton: public Button{
    public:
        BetButton();
};

class HoldButton: public Button{
    public:
        HoldButton(int index);
        int GetIndex();
    private:
        int index_;
};

class CashOutButton: public Button{
    public:
        CashOutButton();
};

class DoubleButton: public Button{
    public:
        DoubleButton();
};

class SmallButton: public Button{
    public:
        SmallButton();
};

class BigButton: public Button{
    public:
        BigButton();
};

std::vector<Button> getButtons();
std::vector<ButtonType> getButtonTypes();
std::map<ButtonType, bool> getDefaultButtonMap();
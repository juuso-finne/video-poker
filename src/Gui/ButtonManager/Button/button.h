#pragma once
#include<raylib.h>
#include <string>
#include <map>
#include <vector>

class GameData;

class Button{
    public:
        Button();
        virtual void OnClick();
        virtual void Draw();
        Rectangle bounds_;
        const char *text_;
        bool enabled_;
        int color_enabled_;
        int color_disabled_;
    protected:
        float width_;
        float height_;
        int padding_;
};

class DealButton: public Button{
    public:
        DealButton();
        void OnClick() override;
};

class BetButton: public Button{
    public:
        BetButton();
        void OnClick() override;
};

class HoldButton: public Button{
    public:
        HoldButton(int index);
        void OnClick() override;
    private:
        int index_;
};

class CashOutButton: public Button{
    public:
        CashOutButton();
        void OnClick() override;
};

class DoubleButton: public Button{
    public:
        DoubleButton();
        void OnClick() override;
};

class SmallButton: public Button{
    public:
        SmallButton();
        void OnClick() override;
};

class BigButton: public Button{
    public:
        BigButton();
        void OnClick() override;
};
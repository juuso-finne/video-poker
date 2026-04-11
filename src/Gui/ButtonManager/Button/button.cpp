#include "button.h"
#define RAYGUI_IMPLEMENTATION
#include <raygui.h>
#include "../../../Game/GameData/gameData.h"
#include "../../../Game/GameState/gameState.h"
#include "../../gui.h"

Button::Button()
{
    width_ = 100;
    height_ = 50;
    padding_ = 20;
    enabled_ = false;
}

void Button::OnClick(){}

void Button::Draw(){
    if (enabled_){
        GuiEnable();
    } else{
        GuiDisable();
    }

    if(GuiButton(bounds_, text_)){
        OnClick();
    }
}

DealButton::DealButton(): Button(){
    text_ = "DEAL";
    float x = Gui::screenWidth_ - padding_ - width_;
    float y = Gui::screenHeight_ - padding_ - height_;
    bounds_ = Rectangle{x, y, width_, height_};
}

void DealButton::OnClick(){
    GameData::state_ -> Deal();
}

BetButton::BetButton(): Button(){
    text_ = "BET";
    float x = Gui::screenWidth_ - padding_ - width_;
    float y = Gui::screenHeight_ - 2 * (padding_ + height_);
    bounds_ = Rectangle{x, y, width_, height_};
}

void BetButton::OnClick(){
    GameData::state_ -> Bet();
}

HoldButton::HoldButton(int index): Button(){
    text_ = "HOLD";
    float x = (index + 1) * padding_ + index * width_;
    float y = Gui::screenHeight_ - 2 * (padding_ + height_);
    bounds_ = Rectangle{x, y, width_, height_};
    index_ = index;
}

void HoldButton::OnClick(){
    GameData::state_ -> Hold(index_);
}

CashOutButton::CashOutButton(): Button(){
    text_ = "CASH OUT";
    float x = padding_;
    float y = Gui::screenHeight_ - padding_ - height_;
    bounds_ = Rectangle{x, y, width_, height_};
}

void CashOutButton::OnClick(){
    GameData::state_ -> CashOut();
}

DoubleButton::DoubleButton(): Button(){
    text_ = "DOUBLE";
    float x = width_ + 2 * padding_;
    float y = Gui::screenHeight_ - padding_ - height_;
    bounds_ = Rectangle{x, y, width_, height_};
}

void DoubleButton::OnClick(){
    GameData::state_ -> Double();
}

SmallButton::SmallButton(): Button(){
    text_ = "SMALL";
    float x = 2 * width_ + 3 * padding_;
    float y = Gui::screenHeight_ - padding_ - height_;
    bounds_ = Rectangle{x, y, width_, height_};
}

void SmallButton::OnClick(){
    GameData::state_ -> Small();
}

BigButton::BigButton(): Button(){
    text_ = "BIG";
    float x = 3 * width_ + 4 * padding_;
    float y = Gui::screenHeight_ - padding_ - height_;
    bounds_ = Rectangle{x, y, width_, height_};
}

void BigButton::OnClick(){
    GameData::state_ -> Big();
}
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
    color_enabled_ = 0xd3d3d3ff;
    color_disabled_ = 0xd3d3d3ff;
}

void Button::OnClick(){}

void Button::Draw(){
    if (enabled_){
        GuiEnable();
    } else{
        GuiDisable();
    }


    GuiSetStyle(BUTTON, BASE_COLOR_NORMAL, color_enabled_);
    GuiSetStyle(BUTTON, BASE_COLOR_DISABLED, color_disabled_);
    if(GuiButton(bounds_, text_)){
        OnClick();
    }
}

DealButton::DealButton(): Button(){
    text_ = "DEAL";
    float x = ScreenConstants::screen_width_ - padding_ - width_;
    float y = ScreenConstants::screen_height_ - padding_ - height_;
    bounds_ = Rectangle{x, y, width_, height_};
    color_enabled_ = 0x00ff00ff;
    color_disabled_ = 0x082905ff;
}

void DealButton::OnClick(){
    GameData::state_ -> Deal();
}

BetButton::BetButton(): Button(){
    text_ = "BET";
    float x = ScreenConstants::screen_width_ - padding_ - width_;
    float y = ScreenConstants::screen_height_ - 2 * (padding_ + height_);
    bounds_ = Rectangle{x, y, width_, height_};
    color_enabled_ = 0x0000ffff;
    color_disabled_ = 0x051029ff;
}

void BetButton::OnClick(){
    GameData::state_ -> Bet();
}

HoldButton::HoldButton(int index): Button(){
    text_ = "HOLD";
    float x = (index + 1) * padding_ + index * width_;
    float y = ScreenConstants::screen_height_ - 2 * (padding_ + height_);
    bounds_ = Rectangle{x, y, width_, height_};
    index_ = index;
    color_enabled_ = 0xff0000ff;
    color_disabled_ = 0x290705ff;
}

void HoldButton::OnClick(){
    GameData::state_ -> Hold(index_);
}

CashOutButton::CashOutButton(): Button(){
    text_ = "CASH OUT";
    float x = padding_;
    float y = ScreenConstants::screen_height_ - padding_ - height_;
    bounds_ = Rectangle{x, y, width_, height_};
    color_enabled_ = 0xe7ed28ff;
    color_disabled_ = 0x3e4009ff;
}

void CashOutButton::OnClick(){
    GameData::state_ -> CashOut();
}

DoubleButton::DoubleButton(): Button(){
    text_ = "DOUBLE";
    float x = 3 * width_ + 4 * padding_;
    float y = ScreenConstants::screen_height_ - padding_ - height_;
    bounds_ = Rectangle{x, y, width_, height_};
    color_enabled_ = 0xe37b19ff;
    color_disabled_ = 0x3d2107ff;
}

void DoubleButton::OnClick(){
    GameData::state_ -> Double();
}

SmallButton::SmallButton(): Button(){
    text_ = "SMALL";
    float x = width_ + 2 * padding_;
    float y = ScreenConstants::screen_height_ - padding_ - height_;
    bounds_ = Rectangle{x, y, width_, height_};
    color_enabled_ = 0xe37b19ff;
    color_disabled_ = 0x3d2107ff;
}

void SmallButton::OnClick(){
    GameData::state_ -> Small();
}

BigButton::BigButton(): Button(){
    text_ = "BIG";
    float x = 2 * width_ + 3 * padding_;
    float y = ScreenConstants::screen_height_ - padding_ - height_;
    bounds_ = Rectangle{x, y, width_, height_};
    color_enabled_ = 0xe37b19ff;
    color_disabled_ = 0x3d2107ff;
}

void BigButton::OnClick(){
    GameData::state_ -> Big();
}
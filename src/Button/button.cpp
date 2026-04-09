#include "button.h"

Button::Button(std::shared_ptr<GameState> game_state)
{
    width_ = 100;
    height_ = 50;
    padding_ = 20;
    enabled_ = false;
    game_state_ = std::move(game_state);
}

void Button::OnClick(){}

DealButton::DealButton(std::shared_ptr<GameState> game_state): Button(game_state){
    text_ = "DEAL";
    float x = (float)GetScreenWidth() - padding_ - width_;
    float y = (float)GetScreenHeight() - padding_ - height_;
    bounds_ = Rectangle{x, y, width_, height_};
    enabled_ = game_state_ -> DealButtonEnabled();
}

void DealButton::OnClick(){ game_state_ -> DealButtonClick(); }

BetButton::BetButton(std::shared_ptr<GameState> game_state): Button(game_state){
    text_ = "BET";
    float x = (float)GetScreenWidth() - padding_ - width_;
    float y = (float)GetScreenHeight() - 2 * (padding_ + height_);
    bounds_ = Rectangle{x, y, width_, height_};
    enabled_ = game_state_ -> BetButtonEnabled();
}

void BetButton::OnClick(){ game_state_ -> BetButtonClick(); }

HoldButton::HoldButton(int index, std::shared_ptr<GameState> game_state): Button(game_state){
    text_ = "HOLD";
    float x = (index + 1) * padding_ + index * width_;
    float y = (float)GetScreenHeight() - 2 * (padding_ + height_);
    bounds_ = Rectangle{x, y, width_, height_};
    enabled_ = game_state_ -> HoldButtonEnabled();
    index_ = index;
}

int HoldButton::GetIndex(){
    return index_;
}

CashOutButton::CashOutButton(std::shared_ptr<GameState> game_state): Button(game_state){
    text_ = "CASH OUT";
    float x = padding_;
    float y = (float)GetScreenHeight() - padding_ - height_;
    bounds_ = Rectangle{x, y, width_, height_};
    enabled_ = game_state_ -> CashOutButtonEnabled();
}

DoubleButton::DoubleButton(std::shared_ptr<GameState> game_state): Button(game_state){
    text_ = "DOUBLE";
    float x = width_ + 2 * padding_;
    float y = (float)GetScreenHeight() - padding_ - height_;
    bounds_ = Rectangle{x, y, width_, height_};
    enabled_ = game_state_ -> DoubleButtonEnabled();
}

SmallButton::SmallButton(std::shared_ptr<GameState> game_state): Button(game_state){
    text_ = "SMALL";
    float x = 2 * width_ + 3 * padding_;
    float y = (float)GetScreenHeight() - padding_ - height_;
    bounds_ = Rectangle{x, y, width_, height_};
    enabled_ = game_state_ -> SmallButtonEnabled();
}

BigButton::BigButton(std::shared_ptr<GameState> game_state): Button(game_state){
    text_ = "BIG";
    float x = 3 * width_ + 4 * padding_;
    float y = (float)GetScreenHeight() - padding_ - height_;
    bounds_ = Rectangle{x, y, width_, height_};
    enabled_ = game_state_ -> BigButtonEnabled();
}

/*
std::vector<Button> getButtons(std::shared_ptr<GameState> game_state){
    std::vector<Button> output = {
        DealButton(game_state),
        BetButton(game_state),
        CashOutButton(game_state),
        DoubleButton(game_state),
        SmallButton(game_state),
        BigButton(game_state)
    };

    for(int i = 0; i < 5; i++){
        output.push_back(HoldButton(i, std::move(game_state)));
    }

    return output;
}
*/
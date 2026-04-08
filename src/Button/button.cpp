#include "button.h"

Button::Button(GameState *game_state)
{
    width_ = 100;
    height_ = 50;
    padding_ = 20;
    game_state_ = game_state;
    enabled_ = false;
}

void Button::OnClick(){}

DealButton::DealButton(GameState *game_state): Button(game_state){
    text_ = "DEAL";
    type_ = ButtonType::kDeal;
    float x = (float)GetScreenWidth() - padding_ - width_;
    float y = (float)GetScreenHeight() - padding_ - height_;
    bounds_ = Rectangle{x, y, width_, height_};
    enabled_ = game_state_ -> DealButtonEnabled();
}

void DealButton::OnClick(){ game_state_ -> DealButtonClick(); }

BetButton::BetButton(GameState *game_state): Button(game_state){
    text_ = "BET";
    float x = (float)GetScreenWidth() - padding_ - width_;
    float y = (float)GetScreenHeight() - 2 * (padding_ + height_);
    bounds_ = Rectangle{x, y, width_, height_};
    type_ = ButtonType::kBet;
    enabled_ = game_state_ -> BetButtonEnabled();
}

void BetButton::OnClick(){ game_state_ -> BetButtonClick(); }

HoldButton::HoldButton(int index, GameState *game_state): Button(game_state){
    type_ = ButtonType::kHold;
    index_ = index;
}

int HoldButton::GetIndex(){
    return index_;
}

CashOutButton::CashOutButton(GameState *game_state): Button(game_state){
    type_ = ButtonType::kCashOut;
}

DoubleButton::DoubleButton(GameState *game_state): Button(game_state){
    type_ = ButtonType::kDouble;
}

SmallButton::SmallButton(GameState *game_state): Button(game_state){
    type_ = ButtonType::kSmall;
}

BigButton::BigButton(GameState *game_state): Button(game_state){
    type_ = ButtonType::kBig;
}

std::vector<Button> getButtons(GameState *game_state){
    std::vector<Button> output = {
        DealButton(game_state),
        BetButton(game_state),
        CashOutButton(game_state),
        DoubleButton(game_state),
        SmallButton(game_state),
        BigButton(game_state)
    };

    for(int i = 0; i < 5; i++){
        output.push_back(HoldButton(i, game_state));
    }

    return output;
}
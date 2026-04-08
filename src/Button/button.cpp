#include "button.h"

Button::Button(const Vector2 &position){
    bounds_ = Rectangle{position.x, position.y, kButtonWidth, kButtonHeight};
}

DealButton::DealButton(const Vector2 &position): Button(position){
    type_ = ButtonType::kDeal;
}

BetButton::BetButton(const Vector2 &position): Button(position){
    type_ = ButtonType::kBet;
}

HoldButton::HoldButton(const Vector2 &position): Button(position){
    type_ = ButtonType::kHold;
}

CashOutButton::CashOutButton(const Vector2 &position): Button(position){
    type_ = ButtonType::kCashOut;
}

DoubleButton::DoubleButton(const Vector2 &position): Button(position){
    type_ = ButtonType::kDouble;
}

SmallButton::SmallButton(const Vector2 &position): Button(position){
    type_ = ButtonType::kSmall;
}

BigButton::BigButton(const Vector2 &position): Button(position){
    type_ = ButtonType::kBig;
}
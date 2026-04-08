#include "button.h"

Button::Button(){
    width_ = 100;
    height_ = 50;
    padding_ = 20;
}

DealButton::DealButton(){
    type_ = ButtonType::kDeal;
    float x = (float)GetScreenWidth() - padding_;
    float y = (float)GetScreenHeight() - padding_;
    bounds_ = Rectangle{x, y, width_, height_};
}

BetButton::BetButton(){
    type_ = ButtonType::kBet;
}

HoldButton::HoldButton(int index){
    type_ = ButtonType::kHold;
    index_ = index;
}

int HoldButton::GetIndex(){
    return index_;
}

CashOutButton::CashOutButton(){
    type_ = ButtonType::kCashOut;
}

DoubleButton::DoubleButton(){
    type_ = ButtonType::kDouble;
}

SmallButton::SmallButton(){
    type_ = ButtonType::kSmall;
}

BigButton::BigButton(){
    type_ = ButtonType::kBig;
}

std::vector<Button> getButtons(){
    std::vector<Button> output = {
        DealButton(),
        BetButton(),
        CashOutButton(),
        DoubleButton(),
        SmallButton(),
        BigButton()
    };

    for(int i = 0; i < 5; i++){
        output.push_back(HoldButton(i));
    }

    return output;
}

std::vector<ButtonType> getButtonTypes()
{
    return std::vector<ButtonType>{
        ButtonType::kDeal,
        ButtonType::kBet,
        ButtonType::kHold,
        ButtonType::kCashOut,
        ButtonType::kDouble,
        ButtonType::kSmall,
        ButtonType::kBig
    };
}

std::map<ButtonType, bool> getDefaultButtonMap(){
    std::map<ButtonType, bool> output;

    std::vector<ButtonType>typeList = getButtonTypes();

    for(ButtonType t: typeList){
        output[t] = false;
    }

    return output;
}

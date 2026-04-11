#include "buttonManager.h"

DealButton ButtonManager::deal_button_;
BetButton ButtonManager::bet_button_;
std::vector<HoldButton> ButtonManager::hold_buttons_ = {
    HoldButton(0),
    HoldButton(1),
    HoldButton(2),
    HoldButton(3),
    HoldButton(4)
};
CashOutButton ButtonManager::cash_out_button_;
DoubleButton ButtonManager::double_button_;
SmallButton ButtonManager::small_button_;
BigButton ButtonManager::big_button_;

void ButtonManager::DisableButtons(){
    deal_button_.enabled_ = false;

    for (HoldButton &b : hold_buttons_){
        b.enabled_ = false;
    }

    bet_button_.enabled_ = false;
    cash_out_button_.enabled_ = false;
    double_button_.enabled_ = false;
    small_button_.enabled_ = false;
    big_button_.enabled_ = false;
}

void ButtonManager::DrawButtons(){

    deal_button_.Draw();

    for (HoldButton &b : hold_buttons_){
        b.Draw();
    }

    bet_button_.Draw();
    cash_out_button_.Draw();
    double_button_.Draw();
    small_button_.Draw();
    big_button_.Draw();
}
#include "gui.h"

float Gui::screenHeight_ = 600;
float Gui::screenWidth_ = 800;

DealButton Gui::deal_button_;
BetButton Gui::bet_button_;
std::vector<HoldButton> Gui::hold_buttons_ = {
    HoldButton(0),
    HoldButton(1),
    HoldButton(2),
    HoldButton(3),
    HoldButton(4)
};
CashOutButton Gui::cash_out_button_;
DoubleButton Gui::double_button_;
SmallButton Gui::small_button_;
BigButton Gui::big_button_;

void Gui::DisableButtons(){
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

void Gui::DrawButtons(){

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
